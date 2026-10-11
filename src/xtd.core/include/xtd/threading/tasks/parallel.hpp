/// @file
/// @brief Contains xtd::threading::tasks::parallel <result_t> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "task_factory.hpp"
#include "../../collections/generic/list.hpp"
#include "../../action_callable.hpp"
#include "../../array.hpp"
#include "../../integer.hpp"
#include "../../static.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::parallel which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::parallel <result_t>, which is a parallel that can return a value. The xtd::threading::tasks::parallel class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @brief Provides support for creating and scheduling Task objects.
      /// @par Namespace
      /// xtd::threading::tasks
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading tasks
      class parallel static_ {
      public:
        template<xtd::integer integer_t>
        static auto for_(integer_t from_inclusive, integer_t to_exclusive, auto&& body) -> void {
          for_each(xtd::linq::enumerable::range(from_inclusive, to_exclusive - from_inclusive), body);
        }
        
        template<xtd::integer integer_t>
        static auto for_(integer_t from_inclusive, integer_t to_exclusive, auto&& body, const xtd::threading::cancellation_token& cancellation_token) -> void {
          for_each(xtd::linq::enumerable::range(from_inclusive, to_exclusive - from_inclusive), body, cancellation_token).wait();
        }

        template<xtd::integer integer_t>
        static auto for_async(integer_t from_inclusive, integer_t to_exclusive, auto&& body) -> xtd::threading::tasks::task<> {
          return for_each_async(xtd::linq::enumerable::range(from_inclusive, to_exclusive - from_inclusive), body);
        }
        
        template<xtd::integer integer_t>
        static auto for_async(integer_t from_inclusive, integer_t to_exclusive, auto&& body, const xtd::threading::cancellation_token& cancellation_token) -> xtd::threading::tasks::task<> {
          return for_each_async(xtd::linq::enumerable::range(from_inclusive, to_exclusive - from_inclusive), body, cancellation_token);
        }
        
        template<xtd::iterable source_t>
        static auto for_each(source_t&& source, auto&& body) -> void {
          for_each_async(std::forward<source_t>(source), body).wait();
        }
        
        template<xtd::iterable source_t>
        static auto for_each(source_t&& source, auto&& body, const xtd::threading::cancellation_token& cancellation_token) -> void {
          for_each_async(std::forward<source_t>(source), body, cancellation_token).wait();
        }

        /// @brief Executes a for-each operation on an xtd::iterable in which iterations may run in parallel.
        /// @param source An enumerable data source.
        /// @param body An asynchronous delegate that is invoked once per element in the data source.
        /// @return A task that represents the entire for-each operation.
        /// @remarks The operation will execute at most ProcessorCount operations in parallel.
        template<xtd::iterable source_t>
        static auto for_each_async(source_t&& source, auto&& body) -> xtd::threading::tasks::task<> {
          using result_t = xtd::raw_type<decltype(body(std::declval<const xtd::iterable_value_type<source_t>&>()))>;
          xtd::collections::generic::list<xtd::threading::tasks::task<result_t>> tasks;
          
          for(const auto& item : source)
            tasks.add(xtd::threading::tasks::task<>::factory().start_new([body](auto state) -> result_t {return body(as<xtd::iterable_value_type<source_t>>(state));}, xtd::any_object(item)));
          
          co_await xtd::threading::tasks::task<result_t>::when_all(tasks);
        }
        
        /// @brief Executes a for-each operation on an xtd::iterable in which iterations may run in parallel.
        /// @param source An enumerable data source.
        /// @param body An asynchronous delegate that is invoked once per element in the data source.
        /// @param cancellation_token 
        /// @return A task that represents the entire for-each operation.
        /// @remarks The operation will execute at most ProcessorCount operations in parallel.
        template<xtd::iterable source_t>
        static auto for_each_async(source_t&& source, auto&& body, const xtd::threading::cancellation_token& cancellation_token) -> xtd::threading::tasks::task<> {
          using result_t = xtd::raw_type<decltype(body(std::declval<const xtd::iterable_value_type<source_t>&>()))>;
          xtd::collections::generic::list<xtd::threading::tasks::task<result_t>> tasks;
          
          for(const auto& item : source)
            tasks.add(xtd::threading::tasks::task<>::factory().start_new([body](auto state) -> result_t {return body(as<xtd::iterable_value_type<source_t>>(state));}, xtd::any_object(item), cancellation_token));
          
          co_await xtd::threading::tasks::task<result_t>::when_all(tasks);
        }
        
        /// @cond
        template<typename type_t>
        static auto for_each(std::initializer_list<type_t>&& source, auto&& body) -> void {
          for_each(xtd::collections::generic::list<type_t>(source), body);
        }
        
        template<typename type_t>
        static auto for_each(std::initializer_list<type_t>&& source, auto&& body, const xtd::threading::cancellation_token& cancellation_token) -> void {
          for_each(xtd::collections::generic::list<type_t>(source), body, cancellation_token);
        }
        
        template<typename type_t>
        static auto for_each_async(std::initializer_list<type_t>&& source, auto&& body) -> xtd::threading::tasks::task<> {
          return for_each_async(xtd::collections::generic::list<type_t>(source), body);
        }
        
        template<typename type_t>
        static auto for_each_async(std::initializer_list<type_t>&& source, auto&& body, const xtd::threading::cancellation_token& cancellation_token) -> xtd::threading::tasks::task<> {
          return for_each_async(xtd::collections::generic::list<type_t>(source), body, cancellation_token);
        }
        /// @endcond

        /// @brief Executes each of the provided actions, possibly in parallel.
        /// @par Library
        /// Switch.Core
        /// @ingroup SwitchCore
        /// @param An array of Action to execute.
        /// @remarks This method can be used to execute a set of operations, potentially in parallel.
        /// @remarks No guarantees are made about the order in which the operations execute or whether they execute in parallel. This method does not return until each of the provided operations has completed, regardless of whether completion occurs due to normal or exceptional termination.
        /// @par Examples
        /// This example demonstrates how to use the Invokemethod with other methods, anonymous delegates, and lambda expressions.
        /// @include parallel_invoke.cpp
        static auto invoke(xtd::array<xtd::action<>>&& actions) -> void {
          task<>::wait_all(invoke_async(actions));
        }
        /// @brief Executes each of the provided actions, possibly in parallel.
        /// @par Library
        /// Switch.Core
        /// @ingroup SwitchCore
        /// @param An array of Action to execute.
        /// @remarks This method can be used to execute a set of operations, potentially in parallel.
        /// @remarks No guarantees are made about the order in which the operations execute or whether they execute in parallel. This method does not return until each of the provided operations has completed, regardless of whether completion occurs due to normal or exceptional termination.
        /// @par Examples
        /// This example demonstrates how to use the Invokemethod with other methods, anonymous delegates, and lambda expressions.
        /// @include parallel_invoke.cpp
        template<typename collection_t>
        static auto invoke(collection_t&& actions) -> void {
          task<>::wait_all(invoke_async(actions));
        }
        /// @brief Executes each of the provided actions, possibly in parallel.
        /// @par Library
        /// Switch.Core
        /// @ingroup SwitchCore
        /// @param An array of Action to execute.
        /// @remarks This method can be used to execute a set of operations, potentially in parallel.
        /// @remarks No guarantees are made about the order in which the operations execute or whether they execute in parallel. This method does not return until each of the provided operations has completed, regardless of whether completion occurs due to normal or exceptional termination.
        /// @par Examples
        /// This example demonstrates how to use the Invokemethod with other methods, anonymous delegates, and lambda expressions.
        /// @include parallel_invoke.cpp
        template<typename ...args_t>
        static auto invoke(args_t&&... args) -> void {invoke(xtd::array<xtd::action<>> {xtd::action<> {std::forward<args_t>(args)}...});}

        static auto invoke_async(xtd::array<xtd::action<>>&& actions) -> xtd::array<xtd::threading::tasks::task<>> {
          xtd::collections::generic::list<xtd::threading::tasks::task<>> tasks;
          for (const auto& action : actions)
            tasks.add(xtd::threading::tasks::task<>::factory().start_new(action));
          return tasks.to_array();
        }
        
        template<typename collection_t>
        static auto invoke_async(collection_t&& actions) -> xtd::array<xtd::threading::tasks::task<>> {
          xtd::collections::generic::list<xtd::threading::tasks::task<>> tasks;
          for (const auto& action : actions)
            tasks.add(xtd::threading::tasks::task<>::factory().start_new(action));
          return tasks.to_array();
        }
        
        template<typename ...args_t>
        static auto invoke_async(args_t&&... args) -> xtd::array<xtd::threading::tasks::task<>> {return invoke_async(xtd::array<xtd::action<>> {xtd::action<> {std::forward<args_t>(args)}...});}
      };
    }
  }
}
