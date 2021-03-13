#pragma once

#include <vector>

namespace moduru {
	namespace io {

		class CircularTBuffer {

		private:
			std::vector<float> data;
			long writePos = 0;
			long readPos = 0;

		public:
			void read(std::vector<float>* dest, int srcOffset, int length);
			void write(std::vector<float>* src);
			void moveReadPos(int amount);
			void multiply(int relativePos, float factor);

		public:
			CircularTBuffer(int size);
			~CircularTBuffer();

		};

	}
}
