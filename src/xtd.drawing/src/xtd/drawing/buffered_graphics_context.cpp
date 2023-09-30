#include "../../../include/xtd/drawing/buffered_graphics_context.h"
#include <xtd/threading/interlocked>
#include <xtd/argument_exception>
#include <xtd/optional>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::threading;

const xtd::drawing::size& buffered_graphics_context::maximum_buffer() const noexcept {
  return maximum_buffer_;
}

buffered_graphics_context& buffered_graphics_context::maximum_buffer(const xtd::drawing::size& value) {
  if (value.height() <= 0 || value.width() <= 0) throw argument_exception {csf_};
  if (value.height() * value.width() < maximum_buffer_.height() * maximum_buffer_.width()) invalidate();
  maximum_buffer_ = value;
  return *this;
}


void buffered_graphics_context::allocate(const xtd::drawing::graphics& target_graphics, const xtd::drawing::rectangle& target_rectangle) {
  compat_graphics_ = target_graphics;
  
}

void buffered_graphics_context::allocate(intptr target_dc, const xtd::drawing::rectangle& target_rectangle) {
  allocate(graphics::from_hdc(target_dc), target_rectangle);
}

void buffered_graphics_context::invalidate() {
  int old_busy = interlocked::compare_exchange(busy_, BUFFER_BUSY_DESTROYING, BUFFER_FREE);
  
  // if we're not busy with our buffer, lets clean it up now
  if (old_busy == BUFFER_FREE) {
    destroy();
    busy_ = BUFFER_FREE;
  } else
    // this will indicate to free the buffer as soon as it becomes non-busy
    invalidate_when_free_ = true;
}

/*
xtd::drawing::buffered_graphics buffered_graphics_context::alloc_buffer_in_temp_manager(const xtd::drawing::graphics* target_graphics, intptr target_dc, const xtd::drawing::rectangle& target_rectangle) {
  auto temp_context = buffered_graphics_context {};
  auto temp_buffer = buffered_graphics {};

  try {
      temp_buffer = temp_context.alloc_buffer(targetGraphics, targetDC, targetRectangle);
      temp_buffer.free_context(true);
    }
  }
  finally {
    if (temp_context != null && (temp_buffer == null || (temp_buffer != null && !temp_buffer.DisposeContext))) {
      temp_context.Dispose();
    }
  }

  return temp_buffer;
}

buffered_graphics buffered_graphics_context::allocate_buffer(const graphics* target_graphics, intptr target_dc, const rectangle& target_rectangle) {
  auto old_busy = interlocked::compare_exchange(busy_, BUFFER_BUSY_PAINTING, BUFFER_FREE);

  // In the case were we have contention on the buffer - i.e. two threads trying to use the buffer at the same time, we just create a temp buffermanager and have the buffer dispose of it when it is done.
  //
  if (old_busy != BUFFER_FREE) {
    return alloc_buffer_in_temp_manager(target_graphics, target_dc, target_rectangle);
  }

  auto surface = optional<graphics> (};
  target_location_ = point(target_rectangle.x(), target_rectangle.y());

  try {
    if (target_graphics != null) {
      auto dest_dc = target_graphics->get_hdc();
      try {
        surface = create_buffer(dest_dc, -target_location_.x(), -target_location_.y(), target_rectangle.width(), target_rectangle.height());
      } catch(...) {

      }
      target_graphics->release_hdc(dest_dc);
    }
    else {
      surface = create_buffer(target_dc, -target_location_.x(), -target_location_.y(), target_rectangle.width(), target_rectangle.height());
    }

    buffer_ = buffered_graphics(surface.value()// *, *this* /, *target_graphics, target_dc, target_location_, virtual_size_);
  } catch(...) {
    busy_ = BUFFER_FREE; // free the buffer so it can be disposed.
    throw;
  }
  return buffer_;
}
*/

void buffered_graphics_context::destroy() {

}
