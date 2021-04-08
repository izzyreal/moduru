#pragma once
#include <file/FsNode.hpp>

#include <vector>
#include <memory>
#include <string>

namespace moduru::file
{

class Directory final
: public FsNode, public std::enable_shared_from_this<Directory>
{
    
public:
    std::vector<std::shared_ptr<FsNode>> listFiles(bool recursive = false);
    
public:
    bool isFile() override;
    bool isDirectory() override;
    bool create() override;
    bool del() override;
    static void deleteRecursive(std::shared_ptr<Directory> itself);
    
public:
    Directory(std::string const path, std::shared_ptr<Directory> parent = {});
    
};
}
