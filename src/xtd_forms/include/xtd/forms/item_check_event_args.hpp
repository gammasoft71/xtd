#pragma once
#include <cstdint>
#include <xtd/event_args.h>
#include <xtd/xtd.strings>
#include "check_state.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Provides data for the item_check event of the checked_list_box and list_view controls.
    /// @remarks The item_check event occurs when the checked state of an item in a checked list box changes. The item_check_event_args class specifies the index of the item to change, the current value of the check box for the item, and the new value to set for the check box.
    class item_check_event_args : public event_args {
    public:
      /// @cond
      item_check_event_args(const item_check_event_args& item_check_event_args) = default;
      item_check_event_args& operator=(const item_check_event_args& item_check_event_args) = default;
      /// @endcond
      
      /// @brief Initializes a new instance of the item_check_event_args class.
      /// @param index The zero-based index of the item to change.
      /// @param new_value One of the check_state values that indicates whether to change the check box for the item to be checked, unchecked, or indeterminate.
      /// @param current_value One of the check_state values that indicates whether the check box for the item is currently checked, unchecked, or indeterminate.
      item_check_event_args(size_t index, check_state new_value, check_state current_value) : index_(index), new_value_(new_value), current_value_(current_value) {}
      
      /// @brief Gets a value indicating the current state of the item's check box.
      /// @return One of the check_state values.
      /// @remarks This property enables you to determine the check state of the specified item in the checked_list_box before the check state change to apply is made.
      check_state current_value() const {return this->current_value_;}
      
      /// @brief Gets the zero-based index of the item to change.
      /// @return The zero-based index of the item to change.
      /// @remarks You can use this property to determine which item's check box in the checked_list_box is being changed.
      size_t index() const {return this->index_;}
      
      /// @brief Gets a value indicating whether to set the check box for the item to be checked, unchecked, or indeterminate.
      /// @return One of the check_state values.
      /// @remarks This property enables you to determine the new check state for the specified item before the check state is changed by the checked_list_box control. In addition to determining the new check state, you can use this property in an event handler for the ItemCheck event to change the state to a different check state than the one specified. For example, if the user placed a check mark next to an item in the checked_list_box that you have determined should not be checked based on the state of your application, you can override the change in the check mark state by setting this property to its previous setting or to a different check state.
      check_state new_value() const {return this->new_value_;}
      /// @brief Gets a value indicating whether to set the check box for the item to be checked, unchecked, or indeterminate.
      /// @param new_value One of the check_state values.
      /// @remarks This property enables you to determine the new check state for the specified item before the check state is changed by the checked_list_box control. In addition to determining the new check state, you can use this property in an event handler for the ItemCheck event to change the state to a different check state than the one specified. For example, if the user placed a check mark next to an item in the checked_list_box that you have determined should not be checked based on the state of your application, you can override the change in the check mark state by setting this property to its previous setting or to a different check state.
      void new_value(check_state new_value) {this->new_value_ = new_value;}

    private:
      size_t index_ = -1;
      check_state new_value_ = check_state::indeterminate;
      check_state current_value_ = check_state::unchecked;
    };
  }
}
