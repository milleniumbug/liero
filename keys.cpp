#ifdef WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif // WIN32
#include <cstddef>
#include <cassert>
#include <map>

std::map<int, int> SDLToDOSScanCodes;

SDL_Scancode const Z = SDL_SCANCODE_UNKNOWN;
SDL_Scancode lieroToSDLKeys[] =
{
	SDL_SCANCODE_UNKNOWN,SDL_SCANCODE_ESCAPE,
	SDL_SCANCODE_1,SDL_SCANCODE_2,SDL_SCANCODE_3,SDL_SCANCODE_4,SDL_SCANCODE_5,SDL_SCANCODE_6,SDL_SCANCODE_7,SDL_SCANCODE_8,SDL_SCANCODE_9,SDL_SCANCODE_0,
	/* 0x0c: */
    SDL_SCANCODE_MINUS,SDL_SCANCODE_EQUALS,SDL_SCANCODE_BACKSPACE,SDL_SCANCODE_TAB,
    SDL_SCANCODE_Q,SDL_SCANCODE_W,SDL_SCANCODE_E,SDL_SCANCODE_R,SDL_SCANCODE_T,SDL_SCANCODE_Y,SDL_SCANCODE_U,SDL_SCANCODE_I,SDL_SCANCODE_O,SDL_SCANCODE_P,
    SDL_SCANCODE_LEFTBRACKET,SDL_SCANCODE_RIGHTBRACKET,SDL_SCANCODE_RETURN,SDL_SCANCODE_LCTRL,
    SDL_SCANCODE_A,SDL_SCANCODE_S,SDL_SCANCODE_D,SDL_SCANCODE_F,SDL_SCANCODE_G,SDL_SCANCODE_H,SDL_SCANCODE_J,SDL_SCANCODE_K,SDL_SCANCODE_L,
    SDL_SCANCODE_SEMICOLON,SDL_SCANCODE_APOSTROPHE,SDL_SCANCODE_GRAVE,SDL_SCANCODE_LSHIFT,SDL_SCANCODE_BACKSLASH,
    SDL_SCANCODE_Z,SDL_SCANCODE_X,SDL_SCANCODE_C,SDL_SCANCODE_V,SDL_SCANCODE_B,SDL_SCANCODE_N,SDL_SCANCODE_M,
	/* 0x33: */
	SDL_SCANCODE_COMMA,SDL_SCANCODE_PERIOD,SDL_SCANCODE_SLASH,SDL_SCANCODE_RSHIFT,SDL_SCANCODE_KP_MULTIPLY,
	SDL_SCANCODE_LALT,SDL_SCANCODE_SPACE,SDL_SCANCODE_CAPSLOCK,
	SDL_SCANCODE_F1,SDL_SCANCODE_F2,SDL_SCANCODE_F3,SDL_SCANCODE_F4,SDL_SCANCODE_F5,SDL_SCANCODE_F6,SDL_SCANCODE_F7,SDL_SCANCODE_F8,SDL_SCANCODE_F9,SDL_SCANCODE_F10,
	/* 0x45: */
	SDL_SCANCODE_NUMLOCKCLEAR,SDL_SCANCODE_SCROLLLOCK,
	SDL_SCANCODE_KP_7,SDL_SCANCODE_KP_8,SDL_SCANCODE_KP_9,SDL_SCANCODE_KP_MINUS,SDL_SCANCODE_KP_4,SDL_SCANCODE_KP_5,SDL_SCANCODE_KP_6,SDL_SCANCODE_KP_PLUS,
	SDL_SCANCODE_KP_1,SDL_SCANCODE_KP_2,SDL_SCANCODE_KP_3,SDL_SCANCODE_KP_0,SDL_SCANCODE_KP_PERIOD,
	SDL_SCANCODE_UNKNOWN,SDL_SCANCODE_UNKNOWN,
	SDL_SCANCODE_NONUSBACKSLASH,SDL_SCANCODE_F11,SDL_SCANCODE_F12,

	Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z, // 27 zeroes
	SDL_SCANCODE_KP_ENTER, // Enter (Pad)
	SDL_SCANCODE_RCTRL, // Right Ctrl
	Z, Z, Z, Z, Z, Z, Z, Z, Z, Z,
	Z, Z, // 12 zeroes
	SDL_SCANCODE_PRINTSCREEN,
	Z, Z, Z, Z, Z, Z, Z, Z, Z, Z, // 10 zeroes
	SDL_SCANCODE_KP_DIVIDE, // / (Pad)
	Z,
	SDL_SCANCODE_PRINTSCREEN,
	SDL_SCANCODE_RALT, // Right Alt
	Z, Z, Z, Z, Z, Z, Z, Z, Z, Z,
	Z, Z, Z, Z, // 14 zeroes
	SDL_SCANCODE_HOME, // Home
	SDL_SCANCODE_UP, // Up
	SDL_SCANCODE_PAGEUP, // Page Up
	Z,
	SDL_SCANCODE_LEFT, // Left
	Z,
	SDL_SCANCODE_RIGHT, // Right
	Z,
	SDL_SCANCODE_END, // End
	SDL_SCANCODE_DOWN, // Down
	SDL_SCANCODE_PAGEDOWN, // Page Down
	SDL_SCANCODE_INSERT, // Insert
	SDL_SCANCODE_DELETE, // Delete
	Z, Z, Z, Z, Z // 5 zeroes
};

Uint32 const maxScanCodes = sizeof(lieroToSDLKeys) / sizeof(*lieroToSDLKeys);

void initKeys()
{
	for(std::size_t i = 0; i < maxScanCodes; ++i)
	{
		if(lieroToSDLKeys[i] != SDL_SCANCODE_UNKNOWN)
		{
			SDLToDOSScanCodes[lieroToSDLKeys[i]] = int(i);
		}
	}
}

Uint32 SDLToDOSKey(SDL_Scancode scancode)
{
	std::map<int, int>::iterator i = SDLToDOSScanCodes.find(Uint32(scancode));
	if(i != SDLToDOSScanCodes.end())
		return i->second;
	return 89;
}

Uint32 SDLToDOSKey(SDL_Keysym const& keysym)
{
	Uint32 key = SDLToDOSKey(keysym.scancode);

	if(key >= 177) // Liero doesn't have keys >= 177
		return 89; // Arbitrarily translate it to 89
	return key;

}
