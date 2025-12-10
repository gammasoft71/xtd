#include <xtd/xtd>

class program {
public:
  static auto main() {
    // Get the date and time for the current moment, adjusted
    // to the local time zone.
    
    auto save_now = date_time::now();
    
    // Get the date and time for the current moment expressed
    // as coordinated universal time (UTC).
    
    auto save_utc_now = date_time::utc_now();
    auto my_dt = date_time {};
    
    // display the value and kind property of the current moment
    // expressed as UTC and local time.
    
    display_now("utc_now: ...........", save_utc_now);
    display_now("now: ...............", save_now);
    console::write_line();
    
    // Change the kind property of the current moment to
    // date_time_kind::utc and display the result.
    
    my_dt = date_time::specify_kind(save_now, date_time_kind::utc);
    display("utc: ...............", my_dt);
    
    // Change the kind property of the current moment to
    // date_time_kind::local and display the result.
    
    my_dt = date_time::specify_kind(save_now, date_time_kind::local);
    display("local: .............", my_dt);
    
    // Change the kind property of the current moment to
    // date_time_kind::unspecified and display the result.
    
    my_dt = date_time::specify_kind(save_now, date_time_kind::unspecified);
    display("unspecified: .......", my_dt);
  }
  
  // display the value and kind() property of a date_time structure, the
  // date_time structure converted to local time, and the date_time
  // structure converted to universal time.
  
  inline static const string date_patt = "M/d/yyyy hh:mm:ss tt";  
  static auto display(const string& title, const date_time& input_dt) -> void {
    auto disp_dt = input_dt;
    auto dt_string = string::empty_string;
    
    // display the original date_time.
    
    dt_string = disp_dt.to_string("");
    console::write_line("{0} {1}, kind = {2}", title, dt_string, disp_dt.kind());
    
    // Convert input_dt to local time and display the result.
    // If input_dt.kind() is date_time_kind.Utc, the conversion is performed.
    // If input_dt.kind() is date_time_kind::local, the conversion is not performed.
    // If input_dt.kind() is date_time_kind::unspecified, the conversion is
    // performed as if input_dt was universal time.
    
    disp_dt = input_dt.to_local_time();
    dt_string = disp_dt.to_string(date_patt);
    console::write_line("  to_local_time:     {0}, kind = {1}", dt_string, disp_dt.kind());
    
    // Convert input_dt to universal time and display the result.
    // If input_dt.kind() is date_time_kind.Utc, the conversion is not performed.
    // If input_dt.kind() is date_time_kind::local, the conversion is performed.
    // If input_dt.kind() is date_time_kind::unspecified, the conversion is
    // performed as if input_dt was local time.
    
    disp_dt = input_dt.to_universal_time();
    dt_string = disp_dt.to_string(date_patt);
    console::write_line("  to_universal_time: {0}, kind = {1}", dt_string, disp_dt.kind());
    console::write_line();
  }
  
  // display the value and kind property for date_time::now() and date_time::utc_now().
  
  static auto display_now(const string& title, const date_time& input_dt) -> void {
    auto dt_string = input_dt.to_string(date_patt);
    console::write_line("{0} {1}, kind = {2}", title, dt_string, input_dt.kind());
  }
};

startup_(program::main);

// This code can produce the following output :
//
// utc_now: ........... 10/24/2025 08:59:24 PM, kind = utc
// now: ............... 10/24/2025 10:59:24 PM, kind = local
//
// utc: ............... 10/24/2025 8:59:24 PM, kind = utc
//   to_local_time:     10/24/2025 10:59:24 PM, kind = local
//   to_universal_time: 10/24/2025 08:59:24 PM, kind = utc
//
// local: ............. 10/24/2025 10:59:24 PM, kind = local
//   to_local_time:     10/24/2025 10:59:24 PM, kind = local
//   to_universal_time: 10/24/2025 08:59:24 PM, kind = utc
//
// unspecified: ....... 10/24/2025 10:59:24 PM, kind = unspecified
//   to_local_time:     10/25/2025 00:59:24 AM, kind = local
//   to_universal_time: 10/24/2025 08:59:24 PM, kind = utc
