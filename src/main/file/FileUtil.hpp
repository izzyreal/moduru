#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdint>
#include <stdio.h>

namespace moduru::file
{
    class FileUtil
    {
    public:
        static FILE* fopenw(const std::string& path, const std::string& mode);
        static uint64_t getTotalDiskSpace(std::string driveLetterStr = "C");
    };
}
