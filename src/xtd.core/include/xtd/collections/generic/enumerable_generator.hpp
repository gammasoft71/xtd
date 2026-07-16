/// @file
/// @brief Contains xtd::collections::generic::enumerable_generator <> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "ienumerable.hpp"
#include "ienumerator.hpp"
#define __XTD_CORE_INTERNAL__
#include "../../internal/__string_definitions.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../../helpers/throw_helper.hpp"
#include "../../object.hpp"
//#include "../../string.hpp"
#include <coroutine>
#include <exception>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents an enumerable generator that supports deferred, lazy iteration over a collection of a specified type using C++20 coroutines.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// class enumerable_generator : public xtd::collections::generic::ienumerable<type_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/enumerable_generator>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @par Examples
      /// The following example demonstrates how to create and consume an xtd::collections::generic::enumerable_generator <type_t> using the `co_yield` keyword and LINQ pipeline operators.
      /// @include generic_enumerable_generator.cpp
      /// @remarks xtd::collections::generic::enumerable_generator <type_t> acts as a stream-like, lazy-evaluated data source. It leverages the C++20 coroutine standard to suspend and resume execution on-demand whenever an element is requested by an iterator or an enumerator.
      /// @remarks Because it wraps an ephemeral coroutine frame state, an xtd::collections::generic::enumerable_generator <type_t> is a **single-pass** stream. It cannot be copied, only moved. Multiple iterators active at the same time on the same generator will advance and consume the exact same underlying state stream.
      /// @remarks Tenting to invoke the xtd::collections::generic::ienumerator::reset method on a generator's enumerator will systematically throw an xtd::not_supported_exception, as coroutine execution states cannot be rewound.
      template<typename type_t>
      class enumerable_generator : public xtd::object, public xtd::collections::generic::ienumerable<type_t> {
      public:
        /// @brief The promise type required by the C++20 coroutine standard to manage the state and lifecycle of the enumerable_generator.
        /// @remarks This structure acts as the internal bridge between the compiler's coroutine mechanics and the public xtd::collections::generic::enumerable_generator instance.
        /// @warning This structure is used internally by the compiler when processing functions containing the `co_yield` keyword. It should not be manipulated directly by application code.
        struct promise_type {
          /// @brief Represents the current value yielded by the coroutine execution state.
          type_t current_value;
          
          /// @brief Creates and returns the public instance of the xtd::collections::generic::enumerable_generator linked to this promise state.
          /// @return A new xtd::collections::generic::enumerable_generator instance wrapping the underlying coroutine handle.
          enumerable_generator get_return_object() {return enumerable_generator {std::coroutine_handle<promise_type>::from_promise(*this)};}
          
          /// @brief Defines the initial suspension behavior of the coroutine.
          /// @return An object that forces the coroutine to suspend immediately, ensuring **lazy evaluation** behavior.
          /// @remarks The generator will not execute any code until the very first call to xtd::collections::generic::ienumerator::move_next is triggered.
          std::suspend_always initial_suspend() noexcept {return {};}

          /// @brief Defines the final suspension behavior of the coroutine upon completion.
          /// @return An object that forces the coroutine to suspend at its endpoint.
          /// @remarks Keeping the coroutine suspended at its end prevents the handle from destroying itself prematurely, allowing the parent generator to safely manage its cleanup.
          std::suspend_always final_suspend() noexcept {return {};}

          /// @brief Handles the completion of a coroutine function that does not return a final value (using `co_return;` or reaching the end of the body).
          void return_void() noexcept {}
          
          /// @brief Catches any unhandled exceptions escaped from the coroutine body.
          /// @remarks In the context of xtd::collections::generic::enumerable_generator, any unhandled exception within the generator block immediately triggers a std::terminate to guarantee system safety.
          void unhandled_exception() {std::terminate();}
          
          /// @brief Captures the value emitted by a `co_yield` expression and suspends the coroutine execution flow.
          /// @param value The value of type `type_t` to be transmitted to the active enumerator or iterator façade.
          /// @return An object that instructs the compiler to suspend execution immediately after capturing the value.
          /// @remarks The value is efficiently transferred into the state using std::move to minimize overhead and enforce **zero-cost abstraction** performance.
          std::suspend_always yield_value(type_t value) noexcept {
            current_value = std::move(value);
            return {};
          }
        };
        
        /// @cond
        enumerable_generator(const enumerable_generator& other) = delete;
        enumerable_generator& operator =(const enumerable_generator& other) = delete;
        enumerable_generator(enumerable_generator&& other) noexcept : handle_(std::exchange(other.handle_, {})) {}
        enumerable_generator& operator =(enumerable_generator&& other) noexcept {
          handle_ = std::exchange(other.handle_, {});
          return *this;
        }
        ~enumerable_generator() override {if (handle_) handle_.destroy();}
        /// @endcond
        
        /// @name Public Methods
        
        /// @{
        /// @brief Returns an enumerator that iterates through the xtd::collections::generic::enumerable_generator.
        /// @return An xtd::collections::generic::enumerator object that can be used to iterate through the xtd::collections::generic::enumerable_generator <type_t>.
        xtd::collections::generic::enumerator<type_t> get_enumerator() const override {
          struct generator_enumerator final : xtd::collections::generic::ienumerator<type_t> {
            explicit generator_enumerator(std::coroutine_handle<promise_type> handle) : handle_(handle) {}
            const type_t& current() const override {
              if (!started_) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
              return handle_.promise().current_value;
            }
            bool move_next() override {
              started_ = true;
              if (!handle_ || handle_.done()) return false;
              handle_.resume();
              return !handle_.done();
            }
            void reset() override {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::not_supported);}
            
          private:
            bool started_ = false;
            std::coroutine_handle<promise_type> handle_;
          };
          
          return {new_ptr<generator_enumerator>(handle_)};
        }
        
        /// @brief Returns a xtd::string that represents the current object.
        /// @return A string that represents the current object.
        [[nodiscard]] auto to_string() const noexcept -> xtd::string override; // Defined in xtd/string.hpp
        /// @}
        
      private:
        explicit enumerable_generator(std::coroutine_handle<promise_type> handle) : handle_(handle) {}
        
        mutable std::coroutine_handle<promise_type> handle_;
      };
    }
  }
}
