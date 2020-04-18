#pragma once

#include <set>
#include <string>

using namespace std;

namespace moduru::raw::fat {
	class ShortName;
}

namespace moduru::raw::fat {

	class ShortNameGenerator
	{

	private:
		set<string> usedNames;

	public:
		static bool validChar(char toTest);
		static bool isSkipChar(char c);

	private:
		string tidyString(string dirty);
		bool cleanString(string s);
		string stripLeadingPeriods(string str);

	public:
		ShortName generateShortName(const string& longFullName);

		ShortNameGenerator(const set<string>& usedNames);
	};
}
