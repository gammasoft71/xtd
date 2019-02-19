/// @file
/// @brief Contains xtd::tunit::event_listener class.
#pragma once
#include "class_event_args.hpp"
#include "test_event_args.hpp"
#include "tunit_event_args.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The event_listener class.
    class event_listener {
    public:
      /// @cond
      virtual ~event_listener() = default;
      /// @endcond
      
      virtual void on_class_cleanup_end(const xtd::tunit::class_event_args& e) const {}
      virtual void on_class_cleanup_start(const xtd::tunit::class_event_args& e) const {}
      virtual void on_class_end(const xtd::tunit::class_event_args& e) const {}
      virtual void on_class_initialize_end(const xtd::tunit::class_event_args& e) const {}
      virtual void on_class_initialize_start(const xtd::tunit::class_event_args& e) const {}
      virtual void on_class_start(const xtd::tunit::class_event_args& e) const {}
      
      virtual void on_test_cleanup_end(const xtd::tunit::test_event_args& e) const {}
      virtual void on_test_cleanup_start(const xtd::tunit::test_event_args& e) const {}
      virtual void on_test_initialize_end(const xtd::tunit::test_event_args& e) const {}
      virtual void on_test_initialize_start(const xtd::tunit::test_event_args& e) const {}
      virtual void on_test_end(const xtd::tunit::test_event_args& e) const {}
      virtual void on_test_failed(const xtd::tunit::test_event_args& e) const {}
      virtual void on_test_start(const xtd::tunit::test_event_args& e) const {}
      virtual void on_test_succeed(const xtd::tunit::test_event_args& e) const {}
      
      virtual void on_unit_test_cleanup_end(const xtd::tunit::tunit_event_args& e) const {}
      virtual void on_unit_test_cleanup_start(const xtd::tunit::tunit_event_args& e) const {}
      virtual void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const {}
      virtual void on_unit_test_initialize_end(const xtd::tunit::tunit_event_args& e) const {}
      virtual void on_unit_test_initialize_start(const xtd::tunit::tunit_event_args& e) const {}
      virtual void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const {}
      
    };
  }
}
