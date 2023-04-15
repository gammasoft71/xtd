#include "../../../include/xtd/drawing/buffered_graphics_context.h"
#include <xtd/argument_exception.h>
#include <xtd/threading/interlocked.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::threading;

const xtd::drawing::size& buffered_graphics_context::maximum_buffer() const noexcept {
  return maximum_buffer_;
}

buffered_graphics_context& buffered_graphics_context::maximum_buffer(const xtd::drawing::size& value) {
  if (value.height() <= 0 || value.width() <= 0) throw argument_exception(csf_);
  if (value.height() * value.width() < maximum_buffer_.height() * maximum_buffer_.width()) invalidate();
  maximum_buffer_ = value;
  return *this;
}

void buffered_graphics_context::invalidate() {
  int old_busy = interlocked::compare_exchange(buzy_, BUFFER_BUSY_DESTROYING, BUFFER_FREE);
  
  // if we're not busy with our buffer, lets clean it up now
  if (old_busy == BUFFER_FREE) {
    destroy();
    buzy_ = BUFFER_FREE;
  } else
    // this will indicate to free the buffer as soon as it becomes non-busy
    invalidate_when_free_ = true;
}

void buffered_graphics_context::destroy() {
  
}
