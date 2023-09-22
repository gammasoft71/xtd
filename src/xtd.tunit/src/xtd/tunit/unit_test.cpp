#include "../../../include/xtd/tunit/unit_test"

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
  return xtd::tunit::settings::default_settings().repeat_test();
}

bool unit_test::repeat_tests() const noexcept {
  return xtd::tunit::settings::default_settings().repeat_test() != 1;
}

size_t unit_test::test_cases_count() const noexcept {
  size_t count = 0;
  for (auto test_class : test_classes())
    if (test_class.test()->test_count())
      count ++;
  return count;
}

size_t unit_test::test_count() const noexcept {
  size_t count = 0;
  for (auto test_class : test_classes())
    count += test_class.test()->test_count();
  return count;
}

size_t unit_test::aborted_test_count() const noexcept {
  size_t count = 0;
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.aborted()) count++;
  return count;
}

vector<ustring> unit_test::aborted_test_names() const noexcept {
  vector<ustring> names;
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.aborted()) names.push_back(test_class.test()->name() + "." + test.name());
  return names;
}

std::chrono::milliseconds unit_test::elapsed_time() const noexcept {
  using namespace std::chrono_literals;
  if (start_time_point_.ticks() == 0 && end_time_point_.ticks() == 0) return 0ms;
  if (end_time_point_.ticks() == 0) return std::chrono::duration_cast<std::chrono::milliseconds>((xtd::date_time::now() - start_time_point_).ticks_duration());
  return std::chrono::duration_cast<std::chrono::milliseconds>((end_time_point_ - start_time_point_).ticks_duration());
}

size_t unit_test::ignored_test_count() const noexcept {
  size_t count = 0;
  for (auto test_class : test_classes())
    count += test_class.test()->ignored_test_count();
  return count;
}

vector<ustring> unit_test::ignored_test_names() const noexcept {
  vector<ustring> names;
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.ignored()) names.push_back(test_class.test()->name() + "." + test.name());
  return names;
}

size_t unit_test::failed_test_count() const noexcept {
  size_t count = 0;
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.failed()) count++;
  return count;
}

vector<ustring> unit_test::failed_test_names() const noexcept {
  vector<ustring> names;
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.failed()) names.push_back(test_class.test()->name() + "." + test.name());
  return names;
}

size_t unit_test::succeed_test_count() const noexcept {
  size_t count = 0;
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.succeed()) count++;
  return count;
}

vector<ustring> unit_test::succeed_test_names() const noexcept {
  vector<ustring> names;
  for (auto& test_class : test_classes())
    for (auto& test : test_class.test()->tests())
      if (settings::default_settings().is_match_test_name(test_class.test()->name(), test.name()) && test.succeed()) names.push_back(test_class.test()->name() + "." + test.name());
  return names;
}

int32 unit_test::run() {
  if (parse_arguments(arguments))
    return xtd::tunit::settings::default_settings().exit_status();
    
  if (xtd::tunit::settings::default_settings().count_tests()) {
    auto count = 0;
    for (auto test_class : test_classes())
      for (auto test : test_class.test()->tests())
        count++;
        
    return count_tests(count);
  }
  
  if (xtd::tunit::settings::default_settings().list_tests()) {
    vector<ustring> tests;
    for (auto test_class : test_classes())
      for (auto test : test_class.test()->tests())
        tests.push_back(test_class.test()->name() + '.' + test.name());
        
    if (xtd::tunit::settings::default_settings().output_json()) write_list_tests_json();
    if (xtd::tunit::settings::default_settings().output_xml()) write_list_tests_xml();
    
    return list_tests(tests);
  }
  
  xtd::system_exception::enable_stack_trace(settings::default_settings().enable_stack_trace());
  
  auto random = xtd::tunit::settings::default_settings().random_seed() ? xtd::random(xtd::tunit::settings::default_settings().random_seed()) : xtd::random();
  
  for (repeat_iteration_ = 1; repeat_iteration_ <= xtd::tunit::settings::default_settings().repeat_test() || xtd::tunit::settings::default_settings().repeat_test() < 0; ++repeat_iteration_) {
    if (xtd::tunit::settings::default_settings().shuffle_test())
      std::shuffle(test_classes().begin(), test_classes().end(), random.generator());
      
    try {
      if (!settings::default_settings().brief()) event_listener_->on_unit_test_start(xtd::tunit::tunit_event_args(*this));
      
      if (!settings::default_settings().brief()) event_listener_->on_unit_test_initialize_start(xtd::tunit::tunit_event_args(*this));
      unit_test_initialize();
      if (!settings::default_settings().brief()) event_listener_->on_unit_test_initialize_end(xtd::tunit::tunit_event_args(*this));
      
      start_time_point_ = xtd::date_time::now();
      for (auto& test_class : test_classes())
        if (test_class.test()->test_count())
          test_class.test()->run(*this);
      end_time_point_ = xtd::date_time::now();
      
      if (!settings::default_settings().brief()) event_listener_->on_unit_test_cleanup_start(xtd::tunit::tunit_event_args(*this));
      unit_test_cleanup();
      if (!settings::default_settings().brief()) event_listener_->on_unit_test_cleanup_end(xtd::tunit::tunit_event_args(*this));
      
      event_listener_->on_unit_test_end(xtd::tunit::tunit_event_args(*this));
    } catch (const std::exception&) {
      xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
      // do error...
    } catch (...) {
      xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
      // do error...
    }
  }
  
  xtd::tunit::settings::default_settings().end_time(xtd::date_time::now());
  
  if (xtd::tunit::settings::default_settings().output_json()) write_tests_json();
  if (xtd::tunit::settings::default_settings().output_xml()) write_tests_xml();
  
  return xtd::tunit::settings::default_settings().exit_status();
}

