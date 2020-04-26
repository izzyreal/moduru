#define _CRT_SECURE_NO_WARNINGS
#define _HAS_STD_BYTE 0

#include <file/FileUtil.hpp>


#if defined (_WIN32)
#include <thirdp/dirent.h>
#include <Windows.h>
#endif

#if defined (__APPLE__)
#include <sys/dirent.h>
#include <sys/dir.h>
#endif

#if defined (__linux__)
#include <dirent.h>
#endif

#include <Logger.hpp>

using namespace moduru::file;

FILE* FileUtil::fopenw(const std::string& path, const std::string& mode)
{
#ifndef _WIN32
	return fopen(filePath.c_str(), mode);
#else
	std::wstring filePathW;
	filePathW.resize(path.size());
	int newPathSize = MultiByteToWideChar(CP_UTF8, 0, path.c_str(), path.length(), const_cast<wchar_t*>(filePathW.c_str()), path.length());
	filePathW.resize(newPathSize);
	
	std::wstring modeW;
	modeW.resize(mode.size());
	int newModeSize = MultiByteToWideChar(CP_UTF8, 0, mode.c_str(), mode.length(), const_cast<wchar_t*>(modeW.c_str()), mode.length());
	modeW.resize(newModeSize);

	return _wfopen(filePathW.c_str(), modeW.c_str());
#endif
}

bool FileUtil::Exists(string path)
{
	auto fp = fopenw(path.c_str(), "r");

#ifdef _WIN32

	if (fp == NULL) {
		std::wstring pathW;
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
	DIR* d = opendir(path.c_str());
	if (d != NULL) {
		closedir(d);
		return true;
	}
	return false;
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
