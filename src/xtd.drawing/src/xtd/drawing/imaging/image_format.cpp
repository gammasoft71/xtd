#include "../../../../include/xtd/drawing/imaging/image_format.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;

image_format::image_format(const class guid& guid) noexcept : guid_(guid) {
}

const class guid image_format::guid() const noexcept {
  return guid_;
}

image_format image_format::bmp() noexcept {
  return image_format {xtd::guid {"b96b3cab-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::emf() noexcept {
  return image_format {xtd::guid {"b96b3cac-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::exif() noexcept {
  return image_format {xtd::guid {"b96b3cb2-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::gif() noexcept {
  return image_format {xtd::guid {"b96b3cb0-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::ico() noexcept {
  return image_format {xtd::guid {"b96b3cb5-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::jpeg() noexcept {
  return image_format {xtd::guid {"b96b3cae-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_bmp() noexcept {
  return image_format {xtd::guid {"b96b3caa-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::png() noexcept {
  return image_format {xtd::guid {"b96b3caf-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::tiff() noexcept {
  return image_format {xtd::guid {"b96b3cb1-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::wmf() noexcept {
  return image_format {xtd::guid {"b96b3cad-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_gif() noexcept {
  return image_format {xtd::guid {"b96b3cb6-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_ico() noexcept {
  return image_format {xtd::guid {"b96b3cb7-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_jpeg() noexcept {
  return image_format {xtd::guid {"b96b3cb8-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_png() noexcept {
  return image_format {xtd::guid {"b96b3cb9-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_tiff() noexcept {
  return image_format {xtd::guid {"b96b3cba-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::cur() noexcept {
  return image_format {xtd::guid {"b96b3cbb-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_cur() noexcept {
  return image_format {xtd::guid {"b96b3cbc-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::xbm() noexcept {
  return image_format {xtd::guid {"b96b3cbd-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_xbm() noexcept {
  return image_format {xtd::guid {"b96b3cbe-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::xpm() noexcept {
  return image_format {xtd::guid {"b96b3cbf-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_xpm() noexcept {
  return image_format {xtd::guid {"b96b3cc0-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::pnm() noexcept {
  return image_format {xtd::guid {"b96b3cc1-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_pnm() noexcept {
  return image_format {xtd::guid {"b96b3cc2-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::pcx() noexcept {
  return image_format {xtd::guid {"b96b3cc3-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_pcx() noexcept {
  return image_format {xtd::guid {"b96b3cc4-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::pict() noexcept {
  return image_format {xtd::guid {"b96b3cc5-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_pict() noexcept {
  return image_format {xtd::guid {"b96b3cc6-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::icon() noexcept {
  return image_format {xtd::guid {"b96b3cc7-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_icon() noexcept {
  return image_format {xtd::guid {"b96b3cc8-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::cursor() noexcept {
  return image_format {xtd::guid {"b96b3cc9-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::memory_cursor() noexcept {
  return image_format {xtd::guid {"b96b3cca-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::ani() noexcept {
  return image_format {xtd::guid {"b96b3ccb-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::iif() noexcept {
  return image_format {xtd::guid {"b96b3ccc-0728-11d3-9d7b-0000f81ef32e"}};
}

image_format image_format::tga() noexcept {
  return image_format {xtd::guid {"b96b3ccd-0728-11d3-9d7b-0000f81ef32e"}};
}

int32 image_format::compare_to(const image_format& value) const noexcept {
  return guid_ < value.guid_ ? -1 : guid_ > value.guid_ ? 1 : 0;
}

bool image_format::equals(const object& obj) const noexcept {
  return is<image_format>(obj) && equals(static_cast<const image_format&>(obj));
}

bool image_format::equals(const image_format& other) const noexcept {
  return guid_ == other.guid_;
}

size image_format::get_hash_code() const noexcept {
  return hash_code::combine(guid_);
}

string image_format::to_string() const noexcept {
  return string::format("[image_format: {}]", guid_);
}
