#pragma once

#include <string>
#include <map>

namespace moduru::sys
{
class WindowsKeyCodes
{
public:
    static inline std::map<int, std::string> keyCodeNames = {
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
    };
    
};
}
