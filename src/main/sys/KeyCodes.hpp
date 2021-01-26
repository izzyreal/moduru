#pragma once

#ifdef __APPLE__
#elif defined _WIN32
// Include Windows header that has VK_ info
#elif defined __linux__
#include <X11/keysymdef.h>
#endif

#include <string>
#include <map>

namespace moduru::sys
{

class KeyCodes
{
public:
    static inline std::map<int, std::string> keyCodeNames = {
        
#ifdef __APPLE__
        { 122, "F1"  },
        { 120, "F2"  },
        {  99, "F3"  },
        { 118, "F4"  },
        { 96 , "F5"  },
        { 97 , "F6"  },
        { 98 , "F7"  },
        { 100, "F8"  },
        { 101, "F9"  },
        { 109, "F10" },
        { 103, "F11" },
        { 111, "F12" },
        
        { 53, "esc" },
        { 50, "` (backtick)" },
        { 10, "§ (section mark)" },
        { 48, "tab" },
        { 57, "caps lock" },
        { 56, "left shift" },
        { 63, "fn" },
        { 59, "left control" },
        { 58, "left option/alt" },
        { 55, "command" },
        { 27, "minus" },
        { 24, "equals" },
        { 51, "delete" },
        { 33, "{ (left bracket)" },
        { 30, "} (right bracket)" },
        { 42, "\\ (backslash)" },
        { 41, "; (semicolon)" },
        { 39, "' (quote)" },
        { 36, "return" },
        { 43, ", (comma)" },
        { 47, ". (period)" },
        { 44, "/ (slash)" },
        { 60, "right shift" },
        { 61, "right option/alt" },
        { 49, "space" },
        
        { 82, "Keypad 0" },
        { 83, "Keypad 1" },
        { 84, "Keypad 2" },
        { 85, "Keypad 3" },
        { 86, "Keypad 4" },
        { 87, "Keypad 5" },
        { 88, "Keypad 6" },
        { 89, "Keypad 7" },
        { 91, "Keypad 8" },
        { 92, "Keypad 9" },
        
        { 29, "0" },
        { 18, "1" },
        { 19, "2" },
        { 20, "3" },
        { 21, "4" },
        { 23, "5" },
        { 22, "6" },
        { 26, "7" },
        { 28, "8" },
        { 25, "9" },
        
        { 12, "q" },
        { 13, "w" },
        { 14, "e" },
        { 15, "r" },
        { 17, "t" },
        { 16, "y" },
        { 32, "u" },
        { 34, "i" },
        { 31, "o" },
        { 35, "p" },
        { 0 , "a" },
        { 1 , "s" },
        { 2 , "d" },
        { 3 , "f" },
        { 5 , "g" },
        { 4 , "h" },
        { 38, "j" },
        { 40, "k" },
        { 37, "l" },
        { 6 , "z" },
        { 7 , "x" },
        { 8 , "c" },
        { 9 , "v" },
        { 11, "b" },
        { 45, "n" },
        { 46, "m" },
        
        { 123, "cursor left"  },
        { 124, "cursor right" },
        { 126, "cursor up"    },
        { 125, "cursor down"  },
        
        { 65, "keypad decimal" },
        { 67, "keypad multiply" },
        { 69, "keypad plus" },
        { 71, "keypad clear" },
        { 75, "keypad divide" },
        { 76, "keypad enter" },
        { 78, "keypad minus" },
        { 81, "keypad equals" },
        
        { 115, "home" },
        { 116, "page up" },
        { 119, "end" },
        { 121, "page down" }
        
#elif defined _WIN32

        { 0x70, "F1"  },
        { 0x71, "F2"  },
        { 0x72, "F3"  },
        { 0x73, "F4"  },
        { 0x74, "F5"  },
        { 0x75 , "F6"  },
        { 0x76, "F7"  },
        { 0x77, "F8"  },
        { 0x78, "F9"  },
        { 0x79, "F10" },
        { 0x7A, "F11" },
        { 0x7B, "F12" },
        
        { 0x1B, "esc" },
        { 0xC0, "` (backtick)" },
        { 0x09, "tab" },
        { 0x14, "caps lock" },
        { 0x10, "left shift" },
        { 0x11, "left control" },
        { 0x12, "left alt" },
        { 0xBD, "minus" },
        { 0xBB, "equals" },
        { 0x2D, "insert" },
        { 0x2E, "delete" },
        { 0xDB, "{ (left bracket)" },
        { 0xDD, "} (right bracket)" },
        { 0xDC, "\\ (backslash)" },
        { 0xBA, "; (semicolon)" },
        { 0xDE, "' (quote)" },
        { 0x0D, "return" },
        { 0xBC, ", (comma)" },
        { 0xBE, ". (period)" },
        { 0xBF, "/ (slash)" },
        { 0x20, "space" },
        
        { 0x60, "Keypad 0" },
        { 0x61, "Keypad 1" },
        { 0x62, "Keypad 2" },
        { 0x63, "Keypad 3" },
        { 0x64, "Keypad 4" },
        { 0x65, "Keypad 5" },
        { 0x66, "Keypad 6" },
        { 0x67, "Keypad 7" },
        { 0x68, "Keypad 8" },
        { 0x69, "Keypad 9" },
        
        { 0x30, "0" },
        { 0x31, "1" },
        { 0x32, "2" },
        { 0x33, "3" },
        { 0x34, "4" },
        { 0x35, "5" },
        { 0x36, "6" },
        { 0x37, "7" },
        { 0x38, "8" },
        { 0x39, "9" },
        
        { 0x41, "a" },
        { 0x42, "b" },
        { 0x43, "c" },
        { 0x44, "d" },
        { 0x45, "e" },
        { 0x46, "f" },
        { 0x47, "g" },
        { 0x48, "h" },
        { 0x49, "i" },
        { 0x4A, "j" },
        { 0x4B, "k" },
        { 0x4C, "l" },
        { 0x4D, "m" },
        { 0x4E, "n" },
        { 0x4F, "o" },
        { 0x50, "p" },
        { 0x51, "q" },
        { 0x52, "r" },
        { 0x53, "s" },
        { 0x54, "t" },
        { 0x55, "u" },
        { 0x56, "v" },
        { 0x57, "w" },
        { 0x58, "x" },
        { 0x59, "y" },
        { 0x5A, "z" },
        
        { 0x25, "cursor left"  },
        { 0x27, "cursor right" },
        { 0x26, "cursor up"    },
        { 0x28, "cursor down"  },
        
        { 0x6E, "keypad decimal" },
        { 0x6A, "keypad multiply" },
        { 0x6B, "keypad plus" },
        { 0x0C, "keypad clear" },
        { 0x6F, "keypad divide" },
        { 0x6D, "keypad minus" },
        
        { 0x24, "home" },
        { 0x21, "page up" },
        { 0x23, "end" },
        { 0x22, "page down" }
        
#elif defined __linux__

        { XK_F1, "F1"  },
        { XK_F2, "F2"  },
        { XK_F3, "F3"  },
        { XK_F4, "F4"  },
        { XK_F5, "F5"  },
        { XK_F6, "F6" },
        { XK_F7, "F7"  },
        { XK_F8, "F8"  },
        { XK_F9, "F9"  },
        { XK_F10, "F10" },
        { XK_F11, "F11" },
        { XK_F12, "F12" },
        
        { XK_Escape, "esc" },
        { XK_Tab, "tab" },
        { XK_Caps_Lock, "caps lock" },
        { XK_Shift_L, "left shift" },
        { XK_Control_L, "left control" },
        { XK_Alt_L, "left alt" },
        { XK_minus, "minus" },
        { XK_equal, "equals" },
        { XK_Insert, "insert" },
        { XK_Delete, "delete" },
        { XK_bracketleft, "{ (left bracket)" },
        { XK_bracketright, "} (right bracket)" },
        { XK_backslash, "\\ (backslash)" },
        { XK_semicolon, "; (semicolon)" },
        { XK_apostrophe, "' (quote)" },
        { XK_Return, "return" },
        { XK_comma, ", (comma)" },
        { XK_period, ". (period)" },
        { XK_slash, "/ (slash)" },
        { XK_space, "space" },
        
        { XK_0, "0" },
        { XK_1, "1" },
        { XK_2, "2" },
        { XK_3, "3" },
        { XK_4, "4" },
        { XK_5, "5" },
        { XK_6, "6" },
        { XK_7, "7" },
        { XK_8, "8" },
        { XK_9, "9" },
        
        { XK_a, "a" },
        { XK_b, "b" },
        { XK_c, "c" },
        { XK_d, "d" },
        { XK_e, "e" },
        { XK_f, "f" },
        { XK_g, "g" },
        { XK_h, "h" },
        { XK_i, "i" },
        { XK_j, "j" },
        { XK_k, "k" },
        { XK_l, "l" },
        { XK_m, "m" },
        { XK_n, "n" },
        { XK_o, "o" },
        { XK_p, "p" },
        { XK_q, "q" },
        { XK_r, "r" },
        { XK_s, "s" },
        { XK_t, "t" },
        { XK_u, "u" },
        { XK_v, "v" },
        { XK_w, "w" },
        { XK_x, "x" },
        { XK_y, "y" },
        { XK_z, "z" },
        
        { XK_Left, "cursor left"  },
        { XK_Right, "cursor right" },
        { XK_Up, "cursor up"    },
        { XK_Down, "cursor down"  },
        
        { XK_Home, "home" },
        { XK_Page_Up, "page up" },
        { XK_End, "end" },
        { XK_Page_Down, "page down" }
#endif
        
    };
    
private:
    template<typename A, typename B>
    static std::pair<B,A> flip_pair(const std::pair<A,B> &p)
    {
        return std::pair<B,A>(p.second, p.first);
    }
    
    template<typename A, typename B>
    static std::map<B,A> flip_map(const std::map<A,B> &src)
    {
        std::map<B,A> dst;
        transform(src.begin(), src.end(), inserter(dst, dst.begin()),
                  flip_pair<A,B>);
        return dst;
    }
    
public:
    static const std::map<std::string, int> nameKeyCodes()
    {
        static auto flippedMap = flip_map(keyCodeNames);
        return flippedMap;
    }
};
}
