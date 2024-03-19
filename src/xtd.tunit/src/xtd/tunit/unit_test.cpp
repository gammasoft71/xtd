#include "../../../include/xtd/tunit/unit_test.h"
#include <xtd/random>

#if defined(_WIN32)
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;
int __tunit_argc = __argc;
char** __tunit_argv = __argv;
#else
int __tunit_argc;
char** __tunit_argv;

namespace {
  __attribute__((constructor)) void startup_program(int argc, char** argv) {
    __tunit_argc = argc;
    __tunit_argv = argv;
  }
}
#endif

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

unit_test::unit_test(unique_ptr<event_listener> event_listener) noexcept : unit_test(std::move(event_listener), __tunit_argc, __tunit_argv) {
}

unit_test::unit_test(unique_ptr<event_listener> event_listener, int argc, char* argv[]) noexcept : arguments(argv == nullptr ? 0 : argv + 1, argv == nullptr ? 0 : argv + argc), name_(get_filename(argv[0])), event_listener_(std::move(event_listener)) {
}

unit_test::~unit_test() {
}

int32 unit_test::repeat_iteration() const noexcept {
  return repeat_iteration_;
}

int32 unit_test::repeat_iteration_count() const noexcept {
  return settings::default_settings().repeat_test();
}

bool unit_test::repeat_tests() const noexcept {
  return settings::default_settings().repeat_test() != 1;
}

size_t unit_test::test_cases_count() const noexcept {
  auto count = 0_z;
  for (auto test_class : test_classes())
    if (test_class.test()->test_count())
      count ++;
  return count;
}

size_t unit_test::test_count() const noexcept {
  auto count = 0_z;
  for (auto test_class : test_classes())
    count += test_class.test()->test_count();
  return count;
}

size_t unit_test::aborted_test_count() const noexcept {
  auto count = 0_z;
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.aborted()) count++;
  return count;
}

vector<ustring> unit_test::aborted_test_names() const noexcept {
  auto names = vector<ustring> {};
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.aborted()) names.push_back(test_class.test()->name() + "." + test.name());
  return names;
}

time_span unit_test::elapsed_time() const noexcept {
  if (start_time_point_.ticks() == 0 && end_time_point_.ticks() == 0) return 0_ms;
  if (end_time_point_.ticks() == 0) return date_time::now() - start_time_point_;
  return end_time_point_ - start_time_point_;
}

size_t unit_test::ignored_test_count() const noexcept {
  auto count = 0_z;
  for (auto test_class : test_classes())
    count += test_class.test()->ignored_test_count();
  return count;
}

vector<ustring> unit_test::ignored_test_names() const noexcept {
  auto names = vector<ustring> {};
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.ignored()) names.push_back(test_class.test()->name() + "." + test.name());
  return names;
}

size_t unit_test::failed_test_count() const noexcept {
  auto count = 0_z;
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.failed()) count++;
  return count;
}

vector<ustring> unit_test::failed_test_names() const noexcept {
  auto names = vector<ustring> {};
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.failed()) names.push_back(test_class.test()->name() + "." + test.name());
  return names;
}

size_t unit_test::succeed_test_count() const noexcept {
  auto count = 0_z;
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.succeed()) count++;
  return count;
}

vector<ustring> unit_test::succeed_test_names() const noexcept {
  auto names = vector<ustring> {};
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.succeed()) names.push_back(test_class.test()->name() + "." + test.name());
  return names;
}

