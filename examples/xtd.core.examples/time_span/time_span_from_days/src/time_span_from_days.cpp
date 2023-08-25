#include <xtd/console>
#include <xtd/time_span>
#include <xtd/int64_object>
#include <xtd/ustring>

using namespace std;
using namespace xtd;

void gen_time_span_from_days (double days) {
  // Crée un objet TimeSpan et une chaîne TimeSpan à partir
  // d'un nombre de jours.
  auto interval = time_span::from_days(days);
  auto time_interval = interval.to_string();
  
  // Remplit la fin de la chaîne TimeSpan avec des espaces si elle
  // ne contient pas de millisecondes.
  size_t index = time_interval.index_of( ':' );
  index = time_interval.index_of( '.', index );
  if (index == ustring::npos) time_interval += "        ";
  
  console::write_line("{0,21}{1,26}", days, time_interval);
}

int main() {
  console::write_line("This example of time_span::from_days(double)\n"
                      "generates the following output.\n" );
  console::write_line("{0,21}{1,18}",
                      "FromDays", "TimeSpan" );
  console::write_line("{0,21}{1,18}",
                      "--------", "--------" );
  
  gen_time_span_from_days(0.000000006);
  gen_time_span_from_days(0.000000017);
  gen_time_span_from_days(0.000123456);
  gen_time_span_from_days(1.234567898);
  gen_time_span_from_days(12345.678987654);
  gen_time_span_from_days(0.000011574);
  gen_time_span_from_days(0.000694444);
  gen_time_span_from_days(0.041666666);
  gen_time_span_from_days(1);
  gen_time_span_from_days(20.84745602);
}

// This example of time_span::from_days(double)
// generates the following output.
//
//              FromDays          TimeSpan
//              --------          --------
//                 6E-09          00:00:00.0010000
//               1.7E-08          00:00:00.0010000
//           0.000123456          00:00:10.6670000
//           1.234567898        1.05:37:46.6660000
//       12345.678987654    12345.16:17:44.5330000
//            1.1574E-05          00:00:01
//           0.000694444          00:01:00
//           0.041666666          01:00:00
//                     1        1.00:00:00
//           20.84745602       20.20:20:20.2000000
