#include <file/FsNode.hpp>

#include <file/Directory.hpp>
#include <file/FileUtil.hpp>

#include <Logger.hpp>

#if defined (_WIN32)
#include <Windows.h>
#endif // 


using namespace moduru::file;
using namespace std;

FsNode::FsNode(std::string const path, Directory* const parent)
	: path(path), parent(parent)
{
}

Directory* const FsNode::getParent() {
	return parent;
}

bool FsNode::exists() {
	return FileUtil::Exists(path);
}

bool FsNode::del() {
	//if (path.find("Users") == string::npos || path.find("vMPC") == string::npos || path.find("Stores") == string::npos || path.find("MPC2000XL") == string::npos) return false;
	if (path.find("vMPC") == string::npos) {
		return false;
	}
	return remove(path.c_str()) == 0;
}

const std::string FsNode::getPath() {
	return path;
}

const std::string FsNode::getName() {

#if defined(_WIN32)
	long     length = 0;
	TCHAR* buffer = NULL;

	length = GetShortPathName(path.c_str(), NULL, 0);

	if (length == 0) {
		MLOG("length == 0");
		return path.substr(FileUtil::GetLastSeparator(path) + 1);
	}

	buffer = new TCHAR[length];

	length = GetShortPathName(path.c_str(), buffer, length);
	if (length == 0) {
		return path.substr(FileUtil::GetLastSeparator(path) + 1);
	}

	auto result = string(buffer);

	delete[] buffer;
	return result.substr(FileUtil::GetLastSeparator(result) + 1);

#endif
	return path.substr(FileUtil::GetLastSeparator(path) + 1);
}

bool FsNode::renameTo(std::string newName) {
	if (path.find("Users") == string::npos || path.find("vMPC") == string::npos || path.find("Stores") == string::npos || path.find("MPC2000XL") == string::npos) return false;
	int result = rename(path.c_str(), std::string(parent->getPath() + FileUtil::getSeparator() + newName).c_str());
	return result == 0;
}

FsNode::~FsNode() {
}
