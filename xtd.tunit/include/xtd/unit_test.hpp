/// @file
/// @brief Contains xtd::unit_test class.
#pragma once
#include "class_event_handler.hpp"
#include "registered_test_class.hpp"
#include "settings.hpp"
#include "test_event_handler.hpp"
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
      unit_test() noexcept {
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
      
      xtd::tunit::test_event_handler<const xtd::tunit::unit_test&> test_cleanup_end;
      xtd::tunit::test_event_handler<const xtd::tunit::unit_test&> test_cleanup_start;
      xtd::tunit::test_event_handler<const xtd::tunit::unit_test&> test_initialize_end;
      xtd::tunit::test_event_handler<const xtd::tunit::unit_test&> test_initialize_start;
      xtd::tunit::test_event_handler<const xtd::tunit::unit_test&> test_end;
      xtd::tunit::test_event_handler<const xtd::tunit::unit_test&> test_failed;
      xtd::tunit::test_event_handler<const xtd::tunit::unit_test&> test_start;
      xtd::tunit::test_event_handler<const xtd::tunit::unit_test&> test_succeed;
      
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_cleanup_end;
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_cleanup_start;
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_end;
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_initialize_end;
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_initialize_start;
      xtd::event_handler<const xtd::tunit::unit_test&> unit_test_start;

      virtual void on_class_cleanup_end(const xtd::tunit::class_event_args& e) const {this->class_cleanup_end(*this, e);}
      virtual void on_class_cleanup_start(const xtd::tunit::class_event_args& e) const {this->class_cleanup_start(*this, e);}
      virtual void on_class_end(const xtd::tunit::class_event_args& e) const {this->class_end(*this, e);}
      virtual void on_class_initialize_end(const xtd::tunit::class_event_args& e) const {this->class_initialize_end(*this, e);}
      virtual void on_class_initialize_start(const xtd::tunit::class_event_args& e) const {this->class_initialize_start(*this, e);}
      virtual void on_class_start(const xtd::tunit::class_event_args& e) const {this->class_start(*this, e);}

      virtual void on_test_cleanup_end(const xtd::tunit::test_event_args& e) const {this->test_cleanup_end(*this, e);}
      virtual void on_test_cleanup_start(const xtd::tunit::test_event_args& e) const {this->test_cleanup_start(*this, e);}
      virtual void on_test_initialize_end(const xtd::tunit::test_event_args& e) const {this->test_initialize_end(*this, e);}
      virtual void on_test_initialize_start(const xtd::tunit::test_event_args& e) const {this->test_initialize_start(*this, e);}
      virtual void on_test_end(const xtd::tunit::test_event_args& e) const {this->test_end(*this, e);}
      virtual void on_test_failed(const xtd::tunit::test_event_args& e) const {this->test_failed(*this, e);}
      virtual void on_test_start(const xtd::tunit::test_event_args& e) const {this->test_start(*this, e);}
      virtual void on_test_succeed(const xtd::tunit::test_event_args& e) const {this->test_succeed(*this, e);}

      virtual void on_unit_test_cleanup_end(const xtd::event_args& e) const {this->unit_test_cleanup_end(*this, e);}
      virtual void on_unit_test_cleanup_start(const xtd::event_args& e) const {this->unit_test_cleanup_start(*this, e);}
      virtual void on_unit_test_end(const xtd::event_args& e) const {this->unit_test_end(*this, e);}
      virtual void on_unit_test_initialize_end(const xtd::event_args& e) const {this->unit_test_initialize_end(*this, e);}
      virtual void on_unit_test_initialize_start(const xtd::event_args& e) const {this->unit_test_initialize_start(*this, e);}
      virtual void on_unit_test_start(const xtd::event_args& e) const {this->unit_test_start(*this, e);}

      int run() {
        this->start_time_point = std::chrono::high_resolution_clock::now();
        try {
          this->on_unit_test_start(xtd::event_args::empty());
          for (auto test_class : test_classes())
            test_class.test()->run(*this);
          this->on_unit_test_end(xtd::event_args::empty());
        } catch(...) {
          xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
          // do error...
        }
        this->end_time_point = std::chrono::high_resolution_clock::now();
        return xtd::tunit::settings::default_settings().exit_status();
      }
      
      size_t test_cases_count() const noexcept {return this->test_classes().size();}
      size_t test_count() const noexcept {
        size_t count = 0;
        for (auto test_class : this->test_classes())
          count += test_class.test()->test_count();
        return count;
      }
      
      size_t ignore_test_count() const noexcept {
        size_t count = 0;
        for (auto test_class : this->test_classes())
          count += test_class.test()->ignore_test_count();
        return count;
      }
      
      std::chrono::milliseconds elapsed_time() const noexcept {
        using namespace std::chrono_literals;
        if (this->start_time_point.time_since_epoch() == 0ms && this->end_time_point.time_since_epoch() == 0ms) return 0ms;
        if (this->end_time_point.time_since_epoch() == 0ms) return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - this->start_time_point);
        return std::chrono::duration_cast<std::chrono::milliseconds>(this->end_time_point - this->start_time_point);
      }
      
    private:
      template <typename TestClass>
      friend struct xtd::tunit::test_class_attribute;
      
      static void add(const xtd::tunit::registered_test_class& test_class) {test_classes().push_back(test_class);}
      
      void unit_test_cleanup() {
      }
      
      void unit_test_initialize() {
      }
      
      static std::vector<xtd::tunit::registered_test_class>& test_classes() {
        static std::vector<xtd::tunit::registered_test_class> test_classes;
        return test_classes;
      }

      std::chrono::high_resolution_clock::time_point end_time_point;
      std::chrono::high_resolution_clock::time_point start_time_point;
    };
  }
}
