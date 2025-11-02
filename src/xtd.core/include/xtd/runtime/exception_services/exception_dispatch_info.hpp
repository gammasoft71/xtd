/// @file
/// @brief Contains xtd::runtime::exception_services::exception_dispatch_info class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../../exception.hpp"
#include "../../ptr.hpp"
#include <exception>
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains advanced types that support diverse namespaces such as the `xtd`, `runtime`, and the `security` namespaces.
  namespace runtime {
    /// @brief Provides classes for advanced exception handling.
    namespace exception_services {
      /// @brief Represents an exception whose state is captured at a certain point in code.
      /// @par Definition
      /// ```cpp
      /// class exception_dispatch_info final : public xtd::object;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/runtime/exception_services/exception_dispatch_info>
      /// ```
      /// @par Namespace
      /// xtd::runtime
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core system
      /// @remarks An xtd::runtime::exception_services::exception_dispatch_info object stores the stack trace information that an exception contains at the point where it's captured. The exception can then be thrown at another time and possibly on another thread by calling the xtd::runtime::exception_services::exception_dispatch_info.rethrow method. The exception is thrown as if it had flowed from the point where it was captured to the point where the xtd::runtime::exception_services::exception_dispatch_info::rethrow method is called.
      /// @remarks For an example, see [Capture exceptions to rethrow later](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Exceptions/exceptions_best_practices#capture-and-rethrow-exceptions-properly).
      class exception_dispatch_info final : public xtd::object {
      public:
        /// @cond
        exception_dispatch_info() = default;
        exception_dispatch_info(exception_dispatch_info&&) = default;
        exception_dispatch_info(const exception_dispatch_info&) = default;
        exception_dispatch_info& operator =(exception_dispatch_info&&) = default;
        exception_dispatch_info& operator =(const exception_dispatch_info&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets a value indicating whether the exception is caught or not.
        /// @return `true`if the exception is captured; otherwise `false`.
        bool exception_captured() const noexcept {return exception_ptr_ ? true : false;}
        
        /// @brief Gets the exception that's represented by the current instance.
        /// @return The exception that's represented by the current instance.
        /// @remarks This property is used by the Task Parallel Library, for example, to combine multiple exceptions in an xtd::aggregate_exception object. It's not intended to be used by application code. Use the xtd::runtime::exception_services::exception_dispatch_info::rethrow method to restore the state of the captured exception and throw it.
        xtd::ptr<xtd::exception> source_exception() const noexcept {return source_;}
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Creates an xtd::runtime::exception_services::exception_dispatch_info object that represents the specified exception at the current point in code.
        /// @param source The exception whose state is captured, and which is represented by the returned object.
        /// @return An object that represents the specified exception at the current point in code.
        /// @remarks You can use the xtd::runtime::exception_services::exception_dispatch_info object that's returned by this method at another time and possibly on another thread to rethrow the specified exception, as if the exception had flowed from the point where it was captured to the point where it's rethrown.
        /// @remarks If the exception is active when it's captured, the current stack trace information that's contained in the exception is stored. If it's inactive, that is, if it has not been thrown, it doesn't have any stack trace information.
        template<class exception_t>
        inline static exception_dispatch_info capture(const exception_t& source) {
          static_assert(std::is_base_of<xtd::exception, exception_t>::value);
          return exception_dispatch_info {source};
        }
        
        /// @brief Rethrows the exception that's represented by the current xtd::runtime::exception_services::exception_dispatch_info object, after restoring the state that was saved when the exception was captured.
        void rethrow() {if (exception_captured()) std::rethrow_exception(exception_ptr_);}
        /// @brief Rehrows the source exception, maintaining the original stack trace information.
        template<class exception_t>
        inline static void rethrow(const exception_t& source) {exception_dispatch_info {source}.rethrow();}
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Convert to boolean operator.
        /// @return `true` if exception is captured; otherwise `false`.
        explicit operator bool() const noexcept {return exception_captured();}
        /// @}
        
      private:
        template<class exception_t>
        exception_dispatch_info(const exception_t& source) : source_ {source.template memberwise_clone<exception_t>().release()}, exception_ptr_ {std::make_exception_ptr(source)} {}
        
        xtd::ptr<xtd::exception> source_;
        std::exception_ptr exception_ptr_;
      };
    }
  }
}
