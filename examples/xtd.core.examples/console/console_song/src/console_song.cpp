#include <xtd/xtd>

// Define the frequencies of notes in an octave, as well as silence (rest).
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
  g_sharp = 415
};

// Define the duration of a note in units of milliseconds.
enum class duration {
  none = 0,
  whole = 1600,
  half = whole / 2,
  quarter = half / 2,
  eighth = quarter / 2,
  sixteenth = eighth / 2
};

// Define a note as a frequency (tone) and the amount of time (duration) the note plays.
struct note {
  // Define properties to return the note's tone and duration.
  tone tone = tone::rest;
  duration duration = duration::none;
};

// Play the notes in a song.
auto play(const array<note>& tune) {
  for (auto [tone, duration] : tune)
    console::beep(as<uint32>(tone), as<uint32>(duration));
}

auto main() -> int {
  // Declare the first few notes of the song, "Mary Had A Little Lamb" and play it
  play({
    {tone::b, duration::quarter},
    {tone::a, duration::quarter},
    {tone::g_below_c, duration::quarter},
    {tone::a, duration::quarter},
    {tone::b, duration::quarter},
    {tone::b, duration::quarter},
    {tone::b, duration::half},
    {tone::a, duration::quarter},
    {tone::a, duration::quarter},
    {tone::a, duration::half},
    {tone::b, duration::quarter},
    {tone::d, duration::quarter},
    {tone::d, duration::half}
  });
}
