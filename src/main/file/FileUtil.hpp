#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include <stdio.h>

namespace moduru {
	namespace file {

		class FileUtil {

		public:
			static bool Exists(std::string path);
			static std::vector<std::string> splitName(std::string name);
			static int GetLastSeparator(std::string path);
			static bool IsDirectory(std::string path);

            // Returns path separator used by the OS
            static std::string getSeparator();
            
            // Joins names, welded using path separator
            template<typename ... String_Types, typename Separator>
            static std::string join_with_separator(Separator separator, String_Types ... strings)
            {
                std::vector<std::string> string_array = {strings...};
                std::stringstream new_string;
                for(auto &s : string_array)
                {
                    if (s != string_array.back()) {
                        new_string<<s<<separator;
                    }
                    else {
                        new_string<<s;
                    }
                }
            }

		};

	}
}
