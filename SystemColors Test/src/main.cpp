#include <windows.h>
#include <iostream>

#include "systemcolors.h"


int main()
{
	COLORREF c = GetAccentColor();

	std::cout << (int)GetRValue(c) << ' ' << (int)GetGValue(c) << ' ' << (int)GetBValue(c) << '\n';

	c = GetAccentColorDark1();

	std::cout << (int)GetRValue(c) << ' ' << (int)GetGValue(c) << ' ' << (int)GetBValue(c) << '\n';

	c = GetAccentColorDark2();

	std::cout << (int)GetRValue(c) << ' ' << (int)GetGValue(c) << ' ' << (int)GetBValue(c) << '\n';

	c = GetAccentColorDark3();

	std::cout << (int)GetRValue(c) << ' ' << (int)GetGValue(c) << ' ' << (int)GetBValue(c) << '\n';

	c = GetAccentColorLight1();

	std::cout << (int)GetRValue(c) << ' ' << (int)GetGValue(c) << ' ' << (int)GetBValue(c) << '\n';

	c = GetAccentColorLight2();

	std::cout << (int)GetRValue(c) << ' ' << (int)GetGValue(c) << ' ' << (int)GetBValue(c) << '\n';

	c = GetAccentColorLight3();

	std::cout << (int)GetRValue(c) << ' ' << (int)GetGValue(c) << ' ' << (int)GetBValue(c) << '\n';

	c = GetTextColor();

	std::cout << (int)GetRValue(c) << ' ' << (int)GetGValue(c) << ' ' << (int)GetBValue(c) << '\n';

	c = GetBackgroundColor();

	std::cout << (int)GetRValue(c) << ' ' << (int)GetGValue(c) << ' ' << (int)GetBValue(c) << '\n';

	return 0;
}
