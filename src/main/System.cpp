#include <System.hpp>

#include <chrono>
#include <thread>

#if defined (__APPLE__) || defined (__linux__)
#include <cxxabi.h>
#endif

using namespace std;
using namespace std::chrono;
using namespace moduru;

uint64_t System::currentTimeMillis()
{
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

#if defined (__APPLE__) || defined (__linux__)
string System::demangle(const string& typeIdName) {
    int status = 0;
    char* demangled = abi::__cxa_demangle(typeIdName.c_str(), 0, 0, &status);
    std::string result(demangled);
    free(demangled);
    return result;
}
#endif

#ifdef _WIN32
string System::demangle(const string& typeIdName) {
    auto copy = string(typeIdName);
    auto toDelete = string("class ");
    auto i = copy.find(toDelete);
    if (i != string::npos) copy.erase(i, toDelete.size());
    return copy;
}
#endif // _WIN32

void System::sleep(const int ms) {
	this_thread::sleep_for(chrono::milliseconds(ms));
}
