/// @file
/// @brief Contains xtd::tunit::unit_test class.
#pragma once
#include "event_listener.hpp"
#include "registered_test_class.hpp"
#include "settings.hpp"
#include <chrono>
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @cond
    template <typename TestClass>
    struct test_class_attribute;
    /// @endcond

    /// @brief The template class.
    class unit_test {
    public:
      unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener) noexcept : event_listener_(std::move(event_listener)) {}
      
      explicit unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener, char* argv[], int argc) noexcept : event_listener_(std::move(event_listener)) {
        /// parse args...
      }

      /// @cond
      virtual ~unit_test() {
      }
      /// @endcond
      
      /// @brief Runs all tests in this UnitTest object and prints the result.
      /// @return 0 if succeed; otherwise return 1.
      int run() {
        this->start_time_point_ = std::chrono::high_resolution_clock::now();
        try {
          this->event_listener_->on_unit_test_start(xtd::tunit::tunit_event_args(*this));

          this->event_listener_->on_unit_test_initialize_start(xtd::tunit::tunit_event_args(*this));
          unit_test_initialize();
          this->event_listener_->on_unit_test_initialize_end(xtd::tunit::tunit_event_args(*this));
          
          for (auto& test_class : test_classes())
            if (test_class.test()->test_count())
              test_class.test()->run(*this);

          this->event_listener_->on_unit_test_cleanup_start(xtd::tunit::tunit_event_args(*this));
          unit_test_cleanup();
          this->event_listener_->on_unit_test_cleanup_end(xtd::tunit::tunit_event_args(*this));
          
          this->event_listener_->on_unit_test_end(xtd::tunit::tunit_event_args(*this));
        } catch(const std::exception&) {
          xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
          // do error...
        } catch(...) {
          xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
          // do error...
        }
        this->end_time_point_ = std::chrono::high_resolution_clock::now();

        return xtd::tunit::settings::default_settings().exit_status();
      }
      
      size_t test_cases_count() const noexcept {
        size_t count = 0;
        for (auto test_class : this->test_classes())
          if (test_class.test()->test_count())
            count ++;
        return count;
      }
      
      size_t test_count() const noexcept {
        size_t count = 0;
        for (auto test_class : this->test_classes())
          count += test_class.test()->test_count();
        return count;
      }

      size_t aborted_test_count() const noexcept {
        size_t count = 0;
        for (auto& test_class : this->test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_valid_test_name(test_class.test()->name(), test.name()) && test.aborted()) count++;
        return count;
      }
      
      std::vector<std::string> aborted_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : this->test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_valid_test_name(test_class.test()->name(), test.name()) && test.aborted()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }

      std::chrono::milliseconds elapsed_time() const noexcept {
        using namespace std::chrono_literals;
        if (this->start_time_point_.time_since_epoch() == 0ms && this->end_time_point_.time_since_epoch() == 0ms) return 0ms;
        if (this->end_time_point_.time_since_epoch() == 0ms) return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - this->start_time_point_);
        return std::chrono::duration_cast<std::chrono::milliseconds>(this->end_time_point_ - this->start_time_point_);
      }

      size_t ignored_test_count() const noexcept {
        size_t count = 0;
        for (auto test_class : this->test_classes())
          count += test_class.test()->ignored_test_count();
        return count;
      }

      std::vector<std::string> ignored_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : this->test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_valid_test_name(test_class.test()->name(), test.name()) && test.ignored()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }

      size_t failed_test_count() const noexcept {
        size_t count = 0;
        for (auto& test_class : this->test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_valid_test_name(test_class.test()->name(), test.name()) && test.failed()) count++;
        return count;
      }

      std::vector<std::string> failed_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : this->test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_valid_test_name(test_class.test()->name(), test.name()) && test.failed()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }

      size_t succeed_test_count() const noexcept {
        size_t count = 0;
        for (auto& test_class : this->test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_valid_test_name(test_class.test()->name(), test.name()) && test.succeed()) count++;
        return count;
      }

      std::vector<std::string> succeed_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : this->test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_valid_test_name(test_class.test()->name(), test.name()) && test.succeed()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }

    private:
      template <typename TestClass>
      friend struct xtd::tunit::test_class_attribute;
      friend struct xtd::tunit::test_class;
      friend struct xtd::tunit::test;

      static void add(const xtd::tunit::registered_test_class& test_class) {test_classes().push_back(test_class);}
      
      void unit_test_cleanup() {
      }
      
      void unit_test_initialize() {
      }
      
      static std::vector<xtd::tunit::registered_test_class>& test_classes() {
        static std::vector<xtd::tunit::registered_test_class> test_classes;
        return test_classes;
      }

      std::unique_ptr<xtd::tunit::event_listener> event_listener_;
      std::chrono::high_resolution_clock::time_point end_time_point_;
      std::chrono::high_resolution_clock::time_point start_time_point_;
    };
  }
}
