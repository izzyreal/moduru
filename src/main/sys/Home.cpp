#define _HAS_STD_BYTE 0
#define _CRT_SECURE_NO_WARNINGS
#include <sys/Home.hpp>

#include <Logger.hpp>

#ifdef __APPLE__
#include <pwd.h>
#include <unistd.h>
#endif

#ifdef _WIN32
#include <Windows.h>
#include <ShlObj.h>
#include <codecvt>
#endif

using namespace moduru::sys;
using namespace std;


#ifdef __linux__
#include <unistd.h>
#include <pwd.h>
#endif

#ifdef _WIN32

std::string utf16ToUtf8(const std::wstring& utf16Str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
    return conv.to_bytes(utf16Str);
}

string Home::get() {

    wchar_t path[MAX_PATH];
    auto shGetRes = SHGetFolderPathW(NULL, CSIDL_PROFILE, NULL, 0, path);
    if (shGetRes == S_OK)
    {
        return utf16ToUtf8(wstring(path));
    }
    else
    {
        auto homeDrive = string(getenv("HOMEDRIVE"));
        auto homePath = string(getenv("HOMEPATH"));
        return homeDrive + homePath;
    }
}
#else
string Home::get() {
    char* home = getpwuid(getuid())->pw_dir;
    return string(home);
}
#endif