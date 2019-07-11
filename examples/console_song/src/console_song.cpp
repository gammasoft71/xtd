#include <xtd/xtd.console>
#include <chrono>
#include <vector>
#include <thread>

using namespace std;
using namespace xtd;

// Define the frequencies of notes in an octave, as well as
// silence (rest).
enum class tone {
  REST = 0,
  GbelowC = 196,
  A = 220,
  Asharp = 233,
  B = 247,
  C = 262,
  Csharp = 277,
  D = 294,
  Dsharp = 311,
  E = 330,
  F = 349,
  Fsharp = 370,
  G = 392,
  Gsharp = 415,
};

// Define the duration of a note in units of milliseconds.
enum class duration {
  WHOLE = 1600,
  HALF = WHOLE / 2,
  QUARTER = HALF / 2,
  EIGHTH = QUARTER / 2,
  SIXTEENTH = EIGHTH / 2,
};

// Define a note as a frequency (tone) and the amount of
// time (duration) the note plays.
struct note final {
private:
  tone tone_val = static_cast<tone>(0);
  duration dur_val = static_cast<duration>(0);
  
public:
  // Define a constructor to create a specific note.
  note(tone frequency, duration time) : tone_val(frequency), dur_val(time) {}
  
  note() = default;
  note(const note& note) = default;
  note& operator=(const note& note) = default;
  
  // Define properties to return the note's tone and duration.
  tone note_tone() noexcept {return tone_val;}
  duration note_duration() noexcept {return dur_val;}
};

// Play the notes in a song.
void play(const vector<note>& tune) {
  for (note n : tune) {
    if (n.note_tone() == tone::REST)
      this_thread::sleep_for(chrono::milliseconds(static_cast<int>(n.note_duration())));
    else
      console::beep(static_cast<int>(n.note_tone()), static_cast<int>(n.note_duration()));
  }
}

// The main entry point for the application.
int main() {
  // Declare the first few notes of the song, "Mary Had A Little Lamb".
  vector<note> mary = {
    note(tone::B, duration::QUARTER),
    note(tone::A, duration::QUARTER),
    note(tone::GbelowC, duration::QUARTER),
    note(tone::A, duration::QUARTER),
    note(tone::B, duration::QUARTER),
    note(tone::B, duration::QUARTER),
    note(tone::B, duration::HALF),
    note(tone::A, duration::QUARTER),
    note(tone::A, duration::QUARTER),
    note(tone::A, duration::HALF),
    note(tone::B, duration::QUARTER),
    note(tone::D, duration::QUARTER),
    note(tone::D, duration::HALF)
  };
  // Play the song
  play(mary);
}
