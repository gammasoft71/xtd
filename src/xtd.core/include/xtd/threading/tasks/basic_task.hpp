/// @file
/// @brief Contains xtd::threading::tasks::basic_task <> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "task_creation_options.hpp"
#include "task_status.hpp"
#include "../../aggregate_exception.hpp"
#include "../../iasync_result.hpp"
#include "../../new_sptr.hpp"
#include "../../object.hpp"
#include "../../optional.hpp"
#include "../../sptr.hpp"
#include "../auto_reset_event.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @cond
      template<class result_t = void>
      class task;
      /// @endcond
      
      /// @brief Represents an asynchronous operation.
      /// @par Namespace
      /// xtd::threading::tasks
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading tasks
      template<class result_t>
      class basic_task : public xtd::object, public xtd::iasync_result {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @}

        
        /// @name Public Properties
        
        /// @{
        [[nodiscard]] auto async_state() const noexcept -> xtd::any_object override {return data_->async_state;}
        [[nodiscard]] auto creation_options() const noexcept -> xtd::threading::tasks::task_creation_options {return data_->creation_options;}
        [[nodiscard]] auto exception() const noexcept -> const xtd::optional<xtd::aggregate_exception>& {return data_->exception;}
        [[nodiscard]] auto id() const noexcept -> xtd::size {return data_->id;}
        [[nodiscard]] auto is_canceled() const noexcept -> bool {return data_->status == xtd::threading::tasks::task_status::canceled;}
        [[nodiscard]] auto is_completed() const noexcept -> bool override {return is_faulted() || is_canceled() || data_->status == xtd::threading::tasks::task_status::ran_to_completion;}
        [[nodiscard]] auto is_faulted() const noexcept -> bool {return data_->status == xtd::threading::tasks::task_status::faulted;}
        [[nodiscard]] auto status() const noexcept -> xtd::threading::tasks::task_status {return data_->status;}
        /// @}
        
        /// @name Public Static Properties
        
        /// @{
        [[nodiscard]] static auto completed_task() -> task<result_t>;
        [[nodiscard]] static auto current_id() noexcept -> xtd::optional<xtd::size> {return current_id_;}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @}
        
        /// @name Public Static Methods
        
        /// @{
        template<class from_result_t>
        [[nodiscard]] static auto from_result(from_result_t result) -> task<from_result_t>;
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @}
        
      private:
        template<class task_result_t>
        friend class task;
        
        basic_task() = default;
        basic_task(basic_task&&) = default;
        basic_task(const basic_task&) = default;
        auto operator=(basic_task&&) -> basic_task& = default;
        auto operator=(const basic_task&) -> basic_task& = default;
        
        [[nodiscard]] auto async_wait_handle() noexcept -> xtd::threading::wait_handle& override {return data_->async_event;}
        [[nodiscard]] auto completed_synchronously() const noexcept -> bool override {return false;}

        static auto generate_id() -> xtd::size {
          static auto id = xtd::size {0};
          return ++id;
        }
        
        struct data {
          xtd::async_callback async_callback;
          xtd::threading::manual_reset_event async_event;
          xtd::any_object async_state;
          xtd::threading::tasks::task_creation_options creation_options = xtd::threading::tasks::task_creation_options::none;
          xtd::threading::auto_reset_event end_event;
          xtd::optional<xtd::aggregate_exception> exception;
          xtd::size id = generate_id();
          xtd::int32 milliseconds_delay = 0;
          xtd::threading::auto_reset_event start_event;
          const xtd::any_object* state = &empty_state;
          xtd::threading::tasks::task_status status = xtd::threading::tasks::task_status::created;
          const xtd::any_object empty_state;
        };
        
        xtd::sptr<data> data_ = xtd::new_sptr<data>();

        inline static thread_local xtd::optional<xtd::size> current_id_;
      };
    }
  }
}
