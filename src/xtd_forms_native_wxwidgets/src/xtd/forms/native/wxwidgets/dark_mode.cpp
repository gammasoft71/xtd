#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"

#if defined(_WIN32)
#include <Windows.h>
#include <Uxtheme.h>

namespace {
template <typename T, typename T1, typename T2>
constexpr T RVA2VA(T1 base, T2 rva) {
  return reinterpret_cast<T>(reinterpret_cast<ULONG_PTR>(base) + rva);
}

template <typename T>
constexpr T DataDirectoryFromModuleBase(void* moduleBase, size_t entryID) {
  auto dosHdr = reinterpret_cast<PIMAGE_DOS_HEADER>(moduleBase);
  auto ntHdr = RVA2VA<PIMAGE_NT_HEADERS>(moduleBase, dosHdr->e_lfanew);
  auto dataDir = ntHdr->OptionalHeader.DataDirectory;
  return RVA2VA<T>(moduleBase, dataDir[entryID].VirtualAddress);
}

PIMAGE_THUNK_DATA FindAddressByName(void* moduleBase, PIMAGE_THUNK_DATA impName, PIMAGE_THUNK_DATA impAddr, const char* funcName) {
  for (; impName->u1.Ordinal; ++impName, ++impAddr) {
    if (IMAGE_SNAP_BY_ORDINAL(impName->u1.Ordinal)) continue;
    auto import = RVA2VA<PIMAGE_IMPORT_BY_NAME>(moduleBase, impName->u1.AddressOfData);
    if (strcmp(import->Name, funcName) != 0) continue;
    return impAddr;
  }
  return nullptr;
}

PIMAGE_THUNK_DATA FindAddressByOrdinal(void* moduleBase, PIMAGE_THUNK_DATA impName, PIMAGE_THUNK_DATA impAddr, uint16_t ordinal) {
  for (; impName->u1.Ordinal; ++impName, ++impAddr) {
    if (IMAGE_SNAP_BY_ORDINAL(impName->u1.Ordinal) && IMAGE_ORDINAL(impName->u1.Ordinal) == ordinal) return impAddr;
  }
  return nullptr;
}

PIMAGE_THUNK_DATA FindIatThunkInModule(void* moduleBase, const char* dllName, const char* funcName) {
  auto imports = DataDirectoryFromModuleBase<PIMAGE_IMPORT_DESCRIPTOR>(moduleBase, IMAGE_DIRECTORY_ENTRY_IMPORT);
  for (; imports->Name; ++imports) {
    if (_stricmp(RVA2VA<LPCSTR>(moduleBase, imports->Name), dllName) != 0) continue;
    auto origThunk = RVA2VA<PIMAGE_THUNK_DATA>(moduleBase, imports->OriginalFirstThunk);
    auto thunk = RVA2VA<PIMAGE_THUNK_DATA>(moduleBase, imports->FirstThunk);
    return FindAddressByName(moduleBase, origThunk, thunk, funcName);
  }
  return nullptr;
}

PIMAGE_THUNK_DATA FindDelayLoadThunkInModule(void* moduleBase, const char* dllName, const char* funcName) {
  auto imports = DataDirectoryFromModuleBase<PIMAGE_DELAYLOAD_DESCRIPTOR>(moduleBase, IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT);
  for (; imports->DllNameRVA; ++imports) {
    if (_stricmp(RVA2VA<LPCSTR>(moduleBase, imports->DllNameRVA), dllName) != 0) continue;
    auto impName = RVA2VA<PIMAGE_THUNK_DATA>(moduleBase, imports->ImportNameTableRVA);
    auto impAddr = RVA2VA<PIMAGE_THUNK_DATA>(moduleBase, imports->ImportAddressTableRVA);
    return FindAddressByName(moduleBase, impName, impAddr, funcName);
  }
  return nullptr;
}

PIMAGE_THUNK_DATA FindDelayLoadThunkInModule(void* moduleBase, const char* dllName, uint16_t ordinal)
{
  auto imports = DataDirectoryFromModuleBase<PIMAGE_DELAYLOAD_DESCRIPTOR>(moduleBase, IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT);
  for (; imports->DllNameRVA; ++imports) {
    if (_stricmp(RVA2VA<LPCSTR>(moduleBase, imports->DllNameRVA), dllName) != 0) continue;
    auto impName = RVA2VA<PIMAGE_THUNK_DATA>(moduleBase, imports->ImportNameTableRVA);
    auto impAddr = RVA2VA<PIMAGE_THUNK_DATA>(moduleBase, imports->ImportAddressTableRVA);
    return FindAddressByOrdinal(moduleBase, impName, impAddr, ordinal);
  }
  return nullptr;
}

enum IMMERSIVE_HC_CACHE_MODE {
  IHCM_USE_CACHED_VALUE,
  IHCM_REFRESH
};

// 1903 18362
enum PreferredAppMode {
  Default,
  AllowDark,
  ForceDark,
  ForceLight,
  Max
};

enum WINDOWCOMPOSITIONATTRIB {
  WCA_UNDEFINED = 0,
  WCA_NCRENDERING_ENABLED = 1,
  WCA_NCRENDERING_POLICY = 2,
  WCA_TRANSITIONS_FORCEDISABLED = 3,
  WCA_ALLOW_NCPAINT = 4,
  WCA_CAPTION_BUTTON_BOUNDS = 5,
  WCA_NONCLIENT_RTL_LAYOUT = 6,
  WCA_FORCE_ICONIC_REPRESENTATION = 7,
  WCA_EXTENDED_FRAME_BOUNDS = 8,
  WCA_HAS_ICONIC_BITMAP = 9,
  WCA_THEME_ATTRIBUTES = 10,
  WCA_NCRENDERING_EXILED = 11,
  WCA_NCADORNMENTINFO = 12,
  WCA_EXCLUDED_FROM_LIVEPREVIEW = 13,
  WCA_VIDEO_OVERLAY_ACTIVE = 14,
  WCA_FORCE_ACTIVEWINDOW_APPEARANCE = 15,
  WCA_DISALLOW_PEEK = 16,
  WCA_CLOAK = 17,
  WCA_CLOAKED = 18,
  WCA_ACCENT_POLICY = 19,
  WCA_FREEZE_REPRESENTATION = 20,
  WCA_EVER_UNCLOAKED = 21,
  WCA_VISUAL_OWNER = 22,
  WCA_HOLOGRAPHIC = 23,
  WCA_EXCLUDED_FROM_DDA = 24,
  WCA_PASSIVEUPDATEMODE = 25,
  WCA_USEDARKMODECOLORS = 26,
  WCA_LAST = 27
};

struct WINDOWCOMPOSITIONATTRIBDATA {
  WINDOWCOMPOSITIONATTRIB Attrib;
  PVOID pvData;
  SIZE_T cbData;
};
}