int32 unit_test::run() {
  if (parse_arguments(arguments))
    return settings::default_settings().exit_status();
    
  if (settings::default_settings().count_tests()) {
    auto count = 0;
    for (auto test_class : test_classes())
      for (auto test : test_class.test()->tests())
        count++;
        
    return count_tests(count);
  }
  
  if (settings::default_settings().list_tests()) {
    auto tests = vector<ustring> {};
    for (auto test_class : test_classes())
      for (auto test : test_class.test()->tests())
        tests.push_back(test_class.test()->name() + '.' + test.name());
        
    if (settings::default_settings().output_json()) write_list_tests_json();
    if (settings::default_settings().output_xml()) write_list_tests_xml();
    
    return list_tests(tests);
  }
  
  system_exception::enable_stack_trace(settings::default_settings().enable_stack_trace());
  
  auto random = settings::default_settings().random_seed() ? xtd::random(settings::default_settings().random_seed()) : xtd::random();
  
  for (repeat_iteration_ = 1; repeat_iteration_ <= settings::default_settings().repeat_test() || settings::default_settings().repeat_test() < 0; ++repeat_iteration_) {
    if (settings::default_settings().shuffle_test())
      shuffle(test_classes().begin(), test_classes().end(), random.generator());
      
    try {
      if (!settings::default_settings().brief()) event_listener_->on_unit_test_start(tunit_event_args(*this));
      
      if (!settings::default_settings().brief()) event_listener_->on_unit_test_initialize_start(tunit_event_args(*this));
      unit_test_initialize();
      if (!settings::default_settings().brief()) event_listener_->on_unit_test_initialize_end(tunit_event_args(*this));
      
      start_time_point_ = date_time::now();
      for (auto& test_class : test_classes())
        if (test_class.test()->test_count())
          test_class.test()->run(*this);
      end_time_point_ = date_time::now();
      
      if (!settings::default_settings().brief()) event_listener_->on_unit_test_cleanup_start(tunit_event_args(*this));
      unit_test_cleanup();
      if (!settings::default_settings().brief()) event_listener_->on_unit_test_cleanup_end(tunit_event_args(*this));
      
      event_listener_->on_unit_test_end(tunit_event_args(*this));
    } catch (const exception&) {
      settings::default_settings().exit_status(EXIT_FAILURE);
      // do error...
    } catch (...) {
      settings::default_settings().exit_status(EXIT_FAILURE);
      // do error...
    }
  }
  
  settings::default_settings().end_time(date_time::now());
  
  if (settings::default_settings().output_json()) write_tests_json();
  if (settings::default_settings().output_xml()) write_tests_xml();
  
  return settings::default_settings().exit_status();
}

int32 unit_test::count_tests(int32 count) {
  return settings::default_settings().exit_status();
}

int32 unit_test::list_tests(const vector<ustring>& tests) {
  return settings::default_settings().exit_status();
}

bool unit_test::parse_arguments(const vector<ustring>& args) {
  auto gtest_compatibility = settings::default_settings().gtest_compatibility();
  for (auto arg : args) {
    if (arg == "--gtest_compatibility" || arg.find("--gtest") == 0) gtest_compatibility = true;
    // Test selection :
    if (arg == "--count_tests") settings::default_settings().count_tests(true);
    else if (arg == "--list_tests") settings::default_settings().list_tests(true);
    else if (arg == "--gtest_list_tests") settings::default_settings().list_tests(true);
    else if (arg.find("--filter_tests=") == 0) settings::default_settings().filter_tests(arg.substring(15).split({':'}));
    else if (arg.find("--gtest_filter=") == 0) settings::default_settings().filter_tests(arg.substring(15).split({':'}));
    else if (arg == "--also_run_ignored_tests") settings::default_settings().also_run_ignored_tests(true);
    else if (arg == "--gtest_also_run_disabled_tests") settings::default_settings().also_run_ignored_tests(true);
    // Test execution:
    else if (arg.find("--repeat_tests=") == 0) settings::default_settings().repeat_tests(convert::to_int32(arg.substring(15)));
    else if (arg.find("--gtest_repeat=") == 0) settings::default_settings().repeat_tests(convert::to_int32(arg.substring(15)));
    else if (arg == "--shuffle_tests") settings::default_settings().shuffle_test(true);
    else if (arg == "--gtest_shuffle") settings::default_settings().shuffle_test(true);
    else if (arg.find("--random_seed=") == 0) settings::default_settings().random_seed(convert::to_uint32(arg.substring(14)));
    else if (arg.find("--gtest_random_seed=") == 0) settings::default_settings().random_seed(convert::to_uint32(arg.substring(20)));
    else if (arg == "--enable_stack_trace=true") settings::default_settings().enable_stack_trace(true);
    else if (arg == "--enable_stack_trace=false") settings::default_settings().enable_stack_trace(false);
    // Test output
    else if (arg == "--output_color=true") settings::default_settings().output_color(true);
    else if (arg == "--gtest_color=auto" || arg == "--gtest_color=yes") settings::default_settings().output_color(true);
    else if (arg == "--output_color=false") settings::default_settings().output_color(false);
    else if (arg == "--gtest_color=no") settings::default_settings().output_color(false);
    else if (arg == "--brief=true") settings::default_settings().brief(true);
    else if (arg == "--gtest_brief=1") settings::default_settings().brief(true);
    else if (arg == "--brief=false") settings::default_settings().brief(false);
    else if (arg == "--gtest_brief=0") settings::default_settings().brief(false);
    else if (arg == "--show_duration=true") settings::default_settings().show_duration(true);
    else if (arg == "--gtest_print_time=1") settings::default_settings().show_duration(true);
    else if (arg == "--show_duration=false") settings::default_settings().show_duration(false);
    else if (arg == "--gtest_print_time=0") settings::default_settings().show_duration(false);
    else if (arg.find("--output=json") == 0) {
      settings::default_settings().output_json(true);
      if (arg[13] == ':') settings::default_settings().output_json_path(arg.substring(14));
    } else if (arg.find("--gtest_output=json") == 0) {
      settings::default_settings().output_json(true);
      if (arg[19] == ':') settings::default_settings().output_json_path(arg.substring(20));
    } else if (arg.find("--output=xml") == 0) {
      settings::default_settings().output_xml(true);
      if (arg[12] == ':') settings::default_settings().output_xml_path(arg.substring(13));
    } else if (arg.find("--gtest_output=xml") == 0) {
      settings::default_settings().output_xml(true);
      if (arg[18] == ':') settings::default_settings().output_xml_path(arg.substring(19));
    }
    // Assertion Behavior
    else if (arg == "--break_on_failure")
      settings::default_settings().break_on_failure(true);
    else if (arg == "--throw_on_failure")
      settings::default_settings().throw_on_failure(true);
  }
  settings::default_settings().gtest_compatibility(gtest_compatibility);
  return false;
}

