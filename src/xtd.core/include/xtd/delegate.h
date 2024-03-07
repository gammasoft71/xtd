/// @file
/// @brief Contains xtd::delegate delegate.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "any.h"
#include "argument_null_exception.h"
#include "async_result.h"
#include "iequatable.h"
#include "object.h"
#include "object_ref.h"
#include <functional>
#include <stdexcept>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  template<typename result_t>
  class delegate;
  
  template<typename result_t, typename... arguments_t>
  class delegate<result_t(arguments_t...)>;
  /// @endcond

  /// @brief References a method to be called when a corresponding asynchronous operation completes.
  /// @param ar The result of the asynchronous operation.
  /// @par Header
  /// @code #include <xtd/async_callback> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  using async_callback = delegate<void(async_result ar)>;

  /// @brief Represents a delegate, which is a data structure that refers to a static method or to a class instance && an instance method of that class.
  /// @par Header
  /// @code #include <xtd/delegate> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks For more info about delegates see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/delegates">Delegates</a> guide.
  /// @par Examples
  /// The following example shows how to define a delegate named my Method delegate. Instances of this delegate are created for an instance method && a static method of the nested mySampleClass class. The delegate for the instance method requires an instance of mySampleClass. The mySampleClass instance is saved in a variable named mySC.
  /// @include delegate.cpp
  template<typename result_t>
  class delegate<result_t()> : public xtd::object, public xtd::iequatable<delegate<result_t()>> {
    struct data {
      std::vector<std::function <result_t()>> functions;
    };
    
    class async_result_invoke : public xtd::iasync_result {
      struct data;
    public:
      async_result_invoke(xtd::async_callback async_callback, std::any async_state);
      std::any async_state() const noexcept override;
      xtd::threading::wait_handle& async_wait_handle() noexcept override;
      bool completed_synchronously() const noexcept override;
      bool is_completed() const noexcept override;
      
      std::shared_ptr<data> data_;
    };

  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief function_t pointer type
    using function_t = std::function <result_t()>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes an empty delegate.
    delegate() = default;
    /// @brief Initializes a delegate that invokes the specified delegate instance.
    /// @param delegate The delegate instance.
    delegate(const delegate& delegate) noexcept {
      data_->functions = delegate.data_->functions;
    }
    /// @cond
    delegate(const function_t& function) noexcept {data_->functions.push_back(function);} // Can't be explicit by design.
    delegate& operator =(const delegate& delegate) noexcept {
      data_->functions = delegate.data_->functions;
      return *this;
    }
    /// @endcond
    
    /// @brief Initializes a delegate that invokes the specified instance method on the specified class instance.
    /// @param object the class instance.
    /// @param function the method instance.
    template<typename object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)() const) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));
    }
    /// @brief Initializes a delegate that invokes the specified instance method on the specified class instance.
    /// @param object the class instance.
    /// @param function the method instance.
    template<typename object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)()) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));
    }
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the delegates array
    /// @return The delegates array.
    const std::vector<function_t>& functions() const {return data_->functions;}
    
    /// @brief Return if the delegate is empty.
    /// @return bool Return true if delegate is empty; otherwise false.
    bool is_empty() const noexcept {return data_->functions.size() == 0;}
    
    /// @brief Return the size of invocation list.
    /// @return Return the size of invocation list.
    size_t size() const noexcept {return data_->functions.size();}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Clear delegates array.
    void clear() {data_->functions.clear();}

    /// @brief Executes the method represented by the current delegate asynchronously on the thread that the control's underlying handle was created on.
    /// @return An async_result_invoke that represents the result of the begin_invoke operation.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    async_result begin_invoke();
    /// @brief Executes the method represented by the current delegate asynchronously on the thread that the control's underlying handle was created on.
    /// @param async_callback The asynchronous callback that will be called at the end of the invocation.
    /// @return An async_result_invoke that represents the result of the begin_invoke operation.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    async_result begin_invoke(xtd::async_callback async_callback);
    /// @brief Executes the method represented by the current delegate asynchronously on the thread that the control's underlying handle was created on.
    /// @param async_callback The asynchronous callback that will be called at the end of the invocation.
    /// @param async_state The asynchronous state associated with the invocation.
    /// @return An async_result_invoke that represents the result of the begin_invoke operation.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    async_result begin_invoke(xtd::async_callback async_callback, std::any async_state);

    /// @brief Retrieves the return value of the asynchronous operation represented by the async_result_invoke passed.
    /// @param async The async_result_invoke that represents a specific invoke asynchronous operation, returned when calling begin_invoke.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    result_t end_invoke(async_result async);

    /// @brief invokes the method represented by the current delegate.
    /// @param arguments The parameter list.
    /// @return result_t The return value.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    result_t invoke() const {return operator()();}
    
    /// @brief Determines whether this instance and another specified delegateType object have the same value.
    /// @param value The delegateType to compare.
    /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
    bool equals(const delegate& delegate) const noexcept override {
      if (data_->functions.size() != delegate.data_->functions.size())
        return false;
      
      for (size_t i = 0; i < data_->functions.size(); i++)
        if (!are_equals(data_->functions[i], delegate.data_->functions[i]))
          return false;
      
      return true;
    }
    /// @}

    /// @name Public Static Methods
    
    /// @{
    /// @brief Concatenates the invocation lists of an array of delegates.
    /// @param delegates The array of delegates to combine.
    /// @return Delegate A new delegate with an invocation list that concatenates the invocation lists of the delegates in the delegates array. Returns null if delegates is null, if delegates contains zero elements, || if every entry in delegates is null.
    /// @remarks If the delegates array contains entries that are null, those entries are ignored.
    /// @remarks The invocation list can contain duplicate entries; that is, entries that refer to the same method on the same object.
    static delegate combine(const std::vector<delegate>& delegates) noexcept {
      delegate result;
      for (const delegate& delegate : delegates) {
        for (const function_t& function : delegate.data_->functions)
          result.data_->functions.push_back(function);
      }
      return result;
    }
    
    /// @brief Concatenates the invocation lists of two delegates.
    /// @param a The delegate whose invocation list comes first.
    /// @param b The delegate whose invocation list comes second.
    /// @return delegateType A new delegate with an invocation list that concatenates the invocation lists of a and b in that order. Returns a if b is null, returns b if a is a null reference, and returns a null reference if both a and b are null references.
    /// @remarks The invocation list can contain duplicate entries; that is, entries that refer to the same method on the same object.
    static delegate combine(const delegate& a, const delegate& b) noexcept {
      delegate result =  a;
      for (const function_t& function : b.data_->functions)
        result.data_->functions.push_back(function);
      return result;
    }
    
    /// @brief removes the last occurrence of the invocation list of a delegate from the invocation list of another delegate.
    /// @param source The delegate from which to remove the invocation list of value.
    /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
    /// @return delegate A new delegate with an invocation list formed by taking the invocation list of source and removing the last occurrence of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null || if the invocation list of value is ! found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source || if source is a null reference.
    /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, the last occurrence is removed.
    static delegate remove(const delegate& source, const delegate& value) noexcept {
      delegate result = source;
      std::for_each(value.data_->functions.begin(), value.data_->functions.end(), [&](auto function) {
        auto iterator = std::find_if(result.data_->functions.rbegin(), result.data_->functions.rend(), [&](auto item) {return are_equals(item, function);});
        if (iterator != result.data_->functions.rend()) result.data_->functions.erase((iterator + 1).base());
      });
      return result;
    }
    
    /// @brief removes all occurrences of the invocation list of a delegate from the invocation list of another delegate.
    /// @param source The delegate from which to remove the invocation list of value.
    /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
    /// @return delegate A new delegate with an invocation list formed by taking the invocation list of source && removing all occurrences of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null || if the invocation list of value is ! found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source, if source contains only a series of invocation lists that are equal to the invocation list of value, || if source is a null reference.
    /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, all occurrences are removed.
    static delegate remove_all(const delegate& source, const delegate& value) noexcept {
      delegate result = source;
      for (const function_t& function : value.data_->functions) {
        if (find(result.data_->functions.begin(), result.data_->functions.end(), function) != result.data_->functions.end()) {
          for (typename std::vector<function_t>::reverse_iterator iterator = result.data_->functions.rbegin(); iterator != result.data_->functions.rend(); ++iterator) {
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
    result_t operator()() const {
      if (data_->functions.size() == 0) return result_t();
      
      for (size_t i = 0; i < data_->functions.size() - 1; i++) {
        if (data_->functions[i] == nullptr) throw xtd::argument_null_exception {csf_};
        data_->functions[i]();
      }
      if (data_->functions.back() == nullptr) throw xtd::argument_null_exception {csf_};
      return data_->functions.back()();
    }
    
    delegate& operator =(const function_t& function) noexcept {
      data_->functions.clear();
      data_->functions.push_back(function);
      return *this;
    }
    /// @}
    
    /// @cond
    delegate operator +(const delegate& other) noexcept {
      delegate result = *this;
      result += other;
      return result;
    }
    
    delegate operator +(const function_t& function) noexcept {
      delegate result = *this;
      result += function;
      return result;
    }
    
    template<typename fn_t>
    delegate operator +(fn_t function) noexcept {
      delegate result = *this;
      result += function;
      return result;
    }

    delegate& operator +=(const delegate& delegate) noexcept {
      *this = delegate::combine(*this, delegate);
      return *this;
    }
    
    delegate& operator +=(const function_t& function) noexcept {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }
    
    template<typename fn_t>
    delegate& operator +=(fn_t function) noexcept {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }

    delegate operator -(const delegate& other) noexcept {
      delegate result = *this;
      result -= other;
      return result;
    }
    
    delegate operator -(const function_t& function) noexcept {
      delegate result = *this;
      result -= function;
      return result;
    }
    
    template<typename fn_t>
    delegate operator -(fn_t function) noexcept {
      delegate result = *this;
      result -= function;
      return result;
    }

    delegate& operator -=(const delegate& delegate) noexcept {
      *this = delegate::remove(*this, delegate);
      return *this;
    }
    
    delegate& operator -=(const function_t& function) noexcept {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    
    template<typename fn_t>
    delegate& operator -=(fn_t function) noexcept {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    /// @endcond
    
  private:
    static bool are_equals(const std::function<result_t()>& fct1, const std::function<result_t()>& fct2) noexcept {
      return fct1.target_type() == fct2.target_type() && (fct1.template target<result_t(*)()>() == fct2.template target<result_t(*)()>() || *fct1.template target<result_t(*)()>() == *fct2.template target<result_t(*)()>());
    }
    
    static typename std::vector<function_t>::const_iterator find(typename std::vector<function_t>::const_iterator begin, typename std::vector<function_t>::const_iterator end, const function_t& function) noexcept {
      auto iterator = std::find_if(begin, end, [&](auto item) {return are_equals(item, function);});
      if (iterator != end) return iterator;
      return end;
    }
    std::shared_ptr<data> data_ = std::make_shared<data>();
  };
  
  /// @brief Represents a delegate, which is a data structure that refers to a static method or to a class instance && an instance method of that class.
  /// @par Header
  /// @code #include <xtd/delegate> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks For more info about delegates see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/delegates">Delegates</a> guide.
  /// @par Examples
  /// The following example shows how to define a delegate named my Method delegate. Instances of this delegate are created for an instance method && a static method of the nested mySampleClass class. The delegate for the instance method requires an instance of mySampleClass. The mySampleClass instance is saved in a variable named mySC.
  /// @include delegate.cpp
  template<typename result_t, typename... arguments_t>
  class delegate<result_t(arguments_t...)> : public object, public xtd::iequatable<delegate<result_t(arguments_t...)>> {
    struct data {
      std::vector<std::function <result_t()>> no_arguments_functions;
      std::vector<std::function <result_t(arguments_t...)>> functions;
    };
    
    class async_result_invoke : public xtd::iasync_result {
      struct data;
    public:
      async_result_invoke(xtd::async_callback async_callback, std::any async_state);
      std::any async_state() const noexcept override;
      xtd::threading::wait_handle& async_wait_handle() noexcept override;
      bool completed_synchronously() const noexcept override;
      bool is_completed() const noexcept override;
      
      std::shared_ptr<data> data_;
    };

  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief no_arguments_function_t pointer type
    using no_arguments_function_t = std::function <result_t()>;
    /// @brief function_t pointer type
    using function_t = std::function <result_t(arguments_t...)>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes an empty delegate.
    delegate() = default;
    /// @brief Initializes a delegate that invokes the specified delegate instance.
    /// @param delegate The delegate instance.
    delegate(const delegate& delegate) noexcept {
      data_->no_arguments_functions = delegate.data_->no_arguments_functions;
      data_->functions = delegate.data_->functions;
    }
    /// @cond
    delegate& operator =(const delegate& delegate) noexcept {
      data_->no_arguments_functions = delegate.data_->no_arguments_functions;
      data_->functions = delegate.data_->functions;
      return *this;
    }
    delegate(const delegate<result_t()>& delegate) noexcept {
      data_->no_arguments_functions = delegate.functions();
    }
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
    template<typename object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)() const) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));
    }
    
    /// @brief Initializes a delegate that invokes the specified instance method on the specified class instance.
    /// @param object the class instance.
    /// @param function the method instance.
    template<typename object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)()) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));
    }
    /// @}
    
    /// @cond
    template<typename object1_t, typename object2_t, typename a1_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t) const) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t)) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t) const) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t)) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t) const) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t)) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t) const) {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t)) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5) const) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5)) {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t) const) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t)) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t) const) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t)) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t) const) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t)) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t, typename a9_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t, a9_t) const) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t, typename a9_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t, a9_t)) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t, typename a9_t, typename a10_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t, a9_t, a10_t) const) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10)));
    }
    
    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t, typename a9_t, typename a10_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t, a9_t, a10_t)) noexcept {
      data_->functions.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10)));
    }
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the no arguments delegates array
    /// @return The delegates array.
    const std::vector<no_arguments_function_t>& no_arguments_functions() const {return data_->no_arguments_functions;}
    
    /// @brief Gets the delegates array
    /// @return The delegates array.
    const std::vector<function_t>& functions() const {return data_->functions;}
    
    /// @brief Return if the delegate is empty.
    /// @return bool Return true if delegate is empty; otherwise false.
    bool is_empty() const noexcept {return data_->functions.size() == 0 && data_->no_arguments_functions.size() == 0;}
    
    /// @brief Return the size of invocation list.
    /// @return Return the size of invocation list.
    size_t size() const noexcept {return data_->functions.size() + data_->no_arguments_functions.size();}
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
    async_result begin_invoke(arguments_t... arguments);
    /// @brief Executes the method represented by the current delegate asynchronously on the thread that the control's underlying handle was created on.
    /// @param async_callback The asynchronous callback that will be called at the end of the invocation.
    /// @param arguments The parameter list.
    /// @return An async_result_invoke that represents the result of the begin_invoke operation.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    async_result begin_invoke(xtd::async_callback async_callback, arguments_t... arguments);
    /// @brief Executes the method represented by the current delegate asynchronously on the thread that the control's underlying handle was created on.
    /// @param arguments The parameter list.
    /// @return An async_result_invoke that represents the result of the begin_invoke operation.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    async_result begin_invoke(xtd::async_callback async_callback, std::any async_state, arguments_t... arguments);
        
    /// @brief Retrieves the return value of the asynchronous operation represented by the async_result_invoke passed.
    /// @param async The async_result_invoke that represents a specific invoke asynchronous operation, returned when calling begin_invoke.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    result_t end_invoke(async_result async);

    /// @brief invokes the method represented by the current delegate.
    /// @param arguments The parameter list.
    /// @return result_t The return value.
    /// @par Examples
    /// The following examples shows hot tu use xtd::delegate::begin_invoke, xtd::delegate::end_invoke, xtd::delegate::invoke methods.
    /// @include delegate_begin_invoke.cpp
    result_t invoke(arguments_t... arguments) const {return operator()(arguments...);}
    
    /// @brief Determines whether this instance and another specified delegateType object have the same value.
    /// @param value The delegateType to compare.
    /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
    bool equals(const delegate& delegate) const noexcept override {
      if (data_->functions.size() != delegate.data_->functions.size() || data_->no_arguments_functions.size() != delegate.data_->no_arguments_functions.size())
        return false;
      
      for (size_t i = 0; i < data_->no_arguments_functions.size(); i++)
        if (!are_equals(data_->no_arguments_functions[i], delegate.data_->no_arguments_functions[i]))
          return false;
      
      for (size_t i = 0; i < data_->functions.size(); i++)
        if (!are_equals(data_->functions[i], delegate.data_->functions[i]))
          return false;
      
      return true;
    }
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Concatenates the invocation lists of an array of delegates.
    /// @param delegates The array of delegates to combine.
    /// @return Delegate A new delegate with an invocation list that concatenates the invocation lists of the delegates in the delegates array. Returns null if delegates is null, if delegates contains zero elements, || if every entry in delegates is null.
    /// @remarks If the delegates array contains entries that are null, those entries are ignored.
    /// @remarks The invocation list can contain duplicate entries; that is, entries that refer to the same method on the same object.
    static delegate combine(const std::vector<delegate>& delegates) noexcept {
      delegate result;
      for (const delegate& delegate : delegates) {
        for (const no_arguments_function_t& function : delegate.data_->no_arguments_functions)
          result.data_->no_arguments_functions.push_back(function);
        for (const function_t& function : delegate.data_->functions)
          result.data_->functions.push_back(function);
      }
      return result;
    }
    
    /// @brief Concatenates the invocation lists of two delegates.
    /// @param a The delegate whose invocation list comes first.
    /// @param b The delegate whose invocation list comes second.
    /// @return delegateType A new delegate with an invocation list that concatenates the invocation lists of a and b in that order. Returns a if b is null, returns b if a is a null reference, and returns a null reference if both a and b are null references.
    /// @remarks The invocation list can contain duplicate entries; that is, entries that refer to the same method on the same object.
    static delegate combine(const delegate& a, const delegate& b) noexcept {
      delegate result =  a;
      for (const no_arguments_function_t& function : b.data_->no_arguments_functions)
        result.data_->no_arguments_functions.push_back(function);
      for (const function_t& function : b.data_->functions)
        result.data_->functions.push_back(function);
      return result;
    }
    
    /// @brief removes the last occurrence of the invocation list of a delegate from the invocation list of another delegate.
    /// @param source The delegate from which to remove the invocation list of value.
    /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
    /// @return delegate A new delegate with an invocation list formed by taking the invocation list of source and removing the last occurrence of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null || if the invocation list of value is ! found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source || if source is a null reference.
    /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, the last occurrence is removed.
    static delegate remove(const delegate& source, const delegate& value) noexcept {
      delegate result = source;
      std::for_each(value.data_->no_arguments_functions.begin(), value.data_->no_arguments_functions.end(), [&](auto no_arguments_function) {
        auto iterator = std::find_if(result.data_->no_arguments_functions.rbegin(), result.data_->no_arguments_functions.rend(), [&](auto item) {return are_equals(item, no_arguments_function);});
        if (iterator != result.data_->no_arguments_functions.rend()) result.data_->no_arguments_functions.erase((iterator + 1).base());
      });
      
      std::for_each(value.data_->functions.begin(), value.data_->functions.end(), [&](auto function) {
        auto iterator = std::find_if(result.data_->functions.rbegin(), result.data_->functions.rend(), [&](auto item) {return are_equals(item, function);});
        if (iterator != result.data_->functions.rend()) result.data_->functions.erase((iterator + 1).base());
      });
      return result;
    }
    
    /// @brief removes all occurrences of the invocation list of a delegate from the invocation list of another delegate.
    /// @param source The delegate from which to remove the invocation list of value.
    /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
    /// @return delegate A new delegate with an invocation list formed by taking the invocation list of source && removing all occurrences of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null || if the invocation list of value is ! found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source, if source contains only a series of invocation lists that are equal to the invocation list of value, || if source is a null reference.
    /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, all occurrences are removed.
    static delegate remove_all(const delegate& source, const delegate& value) noexcept {
      delegate result = source;
      for (const no_arguments_function_t& function : value.data_->no_arguments_functions) {
        if (find(result.data_->no_arguments_functions.begin(), result.data_->no_arguments_functions.end(), function) != result.data_->no_arguments_functions.end()) {
          for (typename std::vector<function_t>::reverse_iterator iterator = result.data_->no_arguments_functions.rbegin(); iterator != result.data_->no_arguments_functions.rend(); ++iterator) {
            if (are_equals(*iterator, function))
              result.data_->no_arguments_functions.erase((iterator + 1).base());
          }
        }
      }
      
      for (const function_t& function : value.data_->functions) {
        if (find(result.data_->functions.begin(), result.data_->functions.end(), function) != result.data_->functions.end()) {
          for (typename std::vector<function_t>::reverse_iterator iterator = result.data_->functions.rbegin(); iterator != result.data_->functions.rend(); ++iterator) {
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
    result_t operator()(arguments_t... arguments) const {
      if (data_->no_arguments_functions.size() == 0 && data_->functions.size() == 0) return result_t();
      
      if (data_->no_arguments_functions.size()) {
        for (size_t i = 0; i < data_->no_arguments_functions.size() - (data_->functions.size() == 0 ? 1 : 0); i++) {
          if (data_->no_arguments_functions[i] == nullptr) throw xtd::argument_null_exception {csf_};
          data_->no_arguments_functions[i]();
        }
        
        if (data_->functions.size() == 0) {
          if (data_->no_arguments_functions.back() == nullptr) throw xtd::argument_null_exception {csf_};
          return data_->no_arguments_functions.back()();
        }
      }
      
      for (size_t i = 0; i < data_->functions.size() - 1; i++) {
        if (data_->functions[i] == nullptr) throw xtd::argument_null_exception {csf_};
        data_->functions[i](arguments...);
      }
      if (data_->functions.back() == nullptr) throw xtd::argument_null_exception {csf_};
      return data_->functions.back()(arguments...);
    }
    /// @}
    
    /// @cond
    template<typename type_t>
    delegate& operator =(const type_t& function) noexcept {
      data_->no_arguments_functions.clear();
      data_->functions.clear();
      data_->functions.push_back(function_t(function));
      return *this;
    }
    
    delegate& operator =(const function_t& function) noexcept {
      data_->no_arguments_functions.clear();
      data_->functions.clear();
      data_->functions.push_back(function);
      return *this;
    }
    
    delegate& operator =(const no_arguments_function_t& function) noexcept {
      data_->no_arguments_functions.clear();
      data_->functions.clear();
      data_->no_arguments_functions.push_back(function);
      return *this;
    }
    
    delegate operator +(const delegate& other) noexcept {
      delegate result = *this;
      result += other;
      return result;
    }
    
    delegate operator +(const no_arguments_function_t& function) noexcept {
      delegate result = *this;
      result += function;
      return result;
    }
    
    delegate operator +(const function_t& function) noexcept {
      delegate result = *this;
      result += function;
      return result;
    }
    
    template<typename fn_t>
    delegate operator +(fn_t function) noexcept {
      delegate result = *this;
      result += function;
      return result;
    }
    
    delegate& operator +=(const delegate& delegate) noexcept {
      *this = delegate::combine(*this, delegate);
      return *this;
    }
    
    delegate& operator +=(const no_arguments_function_t& function) noexcept {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }
    
    delegate& operator +=(const function_t& function) noexcept {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }
    
    template<typename fn_t>
    delegate& operator +=(fn_t function) noexcept {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }
    
    delegate operator -(const delegate& other) noexcept {
      delegate result = *this;
      result -= other;
      return result;
    }
    
    delegate operator -(const no_arguments_function_t& function) noexcept {
      delegate result = *this;
      result -= function;
      return result;
    }
    
    delegate operator -(const function_t& function) noexcept {
      delegate result = *this;
      result -= function;
      return result;
    }
    
    template<typename fn_t>
    delegate operator -(fn_t function) noexcept {
      delegate result = *this;
      result -= function;
      return result;
    }
    
    delegate& operator -=(const delegate& delegate) noexcept {
      *this = delegate::remove(*this, delegate);
      return *this;
    }
    
    delegate& operator -=(const no_arguments_function_t& function) noexcept {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    
    delegate& operator -=(const function_t& function) noexcept {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    
    template<typename fn_t>
    delegate& operator -=(fn_t function) noexcept {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    /// @endcond
    
  private:
    static bool are_equals(const std::function<result_t(arguments_t...)>& fct1, const std::function<result_t(arguments_t...)>& fct2) noexcept {
      return fct1.target_type() == fct2.target_type() && (fct1.template target<result_t(*)(arguments_t...)>() == fct2.template target<result_t(*)(arguments_t...)>() || *fct1.template target<result_t(*)(arguments_t...)>() == *fct2.template target<result_t(*)(arguments_t...)>());
    }
    
    static bool are_equals(const std::function<result_t()>& fct1, const std::function<result_t()>& fct2) noexcept {
      return fct1.target_type() == fct2.target_type() && (fct1.template target<result_t(*)()>() == fct2.template target<result_t(*)()>() || *fct1.template target<result_t(*)()>() == *fct2.template target<result_t(*)()>());
    }
    
    static typename std::vector<no_arguments_function_t>::const_iterator find(typename std::vector<no_arguments_function_t>::const_iterator begin, typename std::vector<no_arguments_function_t>::const_iterator end, const no_arguments_function_t& function) noexcept {
      auto iterator = std::find_if(begin, end, [&](auto item) {return are_equals(item, function);});
      if (iterator != end) return iterator;
      return end;
    }
    
    static typename std::vector<function_t>::const_iterator find(typename std::vector<function_t>::const_iterator begin, typename std::vector<function_t>::const_iterator end, const function_t& function) noexcept {
      auto iterator = std::find_if(begin, end, [&](auto item) {return are_equals(item, function);});
      if (iterator != end) return iterator;
      return end;
    }
    
    std::shared_ptr<data> data_ = std::make_shared<data>();
  };
}

// Required for begin_invoke and end_invoke methods implementation.
#include "threading/thread_pool.h"
