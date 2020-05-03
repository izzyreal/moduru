#define _CRT_SECURE_NO_WARNINGS
#define _HAS_STD_BYTE 0

#include <file/FileUtil.hpp>


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
#endif

#include <sys/stat.h>

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

string FileUtil::getFreeDiskSpaceFormatted(const string& path)
{
	struct stat info;
	
	stat("C:/Users/Izmar/", &info);
	auto byteCount = info.st_size;

	int i = 0;
	const char* units[] = { "B", "kB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB" };
	while (byteCount > 1024) {
		byteCount /= 1024;
		i++;
	}
	char buf[10];
	sprintf(buf, "%.*f %s", i, byteCount, units[i]);
	auto freeFormatted = string(buf);
	//return freeFormatted;
	return "doesn't work yet";
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
