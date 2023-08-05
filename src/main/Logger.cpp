#define _CRT_SECURE_NO_WARNINGS
#include <Logger.hpp>

#include <string>

using namespace moduru;
using namespace std;

Logger::Logger()
{
	remove(path.c_str());
}
Logger Logger::l;

void Logger::setPath(std::string s) {
	path = s;
}

void Logger::log(std::string s) {
	if (path.empty()) {
		return;
	}

	//auto fp = moduru::file::FileUtil::fopenw(path, "ab");
    //
	//s += "\n";
    //
	//fwrite(s.c_str(), s.length(), 1, fp);
    //
	//fclose(fp);
}