void unit_test::add(const registered_test_class& test_class) {
  test_classes().push_back(test_class);
}

vector<registered_test_class>& unit_test::test_classes() {
  static auto test_classes = vector<registered_test_class> {};
  return test_classes;
}

ustring unit_test::get_filename(const ustring& path) {
  auto filename = path;
  const auto last_slash_idx = filename.find_last_of("\\/");
  if (ustring::npos != last_slash_idx)
    filename = filename.remove(0, last_slash_idx + 1);
    
  const auto period_idx = filename.rfind('.');
  if (ustring::npos != period_idx)
    filename = filename.remove(period_idx);
  return filename;
}

ustring unit_test::cdata_message_to_xml_string(const test& test) {
  auto ss = stringstream {};
  if (settings::default_settings().gtest_compatibility()) {
    if (test.stack_frame() != stack_frame::empty())
      ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << endl;
    ss << "Value of: " << test.actual() << endl;
    ss << "  Actual: " << test.actual() << endl;
    ss << "Expected: " << test.expect();
  } else {
    if (test.stack_frame() != stack_frame::empty())
      ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << endl;
    ss << "Expected: " << test.expect() << endl;
    ss << "But was : " << test.actual();
  }
  return ss.str();
}

ustring unit_test::escape_path_to_json_string(const ustring& path) {
  return ustring::join(ustring::format("\\{}", io::path::directory_separator_char()), ustring(path).split({io::path::directory_separator_char()}));
}

ustring unit_test::escape_to_json_string(const ustring& str) {
  return ustring(str).replace("\"", "\\\"");
}

ustring unit_test::escape_to_xml_string(const ustring& str) {
  return ustring(str).replace("\"", "&quot;").replace("&", "&amp;").replace("'", "&apos;").replace("<", "&lt;").replace(">", "&gt;");
}

ustring unit_test::message_to_json_string(const test& test) {
  auto ss = stringstream {};
  if (settings::default_settings().gtest_compatibility())
    ss << "Value of: " << escape_to_json_string(test.actual()) << "\\n" << "  Actual: " << escape_to_json_string(test.actual()) << "\\n" << "Expected: " << escape_to_json_string(test.expect());
  else
    ss <<  "Expected: " << escape_to_json_string(test.expect()) << "\\n" << "But was: " << escape_to_json_string(test.actual());
  return ss.str();
}

