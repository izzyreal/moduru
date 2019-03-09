#pragma once

#include <vector>

#include <cstdint>
#include <stdexcept>

namespace moduru {

	class VecUtil {

	public:
		static std::vector<char> CopyOfRange(std::vector<char>* src, int offset, int length);
		static std::vector<double> CopyOf(std::vector<double> src, int newLength);

		static std::vector<short> BytesToShorts(std::vector<char> src);
		static bool Equals(std::vector<char> a, std::vector<char> b);

		template<typename T>
		static void VecCopy(std::vector<T>* src, int srcPos, std::vector<T>* dest, int destPos, int length) {
			if (destPos + length > dest->size()) throw std::invalid_argument("Destination out of bounds!\n");
			if (srcPos + length > src->size()) throw std::invalid_argument("Source out of bounds!\n");
			if (src == dest) dest = new std::vector<T>(src->size());
			for (int i = 0; i < length; i++)
				(*dest)[i + destPos] = (*src)[i + srcPos];
		}

		static std::vector<int8_t> CopyOf(std::vector<int8_t> src, int newLength);
		static std::vector<int> CopyOf(std::vector<int> src, int newLength);

	};

}
