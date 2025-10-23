#include <xtd/xtd>

class program {
public:
  static auto main() {
    auto window = 10;
    auto freq = 60 * 60 * 2; // 2 hours;
    
    auto d1 = date_time::now();
    
    auto d2 = d1.add_seconds(2 * window);
    auto d3 = d1.add_seconds(-2 * window);
    auto d4 = d1.add_seconds(window / 2);
    auto d5 = d1.add_seconds(-window / 2);
    
    auto d6 = (d1.add_hours(2)).add_seconds(2 * window);
    auto d7 = (d1.add_hours(2)).add_seconds(-2 * window);
    auto d8 = (d1.add_hours(2)).add_seconds(window / 2);
    auto d9 = (d1.add_hours(2)).add_seconds(-window / 2);
    
    console::write_line("d1 ({0}) ~= d1 ({1}): {2}", d1, d1, roughly_equals(d1, d1, window, freq));
    console::write_line("d1 ({0}) ~= d2 ({1}): {2}", d1, d2, roughly_equals(d1, d2, window, freq));
    console::write_line("d1 ({0}) ~= d3 ({1}): {2}", d1, d3, roughly_equals(d1, d3, window, freq));
    console::write_line("d1 ({0}) ~= d4 ({1}): {2}", d1, d4, roughly_equals(d1, d4, window, freq));
    console::write_line("d1 ({0}) ~= d5 ({1}): {2}", d1, d5, roughly_equals(d1, d5, window, freq));
    
    console::write_line("d1 ({0}) ~= d6 ({1}): {2}", d1, d6, roughly_equals(d1, d6, window, freq));
    console::write_line("d1 ({0}) ~= d7 ({1}): {2}", d1, d7, roughly_equals(d1, d7, window, freq));
    console::write_line("d1 ({0}) ~= d8 ({1}): {2}", d1, d8, roughly_equals(d1, d8, window, freq));
    console::write_line("d1 ({0}) ~= d9 ({1}): {2}", d1, d9, roughly_equals(d1, d9, window, freq));
  }
  
private:
  static bool roughly_equals(const date_time& time, const date_time& time_with_window, int window_in_seconds, int frequency_in_seconds) {
    auto delta = convert::to_int32((time_with_window - time).total_seconds_duration().count()) % frequency_in_seconds;
    
    delta = delta > window_in_seconds ? frequency_in_seconds - delta : delta;
    
    return math::abs(delta) < window_in_seconds;
  }
};

startup_(program::main);

// This code produces the following output :
//
// d1 (10/23/2025 1:04:56 AM) ~= d1 (10/23/2025 1:04:56 AM): true
// d1 (10/23/2025 1:04:56 AM) ~= d2 (10/23/2025 1:05:16 AM): false
// d1 (10/23/2025 1:04:56 AM) ~= d3 (10/23/2025 1:04:36 AM): false
// d1 (10/23/2025 1:04:56 AM) ~= d4 (10/23/2025 1:05:01 AM): true
// d1 (10/23/2025 1:04:56 AM) ~= d5 (10/23/2025 1:04:51 AM): true
// d1 (10/23/2025 1:04:56 AM) ~= d6 (10/23/2025 3:05:16 AM): false
// d1 (10/23/2025 1:04:56 AM) ~= d7 (10/23/2025 3:04:36 AM): false
// d1 (10/23/2025 1:04:56 AM) ~= d8 (10/23/2025 3:05:01 AM): true
// d1 (10/23/2025 1:04:56 AM) ~= d9 (10/23/2025 3:04:51 AM): true
