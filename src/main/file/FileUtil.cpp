#define _CRT_SECURE_NO_WARNINGS
#define _HAS_STD_BYTE 0

#include <Logger.hpp>

#include <file/FileUtil.hpp>

#if defined (_WIN32)
#include <thirdp/dirent.h>
#include <Windows.h>
#include <codecvt>
#include <locale>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <regex>
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

uint64_t FileUtil::getTotalDiskSpace(std::string driveLetterStr)
{
#ifdef _WIN32
	std::string cmd = "wmic logicaldisk get name,size | find /i \"" + driveLetterStr + ":\"";
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd.c_str(), "r"), _pclose);

	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}

	result = std::regex_replace(result, std::regex("([^0-9])"), "");

	unsigned long long mediaSize = 0;

	try {
		mediaSize = stoull(result);
	}
	catch (const std::exception&) {}

	return mediaSize;
#else
    struct statfs stat;
    struct passwd *pw = getpwuid(getuid());

    if ( NULL != pw && 0 == statfs(pw->pw_dir, &stat) )
    {
        uint64_t totalBytes = (uint64_t)stat.f_blocks * stat.f_bsize;
        return totalBytes;
    }

    return 0ULL;
#endif
}

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
