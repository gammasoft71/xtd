#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/guid>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <algorithm>
#include <numeric>
#include <random>
#if !defined(__ANDROID__) && !defined(__HAIKU__)
#include <uuid/uuid.h>
#endif

using namespace xtd::native;

std::vector<uint8_t> guid::new_guid() {
  auto guid = std::vector<uint8_t>(16);
  #if !defined(__ANDROID__) && !defined(__HAIKU__)
  uuid_generate(guid.data());
  #else
  // http://tools.ietf.org/html/rfc4122
  //
  // 0                   1                   2                   3
  // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |                          time_low                             |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |       time_mid                |         time_hi_and_version   |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |clk_seq_hi_res |  clk_seq_low  |         node (0-1)            |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |                         node (2-5)                            |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  //
  // 4.4 Algorithms for Creating a UUID from Truly Random or
  // Pseudo-Random Numbers
  //
  // The version 4 UUID is meant for generating UUIDs from truly-random or pseudo-random numbers.
  //
  // The algorithm is as follows:
  //  o  Set the two most significant bits (bits 6 and 7) of the clock_seq_hi_and_reserved to zero and one, respectively.
  //  o  Set the four most significant bits (bits 12 through 15) of the time_hi_and_version field to the 4-bit version number from Section 4.1.3.
  //  o  Set all the other bits to randomly (or pseudo-randomly) chosen values.
  static auto rand = std::random_device {};
  std::uniform_int_distribution<int32_t> rand_byte_distribution(0, std::numeric_limits<uint8_t>::max());
  std::for_each(guid.begin(), guid.end(), [&](uint8_t& value) {value = static_cast<int8_t>(rand_byte_distribution(rand));});
  guid[6] = (guid[6] & 0x0f) | 0x40;
  guid[8] = (guid[8] & 0x3f) | 0x80;
  #endif
  return guid;
}
