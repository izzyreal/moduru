#define _CRT_SECURE_NO_WARNINGS
#include <file/File.hpp>
#include <file/FileUtil.hpp>

#include <fstream>

#if defined (__APPLE__) || defined(__linux__)
#include <sys/stat.h>
#endif


using namespace moduru::file;
using namespace std;

File::File(string const path, shared_ptr<Directory> parent)
	: FsNode(path, parent)
{
}

int File::getLength() {
#ifdef _WIN32
	FILE* file = moduru::file::FileUtil::fopenw(getPath(), "rb");

	if (file == NULL) {
		return -1;
	}

	fseek(file, 0, SEEK_END);
	auto size = ftell(file);
	fclose(file);
	return (int) size;
#else
	struct stat stat_buf;
	int rc = stat(getPath().c_str(), &stat_buf);
	return rc == 0 ? stat_buf.st_size : -1;
#endif
}

bool File::setData(vector<char>* src) {
    int size = (int) src->size();
	auto stream = FileUtil::ofstreamw(getPath(), ios::binary);
	stream.write(reinterpret_cast<char*>(&(*src)[0]), size);
    stream.close();
    return true;
}

bool File::create() {
	auto fp = FileUtil::fopenw(getPath().c_str(), "w");
	auto res = fp != nullptr;
	if (res) fclose(fp);
	return res;
}

bool File::isFile() {
	return true;
}

bool File::isDirectory() {
	return false;
}

bool File::close() {
	if (handle) {
		//handle.reset();
	}
	return true;
}

int File::getPosition() {
	if (!handle) return 0;
	return handle->getPosition();
}

void File::seek(int pos) {
	if (!handle) return;
	handle->seek(pos);
}

void File::openRead() {
	if (handle) {
		handle->seek(0);
		return;
	}
	handle = make_unique<FileHandle>(getPath(), true);
}

void File::openWrite() {
	if (handle && !handle->isReadOnly()) return;
	handle = make_unique<FileHandle>(getPath(), false);
}

char File::readByte() {
	return handle->readByte();
}

void File::writeByte(char& c) {
	handle->writeByte(c);
}

long File::readLong() {
	return handle->readLong();
}

short File::readShort() {
	return handle->readShort();
}

void File::writeShort(short& s) {
	handle->writeShort(s);
}

bool File::getData(vector<char>* dest) {
	//openRead();
	//if (handle) {
		
	auto fp = FileUtil::fopenw(getPath(), "rb");

	if (fp != NULL) {

		fseek(fp, 0L, SEEK_END);
		auto size = ftell(fp);

		fseek(fp, 0L, SEEK_SET);

		if (dest->size() != size) {
			dest->resize(size);
		}

		fread(&(*dest)[0], 1, size, fp);
		fclose(fp);
		return true;
	}
	else {
		return false;
	}
}
