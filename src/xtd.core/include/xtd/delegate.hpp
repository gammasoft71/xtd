/// @file
/// @brief Contains xtd::delegate <result_t(arguments_t...)> delegate.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "any.hpp"
#include "argument_null_exception.hpp"
#include "async_result.hpp"
#include "iequatable.hpp"
#include "object.hpp"
#include "object_ref.hpp"
#include "usize.hpp"
#include <functional>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  template<typename result_t>
  class delegate;
  
  template<typename result_t, typename ...arguments_t>
  class delegate<result_t(arguments_t...)>;
  /// @endcond
  
  /// @brief References a method to be called when a corresponding asynchronous operation completes.
  /// ```cpp
  /// using async_callback = xtd::delegate<void(async_result ar)>;
  /// ```
  /// @param ar The result of the asynchronous operation.
  /// @par Header
  /// ```cpp
  /// #include <xtd/async_callback>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system delegates
  using async_callback = xtd::delegate<void(async_result ar)>;
  
  /// @brief Represents a delegate, which is a data structure that refers to a static method or to a class instance and an instance method of that class.
  /// @par Header
  /// ```cpp
  /// #include <xtd/delegate>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system delegates
  /// @remarks For more info about delegates see [Delegates](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/delegates) guide.
  /// @par Examples
  /// The following example shows how to define a delegate named my Method delegate. Instances of this delegate are created for an instance method and a static method of the nested mySampleClass class. The delegate for the instance method requires an instance of mySampleClass. The mySampleClass instance is saved in a variable named mySC.
  /// @include delegate.cpp
  template<typename result_t>
  class delegate<result_t()> : public xtd::object, public xtd::iequatable<delegate<result_t()>> {
    struct data {
      std::vector<std::function<result_t()>> functions;
    };
    
    class async_result_invoke : public xtd::iasync_result {
      struct data;
    public:
      async_result_invoke(xtd::async_callback async_callback, const xtd::any_object& async_state);
      [[nodiscard]] auto async_state() const noexcept -> xtd::any_object override;
      [[nodiscard]] auto async_wait_handle() noexcept -> xtd::threading::wait_handle& override;
      [[nodiscard]] auto completed_synchronously() const noexcept -> bool override;
      [[nodiscard]] auto is_completed() const noexcept -> bool override;
      
      xtd::sptr<data> data_;
    };
    
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents function type.
    using function_t = std::function<result_t()>;
    /// @brief Represents the function collection type.
    using function_collection = std::vector<function_t>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes an empty delegate.
    delegate() = default;
    /// @cond
    delegate(delegate&&) = default;
    delegate(const delegate& other) {*data_ = *other.data_;}
    delegate& operator =(const delegate& other) {*data_ = *other.data_; return *this;}
    /// @endcond
    
    /// @brief Initializes a delegate that invokes the specified instance method.
    /// @param function the method instance.
    delegate(const function_t& function) noexcept {data_->functions.push_back(function);} // Can't be explicit by design.
    
    /// @brief Initializes a delegate that invokes the specified instance method on the specified class instance.
    /// @param object the class instance.
    /// @param function the method instance.
    template<class object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)() const) noexcept {data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));}
    /// @brief Initializes a delegate that invokes the specified instance method on the specified class instance.
    /// @param object the class instance.
    /// @param function the method instance.
    template<class object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)()) noexcept {data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));}
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief Return the size of invocation list.
    /// @return Return the size of invocation list.
    [[nodiscard]] auto count() const noexcept -> xtd::usize {return data_->functions.size();}
    
    /// @brief Gets the delegates array
    /// @return The delegates array.
    [[nodiscard]] auto functions() const -> const function_collection& {return data_->functions;}
    
    /// @brief Return if the delegate is empty.
    /// @return bool Return `true` if delegate is empty; otherwise `false`.
    [[nodiscard]] auto is_empty() const noexcept -> bool {return count() == 0;}
    
    /// @brief Return the size of invocation list.
    /// @return Return the size of invocation list.
    [[nodiscard]] auto size() const noexcept -> xtd::usize {return count();}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Clear delegates array.
    auto clear() -> void {data_->functions.clear();}
    
    /// @brief Executes the method represented by the current delegate asynchronously on the thread that the control's underlying handle was created on.
    /// @return An async_result_invoke that represents the result of the begin_invoke operation.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    [[nodiscard]] auto begin_invoke() -> async_result;
    /// @brief Executes the method represented by the current delegate asynchronously on the thread that the control's underlying handle was created on.
    /// @param async_callback The asynchronous callback that will be called at the end of the invocation.
    /// @return An async_result_invoke that represents the result of the begin_invoke operation.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    [[nodiscard]] auto begin_invoke(xtd::async_callback async_callback) -> async_result;
    /// @brief Executes the method represented by the current delegate asynchronously on the thread that the control's underlying handle was created on.
    /// @param async_callback The asynchronous callback that will be called at the end of the invocation.
    /// @param async_state The asynchronous state associated with the invocation.
    /// @return An async_result_invoke that represents the result of the begin_invoke operation.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    [[nodiscard]] auto begin_invoke(xtd::async_callback async_callback, const xtd::any_object& async_state) -> async_result;
    
    /// @brief Retrieves the return value of the asynchronous operation represented by the async_result_invoke passed.
    /// @param async The async_result_invoke that represents a specific invoke asynchronous operation, returned when calling begin_invoke.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    auto end_invoke(async_result async) -> result_t;
    
    /// @brief invokes the method represented by the current delegate.
    /// @param arguments The parameter list.
    /// @return result_t The return value.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    auto invoke() const -> result_t {return operator()();}
    
    /// @brief Determines whether this instance and another specified delegateType object have the same value.
    /// @param obj The delegateType to compare.
    /// @return bool `true` if the value of this instance is the same as the value of value; otherwise, `false`.
    [[nodiscard]] auto equals(const object& obj) const noexcept -> bool override {return is<delegate>(obj) && equals(static_cast<const delegate&>(obj));}
    /// @brief Determines whether this instance and another specified delegateType object have the same value.
    /// @param other The delegateType to compare.
    /// @return bool `true` if the value of this instance is the same as the value of value; otherwise, `false`.
    [[nodiscard]] auto equals(const delegate& other) const noexcept -> bool override {
      if (data_->functions.size() != other.data_->functions.size()) return false;
      for (auto i = xtd::usize {0}; i < data_->functions.size(); i++)
        if (!are_equals(data_->functions[i], other.data_->functions[i])) return false;
      return true;
    }
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Concatenates the invocation lists of an array of delegates.
    /// @param delegates The array of delegates to combine.
    /// @return Delegate A new delegate with an invocation list that concatenates the invocation lists of the delegates in the delegates array. Returns null if delegates is null, if delegates contains zero elements, or if every entry in delegates is null.
    /// @remarks If the delegates array contains entries that are null, those entries are ignored.
    /// @remarks The invocation list can contain duplicate entries; that is, entries that refer to the same method on the same object.
    [[nodiscard]] static auto combine(const xtd::array<delegate>& delegates) noexcept -> delegate {
      auto result = delegate {};
      for (auto delegate : delegates)
        for (auto function : delegate.data_->functions)
          result.data_->functions.push_back(function);
      return result;
    }
    
    /// @brief Concatenates the invocation lists of two delegates.
    /// @param a The delegate whose invocation list comes first.
    /// @param b The delegate whose invocation list comes second.
    /// @return A new delegate with an invocation list that concatenates the invocation lists of a and b in that order. Returns a if b is empty, returns b if a is a empty, and returns empty if both a and b are empty.
    /// @remarks The invocation list can contain duplicate entries; that is, entries that refer to the same method on the same object.
    [[nodiscard]] static auto combine(const delegate& a, const delegate& b) noexcept -> delegate {return combine({a, b});}
    
    /// @brief removes the last occurrence of the invocation list of a delegate from the invocation list of another delegate.
    /// @param source The delegate from which to remove the invocation list of value.
    /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
    /// @return A new delegate with an invocation list formed by taking the invocation list of source and removing the last occurrence of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null or if the invocation list of value is not found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source or if source is a null reference.
    /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, the last occurrence is removed.
    [[nodiscard]] static auto remove(const delegate& source, const delegate& value) noexcept -> delegate {
      auto result = source;
      std::for_each(value.data_->functions.begin(), value.data_->functions.end(), [&](const auto& function) {
        auto iterator = std::find_if(result.data_->functions.rbegin(), result.data_->functions.rend(), [&](const auto& item) {return are_equals(item, function);});
        if (iterator != result.data_->functions.rend()) result.data_->functions.erase((iterator + 1).base());
      });
      return result;
    }
    
    /// @brief removes all occurrences of the invocation list of a delegate from the invocation list of another delegate.
    /// @param source The delegate from which to remove the invocation list of value.
    /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
    /// @return A new delegate with an invocation list formed by taking the invocation list of source and removing all occurrences of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null or if the invocation list of value is not found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source, if source contains only a series of invocation lists that are equal to the invocation list of value, or if source is a null reference.
    /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, all occurrences are removed.
    [[nodiscard]] static auto remove_all(const delegate& source, const delegate& value) noexcept -> delegate {
      delegate result = source;
      for (const function_t& function : value.data_->functions) {
        if (find(result.data_->functions.begin(), result.data_->functions.end(), function) != result.data_->functions.end()) {
          for (typename function_collection::reverse_iterator iterator = result.data_->functions.rbegin(); iterator != result.data_->functions.rend(); ++iterator) {
            if (are_equals(*iterator, function))
              result.data_->functions.erase((iterator + 1).base());
          }
        }
      }
      return result;
    }
    /// @}
    
    /// @name Operators
    
    /// @{
    /// @brief invokes the method represented by the current delegate.
    /// @param arguments The parameter list.
    /// @return result_t The return value.
    auto operator()() const -> result_t {
      if (data_->functions.size() == 0) {
        if constexpr(std::is_void_v<result_t>) return;
        else if constexpr(std::is_reference_v<result_t>) {
          using underlying_t = std::remove_reference_t<result_t>;
          if constexpr(std::is_const_v<underlying_t>) {
            static const underlying_t empty_value{};
            return empty_value;
          } else {
            static underlying_t empty_value{};
            return empty_value;
          }
        } else return result_t{};
      }
      
      for (auto i = xtd::usize {0}; i < data_->functions.size() - 1; i++) {
        if (data_->functions[i] == nullptr) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
        data_->functions[i]();
      }
      if (data_->functions.back() == nullptr) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
      return data_->functions.back()();
    }
    
    auto operator =(const function_t& function) noexcept -> delegate& {
      data_->functions.clear();
      data_->functions.push_back(function);
      return *this;
    }
    /// @}
    
    /// @cond
    auto operator +(const delegate& other) const noexcept -> delegate {
      delegate result = *this;
      result += other;
      return result;
    }
    
    auto operator +(const function_t& function) const noexcept -> delegate {
      delegate result = *this;
      result += function;
      return result;
    }
    
    template<class fn_t>
    auto operator +(fn_t function) const noexcept -> delegate {
      delegate result = *this;
      result += function;
      return result;
    }
    
    auto operator +=(const delegate& other) noexcept -> delegate& {
      *this = delegate::combine(*this, other);
      return *this;
    }
    
    auto operator +=(const function_t& function) noexcept -> delegate& {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }
    
    template<class fn_t>
    auto operator +=(fn_t function) noexcept -> delegate& {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }
    
    auto operator -(const delegate& other) const noexcept -> delegate {
      delegate result = *this;
      result -= other;
      return result;
    }
    
    auto operator -(const function_t& function) const noexcept -> delegate {
      delegate result = *this;
      result -= function;
      return result;
    }
    
    template<class fn_t>
    auto operator -(fn_t function) const noexcept -> delegate {
      delegate result = *this;
      result -= function;
      return result;
    }
    
    auto operator -=(const delegate& other) noexcept -> delegate& {
      *this = delegate::remove(*this, other);
      return *this;
    }
    
    auto operator -=(const function_t& function) noexcept -> delegate& {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    
    template<class fn_t>
    auto operator -=(fn_t function) noexcept -> delegate& {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    /// @endcond
    
  private:
    [[nodiscard]] static auto are_equals(const std::function<result_t()>& fct1, const std::function<result_t()>& fct2) noexcept -> bool {return fct1.target_type() == fct2.target_type() && (fct1.template target<result_t(*)()>() == fct2.template target<result_t(*)()>() || *fct1.template target<result_t(*)()>() == *fct2.template target<result_t(*)()>());}
    [[nodiscard]] static auto find(typename function_collection::const_iterator begin, typename function_collection::const_iterator end, const function_t& function) noexcept -> typename function_collection::const_iterator {
      auto iterator = std::find_if(begin, end, [&](const auto& item) {return are_equals(item, function);});
      if (iterator != end) return iterator;
      return end;
    }
    
    xtd::sptr<data> data_ = xtd::new_sptr<data>();
  };
  
  /// @brief Represents a delegate, which is a data structure that refers to a static method or to a class instance and an instance method of that class.
  /// @par Header
  /// ```cpp
  /// #include <xtd/delegate>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system delegates
  /// @remarks For more info about delegates see [Delegates](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/delegates) guide.
  /// @par Examples
  /// The following example shows how to define a delegate named my Method delegate. Instances of this delegate are created for an instance method and a static method of the nested mySampleClass class. The delegate for the instance method requires an instance of mySampleClass. The mySampleClass instance is saved in a variable named mySC.
  /// @include delegate.cpp
  template<class result_t, typename ...arguments_t>
  class delegate<result_t(arguments_t...)> : public object, public xtd::iequatable<delegate<result_t(arguments_t...)>> {
    struct data {
      std::vector<std::function<result_t()>> no_arguments_functions;
      std::vector<std::function<result_t(arguments_t...)>> functions;
    };
    
    class async_result_invoke : public xtd::iasync_result {
      struct data;
    public:
      async_result_invoke(xtd::async_callback async_callback, const xtd::any_object& async_state);
      [[nodiscard]] auto async_state() const noexcept -> xtd::any_object override;
      [[nodiscard]] auto async_wait_handle() noexcept -> xtd::threading::wait_handle& override;
      [[nodiscard]] auto completed_synchronously() const noexcept -> bool override;
      [[nodiscard]] auto is_completed() const noexcept -> bool override;
      
      xtd::sptr<data> data_;
    };
    
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents no arguments function type.
    using no_arguments_function_t = std::function<result_t()>;
    /// @brief Represents function type.
    using function_t = std::function<result_t(arguments_t...)>;
    /// @brief function_t Represents the no arguments function collection type.
    using no_arguments_function_collection = std::vector<no_arguments_function_t>;
    /// @brief function_t Represents the function collection type.
    using function_collection = std::vector<function_t>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes an empty delegate.
    delegate() = default;
    /// @cond
    delegate(delegate&&) = default;
    delegate(const delegate& other) {*data_ = *other.data_;}
    delegate& operator =(const delegate& other) {*data_ = *other.data_; return *this;}
    delegate(const delegate<result_t()>& delegate) noexcept {data_->no_arguments_functions = delegate.functions();}
    /// @endcond
    
    /// @brief Initializes a delegate that invokes the specified instance method.
    /// @param function the method instance.
    delegate(const function_t& function) noexcept {data_->functions.push_back(function);} // Can't be explicit by design.
    
    /// @cond
    delegate(const no_arguments_function_t& function) noexcept {data_->no_arguments_functions.push_back(function);} // Can't be explicit by design.
    /// @endcond
    
    /// @brief Initializes a delegate that invokes the specified instance method on the specified class instance.
    /// @param object the class instance.
    /// @param function the method instance.
    template<class object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)() const) noexcept {data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));}
    
    /// @brief Initializes a delegate that invokes the specified instance method on the specified class instance.
    /// @param object the class instance.
    /// @param function the method instance.
    template<class object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)()) noexcept {data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));}
    /// @}
    
    /// @cond
    template<class object1_t, typename object2_t, typename... args_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(args_t...) const) noexcept {data_->functions.push_back(function_t(std::bind_front(method, const_cast<object1_t*>(&object))));}

    template<class object1_t, typename object2_t, typename... args_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(args_t...)) noexcept {data_->functions.push_back(function_t(std::bind_front(method, const_cast<object1_t*>(&object))));}
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Return the size of invocation list.
    /// @return Return the size of invocation list.
    [[nodiscard]] auto count() const noexcept -> xtd::usize {return data_->functions.size() + data_->no_arguments_functions.size();}
    
    /// @brief Gets the no arguments delegates array
    /// @return The delegates array.
    [[nodiscard]] auto no_arguments_functions() const -> const no_arguments_function_collection& {return data_->no_arguments_functions;}
    
    /// @brief Gets the delegates array
    /// @return The delegates array.
    [[nodiscard]] auto functions() const -> const function_collection& {return data_->functions;}
    
    /// @brief Return if the delegate is empty.
    /// @return bool Return `true` if delegate is empty; otherwise `false`.
    [[nodiscard]] auto is_empty() const noexcept -> bool {return count() == 0;}
    
    /// @brief Return the size of invocation list.
    /// @return Return the size of invocation list.
    [[nodiscard]] auto size() const noexcept -> xtd::usize {return count();}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Executes the method represented by the current delegate asynchronously on the thread that the control's underlying handle was created on.
    /// @param async_callback The asynchronous callback that will be called at the end of the invocation.
    /// @param async_state The asynchronous state associated with the invocation.
    /// @param arguments The parameter list.
    /// @return An async_result_invoke that represents the result of the begin_invoke operation.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    [[nodiscard]] auto begin_invoke(arguments_t&&... arguments) -> async_result;
    /// @brief Executes the method represented by the current delegate asynchronously on the thread that the control's underlying handle was created on.
    /// @param async_callback The asynchronous callback that will be called at the end of the invocation.
    /// @param arguments The parameter list.
    /// @return An async_result_invoke that represents the result of the begin_invoke operation.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    [[nodiscard]] auto begin_invoke(xtd::async_callback async_callback, arguments_t&&... arguments) -> async_result;
    /// @brief Executes the method represented by the current delegate asynchronously on the thread that the control's underlying handle was created on.
    /// @param arguments The parameter list.
    /// @return An async_result_invoke that represents the result of the begin_invoke operation.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    [[nodiscard]] auto begin_invoke(xtd::async_callback async_callback, const xtd::any_object& async_state, arguments_t&&... arguments) -> async_result;
    
    /// @brief Retrieves the return value of the asynchronous operation represented by the async_result_invoke passed.
    /// @param async The async_result_invoke that represents a specific invoke asynchronous operation, returned when calling begin_invoke.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    auto end_invoke(async_result async) -> result_t;
    
    /// @brief invokes the method represented by the current delegate.
    /// @param arguments The parameter list.
    /// @return result_t The return value.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    auto invoke(arguments_t&&... arguments) const -> result_t {return operator()(arguments...);}
    
    /// @brief Determines whether this instance and another specified delegateType object have the same value.
    /// @param obj The delegateType to compare.
    /// @return bool `true` if the value of this instance is the same as the value of value; otherwise, `false`.
    [[nodiscard]] auto equals(const object& obj) const noexcept -> bool override {return is<delegate>(obj) && equals(static_cast<const delegate&>(obj));}
    /// @brief Determines whether this instance and another specified delegateType object have the same value.
    /// @param other The delegateType to compare.
    /// @return bool `true` if the value of this instance is the same as the value of value; otherwise, `false`.
    [[nodiscard]] auto equals(const delegate& other) const noexcept -> bool override {
      if (data_->functions.size() != other.data_->functions.size() || data_->no_arguments_functions.size() != other.data_->no_arguments_functions.size()) return false;
      for (auto i = xtd::usize {0}; i < data_->no_arguments_functions.size(); i++)
        if (!are_equals(data_->no_arguments_functions[i], other.data_->no_arguments_functions[i])) return false;
      for (auto i = xtd::usize {0}; i < data_->functions.size(); i++)
        if (!are_equals(data_->functions[i], other.data_->functions[i])) return false;
      return true;
    }
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Concatenates the invocation lists of an array of delegates.
    /// @param delegates The array of delegates to combine.
    /// @return Delegate A new delegate with an invocation list that concatenates the invocation lists of the delegates in the delegates array. Returns null if delegates is null, if delegates contains zero elements, or if every entry in delegates is null.
    /// @remarks If the delegates array contains entries that are null, those entries are ignored.
    /// @remarks The invocation list can contain duplicate entries; that is, entries that refer to the same method on the same object.
    [[nodiscard]] static auto combine(const xtd::array<delegate>& delegates) noexcept -> delegate {
      auto result = delegate {};
      for (auto delegate : delegates) {
        for (auto function : delegate.data_->no_arguments_functions)
          result.data_->no_arguments_functions.push_back(function);
        for (auto function : delegate.data_->functions)
          result.data_->functions.push_back(function);
      }
      return result;
    }
    
    /// @brief Concatenates the invocation lists of two delegates.
    /// @param a The delegate whose invocation list comes first.
    /// @param b The delegate whose invocation list comes second.
    /// @return delegateType A new delegate with an invocation list that concatenates the invocation lists of a and b in that order. Returns a if b is null, returns b if a is a null reference, and returns a null reference if both a and b are null references.
    /// @remarks The invocation list can contain duplicate entries; that is, entries that refer to the same method on the same object.
    [[nodiscard]] static auto combine(const delegate& a, const delegate& b) noexcept -> delegate {return combine({a, b});}
    
    /// @brief removes the last occurrence of the invocation list of a delegate from the invocation list of another delegate.
    /// @param source The delegate from which to remove the invocation list of value.
    /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
    /// @return delegate A new delegate with an invocation list formed by taking the invocation list of source and removing the last occurrence of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null or if the invocation list of value is not found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source or if source is a null reference.
    /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, the last occurrence is removed.
    [[nodiscard]] static auto remove(const delegate& source, const delegate& value) noexcept -> delegate {
      auto result = source;
      std::for_each(value.data_->no_arguments_functions.begin(), value.data_->no_arguments_functions.end(), [&](const auto& no_arguments_function) {
        auto iterator = std::find_if(result.data_->no_arguments_functions.rbegin(), result.data_->no_arguments_functions.rend(), [&](const auto& item) {return are_equals(item, no_arguments_function);});
        if (iterator != result.data_->no_arguments_functions.rend()) result.data_->no_arguments_functions.erase((iterator + 1).base());
      });
      
      std::for_each(value.data_->functions.begin(), value.data_->functions.end(), [&](const auto& function) {
        auto iterator = std::find_if(result.data_->functions.rbegin(), result.data_->functions.rend(), [&](const auto& item) {return are_equals(item, function);});
        if (iterator != result.data_->functions.rend()) result.data_->functions.erase((iterator + 1).base());
      });
      return result;
    }
    
    /// @brief removes all occurrences of the invocation list of a delegate from the invocation list of another delegate.
    /// @param source The delegate from which to remove the invocation list of value.
    /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
    /// @return delegate A new delegate with an invocation list formed by taking the invocation list of source and removing all occurrences of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null or if the invocation list of value is not found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source, if source contains only a series of invocation lists that are equal to the invocation list of value, or if source is a null reference.
    /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, all occurrences are removed.
    [[nodiscard]] static auto remove_all(const delegate& source, const delegate& value) noexcept -> delegate {
      auto result = source;
      for (auto function : value.data_->no_arguments_functions) {
        if (find(result.data_->no_arguments_functions.begin(), result.data_->no_arguments_functions.end(), function) != result.data_->no_arguments_functions.end()) {
          for (typename function_collection::reverse_iterator iterator = result.data_->no_arguments_functions.rbegin(); iterator != result.data_->no_arguments_functions.rend(); ++iterator) {
            if (are_equals(*iterator, function))
              result.data_->no_arguments_functions.erase((iterator + 1).base());
          }
        }
      }
      
      for (auto function : value.data_->functions) {
        if (find(result.data_->functions.begin(), result.data_->functions.end(), function) != result.data_->functions.end()) {
          for (auto iterator = result.data_->functions.rbegin(); iterator != result.data_->functions.rend(); ++iterator) {
            if (are_equals(*iterator, function))
              result.data_->functions.erase((iterator + 1).base());
          }
        }
      }
      return result;
    }
    /// @}
    
    /// @name Operators
    
    /// @{
    /// @brief invokes the method represented by the current delegate.
    /// @param arguments The parameter list.
    /// @return result_t The return value.
    auto operator()(arguments_t... arguments) const -> result_t {
      if (data_->no_arguments_functions.size() == 0 && data_->functions.size() == 0) {
        if constexpr(std::is_void_v<result_t>) return;
        else if constexpr(std::is_reference_v<result_t>) {
          using underlying_t = std::remove_reference_t<result_t>;
          if constexpr(std::is_const_v<underlying_t>) {
            static const underlying_t empty_value{};
            return empty_value;
          } else {
            static underlying_t empty_value{};
            return empty_value;
          }
        } else return result_t{};
      }
      
      if (data_->no_arguments_functions.size()) {
        for (auto i = xtd::usize {0}; i < data_->no_arguments_functions.size() - (data_->functions.size() == 0 ? 1 : 0); i++) {
          if (data_->no_arguments_functions[i] == nullptr) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
          data_->no_arguments_functions[i]();
        }
        
        if (data_->functions.size() == 0) {
          if (data_->no_arguments_functions.back() == nullptr) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
          return data_->no_arguments_functions.back()();
        }
      }
      
      for (auto i = xtd::usize {0}; i < data_->functions.size() - 1; i++) {
        if (data_->functions[i] == nullptr) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
        data_->functions[i](arguments...);
      }
      if (data_->functions.back() == nullptr) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null);
      return data_->functions.back()(arguments...);
    }
    /// @}
    
    /// @cond
    template<class type_t>
    auto operator =(const type_t& function) noexcept -> delegate& {
      data_->no_arguments_functions.clear();
      data_->functions.clear();
      data_->functions.push_back(function_t(function));
      return *this;
    }
    
    auto operator =(const function_t& function) noexcept -> delegate& {
      data_->no_arguments_functions.clear();
      data_->functions.clear();
      data_->functions.push_back(function);
      return *this;
    }
    
    auto operator =(const no_arguments_function_t& function) noexcept -> delegate& {
      data_->no_arguments_functions.clear();
      data_->functions.clear();
      data_->no_arguments_functions.push_back(function);
      return *this;
    }
    
    auto operator +(const delegate& other) const noexcept -> delegate {
      delegate result = *this;
      result += other;
      return result;
    }
    
    auto operator +(const no_arguments_function_t& function) const noexcept -> delegate {
      delegate result = *this;
      result += function;
      return result;
    }
    
    auto operator +(const function_t& function) const noexcept -> delegate {
      delegate result = *this;
      result += function;
      return result;
    }
    
    template<class fn_t>
    auto operator +(fn_t function) const noexcept -> delegate {
      delegate result = *this;
      result += function;
      return result;
    }
    
    auto operator +=(const delegate& other) noexcept -> delegate& {
      *this = delegate::combine(*this, other);
      return *this;
    }
    
    auto operator +=(const no_arguments_function_t& function) noexcept -> delegate& {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }
    
    auto operator +=(const function_t& function) noexcept -> delegate& {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }
    
    template<class fn_t>
    auto operator +=(fn_t function) noexcept -> delegate& {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }
    
    auto operator -(const delegate& other) const noexcept -> delegate {
      delegate result = *this;
      result -= other;
      return result;
    }
    
    auto operator -(const no_arguments_function_t& function) const noexcept -> delegate {
      delegate result = *this;
      result -= function;
      return result;
    }
    
    auto operator -(const function_t& function) const noexcept -> delegate {
      delegate result = *this;
      result -= function;
      return result;
    }
    
    template<class fn_t>
    auto operator -(fn_t function) const noexcept -> delegate {
      delegate result = *this;
      result -= function;
      return result;
    }
    
    auto operator -=(const delegate& other) noexcept -> delegate& {
      *this = delegate::remove(*this, other);
      return *this;
    }
    
    auto operator -=(const no_arguments_function_t& function) noexcept -> delegate& {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    
    auto operator -=(const function_t& function) noexcept -> delegate& {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    
    template<class fn_t>
    auto operator -=(fn_t function) noexcept -> delegate& {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    /// @endcond
    
  private:
    struct delegate_async_state;
    
    [[nodiscard]] static auto are_equals(const std::function<result_t(arguments_t...)>& fct1, const std::function<result_t(arguments_t...)>& fct2) noexcept -> bool {
      return fct1.target_type() == fct2.target_type() && (fct1.template target<result_t(*)(arguments_t...)>() == fct2.template target<result_t(*)(arguments_t...)>() || *fct1.template target<result_t(*)(arguments_t...)>() == *fct2.template target<result_t(*)(arguments_t...)>());
    }
    
    [[nodiscard]] static auto are_equals(const std::function<result_t()>& fct1, const std::function<result_t()>& fct2) noexcept -> bool {
      return fct1.target_type() == fct2.target_type() && (fct1.template target<result_t(*)()>() == fct2.template target<result_t(*)()>() || *fct1.template target<result_t(*)()>() == *fct2.template target<result_t(*)()>());
    }
    
    [[nodiscard]] static auto find(typename no_arguments_function_collection::const_iterator begin, typename no_arguments_function_collection::const_iterator end, const no_arguments_function_t& function) noexcept -> typename no_arguments_function_collection::const_iterator {
      auto iterator = std::find_if(begin, end, [&](const auto& item) {return are_equals(item, function);});
      if (iterator != end) return iterator;
      return end;
    }
    
    [[nodiscard]] static auto find(typename function_collection::const_iterator begin, typename function_collection::const_iterator end, const function_t& function) noexcept -> typename function_collection::const_iterator {
      auto iterator = std::find_if(begin, end, [&](const auto& item) {return are_equals(item, function);});
      if (iterator != end) return iterator;
      return end;
    }
    
    xtd::sptr<data> data_ = xtd::new_sptr<data>();
  };
}

/// @brief The declaration of a delegate type is similar to a method signature. It has a return value and any number of parameters of any type
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @par Examples
/// @code
/// button.click += delegate_(const object& sender, const event_args& e) {
///   message_box::show("Button click!", "Message", message_box_buttons::ok);
/// };
/// @endcode
#define delegate_ \
  [&]

// Required for begin_invoke and end_invoke methods implementation.
#include "threading/thread_pool.hpp"
