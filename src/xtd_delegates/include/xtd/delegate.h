#pragma once

#include <functional>
#include <memory>
#include <stdexcept>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  template<typename result_t>
  class delegate;

  template<typename result_t>
  class delegate<result_t()> {
  public:
    using function_t = std::function <result_t()>;
    
    delegate() = default;
    delegate(const delegate& delegate) noexcept : functions_(delegate.functions_) {}
    delegate(const function_t& function) noexcept { this->functions_.push_back(function); }
    
    template<typename object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)() const) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));
    }

    template<typename object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)()) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));
    }

    result_t operator()() const {
      if (this->functions_.size() == 0) return result_t();
      
      for (size_t i = 0; i < this->functions_.size() - 1; i++) {
        if (this->functions_[i] == nullptr) throw std::invalid_argument("function null");
        this->functions_[i]();
      }
      if (this->functions_.back() == nullptr) throw std::invalid_argument("function null");
      return this->functions_.back()();
    }

    const std::vector<function_t>& functions() const {return this->functions_;}
    
    void clear() {this->functions_.clear();}

    result_t invoke() const { return this->operator()(); }
    
    static delegate combine(const std::vector<delegate>& delegates) noexcept {
      delegate result;
      for (const delegate& delegate : delegates) {
        for (const function_t& function : delegate.functions_)
          result.functions_.push_back(function);
      }
      return result;
    }
    
    static delegate combine(const delegate& a, const delegate& b) noexcept {
      delegate result =  a;
      for (const function_t& function : b.functions_)
        result.functions_.push_back(function);
      return result;
    }
    
    bool is_empty() const noexcept { return this->functions_.size() == 0; }
    
    static delegate remove(const delegate& source, const delegate& value) noexcept {
      delegate result = source;
      for (const function_t& function : value.functions_) {
        if (find(result.functions_.begin(), result.functions_.end(), function) != result.functions_.end()) {
          for (typename std::vector<function_t>::reverse_iterator iterator = result.functions_.rbegin(); iterator != result.functions_.rend(); ++iterator) {
            if (are_equals(*iterator, function)) {
              result.functions_.erase((iterator + 1).base());
              break;
            }
          }
        }
      }
      return result;
    }
    
    static delegate remove_all(const delegate& source, const delegate& value) noexcept {
      delegate result = source;
      for (const function_t& function : value.functions_) {
        if (find(result.functions_.begin(), result.functions_.end(), function) != result.functions_.end()) {
          for (typename std::vector<function_t>::reverse_iterator iterator = result.functions_.rbegin(); iterator != result.functions_.rend(); ++iterator) {
            if (are_equals(*iterator, function)) {
              result.functions_.erase((iterator + 1).base());
            }
          }
        }
      }
      return result;
    }
    
    bool operator ==(const delegate& delegate) const noexcept {
      if (this->functions_.size() != delegate.functions_.size())
        return false;
      
      for (size_t i = 0; i < this->functions_.size(); i++)
        if (!are_equals(this->functions_[i], delegate.functions_[i]))
          return false;
      
      return true;
    }
    
    bool operator !=(const delegate& delegate) const { return !this->operator==(delegate); }
    
    delegate& operator=(const function_t& function) noexcept {
      this->functions_.push_back(function);
      return *this;
    }
    
    delegate& operator+=(const delegate& delegate) noexcept {
      *this = delegate::combine(*this, delegate);
      return *this;
    }
    
    delegate& operator+=(const function_t& function) noexcept {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }
    
    delegate& operator-=(const delegate& delegate) noexcept {
      *this = delegate::remove(*this, delegate);
      return *this;
    }
    
    delegate& operator-=(const function_t& function) noexcept {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    
    template<typename fn_t>
    delegate& operator-=(fn_t function) noexcept {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }
    
  private:
    static bool are_equals(const std::function<result_t()>& fct1, const std::function<result_t()>& fct2) noexcept {
      return fct1.target_type() == fct2.target_type() && (fct1.template target<result_t(*)()>() == fct2.template target<result_t(*)()>() || *fct1.template target<result_t(*)()>() == *fct2.template target<result_t(*)()>());
    }
    
    static typename std::vector<function_t>::const_iterator find(typename std::vector<function_t>::const_iterator begin, typename std::vector<function_t>::const_iterator end, const function_t& function) noexcept {
      for (typename std::vector<function_t>::const_iterator iterator = begin; iterator != end; ++iterator)
        if (are_equals(*iterator, function))
          return iterator;
      return end;
    }
    
    std::vector<function_t> functions_;
  };
  /// @endcond
  
  /// @brief Represents a delegate, which is a data structure that refers to a static method or to a class instance && an instance method of that class.
  /// The following example shows how to define a delegate named myMethoddelegate. Instances of this delegate are created for an instance method && a static method of the nested mySampleClass class. The delegate for the instance method requires an instance of mySampleClass. The mySampleClass instance is saved in a variable named mySC.
  /// @include delegate.cpp
  template<typename result_t, typename... arguments_t>
  class delegate<result_t(arguments_t...)> {
  public:
    /// @brief function_t pointer type
    using no_arguments_function_t = std::function <result_t()>;
    using function_t = std::function <result_t(arguments_t...)>;

    /// @brief Initializes an empty delegate.
    delegate() = default;

    /// @brief Initializes a delegate that invokes the specified delegate instance.
    /// @param delegate The delegate instance.
    delegate(const delegate& delegate) noexcept : no_arguments_functions_(delegate.no_arguments_functions_), functions_(delegate.functions_) {}

    /// @brief Initializes a delegate that invokes the specified instance method.
    /// @param function the method instance.
    delegate(const function_t& function) noexcept { this->functions_.push_back(function); }

    /// @cond
    delegate(const no_arguments_function_t& function) noexcept { this->no_arguments_functions_.push_back(function); }
    /// @endcond

    /// @brief Initializes a delegate that invokes the specified instance method on the specified class instance.
    /// @param object the class instance.
    /// @param function the method instance.
    template<typename object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)() const) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));
    }

    /// @brief Initializes a delegate that invokes the specified instance method on the specified class instance.
    /// @param object the class instance.
    /// @param function the method instance.
    template<typename object1_t, typename object2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)()) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object))));
    }

    /// @cond
    template<typename object1_t, typename object2_t, typename a1_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t) const) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1)));
    }

    template<typename object1_t, typename object2_t, typename a1_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t)) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t) const) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t)) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t) const) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t)) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t) const) {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t)) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5) const) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5)) {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t) const) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t)) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t) const) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t)) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t) const) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t)) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t, typename a9_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t, a9_t) const) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t, typename a9_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t, a9_t)) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t, typename a9_t, typename a10_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t, a9_t, a10_t) const) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10)));
    }

    template<typename object1_t, typename object2_t, typename a1_t, typename a2_t, typename a3_t, typename a4_t, typename A5, typename a6_t, typename a7_t, typename a8_t, typename a9_t, typename a10_t>
    delegate(const object1_t& object, result_t(object2_t::*method)(a1_t, a2_t, a3_t, a4_t, A5, a6_t, a7_t, a8_t, a9_t, a10_t)) noexcept {
      this->functions_.push_back(function_t(std::bind(method, const_cast<object1_t*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10)));
    }
    /// @endcond

    /// @brief invokes the method represented by the current delegate.
    /// @param arguments The paramter list.
    /// @return result_t The return value.
    result_t operator()(arguments_t... arguments) const {
      if (this->no_arguments_functions_.size() == 0 && this->functions_.size() == 0) return result_t();

      if (this->no_arguments_functions_.size()) {
        for (size_t i = 0; i < this->no_arguments_functions_.size() - (this->functions_.size() == 0 ? 1 : 0); i++) {
          if (this->no_arguments_functions_[i] == nullptr) throw std::invalid_argument("function null");
          this->no_arguments_functions_[i]();
        }
        
        if (this->functions_.size() == 0) {
          if (this->no_arguments_functions_.back() == nullptr) throw std::invalid_argument("function null");
          return this->no_arguments_functions_.back()();
        }
      }

      for (size_t i = 0; i < this->functions_.size() - 1; i++) {
        if (this->functions_[i] == nullptr) throw std::invalid_argument("function null");
        this->functions_[i](arguments...);
      }
      if (this->functions_.back() == nullptr) throw std::invalid_argument("function null");
      return this->functions_.back()(arguments...);
    }
    
    const std::vector<no_arguments_function_t>& no_arguments_functions() const {return this->no_arguments_functions_;}
    
    const std::vector<function_t>& functions() const {return this->functions_;}
    
    void clear() {
      this->no_arguments_functions_.clear();
      this->functions_.clear();
    }
    
    /// @brief invokes the method represented by the current delegate.
    /// @param arguments The paramter list.
    /// @return result_t The return value.
    result_t invoke(arguments_t... arguments) const { return this->operator()(arguments...); }

    /// @brief Concatenates the invocation lists of an array of delegates.
    /// @param delagates The array of delegates to combine.
    /// @return Delegte A new delegate with an invocation list that concatenates the invocation lists of the delegates in the delegates array. Returns null if delegates is null, if delegates contains zero elements, || if every entry in delegates is null.
    /// @remarks If the delegates array contains entries that are null, those entries are ignored.
    /// @remarks The invocation list can contain duplicate entries; that is, entries that refer to the same method on the same object.
    static delegate combine(const std::vector<delegate>& delegates) noexcept {
      delegate result;
      for (const delegate& delegate : delegates) {
        for (const no_arguments_function_t& function : delegate.no_arguments_functions_)
          result.no_arguments_functions_.push_back(function);
        for (const function_t& function : delegate.functions_)
          result.functions_.push_back(function);
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
      for (const no_arguments_function_t& function : b.no_arguments_functions_)
        result.no_arguments_functions_.push_back(function);
      for (const function_t& function : b.functions_)
        result.functions_.push_back(function);
      return result;
    }

    /// @brief Return if the delegate is empty.
    /// @return bool Return true if delegate is empty; otherwhise false.
    bool is_empty() const noexcept { return this->functions_.size() == 0 && this->no_arguments_functions_.size() == 0; }

    /// @brief removes the last occurrence of the invocation list of a delegate from the invocation list of another delegate.
    /// @param source The delegate from which to remove the invocation list of value.
    /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
    /// @return delegate A new delegate with an invocation list formed by taking the invocation list of source and removing the last occurrence of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null || if the invocation list of value is ! found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source || if source is a null reference.
    /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, the last occurrence is removed.
    static delegate remove(const delegate& source, const delegate& value) noexcept {
      delegate result = source;
      for (const no_arguments_function_t& function : value.no_arguments_functions_) {
        if (find(result.no_arguments_functions_.begin(), result.no_arguments_functions_.end(), function) != result.no_arguments_functions_.end()) {
          for (typename std::vector<no_arguments_function_t>::reverse_iterator iterator = result.no_arguments_functions_.rbegin(); iterator != result.no_arguments_functions_.rend(); ++iterator) {
            if (are_equals(*iterator, function)) {
              result.no_arguments_functions_.erase((iterator + 1).base());
              break;
            }
          }
        }
      }

      for (const function_t& function : value.functions_) {
        if (find(result.functions_.begin(), result.functions_.end(), function) != result.functions_.end()) {
          for (typename std::vector<function_t>::reverse_iterator iterator = result.functions_.rbegin(); iterator != result.functions_.rend(); ++iterator) {
            if (are_equals(*iterator, function)) {
              result.functions_.erase((iterator + 1).base());
              break;
            }
          }
        }
      }
      return result;
    }

    /// @brief removes all occurrences of the invocation list of a delegate from the invocation list of another delegate.
    /// @param source The delegate from which to remove the invocation list of value.
    /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
    /// @return delegate A new delegate with an invocation list formed by taking the invocation list of source && removing all occurrences of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null || if the invocation list of value is ! found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source, if source contains only a series of invocation lists that are equal to the invocation list of value, || if source is a null reference.
    /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, all occurrences are removed.
    static delegate remove_all(const delegate& source, const delegate& value) noexcept {
      delegate result = source;
      for (const no_arguments_function_t& function : value.no_arguments_functions_) {
        if (find(result.no_arguments_functions_.begin(), result.no_arguments_functions_.end(), function) != result.no_arguments_functions_.end()) {
          for (typename std::vector<function_t>::reverse_iterator iterator = result.no_arguments_functions_.rbegin(); iterator != result.no_arguments_functions_.rend(); ++iterator) {
            if (are_equals(*iterator, function)) {
              result.no_arguments_functions_.erase((iterator + 1).base());
            }
          }
        }
      }
      
      for (const function_t& function : value.functions_) {
        if (find(result.functions_.begin(), result.functions_.end(), function) != result.functions_.end()) {
          for (typename std::vector<function_t>::reverse_iterator iterator = result.functions_.rbegin(); iterator != result.functions_.rend(); ++iterator) {
            if (are_equals(*iterator, function)) {
              result.functions_.erase((iterator + 1).base());
            }
          }
        }
      }
      return result;
    }

    /// @brief Determines whether this instance and another specified delegateType object have the same value.
    /// @param value The delegateType to compare.
    /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
    bool operator==(const delegate& delegate) const noexcept {
      if (this->functions_.size() != delegate.functions_.size() || this->no_arguments_functions_.size() != delegate.no_arguments_functions_.size())
        return false;

      for (size_t i = 0; i < this->no_arguments_functions_.size(); i++)
        if (!are_equals(this->no_arguments_functions_[i], delegate.no_arguments_functions_[i]))
          return false;

      for (size_t i = 0; i < this->functions_.size(); i++)
        if (!are_equals(this->functions_[i], delegate.functions_[i]))
          return false;

      return true;
    }

    /// @brief Determines whether this instance and another specified delegateType object have the same value.
    /// @param value The delegateType to compare.
    /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
    bool operator!=(const delegate& delegate) const { return !this->operator==(delegate); }

    delegate& operator=(const function_t& function) noexcept {
      this->functions_.push_back(function);
      return *this;
    }
    
    delegate& operator=(const no_arguments_function_t& function) noexcept {
      this->no_arguments_functions_.push_back(function);
      return *this;
    }
    
    delegate& operator+=(const delegate& delegate) noexcept {
      *this = delegate::combine(*this, delegate);
      return *this;
    }

    delegate& operator+=(const no_arguments_function_t& function) noexcept {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }

    delegate& operator+=(const function_t& function) noexcept {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }

    template<typename fn_t>
    delegate& operator+=(fn_t function) noexcept {
      *this = delegate::combine(*this, delegate(function));
      return *this;
    }
    
    delegate& operator-=(const delegate& delegate) noexcept {
      *this = delegate::remove(*this, delegate);
      return *this;
    }

    delegate& operator-=(const no_arguments_function_t& function) noexcept {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }

    delegate& operator-=(const function_t& function) noexcept {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }

    template<typename fn_t>
    delegate& operator-=(fn_t function) noexcept {
      *this = delegate::remove(*this, delegate(function));
      return *this;
    }

  private:
    static bool are_equals(const std::function<result_t(arguments_t...)>& fct1, const std::function<result_t(arguments_t...)>& fct2) noexcept {
      return fct1.target_type() == fct2.target_type() && (fct1.template target<result_t(*)(arguments_t...)>() == fct2.template target<result_t(*)(arguments_t...)>() || *fct1.template target<result_t(*)(arguments_t...)>() == *fct2.template target<result_t(*)(arguments_t...)>());
    }
    
    static bool are_equals(const std::function<result_t()>& fct1, const std::function<result_t()>& fct2) noexcept {
      return fct1.target_type() == fct2.target_type() && (fct1.template target<result_t(*)()>() == fct2.template target<result_t(*)()>() || *fct1.template target<result_t(*)()>() == *fct2.template target<result_t(*)()>());
    }
    
    static typename std::vector<no_arguments_function_t>::const_iterator find(typename std::vector<no_arguments_function_t>::const_iterator begin, typename std::vector<no_arguments_function_t>::const_iterator end, const no_arguments_function_t& function) noexcept {
      for (typename std::vector<no_arguments_function_t>::const_iterator iterator = begin; iterator != end; ++iterator)
        if (are_equals(*iterator, function))
          return iterator;
      return end;
    }
    
    static typename std::vector<function_t>::const_iterator find(typename std::vector<function_t>::const_iterator begin, typename std::vector<function_t>::const_iterator end, const function_t& function) noexcept {
      for (typename std::vector<function_t>::const_iterator iterator = begin; iterator != end; ++iterator)
        if (are_equals(*iterator, function))
          return iterator;
      return end;
    }
    
    std::vector<no_arguments_function_t> no_arguments_functions_;
    std::vector<function_t> functions_;
  };
}
