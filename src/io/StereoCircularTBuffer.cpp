#include "StereoCircularTBuffer.hpp"

#include <Logger.hpp>

using namespace moduru::io;
using namespace std;

StereoCircularTBuffer::StereoCircularTBuffer(int size) {
	dataL = vector<float>(size);
	dataR = vector<float>(size);
}

void StereoCircularTBuffer::read(vector<float>* destL, vector<float>* destR, int srcOffset, int length) {
	auto oldReadPos = readPos;
	for (int i = 0; i < length; i++) {
		if (readPos + srcOffset >= dataL.size()) readPos -= dataL.size();
		while ((readPos + srcOffset) < 0) readPos += dataL.size();
		(*destL)[i] = dataL[readPos + srcOffset];
		(*destR)[i] = dataR[readPos + srcOffset];
		readPos++;
	}
	readPos = oldReadPos;
}

void encodeMidSide1(const float& l, const float& r, float& m, float& s) {
	m = 0.5f * (l + r);
	s = 0.5f * (l - r);
}

void decodeMidSide1(float& l, float& r, const float& m, const float& s) {
	l = m + s;
	r = m - s;
}

void StereoCircularTBuffer::multiply(int relativePos, float factor, bool left) {
	vector<float>* data = left ? &dataL : &dataR;
	if (readPos + relativePos >= data->size()) readPos -= data->size();
	while ((readPos + relativePos) < 0) readPos += data->size();
	(*data)[readPos + relativePos] *= factor;
}

void StereoCircularTBuffer::encodeMidSide(int relativePos) {
	if (readPos + relativePos >= dataL.size()) readPos -= dataL.size();
	while ((readPos + relativePos) < 0) readPos += dataL.size();
	const auto l = dataL[readPos + relativePos];
	const auto r = dataR[readPos + relativePos];
	float m, s;
	encodeMidSide1(l, r, m, s);
	dataL[readPos + relativePos] = m;
	dataR[readPos + relativePos] = s;
}

void StereoCircularTBuffer::decodeMidSide(int relativePos) {
	if (readPos + relativePos >= dataL.size()) readPos -= dataL.size();
	while ((readPos + relativePos) < 0) readPos += dataL.size();
	const auto m = dataL[readPos + relativePos];
	const auto s = dataR[readPos + relativePos];
	float l, r;
	decodeMidSide1(l, r, m, s);
	dataL[readPos + relativePos] = l;
	dataR[readPos + relativePos] = r;
}

void StereoCircularTBuffer::moveReadPos(int amount) {
	readPos += amount;
	if (readPos >= dataL.size()) readPos -= dataL.size();
	while ((readPos) < 0) readPos += dataL.size();
}

void StereoCircularTBuffer::write(vector<float>* srcL, vector<float>* srcR) {
	for (int i = 0; i < srcL->size(); i++) {
		if (writePos >= dataL.size()) writePos = 0;
		dataL[writePos] = (*srcL)[i];
		dataR[writePos] = (*srcR)[i];
		writePos++;
	}
	//readPos = writePos;
}

StereoCircularTBuffer::~StereoCircularTBuffer() {
}
