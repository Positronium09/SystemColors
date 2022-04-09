#include "systemcolors.h"


using PGetImmersiveColorFromColorSetEx = COLORREF(WINAPI*)(UINT dwImmersiveColorSet, UINT dwImmersiveColorType, bool bIgnoreHighContrast, UINT dwHighContrastCacheMode);
using PGetImmersiveColorTypeFromName = int (WINAPI*)(const WCHAR* name);
using PGetImmersiveUserColorSetPreference = int (WINAPI*)(bool bForceCheckRegistry, bool bSkipCheckOnFail);


COLORREF SystemColors::GetColor(const WCHAR* name)
{
	HMODULE hUxTheme = LoadLibrary(TEXT("uxtheme.dll"));

	if (hUxTheme)
	{
		PGetImmersiveColorFromColorSetEx GetImmersiveColorFromColorSetEx = (PGetImmersiveColorFromColorSetEx)GetProcAddress(hUxTheme, MAKEINTRESOURCEA(95));
		PGetImmersiveColorTypeFromName GetImmersiveColorTypeFromName = (PGetImmersiveColorTypeFromName)GetProcAddress(hUxTheme, MAKEINTRESOURCEA(96));
		PGetImmersiveUserColorSetPreference GetImmersiveUserColorSetPreference = (PGetImmersiveUserColorSetPreference)GetProcAddress(hUxTheme, MAKEINTRESOURCEA(98));

		COLORREF color = GetImmersiveColorFromColorSetEx(GetImmersiveUserColorSetPreference(false, false),
			GetImmersiveColorTypeFromName(name), false, 0);

		FreeLibrary(hUxTheme);

		return color;
	}
	return 0;
}

COLORREF SystemColors::GetAccentColor()
{
	return GetColor(L"ImmersiveSystemAccent");
}

COLORREF SystemColors::GetAccentColorDark1()
{
	return GetColor(L"ImmersiveSystemAccentDark1");
}

COLORREF SystemColors::GetAccentColorDark2()
{
	return GetColor(L"ImmersiveSystemAccentDark2");
}

COLORREF SystemColors::GetAccentColorDark3()
{
	return GetColor(L"ImmersiveSystemAccentDark3");
}

COLORREF SystemColors::GetAccentColorLight1()
{
	return GetColor(L"ImmersiveSystemAccentLight1");
}

COLORREF SystemColors::GetAccentColorLight2()
{
	return GetColor(L"ImmersiveSystemAccentLight2");
}

COLORREF SystemColors::GetAccentColorLight3()
{
	return GetColor(L"ImmersiveSystemAccentLight3");
}

COLORREF SystemColors::GetTextColor()
{
	return GetColor(L"ImmersiveSystemText");
}

COLORREF SystemColors::GetBackgroundColor()
{
	return GetColor(L"ImmersiveSystemBackground");
}