ustring unit_test::message_to_xml_string(const test& test) {
  auto ss = stringstream {};
  if (settings::default_settings().gtest_compatibility()) {
    if (test.stack_frame() != stack_frame::empty())
      ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << "&#x0A;";
    ss << "Value of: " << escape_to_xml_string(test.actual()) << "&#x0A;";
    ss << "  Actual: " << escape_to_xml_string(test.actual()) << "&#x0A;";
    ss << "Expected: " <<  escape_to_xml_string(test.expect());
  } else {
    if (test.stack_frame() != stack_frame::empty())
      ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << "&#x0A;";
    ss << "Expected: " << escape_to_xml_string(test.expect()) << "&#x0A;";
    ss << "But was : " << escape_to_xml_string(test.actual());
  }
  return ss.str();
}

ustring unit_test::name_to_string(const ustring& name) {
  return (settings::default_settings().gtest_compatibility() ? "AllTests" : name_);
}

ustring unit_test::status_to_string(const test& test) {
  auto ss = stringstream {};
  if (test.not_started() || test.ignored()) ss << "notrun";
  else ss << "run";
  return ss.str();
}

ustring unit_test::to_string(const time_span& ts) {
  auto ss = stringstream {};
  auto ms = static_cast<int32>(ts.total_nanoseconds());
  if (ms == 0) ss << 0;
  else ss << ms / 1000 << "." << setfill('0') << setw(3) << ms % 1000;
  return ss.str();
}

void unit_test::unit_test_cleanup() {
}

void unit_test::unit_test_initialize() {
}

void unit_test::write_list_tests_json() {
  auto file = fstream {settings::default_settings().output_json_path(), ios::out | ios::trunc};
  file << "{" << endl;
  file << "  \"tests\": " << test_count() << "," << endl;
  file << "  \"name\": \"" << name_to_string(name_) << "\"," << endl;
  file << "  \"testsuites\": [" << endl;
  for (auto& test_class : test_classes()) {
    file << "    {" << endl;
    file << "      \"name\": \"" << escape_to_xml_string(test_class.test()->name()) << "\"," << endl;
    file << "      \"tests\": " << test_class.test()->test_count() << "," << endl;
    file << "      \"testsuite\": [" << endl;
    for (auto& test : test_class.test()->tests()) {
      file << "        {" << endl;
      file << "          \"name\": \"" << test.name() << "\"," << endl;
      file << "          \"file\": \"" << escape_path_to_json_string(test.stack_frame().get_file_name()) << "\"," << endl;
      file << "          \"line\": " << test.stack_frame().get_file_line_number() << "," << endl;
      file << "        }," << endl;
    }
    file << "      ]" << endl;
    file << "    }," << endl;
  }
  file << "  ]" << endl;
  file << "}" << endl;
  file.close();
}

void unit_test::write_list_tests_xml() {
  auto file = fstream {settings::default_settings().output_xml_path(), ios::out | ios::trunc};
  file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
  file << "<testsuites tests=\"" << test_count() << "\" name=\"" << name_to_string(name_) << "\">" << endl;
  for (auto& test_class : test_classes()) {
    file << "  <testsuite name=\"" << escape_to_xml_string(test_class.test()->name()) << "\" tests=\"" << test_class.test()->test_count() << "\">" << endl;
    for (auto& test : test_class.test()->tests())
      file << "    <testcase name=\"" << test.name() << "\" file=\"" << test.stack_frame().get_file_name() << "\" line=\"" << test.stack_frame().get_file_line_number() << "\" />" << endl;
    file << "  </testsuite>" << endl;
  }
  file << "</testsuites>" << endl;
  file.close();
}

