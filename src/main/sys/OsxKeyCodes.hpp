#pragma once

#include <map>

namespace moduru::sys
{
class OsxKeyCodes
{
public:
    static inline std::map<int, std::string> keyCodeNames = {
        { 107, "F1"  },
        { 113, "F2"  },
        { 160, "F3"  },
        { 131, "F4"  },
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
    };
    
};
}
