#include "../../../include/xtd/drawing/icon.h"
#include <fstream>
#include <xtd/drawing/native/icon.h>

using namespace xtd;
using namespace xtd::drawing;

icon icon::empty;

icon::icon(const std::string &filename) {
  data_->handle_ = native::icon::create(filename);
}

icon::icon(std::istream& stream) {
  data_->handle_ = native::icon::create(stream);
}

icon::icon(const char* const* bits) {
  data_->handle_ = native::icon::create(bits);
}

icon::icon(const icon& icon, int32_t width, int32_t height) {
  data_->handle_ = native::icon::create(icon.data_->handle_, width, height);
}

icon::~icon() {
  if (data_.use_count() == 1 && data_->handle_)
    native::icon::destroy(data_->handle_);
}

void icon::save(const std::string& filename) const {
  native::icon::save(data_->handle_, filename);
}

void icon::save(std::ostream& stream) const {
  native::icon::save(data_->handle_, stream);
}

bitmap icon::to_bitmap() const {
 return bitmap(image::from_hbitmap(native::icon::to_bitmap(data_->handle_)));
}
