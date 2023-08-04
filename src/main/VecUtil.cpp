#include <VecUtil.hpp>

using namespace moduru;
using namespace std;

vector<char> VecUtil::CopyOfRange(const vector<char>& src, int offset, int endOffset)
{
	return vector<char>(begin(src) + offset, begin(src) + endOffset);
}

vector<double> CopyOf(const vector<double>& src, int newLength)
{
    if (src.size() < newLength)
    {
        vector<double> srcCopy(begin(src), end(src));
        while (srcCopy.size() < newLength)
            srcCopy.push_back(0);
        return srcCopy;
    }
    
	return vector<double>(src.begin(), src.begin() + newLength);
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
	int elementsToCopy = newLength < static_cast<int>(src.size() ? newLength : src.size());
	for (int i = 0; i < elementsToCopy; i++) {
		if (i == src.size()) break;
		res[i] = src[i];
	}
	return res;
}
