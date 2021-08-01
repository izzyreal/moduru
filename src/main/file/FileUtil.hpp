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
        static bool Exists(std::string path);
        static std::vector<std::string> splitName(std::string name);
        static int GetLastSeparator(std::string path);
        static bool IsDirectory(std::string path);

        static FILE* fopenw(const std::string& path, const std::string& mode);
        static std::ifstream ifstreamw(const std::string& path, std::ios_base::openmode flags);
        static std::ofstream ofstreamw(const std::string& path, std::ios_base::openmode flags);

        static std::string getFreeDiskSpaceFormatted(const std::string& path);
        static uint64_t getTotalDiskSpace();

        // Returns path separator used by the OS
        static std::string getSeparator();

        // Joins names with a path separator
        template<typename ... String_Types>
        static std::string joinPath(String_Types ... strings)
        {
            std::vector<std::string> string_array = { strings... };
            std::stringstream new_string;
            for (auto& s : string_array)
            {
                if (s != string_array.back())
                {
                    new_string << s << FileUtil::getSeparator();
                }
                else
                {
                    new_string << s;
                }
            }
            return new_string.str();
        }

    };
}