using fnRtlGetNtVersionNumbers = void (WINAPI *)(LPDWORD major, LPDWORD minor, LPDWORD build);
using fnSetWindowCompositionAttribute = BOOL (WINAPI *)(HWND hWnd, WINDOWCOMPOSITIONATTRIBDATA*);
// 1809 17763
using fnShouldAppsUseDarkMode = bool (WINAPI *)(); // ordinal 132
using fnAllowDarkModeForWindow = bool (WINAPI *)(HWND hWnd, bool allow); // ordinal 133
using fnAllowDarkModeForApp = bool (WINAPI *)(bool allow); // ordinal 135, in 1809
using fnFlushMenuThemes = void (WINAPI *)(); // ordinal 136
using fnRefreshImmersiveColorPolicyState = void (WINAPI *)(); // ordinal 104
using fnIsDarkModeAllowedForWindow = bool (WINAPI *)(HWND hWnd); // ordinal 137
using fnGetIsImmersiveColorUsingHighContrast = bool (WINAPI *)(IMMERSIVE_HC_CACHE_MODE mode); // ordinal 106
using fnOpenNcThemeData = HTHEME(WINAPI *)(HWND hWnd, LPCWSTR pszClassList); // ordinal 49
// 1903 18362
using fnShouldSystemUseDarkMode = bool (WINAPI *)(); // ordinal 138
using fnSetPreferredAppMode = PreferredAppMode (WINAPI *)(PreferredAppMode appMode); // ordinal 135, in 1903
using fnIsDarkModeAllowedForApp = bool (WINAPI *)(); // ordinal 139

