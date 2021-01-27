#pragma once

#ifdef __APPLE__
#include <Carbon/Carbon.h>
#elif defined _WIN32
#include <WinUser.h>
#elif defined __linux__
#include <X11/keysymdef.h>
#endif

#include <string>
#include <map>

namespace moduru::sys
{

class KeyCodes
{
private:
    enum moduruKeyCodes {
        MVK_F1,
        MVK_F2,
        MVK_F3,
        MVK_F4,
        MVK_F5,
        MVK_F6,
        MVK_F7,
        MVK_F8,
        MVK_F9,
        MVK_F10,
        MVK_F11,
        MVK_F12,

        MVK_Escape,
        MVK_ANSI_Grave,
        MVK_ISO_Section,
        MVK_Tab,
        MVK_CapsLock,
        MVK_Shift,
        MVK_Function,
        MVK_Control,
        MVK_Option,
        MVK_Command,
        MVK_ANSI_Minus,
        MVK_ANSI_Equal,
        MVK_Delete,
        MVK_Insert,
        MVK_ANSI_LeftBracket,
        MVK_ANSI_RightBracket,
        MVK_ANSI_Backslash,
        MVK_ANSI_Semicolon,
        MVK_ANSI_Quote,
        MVK_Return,
        MVK_ANSI_Comma,
        MVK_ANSI_Period,
        MVK_ANSI_Slash,
        MVK_RightShift,
        MVK_RightOption,
        MVK_Space,

        MVK_ANSI_Keypad0,
        MVK_ANSI_Keypad1,
        MVK_ANSI_Keypad2,
        MVK_ANSI_Keypad3,
        MVK_ANSI_Keypad4,
        MVK_ANSI_Keypad5,
        MVK_ANSI_Keypad6,
        MVK_ANSI_Keypad7,
        MVK_ANSI_Keypad8,
        MVK_ANSI_Keypad9,

        MVK_ANSI_0,
        MVK_ANSI_1,
        MVK_ANSI_2,
        MVK_ANSI_3,
        MVK_ANSI_4,
        MVK_ANSI_5,
        MVK_ANSI_6,
        MVK_ANSI_7,
        MVK_ANSI_8,
        MVK_ANSI_9,

        MVK_ANSI_Q,
        MVK_ANSI_W,
        MVK_ANSI_E,
        MVK_ANSI_R,
        MVK_ANSI_T,
        MVK_ANSI_Y,
        MVK_ANSI_U,
        MVK_ANSI_I,
        MVK_ANSI_O,
        MVK_ANSI_P,
        MVK_ANSI_A,
        MVK_ANSI_S,
        MVK_ANSI_D,
        MVK_ANSI_F,
        MVK_ANSI_G,
        MVK_ANSI_H,
        MVK_ANSI_J,
        MVK_ANSI_K,
        MVK_ANSI_L,
        MVK_ANSI_Z,
        MVK_ANSI_X,
        MVK_ANSI_C,
        MVK_ANSI_V,
        MVK_ANSI_B,
        MVK_ANSI_N,
        MVK_ANSI_M,

        MVK_LeftArrow,
        MVK_RightArrow,
        MVK_UpArrow,
        MVK_DownArrow,

        MVK_ANSI_KeypadDecimal,
        MVK_ANSI_KeypadMultiply,
        MVK_ANSI_KeypadPlus,
        MVK_ANSI_KeypadClear,
        MVK_ANSI_KeypadDivide,
        MVK_ANSI_KeypadEnter,
        MVK_ANSI_KeypadMinus,
        MVK_ANSI_KeypadEquals,

        MVK_Home,
        MVK_PageUp,
        MVK_End,
        MVK_PageDown,
    };