int32 unit_test::count_tests(int32 count) {
  return xtd::tunit::settings::default_settings().exit_status();
}

int32 unit_test::list_tests(const vector<ustring>& tests) {
  return xtd::tunit::settings::default_settings().exit_status();
}

bool unit_test::parse_arguments(const vector<ustring>& args) {
  bool gtest_compatibility = xtd::tunit::settings::default_settings().gtest_compatibility();
  for (auto arg : args) {
    if (arg == "--gtest_compatibility" || arg.find("--gtest") == 0) gtest_compatibility = true;
    // Test selection :
    if (arg == "--count_tests") xtd::tunit::settings::default_settings().count_tests(true);
    else if (arg == "--list_tests") xtd::tunit::settings::default_settings().list_tests(true);
    else if (arg == "--gtest_list_tests") xtd::tunit::settings::default_settings().list_tests(true);
    else if (arg.find("--filter_tests=") == 0) xtd::tunit::settings::default_settings().filter_tests(arg.substring(15).split({':'}));
    else if (arg.find("--gtest_filter=") == 0) xtd::tunit::settings::default_settings().filter_tests(arg.substring(15).split({':'}));
    else if (arg == "--also_run_ignored_tests") xtd::tunit::settings::default_settings().also_run_ignored_tests(true);
    else if (arg == "--gtest_also_run_disabled_tests") xtd::tunit::settings::default_settings().also_run_ignored_tests(true);
    // Test execution:
    else if (arg.find("--repeat_tests=") == 0) xtd::tunit::settings::default_settings().repeat_tests(convert::to_int32(arg.substring(15)));
    else if (arg.find("--gtest_repeat=") == 0) xtd::tunit::settings::default_settings().repeat_tests(convert::to_int32(arg.substring(15)));
    else if (arg == "--shuffle_tests") xtd::tunit::settings::default_settings().shuffle_test(true);
    else if (arg == "--gtest_shuffle") xtd::tunit::settings::default_settings().shuffle_test(true);
    else if (arg.find("--random_seed=") == 0) xtd::tunit::settings::default_settings().random_seed(convert::to_uint32(arg.substring(14)));
    else if (arg.find("--gtest_random_seed=") == 0) xtd::tunit::settings::default_settings().random_seed(convert::to_uint32(arg.substring(20)));
    else if (arg == "--enable_stack_trace=true") xtd::tunit::settings::default_settings().enable_stack_trace(true);
    else if (arg == "--enable_stack_trace=false") xtd::tunit::settings::default_settings().enable_stack_trace(false);
    // Test output
    else if (arg == "--output_color=true") xtd::tunit::settings::default_settings().output_color(true);
    else if (arg == "--gtest_color=auto" || arg == "--gtest_color=yes") xtd::tunit::settings::default_settings().output_color(true);
    else if (arg == "--output_color=false") xtd::tunit::settings::default_settings().output_color(false);
    else if (arg == "--gtest_color=no") xtd::tunit::settings::default_settings().output_color(false);
    else if (arg == "--brief=true") xtd::tunit::settings::default_settings().brief(true);
    else if (arg == "--gtest_brief=1") xtd::tunit::settings::default_settings().brief(true);
    else if (arg == "--brief=false") xtd::tunit::settings::default_settings().brief(false);
    else if (arg == "--gtest_brief=0") xtd::tunit::settings::default_settings().brief(false);
    else if (arg == "--show_duration=true") xtd::tunit::settings::default_settings().show_duration(true);
    else if (arg == "--gtest_print_time=1") xtd::tunit::settings::default_settings().show_duration(true);
    else if (arg == "--show_duration=false") xtd::tunit::settings::default_settings().show_duration(false);
    else if (arg == "--gtest_print_time=0") xtd::tunit::settings::default_settings().show_duration(false);
    else if (arg.find("--output=json") == 0) {
      xtd::tunit::settings::default_settings().output_json(true);
      if (arg[13] == ':') xtd::tunit::settings::default_settings().output_json_path(arg.substring(14));
    } else if (arg.find("--gtest_output=json") == 0) {
      xtd::tunit::settings::default_settings().output_json(true);
      if (arg[19] == ':') xtd::tunit::settings::default_settings().output_json_path(arg.substring(20));
    } else if (arg.find("--output=xml") == 0) {
      xtd::tunit::settings::default_settings().output_xml(true);
      if (arg[12] == ':') xtd::tunit::settings::default_settings().output_xml_path(arg.substring(13));
    } else if (arg.find("--gtest_output=xml") == 0) {
      xtd::tunit::settings::default_settings().output_xml(true);
      if (arg[18] == ':') xtd::tunit::settings::default_settings().output_xml_path(arg.substring(19));
    }
    // Assertion Behavior
    else if (arg == "--break_on_failure")
      settings::default_settings().break_on_failure(true);
    else if (arg == "--throw_on_failure")
      settings::default_settings().throw_on_failure(true);
  }
  xtd::tunit::settings::default_settings().gtest_compatibility(gtest_compatibility);
  return false;
}

