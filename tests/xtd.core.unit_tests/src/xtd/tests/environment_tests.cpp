#include <xtd/environment.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(environment_tests) {
  public:
    void test_method_(command_line) {
      assert::is_true(environment::command_line().contains("xtd.core.unit_tests"), csf_);
    }
    
    void test_method_(compiler_version) {
      auto compiler = environment::compiler_version();
#if defined(_MSC_VER)
      assert::are_equal(compiler_id::microsoft_visual_studio, compiler.compiler_id(), csf_);
      assert::are_equal(version {_MSC_VER / 100, _MSC_VER % 100, 0}, compiler.version(), csf_);
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
    
    void test_method_(cpp_version) {
      assert::is_true(environment::cpp_version().language() == language_id::cpp17 || environment::cpp_version().language() == language_id::cpp20, csf_);
    }
    
    void test_method_(current_directory) {
      auto current_directory = environment::current_directory();
      auto directory = io::path::combine(io::path::get_temp_path(), "xtd_environment_test");
      if (!io::directory::exists(directory)) io::directory::create_directory(directory);
      environment::current_directory(directory);
      assert::are_equal(directory, environment::current_directory(), csf_);
      environment::current_directory(current_directory);
      io::directory::remove(directory);
    }
    
    void test_method_(current_thread_id) {
      assert::are_equal(std::this_thread::get_id(), environment::current_thread_id(), csf_);
    }
    
    void test_method_(exit_code) {
      assert::is_zero(environment::exit_code(), csf_);
      environment::exit_code(42);
      assert::are_equal(42, environment::exit_code(), csf_);
      environment::exit_code(0);
      assert::is_zero(environment::exit_code(), csf_);
    }
    
    void test_method_(has_shutdown_started) {
      assert::is_false(environment::has_shutdown_started(), csf_);
    }
    
    void test_method_(is_64_bit_operating_system) {
      // Not possible to check in the unit test
      //assert::is_true(environment::is_64_bit_operating_system(), csf_);
      //assert::is_false(environment::is_64_bit_operating_system(), csf_);
    }
    
    void test_method_(is_64_bit_process) {
      assert::are_equal(sizeof(size_t) == 8, environment::is_64_bit_process(), csf_);
    }
    
    void test_method_(locale) {
      assert::are_equal(std::locale(), environment::locale(), csf_);
    }
    
    void test_method_(machine_name) {
      // Not possible to check in the unit test
      //assert::is_not_empty(environment::machine_name(), csf_);
    }

    void test_method_(new_line) {
      assert::are_equal("\n", environment::new_line(), csf_);
    }
  };
}
