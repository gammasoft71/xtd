/// @file
/// @brief Contains xtd::tunit::unit_test class.
#pragma once
#include "event_listener.hpp"
#include "registered_test_class.hpp"
#include "settings.hpp"
#include <chrono>
#include <iomanip>
#include <fstream>
#include <memory>
#include <string>

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
        this->name_ = get_filename(argv[0]);
        /// parse args...
      }

      /// @cond
      virtual ~unit_test() {
      }
      /// @endcond
      
      /// @brief Runs all tests in this UnitTest object and prints the result.
      /// @return 0 if succeed; otherwise return 1.
      int run() {
        xtd::tunit::settings::default_settings().start_time(std::chrono::system_clock::now());
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

        xtd::tunit::settings::default_settings().end_time(std::chrono::system_clock::now());
        write_xml();
        
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
      
      std::string get_filename(const std::string& path) {
        std::string filename = path;
        const size_t last_slash_idx = filename.find_last_of("\\/");
        if (std::string::npos != last_slash_idx)
          filename.erase(0, last_slash_idx + 1);
        
        const size_t period_idx = filename.rfind('.');
        if (std::string::npos != period_idx)
          filename.erase(period_idx);
        return filename;
      }
      
      std::string to_string(const std::chrono::milliseconds& ms) {
        std::stringstream ss;
        if (ms.count() == 0)
          ss << 0;
        else
          ss << ms.count() / 1000 << "." << std::setfill('0') << std::setw(3) << ms.count() % 1000;
        return ss.str();
      }
      
      std::string to_string(const std::chrono::time_point<std::chrono::system_clock>& time) {
        std::time_t time_t = std::chrono::system_clock::to_time_t(time);
        std::tm* tm = std::localtime(&time_t);
        std::stringstream ss;
        ss << tm->tm_year + 1900 << "-" << std::setfill('0') << std::setw(2) << tm->tm_mon << "-" << std::setfill('0') << std::setw(2) << tm->tm_mday;
        ss << "T" << std::setfill('0') << std::setw(2) << tm->tm_hour << ":" << std::setfill('0') << std::setw(2) << tm->tm_min << ":" << std::setfill('0') << std::setw(2) << tm->tm_sec;
        return ss.str();
      }
      
      std::string status_to_string(const xtd::tunit::test& test) {
        std::stringstream ss;
        if (test.not_started() || test.ignored()) ss << "notrun";
        else ss << "run";
        return ss.str();
      }
      
      std::string message_to_string(const xtd::tunit::test& test) {
        std::stringstream ss;
        if (test.line_info() != xtd::tunit::line_info::empty())
          ss << test.line_info().file_path() << ":" << test.line_info().line_number() << "&#0x0A;";
        ss << "Expected: " << test.expect() << "&#0x0A;";
        ss << "But was : " << test.actual();
        return ss.str();
      }
      
      std::string cdata_message_to_string(const xtd::tunit::test& test) {
        std::stringstream ss;
        if (test.line_info() != xtd::tunit::line_info::empty())
          ss << test.line_info().file_path() << ":" << test.line_info().line_number() << std::endl;
        ss << "Expected: " << test.expect() << std::endl;
        ss << "But was : " << test.actual();
        return ss.str();
      }
      
      void write_xml() {
        if (xtd::tunit::settings::default_settings().output_xml() != "") {
          std::fstream file(xtd::tunit::settings::default_settings().output_xml(), std::ios::out | std::ios::trunc);
          file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
          file << "<testsuites tests=\"" << this->test_count() << "\" failures=\"" << this->failed_test_count() << "\" disabled=\"" << this->ignored_test_count() << "\" errors=\"" << 0 << "\" timestamp=\"" << to_string(xtd::tunit::settings::default_settings().start_time()) << "\" time=\"" << to_string(this->elapsed_time()) << "\" name=\"" << this->name_ << "\">" << std::endl;
          for (auto& test_class : test_classes()) {
            file << "  <testsuite name=\"" << test_class.test()->name() << "\" tests=\"" << test_class.test()->test_count() << "\" failures=\"" << test_class.test()->failed_test_count() << "\" disabled=\"" << test_class.test()->ignored_test_count() << "\" error=\"" << test_class.test()->failed_test_count() << "\" time=\"" << to_string(test_class.test()->elapsed_time()) << "\">" << std::endl;
            for (auto& test : test_class.test()->tests()) {
              file << "    <testcase name=\"" << test.name() << "\" status=\"" << status_to_string(test) << "\" time=\"" << to_string(test.elapsed_time()) << "\" classname=\"" << test_class.test()->name() << "\"";
              if (!test.failed())
                file << " />";
              else {
                file << ">" << std::endl;
                file << "      <failure message=\"" << message_to_string(test) << "\" type= \"" << "\">";
                // datas...
                file << "<![CDATA[" << cdata_message_to_string(test) << "]]></failure>";
                file << std::endl << "    </testcase>";
              }
              file << std::endl;
            }
            file << "  </testsuite>" << std::endl;
          }
          file << "</testsuites>" << std::endl;
          file.close();
        }
      }

      std::string name_ = "AllTests";
      std::unique_ptr<xtd::tunit::event_listener> event_listener_;
      std::chrono::high_resolution_clock::time_point end_time_point_;
      std::chrono::high_resolution_clock::time_point start_time_point_;
    };
  }
}
