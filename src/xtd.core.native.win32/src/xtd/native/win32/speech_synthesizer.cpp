#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/speech_synthesizer.h>
#include <xtd/native/file_permission.h>
#include <xtd/native/file_system.h>
#include <xtd/native/process.h>
#include <xtd/native/process_window_style.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <Windows.h>

using namespace std;
using namespace xtd::native;

namespace {
  struct speech_synthesizer_data {
    string say_cmd_file_name;
    intptr_t process_handle = 0;
  };
  
  static string get_temp_path() {
    if (getenv("TMP") != nullptr)  return getenv("TMP");
    if (getenv("TEMP") != nullptr) return getenv("TEMP");
    if (getenv("USERPROFILE") != nullptr) return getenv("USERPROFILE");
    return getenv("WINDIR");
  }
  
  static string get_unique_speak_cmd_file_name() {
    static int_least32_t cpt = 0;
    stringstream ss;
    ss << get_temp_path() << "\\__xtd_speech_synthesizer_speak_process_" << ++cpt << "__.cmd";
    return  ss.str();
  }
}

intptr_t speech_synthesizer::create() {
  speech_synthesizer_data* data = new speech_synthesizer_data {get_unique_speak_cmd_file_name(), 0};
  ofstream cmd_file;
  cmd_file.open(data->say_cmd_file_name);
  cmd_file << "@echo Set Speaker=CreateObject(\"sapi.spvoice\") > %TEMP%\\say_.vbs\n@echo Speaker.Speak \"%*\" >> %TEMP%\\say_.vbs\n@%TEMP%\\say_.vbs\n";
  cmd_file.close();
  native::file_system::set_permissions(data->say_cmd_file_name, FILE_PERMISSIONS_OWNER_ALL);
  return reinterpret_cast<intptr_t>(data);
}

void speech_synthesizer::destroy(intptr_t handle) {
  ::remove(reinterpret_cast<speech_synthesizer_data*>(handle)->say_cmd_file_name.c_str());
  delete reinterpret_cast<speech_synthesizer_data*>(handle);
}

void speech_synthesizer::pause(intptr_t handle) {

}

void speech_synthesizer::resume(intptr_t handle) {

}

void speech_synthesizer::speak(intptr_t handle, const string& text_to_speak) {
  speak_async(handle, text_to_speak, [] {});
  int_least32_t exit_code = 0;
  native::process::wait(reinterpret_cast<speech_synthesizer_data*>(handle)->process_handle, exit_code);
}

void speech_synthesizer::speak_async(intptr_t handle, const string& text_to_speak, std::function<void()> on_speak_completed) {
  reinterpret_cast<speech_synthesizer_data*>(handle)->process_handle = native::process::shell_execute("", reinterpret_cast<speech_synthesizer_data*>(handle)->say_cmd_file_name, text_to_speak, "", PROCESS_WINDOW_STYLE_HIDDEN);
  thread wait_process_thread([on_speak_completed, handle] {
    int_least32_t exit_code = 0;
    native::process::wait(reinterpret_cast<speech_synthesizer_data*>(handle)->process_handle, exit_code);
    on_speak_completed();
  });
  wait_process_thread.detach();
}

void speech_synthesizer::stop(intptr_t handle) {

}
