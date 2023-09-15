#include <xtd/console>
#include <xtd/time_span>
#include <xtd/int64_object>
#include <xtd/ustring>

using namespace xtd;

void gen_time_span_from_hours(double hours) {
  // Crée un objet time_span et une chaîne ustring à partir
  // d'un nombre d'heures.
  time_span interval = time_span::from_hours(hours);
  ustring timeInterval = interval.to_string();
  
  // Remplit la fin de la chaîne ustring avec des espaces si elle
  // ne contient pas de millisecondes.
  size_t pIndex = timeInterval.index_of(':');
  pIndex = timeInterval.index_of( '.', pIndex );
  if (pIndex < 0) timeInterval += "        ";
  
  console::write_line( "{0,21}{1,26}", hours, timeInterval );
}

int main( ) {
  console::write_line("This example of time_span::from_hours(double)\n"
                      "generates the following output.\n" );
  console::write_line( "{0,21}{1,19}",
                      "from_hours", "time_span" );
  console::write_line( "{0,21}{1,19}",
                      "----------", "---------" );
  
  gen_time_span_from_hours( 0.0000002 );
  gen_time_span_from_hours( 0.0000003 );
  gen_time_span_from_hours( 0.0012345 );
  gen_time_span_from_hours( 12.3456789 );
  gen_time_span_from_hours( 123456.7898765 );
  gen_time_span_from_hours( 0.0002777 );
  gen_time_span_from_hours( 0.0166666 );
  gen_time_span_from_hours( 1 );
  gen_time_span_from_hours( 24 );
  gen_time_span_from_hours( 500.3389445 );
}

// This example of time_span::from_hours(double)
// generates the following output.
//
//            from_hours          time_span
//            ----------          ---------
//                 2E-07          00:00:00.0007200
//                 3E-07          00:00:00.0010800
//             0.0012345          00:00:04.4442000
//            12.3456789          12:20:44.4440400
//        123456.7898765     5144.00:47:23.5554000
//             0.0002777          00:00:00.9997199
//             0.0166666          00:00:59.9997600
//                     1                  01:00:00
//                    24                1.00:00:00
//           500.3389445       20.20:20:20.2002000
