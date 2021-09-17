/// @file
/// @brief Contains xtd::tunit::event_listener class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "class_event_args.h"
#include "test_event_args.h"
#include "tunit_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Represent the event listener class. Unit test call theses events when unit tests are processing.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    /// @remarks Override this class for create your own event listener.
    /// @par Examples
    /// The follow example shows how to create your own listener event for simulate gtest output.
    /// @include create_your_own_event_listener.cpp
    class event_listener {
    public:
      /// @cond
      virtual ~event_listener() = default;
      /// @endcond

      /// @brief Occurs when class cleanup is ended.
      /// @param class_event_args Contains class event parameters.
      virtual void on_class_cleanup_end(const xtd::tunit::class_event_args& e) const {}

      /// @brief Occurs when class cleanup is started.
      /// @param class_event_args Contains class event parameters.
      virtual void on_class_cleanup_start(const xtd::tunit::class_event_args& e) const {}

      /// @brief Occurs when class is ended.
      /// @param class_event_args Contains class event parameters.
      virtual void on_class_end(const xtd::tunit::class_event_args& e) const {}

      /// @brief Occurs when class initialize is ended.
      /// @param class_event_args Contains class event parameters.
      virtual void on_class_initialize_end(const xtd::tunit::class_event_args& e) const {}

      /// @brief Occurs when class initialize is started.
      /// @param class_event_args Contains class event parameters.
      virtual void on_class_initialize_start(const xtd::tunit::class_event_args& e) const {}

      /// @brief Occurs when class is started.
      /// @param class_event_args Contains class_event parameters.
      virtual void on_class_start(const xtd::tunit::class_event_args& e) const {}
      
      /// @brief Occurs when test cleanup is ended.
      /// @param test_event_args Contains test event parameters.
      virtual void on_test_cleanup_end(const xtd::tunit::test_event_args& e) const {}

      /// @brief Occurs when test cleanup is started.
      /// @param test_event_args Contains test event parameters.
      virtual void on_test_cleanup_start(const xtd::tunit::test_event_args& e) const {}

      /// @brief Occurs when test initialize is ended.
      /// @param test_event_args Contains test event parameters.
      virtual void on_test_initialize_end(const xtd::tunit::test_event_args& e) const {}
      
      /// @brief Occurs when test initialize is ended.
      /// @param test_event_args Contains test event parameters.
      virtual void on_test_initialize_start(const xtd::tunit::test_event_args& e) const {}

      /// @brief Occurs when test is aborted.
      /// @param test_event_args Contains test event parameters.
      virtual void on_test_aborted(const xtd::tunit::test_event_args& e) const {}

      /// @brief Occurs when test is ended.
      /// @param test_event_args Contains test event parameters.
      virtual void on_test_end(const xtd::tunit::test_event_args& e) const {}

      /// @brief Occurs when test is ignored.
      /// @param test_event_args Contains test event parameters.
      virtual void on_test_ignored(const xtd::tunit::test_event_args& e) const {}
      
      /// @brief Occurs when test is failed.
      /// @param test_event_args Contains test event parameters.
      virtual void on_test_failed(const xtd::tunit::test_event_args& e) const {}

      /// @brief Occurs when test initialize is started.
      /// @param test_event_args Contains test event parameters.
      virtual void on_test_start(const xtd::tunit::test_event_args& e) const {}

      /// @brief Occurs when test is succeed.
      /// @param test_event_args Contains test event parameters.
      virtual void on_test_succeed(const xtd::tunit::test_event_args& e) const {}
      
      /// @brief Occurs when unit test cleanup is ended.
      /// @param tunit_event_args Contains unit test event parameters.
      virtual void on_unit_test_cleanup_end(const xtd::tunit::tunit_event_args& e) const {}
      
      /// @brief Occurs when unit test is started.
      /// @param tunit_event_args Contains unit test event parameters.
      virtual void on_unit_test_cleanup_start(const xtd::tunit::tunit_event_args& e) const {}
      
      /// @brief Occurs when unit test is ended.
      /// @param tunit_event_args Contains unit test event parameters.
      virtual void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const {}
      
      /// @brief Occurs when unit test initalize is ended.
      /// @param tunit_event_args Contains unit test event parameters.
      virtual void on_unit_test_initialize_end(const xtd::tunit::tunit_event_args& e) const {}
      
      /// @brief Occurs when unit test initialize is ended.
      /// @param tunit_event_args Contains unit test event parameters.
      virtual void on_unit_test_initialize_start(const xtd::tunit::tunit_event_args& e) const {}
      
      /// @brief Occurs when unit test cleanup is started.
      /// @param tunit_event_args Contains unit test event parameters.
      virtual void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const {}
    };
  }
}
