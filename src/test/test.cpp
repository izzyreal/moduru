#include <Logger.hpp>

#include <file/FileUtil.hpp>

using namespace moduru;
using namespace moduru::file;

int main(){
    Logger::l.setPath("/Users/Izmør/moduru-tests.log");
    MLOG("Hello I'm Izmør");
    
    if (FileUtil::Exists("/Users/Izmør/vMPC")) {
        printf("dir exists\n");
    } else {
        printf("dir does not exist\n");
    }
    
    if (FileUtil::IsDirectory("/Users/Izmør/vMPC")) {
        printf("dir is dir\n");
    } else {
        printf("dir is file\n");
    }
    
}
