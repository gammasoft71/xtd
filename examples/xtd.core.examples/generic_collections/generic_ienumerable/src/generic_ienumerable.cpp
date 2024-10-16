#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::collections::generic;

class program {
public:
  static auto main() -> void {
    test_stream_reader_enumerable();
    console::write_line("---");
    test_reading_file();
  }
  
  static void test_stream_reader_enumerable() {
    // Check the memory before the iterator is used.
    auto memory_before = memory_information::get_used_process_memory();
    auto strings_found = array<string> {};
    // Open a file with the stream_reader_enumerable and check for a string.
    try {
      for (auto line : stream_reader_enumerable {path::combine(path::get_temp_path(), "temp_file.txt")})
        if (line.contains("string to search for")) strings_found.push_back(line);
      console::write_line("Found: {}", strings_found.size());
    } catch (const file_not_found_exception&) {
      console::write_line("This example requires a file named {}.", path::combine(path::get_temp_path(), "temp_file.txt"));
      return;
    }
    
    // Check the memory after the iterator and output it to the console.
    auto memory_after = memory_information::get_used_process_memory();
    console::write_line("Memory Used With Iterator = \t{} kb", (memory_after - memory_before) / 1024);
  }

  static void test_reading_file() {
    size memory_before = memory_information::get_used_process_memory();

    auto file_contents = list<string> {};
    try {
      auto sr = stream_reader {path::combine(path::get_temp_path(), "temp_file.txt")};
      // Add the file contents to a generic list of strings.
      while (!sr.end_of_stream())
        file_contents.add(sr.read_line());
      sr.close();
    } catch (const file_not_found_exception&) {
      console::write_line("This example requires a file named {}.", path::combine(path::get_temp_path(), "temp_file.txt"));
      return;
    }
    
    // Check for the string.
    auto strings_found = array<string> {};
    for (auto line : file_contents)
      if (line.contains("string to search for")) strings_found.push_back(line);
    console::write_line("Found: {}", strings_found.size());

    // Check the memory after when the iterator is not used, and output it to the console.
    auto memory_after = memory_information::get_used_process_memory();
    console::write_line("Memory Used Without Iterator = \t{} kb", (memory_after - memory_before) / 1024);
  }

  // you must also implement xtd::collections::generic::ienumerable <type_t> and xtd::collections::generic::ienumerator <type_t>
  class stream_reader_enumerable : public ienumerable<string> {
  private:
    string file_path_;
    
  public:
    stream_reader_enumerable(const string& file_path) : file_path_ {file_path} {}
    
    // Must implement get_enumerator, which returns a new stream_reader_enumerator.
    enumerator<string> get_enumerator() const override {return {new_ptr<stream_reader_enumerator>(file_path_)};}
  };
  
  // When you implement xtd::collections::generic::ienumerable <type_t>, you must also implement xtd::collections::generic::ienumerator <type_t>, which will walk through the contents of the file one line at a time.
  class stream_reader_enumerator : public object, public ienumerator<string> {
  private:
    stream_reader sr_;
    std::optional<string> current_;

  public:
    stream_reader_enumerator(const string& file_path) : sr_ {file_path} {}
    ~stream_reader_enumerator() {sr_.close();}

    // Implement current, move_next and reset, which are required by ienumerator.
    const string& current() const override {
      if (!current_.has_value()) throw invalid_operation_exception {};
      return current_.value();
    }
        
    bool move_next() override {
      if (sr_.end_of_stream()) current_.reset();
      else current_ = sr_.read_line();
      return current_.has_value();
    }
    
    void reset() override {
      sr_.base_stream()->get().seekg(0, std::ios_base::seekdir::beg);
      current_.reset();
    }
  };
};

startup_(program::main);

// This code produces the following output :
//
// Found: 2
// Memory Used With Iterator =   0 kb
// ---
// Found: 2
// Memory Used Without Iterator =   64 kb
