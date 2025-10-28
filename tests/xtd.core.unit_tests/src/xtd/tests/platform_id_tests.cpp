#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/platform_ids.hpp>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/platform_id>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(platform_id_tests) {
    void test_method_(unknown) {
      assert::are_equal(-1, enum_object<>::to_int32(platform_id::unknown));
      assert::are_equal(PLATFORM_UNKNOWN, enum_object<>::to_int32(platform_id::unknown));
      assert::are_equal("unknown", enum_object<>::to_string(platform_id::unknown));
      assert::are_equal(platform_id::unknown, enum_object<>::parse<platform_id>("unknown"));
    }
    
    void test_method_(win32s) {
      assert::are_equal(0, enum_object<>::to_int32(platform_id::win32s));
      assert::are_equal(PLATFORM_WIN32S, enum_object<>::to_int32(platform_id::win32s));
      assert::are_equal("win32s", enum_object<>::to_string(platform_id::win32s));
      assert::are_equal(platform_id::win32s, enum_object<>::parse<platform_id>("win32s"));
    }
    
    void test_method_(win32_windows) {
      assert::are_equal(1, enum_object<>::to_int32(platform_id::win32_windows));
      assert::are_equal(PLATFORM_WIN32_WINDOWS, enum_object<>::to_int32(platform_id::win32_windows));
      assert::are_equal("win32_windows", enum_object<>::to_string(platform_id::win32_windows));
      assert::are_equal(platform_id::win32_windows, enum_object<>::parse<platform_id>("win32_windows"));
    }
    
    void test_method_(win32_nt) {
      assert::are_equal(2, enum_object<>::to_int32(platform_id::win32_nt));
      assert::are_equal(PLATFORM_WIN32_NT, enum_object<>::to_int32(platform_id::win32_nt));
      assert::are_equal("win32_nt", enum_object<>::to_string(platform_id::win32_nt));
      assert::are_equal(platform_id::win32_nt, enum_object<>::parse<platform_id>("win32_nt"));
    }
    
    void test_method_(win_ce) {
      assert::are_equal(3, enum_object<>::to_int32(platform_id::win_ce));
      assert::are_equal(PLATFORM_WIN_CE, enum_object<>::to_int32(platform_id::win_ce));
      assert::are_equal("win_ce", enum_object<>::to_string(platform_id::win_ce));
      assert::are_equal(platform_id::win_ce, enum_object<>::parse<platform_id>("win_ce"));
    }
    
    void test_method_(unix) {
      assert::are_equal(4, enum_object<>::to_int32(platform_id::unix));
      assert::are_equal(PLATFORM_UNIX, enum_object<>::to_int32(platform_id::unix));
      assert::are_equal("unix", enum_object<>::to_string(platform_id::unix));
      assert::are_equal(platform_id::unix, enum_object<>::parse<platform_id>("unix"));
    }
    
    void test_method_(xbox) {
      assert::are_equal(5, enum_object<>::to_int32(platform_id::xbox));
      assert::are_equal(PLATFORM_XBOX, enum_object<>::to_int32(platform_id::xbox));
      assert::are_equal("xbox", enum_object<>::to_string(platform_id::xbox));
      assert::are_equal(platform_id::xbox, enum_object<>::parse<platform_id>("xbox"));
    }
    
    void test_method_(macos) {
      assert::are_equal(6, enum_object<>::to_int32(platform_id::macos));
      assert::are_equal(PLATFORM_MACOS, enum_object<>::to_int32(platform_id::macos));
      assert::are_equal("macos", enum_object<>::to_string(platform_id::macos));
      assert::are_equal(platform_id::macos, enum_object<>::parse<platform_id>("macos"));
    }
    
    void test_method_(ios) {
      assert::are_equal(7, enum_object<>::to_int32(platform_id::ios));
      assert::are_equal(PLATFORM_IOS, enum_object<>::to_int32(platform_id::ios));
      assert::are_equal("ios", enum_object<>::to_string(platform_id::ios));
      assert::are_equal(platform_id::ios, enum_object<>::parse<platform_id>("ios"));
    }
    
    void test_method_(android) {
      assert::are_equal(8, enum_object<>::to_int32(platform_id::android));
      assert::are_equal(PLATFORM_ANDROID, enum_object<>::to_int32(platform_id::android));
      assert::are_equal("android", enum_object<>::to_string(platform_id::android));
      assert::are_equal(platform_id::android, enum_object<>::parse<platform_id>("android"));
    }
    
    void test_method_(linux) {
      assert::are_equal(9, enum_object<>::to_int32(platform_id::linux));
      assert::are_equal(PLATFORM_LINUX, enum_object<>::to_int32(platform_id::linux));
      assert::are_equal("linux", enum_object<>::to_string(platform_id::linux));
      assert::are_equal(platform_id::linux, enum_object<>::parse<platform_id>("linux"));
    }
    
    void test_method_(tvos) {
      assert::are_equal(10, enum_object<>::to_int32(platform_id::tvos));
      assert::are_equal(PLATFORM_TVOS, enum_object<>::to_int32(platform_id::tvos));
      assert::are_equal("tvos", enum_object<>::to_string(platform_id::tvos));
      assert::are_equal(platform_id::tvos, enum_object<>::parse<platform_id>("tvos"));
    }
    
    void test_method_(watchos) {
      assert::are_equal(11, enum_object<>::to_int32(platform_id::watchos));
      assert::are_equal(PLATFORM_WATCHOS, enum_object<>::to_int32(platform_id::watchos));
      assert::are_equal("watchos", enum_object<>::to_string(platform_id::watchos));
      assert::are_equal(platform_id::watchos, enum_object<>::parse<platform_id>("watchos"));
    }
    
    void test_method_(free_bsd) {
      assert::are_equal(12, enum_object<>::to_int32(platform_id::free_bsd));
      assert::are_equal(PLATFORM_FREEBSD, enum_object<>::to_int32(platform_id::free_bsd));
      assert::are_equal("free_bsd", enum_object<>::to_string(platform_id::free_bsd));
      assert::are_equal(platform_id::free_bsd, enum_object<>::parse<platform_id>("free_bsd"));
    }
    
    void test_method_(haiku) {
      assert::are_equal(13, enum_object<>::to_int32(platform_id::haiku));
      assert::are_equal(PLATFORM_HAIKU, enum_object<>::to_int32(platform_id::haiku));
      assert::are_equal("haiku", enum_object<>::to_string(platform_id::haiku));
      assert::are_equal(platform_id::haiku, enum_object<>::parse<platform_id>("haiku"));
    }
    
    void test_method_(serenityos) {
      assert::are_equal(14, enum_object<>::to_int32(platform_id::serenityos));
      assert::are_equal(PLATFORM_SERENITYOS, enum_object<>::to_int32(platform_id::serenityos));
      assert::are_equal("serenityos", enum_object<>::to_string(platform_id::serenityos));
      assert::are_equal(platform_id::serenityos, enum_object<>::parse<platform_id>("serenityos"));
    }

    void test_method_(aix) {
      assert::are_equal(15, enum_object<>::to_int32(platform_id::aix));
      assert::are_equal(PLATFORM_AIX, enum_object<>::to_int32(platform_id::aix));
      assert::are_equal("aix", enum_object<>::to_string(platform_id::aix));
      assert::are_equal(platform_id::aix, enum_object<>::parse<platform_id>("aix"));
    }
    
    void test_method_(mingw) {
      assert::are_equal(16, enum_object<>::to_int32(platform_id::mingw));
      assert::are_equal(PLATFORM_MINGW, enum_object<>::to_int32(platform_id::mingw));
      assert::are_equal("mingw", enum_object<>::to_string(platform_id::mingw));
      assert::are_equal(platform_id::mingw, enum_object<>::parse<platform_id>("mingw"));
    }
    
    void test_method_(msys) {
      assert::are_equal(17, enum_object<>::to_int32(platform_id::msys));
      assert::are_equal(PLATFORM_MSYS, enum_object<>::to_int32(platform_id::msys));
      assert::are_equal("msys", enum_object<>::to_string(platform_id::msys));
      assert::are_equal(platform_id::msys, enum_object<>::parse<platform_id>("msys"));
    }
    
    void test_method_(posix) {
      assert::are_equal(18, enum_object<>::to_int32(platform_id::posix));
      assert::are_equal(PLATFORM_POSIX, enum_object<>::to_int32(platform_id::posix));
      assert::are_equal("posix", enum_object<>::to_string(platform_id::posix));
      assert::are_equal(platform_id::posix, enum_object<>::parse<platform_id>("posix"));
    }
    
    void test_method_(other) {
      assert::are_equal(32767, enum_object<>::to_int32(platform_id::other));
      assert::are_equal(PLATFORM_OTHER, enum_object<>::to_int32(platform_id::other));
      assert::are_equal("other", enum_object<>::to_string(platform_id::other));
      assert::are_equal(platform_id::other, enum_object<>::parse<platform_id>("other"));
    }
  };
}
