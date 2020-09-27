#pragma once

#include <string>

namespace moduru {

	class System {

	public:
		static uint64_t currentTimeMillis();
		static std::string demangle(const std::string& typeIdName);
		static void sleep(const int ms);

	};

}
