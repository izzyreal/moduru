#include <System.hpp>

#include <chrono>

#include <boost/core/demangle.hpp>

using namespace std;
using namespace moduru;

long System::nanoTime() {
	auto nanoTime = chrono::high_resolution_clock::now();
	return  (long) chrono::duration_cast<std::chrono::nanoseconds>(nanoTime.time_since_epoch()).count();
}

string System::demangle(const std::string& typeIdName) {
	auto copy = typeIdName;
	auto toDelete = string("class ");
	auto i = copy.find(toDelete);
	if (i != string::npos) copy.erase(i, toDelete.size());
	return boost::core::demangle(copy.c_str());
}