void unit_test::add(const xtd::tunit::registered_test_class& test_class) {
  test_classes().push_back(test_class);
}

vector<xtd::tunit::registered_test_class>& unit_test::test_classes() {
  static vector<xtd::tunit::registered_test_class> test_classes;
  return test_classes;
}

ustring unit_test::get_filename(const ustring& path) {
  ustring filename = path;
  const size_t last_slash_idx = filename.find_last_of("\\/");
  if (ustring::npos != last_slash_idx)
    filename = filename.remove(0, last_slash_idx + 1);
    
  const size_t period_idx = filename.rfind('.');
  if (ustring::npos != period_idx)
    filename = filename.remove(period_idx);
  return filename;
}

ustring unit_test::cdata_message_to_xml_string(const xtd::tunit::test& test) {
  stringstream ss;
  if (settings::default_settings().gtest_compatibility()) {
    if (test.stack_frame() != xtd::diagnostics::stack_frame::empty())
      ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << std::endl;
    ss << "Value of: " << test.actual() << std::endl;
    ss << "  Actual: " << test.actual() << std::endl;
    ss << "Expected: " << test.expect();
  } else {
    if (test.stack_frame() != xtd::diagnostics::stack_frame::empty())
      ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << std::endl;
    ss << "Expected: " << test.expect() << std::endl;
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

ustring unit_test::message_to_json_string(const xtd::tunit::test& test) {
  stringstream ss;
  if (settings::default_settings().gtest_compatibility())
    ss << "Value of: " << escape_to_json_string(test.actual()) << "\\n" << "  Actual: " << escape_to_json_string(test.actual()) << "\\n" << "Expected: " << escape_to_json_string(test.expect());
  else
    ss <<  "Expected: " << escape_to_json_string(test.expect()) << "\\n" << "But was: " << escape_to_json_string(test.actual());
  return ss.str();
}

ustring unit_test::message_to_xml_string(const xtd::tunit::test& test) {
  stringstream ss;
  if (settings::default_settings().gtest_compatibility()) {
    if (test.stack_frame() != xtd::diagnostics::stack_frame::empty())
      ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << "&#x0A;";
    ss << "Value of: " << escape_to_xml_string(test.actual()) << "&#x0A;";
    ss << "  Actual: " << escape_to_xml_string(test.actual()) << "&#x0A;";
    ss << "Expected: " <<  escape_to_xml_string(test.expect());
  } else {
    if (test.stack_frame() != xtd::diagnostics::stack_frame::empty())
      ss << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << "&#x0A;";
    ss << "Expected: " << escape_to_xml_string(test.expect()) << "&#x0A;";
    ss << "But was : " << escape_to_xml_string(test.actual());
  }
  return ss.str();
}

ustring unit_test::name_to_string(const ustring& name) {
  return (settings::default_settings().gtest_compatibility() ? "AllTests" : name_);
}

ustring unit_test::status_to_string(const xtd::tunit::test& test) {
  stringstream ss;
  if (test.not_started() || test.ignored()) ss << "notrun";
  else ss << "run";
  return ss.str();
}

ustring unit_test::to_string(const std::chrono::milliseconds& ms) {
  stringstream ss;
  if (ms.count() == 0)
    ss << 0;
  else
    ss << ms.count() / 1000 << "." << std::setfill('0') << std::setw(3) << ms.count() % 1000;
  return ss.str();
}

ustring unit_test::to_string(const std::chrono::time_point<std::chrono::system_clock>& time) {
  std::time_t time_t = std::chrono::system_clock::to_time_t(time);
  std::tm tm = *std::localtime(&time_t);
  stringstream ss;
  ss << tm.tm_year + 1900 << "-" << std::setfill('0') << std::setw(2) << tm.tm_mon << "-" << std::setfill('0') << std::setw(2) << tm.tm_mday;
  ss << "T" << std::setfill('0') << std::setw(2) << tm.tm_hour << ":" << std::setfill('0') << std::setw(2) << tm.tm_min << ":" << std::setfill('0') << std::setw(2) << tm.tm_sec;
  return ss.str();
}

void unit_test::unit_test_cleanup() {
}

void unit_test::unit_test_initialize() {
}

void unit_test::write_list_tests_json() {
  std::fstream file(xtd::tunit::settings::default_settings().output_json_path(), std::ios::out | std::ios::trunc);
  file << "{" << std::endl;
  file << "  \"tests\": " << test_count() << "," << std::endl;
  file << "  \"name\": \"" << name_to_string(name_) << "\"," << std::endl;
  file << "  \"testsuites\": [" << std::endl;
  for (auto& test_class : test_classes()) {
    file << "    {" << std::endl;
    file << "      \"name\": \"" << escape_to_xml_string(test_class.test()->name()) << "\"," << std::endl;
    file << "      \"tests\": " << test_class.test()->test_count() << "," << std::endl;
    file << "      \"testsuite\": [" << std::endl;
    for (auto& test : test_class.test()->tests()) {
      file << "        {" << std::endl;
      file << "          \"name\": \"" << test.name() << "\"," << std::endl;
      file << "          \"file\": \"" << escape_path_to_json_string(test.stack_frame().get_file_name()) << "\"," << std::endl;
      file << "          \"line\": " << test.stack_frame().get_file_line_number() << "," << std::endl;
      file << "        }," << std::endl;
    }
    file << "      ]" << std::endl;
    file << "    }," << std::endl;
  }
  file << "  ]" << std::endl;
  file << "}" << std::endl;
  file.close();
}

void unit_test::write_list_tests_xml() {
  std::fstream file(xtd::tunit::settings::default_settings().output_xml_path(), std::ios::out | std::ios::trunc);
  file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
  file << "<testsuites tests=\"" << test_count() << "\" name=\"" << name_to_string(name_) << "\">" << std::endl;
  for (auto& test_class : test_classes()) {
    file << "  <testsuite name=\"" << escape_to_xml_string(test_class.test()->name()) << "\" tests=\"" << test_class.test()->test_count() << "\">" << std::endl;
    for (auto& test : test_class.test()->tests())
      file << "    <testcase name=\"" << test.name() << "\" file=\"" << test.stack_frame().get_file_name() << "\" line=\"" << test.stack_frame().get_file_line_number() << "\" />" << std::endl;
    file << "  </testsuite>" << std::endl;
  }
  file << "</testsuites>" << std::endl;
  file.close();
}

void unit_test::write_tests_json() {
  std::fstream file(xtd::tunit::settings::default_settings().output_json_path(), std::ios::out | std::ios::trunc);
  file << "{" << std::endl;
  file << "  \"tests\": " << test_count() << "," << std::endl;
  file << "  \"failures\": " << failed_test_count() << "," << std::endl;
  file << "  \"disabled\": " << ignored_test_count() << "," << std::endl;
  file << "  \"errors\": " << 0  << "," << std::endl;
  file << "  \"timestamp\": \"" << ustring::format("{0:L}-{0:k}-{0:i}T{0:t}Z", xtd::tunit::settings::default_settings().start_time()) << "\"," << std::endl;
  file << "  \"time\": \"" << to_string(elapsed_time()) << "s\"," << std::endl;
  file << "  \"name\": \"" << name_to_string(name_) << "\"," << std::endl;
  file << "  \"testsuites\": [" << std::endl;
  for (auto& test_class : test_classes()) {
    file << "    {" << std::endl;
    file << "      \"name\": \"" << escape_to_xml_string(test_class.test()->name()) << "\"," << std::endl;
    file << "      \"tests\": " << test_class.test()->test_count() << "," << std::endl;
    file << "      \"failures\": " << test_class.test()->failed_test_count() << "," << std::endl;
    file << "      \"disabled\": " << test_class.test()->ignored_test_count() << "," << std::endl;
    file << "      \"errors\": " << 0 << "," << std::endl;
    file << "      \"timestamp\": \"" << ustring::format("{0:L}-{0:k}-{0:i}T{0:t}Z", test_class.test()->start_time()) << "\"," << std::endl;
    file << "      \"time\": \"" << to_string(test_class.test()->elapsed_time()) << "s\"," << std::endl;
    file << "      \"testsuite\": [" << std::endl;
    for (auto& test : test_class.test()->tests()) {
      file << "        {" << std::endl;
      file << "          \"name\": \"" << test.name() << "\"," << std::endl;
      file << "          \"file\": \"" << escape_path_to_json_string(test.stack_frame().get_file_name()) << "\"," << std::endl;
      file << "          \"line\": " << test.stack_frame().get_file_line_number() << "," << std::endl;
      file << "          \"status\": \"" << ustring(status_to_string(test)).to_upper() << "\"," << std::endl;
      file << "          \"result\": \"" << (test.ignored() ? "SUPPRESSED" : "COMPLETED") << "\"," << std::endl;
      file << "          \"timestamp\": \"" << ustring::format("{0:L}-{0:k}-{0:i}T{0:t}Z", test.start_time()) << "\"," << std::endl;
      file << "          \"time\": \"" << to_string(test.elapsed_time()) << "s\"," << std::endl;
      file << "          \"classname\": \"" << escape_to_xml_string(test_class.test()->name()) << "\"," << std::endl;
      if (test.failed()) {
        file << "          \"failures\": [" << std::endl;
        file << "            {" << std::endl;
        file << "              \"failure\": \"" << test.stack_frame().get_file_name() << ":" << test.stack_frame().get_file_line_number() << "\\n" << message_to_json_string(test) << "\"" << std::endl;
        file << "              \"type\": \"\"" << std::endl;
        file << "            }" << std::endl;
        file << "          ]" << std::endl;
      }
      file << "        }," << std::endl;
    }
    file << "      ]" << std::endl;
    file << "    }," << std::endl;
  }
  file << "  ]" << std::endl;
  file << "}" << std::endl;
  file.close();
}

void unit_test::write_tests_xml() {
  std::fstream file(xtd::tunit::settings::default_settings().output_xml_path(), std::ios::out | std::ios::trunc);
  file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
  file << "<testsuites tests=\"" << test_count() << "\" failures=\"" << failed_test_count() << "\" disabled=\"" << ignored_test_count() << "\" errors=\"" << 0 << "\" time=\"" << to_string(elapsed_time()) << "\" timestamp=\"" << xtd::tunit::settings::default_settings().start_time().to_string("S") << "\" name=\"" << name_to_string(name_) << "\">" << std::endl;
  for (auto& test_class : test_classes()) {
    file << "  <testsuite name=\"" << escape_to_xml_string(test_class.test()->name()) << "\" tests=\"" << test_class.test()->test_count() << "\" failures=\"" << test_class.test()->failed_test_count() << "\" disabled=\"" << test_class.test()->ignored_test_count() << "\" skipped=\"" << 0 << "\" errors=\"" << 0 << "\" time=\"" << to_string(test_class.test()->elapsed_time()) << "\" timestamp=\"" << test_class.test()->start_time().to_string("S") << "\">" << std::endl;
    for (auto& test : test_class.test()->tests()) {
      file << "    <testcase name=\"" << test.name() << "\" file=\"" << test.stack_frame().get_file_name() << "\" line=\"" << test.stack_frame().get_file_line_number() << "\" status=\"" << status_to_string(test) << "\" result=\"" << (test.ignored() ? "suppressed" : "completed") << "\" time=\"" << to_string(test.elapsed_time()) << "\" timestamp=\"" << test.start_time().to_string("S") << "\" classname=\"" << escape_to_xml_string(test_class.test()->name()) << "\"";
      if (!test.failed())
        file << " />" << std::endl;
      else {
        file << ">" << std::endl;
        file << "      <failure message=\"" << message_to_xml_string(test) << "\" type=\"" << "\">" << "<![CDATA[" << cdata_message_to_xml_string(test) << "]]></failure>" << std::endl;
        file << "    </testcase>" << std::endl;
      }
    }
    file << "  </testsuite>" << std::endl;
  }
  file << "</testsuites>" << std::endl;
  file.close();
}
