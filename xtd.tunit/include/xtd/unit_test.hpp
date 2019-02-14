/// @file
/// @brief Contains xtd::unit_test class.
#pragma once
#include "class_event_handler.hpp"
#include "registered_test_class.hpp"
#include <chrono>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The TUnit namespace contains a unit test framework.
  namespace tunit {
    /// @cond
    template <typename TestClass>
    struct test_class_attribute;
    /// @endcond

    /// @brief The template class.
    class unit_test {
    public:
      unit_test() = default;
      
      unit_test(char* argv[], int argc) {
        // parse args...
        on_unit_test_initialize_start(xtd::event_args::empty());
        unit_test_initialize();
        on_unit_test_initialize_end(xtd::event_args::empty());
      }

      /// @cond
      virtual ~unit_test() {
        on_unit_test_cleanup_start(xtd::event_args::empty());
        unit_test_cleanup();
        on_unit_test_cleanup_end(xtd::event_args::empty());
      }
      /// @endcond
      
      xtd::tunit::class_event_handler<const xtd::tunit::unit_test&> class_cleanup_end;
      xtd::tunit::class_event_handler<const xtd::tunit::unit_test&> class_cleanup_start;
      xtd::tunit::class_event_handler<const xtd::tunit::unit_test&> class_end;
      xtd::tunit::class_event_handler<const xtd::tunit::unit_test&> class_initialize_end;
      xtd::tunit::class_event_handler<const xtd::tunit::unit_test&> class_initialize_start;
      xtd::tunit::class_event_handler<const xtd::tunit::unit_test&> class_start;
      
      xtd::event_handler<const xtd::tunit::unit_test&> test_cleanup_end;
      xtd::event_handler<const xtd::tunit::unit_test&> test_cleanup_start;
      xtd::event_handler<const xtd::tunit::unit_test&> test_initialize_end;
      xtd::event_handler<const xtd::tunit::unit_test&> test_initialize_start;
      xtd::event_handler<const xtd::tunit::unit_test&> test_end;
      xtd::event_handler<const xtd::tunit::unit_test&> test_failed;
      xtd::event_handler<const xtd::tunit::unit_test&> test_start;
      xtd::event_handler<const xtd::tunit::unit_test&> test_succeed;
      
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_cleanup_end;
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_cleanup_start;
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_end;
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_initialize_end;
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_initialize_start;
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_start;

      bool also_run_ignored_tests() const noexcept {return this->also_run_ignored_tests_;}

      virtual void on_class_cleanup_end(const xtd::tunit::class_event_args& e) const {this->class_cleanup_end(*this, e);}
      virtual void on_class_cleanup_start(const xtd::tunit::class_event_args& e) const {this->class_cleanup_start(*this, e);}
      virtual void on_class_end(const xtd::tunit::class_event_args& e) const {this->class_end(*this, e);}
      virtual void on_class_initialize_end(const xtd::tunit::class_event_args& e) const {this->class_initialize_end(*this, e);}
      virtual void on_class_initialize_start(const xtd::tunit::class_event_args& e) const {this->class_initialize_start(*this, e);}
      virtual void on_class_start(const xtd::tunit::class_event_args& e) const {this->class_start(*this, e);}

      virtual void on_test_cleanup_end(const xtd::event_args& e) const {this->test_cleanup_end(*this, e);}
      virtual void on_test_cleanup_start(const xtd::event_args& e) const {this->test_cleanup_start(*this, e);}
      virtual void on_test_initialize_end(const xtd::event_args& e) const {this->test_initialize_end(*this, e);}
      virtual void on_test_initialize_start(const xtd::event_args& e) const {this->test_initialize_start(*this, e);}
      virtual void on_test_end(const xtd::event_args& e) const {this->test_end(*this, e);}
      virtual void on_test_failed(const xtd::event_args& e) const {this->test_failed(*this, e);}
      virtual void on_test_start(const xtd::event_args& e) const {this->test_start(*this, e);}
      virtual void on_test_succeed(const xtd::event_args& e) const {this->test_succeed(*this, e);}

      virtual void on_unit_test_cleanup_end(const xtd::event_args& e) const {this->unit_test_cleanup_end(*this, e);}
      virtual void on_unit_test_cleanup_start(const xtd::event_args& e) const {this->unit_test_cleanup_start(*this, e);}
      virtual void on_unit_test_end(const xtd::event_args& e) const {this->unit_test_end(*this, e);}
      virtual void on_unit_test_initialize_end(const xtd::event_args& e) const {this->unit_test_initialize_end(*this, e);}
      virtual void on_unit_test_initialize_start(const xtd::event_args& e) const {this->unit_test_initialize_start(*this, e);}
      virtual void on_unit_test_start(const xtd::event_args& e) const {this->unit_test_start(*this, e);}

      int run() {
        try {
          this->on_unit_test_start(xtd::event_args::empty());
          for (auto test_class : test_classes())
            test_class.test()->run(*this);
          this->on_unit_test_end(xtd::event_args::empty());
        } catch(...) {
          // do error...
        }
        return 0;
      }
      
      size_t test_cases_count() const noexcept {return this->test_classes().size();}
      size_t test_count() const noexcept {
        size_t count = 0;
        for (auto test_class : this->test_classes())
          count += test_class.test()->test_methods().size();
        return count;
      }
      
      std::chrono::high_resolution_clock::duration elapsed_time() const noexcept {return std::chrono::high_resolution_clock::now() - this->start_time_point;}

    private:
      template <typename TestClass>
      friend struct xtd::tunit::test_class_attribute;
      std::chrono::high_resolution_clock::time_point start_time_point = std::chrono::high_resolution_clock::now();
      
      static void add(const xtd::tunit::registered_test_class& test_class) {test_classes().push_back(test_class);}
      
      void unit_test_cleanup() {
      }
      
      void unit_test_initialize() {
      }
      
      static std::vector<xtd::tunit::registered_test_class>& test_classes() {
        static std::vector<xtd::tunit::registered_test_class> test_classes;
        return test_classes;
      }
      
      bool also_run_ignored_tests_ = false;
    };
  }
}
