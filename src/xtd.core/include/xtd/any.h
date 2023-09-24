/// @file
/// @brief Contains std::any type and std::bad_any_cast exception.
#pragma once
/// @cond
#if defined(__cpp_lib_any) || __cplusplus >= 201703l
#include <any>
#else
#include <typeinfo>
#include <utility>

namespace std {
  class any;
  template <typename value_t>
  value_t any_cast(const any& any);
  
  template <typename value_t>
  value_t* any_cast(any* any) noexcept;
  
  template <typename value_t>
  const value_t* any_cast(const any* any) noexcept;
  
  class bad_any_cast : public std::bad_cast {
  public:
    const char* what() const noexcept override {return "bad any cast";}
  };
  
  class any {
  public:
    any() noexcept = default;
    any(const any& other) : content(other.content ? other.content->clone() : nullptr) {}
    template <typename value_t>
    any(const value_t& value) : content(new derived<value_t>(value)) {}
    template <typename value_t>
    any(value_t&& value) : content(new derived<value_t>(std::move(value))) {}
    
    ~any() {reset();}
    
    any& operator=(const any& other) {
      if (this == &other) return *this;
      reset();
      content = other.content ? other.content->clone() : nullptr;
      return *this;
    }
    
    any& operator=(const any&& other) noexcept {
      if (this == &other) return *this;
      reset();
      content = other.content ? std::move(other.content) : nullptr;
      return *this;
    }
    
    template <typename value_t>
    any& operator=(const value_t& value) {
      reset();
      content = new derived<value_t>(value);
      return *this;
    }
    
    bool has_value() const noexcept {return content != nullptr;}
    
    const std::type_info& type() const noexcept {return content ? content->type : typeid(void);}
    
    void reset() noexcept {delete content;}
    
  private:
    template <typename value_t>
    friend value_t any_cast(const any& any);
    
    template <typename value_t>
    friend value_t* any_cast(any* any) noexcept;
    
    template <typename value_t>
    friend const value_t* any_cast(const any* any) noexcept;
    
    template <typename value_t>
    value_t& value() {
      return static_cast<derived<value_t>*>(content)->data;
    }
    
    template <typename value_t>
    const value_t& value() const {
      return static_cast<derived<value_t>*>(content)->data;
    }
    
    struct base {
      base(const type_info& type) : type(type) {}
      virtual ~base() {}
      virtual base* clone() const = 0;
      
      const type_info& type;
    };
    
    template <typename value_t>
    struct derived : public base {
      derived(const value_t& value) : base(typeid(value)), data(value) {}
      value_t data;
      
      value_t& operator*() {return data;}
      
      base* clone() const override {
        return new derived<value_t>(*this);
      }
    };
    
    base* content = nullptr;
  };
  
  template <typename value_t>
  value_t any_cast(const any& any) {
    if (!any.has_value() || typeid(value_t) != any.type()) throw bad_any_cast();
    return any.value<value_t>();
  }
  
  template <typename value_t>
  value_t* any_cast(any* any) noexcept {
    if (any == nullptr || !any->has_value() || typeid(value_t) != any->type()) return nullptr;
    return any->value<value_t>();
  }
  
  template <typename value_t>
  const value_t* any_cast(const any* any) noexcept {
    if (any == nullptr || !any->has_value() || typeid(value_t) != any->type()) return nullptr;
    return any->value<value_t>();
  }
  
  template <typename value_t>
  any make_any(value_t&& value) {
    return any(std::forward<value_t>(value));
  }
}
#endif
/// @endcond
