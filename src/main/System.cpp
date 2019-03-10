#include <System.hpp>

#include <chrono>

//#include <cxxabi.h>

using namespace std;
using namespace moduru;

long System::nanoTime() {
	auto nanoTime = chrono::high_resolution_clock::now();
	return (long) chrono::duration_cast<chrono::nanoseconds>(nanoTime.time_since_epoch()).count();
}

string System::demangle(const string& typeIdName) {
	auto copy = string(typeIdName);
	auto toDelete = string("class ");
	auto i = copy.find(toDelete);
	if (i != string::npos) copy.erase(i, toDelete.size());
    int status = 0;
    //char* demangled = abi::__cxa_demangle(typeIdName.c_str(), 0, 0, &status);
    //return string(demangled);
	return copy;
}
