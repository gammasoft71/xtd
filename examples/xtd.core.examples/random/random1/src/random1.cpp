#include <xtd/xtd>

auto main() -> int {
  auto bytes1 = array<byte>(100);
  auto bytes2 = array<byte>(100);
  auto rnd1 = xtd::random {};
  auto rnd2 = xtd::random {};
  
  rnd1.next_bytes(bytes1);
  rnd2.next_bytes(bytes2);
  
  console::write_line("First Series:");
  for (auto i = 0ul; i < bytes1.length(); i++) {
    console::write("{, 5}", bytes1[i]);
    if ((i + 1) % 10 == 0)
      console::write_line();
  }
  
  console::write_line();
  console::write_line("Second Series:");
  for (auto i = 0ul; i < bytes2.length(); i++) {
    console::write("{, 5}", bytes2[i]);
    if ((i + 1) % 10 == 0)
      console::write_line();
  }
}

// This code can produce the following output :
//
// First Series:
//   104  222  250  126  113   23  137   65  199   68
//    72  242   71  179   29   70    1  160  135  214
//   129  158   46   16  137   48   66   28   81  190
//   157  155  212  222    3  211   14  137    1   30
//    50  217  229  181  252   55  241   74  230  148
//   153   59   16  152   54  226   11   64  133  236
//    90  255   30   52   45  116  203  193   27  167
//   187  190   68  218   37   16  229  116  150  161
//   183  130  219   90  192  254   24  232  174  116
//    46  191  226   53  118  198  148   29   76  106
//
// Second Series:
//   104  222  250  126  113   23  137   65  199   68
//    72  242   71  179   29   70    1  160  135  214
//   129  158   46   16  137   48   66   28   81  190
//   157  155  212  222    3  211   14  137    1   30
//    50  217  229  181  252   55  241   74  230  148
//   153   59   16  152   54  226   11   64  133  236
//    90  255   30   52   45  116  203  193   27  167
//   187  190   68  218   37   16  229  116  150  161
//   183  130  219   90  192  254   24  232  174  116
//    46  191  226   53  118  198  148   29   76  106
