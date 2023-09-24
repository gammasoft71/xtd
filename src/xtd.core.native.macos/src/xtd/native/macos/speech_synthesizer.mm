#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/speech_synthesizer>
#include <xtd/native/file_permission>
#include <xtd/native/file_system>
#include <xtd/native/process>
#include <xtd/native/process_window_style>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <unistd.h>

using namespace std;
using namespace xtd::native;

namespace {
  struct speech_synthesizer_data {
    string say_cmd_file_name;
    intmax_t process_handle = 0;
  };
  
  static string get_temp_path() {
    auto tmp_path = getenv("TMPDIR");
    return tmp_path ? tmp_path : "/tmp/";
  }
  
  static string get_unique_speak_cmd_file_name() {
    static auto cpt = 0;
    auto ss = stringstream {};
    ss << get_temp_path() << "/__xtd_speech_synthesizer_speak_process_" << ++cpt << "__.cmd";
    return  ss.str();
  }
}

intmax_t speech_synthesizer::create() {
  speech_synthesizer_data* data = new speech_synthesizer_data {get_unique_speak_cmd_file_name(), 0};
  auto cmd_file = ofstream {};
  cmd_file.open(data->say_cmd_file_name);
  cmd_file << "say \"$*\"\n";
  cmd_file.close();
  native::file_system::set_permissions(data->say_cmd_file_name, FILE_PERMISSIONS_OWNER_ALL);
  return reinterpret_cast<intmax_t>(data);
}

void speech_synthesizer::destroy(intmax_t handle) {
  unlink(reinterpret_cast<speech_synthesizer_data*>(handle)->say_cmd_file_name.c_str());
  delete reinterpret_cast<speech_synthesizer_data*>(handle);
}

void speech_synthesizer::pause(intmax_t handle) {

}

void speech_synthesizer::resume(intmax_t handle) {

}

void speech_synthesizer::speak(intmax_t handle, const string& text_to_speak) {
  speak_async(handle, text_to_speak, [] {});
  auto exit_code = 0;
  native::process::wait(reinterpret_cast<speech_synthesizer_data*>(handle)->process_handle, exit_code);
}

void speech_synthesizer::speak_async(intmax_t handle, const string& text_to_speak, std::function<void()> on_speak_completed) {
  reinterpret_cast<speech_synthesizer_data*>(handle)->process_handle = native::process::shell_execute("", reinterpret_cast<speech_synthesizer_data*>(handle)->say_cmd_file_name, text_to_speak, "", PROCESS_WINDOW_STYLE_HIDDEN);
  auto wait_process_thread = thread {[on_speak_completed, handle] {
    int_least32_t exit_code = 0;
    native::process::wait(reinterpret_cast<speech_synthesizer_data*>(handle)->process_handle, exit_code);
    on_speak_completed();
  }};
  wait_process_thread.detach();
}

void speech_synthesizer::stop(intmax_t handle) {

}
