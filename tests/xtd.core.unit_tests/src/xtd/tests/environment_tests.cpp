#include <xtd/environment.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(environment_tests) {
  public:
    void test_method_(compiler_version) {
      auto compiler = environment::compiler_version();
#if defined(_MSC_VER)
      assert::are_equal(compiler_id::visual_studio, compiler.compiler_id(), csf_);
      assert::are_equal(version {_MSC_VER / 100, _MSC_VER % 100}, compiler.version(), csf_);
#elif defined(__clang__)
      assert::are_equal(compiler_id::clang, compiler.compiler_id(), csf_);
      assert::are_equal(version {__clang_major__, __clang_minor__, __clang_patchlevel__}, compiler.version(), csf_);
#elif defined(__GNUC__)
      assert::are_equal(compiler_id::gcc, compiler.compiler_id(), csf_);
      assert::are_equal(version {__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__}, compiler.version(), csf_);
#else
      assert::are_equal(compiler_id::unknown, compiler.compiler_id(), csf_);
      assert::are_equal(version {}, compiler.version(), csf_);
#endif
      
#if !defined(NDEBUG)
      assert::are_equal(build_type::debug, compiler.build_type(), csf_);
      assert::is_true(compiler.is_build_type_debug(), csf_);
#else
      assert::are_equal(build_type::release, compiler.build_type());
      assert::is_false(compiler.is_build_type_debug(), csf_);
#endif
      assert::are_equal(sizeof(size_t) == 8, compiler.is_64_bit(), csf_);
    }
    
    void test_method_(new_line) {
      assert::are_equal("\n", environment::new_line(), csf_);
    }
  };
}
