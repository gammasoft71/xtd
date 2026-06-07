/// @file
/// @brief Contains xtd::forms::labels factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "label.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of label objects for use by a Windows Forms application.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/labels>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of labels control factory.
    /// @include labels.cpp
    class labels final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Create a system-defined label that represent abort label
      /// @return The created label.
      [[nodiscard]] static auto abort() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent abort label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto abort(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent abort label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto abort(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent abort label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto abort(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent abort label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent abort label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent abort label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent abort label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent about label
      /// @return The created label.
      [[nodiscard]] static auto about() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent about label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto about(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent about label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto about(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent about label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto about(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent about label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto about(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent about label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent about label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent about label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent actual_size label
      /// @return The created label.
      [[nodiscard]] static auto actual_size() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent actual_size label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto actual_size(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent actual_size label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto actual_size(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent actual_size label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto actual_size(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent actual_size label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent actual_size label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent actual_size label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent actual_size label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent add label
      /// @return The created label.
      [[nodiscard]] static auto add() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent add label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto add(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent add label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto add(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent add label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto add(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent add label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto add(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent add label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent add label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent add label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent alignment label
      /// @return The created label.
      [[nodiscard]] static auto alignment() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent alignment label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto alignment(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent alignment label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto alignment(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent alignment label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto alignment(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent alignment label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent alignment label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent alignment label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent alignment label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent align_left label
      /// @return The created label.
      [[nodiscard]] static auto align_left() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_left label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto align_left(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_left label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto align_left(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_left label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto align_left(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_left label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_left label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_left label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_left label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent align_right label
      /// @return The created label.
      [[nodiscard]] static auto align_right() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_right label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto align_right(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_right label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto align_right(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_right label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto align_right(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_right label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_right label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_right label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent align_right label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent apply label
      /// @return The created label.
      [[nodiscard]] static auto apply() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent apply label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto apply(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent apply label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto apply(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent apply label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto apply(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent apply label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent apply label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent apply label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent apply label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent ascending label
      /// @return The created label.
      [[nodiscard]] static auto ascending() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ascending label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ascending(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ascending label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ascending(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ascending label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto ascending(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ascending label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ascending label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ascending label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ascending label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent back label
      /// @return The created label.
      [[nodiscard]] static auto back() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent back label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto back(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent back label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto back(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent back label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto back(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent back label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto back(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent back label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent back label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent back label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent bold label
      /// @return The created label.
      [[nodiscard]] static auto bold() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bold label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto bold(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bold label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto bold(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bold label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto bold(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bold label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bold label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bold label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bold label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent bottom label
      /// @return The created label.
      [[nodiscard]] static auto bottom() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bottom label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto bottom(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bottom label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto bottom(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bottom label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto bottom(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bottom label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bottom label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bottom label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent bottom label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent cancel label
      /// @return The created label.
      [[nodiscard]] static auto cancel() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cancel label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cancel(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cancel label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cancel(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cancel label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto cancel(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cancel label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cancel label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cancel label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cancel label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent cdrom label
      /// @return The created label.
      [[nodiscard]] static auto cdrom() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cdrom label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cdrom(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cdrom label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cdrom(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cdrom label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto cdrom(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cdrom label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cdrom label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cdrom label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cdrom label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent centered label
      /// @return The created label.
      [[nodiscard]] static auto centered() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent centered label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto centered(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent centered label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto centered(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent centered label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto centered(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent centered label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent centered label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent centered label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent centered label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent clear label
      /// @return The created label.
      [[nodiscard]] static auto clear() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent clear label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto clear(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent clear label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto clear(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent clear label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto clear(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent clear label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent clear label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent clear label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent clear label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent close label
      /// @return The created label.
      [[nodiscard]] static auto close() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent close label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto close(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent close label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto close(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent close label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto close(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent close label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto close(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent close label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent close label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent close label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent color label
      /// @return The created label.
      [[nodiscard]] static auto color() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent color label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto color(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent color label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto color(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent color label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto color(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent color label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto color(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent color label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent color label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent color label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent contents label
      /// @return The created label.
      [[nodiscard]] static auto contents() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent contents label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto contents(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent contents label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto contents(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent contents label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto contents(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent contents label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent contents label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent contents label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent contents label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent convert label
      /// @return The created label.
      [[nodiscard]] static auto convert() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent convert label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto convert(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent convert label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto convert(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent convert label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto convert(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent convert label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent convert label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent convert label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent convert label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent copy label
      /// @return The created label.
      [[nodiscard]] static auto copy() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent copy label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto copy(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent copy label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto copy(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent copy label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto copy(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent copy label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent copy label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent copy label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent copy label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent customize label
      /// @return The created label.
      [[nodiscard]] static auto customize() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent customize label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto customize(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent customize label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto customize(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent customize label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto customize(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent customize label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent customize label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent customize label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent customize label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent cut label
      /// @return The created label.
      [[nodiscard]] static auto cut() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cut label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cut(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cut label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cut(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cut label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto cut(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cut label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cut label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cut label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent cut label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent del label
      /// @return The created label.
      [[nodiscard]] static auto del() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent del label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto del(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent del label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto del(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent del label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto del(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent del label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto del(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent del label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent del label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent del label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent descending label
      /// @return The created label.
      [[nodiscard]] static auto descending() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent descending label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto descending(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent descending label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto descending(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent descending label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto descending(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent descending label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent descending label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent descending label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent descending label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent down label
      /// @return The created label.
      [[nodiscard]] static auto down() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent down label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto down(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent down label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto down(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent down label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto down(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent down label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto down(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent down label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent down label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent down label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent edit label
      /// @return The created label.
      [[nodiscard]] static auto edit() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent edit label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto edit(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent edit label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto edit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent edit label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto edit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent edit label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent edit label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent edit label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent edit label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent execute label
      /// @return The created label.
      [[nodiscard]] static auto execute() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent execute label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto execute(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent execute label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto execute(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent execute label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto execute(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent execute label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent execute label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent execute label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent execute label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent exit label
      /// @return The created label.
      [[nodiscard]] static auto exit() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent exit label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto exit(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent exit label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto exit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent exit label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto exit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent exit label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent exit label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent exit label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent exit label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent file label
      /// @return The created label.
      [[nodiscard]] static auto file() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent file label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto file(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent file label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto file(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent file label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto file(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent file label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto file(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent file label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent file label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent file label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent find label
      /// @return The created label.
      [[nodiscard]] static auto find() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent find label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto find(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent find label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto find(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent find label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto find(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent find label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto find(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent find label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent find label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent find label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent first label
      /// @return The created label.
      [[nodiscard]] static auto first() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent first label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto first(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent first label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto first(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent first label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto first(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent first label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto first(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent first label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent first label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent first label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent floppy label
      /// @return The created label.
      [[nodiscard]] static auto floppy() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent floppy label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto floppy(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent floppy label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto floppy(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent floppy label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto floppy(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent floppy label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent floppy label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent floppy label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent floppy label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent font label
      /// @return The created label.
      [[nodiscard]] static auto font() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent font label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto font(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent font label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto font(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent font label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto font(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent font label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto font(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent font label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent font label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent font label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent forward label
      /// @return The created label.
      [[nodiscard]] static auto forward() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent forward label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto forward(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent forward label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto forward(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent forward label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto forward(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent forward label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent forward label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent forward label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent forward label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent harddisk label
      /// @return The created label.
      [[nodiscard]] static auto harddisk() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent harddisk label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto harddisk(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent harddisk label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto harddisk(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent harddisk label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto harddisk(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent harddisk label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent harddisk label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent harddisk label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent harddisk label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent help label
      /// @return The created label.
      [[nodiscard]] static auto help() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent help label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto help(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent help label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto help(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent help label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto help(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent help label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto help(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent help label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent help label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent help label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent home label
      /// @return The created label.
      [[nodiscard]] static auto home() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent home label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto home(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent home label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto home(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent home label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto home(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent home label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto home(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent home label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent home label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent home label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent ignore label
      /// @return The created label.
      [[nodiscard]] static auto ignore() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ignore label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ignore(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ignore label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ignore(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ignore label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto ignore(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ignore label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ignore label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ignore label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ignore label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent indent label
      /// @return The created label.
      [[nodiscard]] static auto indent() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent indent label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto indent(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent indent label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto indent(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent indent label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto indent(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent indent label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent indent label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent indent label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent indent label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent index label
      /// @return The created label.
      [[nodiscard]] static auto index() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent index label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto index(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent index label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto index(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent index label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto index(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent index label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto index(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent index label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent index label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent index label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent info label
      /// @return The created label.
      [[nodiscard]] static auto info() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent info label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto info(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent info label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto info(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent info label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto info(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent info label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto info(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent info label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent info label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent info label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent italic label
      /// @return The created label.
      [[nodiscard]] static auto italic() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent italic label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto italic(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent italic label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto italic(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent italic label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto italic(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent italic label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent italic label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent italic label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent italic label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent justified label
      /// @return The created label.
      [[nodiscard]] static auto justified() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent justified label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto justified(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent justified label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto justified(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent justified label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto justified(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent justified label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent justified label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent justified label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent justified label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent jump_to label
      /// @return The created label.
      [[nodiscard]] static auto jump_to() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent jump_to label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto jump_to(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent jump_to label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto jump_to(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent jump_to label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto jump_to(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent jump_to label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent jump_to label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent jump_to label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent jump_to label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent last label
      /// @return The created label.
      [[nodiscard]] static auto last() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent last label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto last(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent last label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto last(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent last label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto last(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent last label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto last(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent last label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent last label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent last label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent network label
      /// @return The created label.
      [[nodiscard]] static auto network() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent network label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto network(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent network label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto network(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent network label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto network(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent network label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto network(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent network label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent network label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent network label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent new_ label
      /// @return The created label.
      [[nodiscard]] static auto new_() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent new_ label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto new_(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent new_ label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto new_(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent new_ label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto new_(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent new_ label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent new_ label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent new_ label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent new_ label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent next label
      /// @return The created label.
      [[nodiscard]] static auto next() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent next label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto next(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent next label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto next(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent next label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto next(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent next label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto next(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent next label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent next label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent next label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent no label
      /// @return The created label.
      [[nodiscard]] static auto no() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent no label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto no(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent no label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto no(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent no label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto no(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent no label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto no(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent no label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent no label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent no label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent ok label
      /// @return The created label.
      [[nodiscard]] static auto ok() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ok label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ok(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ok label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ok(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ok label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto ok(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ok label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ok label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ok label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent ok label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent open label
      /// @return The created label.
      [[nodiscard]] static auto open() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent open label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto open(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent open label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto open(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent open label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto open(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent open label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto open(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent open label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent open label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent open label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent options label
      /// @return The created label.
      [[nodiscard]] static auto options() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent options label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto options(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent options label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto options(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent options label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto options(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent options label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto options(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent options label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent options label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent options label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent paste label
      /// @return The created label.
      [[nodiscard]] static auto paste() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent paste label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto paste(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent paste label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto paste(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent paste label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto paste(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent paste label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent paste label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent paste label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent paste label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent preferences label
      /// @return The created label.
      [[nodiscard]] static auto preferences() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent preferences label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto preferences(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent preferences label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto preferences(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent preferences label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto preferences(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent preferences label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent preferences label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent preferences label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent preferences label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent previous label
      /// @return The created label.
      [[nodiscard]] static auto previous() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent previous label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto previous(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent previous label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto previous(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent previous label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto previous(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent previous label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent previous label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent previous label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent previous label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent print label
      /// @return The created label.
      [[nodiscard]] static auto print() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto print(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto print(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto print(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto print(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent print_preview label
      /// @return The created label.
      [[nodiscard]] static auto print_preview() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print_preview label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto print_preview(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print_preview label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto print_preview(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print_preview label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto print_preview(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print_preview label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print_preview label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print_preview label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent print_preview label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent properties label
      /// @return The created label.
      [[nodiscard]] static auto properties() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent properties label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto properties(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent properties label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto properties(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent properties label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto properties(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent properties label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent properties label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent properties label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent properties label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent quit label
      /// @return The created label.
      [[nodiscard]] static auto quit() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent quit label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto quit(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent quit label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto quit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent quit label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto quit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent quit label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent quit label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent quit label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent quit label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent redo label
      /// @return The created label.
      [[nodiscard]] static auto redo() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent redo label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto redo(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent redo label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto redo(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent redo label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto redo(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent redo label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent redo label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent redo label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent redo label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent refresh label
      /// @return The created label.
      [[nodiscard]] static auto refresh() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent refresh label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto refresh(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent refresh label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto refresh(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent refresh label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto refresh(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent refresh label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent refresh label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent refresh label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent refresh label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent remove label
      /// @return The created label.
      [[nodiscard]] static auto remove() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent remove label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto remove(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent remove label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto remove(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent remove label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto remove(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent remove label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent remove label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent remove label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent remove label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent replace label
      /// @return The created label.
      [[nodiscard]] static auto replace() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent replace label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto replace(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent replace label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto replace(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent replace label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto replace(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent replace label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent replace label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent replace label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent replace label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent retry label
      /// @return The created label.
      [[nodiscard]] static auto retry() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent retry label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto retry(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent retry label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto retry(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent retry label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto retry(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent retry label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent retry label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent retry label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent retry label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent revert_to_saved label
      /// @return The created label.
      [[nodiscard]] static auto revert_to_saved() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent revert_to_saved label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto revert_to_saved(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent revert_to_saved label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto revert_to_saved(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent revert_to_saved label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto revert_to_saved(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent revert_to_saved label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent revert_to_saved label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent revert_to_saved label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent revert_to_saved label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent save label
      /// @return The created label.
      [[nodiscard]] static auto save() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto save(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto save(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto save(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto save(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent save_as label
      /// @return The created label.
      [[nodiscard]] static auto save_as() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save_as label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto save_as(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save_as label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto save_as(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save_as label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto save_as(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save_as label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save_as label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save_as label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent save_as label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent search label
      /// @return The created label.
      [[nodiscard]] static auto search() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent search label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto search(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent search label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto search(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent search label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto search(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent search label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto search(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent search label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent search label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent search label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent select_all label
      /// @return The created label.
      [[nodiscard]] static auto select_all() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent select_all label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto select_all(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent select_all label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto select_all(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent select_all label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto select_all(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent select_all label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent select_all label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent select_all label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent select_all label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent settings label
      /// @return The created label.
      [[nodiscard]] static auto settings() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent settings label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto settings(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent settings label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto settings(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent settings label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto settings(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent settings label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent settings label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent settings label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent settings label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent spell_check label
      /// @return The created label.
      [[nodiscard]] static auto spell_check() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent spell_check label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto spell_check(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent spell_check label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto spell_check(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent spell_check label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto spell_check(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent spell_check label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent spell_check label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent spell_check label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent spell_check label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent stop label
      /// @return The created label.
      [[nodiscard]] static auto stop() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent stop label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto stop(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent stop label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto stop(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent stop label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto stop(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent stop label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent stop label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent stop label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent stop label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent strikeout label
      /// @return The created label.
      [[nodiscard]] static auto strikeout() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent strikeout label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto strikeout(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent strikeout label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto strikeout(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent strikeout label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto strikeout(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent strikeout label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent strikeout label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent strikeout label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent strikeout label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent tools label
      /// @return The created label.
      [[nodiscard]] static auto tools() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent tools label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto tools(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent tools label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto tools(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent tools label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto tools(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent tools label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent tools label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent tools label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent tools label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent top label
      /// @return The created label.
      [[nodiscard]] static auto top() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent top label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto top(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent top label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto top(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent top label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto top(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent top label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto top(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent top label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent top label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent top label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent undelete label
      /// @return The created label.
      [[nodiscard]] static auto undelete() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undelete label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto undelete(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undelete label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto undelete(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undelete label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto undelete(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undelete label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undelete label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undelete label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undelete label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent underline label
      /// @return The created label.
      [[nodiscard]] static auto underline() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent underline label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto underline(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent underline label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto underline(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent underline label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto underline(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent underline label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent underline label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent underline label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent underline label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent undo label
      /// @return The created label.
      [[nodiscard]] static auto undo() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undo label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto undo(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undo label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto undo(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undo label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto undo(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undo label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undo label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undo label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent undo label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent unindent label
      /// @return The created label.
      [[nodiscard]] static auto unindent() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent unindent label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto unindent(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent unindent label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto unindent(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent unindent label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto unindent(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent unindent label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent unindent label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent unindent label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent unindent label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent up label
      /// @return The created label.
      [[nodiscard]] static auto up() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent up label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto up(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent up label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto up(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent up label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto up(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent up label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto up(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent up label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent up label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent up label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent view label
      /// @return The created label.
      [[nodiscard]] static auto view() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent view label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto view(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent view label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto view(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent view label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto view(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent view label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto view(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent view label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent view label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent view label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent window label
      /// @return The created label.
      [[nodiscard]] static auto window() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent window label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto window(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent window label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto window(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent window label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto window(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent window label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto window(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent window label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent window label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent window label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent yes label
      /// @return The created label.
      [[nodiscard]] static auto yes() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent yes label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto yes(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent yes label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto yes(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent yes label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto yes(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent yes label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent yes label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent yes label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent yes label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent zoom_in label
      /// @return The created label.
      [[nodiscard]] static auto zoom_in() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_in label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_in(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_in label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_in(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_in label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto zoom_in(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_in label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_in label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_in label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_in label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent zoom_out label
      /// @return The created label.
      [[nodiscard]] static auto zoom_out() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_out label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_out(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_out label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_out(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_out label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto zoom_out(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_out label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_out label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_out label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_out label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      
      /// @brief Create a system-defined label that represent zoom_to_fit label
      /// @return The created label.
      [[nodiscard]] static auto zoom_to_fit() -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_to_fit(const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_to_fit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto zoom_to_fit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::label;
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::label;
      /// @}
    };
  }
}
