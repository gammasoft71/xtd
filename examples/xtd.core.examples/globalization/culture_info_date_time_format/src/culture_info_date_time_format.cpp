#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  // Creates and initializes a CultureInfo.
  auto my_ci = culture_info {"en-US", false};
  
  // Clones my_ci and modifies the DTFI and NFI instances associated with the clone.
  auto my_ci_clone = my_ci.clone();
  my_ci_clone.date_time_format().am_designator("a.m.");
  my_ci_clone.date_time_format().date_separator("-");
  //my_ci_clone.number_format().currency_symbol("USD");
  //my_ci_clone.number_format().number_decimal_digits(4);
  
  // Displays the properties of the DTFI and NFI instances associated with the original and with the clone.
  console::write_line( "dtfi/nfi PROPERTY\tORIGINAL\tMODIFIED CLONE" );
  console::write_line( "dtfi.am_designator\t{0}\t\t{1}", my_ci.date_time_format().am_designator(), my_ci_clone.date_time_format().am_designator() );
  console::write_line( "dtfi.date_separator\t{0}\t\t{1}", my_ci.date_time_format().date_separator(), my_ci_clone.date_time_format().date_separator() );
  //console::write_line( "nfi.currency_symbol\t{0}\t\t{1}", my_ci.number_format().currency_symbol(), my_ci_clone.number_format().currency_symbol() );
  //console::write_line( "nfi.NumberDecimalDigits\t{0}\t\t{1}", my_ci.number_format().number_decimal_digits(), my_ci_clone.number_format().number_decimal_digits() );
}

// This code produces the following output :
//
// dtfi/nfi PROPERTY         ORIGINAL        MODIFIED CLONE
// dtfi.am_designator        AM              a.m.
// dfi.date_separator        /               -
// nfi.currency_symbol       $               USD
// nfi.number_decimal_digits 2               4
