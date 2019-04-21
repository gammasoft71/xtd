#pragma once
#include <vector>

namespace xtd {
  class guid final {
  public:
    guid() = default;
    explicit guid(const std::vector<unsigned char>& data) noexcept : data_(data) {}

    /// @cond
    guid(const guid&) = default;
    guid& operator=(const guid&) = default;
    /// @endcond
    
    bool operator==(const guid& g) const noexcept {
      for (size_t index = 0; index < 16; index++)
        if (this->data_[index] != g.data_[index]) return false;
      return true;
    }
    
    bool operator!=(const guid& g) const noexcept {return !this->operator==(g);}

  private:
    std::vector<unsigned char> data_ = std::vector<unsigned char>(16);
  };
}
