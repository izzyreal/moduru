#include <file/FsNode.hpp>

#include <file/Directory.hpp>
#include <file/FileUtil.hpp>

using namespace moduru::file;

FsNode::FsNode(std::string const path, std::shared_ptr<Directory> parent)
	: path(path), parent(parent)
{
}

std::shared_ptr<Directory> const FsNode::getParent() {
	return parent;
}

bool FsNode::exists() {
	return FileUtil::Exists(path);
}

bool FsNode::del() {
    return remove(path.c_str()) == 0;
}

const std::string FsNode::getPath() {
    return path;
}

const std::string FsNode::getNameWithoutExtension() {
	auto name = getName();
	auto extIndex = name.find_last_of('.');
	if (extIndex != std::string::npos) {
		name = name.substr(0, extIndex);
	}
	return name;
}

const std::string FsNode::getName() {
    return path.substr(FileUtil::GetLastSeparator(path) + 1);
}

bool FsNode::renameTo(std::string newName) {

	auto newPath = std::string(parent->getPath() + FileUtil::getSeparator() + newName);

	int result = rename(path.c_str(), newPath.c_str());
	
	if (result == 0)
	{
		path = newPath;
		return true;
	}
	
	return false;
}
