#pragma once

//? https://social.msdn.microsoft.com/Forums/officeocs/en-US/16b70775-d87e-42d3-aa8f-41d7d6888c66/how-to-get-colors-of-default-app-mode-quotdarkquot-in-my-win32-app?forum=windowsgeneraldevelopmentissues

#include <windows.h>


COLORREF GetAccentColor();
COLORREF GetAccentColorDark1();
COLORREF GetAccentColorDark2();
COLORREF GetAccentColorDark3();
COLORREF GetAccentColorLight1();
COLORREF GetAccentColorLight2();
COLORREF GetAccentColorLight3();

COLORREF GetTextColor();
COLORREF GetBackgroundColor();
