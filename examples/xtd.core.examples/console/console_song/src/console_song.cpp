#include <xtd/threading/thread>
#include <xtd/as>
#include <xtd/console>

using namespace std;
using namespace xtd;

// Define the frequencies of notes in an octave, as well as
// silence (rest).
enum class tone {
  rest = 0,
  g_below_c = 196,
  a = 220,
  a_sharp = 233,
  b = 247,
  c = 262,
  c_sharp = 277,
  d = 294,
  d_sharp = 311,
  e = 330,
  f = 349,
  f_sharp = 370,
  g = 392,
  g_sharp = 415,
};

// Define the duration of a note in units of milliseconds.
enum class duration {
  none = 0,
  whole = 1600,
  half = whole / 2,
  quarter = half / 2,
  eighth = quarter / 2,
  sixteenth = eighth / 2,
};

// Define a note as a frequency (tone) and the amount of
// time (duration) the note plays.
struct note final {
private:
  tone tone_val = tone::rest;
  ::duration dur_val = ::duration::none;
  
public:
  // Define a constructor to create a specific note.
  note(tone frequency, ::duration time) : tone_val(frequency), dur_val(time) {}
  
  note() = default;
  note(const note& note) = default;
  note& operator=(const note& note) = default;
  
  // Define properties to return the note's tone and duration.
  tone note_tone() const noexcept {return tone_val;}
  duration note_duration() const noexcept {return dur_val;}
};

// Play the notes in a song.
void play(const vector<note>& tune) {
  for (auto n : tune) {
    if (n.note_tone() == tone::rest)
      threading::thread::sleep(as<int>(n.note_duration()));
    else
      console::beep(as<unsigned int>(n.note_tone()), as<unsigned int>(n.note_duration()));
  }
}

auto main() -> int {
  // Declare the first few notes of the song, "Mary Had A Little Lamb".
  auto mary = vector {
    note(tone::b, ::duration::quarter),
    note(tone::a, ::duration::quarter),
    note(tone::g_below_c, ::duration::quarter),
    note(tone::a, ::duration::quarter),
    note(tone::b, ::duration::quarter),
    note(tone::b, ::duration::quarter),
    note(tone::b, ::duration::half),
    note(tone::a, ::duration::quarter),
    note(tone::a, ::duration::quarter),
    note(tone::a, ::duration::half),
    note(tone::b, ::duration::quarter),
    note(tone::d, ::duration::quarter),
    note(tone::d, ::duration::half)
  };
  // Play the song
  play(mary);
}
