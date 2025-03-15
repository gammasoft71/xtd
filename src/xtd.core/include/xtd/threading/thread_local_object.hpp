/// @file
/// @brief Contains xtd::threading::thread_local_object exception.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "mutex.hpp"
#include "thread.hpp"
#include "../func.hpp"
#include "../invalid_operation_exception.hpp"
#include "../object.hpp"
#include "../time_span.hpp"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Provides thread-local storage of data.
    /// ```cpp
    /// template<class value_t>
    /// class thread_local_object : public xtd::object
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/threading/thread_local_object>
    /// ```
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example shows how to use a xtd::threading::thread_local_object:
    /// @include thread_local_object.cpp
    /// @remarks All public and protected members of xtd::threading::thread_local_object are thread-safe and may be used concurrently from multiple threads. The value returned for the xtd::threading::thread_local_object::value and xtd::threading::thread_local_object::is_value_created properties is specific for the thread on which the property is accessed.
    /// @remarks The differences between the thread_local_object class and the C++ thread_local keyword are :
    /// * It is possible to declare a member variable of a thread local class with the thread_local_object class, whereas this is not possible with the thread_local keyword.
    /// * With the thread_local_object class, you can consult the various values stored by all threads.
    /// @warning Each thread that has ever accessed the instance will contribute to the values stored in the instance. This includes threads that have since left the instance
    template<class value_t>
    class thread_local_object : public object {
      struct data : public object {
        threading::mutex mutex;
        bool track_all_values = false;
        func<value_t> value_factory;
        std::map<intptr, value_t> values;
      };

      struct lock_guard_mutex {
        lock_guard_mutex(mutex& mutex) : mutex_(mutex) {mutex_.lock();}
        ~lock_guard_mutex() {mutex_.unlock();}
      private:
        mutex& mutex_;
      };

    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes the xtd::threading::thread_local_object instance.
      /// @remarks The default value of value_t is used to initialize the instance when xtd::threading::thread_local_object::value is accessed for the first time.
      /// @remarks This constructor is equivalent to calling the xtd::threading::thread_local_object(bool) constructor with a value of `false` for the track_all_values argument.
      thread_local_object() = default;
      /// @brief Initializes the xtd::threading::thread_local_object instance and specifies whether all values are accessible from any thread.
      /// @param track_all_values `true` to track all values set on the instance and expose them through the xtd::threading::thread_local_object::values property; `false` otherwise. When set to `true`, a value stored from a given thread will be available through xtd::threading::thread_local_object::values even after that thread has exited.
      /// @remarks If track_all_values is `false`, only the value of this instance for the current thread is accessible. Attempting to use the xtd::threading::thread_local_object::values property to retrieve all values throws an xtd::invalid_operation_exception exception.
      explicit thread_local_object(bool track_all_values) {data_->track_all_values = track_all_values;}
      /// @brief Initializes the xtd::threading::thread_local_object instance with the specified value_factory function.
      /// @param value_factory The xtd::func invoked to produce a lazily-initialized value when an attempt is made to retrieve xtd::threading::thread_local_object::value without it having been previously initialized.
      explicit thread_local_object(const func<value_t>& value_factory) {data_->value_factory = value_factory;}
      /// @brief Initializes the xtd::threading::thread_local_object instance with the specified value_factory function and a flag that indicates whether all values are accessible from any thread.
      /// @param value_factory The xtd::func invoked to produce a lazily-initialized value when an attempt is made to retrieve Value without it having been previously initialized.
      /// @param track_all_values `true` to track all values set on the instance and expose them through the xtd::threading::thread_local_object::values property; `false` otherwise. When set to `true`, a value stored from a given thread will be available through xtd::threading::thread_local_object::values even after that thread has exited.
      /// @remarks If track_all_values is `false`, only the value of this instance for the current thread is accessible. Attempting to use the xtd::threading::thread_local_object::values property to retrieve all values throws an xtd::invalid_operation_exception exception.
      thread_local_object(const func<value_t>& value_factory, bool track_all_values) {
        data_->value_factory = value_factory;
        data_->track_all_values = track_all_values;
      }
      /// @}

      /// @cond
      template<class func_t>
      explicit thread_local_object(func_t value_factory) : thread_local_object(func<value_t> {value_factory}) {}
      template<class func_t>
      explicit thread_local_object(func_t value_factory, bool track_all_values) : thread_local_object(func<value_t> {value_factory}, track_all_values) {}
      thread_local_object(thread_local_object&&) = default;
      thread_local_object(const thread_local_object&) = default;
      thread_local_object& operator =(const thread_local_object& other) = default;
      /// @endcond

      /// @name Public Properties
      
      /// @{
      /// @brief Gets whether xtd::threading::thread_local_object::value is initialized on the current thread.
      /// @return `true` if xtd::threading::thread_local_object::value is initialized on the current thread; otherwise `false`.
      bool is_value_created() const noexcept {
        lock_guard_mutex lock {data_->mutex};
        return data_->values.find(thread::current_thread().thread_id()) != data_->values.end();
      }

      /// @brief Gets the value of this instance for the current thread.
      /// @return Returns an instance of the object that this xtd::threading::thread_local_object::value is responsible for initializing.
      /// @remarks If this instance was not previously initialized for the current thread, accessing xtd::threading::thread_local_object::value will attempt to initialize it. If an initialization function was supplied during the construction, that initialization will happen by invoking the function to retrieve the initial value for xtd::threading::thread_local_object::value. Otherwise, the default value of value_t will be used.
      value_t value() const noexcept {
        lock_guard_mutex lock {data_->mutex};
        if (!is_value_created()) data_->values[thread::current_thread().thread_id()] = data_->value_factory.is_empty() ? value_t {} : data_->values[thread::current_thread().thread_id()] = data_->value_factory();
        return data_->values.find(thread::current_thread().thread_id())->second;
      }
      
      /// @brief Sets the value of this instance for the current thread.
      /// @param value An instance of the object that this xtd::threading::thread_local_object::value is responsible for initializing.
      /// @remarks If this instance was not previously initialized for the current thread, accessing xtd::threading::thread_local_object::value will attempt to initialize it. If an initialization function was supplied during the construction, that initialization will happen by invoking the function to retrieve the initial value for xtd::threading::thread_local_object::value. Otherwise, the default value of value_t will be used.
      void value(value_t value) noexcept {
        lock_guard_mutex lock {data_->mutex};
        data_->values[thread::current_thread().thread_id()] = value;
      }
      
      /// @brief Gets a list containing the values stored by all threads that have accessed this instance.
      /// @return A list for all of the values stored by all of the threads that have accessed this instance.
      /// @exception xtd::invalid_operation_exception Values stored by all threads are not available because this instance was initialized with the track_all_values argument set to `false` in the call to a class constructor.
      /// @remarks Each thread that has ever accessed this instance will contribute to this list the value last stored into the instance. This includes threads that have since exited.
      xtd::array<value_t> values() const {
        if (!data_->track_all_values) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
        lock_guard_mutex lock {data_->mutex};
        auto values = xtd::array<value_t> {};
        for (const auto& entry : data_->values)
          values.resize(values.size() + 1, entry.second);
        return values;
      }
      /// @}

      /// @name Public Methods
      
      /// @{
      string to_string() const noexcept override {
        return string::format("{}", value());
      }
      /// @}

    private:
      mutable xtd::sptr<data> data_ = xtd::new_sptr<data>();
    };
  }
}
