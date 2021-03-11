#define _HAS_STD_BYTE 0
#include <file/FsNode.hpp>

#include <file/Directory.hpp>
#include <file/FileUtil.hpp>

#include <Logger.hpp>

#if defined (_WIN32)
#include <Windows.h>
#endif 


using namespace moduru::file;
using namespace std;

FsNode::FsNode(std::string const path, shared_ptr<Directory> parent)
	: path(path), parent(parent)
{
#if defined(_WIN32)
		long     length = 0;
		TCHAR* buffer = NULL;

		length = GetShortPathName(path.c_str(), NULL, 0);

		if (length > 0) {

			buffer = new TCHAR[length];

			length = GetShortPathName(path.c_str(), buffer, length);

			if (length > 0) {
				auto result = string(buffer);
				shortName = make_shared<string>(result.substr(FileUtil::GetLastSeparator(result) + 1));
			}

			delete[] buffer;
		}
#endif
}

shared_ptr<Directory> const FsNode::getParent() {
	return parent;
}

bool FsNode::exists() {
	return FileUtil::Exists(path);
}

bool FsNode::del() {
    if (path.find("VMPC2000XL") == string::npos)
        return false;
    
    return remove(path.c_str()) == 0;
}

const std::string FsNode::getPath() {
    return path;
}

const std::string FsNode::getNameWithoutExtension() {
	auto name = getName();
	auto extIndex = name.find_last_of('.');
	if (extIndex != string::npos) {
		name = name.substr(0, extIndex);
	}
	return name;
}

const std::string FsNode::getName() {
	
	if (isDirectory() && shortName) {
		return (*shortName.get());
	}

	return path.substr(FileUtil::GetLastSeparator(path) + 1);
}

bool FsNode::renameTo(std::string newName) {
	
	if (path.find("VMPC2000XL") == string::npos)
		return false;
	
	auto newPath = std::string(parent->getPath() + FileUtil::getSeparator() + newName);

	int result = rename(path.c_str(), newPath.c_str());
	
	if (result == 0)
	{
		path = newPath;

		if (shortName)
			shortName = make_shared<string>(newName);

		return true;
	}
	
	return false;
}
