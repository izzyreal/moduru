#pragma once
#include <string>
#include <vector>

using namespace std;

namespace moduru {

	namespace lang {

		class StrUtil {

		public:
			static string padLeft(string str, string pad, int size);
			static string padRight(string str, string pad, int size);
			static string trim(const string& str);
			static string toUpper(string str);
			static string toLower(string str);
			static bool eqIgnoreCase(string s1, string s2);
			static string replaceAll(string str, char c, string replacement);
			static string TrimDecimals(const string& str, int decimalCount);
			static string TrimDecimals(float f, int decimalCount);
			
			static bool hasEnding(string const &fullString, string const &ending);

			static string subStr(const string str, int start, int end);
			static int cntByte(unsigned char cChar);

			static vector<string> split(const string& s, char c);
		};
	}
}
