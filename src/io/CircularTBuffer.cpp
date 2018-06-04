#include "CircularTBuffer.hpp"

using namespace moduru::io;
using namespace std;

CircularTBuffer::CircularTBuffer(int size) {
	data = vector<float>(size);
}

void CircularTBuffer::read(std::vector<float>* dest, int srcOffset, int length) {
	auto oldReadPos = readPos;
	for (int i = 0; i < length; i++) {
		if (readPos + srcOffset >= data.size()) readPos -= data.size();
		while ((readPos + srcOffset) < 0) readPos += data.size();
		(*dest)[i] = data[readPos + srcOffset];
		readPos++;
	}
	readPos = oldReadPos;
}

void CircularTBuffer::multiply(int relativePos, float factor) {
	if (readPos + relativePos >= data.size()) readPos -= data.size();
	while ((readPos + relativePos) < 0) readPos += data.size();
	data[readPos + relativePos] *= factor;
}

void CircularTBuffer::moveReadPos(int amount) {
	readPos += amount;
}

void CircularTBuffer::write(std::vector<float>* src) {
	for (int i = 0; i < src->size(); i++) {
		if (writePos == data.size()) writePos = 0;
		data[writePos++] = (*src)[i];
	}
	readPos = writePos;
}

CircularTBuffer::~CircularTBuffer() {
}
