#pragma once
#include "../../../include/xtd/threading/event_wait_handle.hpp"
#include "../../../include/xtd/abstract.hpp"

class xtd::threading::event_wait_handle::event_wait_handle_base abstract_ {
public:
  [[nodiscard]] virtual auto handle() const noexcept -> intptr = 0;
  virtual auto handle(intptr value) -> void = 0;
  [[nodiscard]] virtual auto create(bool initial_state, bool manual_reset) -> bool = 0;
  [[nodiscard]] virtual auto create(bool initial_state, bool manual_reset, const string& name) -> bool = 0;
  virtual auto destroy() -> void = 0;
  virtual auto open(const string& name) -> bool = 0;
  virtual auto set(bool& io_error) -> bool = 0;
  virtual auto reset(bool& io_error) -> bool = 0;
  virtual auto wait(int32 milliseconds_timeout) -> uint32 = 0;
};
