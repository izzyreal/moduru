#pragma once

#ifdef __APPLE__
#include <Carbon/Carbon.h>
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
        { kVK_F1, "F1"  },
        { kVK_F2, "F2"  },
        { kVK_F3, "F3"  },
        { kVK_F4, "F4"  },
        { kVK_F5 , "F5"  },
        { kVK_F6 , "F6"  },
        { kVK_F7 , "F7"  },
        { kVK_F8, "F8"  },
        { kVK_F9, "F9"  },
        { kVK_F10, "F10" },
        { kVK_F11, "F11" },
        { kVK_F12, "F12" },
        
        { kVK_Escape, "esc" },
        { kVK_ANSI_Grave, "` (backtick)" },
        { kVK_ISO_Section, "§ (section mark)" },
        { kVK_Tab, "tab" },
        { kVK_CapsLock, "caps lock" },
        { kVK_Shift, "left shift" },
        { kVK_Function, "fn" },
        { kVK_Control, "left control" },
        { kVK_Option, "left option/alt" },
        { kVK_Command, "command" },
        { kVK_ANSI_Minus, "minus" },
        { kVK_ANSI_Equal, "equals" },
        { kVK_Delete, "delete" },
        { kVK_ANSI_LeftBracket, "{ (left bracket)" },
        { kVK_ANSI_RightBracket, "} (right bracket)" },
        { kVK_ANSI_Backslash, "\\ (backslash)" },
        { kVK_ANSI_Semicolon, "; (semicolon)" },
        { kVK_ANSI_Quote, "' (quote)" },
        { kVK_Return, "return" },
        { kVK_ANSI_Comma, ", (comma)" },
        { kVK_ANSI_Period, ". (period)" },
        { kVK_ANSI_Slash, "/ (slash)" },
        { kVK_RightShift, "right shift" },
        { kVK_RightOption, "right option/alt" },
        { kVK_Space, "space" },
        
        { kVK_ANSI_Keypad0, "Keypad 0" },
        { kVK_ANSI_Keypad1, "Keypad 1" },
        { kVK_ANSI_Keypad2, "Keypad 2" },
        { kVK_ANSI_Keypad3, "Keypad 3" },
        { kVK_ANSI_Keypad4, "Keypad 4" },
        { kVK_ANSI_Keypad5, "Keypad 5" },
        { kVK_ANSI_Keypad6, "Keypad 6" },
        { kVK_ANSI_Keypad7, "Keypad 7" },
        { kVK_ANSI_Keypad8, "Keypad 8" },
        { kVK_ANSI_Keypad9, "Keypad 9" },
        
        { kVK_ANSI_0, "0" },
        { kVK_ANSI_1, "1" },
        { kVK_ANSI_2, "2" },
        { kVK_ANSI_3, "3" },
        { kVK_ANSI_4, "4" },
        { kVK_ANSI_5, "5" },
        { kVK_ANSI_6, "6" },
        { kVK_ANSI_7, "7" },
        { kVK_ANSI_8, "8" },
        { kVK_ANSI_8, "9" },
        
        { kVK_ANSI_Q, "q" },
        { kVK_ANSI_W, "w" },
        { kVK_ANSI_E, "e" },
        { kVK_ANSI_R, "r" },
        { kVK_ANSI_T, "t" },
        { kVK_ANSI_Y, "y" },
        { kVK_ANSI_U, "u" },
        { kVK_ANSI_I, "i" },
        { kVK_ANSI_O, "o" },
        { kVK_ANSI_P, "p" },
        { kVK_ANSI_A, "a" },
        { kVK_ANSI_S, "s" },
        { kVK_ANSI_D, "d" },
        { kVK_ANSI_F, "f" },
        { kVK_ANSI_G, "g" },
        { kVK_ANSI_H, "h" },
        { kVK_ANSI_J, "j" },
        { kVK_ANSI_K, "k" },
        { kVK_ANSI_L, "l" },
        { kVK_ANSI_Z, "z" },
        { kVK_ANSI_X, "x" },
        { kVK_ANSI_C, "c" },
        { kVK_ANSI_V, "v" },
        { kVK_ANSI_B, "b" },
        { kVK_ANSI_N, "n" },
        { kVK_ANSI_M, "m" },
        
        { kVK_LeftArrow, "cursor left"  },
        { kVK_RightArrow, "cursor right" },
        { kVK_UpArrow, "cursor up"    },
        { kVK_DownArrow, "cursor down"  },
        
        { kVK_ANSI_KeypadDecimal, "keypad decimal" },
        { kVK_ANSI_KeypadMultiply, "keypad multiply" },
        { kVK_ANSI_KeypadPlus, "keypad plus" },
        { kVK_ANSI_KeypadClear, "keypad clear" },
        { kVK_ANSI_KeypadDivide, "keypad divide" },
        { kVK_ANSI_KeypadEnter, "keypad enter" },
        { kVK_ANSI_KeypadMinus, "keypad minus" },
        { kVK_ANSI_KeypadEquals, "keypad equals" },
        
        { kVK_Home, "home" },
        { kVK_PageUp, "page up" },
        { kVK_End, "end" },
        { kVK_PageDown, "page down" }
        
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
