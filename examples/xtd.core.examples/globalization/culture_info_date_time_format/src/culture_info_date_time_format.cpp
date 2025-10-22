#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  // Creates and initializes a xtd::globalization::culture_info.
  auto my_ci = culture_info {"en-US"};
  
  // Copy my_ci and modifies the DTFI and NFI instances associated with the copy.
  auto my_ci_copy = my_ci;
  my_ci_copy.date_time_format().am_designator("A.M.");
  my_ci_copy.date_time_format().date_separator("-");
  //my_ci_copy.number_format().currency_symbol("USD");
  //my_ci_copy.number_format().number_decimal_digits(4);
  
  // Clones my_ci and modifies the DTFI and NFI instances associated with the clone.
  auto my_ci_clone = my_ci.clone();
  my_ci_clone.date_time_format().am_designator("a.m.");
  my_ci_clone.date_time_format().date_separator(".");
  //my_ci_clone.number_format().currency_symbol("usd");
  //my_ci_clone.number_format().number_decimal_digits(3);

  // Displays the properties of the DTFI and NFI instances associated with the original and with the clone.
  console::write_line("dtfi/nfi PROPERTY           ORIGINAL         LOCAL            MODIFIED COPY    MODIFIED CLONE" );
  console::write_line("dtfi.am_designator          {,-16} {,-16} {,-16} {,-16}", culture_info {"en-US"}.date_time_format().am_designator(), my_ci.date_time_format().am_designator(), my_ci_copy.date_time_format().am_designator(), my_ci_clone.date_time_format().am_designator());
  console::write_line("dtfi.date_separator         {,-16} {,-16} {,-16} {,-16}", culture_info {"en-US"}.date_time_format().date_separator(), my_ci.date_time_format().date_separator(), my_ci_copy.date_time_format().date_separator(), my_ci_clone.date_time_format().date_separator());
  //console::write_line("nfi.currency_symbol         {,-16} {,-16} {,-16} {,-16}", culture_info {"en-US"}.number_format().currency_symbol(), my_ci.number_format().currency_symbol(), my_ci_copy.number_format().currency_symbol(), my_ci_clone.number_format().currency_symbol());
  //console::write_line("nfi.number_decimal_digits   {,-16} {,-16} {,-16} {,-16}", culture_info {"en-US"}.number_format().number_decimal_digits(), my_ci.number_format().number_decimal_digits(), my_ci_copy.number_format().number_decimal_digits(), my_ci_clone.number_format().number_decimal_digits());
}

// This code produces the following output :
//
// dtfi/nfi PROPERTY           ORIGINAL         LOCAL            MODIFIED COPY    MODIFIED CLONE
// dtfi.am_designator          AM               A.M.             A.M.             a.m.
// dtfi.date_separator         /                -                -                .
// nfi.currency_symbol         $                USD              USD              usd
// nfi.number_decimal_digits   2                4                4                3
