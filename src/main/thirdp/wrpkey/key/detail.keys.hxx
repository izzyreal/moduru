#pragma once

#define _wrpx11 1

#if __GNUC__ == 4 &&  __GNUC_MINOR__ < 7
typedef std::tuple<const char* const, const int> keys_element_t;
#else
using keys_element_t = std::tuple<const char* const, const int>;
#endif

#if defined(_WIN64) || defined(_WIN32)
  #include "detail.keys.Windows.hxx"

#elif defined(__APPLE__)
  #include "detail.keys.OSX.hxx"
#elif defined(__linux)
  #if defined _wrpx11
    #include "detail.keys.LinuxX.hxx"
  #else
    #include "detail.keys.Linux.hxx"
  #endif
#endif
