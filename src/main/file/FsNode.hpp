#pragma once

#include <string>
#include <memory>

namespace moduru::file {
	class Directory;
}

namespace moduru::file {
	class FsNode {

	private:
		std::string path;
		Directory* const parent;

	public:
		const std::string getPath();
		const std::string getName();
		const std::string getNameWithoutExtension();
		Directory* const getParent();

	public:
		virtual int getLength() { return 0; };

	public:
		virtual bool isFile() = 0;
		virtual bool isDirectory() = 0;
		virtual bool create() = 0;

	public:
		virtual bool del();

	public:
		bool renameTo(std::string newName);
		bool exists();

	public:
		FsNode(std::string const path, Directory* const parent);
		virtual ~FsNode();

	};
}
