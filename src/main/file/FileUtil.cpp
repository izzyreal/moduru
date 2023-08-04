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
