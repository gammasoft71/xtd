#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <xtd/static.h>
#include <xtd/drawing/icon.h>

namespace xtd {
  namespace forms {
    namespace native {
      class about_dialog static_ {
      public:
        static void show(intptr_t hwnd, const xtd::drawing::icon& icon, const std::string& name, const std::string& description, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const std::vector<std::string>& creators, const std::vector<std::string>& designers, const std::vector<std::string>& doc_writers, const std::vector<std::string>& translators, const std::string& license);
      };
    }
  }
}
