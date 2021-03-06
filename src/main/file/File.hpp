#pragma once
#include <file/FsNode.hpp>
#include <file/FileHandle.hpp>

#include <memory>
#include <vector>
#include <string>

namespace moduru::file
{
class Directory;

class File final
: public FsNode {
    
private:
    std::unique_ptr<FileHandle> handle;
    
public:
    bool setData(std::vector<char>* src);
    bool getData(std::vector<char>* dest);
    bool close();
    int getPosition();
    void seek(int pos);
    void openRead();
    void openWrite();
    char readByte();
    long readLong();
    short readShort();
    void writeByte(char& c);
    void writeShort(short& s);
    
public:
    bool isFile() override;
    bool isDirectory() override;
    bool create() override;
    
public:
    int getLength() override;
    
public:
    File(std::string const path, std::shared_ptr<Directory> parent);
    
};

}
