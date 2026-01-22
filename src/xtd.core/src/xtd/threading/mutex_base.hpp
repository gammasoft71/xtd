#pragma once
#include "../../../include/xtd/threading/mutex.hpp"
#include "../../../include/xtd/abstract.hpp"

class xtd::threading::mutex::mutex_base abstract_ {
public:
  [[nodiscard]] virtual auto handle() const noexcept -> intptr = 0;
  virtual auto handle(intptr value) -> void = 0;
  [[nodiscard]] virtual auto create(bool initially_owned) -> bool = 0;
  [[nodiscard]] virtual auto create(bool initially_owned, const string& name) -> bool = 0;
  virtual auto destroy() -> void = 0;
  virtual auto open(const string& name) -> bool = 0;
  virtual auto signal(bool& io_error) -> bool = 0;
  virtual auto wait(int32 milliseconds_timeout) -> uint32 = 0;
};
