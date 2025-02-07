#include "../../../../include/xtd/drawing/imaging/encoder.hpp"

using namespace xtd;
using namespace xtd::drawing::imaging;

encoder::encoder(const xtd::guid& guid) : guid_ {guid} {
}

encoder encoder::chrominance_table() noexcept {
  return encoder {xtd::guid {"f2e455dc-09b3-4316-8260-676ada32481c"}};
}

encoder encoder::color_depth() noexcept {
  return encoder {xtd::guid {"66087055-ad66-4c7c-9a18-38a2310b8337"}};
}

encoder encoder::compression() noexcept {
  return encoder {xtd::guid {"e09d739d-ccd4-44ee-8eba-3fbf8be4fc58"}};
}

encoder encoder::luminance_table() noexcept {
  return encoder {xtd::guid {"edb33bce-0266-4a77-b904-27216099e717"}};
}

encoder encoder::quality() noexcept {
  return encoder {xtd::guid {"1d5be4b5-fa4a-452d-9cdd-5db35105e7eb"}};
}

encoder encoder::render_method() noexcept {
  return encoder {xtd::guid {"6d42c53a-229a-4825-8bb7-5c99e2b9a8b8"}};
}

encoder encoder::save_flag() noexcept {
  return encoder {xtd::guid {"292266fc-ac40-47bf-8cfc-a85b89a655de"}};
}

encoder encoder::scan_method() noexcept {
  return encoder {xtd::guid {"3a4e2661-3109-4e56-8536-42c156e7dcfa"}};
}

encoder encoder::transformation() noexcept {
  return encoder {xtd::guid {"8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9"}};
}

encoder encoder::version() noexcept {
  return encoder {xtd::guid {"24d18c76-814a-41a4-bf53-1c219cccf797"}};
}

const guid& encoder::guid() const noexcept {
  return guid_;
}

bool encoder::equals(const object& obj) const noexcept {
  return is<encoder>(obj) && equals(static_cast<const encoder&>(obj));
}

bool encoder::equals(const encoder& other) const noexcept {
  return guid_ == other.guid_;
}

size encoder::get_hash_code() const noexcept {
  return hash_code::combine(guid_);
}
