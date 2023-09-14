/// @file
/// @brief Contains xtd::threading::thread_local_object exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "mutex.h"
#include "thread.h"
#include "../func.h"
#include "../invalid_operation_exception.h"
#include "../object.h"
#include "../time_span.h"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Provides thread-local storage of data.
    /// @code
    /// class thread_local_object : public xtd::object
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/thread_local_object> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example shows how to use a xtd::threading::thread_local_object:
    /// @include thread_local_object.cpp
    template<typename value_t>
    class thread_local_object : public object {
      struct data : public object {
        threading::mutex mutex;
        bool track_all_values = true;
        func<value_t> value_factory;
        std::map<intptr, value_t> values;
      };
      
    public:
      /// @name Constructors
      
      /// @{
      thread_local_object() = default;
      explicit thread_local_object(bool track_all_values) {data_->track_all_values = track_all_values;}
      explicit thread_local_object(const func<value_t>& value_factory) {data_->value_factory = value_factory;}
      thread_local_object(const func<value_t>& value_factory, bool track_all_values) {
        data_->value_factory = value_factory;
        data_->track_all_values = track_all_values;
      }
      /// @}

      ///@cond
      template<typename func_t>
      explicit thread_local_object(func_t value_factory) : thread_local_object(func<value_t> {value_factory}) {}
      thread_local_object(thread_local_object&&) = default;
      thread_local_object(const thread_local_object&) = default;
      thread_local_object& operator =(const thread_local_object& other) = default;
      ///@endcond

      /// @name Properties
      
      /// @{
      bool is_value_created() const noexcept {
        lock_guard_mutex lock {data_->mutex};
        return data_->values.find(thread::current_thread().thread_id()) != data_->values.end();
      }

      value_t value() const noexcept {
        lock_guard_mutex lock {data_->mutex};
        if (!is_value_created()) data_->values[thread::current_thread().thread_id()] = data_->value_factory.is_empty() ? value_t {} : data_->values[thread::current_thread().thread_id()] = data_->value_factory();
        return data_->values.find(thread::current_thread().thread_id())->second;
      }
      
      void value(value_t value) noexcept {
        lock_guard_mutex lock {data_->mutex};
        data_->values[thread::current_thread().thread_id()] = value;
      }
      
      std::vector<value_t> values() const {
        if (!data_->track_all_values) throw invalid_operation_exception(csf_);
        lock_guard_mutex lock {data_->mutex};
        auto values = std::vector<value_t> {};
        for (const auto& entry : data_->values)
          values.push_back(entry.second);
        return values;
      }
      /// @}

      /// @name Methods
      
      /// @{
      ustring to_string() const noexcept override {
        return ustring::format("{}", value());
      }
      /// @}

    private:
      mutable std::shared_ptr<data> data_ = std::make_shared<data>();
      class lock_guard_mutex {
      public:
        lock_guard_mutex(mutex& mutex) : mutex_(mutex) {mutex_.lock();}
        ~lock_guard_mutex() {mutex_.unlock();}
      private:
        mutex& mutex_;
      };
    };
  }
}
