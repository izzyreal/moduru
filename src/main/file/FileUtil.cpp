#define _CRT_SECURE_NO_WARNINGS
#define _HAS_STD_BYTE 0

#include <Logger.hpp>

#include <file/FileUtil.hpp>
#include <sys/Home.hpp>

#if defined (_WIN32)
#include <thirdp/dirent.h>
#include <Windows.h>
#include <codecvt>
#include <locale>
#endif

#if defined (__APPLE__)
#include <sys/dirent.h>
#include <sys/dir.h>
#endif

#if defined (__linux__)
#include <dirent.h>
#include <sys/vfs.h>
#endif

#if defined(__APPLE__) || defined (__linux__)
#include <sys/param.h>
#include <sys/mount.h>
#include <pwd.h>
#include <unistd.h>
#endif

using namespace moduru::file;
using namespace std;

FILE* FileUtil::fopenw(const string& path, const string& mode)
{
#ifndef _WIN32
	return fopen(path.c_str(), mode.c_str());
#else
	wstring filePathW;
	filePathW.resize(path.size());
	int newPathSize = MultiByteToWideChar(CP_UTF8, 0, path.c_str(), path.length(), const_cast<wchar_t*>(filePathW.c_str()), path.length());
	filePathW.resize(newPathSize);
	
	wstring modeW;
	modeW.resize(mode.size());
	int newModeSize = MultiByteToWideChar(CP_UTF8, 0, mode.c_str(), mode.length(), const_cast<wchar_t*>(modeW.c_str()), mode.length());
	modeW.resize(newModeSize);

	return _wfopen(filePathW.c_str(), modeW.c_str());
#endif
}

#ifndef _WIN32
uint64_t getFreeSpace()
{
    struct statfs stat;
    struct passwd *pw = getpwuid(getuid());
    if ( NULL != pw && 0 == statfs(pw->pw_dir, &stat) )
    {
        uint64_t freeBytes = (uint64_t)stat.f_bavail * stat.f_bsize;
        return freeBytes;
    }
    return 0ULL;
}
#endif

string FileUtil::getFreeDiskSpaceFormatted(const string& path)
{
	size_t byteCount = 0;
    
#ifdef _WIN32
    if (path.length() < 3)
	{
		return "?";
	}
	
	auto pathToCheck = path.substr(0, 3);

	wstring filePathW;
	filePathW.resize(pathToCheck.size());
	int newPathSize = MultiByteToWideChar(CP_UTF8, 0, pathToCheck.c_str(), pathToCheck.length(), const_cast<wchar_t*>(filePathW.c_str()), pathToCheck.length());
	filePathW.resize(newPathSize);

	BOOL fResult;
	DWORD dwSectPerClust, dwBytesPerSect, dwFreeClusters, dwTotalClusters;
	fResult = GetDiskFreeSpaceW(filePathW.c_str(), &dwSectPerClust, &dwBytesPerSect, &dwFreeClusters, &dwTotalClusters);

	if (fResult)
	{
		byteCount = (__int64) dwSectPerClust * dwBytesPerSect * dwFreeClusters;
	}
	else {
		return "?";
	}
#else
    byteCount = getFreeSpace();
#endif
	int i = 0;
	const char* units[] = { "B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB" };
	
	while (byteCount > 1024)
	{
		byteCount /= 1024;
		i++;
	}

	char buf[10];
	sprintf(buf, "%.*zu%s", i, byteCount, units[i]);
	auto freeFormatted = string(buf);
	return freeFormatted;
}

ifstream FileUtil::ifstreamw(const string& path, std::ios_base::openmode flags)
{
#ifdef _WIN32
	wstring_convert<codecvt_utf8<wchar_t>, wchar_t> strconverter;
	auto result = ifstream(strconverter.from_bytes(path).c_str(), flags);
	result.unsetf(ios_base::skipws);
	return result;
	
#else
	return ifstream(path.c_str(), flags); 
#endif
}

ofstream FileUtil::ofstreamw(const string& path, std::ios_base::openmode flags)
{
#ifdef _WIN32
	wstring_convert<codecvt_utf8<wchar_t>, wchar_t> strconverter;
	return ofstream(strconverter.from_bytes(path).c_str(), flags);
#else
	return ofstream(path.c_str(), flags); 
#endif
}

bool FileUtil::Exists(string path)
{
	auto fp = fopenw(path.c_str(), "r");

#ifdef _WIN32

	if (fp == NULL) {
		wstring pathW;
		pathW.resize(path.size());
		int newModeSize = MultiByteToWideChar(CP_UTF8, 0, path.c_str(), path.length(), const_cast<wchar_t*>(pathW.c_str()), path.length());
		pathW.resize(newModeSize);
		DWORD ftyp = GetFileAttributesW(pathW.c_str());
		if (ftyp == INVALID_FILE_ATTRIBUTES)
			return false;

		if (ftyp & FILE_ATTRIBUTE_DIRECTORY) {
			return true;
		}

		return false;
	}
#endif

	if (fp != NULL)
		fclose(fp);

	return fp != NULL;
}

int FileUtil::GetLastSeparator(string path) {
	return (int)(path.find_last_of(getSeparator()));
}

bool FileUtil::IsDirectory(string path) {
#ifdef _WIN32
		wstring pathW;
		pathW.resize(path.size());
		int newModeSize = MultiByteToWideChar(CP_UTF8, 0, path.c_str(), path.length(), const_cast<wchar_t*>(pathW.c_str()), path.length());
		pathW.resize(newModeSize);
		DWORD ftyp = GetFileAttributesW(pathW.c_str());
		if (ftyp == INVALID_FILE_ATTRIBUTES)
			return false;

		if (ftyp & FILE_ATTRIBUTE_DIRECTORY) {
			return true;
		}

		return false;
#else
	DIR* d = opendir(path.c_str());
	if (d != NULL) {
		closedir(d);
		return true;
	}
	return false;
#endif
}

vector<string> FileUtil::splitName(string name) {
	vector<string> res(2);
	if (name.find(".") == string::npos) {
		res[0] = name;
		res[1] = "";
		return res;
	}
	auto i = name.find_last_of(".");
	res[0] = name.substr(0, i);
	res[1] = name.substr(i + 1);
	return res;
}

string FileUtil::getSeparator() {
#ifdef _WIN32
	return "\\";
#else
	return "/";
#endif
}
