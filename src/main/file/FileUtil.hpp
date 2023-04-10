#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include <stdio.h>

namespace moduru::file
{
    class FileUtil
    {
    public:
        static FILE* fopenw(const std::string& path, const std::string& mode);
        static std::string getFreeDiskSpaceFormatted(const std::string& path);
        static uint64_t getTotalDiskSpace(std::string driveLetterStr = "C");
    };
}