    static inline std::map<int, std::string> names = {
        { MVK_F1, "F1"  },
        { MVK_F2, "F2"  },
        { MVK_F3, "F3"  },
        { MVK_F4, "F4"  },
        { MVK_F5 , "F5"  },
        { MVK_F6 , "F6"  },
        { MVK_F7 , "F7"  },
        { MVK_F8, "F8"  },
        { MVK_F9, "F9"  },
        { MVK_F10, "F10" },
        { MVK_F11, "F11" },
        { MVK_F12, "F12" },

        { MVK_Escape, "esc" },
        { MVK_ANSI_Grave, "` (backtick)" },
        { MVK_ISO_Section, "§ (section mark)" },
        { MVK_Tab, "tab" },
        { MVK_CapsLock, "caps lock" },
        { MVK_Shift, "left shift" },
        { MVK_Function, "fn" },
        { MVK_Control, "left control" },
        { MVK_Option, "left option/alt" },
        { MVK_Command, "command" },
        { MVK_ANSI_Minus, "minus" },
        { MVK_ANSI_Equal, "equals" },
        { MVK_Delete, "delete" },
        { MVK_Insert, "insert" },
        { MVK_ANSI_LeftBracket, "{ (left bracket)" },
        { MVK_ANSI_RightBracket, "} (right bracket)" },
        { MVK_ANSI_Backslash, "\\ (backslash)" },
        { MVK_ANSI_Semicolon, "; (semicolon)" },
        { MVK_ANSI_Quote, "' (quote)" },
        { MVK_Return, "return" },
        { MVK_ANSI_Comma, ", (comma)" },
        { MVK_ANSI_Period, ". (period)" },
        { MVK_ANSI_Slash, "/ (slash)" },
        { MVK_RightShift, "right shift" },
        { MVK_RightOption, "right option/alt" },
        { MVK_Space, "space" },

        { MVK_ANSI_Keypad0, "Keypad 0" },
        { MVK_ANSI_Keypad1, "Keypad 1" },
        { MVK_ANSI_Keypad2, "Keypad 2" },
        { MVK_ANSI_Keypad3, "Keypad 3" },
        { MVK_ANSI_Keypad4, "Keypad 4" },
        { MVK_ANSI_Keypad5, "Keypad 5" },
        { MVK_ANSI_Keypad6, "Keypad 6" },
        { MVK_ANSI_Keypad7, "Keypad 7" },
        { MVK_ANSI_Keypad8, "Keypad 8" },
        { MVK_ANSI_Keypad9, "Keypad 9" },

        { MVK_ANSI_0, "0" },
        { MVK_ANSI_1, "1" },
        { MVK_ANSI_2, "2" },
        { MVK_ANSI_3, "3" },
        { MVK_ANSI_4, "4" },
        { MVK_ANSI_5, "5" },
        { MVK_ANSI_6, "6" },
        { MVK_ANSI_7, "7" },
        { MVK_ANSI_8, "8" },
        { MVK_ANSI_9, "9" },

        { MVK_ANSI_Q, "q" },
        { MVK_ANSI_W, "w" },
        { MVK_ANSI_E, "e" },
        { MVK_ANSI_R, "r" },
        { MVK_ANSI_T, "t" },
        { MVK_ANSI_Y, "y" },
        { MVK_ANSI_U, "u" },
        { MVK_ANSI_I, "i" },
        { MVK_ANSI_O, "o" },
        { MVK_ANSI_P, "p" },
        { MVK_ANSI_A, "a" },
        { MVK_ANSI_S, "s" },
        { MVK_ANSI_D, "d" },
        { MVK_ANSI_F, "f" },
        { MVK_ANSI_G, "g" },
        { MVK_ANSI_H, "h" },
        { MVK_ANSI_J, "j" },
        { MVK_ANSI_K, "k" },
        { MVK_ANSI_L, "l (letter L)" },
        { MVK_ANSI_Z, "z" },
        { MVK_ANSI_X, "x" },
        { MVK_ANSI_C, "c" },
        { MVK_ANSI_V, "v" },
        { MVK_ANSI_B, "b" },
        { MVK_ANSI_N, "n" },
        { MVK_ANSI_M, "m" },

        { MVK_LeftArrow, "cursor left"  },
        { MVK_RightArrow, "cursor right" },
        { MVK_UpArrow, "cursor up"    },
        { MVK_DownArrow, "cursor down"  },

        { MVK_ANSI_KeypadDecimal, "keypad decimal" },
        { MVK_ANSI_KeypadMultiply, "keypad multiply" },
        { MVK_ANSI_KeypadPlus, "keypad plus" },
        { MVK_ANSI_KeypadClear, "keypad clear" },
        { MVK_ANSI_KeypadDivide, "keypad divide" },
        { MVK_ANSI_KeypadEnter, "keypad enter" },
        { MVK_ANSI_KeypadMinus, "keypad minus" },
        { MVK_ANSI_KeypadEquals, "keypad equals" },

        { MVK_Home, "home" },
        { MVK_PageUp, "page up" },
        { MVK_End, "end" },
        { MVK_PageDown, "page down" }
    };

public:
    static inline std::map<int, std::string> keyCodeNames = {
        
#ifdef __APPLE__
        { kVK_F1, names[MVK_F1] },
        { kVK_F2, names[MVK_F2] },
        { kVK_F3, names[MVK_F3] },
        { kVK_F4, names[MVK_F4] },
        { kVK_F5 , names[MVK_F5] },
        { kVK_F6 , names[MVK_F6] },
        { kVK_F7 , names[MVK_F7] },
        { kVK_F8, names[MVK_F8] },
        { kVK_F9, names[MVK_F9] },
        { kVK_F10, names[MVK_F10] },
        { kVK_F11, names[MVK_F11] },
        { kVK_F12, names[MVK_F12] },
        
        { kVK_Escape, names[MVK_Escape] },
        { kVK_ANSI_Grave, names[MVK_ANSI_Grave] },
        { kVK_ISO_Section, names[MVK_ISO_Section] },
        { kVK_Tab, names[MVK_Tab] },
        { kVK_CapsLock, names[MVK_CapsLock] },
        { kVK_Shift, names[MVK_Shift] },
        { kVK_Function, names[MVK_Function] },
        { kVK_Control, names[MVK_Control] },
        { kVK_Option, names[MVK_Option] },
        { kVK_Command, names[MVK_Command] },
        { kVK_ANSI_Minus, names[MVK_ANSI_Minus] },
        { kVK_ANSI_Equal, names[MVK_ANSI_Equal] },
        { kVK_Delete, names[MVK_Delete] },
        { kVK_ANSI_LeftBracket, names[MVK_ANSI_LeftBracket] },
        { kVK_ANSI_RightBracket, names[MVK_ANSI_RightBracket] },
        { kVK_ANSI_Backslash, names[MVK_ANSI_Backslash] },
        { kVK_ANSI_Semicolon, names[MVK_ANSI_Semicolon] },
        { kVK_ANSI_Quote, names[MVK_ANSI_Quote] },
        { kVK_Return, names[MVK_Return] },
        { kVK_ANSI_Comma, names[MVK_ANSI_Comma] },
        { kVK_ANSI_Period, names[MVK_ANSI_Period] },
        { kVK_ANSI_Slash, names[MVK_ANSI_Slash] },
        { kVK_RightShift, names[MVK_RightShift] },
        { kVK_RightOption, names[MVK_RightOption] },
        { kVK_Space, names[MVK_Space] },
        
        { kVK_ANSI_Keypad0, names[MVK_ANSI_Keypad0] },
        { kVK_ANSI_Keypad1, names[MVK_ANSI_Keypad1] },
        { kVK_ANSI_Keypad2, names[MVK_ANSI_Keypad2] },
        { kVK_ANSI_Keypad3, names[MVK_ANSI_Keypad3] },
        { kVK_ANSI_Keypad4, names[MVK_ANSI_Keypad4] },
        { kVK_ANSI_Keypad5, names[MVK_ANSI_Keypad5] },
        { kVK_ANSI_Keypad6, names[MVK_ANSI_Keypad6] },
        { kVK_ANSI_Keypad7, names[MVK_ANSI_Keypad7] },
        { kVK_ANSI_Keypad8, names[MVK_ANSI_Keypad8] },
        { kVK_ANSI_Keypad9, names[MVK_ANSI_Keypad9] },
        
        { kVK_ANSI_0, names[MVK_ANSI_0] },
        { kVK_ANSI_1, names[MVK_ANSI_1] },
        { kVK_ANSI_2, names[MVK_ANSI_2] },
        { kVK_ANSI_3, names[MVK_ANSI_3] },
        { kVK_ANSI_4, names[MVK_ANSI_4] },
        { kVK_ANSI_5, names[MVK_ANSI_5] },
        { kVK_ANSI_6, names[MVK_ANSI_6] },
        { kVK_ANSI_7, names[MVK_ANSI_7] },
        { kVK_ANSI_8, names[MVK_ANSI_8] },
        { kVK_ANSI_9, names[MVK_ANSI_9] },
        
        { kVK_ANSI_Q, names[MVK_ANSI_Q] },
        { kVK_ANSI_W, names[MVK_ANSI_W] },
        { kVK_ANSI_E, names[MVK_ANSI_E] },
        { kVK_ANSI_R, names[MVK_ANSI_R] },
        { kVK_ANSI_T, names[MVK_ANSI_T] },
        { kVK_ANSI_Y, names[MVK_ANSI_Y] },
        { kVK_ANSI_U, names[MVK_ANSI_U] },
        { kVK_ANSI_I, names[MVK_ANSI_I] },
        { kVK_ANSI_O, names[MVK_ANSI_O] },
        { kVK_ANSI_P, names[MVK_ANSI_P] },
        { kVK_ANSI_A, names[MVK_ANSI_A] },
        { kVK_ANSI_S, names[MVK_ANSI_S] },
        { kVK_ANSI_D, names[MVK_ANSI_D] },
        { kVK_ANSI_F, names[MVK_ANSI_F] },
        { kVK_ANSI_G, names[MVK_ANSI_G] },
        { kVK_ANSI_H, names[MVK_ANSI_H] },
        { kVK_ANSI_J, names[MVK_ANSI_J] },
        { kVK_ANSI_K, names[MVK_ANSI_K] },
        { kVK_ANSI_L, names[MVK_ANSI_L] },
        { kVK_ANSI_Z, names[MVK_ANSI_Z] },
        { kVK_ANSI_X, names[MVK_ANSI_X] },
        { kVK_ANSI_C, names[MVK_ANSI_C] },
        { kVK_ANSI_V, names[MVK_ANSI_V] },
        { kVK_ANSI_B, names[MVK_ANSI_B] },
        { kVK_ANSI_N, names[MVK_ANSI_N] },
        { kVK_ANSI_M, names[MVK_ANSI_M] },
        
        { kVK_LeftArrow, names[MVK_LeftArrow]  },
        { kVK_RightArrow, names[MVK_RightArrow] },
        { kVK_UpArrow, names[MVK_UpArrow]    },
        { kVK_DownArrow, names[MVK_DownArrow]  },
        
        { kVK_ANSI_KeypadDecimal, names[MVK_ANSI_KeypadDecimal] },
        { kVK_ANSI_KeypadMultiply, names[MVK_ANSI_KeypadMultiply] },
        { kVK_ANSI_KeypadPlus, names[MVK_ANSI_KeypadPlus] },
        { kVK_ANSI_KeypadClear, names[MVK_ANSI_KeypadClear] },
        { kVK_ANSI_KeypadDivide, names[MVK_ANSI_KeypadDivide] },
        { kVK_ANSI_KeypadEnter, names[MVK_ANSI_KeypadEnter] },
        { kVK_ANSI_KeypadMinus, names[MVK_ANSI_KeypadMinus] },
        { kVK_ANSI_KeypadEquals, names[MVK_ANSI_KeypadEquals] },
        
        { kVK_Home, names[MVK_Home] },
        { kVK_PageUp, names[MVK_PageUp] },
        { kVK_End, names[MVK_End] },
        { kVK_PageDown, names[MVK_PageDown] }
        
#elif defined _WIN32

        { VK_F1, names[MVK_F1] },
        { VK_F2, names[MVK_F2] },
        { VK_F3, names[MVK_F3] },
        { VK_F4, names[MVK_F4] },
        { VK_F5, names[MVK_F5] },
        { VK_F6, names[MVK_F6] },
        { VK_F7, names[MVK_F7] },
        { VK_F8, names[MVK_F8] },
        { VK_F9, names[MVK_F9] },
        { VK_F10, names[MVK_F10] },
        { VK_F11, names[MVK_F11] },
        { VK_F12, names[MVK_F12] },
        
        { VK_ESCAPE, names[MVK_Escape] },
        { VK_TAB, names[MVK_Tab] },
        { VK_CAPITAL, names[MVK_CapsLock] },
        { VK_SHIFT, names[MVK_Shift] },
        { VK_LCONTROL, names[MVK_Control] },
        { VK_LMENU, names[MVK_Option] },
        { VK_OEM_MINUS, names[MVK_ANSI_Minus] },
        { VK_OEM_PLUS, names[MVK_ANSI_Equal] },
        { VK_INSERT, names[MVK_Insert] },
        { VK_DELETE, names[MVK_Delete] },
        { VK_RETURN, names[MVK_Return] },
        { VK_OEM_COMMA, names[MVK_ANSI_Comma] },
        { VK_OEM_PERIOD, names[MVK_ANSI_Period] },
        { VK_SPACE, names[MVK_Space] },

        { VK_OEM_1, names[MVK_ANSI_Semicolon] },
        { VK_OEM_2, names[MVK_ANSI_Slash] },
        { VK_OEM_3, names[MVK_ANSI_Grave] },
        { VK_OEM_4, names[MVK_ANSI_LeftBracket] },
        { VK_OEM_6, names[MVK_ANSI_RightBracket] },
        { VK_OEM_5, names[MVK_ANSI_Backslash] },
        { VK_OEM_7, names[MVK_ANSI_Quote] },

        { VK_NUMPAD0, names[MVK_ANSI_Keypad0] },
        { VK_NUMPAD1, names[MVK_ANSI_Keypad1] },
        { VK_NUMPAD2, names[MVK_ANSI_Keypad2] },
        { VK_NUMPAD3, names[MVK_ANSI_Keypad3] },
        { VK_NUMPAD4, names[MVK_ANSI_Keypad4] },
        { VK_NUMPAD5, names[MVK_ANSI_Keypad5] },
        { VK_NUMPAD6, names[MVK_ANSI_Keypad6] },
        { VK_NUMPAD7, names[MVK_ANSI_Keypad7] },
        { VK_NUMPAD8, names[MVK_ANSI_Keypad8] },
        { VK_NUMPAD9, names[MVK_ANSI_Keypad9] },
        
        { '0', names[MVK_ANSI_0] },
        { '1', names[MVK_ANSI_1] },
        { '2', names[MVK_ANSI_2] },
        { '3', names[MVK_ANSI_3] },
        { '4', names[MVK_ANSI_4] },
        { '5', names[MVK_ANSI_5] },
        { '6', names[MVK_ANSI_6] },
        { '7', names[MVK_ANSI_7] },
        { '8', names[MVK_ANSI_8] },
        { '9', names[MVK_ANSI_9] },
        
        { 'A', names[MVK_ANSI_A] },
        { 'B', names[MVK_ANSI_B] },
        { 'C', names[MVK_ANSI_C] },
        { 'D', names[MVK_ANSI_D] },
        { 'E', names[MVK_ANSI_E] },
        { 'F', names[MVK_ANSI_F] },
        { 'G', names[MVK_ANSI_G] },
        { 'H', names[MVK_ANSI_H] },
        { 'I', names[MVK_ANSI_I] },
        { 'J', names[MVK_ANSI_J] },
        { 'K', names[MVK_ANSI_K] },
        { 'L', names[MVK_ANSI_L] },
        { 'M', names[MVK_ANSI_M] },
        { 'N', names[MVK_ANSI_N] },
        { 'O', names[MVK_ANSI_O] },
        { 'P', names[MVK_ANSI_P] },
        { 'Q', names[MVK_ANSI_Q] },
        { 'R', names[MVK_ANSI_R] },
        { 'S', names[MVK_ANSI_S] },
        { 'T', names[MVK_ANSI_T] },
        { 'U', names[MVK_ANSI_U] },
        { 'V', names[MVK_ANSI_V] },
        { 'W', names[MVK_ANSI_W] },
        { 'X', names[MVK_ANSI_X] },
        { 'Y', names[MVK_ANSI_Y] },
        { 'Z', names[MVK_ANSI_Z] },
        
        { VK_LEFT, names[MVK_LeftArrow]  },
        { VK_RIGHT, names[MVK_RightArrow] },
        { VK_UP, names[MVK_UpArrow]    },
        { VK_DOWN, names[MVK_DownArrow]  },
        
        { VK_DECIMAL, names[MVK_ANSI_KeypadDecimal] },
        { VK_MULTIPLY, names[MVK_ANSI_KeypadMultiply] },
        { VK_ADD, names[MVK_ANSI_KeypadPlus] },
        { VK_CLEAR, names[MVK_ANSI_KeypadClear] },
        { VK_DIVIDE, names[MVK_ANSI_KeypadDivide] },
        { VK_SUBTRACT, names[MVK_ANSI_KeypadMinus] },
        
        { VK_HOME, names[MVK_Home] },
        { VK_PRIOR, names[MVK_PageUp] },
        { VK_END, names[MVK_End] },
        { VK_NEXT, names[MVK_PageDown] }
        
#elif defined __linux__

        { XK_F1, names[MVK_F1] },
        { XK_F2, names[MVK_F2] },
        { XK_F3, names[MVK_F3] },
        { XK_F4, names[MVK_F4] },
        { XK_F5, names[MVK_F5] },
        { XK_F6, names[MVK_F6]},
        { XK_F7, names[MVK_F7] },
        { XK_F8, names[MVK_F8] },
        { XK_F9, names[MVK_F9] },
        { XK_F10, names[MVK_F10] },
        { XK_F11, names[MVK_F11] },
        { XK_F12, names[MVK_F12] },
        
        { XK_Escape, names[MVK_Escape] },
        { XK_Tab, names[MVK_Tab] },
        { XK_Caps_Lock, names[MVK_CapsLock] },
        { XK_Shift_L, names[MVK_Shift] },
        { XK_Control_L, names[MVK_Control] },
        { XK_Alt_L, names[MVK_Option] },
        { XK_minus, names[MVK_ANSI_Minus] },
        { XK_equal, names[MVK_ANSI_Equal] },
        { XK_Insert, names[MVK_Insert] },
        { XK_Delete, names[MVK_Delete] },
        { XK_bracketleft, names[MVK_ANSI_LeftBracket] },
        { XK_bracketright, names[MVK_ANSI_RightBracket] },
        { XK_backslash, names[MVK_ANSI_Backslash] },
        { XK_semicolon, names[MVK_ANSI_Semicolon] },
        { XK_apostrophe, names[MVK_ANSI_Quote] },
        { XK_Return, names[MVK_Return] },
        { XK_comma, names[MVK_ANSI_Comma] },
        { XK_period, names[MVK_ANSI_Period] },
        { XK_slash, names[MVK_ANSI_Slash] },
        { XK_space, names[MVK_Space] },
        
        { XK_0, names[MVK_ANSI_0] },
        { XK_1, names[MVK_ANSI_1] },
        { XK_2, names[MVK_ANSI_2] },
        { XK_3, names[MVK_ANSI_3] },
        { XK_4, names[MVK_ANSI_4] },
        { XK_5, names[MVK_ANSI_5] },
        { XK_6, names[MVK_ANSI_6] },
        { XK_7, names[MVK_ANSI_7] },
        { XK_8, names[MVK_ANSI_8] },
        { XK_9, names[MVK_ANSI_9] },
        
        { XK_a, names[MVK_ANSI_A] },
        { XK_b, names[MVK_ANSI_B] },
        { XK_c, names[MVK_ANSI_C] },
        { XK_d, names[MVK_ANSI_D] },
        { XK_e, names[MVK_ANSI_E] },
        { XK_f, names[MVK_ANSI_F] },
        { XK_g, names[MVK_ANSI_G] },
        { XK_h, names[MVK_ANSI_H] },
        { XK_i, names[MVK_ANSI_I] },
        { XK_j, names[MVK_ANSI_J] },
        { XK_k, names[MVK_ANSI_K] },
        { XK_l, names[MVK_ANSI_L] },
        { XK_m, names[MVK_ANSI_M] },
        { XK_n, names[MVK_ANSI_N] },
        { XK_o, names[MVK_ANSI_O] },
        { XK_p, names[MVK_ANSI_P] },
        { XK_q, names[MVK_ANSI_Q] },
        { XK_r, names[MVK_ANSI_R] },
        { XK_s, names[MVK_ANSI_S] },
        { XK_t, names[MVK_ANSI_T] },
        { XK_u, names[MVK_ANSI_U] },
        { XK_v, names[MVK_ANSI_V] },
        { XK_w, names[MVK_ANSI_W] },
        { XK_x, names[MVK_ANSI_X] },
        { XK_y, names[MVK_ANSI_Y] },
        { XK_z, names[MVK_ANSI_Z] },
        
        { XK_Left, names[MVK_LeftArrow]  },
        { XK_Right, names[MVK_RightArrow] },
        { XK_Up, names[MVK_UpArrow]    },
        { XK_Down, names[MVK_DownArrow]  },
        
        { XK_Home, names[MVK_Home] },
        { XK_Page_Up, names[MVK_PageUp] },
        { XK_End, names[MVK_End] },
        { XK_Page_Down, names[MVK_PageDown] }
#endif
        
    };
    
};
}