fnSetWindowCompositionAttribute _SetWindowCompositionAttribute = nullptr;
fnShouldAppsUseDarkMode _ShouldAppsUseDarkMode = nullptr;
fnAllowDarkModeForWindow _AllowDarkModeForWindow = nullptr;
fnAllowDarkModeForApp _AllowDarkModeForApp = nullptr;
fnFlushMenuThemes _FlushMenuThemes = nullptr;
fnRefreshImmersiveColorPolicyState _RefreshImmersiveColorPolicyState = nullptr;
fnIsDarkModeAllowedForWindow _IsDarkModeAllowedForWindow = nullptr;
fnGetIsImmersiveColorUsingHighContrast _GetIsImmersiveColorUsingHighContrast = nullptr;
fnOpenNcThemeData _OpenNcThemeData = nullptr;
// 1903 18362
fnShouldSystemUseDarkMode _ShouldSystemUseDarkMode = nullptr;
fnSetPreferredAppMode _SetPreferredAppMode = nullptr;

bool g_darkModeSupported = false;
bool g_darkModeEnabled = false;
DWORD g_buildNumber = 0;

bool allow_dark_mode_for_window(intptr_t hWnd) {
  if (!g_darkModeEnabled) return false;
  if (g_darkModeSupported)
    return _AllowDarkModeForWindow(reinterpret_cast<HWND>(hWnd), g_darkModeEnabled);
  return false;
}

bool IsHighContrast() {
  HIGHCONTRASTW highContrast = { sizeof(highContrast) };
  if (SystemParametersInfoW(SPI_GETHIGHCONTRAST, sizeof(highContrast), &highContrast, FALSE))
    return highContrast.dwFlags & HCF_HIGHCONTRASTON;
  return false;
}

void refresh_title_bar_theme_color(intptr_t hWnd) {
  if (!g_darkModeEnabled) return;
  BOOL dark = FALSE;
  if (_IsDarkModeAllowedForWindow(reinterpret_cast<HWND>(hWnd)) &&
      _ShouldAppsUseDarkMode() &&
      !IsHighContrast()) {
    dark = TRUE;
  }
  if (g_buildNumber < 18362)
    SetPropW(reinterpret_cast<HWND>(hWnd), L"UseImmersiveDarkModeColors", reinterpret_cast<HANDLE>(static_cast<INT_PTR>(dark)));
  else if (_SetWindowCompositionAttribute) {
    WINDOWCOMPOSITIONATTRIBDATA data = { WCA_USEDARKMODECOLORS, &dark, sizeof(dark) };
    _SetWindowCompositionAttribute(reinterpret_cast<HWND>(hWnd), &data);
  }
}

bool IsColorSchemeChangeMessage(LPARAM lParam) {
  bool is = false;
  if (lParam && CompareStringOrdinal(reinterpret_cast<LPCWCH>(lParam), -1, L"ImmersiveColorSet", -1, TRUE) == CSTR_EQUAL) {
    _RefreshImmersiveColorPolicyState();
    is = true;
  }
  _GetIsImmersiveColorUsingHighContrast(IHCM_REFRESH);
  return is;
}

bool IsColorSchemeChangeMessage(UINT message, LPARAM lParam) {
  if (message == WM_SETTINGCHANGE)
    return IsColorSchemeChangeMessage(lParam);
  return false;
}

void AllowDarkModeForApp() {
  if (!g_darkModeEnabled) return;
  if (_AllowDarkModeForApp)
    _AllowDarkModeForApp(g_darkModeEnabled);
  else if (_SetPreferredAppMode)
    _SetPreferredAppMode(AllowDark);
}

