#include <xtd/linq/enumerable>
#include <xtd/console>

using namespace xtd;
using namespace xtd::linq;

auto main() -> int {
  auto sentence = "the quick brown fox jumps over the lazy dog"_s;
  
  // Split the string into individual words.
  auto words = sentence.split(' ');
  
  // Prepend each word to the beginning of the new sentence to reverse the word order.
  auto reversed = enumerable::aggregate<string>(words.begin(), words.end(), [](const string& working_sentence, const string& next) {
    return next + " " + working_sentence;
  });
  
  console::write_line(reversed.quoted());
}

// This code produces the following output :
//
// "dog lazy the over jumps fox brown quick the"
