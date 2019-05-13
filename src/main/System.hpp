#pragma once

#include <string>

namespace moduru {

	class System {

	public:
		static long nanoTime();
		static std::string demangle(const std::string& typeIdName);
		static void sleep(const int ms);

	};

}
