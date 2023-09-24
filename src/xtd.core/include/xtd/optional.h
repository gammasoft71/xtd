/// @file
/// @brief Contains std::optional type and std::bad_optional_access exception.
#pragma once
/// @cond
#if defined(__cpp_lib_optional) || __cplusplus >= 201703l
#include <optional>
#else
#include <stdexcept>
#include <utility>

namespace std {
  /*
  class bad_optional_access : public std::exception {
  public:
    const char* what() const noexcept override {return "bad optional access";}
  };
   */
  
  template <typename value_t>
  class optional {
  private:
    alignas(value_t) unsigned char data_[sizeof(value_t)];
    bool has_value_;
    
  public:
    optional() : has_value_(false) {}
    
    optional(const value_t& value) : has_value_(true) {
      new (data_) value_t(value);
    }
    
    optional(value_t&& value) : has_value_(true) {
      new (data_) value_t(std::move(value));
    }
    
    optional(const optional& other) : has_value_(other.has_value_) {
      if (other.has_value_) {
        new (data_) value_t(*other);
      }
    }
    
    optional(optional&& other) : has_value_(other.has_value_) {
      if (other.has_value_) {
        new (data_) value_t(std::move(*other));
      }
      other.reset();
    }
    
    optional& operator=(const value_t& value) {
      if (has_value_) {
        *reinterpret_cast<value_t*>(data_) = value;
      } else {
        new (data_) value_t(value);
        has_value_ = true;
      }
      return *this;
    }
    
    optional& operator=(value_t&& value) {
      if (has_value_) {
        *reinterpret_cast<value_t*>(data_) = std::move(value);
      } else {
        new (data_) value_t(std::move(value));
        has_value_ = true;
      }
      return *this;
    }
    
    optional& operator=(const optional& other) {
      if (this == &other) {
        return *this;
      }
      
      if (other.has_value_) {
        if (has_value()) {
          *reinterpret_cast<value_t*>(data_) = *other;
        } else {
          new (data_) value_t(*other);
          has_value_ = true;
        }
      } else {
        reset();
      }
      return *this;
    }
    
    optional& operator=(optional&& other) {
      if (this == &other) {
        return *this;
      }
      
      if (other.has_value_) {
        if (has_value()) {
          *reinterpret_cast<value_t*>(data_) = std::move(*other);
        } else {
          new (data_) value_t(std::move(*other));
          has_value_ = true;
        }
      } else {
        reset();
      }
      other.reset();
      return *this;
    }
    
    ~optional() {
      reset();
    }
    
    bool has_value() const {
      return has_value_;
    }
    
    const value_t& value() const {
      return operator*();
    }
    
    const value_t& value_or(const value_t& other) const {
      return has_value() ? operator*() : other;
    }
    
    void reset() {
      if (!has_value()) return;
      reinterpret_cast<value_t*>(data_)->~value_t();
      has_value_ = false;
    }
    
    const value_t* operator->() const {
      if (!has_value()) {
        throw std::runtime_error("optional does not contain a value.");
      }
      return reinterpret_cast<const value_t*>(data_);
    }
    
    value_t* operator->() {
      if (!has_value_) {
        throw std::runtime_error("optional does not contain a value.");
      }
      return reinterpret_cast<value_t*>(data_);
    }
    
    const value_t& operator*() const {
      return *operator->();
    }
    
    value_t& operator*() {
      return *operator->();
    }
    
    explicit operator bool() const {
      return has_value_;
    }
  };
}
#endif
/// @endcond
