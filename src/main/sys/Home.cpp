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
#endif

using namespace moduru::sys;
using namespace std;


#ifdef __linux__
#include <unistd.h>
#include <pwd.h>
#endif

#ifdef _WIN32
string Home::get() {

    char path[MAX_PATH];
    if (SHGetFolderPathA(NULL, CSIDL_PROFILE, NULL, 0, path) != S_OK)
    {
        return string(path);
    }
    else
    {
        auto homeDrive = string(getenv("HOMEDRIVE"));
        auto homePath = string(getenv("HOMEPATH"));
        auto oldResult = homeDrive + homePath;
        return homeDrive + homePath;
    }
}
#else
string Home::get() {
    char* home = getpwuid(getuid())->pw_dir;
    string res = string(home);
    return res;
    //return u8"/Users/Izm\u00F8r";
}
#endif