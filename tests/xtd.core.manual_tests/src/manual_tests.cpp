#include <xtd/xtd.core>
#include <xtd/xtd.drawing>

using namespace std;
using namespace xtd;

enum class value {
  one,
  two,
  three,
  four,
  five
};

int main() {
  vector<pair<value, ustring>> values {{value::one, "one"}, {value::two, "two"}, {value::three, "three"}, {value::four, "four"}, {value::five, "five"}};
  vector<int> results;
  for_each(values.begin(), values.end(), [&](auto v) {results.push_back(static_cast<int>(v.first));});
}

/*
ustring get_description(const xtd::ustring& file) {
  auto content = io::file::read_all_lines(file);
  if (content.size() < 2) return "";
  auto description = content[2];
  if (description.empty()) return "";
  static const std::regex rgx_md_link(R"(\[(.*?)\]\((.*?)\))", std::regex::optimize);
  xtd::ustring text = description;
  std::sregex_iterator iterator(description.begin(), description.end(), rgx_md_link), end{};
  for (auto it = iterator; it != end; ++it) {
    if (it->size() == 3) { // 3 matches: whole []() + sub [] + sub ()
      const xtd::ustring whole = it->str(0); // []()
      const xtd::ustring title = it->str(1); // [] contents
      text = text.replace(whole, title);
    }
  }

  return text;
}

int main() {
  auto count = 0;
  auto examples_dyrectories = vector {"/Users/yves/Projects/xtd/examples/xtd.core.examples", "/Users/yves/Projects/xtd/examples/xtd.drawing.examples", "/Users/yves/Projects/xtd/examples/xtd.forms.examples", "/Users/yves/Projects/xtd/examples/xtd.tunit.examples", "/Users/yves/Projects/xtd/examples/xtd.cmake.examples"};
  for (auto examples_dyrectory : examples_dyrectories) {
    auto type_directories = io::directory::get_directories(examples_dyrectory);
    sort(type_directories.begin(), type_directories.end());
    for (auto type_directory : type_directories) {
      auto directories = io::directory::get_directories(type_directory);
      sort(directories.begin(), directories.end());
      for (auto directory : directories) {
        auto files = io::directory::get_files(directory);
        for (auto file : files) {
          if (io::path::get_extension(file) == ".md") {
            auto format = ustring::format("/Users/yves/Projects/xtd//docs/pictures/examples/{}_{{}}.png", io::path::get_file_name(directory));
            vector images = {xtd::io::file::exists(ustring::format(format, "w")) ? xtd::drawing::bitmap(ustring::format(format, "w")) : drawing::bitmap::empty, xtd::io::file::exists(ustring::format(format, "wd")) ? xtd::drawing::bitmap(ustring::format(format, "wd")) : drawing::bitmap::empty, xtd::io::file::exists(ustring::format(format, "m")) ? xtd::drawing::bitmap(ustring::format(format, "m")) : drawing::bitmap::empty, xtd::io::file::exists(ustring::format(format, "md")) ? xtd::drawing::bitmap(ustring::format(format, "md")) : drawing::bitmap::empty, xtd::io::file::exists(ustring::format(format, "g")) ? xtd::drawing::bitmap(ustring::format(format, "g")) : drawing::bitmap::empty, xtd::io::file::exists(ustring::format(format, "gd")) ? xtd::drawing::bitmap(ustring::format(format, "gd")) : drawing::bitmap::empty};

            console::write_line("{} - {} - {} - {}", ++count, io::path::get_file_name(examples_dyrectory), io::path::get_file_name(directory), get_description(file));
            continue;
          }
        }
      }
    }
  }
}


// This code produces the following output for a consome application:
//
// target_type="console application"
// target_type="console application"
*/
