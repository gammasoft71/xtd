#include <xtd/console>
#include <xtd/date_time>
#include <xtd/math>
#include <xtd/startup>

using namespace xtd;

class program {
public:
  static auto main() {
    auto base_date = date_time {2000, 2, 29};
    console::write_line("     Base Date:        {0:d}\n", base_date);
    
    // Show dates of previous fifteen years.
    for (auto ctr = -1; ctr >= -15; ctr--)
      console::write_line("{0,2} year(s) ago:        {1:d}", math::abs(ctr), base_date.add_years(ctr));
    console::write_line();
    
    // Show dates of next fifteen years.
    for (auto ctr = 1; ctr <= 15; ctr++)
      console::write_line("{0,2} year(s) from now:   {1:d}", ctr, base_date.add_years(ctr));
  }
};

startup_(program::main);

// This code can produces the following output:
//
//      Base Date:        02/29/2000
//
//  1 year(s) ago:        02/28/1999
//  2 year(s) ago:        02/28/1998
//  3 year(s) ago:        02/28/1997
//  4 year(s) ago:        02/29/1996
//  5 year(s) ago:        02/28/1995
//  6 year(s) ago:        02/28/1994
//  7 year(s) ago:        02/28/1993
//  8 year(s) ago:        02/29/1992
//  9 year(s) ago:        02/28/1991
// 10 year(s) ago:        02/28/1990
// 11 year(s) ago:        02/28/1989
// 12 year(s) ago:        02/29/1988
// 13 year(s) ago:        02/28/1987
// 14 year(s) ago:        02/28/1986
// 15 year(s) ago:        02/28/1985
//
//  1 year(s) from now:   02/28/2001
//  2 year(s) from now:   02/28/2002
//  3 year(s) from now:   02/28/2003
//  4 year(s) from now:   02/29/2004
//  5 year(s) from now:   02/28/2005
//  6 year(s) from now:   02/28/2006
//  7 year(s) from now:   02/28/2007
//  8 year(s) from now:   02/29/2008
//  9 year(s) from now:   02/28/2009
// 10 year(s) from now:   02/28/2010
// 11 year(s) from now:   02/28/2011
// 12 year(s) from now:   02/29/2012
// 13 year(s) from now:   02/28/2013
// 14 year(s) from now:   02/28/2014
// 15 year(s) from now:   02/28/2015
