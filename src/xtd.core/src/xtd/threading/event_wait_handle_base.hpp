#pragma once
#include "../../../include/xtd/threading/event_wait_handle.hpp"
#include "../../../include/xtd/abstract.hpp"

class xtd::threading::event_wait_handle::event_wait_handle_base abstract_ {
public:
  virtual intptr handle() const noexcept = 0;
  virtual void handle(intptr value) = 0;
  virtual bool create(bool initial_state, bool manual_reset) = 0;
  virtual bool create(bool initial_state, bool manual_reset, const string& name) = 0;
  virtual void destroy() = 0;
  virtual bool open(const string& name) = 0;
  virtual bool set(bool& io_error) = 0;
  virtual bool reset(bool& io_error) = 0;
  virtual uint32 wait(int32 milliseconds_timeout) = 0;
};
