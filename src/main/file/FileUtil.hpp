#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include <stdio.h>

using namespace std;

namespace moduru::file {

    class FileUtil {

    public:
        static bool Exists(string path);
        static vector<string> splitName(string name);
        static int GetLastSeparator(string path);
        static bool IsDirectory(string path);

        static FILE* fopenw(const string& path, const string& mode);
        static ifstream ifstreamw(const string& path, std::ios_base::openmode flags);
        static ofstream ofstreamw(const string& path, std::ios_base::openmode flags);

        static string getFreeDiskSpaceFormatted(const string& path);

        // Returns path separator used by the OS
        static string getSeparator();

        // Joins names with a path separator
        template<typename ... String_Types>
        static string joinPath(String_Types ... strings)
        {
            vector<string> string_array = { strings... };
            stringstream new_string;
            for (auto& s : string_array)
            {
                if (s != string_array.back()) {
                    new_string << s << FileUtil::getSeparator();
                }
                else {
                    new_string << s;
                }
            }
            return new_string.str();
        }

    };
}
