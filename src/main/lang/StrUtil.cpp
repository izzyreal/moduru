#include <lang/StrUtil.hpp>

#ifdef __linux__
#include <cstring>
#endif

#include <sstream>

using namespace moduru::lang;
using namespace std;

string StrUtil::replaceAll(string str, char c, string replacement) {
	if (replacement.length() > 1) return "<error>";
	string res;
	for (char ch : str) {
		if (ch == c) {
			if (replacement.length() == 0 || replacement == "") {
				continue;
			}
			else {
				res.push_back(replacement[0]);
			}
		}
		else {
			res.push_back(ch);
		}
	}
	return res;
}

bool StrUtil::eqIgnoreCase(string s1, string s2) {
	if (s1.length() != s2.length()) return false;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != tolower(s2[i]) && s1[i] != toupper(s2[i])) return false;
	}
	return true;
}

string StrUtil::toUpper(string str) {
	string res = str;
	for (int i = 0; i < res.length(); i++)
		res[i] = toupper(res[i]);
	return res;
}

string StrUtil::toLower(string str)
{
	string res = str;
	
	for (int i = 0; i < res.length(); i++)
	{
		res[i] = tolower(res[i]);
	}

	return res;
}

string StrUtil::padLeft(string str, string pad, int size)
{
	if (str.length() >= size)
	{
		return str;
	}

	string result = "";

	for (int i = 0; i < size - str.size(); i++)
	{
		result.append(pad);
	}
	
	int counter = 0;
	
	for (int i = size - static_cast<int>(str.size()); i < size; i++)
	{
		result.append(str.substr(counter++, 1));
	}
	
	return result;
};

string StrUtil::padRight(string str, string pad, int size)
{
	if (str.length() >= size)
	{
		return str;
	}

	string result = "";
	
	for (int i = 0; i < str.size(); i++)
	{
		result.append(str.substr(i, 1));
	}
	
	for (int i = static_cast<int>(str.size()); i < size; i++)
	{
		result.append(pad);
	}
	
	return result;
}

string StrUtil::trim(const string& str) {
	string copy = str;
	while (!copy.empty() && isspace(copy.back())) copy.pop_back();
	return copy;
}

string StrUtil::TrimDecimals(const string& str, int count) {
	try {
		// We check if we're dealing with a float.
        stof(str);
        
        string copy = str;
        const int index = static_cast<int>(str.find("."));
        const int numberOfDecimalsFound = static_cast<int>(str.length()) - index + 1;
        if (numberOfDecimalsFound <= count) {
            // Trimming is not possible
            return str;
        }
        copy = copy.substr(0, index + 1 + count);
        return copy;
	}
	catch (const exception& e) {
        // In this case we're fine returning str
	}
	return str;
}

string StrUtil::TrimDecimals(double d, int count) {
	return TrimDecimals(to_string(d), count);
}

bool StrUtil::hasEnding(std::string const &fullString, std::string const &ending) {
	if (fullString.length() >= ending.length()) {
		return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
	}
	else {
		return false;
	}
}

string StrUtil::subStr(const string str, int start, int end)
{
	static char cRes[1024];
	char* pRes = cRes;
	int i = 0, iPos = 0;
	int iByte;
	auto cStr = str.c_str();
	auto length = end - start;
	while (cStr[i] != '\0') {
		iByte = cntByte(cStr[i]);
		if (start <= iPos && iPos < start + length) {
			memcpy(pRes, (cStr + i), iByte);
			pRes += iByte;
		}
		i += iByte;
		iPos++;
	}
	*pRes = '\0';
	return cRes;
}

int StrUtil::cntByte(unsigned char cChar)
{
	int iByte;

	if ((cChar >= 0x00) && (cChar <= 0x7f)) {
		iByte = 1;
	}
	else if ((cChar >= 0xc2) && (cChar <= 0xdf)) {
		iByte = 2;
	}
	else if ((cChar >= 0xe0) && (cChar <= 0xef)) {
		iByte = 3;
	}
	else if ((cChar >= 0xf0) && (cChar <= 0xf7)) {
		iByte = 4;
	}
	else if ((cChar >= 0xf8) && (cChar <= 0xfb)) {
		iByte = 5;
	}
	else if ((cChar >= 0xfc) && (cChar <= 0xfd)) {
		iByte = 6;
	}
	else {
		iByte = 0;
	}

	return iByte;
}

string ltrim(const string& s, char c)
{
    size_t start = s.find_first_not_of(c);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
string rtrim(const string& s, char c)
{
    size_t end = s.find_last_not_of(c);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
string trim_by_c(const string& s, char c)
{
    return ltrim(rtrim(s, c), c);
}

vector<string> StrUtil::split(const string& s, char c)
{
    auto str = trim_by_c(s, c);
	stringstream ss = stringstream(str);
	string segment;
	vector<string> seglist;

	while (getline(ss, segment, c))
		seglist.push_back(segment);

    return seglist;
}
