#include <xtd/xtd.core>
#include <chrono>
#include <vector>
#include <thread>

using namespace std;
using namespace std::this_thread;
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
  duration dur_val = duration::none;
  
public:
  // Define a constructor to create a specific note.
  note(tone frequency, duration time) : tone_val(frequency), dur_val(time) {}
  
  note() = default;
  note(const note& note) = default;
  note& operator=(const note& note) = default;
  
  // Define properties to return the note's tone and duration.
  tone note_tone() const noexcept {return tone_val;}
  duration note_duration() const noexcept {return dur_val;}
};

// Play the notes in a song.
void play(const vector<note>& tune) {
  for (note n : tune) {
    if (n.note_tone() == tone::rest)
      sleep_for(chrono::milliseconds(static_cast<int>(n.note_duration())));
    else
      console::beep(static_cast<unsigned int>(n.note_tone()), static_cast<unsigned int>(n.note_duration()));
  }
}

int main() {
  // Declare the first few notes of the song, "Mary Had A Little Lamb".
  vector mary = {
    note(tone::b, duration::quarter),
    note(tone::a, duration::quarter),
    note(tone::g_below_c, duration::quarter),
    note(tone::a, duration::quarter),
    note(tone::b, duration::quarter),
    note(tone::b, duration::quarter),
    note(tone::b, duration::half),
    note(tone::a, duration::quarter),
    note(tone::a, duration::quarter),
    note(tone::a, duration::half),
    note(tone::b, duration::quarter),
    note(tone::d, duration::quarter),
    note(tone::d, duration::half)};
  // Play the song
  play(mary);
}
