#define _HAS_STD_BYTE 0
#include <file/Directory.hpp>

#include <file/File.hpp>
#include <file/FileUtil.hpp>

#ifdef _WIN32
#include <thirdp/dirent.h>
#include <direct.h>
#include <Windows.h>
#else
//OSX
#include <stdio.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#endif

#include <lang/StrUtil.hpp>

using namespace moduru::file;

using namespace std;

Directory::Directory(string const path, shared_ptr<Directory> parent)
	: FsNode(path, parent)
{
}

vector<shared_ptr<FsNode>> Directory::listFiles(bool recursive) {
	
	if (!isDirectory()) {
		return vector<shared_ptr<FsNode>>(0);
	}

#ifdef _WIN32
	auto path = getPath();
	std::wstring pathW;
	pathW.resize(path.size());
	int newModeSize = MultiByteToWideChar(CP_UTF8, 0, path.c_str(), path.length(), const_cast<wchar_t*>(pathW.c_str()), path.length());
	pathW.resize(newModeSize);
	WDIR* dir = _wopendir(pathW.c_str());
#else
	DIR* dir = opendir(getPath().c_str());
#endif

	if (dir == NULL) {
		return vector<shared_ptr<FsNode>>(0);
	}

	vector<shared_ptr<FsNode>> res;

#ifdef _WIN32
	struct wdirent *ent;
    
	while ((ent = _wreaddir(dir)) != NULL) {
#else
	struct dirent* ent;
	while ((ent = readdir(dir)) != NULL) {
#endif

		if (ent->d_type != DT_DIR && ent->d_type != DT_REG) {
			//continue;
		}

#ifdef _WIN32
		auto nameW = wstring(ent->d_name);
		auto name = string(nameW.begin(), nameW.end());
#else
		string name(ent->d_name);
#endif

		if (moduru::lang::StrUtil::hasEnding(name, ".DS_")) {
			continue;
		}

		if (name.compare(".DS_Store") == 0) {
			continue;
		}

		if (name.compare(".") == 0 || name.compare("..") == 0) {
			continue;
		}

		string childPath = string(getPath() + FileUtil::getSeparator() + name);

		bool childIsDir = FileUtil::IsDirectory(childPath);
		shared_ptr<FsNode> child;

		if (childIsDir) {
			auto directory = make_shared<Directory>(childPath, shared_from_this());

			if (recursive) {
				auto children = directory->listFiles(true);
				for (auto& c : children) {
					res.push_back(move(shared_ptr<FsNode>(c)));
				}
			}

			child = directory;
		}
		else {
			child = make_shared<File>(childPath, shared_from_this());
		}
		res.push_back(move(child));

	}

#ifdef _WIN32
		_wclosedir(dir);
#else
		closedir(dir); 
#endif

	return res;
}

bool Directory::create() {
#ifdef _WIN32
	return _mkdir(getPath().c_str()) == 0; //Windows
#else
	return mkdir(getPath().c_str(), S_IRWXU) == 0; //OSX
#endif
}

bool Directory::isFile() {
	return false;
}

bool Directory::isDirectory() {
	return true;
}

bool Directory::del() {
#ifdef _WIN32
	return RemoveDirectory(getPath().c_str()) != 0;
#else
	return FsNode::del();
#endif
}
