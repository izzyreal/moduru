#pragma once

#include <vector>

namespace moduru {
	namespace gui {

		class Bressenham {

		public:
			static std::vector<std::vector<int>> Line(int x1, int y1, int const x2, int const y2);

		};
	}
}