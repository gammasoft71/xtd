/// @file
/// @brief Contains xtd::tunit::ostream_event_listener class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "event_listener.h"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The ostream_unit_test class is a specialisation of event_listener class for writing events in std::ostream.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    /// @remarks This class is use by console_unit_test.
    /// @remarks you can use this class as you want as for example communicate between network.
    /// @par Examples
    /// The following examples show how to use ostream_event_listener.
    /// @include ostream_unit_test.cpp
    class tunit_export_ ostream_event_listener : public xtd::tunit::event_listener {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Creates new instance ostream event lister with ostream specified.
      /// @param os std::ostream where events are written.
      ostream_event_listener(std::ostream& os) noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Occurs when class is ended.
      /// @param class_event_args Contains class event parameters.
      void on_class_end(const xtd::tunit::class_event_args& e) const override;
      
      /// @brief Occurs when class cleanup is started.
      /// @param class_event_args Contains class event parameters.
      void on_class_start(const xtd::tunit::class_event_args& e) const override;
      
      /// @brief Occurs when test is aborted.
      /// @param test_event_args Contains test event parameters.
      void on_test_aborted(const xtd::tunit::test_event_args& e) const override;
      
      /// @brief Occurs when test initialize is started.
      /// @param test_event_args Contains test event parameters.
      void on_unit_test_cleanup_start(const xtd::tunit::tunit_event_args& e) const override;
      
      /// @brief Occurs when unit test initialize is started.
      /// @param tunit_event_args Contains unit test event parameters.
      void on_unit_test_initialize_start(const xtd::tunit::tunit_event_args& e) const override;
      
      /// @brief Occurs when test is failed.
      /// @param test_event_args Contains test event parameters.
      void on_test_failed(const xtd::tunit::test_event_args& e) const override;
      
      /// @brief Occurs when test is ignored.
      /// @param test_event_args Contains test event parameters.
      void on_test_ignored(const xtd::tunit::test_event_args& e) const override;
      
      /// @brief Occurs when test initialize is started.
      /// @param test_event_args Contains test event parameters.
      void on_test_start(const xtd::tunit::test_event_args& e) const override;
      
      /// @brief Occurs when test is succeed.
      /// @param test_event_args Contains test event parameters.
      void on_test_succeed(const xtd::tunit::test_event_args& e) const override;
      
      /// @brief Occurs when unit test is ended.
      /// @param tunit_event_args Contains unit test event parameters.
      void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const override;
      
      /// @brief Occurs when unit test cleanup is started.
      /// @param tunit_event_args Contains unit test event parameters.
      void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const override;
      /// @}
      
    private:
      std::ostream& os_;
    };
  }
}
