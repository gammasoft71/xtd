#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  vector<uint8_t> bytes1(100);
  vector<uint8_t> bytes2(100);
  xtd::random rnd1;
  xtd::random rnd2;
  
  rnd1.next_bytes(bytes1);
  rnd2.next_bytes(bytes2);
  
  console::write_line("First Series:");
  for (size_t i = 0; i < bytes1.size(); i++) {
    console::write("{0, 5}", bytes1[i]);
    if ((i + 1) % 10 == 0)
      console::write_line();
  }
  
  console::write_line();
  console::write_line("Second Series:");
  for (size_t i = 0; i < bytes2.size(); i++) {
    console::write("{0, 5}", bytes2[i]);
    if ((i + 1) % 10 == 0)
      console::write_line();
  }
}

// This code can produces the following output:
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
//    23  145  214   85  131   87  216   78  228  179
//    78   33   66  208  147  247  105  248   66  244
//    53   21   60  184   39  229  189  179  228  254
//   181  188  128  222   24   98  231  188   98    3
//   233   85  235  183   72   95   67  197  142  148
//   194  123  209   52  196    0  122   42  221  244
//   255   10   52   45   50  188  218   25  235   45
//   188   19  114  208    8   60  121  223  149  112
//   125    6   64  167  160  240   18   75  150   69
//   192  173  177  149  235  151   75   33  182  108
