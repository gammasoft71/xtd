# How to: Open and Append to a Log File

[stream_writer](javascript:void(0)) and [stream_reader](javascript:void(0)) write characters to and read characters from streams. 
The following code example opens the *log.txt* file for input, or creates it if it doesn't exist, and appends log information to the end of the file.
The example then writes the contents of the file to standard output for display.

As an alternative to this example, you could store the information as a single string or string array, and use the [file::write_all_text](javascript:void(0)) or [file::write_all_lines](javascript:void(0)) method to achieve the same functionality.
 
## Example

```cpp
#include <fstream>
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::io;

class program {
private:
public:
  static auto main() {
    using_ (std::ofstream os = file::append_text("log.txt")) {
      using_ (stream_writer w(os)) {
        log("Test1", w);
        log("Test2", w);
      }
    }
    
    using_ (std::ifstream is = file::open_text("log.txt")) {
      using_ (stream_reader r(is)) {
        dump_log(r);
      }
    }
  }
  
  static void log(const string& log_message, text_writer& w) {
    w.write("\r\nLog Entry : ");
    w.write_line("{} {}", date_time::now().to_long_time_string(), date_time::now().to_long_date_string());
    w.write_line("  :");
    w.write_line("  :{}", log_message);
    w.write_line ("-------------------------------");
  }
  
  static void dump_log(stream_reader& r) {
    while (!r.end_of_stream()) {
      string line = r.read_line();
      console::write_line(line);
    }
  }
};

startup_(program::main);

// The example creates a file named "log.txt" and writes the following lines to it,
// or appends them to the existing "log.txt" file:

// Log Entry : <current long time string> <current long date string>
//  :
//  :Test1
// -------------------------------

// Log Entry : <current long time string> <current long date string>
//  :
//  :Test2
// -------------------------------

// It then writes the contents of "log.txt" to the console.
```
 
## See also

* [Common I/O Tasks](/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks)
* [Tutorials](/docs/documentation/guides/Overview/Tutorials)
* [Documentation](/docs/documentation)

[//]: # (https://docs.microsoft.com/en-us/dotnet/standard/io/how-to-open-and-append-to-a-log-file)
