#include "systemcolors.h"


typedef COLORREF(WINAPI* PGetImmersiveColorFromColorSetEx)(UINT dwImmersiveColorSet, UINT dwImmersiveColorType, bool bIgnoreHighContrast, UINT dwHighContrastCacheMode);
typedef int (WINAPI* PGetImmersiveColorTypeFromName)(const WCHAR* name);
typedef int (WINAPI* PGetImmersiveUserColorSetPreference)(bool bForceCheckRegistry, bool bSkipCheckOnFail);

HMODULE hUxTheme = LoadLibrary(TEXT("uxtheme.dll"));

PGetImmersiveColorFromColorSetEx GetImmersiveColorFromColorSetEx = (PGetImmersiveColorFromColorSetEx)GetProcAddress(hUxTheme, MAKEINTRESOURCEA(95));
PGetImmersiveColorTypeFromName GetImmersiveColorTypeFromName = (PGetImmersiveColorTypeFromName)GetProcAddress(hUxTheme, MAKEINTRESOURCEA(96));
PGetImmersiveUserColorSetPreference GetImmersiveUserColorSetPreference = (PGetImmersiveUserColorSetPreference)GetProcAddress(hUxTheme, MAKEINTRESOURCEA(98));


COLORREF GetAccentColor()
{
	return GetImmersiveColorFromColorSetEx(GetImmersiveUserColorSetPreference(false, false), 
		GetImmersiveColorTypeFromName(L"ImmersiveSystemAccent"), false, 0);
}

COLORREF GetAccentColorDark1()
{
	return GetImmersiveColorFromColorSetEx(GetImmersiveUserColorSetPreference(false, false),
		GetImmersiveColorTypeFromName(L"ImmersiveSystemAccentDark1"), false, 0);
}

COLORREF GetAccentColorDark2()
{
	return GetImmersiveColorFromColorSetEx(GetImmersiveUserColorSetPreference(false, false),
		GetImmersiveColorTypeFromName(L"ImmersiveSystemAccentDark2"), false, 0);
}

COLORREF GetAccentColorDark3()
{
	return GetImmersiveColorFromColorSetEx(GetImmersiveUserColorSetPreference(false, false),
		GetImmersiveColorTypeFromName(L"ImmersiveSystemAccentDark3"), false, 0);
}

COLORREF GetAccentColorLight1()
{
	return GetImmersiveColorFromColorSetEx(GetImmersiveUserColorSetPreference(false, false),
		GetImmersiveColorTypeFromName(L"ImmersiveSystemAccentLight1"), false, 0);
}

COLORREF GetAccentColorLight2()
{
	return GetImmersiveColorFromColorSetEx(GetImmersiveUserColorSetPreference(false, false),
		GetImmersiveColorTypeFromName(L"ImmersiveSystemAccentLight2"), false, 0);
}

COLORREF GetAccentColorLight3()
{
	return GetImmersiveColorFromColorSetEx(GetImmersiveUserColorSetPreference(false, false),
		GetImmersiveColorTypeFromName(L"ImmersiveSystemAccentLight3"), false, 0);
}

COLORREF GetTextColor()
{
	return GetImmersiveColorFromColorSetEx(GetImmersiveUserColorSetPreference(false, false),
		GetImmersiveColorTypeFromName(L"ImmersiveSystemText"), false, 0);
}

COLORREF GetBackgroundColor()
{
	return GetImmersiveColorFromColorSetEx(GetImmersiveUserColorSetPreference(false, false),
		GetImmersiveColorTypeFromName(L"ImmersiveSystemBackground"), false, 0);
}
