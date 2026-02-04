/// @file
/// @brief Contains xtd::collections::generic::enumerable_generator <> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "ienumerable.hpp"
#include "ienumerator.hpp"
#include "../../helpers/throw_helper.hpp"
#include <coroutine>
#include <exception>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents an enumerable enumerable_generator.
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      template<typename type_t>
      class enumerable_generator : public xtd::collections::generic::ienumerable<type_t> {
      public:
        struct promise_type {
          type_t current_value;
          
          enumerable_generator get_return_object() {return enumerable_generator {std::coroutine_handle<promise_type>::from_promise(*this)};}
          
          std::suspend_always initial_suspend() noexcept {return {};}
          std::suspend_always final_suspend() noexcept {return {};}
          void return_void() noexcept {}
          void unhandled_exception() {std::terminate();}
          
          std::suspend_always yield_value(type_t value) noexcept {
            current_value = std::move(value);
            return {};
          }
        };
        
        enumerable_generator(const enumerable_generator& other) = delete;
        enumerable_generator& operator =(const enumerable_generator& other) = delete;
        enumerable_generator(enumerable_generator&& other) noexcept : handle_(std::exchange(other.handle_, {})) {}
        enumerable_generator& operator =(enumerable_generator&& other) noexcept {
          handle_ = std::exchange(other.handle_, {});
          return *this;
        }
        ~enumerable_generator() override {if (handle_) handle_.destroy();}
        
        xtd::collections::generic::enumerator<type_t> get_enumerator() const override {
          struct generator_enumerator final : xtd::collections::generic::ienumerator<type_t> {
            explicit generator_enumerator(std::coroutine_handle<promise_type> handle) : handle_(handle) {}
            const type_t& current() const override {return handle_.promise().current_value;}
            bool move_next() override {
              if (!handle_ || handle_.done()) return false;
              handle_.resume();
              return !handle_.done();
            }
            void reset() override {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::not_supported);}
            
          private:
            std::coroutine_handle<promise_type> handle_;
          };
          
          return {new_ptr<generator_enumerator>(handle_)};
        }
        
      private:
        explicit enumerable_generator(std::coroutine_handle<promise_type> handle) : handle_(handle) {}
        
        mutable std::coroutine_handle<promise_type> handle_;
      };
    }
  }
}
