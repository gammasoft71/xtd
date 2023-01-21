#include <xtd/xtd>

using namespace xtd;

class program {
public:
  static auto main() {
    // Get the date and time for the current moment, adjusted
    // to the local time zone.
    
    date_time save_now = date_time::now();
    
    // Get the date and time for the current moment expressed
    // as coordinated universal time (UTC).
    
    date_time save_utc_now = date_time::utc_now();
    date_time my_dt;
    
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
  
  static void display(const ustring& title, const date_time& input_dt) {
    date_time disp_dt = input_dt;
    ustring dt_string;
    
    // display the original date_time.
    
    dt_string = disp_dt.to_string("u");
    console::write_line("{0} {1}, kind = {2}", title, dt_string, disp_dt.kind());
    
    // Convert input_dt to local time and display the result.
    // If input_dt.kind() is date_time_kind.Utc, the conversion is performed.
    // If input_dt.kind() is date_time_kind::local, the conversion is not performed.
    // If input_dt.kind() is date_time_kind::unspecified, the conversion is
    // performed as if input_dt was universal time.
    
    disp_dt = input_dt.to_local_time();
    dt_string = disp_dt.to_string("u");
    console::write_line("  to_local_time:     {0}, kind = {1}", dt_string, disp_dt.kind());
    
    // Convert input_dt to universal time and display the result.
    // If input_dt.kind() is date_time_kind.Utc, the conversion is not performed.
    // If input_dt.kind() is date_time_kind::local, the conversion is performed.
    // If input_dt.kind() is date_time_kind::unspecified, the conversion is
    // performed as if input_dt was local time.
    
    disp_dt = input_dt.to_universal_time();
    dt_string = disp_dt.to_string("u");
    console::write_line("  to_universal_time: {0}, kind = {1}", dt_string, disp_dt.kind());
    console::write_line();
  }
  
  // display the value and kind property for date_time::now() and date_time::utc_now().
  
  static void display_now(const ustring& title, const date_time& input_dt) {
    ustring dt_string = input_dt.to_string("u");
    console::write_line("{0} {1}, kind = {2}", title, dt_string, input_dt.kind());
  }
};

startup_(program);

// This code can produces the following output:
//
// utc_now: ........... 2021-12-31 17:08:41, Kind = utc
// now: ............... 2021-12-31 18:08:41, Kind = local
//
// utc: ............... 2021-12-31 17:08:41, Kind = utc
//   to_local_time:     2021-12-31 18:08:41, Kind = local
//   to_universal_time: 2021-12-31 17:08:41, Kind = utc
//
// local: ............. 2021-12-31 18:08:41, Kind = local
//   to_local_time:     2021-12-31 18:08:41, Kind = local
//   to_universal_time: 2021-12-31 17:08:41, Kind = utc
//
// unspecified: ....... 2021-12-31 18:08:41, Kind = unspecified
//   to_local_time:     2021-12-31 19:08:41, Kind = local
//   to_universal_time: 2021-12-31 17:08:41, Kind = utc