void FixDarkScrollBar() {
  if (!g_darkModeEnabled) return;
  HMODULE hComctl = LoadLibraryExW(L"comctl32.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
  if (hComctl) {
    auto addr = FindDelayLoadThunkInModule(hComctl, "uxtheme.dll", 49); // OpenNcThemeData
    if (addr)  {
      DWORD oldProtect;
      if (VirtualProtect(addr, sizeof(IMAGE_THUNK_DATA), PAGE_READWRITE, &oldProtect)) {
        auto MyOpenThemeData = [](HWND hWnd, LPCWSTR classList) -> HTHEME {
          if (wcscmp(classList, L"ScrollBar") == 0) {
            hWnd = nullptr;
            classList = L"Explorer::ScrollBar";
          }
          return _OpenNcThemeData(hWnd, classList);
        };
        
        addr->u1.Function = reinterpret_cast<ULONG_PTR>(static_cast<fnOpenNcThemeData>(MyOpenThemeData));
        VirtualProtect(addr, sizeof(IMAGE_THUNK_DATA), oldProtect, &oldProtect);
      }
    }
  }
}

constexpr bool CheckBuildNumber(DWORD buildNumber) {
  return (buildNumber == 17763 || // 1809
          buildNumber == 18362 || // 1903
          buildNumber == 18363); // 1909
}

void init_dark_mode(int enableDarkMode) {
  auto RtlGetNtVersionNumbers = reinterpret_cast<fnRtlGetNtVersionNumbers>(GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "RtlGetNtVersionNumbers"));
  if (RtlGetNtVersionNumbers) {
    DWORD major, minor;
    RtlGetNtVersionNumbers(&major, &minor, &g_buildNumber);
    g_buildNumber &= ~0xF0000000;
    if (major == 10 && minor == 0 && CheckBuildNumber(g_buildNumber)) {
      HMODULE hUxtheme = LoadLibraryExW(L"uxtheme.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
      if (hUxtheme) {
        _OpenNcThemeData = reinterpret_cast<fnOpenNcThemeData>(GetProcAddress(hUxtheme, MAKEINTRESOURCEA(49)));
        _RefreshImmersiveColorPolicyState = reinterpret_cast<fnRefreshImmersiveColorPolicyState>(GetProcAddress(hUxtheme, MAKEINTRESOURCEA(104)));
        _GetIsImmersiveColorUsingHighContrast = reinterpret_cast<fnGetIsImmersiveColorUsingHighContrast>(GetProcAddress(hUxtheme, MAKEINTRESOURCEA(106)));
        _ShouldAppsUseDarkMode = reinterpret_cast<fnShouldAppsUseDarkMode>(GetProcAddress(hUxtheme, MAKEINTRESOURCEA(132)));
        _AllowDarkModeForWindow = reinterpret_cast<fnAllowDarkModeForWindow>(GetProcAddress(hUxtheme, MAKEINTRESOURCEA(133)));
        
        auto ord135 = GetProcAddress(hUxtheme, MAKEINTRESOURCEA(135));
        if (g_buildNumber < 18362)
          _AllowDarkModeForApp = reinterpret_cast<fnAllowDarkModeForApp>(ord135);
        else
          _SetPreferredAppMode = reinterpret_cast<fnSetPreferredAppMode>(ord135);
        
        //_FlushMenuThemes = reinterpret_cast<fnFlushMenuThemes>(GetProcAddress(hUxtheme, MAKEINTRESOURCEA(136)));
        _IsDarkModeAllowedForWindow = reinterpret_cast<fnIsDarkModeAllowedForWindow>(GetProcAddress(hUxtheme, MAKEINTRESOURCEA(137)));
        
        _SetWindowCompositionAttribute = reinterpret_cast<fnSetWindowCompositionAttribute>(GetProcAddress(GetModuleHandleW(L"user32.dll"), "SetWindowCompositionAttribute"));
        
        if (_OpenNcThemeData &&  _RefreshImmersiveColorPolicyState && _ShouldAppsUseDarkMode &&  _AllowDarkModeForWindow && (_AllowDarkModeForApp || _SetPreferredAppMode) &&  /*_FlushMenuThemes && */ _IsDarkModeAllowedForWindow) {
          g_darkModeSupported = true;
          g_darkModeEnabled = enableDarkMode == 1 || (enableDarkMode == -1 && _ShouldAppsUseDarkMode() && !IsHighContrast());
          AllowDarkModeForApp();
          _RefreshImmersiveColorPolicyState();
          FixDarkScrollBar();
        }
      }
    }
  }
}

#else
bool allow_dark_mode_for_window(intptr_t hWnd) {
  return false;
}

void init_dark_mode(int enableDarkMode) {
}
                                         
void refresh_title_bar_theme_color(intptr_t hWnd) {
}

#endif
