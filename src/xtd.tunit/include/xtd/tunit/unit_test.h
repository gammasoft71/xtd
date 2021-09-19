/// @file
/// @brief Contains xtd::tunit::unit_test class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../tunit_export.h"
#include "event_listener.h"
#include "registered_test_class.h"
#include "settings.h"
#include <chrono>
#include <iomanip>
#include <fstream>
#include <memory>
#include <random>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @cond
    template <typename test_class_t>
    class test_class_attribute;
    /// @endcond

    /// @brief The template class.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    class tunit_export_ unit_test {
    public:
      explicit unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener) noexcept;
      
      unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener, int argc, char* argv[]) noexcept : arguments(argv + 1, argv + argc), name_(get_filename(argv[0])), event_listener_(std::move(event_listener)) {}

      /// @cond
      virtual ~unit_test() {}
      /// @endcond
      
      /// @brief Runs all tests in this UnitTest object and prints the result.
      /// @return EXIT_SUCCESS (0) if succeed; otherwise return EXIT_FAILURE (1).
      int run() {
        if (parse_arguments(arguments))
          return xtd::tunit::settings::default_settings().exit_status();

        if (xtd::tunit::settings::default_settings().list_tests()) {
          std::vector<std::string> tests;
          for (auto test_class : test_classes())
            for(auto test : test_class.test()->tests())
              tests.push_back(test_class.test()->name() + '.' + test.name());
          return list_tests(tests);
        }

        if (xtd::tunit::settings::default_settings().shuffle_test()) {
          std::random_device rd;
          std::mt19937 g = xtd::tunit::settings::default_settings().random_seed() == 0 ? std::mt19937(rd()) : std::mt19937(xtd::tunit::settings::default_settings().random_seed());
          std::shuffle(test_classes().begin(), test_classes().end(), g);
        }
          
        for (repeat_iteration_ = 1; repeat_iteration_ <= xtd::tunit::settings::default_settings().repeat_test() || xtd::tunit::settings::default_settings().repeat_test() < 0; ++repeat_iteration_) {
           try {
            event_listener_->on_unit_test_start(xtd::tunit::tunit_event_args(*this));
            
            event_listener_->on_unit_test_initialize_start(xtd::tunit::tunit_event_args(*this));
            unit_test_initialize();
            event_listener_->on_unit_test_initialize_end(xtd::tunit::tunit_event_args(*this));
            
            start_time_point_ = std::chrono::high_resolution_clock::now();
            for (auto& test_class : test_classes())
              if (test_class.test()->test_count())
                test_class.test()->run(*this);
            end_time_point_ = std::chrono::high_resolution_clock::now();

            event_listener_->on_unit_test_cleanup_start(xtd::tunit::tunit_event_args(*this));
            unit_test_cleanup();
            event_listener_->on_unit_test_cleanup_end(xtd::tunit::tunit_event_args(*this));
            
            event_listener_->on_unit_test_end(xtd::tunit::tunit_event_args(*this));
          } catch(const std::exception&) {
            xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
            // do error...
          } catch(...) {
            xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
            // do error...
          }
        }

        xtd::tunit::settings::default_settings().end_time(std::chrono::system_clock::now());
        write_xml();
        
        return xtd::tunit::settings::default_settings().exit_status();
      }
      
      int repeat_iteration() const noexcept {return repeat_iteration_;}
      
      int repeat_iteration_count() const noexcept {return xtd::tunit::settings::default_settings().repeat_test();}
      
      bool repeat_tests() const noexcept {return xtd::tunit::settings::default_settings().repeat_test() != 1;}
      
      size_t test_cases_count() const noexcept {
        size_t count = 0;
        for (auto test_class : test_classes())
          if (test_class.test()->test_count())
            count ++;
        return count;
      }
      
      size_t test_count() const noexcept {
        size_t count = 0;
        for (auto test_class : test_classes())
          count += test_class.test()->test_count();
        return count;
      }

      size_t aborted_test_count() const noexcept {
        size_t count = 0;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.aborted()) count++;
        return count;
      }
      
      std::vector<std::string> aborted_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.aborted()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }

      std::chrono::milliseconds elapsed_time() const noexcept {
        using namespace std::chrono_literals;
        if (start_time_point_.time_since_epoch() == 0ms && end_time_point_.time_since_epoch() == 0ms) return 0ms;
        if (end_time_point_.time_since_epoch() == 0ms) return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time_point_);
        return std::chrono::duration_cast<std::chrono::milliseconds>(end_time_point_ - start_time_point_);
      }

      size_t ignored_test_count() const noexcept {
        size_t count = 0;
        for (auto test_class : test_classes())
          count += test_class.test()->ignored_test_count();
        return count;
      }

      std::vector<std::string> ignored_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.ignored()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }

      size_t failed_test_count() const noexcept {
        size_t count = 0;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.failed()) count++;
        return count;
      }

      std::vector<std::string> failed_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.failed()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }

      size_t succeed_test_count() const noexcept {
        size_t count = 0;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.succeed()) count++;
        return count;
      }

      std::vector<std::string> succeed_test_names() const noexcept {
        std::vector<std::string> names;
        for (auto& test_class : test_classes())
          for (auto& test : test_class.test()->tests())
            if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.succeed()) names.push_back(test_class.test()->name() + "." + test.name());
        return names;
      }
      
    protected:
      virtual int list_tests(const std::vector<std::string>& tests) {
        return xtd::tunit::settings::default_settings().exit_status();
      }
      
      virtual bool parse_arguments(const std::vector<std::string>& args) {
        for (auto arg : args) {
          if (arg == "--also_run_ignored_tests") xtd::tunit::settings::default_settings().also_run_ignored_tests(true);
          else if (arg.find("--filter_tests=") == 0) xtd::tunit::settings::default_settings().filter_tests(arg.substr(15));
          else if (arg == "--list_tests") xtd::tunit::settings::default_settings().list_tests(true);
          else if (arg == "--output_color=true") xtd::tunit::settings::default_settings().output_color(true);
          else if (arg == "--output_color=false") xtd::tunit::settings::default_settings().output_color(false);
          else if (arg.find("--output_xml") == 0) { xtd::tunit::settings::default_settings().output_xml(true);
            if (arg[12] == '=') xtd::tunit::settings::default_settings().output_xml_path(arg.substr(13));
          } else if (arg.find("--random_seed=") == 0) xtd::tunit::settings::default_settings().random_seed(std::stoi(arg.substr(14)));
          else if (arg.find("--repeat_tests=") == 0) xtd::tunit::settings::default_settings().repeat_tests(std::stoi(arg.substr(15)));
          else if (arg == "--show_duration=true") xtd::tunit::settings::default_settings().show_duration(true);
          else if (arg == "--show_duration=false") xtd::tunit::settings::default_settings().show_duration(false);
          else if (arg == "--shuffle_tests") xtd::tunit::settings::default_settings().shuffle_test(true);
        }
        return false;
      }

    private:
      template <typename test_class_t>
      friend class xtd::tunit::test_class_attribute;
      friend class xtd::tunit::test_class;
      friend class xtd::tunit::test;
      friend class xtd::tunit::base_assert;

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
        std::tm tm = *std::localtime(&time_t);
        std::stringstream ss;
        ss << tm.tm_year + 1900 << "-" << std::setfill('0') << std::setw(2) << tm.tm_mon << "-" << std::setfill('0') << std::setw(2) << tm.tm_mday;
        ss << "T" << std::setfill('0') << std::setw(2) << tm.tm_hour << ":" << std::setfill('0') << std::setw(2) << tm.tm_min << ":" << std::setfill('0') << std::setw(2) << tm.tm_sec;
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
        if (test.stack_frame() != xtd::diagnostics::stack_frame::empty())
          ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << "&#0x0A;";
        ss << "Expected: " << test.expect() << "&#0x0A;";
        ss << "But was : " << test.actual();
        return ss.str();
      }
      
      std::string cdata_message_to_string(const xtd::tunit::test& test) {
        std::stringstream ss;
        if (test.stack_frame() != xtd::diagnostics::stack_frame::empty())
          ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << std::endl;
        ss << "Expected: " << test.expect() << std::endl;
        ss << "But was : " << test.actual();
        return ss.str();
      }
      
      void write_xml() {
        if (xtd::tunit::settings::default_settings().output_xml()) {
          std::fstream file(xtd::tunit::settings::default_settings().output_xml_path(), std::ios::out | std::ios::trunc);
          file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
          file << "<testsuites tests=\"" << test_count() << "\" failures=\"" << failed_test_count() << "\" disabled=\"" << ignored_test_count() << "\" errors=\"" << 0 << "\" timestamp=\"" << to_string(xtd::tunit::settings::default_settings().start_time()) << "\" time=\"" << to_string(elapsed_time()) << "\" name=\"" << name_ << "\">" << std::endl;
          for (auto& test_class : test_classes()) {
            file << "  <testsuite name=\"" << test_class.test()->name() << "\" tests=\"" << test_class.test()->test_count() << "\" failures=\"" << test_class.test()->failed_test_count() << "\" disabled=\"" << test_class.test()->ignored_test_count() << "\" error=\"" << test_class.test()->failed_test_count() << "\" time=\"" << to_string(test_class.test()->elapsed_time()) << "\">" << std::endl;
            for (auto& test : test_class.test()->tests()) {
              file << "    <testcase name=\"" << test.name() << "\" status=\"" << status_to_string(test) << "\" time=\"" << to_string(test.elapsed_time()) << "\" classname=\"" << test_class.test()->name() << "\"";
              if (!test.failed())
                file << " />" << std::endl;
              else {
                file << ">" << std::endl;
                file << "      <failure message=\"" << message_to_string(test) << "\" type= \"" << "\">" << "<![CDATA[" << cdata_message_to_string(test) << "]]></failure>" << std::endl;
                file << "    </testcase>" << std::endl;
              }
            }
            file << "  </testsuite>" << std::endl;
          }
          file << "</testsuites>" << std::endl;
          file.close();
        }
      }

      std::vector<std::string> arguments;
      std::string name_ = "AllTests";
      std::unique_ptr<xtd::tunit::event_listener> event_listener_;
      std::chrono::high_resolution_clock::time_point end_time_point_;
      int repeat_iteration_ = 0;
      std::chrono::high_resolution_clock::time_point start_time_point_;
    };
  }
}
