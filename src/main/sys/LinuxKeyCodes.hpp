#pragma once

#include <X11/keysymdef.h>

#include <string>
#include <map>

namespace moduru::sys
{
class LinuxKeyCodes
{
public:
    static inline std::map<int, std::string> keyCodeNames = {
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
    };
    
};
}