void unit_test::write_tests_json() {
  auto file = fstream {settings::default_settings().output_json_path(), ios::out | ios::trunc};
  file << "{" << endl;
  file << "  \"tests\": " << test_count() << "," << endl;
  file << "  \"failures\": " << failed_test_count() << "," << endl;
  file << "  \"disabled\": " << ignored_test_count() << "," << endl;
  file << "  \"errors\": " << 0  << "," << endl;
  file << "  \"timestamp\": \"" << ustring::format("{0:L}-{0:k}-{0:i}T{0:t}Z", settings::default_settings().start_time()) << "\"," << endl;
  file << "  \"time\": \"" << to_string(elapsed_time()) << "s\"," << endl;
  file << "  \"name\": \"" << name_to_string(name_) << "\"," << endl;
  file << "  \"testsuites\": [" << endl;
  for (auto& test_class : test_classes()) {
    file << "    {" << endl;
    file << "      \"name\": \"" << escape_to_xml_string(test_class.test()->name()) << "\"," << endl;
    file << "      \"tests\": " << test_class.test()->test_count() << "," << endl;
    file << "      \"failures\": " << test_class.test()->failed_test_count() << "," << endl;
    file << "      \"disabled\": " << test_class.test()->ignored_test_count() << "," << endl;
    file << "      \"errors\": " << 0 << "," << endl;
    file << "      \"timestamp\": \"" << ustring::format("{0:L}-{0:k}-{0:i}T{0:t}Z", test_class.test()->start_time()) << "\"," << endl;
    file << "      \"time\": \"" << to_string(test_class.test()->elapsed_time()) << "s\"," << endl;
    file << "      \"testsuite\": [" << endl;
    for (auto& test : test_class.test()->tests()) {
      file << "        {" << endl;
      file << "          \"name\": \"" << test.name() << "\"," << endl;
      file << "          \"file\": \"" << escape_path_to_json_string(test.stack_frame().get_file_name()) << "\"," << endl;
      file << "          \"line\": " << test.stack_frame().get_file_line_number() << "," << endl;
      file << "          \"status\": \"" << ustring(status_to_string(test)).to_upper() << "\"," << endl;
      file << "          \"result\": \"" << (test.ignored() ? "SUPPRESSED" : "COMPLETED") << "\"," << endl;
      file << "          \"timestamp\": \"" << ustring::format("{0:L}-{0:k}-{0:i}T{0:t}Z", test.start_time()) << "\"," << endl;
      file << "          \"time\": \"" << to_string(test.elapsed_time()) << "s\"," << endl;
      file << "          \"classname\": \"" << escape_to_xml_string(test_class.test()->name()) << "\"," << endl;
      if (test.failed()) {
        file << "          \"failures\": [" << endl;
        file << "            {" << endl;
        file << "              \"failure\": \"" << escape_path_to_json_string(test.stack_frame().get_file_name()) << ":" << test.stack_frame().get_file_line_number() << "\\n" << message_to_json_string(test) << "\"" << endl;
        file << "              \"type\": \"\"" << endl;
        file << "            }" << endl;
        file << "          ]" << endl;
      }
      file << "        }," << endl;
    }
    file << "      ]" << endl;
    file << "    }," << endl;
  }
  file << "  ]" << endl;
  file << "}" << endl;
  file.close();
}

void unit_test::write_tests_xml() {
  auto file = fstream {settings::default_settings().output_xml_path(), ios::out | ios::trunc};
  file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
  file << "<testsuites tests=\"" << test_count() << "\" failures=\"" << failed_test_count() << "\" disabled=\"" << ignored_test_count() << "\" errors=\"" << 0 << "\" time=\"" << to_string(elapsed_time()) << "\" timestamp=\"" << settings::default_settings().start_time().to_string("S") << "\" name=\"" << name_to_string(name_) << "\">" << endl;
  for (auto& test_class : test_classes()) {
    file << "  <testsuite name=\"" << escape_to_xml_string(test_class.test()->name()) << "\" tests=\"" << test_class.test()->test_count() << "\" failures=\"" << test_class.test()->failed_test_count() << "\" disabled=\"" << test_class.test()->ignored_test_count() << "\" skipped=\"" << 0 << "\" errors=\"" << 0 << "\" time=\"" << to_string(test_class.test()->elapsed_time()) << "\" timestamp=\"" << test_class.test()->start_time().to_string("S") << "\">" << endl;
    for (auto& test : test_class.test()->tests()) {
      file << "    <testcase name=\"" << test.name() << "\" file=\"" << test.stack_frame().get_file_name() << "\" line=\"" << test.stack_frame().get_file_line_number() << "\" status=\"" << status_to_string(test) << "\" result=\"" << (test.ignored() ? "suppressed" : "completed") << "\" time=\"" << to_string(test.elapsed_time()) << "\" timestamp=\"" << test.start_time().to_string("S") << "\" classname=\"" << escape_to_xml_string(test_class.test()->name()) << "\"";
      if (!test.failed())
        file << " />" << endl;
      else {
        file << ">" << endl;
        file << "      <failure message=\"" << message_to_xml_string(test) << "\" type=\"" << "\">" << "<![CDATA[" << cdata_message_to_xml_string(test) << endl << "]]></failure>" << endl;
        file << "    </testcase>" << endl;
      }
    }
    file << "  </testsuite>" << endl;
  }
  file << "</testsuites>" << endl;
  file.close();
}
