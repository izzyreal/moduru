#include <System.hpp>

#include <chrono>

#ifdef __APPLE__
#include <cxxabi.h>
#endif // __APPLE__

using namespace std;
using namespace moduru;

long System::nanoTime() {
	auto nanoTime = chrono::high_resolution_clock::now();
	return (long) chrono::duration_cast<chrono::nanoseconds>(nanoTime.time_since_epoch()).count();
}

#ifdef __APPLE__
string System::demangle(const string& typeIdName) {
    int status = 0;
    char* demangled = abi::__cxa_demangle(typeIdName.c_str(), 0, 0, &status);
    return string(demangled);
}
#endif // __APPLE__

#ifdef _WIN32
string System::demangle(const string& typeIdName) {
    auto copy = string(typeIdName);
    auto toDelete = string("class ");
    auto i = copy.find(toDelete);
    if (i != string::npos) copy.erase(i, toDelete.size());
    return copy;
}
#endif // _WIN32
