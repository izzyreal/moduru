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
    //auto uid = getuid();
    unsigned int uid = 503;
    auto pwuid = getpwuid(uid);
    auto homePath = string(getenv("HOME"));
    printf("home: %s\n", homePath.c_str());
//    char* home = getpwuid(getuid())->pw_dir;
//    string res = string(home);
    return "/Users/admin/Library/Developer/CoreSimulator/Devices/BC2607E1-B614-4A67-B285-8881021AEC7E/data/Root";
    //return u8"/Users/Izm\u00F8r";
}
#endif
