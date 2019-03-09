#pragma once

#include <vector>

namespace moduru {
	namespace io {

		class StereoCircularTBuffer {

		private:
			std::vector<float> dataL;
			std::vector<float> dataR;
			long writePos = 0;
			long readPos = 0;

		public:
			void read(std::vector<float>* destL, std::vector<float>* destR, int srcOffset, int length);
			void write(std::vector<float>* srcL, std::vector<float>* srcR);
			void write(std::vector<float>* srcL, std::vector<float>* srcR, int length);
			void moveReadPos(int amount);
			void multiply(int relativePos, float factor, bool left);
			void encodeMidSide(int relativePos);
			void decodeMidSide(int relativePos);

		public:
			StereoCircularTBuffer(int size);
			~StereoCircularTBuffer();

		};

	}
}
