#include <VecUtil.hpp>

#include <file/ByteUtil.hpp>

using namespace moduru;
using namespace std;

vector<char> VecUtil::CopyOfRange(vector<char>* src, int offset, int endOffset) {
	return vector<char>(src->begin() + offset, src->begin() + endOffset);
}

vector<double> CopyOf(vector<double> src, int newLength) {
	while (src.size() < newLength) {
		src.push_back(0);
	}
	return vector<double>(src.begin(), src.begin() + newLength);
}

vector<short> VecUtil::BytesToShorts(vector<char> src) {
	if (src.size() == 0 || src.size() % 2 != 0) return vector<short>(0);
	int length = (int) (src.size()) / 2;
	auto res = vector<short>(length);
	int charCounter = 0;
	auto pair = vector<char>(2);
	for (int i = 0; i < length; i++) {
		pair[0] = src[charCounter++];
		pair[1] = src[charCounter++];
		res[i] = moduru::file::ByteUtil::bytes2short(pair);
	}
	return res;
}

bool VecUtil::Equals(vector<char> a, vector<char> b) {
	if (a.size() != b.size()) return false;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i]) return false;
	return true;
}

vector<int8_t> VecUtil::CopyOf(vector<int8_t> src, int newLength) {
	while (src.size() < newLength) {
		src.push_back(0);
	}
	return vector<int8_t>(src.begin(), src.begin() + newLength);
}

vector<int> VecUtil::CopyOf(vector<int> src, int newLength) {
	while (src.size() < newLength) {
		src.push_back(0);
	}
	vector<int> res(newLength);
	int elementsToCopy = newLength < src.size() ? newLength : src.size();
	for (int i = 0; i < elementsToCopy; i++) {
		if (i == src.size()) break;
		res[i] = src[i];
	}
	return res;
}
