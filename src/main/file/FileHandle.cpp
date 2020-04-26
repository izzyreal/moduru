#define _CRT_SECURE_NO_WARNINGS
#include <file/FileHandle.hpp>

#include <file/FileUtil.hpp>

using namespace moduru::file;
using namespace std;

FileHandle::FileHandle(std::string _path, bool _readOnly) : readOnly(_readOnly), path(_path) {
	bool success = false;
	if (readOnly) {
		success = openRead();
	}
	else {
		success = openWrite();
	}
	if (!success) throw std::invalid_argument("Handle acquisition failed for path " + path + "\n");
	open = true;
}

bool FileHandle::openRead() {
	if (open) {
		throw std::invalid_argument("Handle already open");
	}
	return file = FileUtil::fopenw(path.c_str(), "rb");
}

bool FileHandle::openWrite() {
	if (open) {
		throw std::invalid_argument("Handle already open");
	}
	return file = FileUtil::fopenw(path.c_str(), "wb");
}

//bool FileHandle::isOpen() {
//	return open;
//}

bool FileHandle::isReadOnly() {
	return readOnly;
}

long FileHandle::getPosition() {
	if (!file) return 0;
	return ftell(file);
}

void FileHandle::seek(long pos) {
	if (!file) return;
	fseek(file, pos, SEEK_SET);
}

char FileHandle::readByte() {
	char value = NULL;
	fread(&value, 1, 1, file);
	return value;
}

size_t FileHandle::writeByte(char& c) {
	return fwrite(&c, 1, 1, file);
}

long FileHandle::readLong() {
	long value;
	fread(&value, 4, 1, file);
	return value;
}

short FileHandle::readShort() {
	short value;
	fread(&value, 2, 1, file);
	return value;
}

size_t FileHandle::writeShort(short& s) {
	return fwrite(&s, 1, 1, file);
}

FileHandle::~FileHandle() {
}
