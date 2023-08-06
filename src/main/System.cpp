#include <System.hpp>

#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace moduru;

uint64_t System::currentTimeMillis()
{
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void System::sleep(const int ms) {
	this_thread::sleep_for(chrono::milliseconds(ms));
}
