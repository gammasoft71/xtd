/// @file
/// @brief Contains xtd::forms::labels factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "label.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of label objects for use by a Windows Forms application.
    /// @par Header
    /// @code #include <xtd/forms/labels> @endcode
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
      static label abort();
      /// @brief Create a system-defined label that represent abort label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label abort(const drawing::point& location);
      /// @brief Create a system-defined label that represent abort label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label abort(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent abort label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label abort(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent abort label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label abort(const control& parent);
      /// @brief Create a system-defined label that represent abort label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label abort(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent abort label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label abort(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent abort label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label abort(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent about label
      /// @return The created label.
      static label about();
      /// @brief Create a system-defined label that represent about label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label about(const drawing::point& location);
      /// @brief Create a system-defined label that represent about label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label about(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent about label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label about(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent about label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label about(const control& parent);
      /// @brief Create a system-defined label that represent about label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label about(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent about label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label about(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent about label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label about(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent actual_size label
      /// @return The created label.
      static label actual_size();
      /// @brief Create a system-defined label that represent actual_size label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label actual_size(const drawing::point& location);
      /// @brief Create a system-defined label that represent actual_size label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label actual_size(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent actual_size label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label actual_size(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent actual_size label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label actual_size(const control& parent);
      /// @brief Create a system-defined label that represent actual_size label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label actual_size(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent actual_size label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label actual_size(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent actual_size label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label actual_size(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent add label
      /// @return The created label.
      static label add();
      /// @brief Create a system-defined label that represent add label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label add(const drawing::point& location);
      /// @brief Create a system-defined label that represent add label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label add(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent add label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label add(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent add label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label add(const control& parent);
      /// @brief Create a system-defined label that represent add label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label add(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent add label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label add(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent add label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label add(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent alignment label
      /// @return The created label.
      static label alignment();
      /// @brief Create a system-defined label that represent alignment label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label alignment(const drawing::point& location);
      /// @brief Create a system-defined label that represent alignment label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label alignment(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent alignment label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label alignment(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent alignment label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label alignment(const control& parent);
      /// @brief Create a system-defined label that represent alignment label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label alignment(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent alignment label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label alignment(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent alignment label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label alignment(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent align_left label
      /// @return The created label.
      static label align_left();
      /// @brief Create a system-defined label that represent align_left label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label align_left(const drawing::point& location);
      /// @brief Create a system-defined label that represent align_left label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label align_left(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent align_left label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label align_left(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent align_left label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label align_left(const control& parent);
      /// @brief Create a system-defined label that represent align_left label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label align_left(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent align_left label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label align_left(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent align_left label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label align_left(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent align_right label
      /// @return The created label.
      static label align_right();
      /// @brief Create a system-defined label that represent align_right label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label align_right(const drawing::point& location);
      /// @brief Create a system-defined label that represent align_right label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label align_right(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent align_right label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label align_right(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent align_right label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label align_right(const control& parent);
      /// @brief Create a system-defined label that represent align_right label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label align_right(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent align_right label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label align_right(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent align_right label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label align_right(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent apply label
      /// @return The created label.
      static label apply();
      /// @brief Create a system-defined label that represent apply label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label apply(const drawing::point& location);
      /// @brief Create a system-defined label that represent apply label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label apply(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent apply label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label apply(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent apply label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label apply(const control& parent);
      /// @brief Create a system-defined label that represent apply label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label apply(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent apply label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label apply(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent apply label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label apply(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent ascending label
      /// @return The created label.
      static label ascending();
      /// @brief Create a system-defined label that represent ascending label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label ascending(const drawing::point& location);
      /// @brief Create a system-defined label that represent ascending label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label ascending(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent ascending label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label ascending(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent ascending label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label ascending(const control& parent);
      /// @brief Create a system-defined label that represent ascending label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label ascending(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent ascending label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label ascending(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent ascending label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label ascending(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent back label
      /// @return The created label.
      static label back();
      /// @brief Create a system-defined label that represent back label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label back(const drawing::point& location);
      /// @brief Create a system-defined label that represent back label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label back(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent back label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label back(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent back label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label back(const control& parent);
      /// @brief Create a system-defined label that represent back label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label back(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent back label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label back(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent back label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label back(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent bold label
      /// @return The created label.
      static label bold();
      /// @brief Create a system-defined label that represent bold label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label bold(const drawing::point& location);
      /// @brief Create a system-defined label that represent bold label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label bold(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent bold label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label bold(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent bold label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label bold(const control& parent);
      /// @brief Create a system-defined label that represent bold label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label bold(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent bold label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label bold(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent bold label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label bold(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent bottom label
      /// @return The created label.
      static label bottom();
      /// @brief Create a system-defined label that represent bottom label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label bottom(const drawing::point& location);
      /// @brief Create a system-defined label that represent bottom label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label bottom(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent bottom label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label bottom(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent bottom label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label bottom(const control& parent);
      /// @brief Create a system-defined label that represent bottom label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label bottom(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent bottom label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label bottom(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent bottom label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label bottom(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent cancel label
      /// @return The created label.
      static label cancel();
      /// @brief Create a system-defined label that represent cancel label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label cancel(const drawing::point& location);
      /// @brief Create a system-defined label that represent cancel label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label cancel(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent cancel label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label cancel(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent cancel label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label cancel(const control& parent);
      /// @brief Create a system-defined label that represent cancel label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label cancel(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent cancel label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label cancel(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent cancel label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label cancel(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent cdrom label
      /// @return The created label.
      static label cdrom();
      /// @brief Create a system-defined label that represent cdrom label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label cdrom(const drawing::point& location);
      /// @brief Create a system-defined label that represent cdrom label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label cdrom(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent cdrom label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label cdrom(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent cdrom label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label cdrom(const control& parent);
      /// @brief Create a system-defined label that represent cdrom label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label cdrom(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent cdrom label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label cdrom(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent cdrom label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label cdrom(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent centered label
      /// @return The created label.
      static label centered();
      /// @brief Create a system-defined label that represent centered label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label centered(const drawing::point& location);
      /// @brief Create a system-defined label that represent centered label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label centered(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent centered label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label centered(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent centered label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label centered(const control& parent);
      /// @brief Create a system-defined label that represent centered label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label centered(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent centered label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label centered(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent centered label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label centered(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent clear label
      /// @return The created label.
      static label clear();
      /// @brief Create a system-defined label that represent clear label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label clear(const drawing::point& location);
      /// @brief Create a system-defined label that represent clear label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label clear(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent clear label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label clear(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent clear label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label clear(const control& parent);
      /// @brief Create a system-defined label that represent clear label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label clear(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent clear label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label clear(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent clear label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label clear(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent close label
      /// @return The created label.
      static label close();
      /// @brief Create a system-defined label that represent close label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label close(const drawing::point& location);
      /// @brief Create a system-defined label that represent close label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label close(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent close label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label close(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent close label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label close(const control& parent);
      /// @brief Create a system-defined label that represent close label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label close(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent close label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label close(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent close label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label close(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent color label
      /// @return The created label.
      static label color();
      /// @brief Create a system-defined label that represent color label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label color(const drawing::point& location);
      /// @brief Create a system-defined label that represent color label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label color(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent color label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label color(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent color label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label color(const control& parent);
      /// @brief Create a system-defined label that represent color label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label color(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent color label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label color(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent color label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label color(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent contents label
      /// @return The created label.
      static label contents();
      /// @brief Create a system-defined label that represent contents label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label contents(const drawing::point& location);
      /// @brief Create a system-defined label that represent contents label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label contents(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent contents label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label contents(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent contents label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label contents(const control& parent);
      /// @brief Create a system-defined label that represent contents label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label contents(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent contents label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label contents(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent contents label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label contents(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent convert label
      /// @return The created label.
      static label convert();
      /// @brief Create a system-defined label that represent convert label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label convert(const drawing::point& location);
      /// @brief Create a system-defined label that represent convert label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label convert(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent convert label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label convert(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent convert label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label convert(const control& parent);
      /// @brief Create a system-defined label that represent convert label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label convert(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent convert label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label convert(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent convert label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label convert(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent copy label
      /// @return The created label.
      static label copy();
      /// @brief Create a system-defined label that represent copy label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label copy(const drawing::point& location);
      /// @brief Create a system-defined label that represent copy label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label copy(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent copy label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label copy(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent copy label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label copy(const control& parent);
      /// @brief Create a system-defined label that represent copy label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label copy(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent copy label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label copy(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent copy label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label copy(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent customize label
      /// @return The created label.
      static label customize();
      /// @brief Create a system-defined label that represent customize label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label customize(const drawing::point& location);
      /// @brief Create a system-defined label that represent customize label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label customize(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent customize label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label customize(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent customize label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label customize(const control& parent);
      /// @brief Create a system-defined label that represent customize label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label customize(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent customize label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label customize(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent customize label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label customize(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent cut label
      /// @return The created label.
      static label cut();
      /// @brief Create a system-defined label that represent cut label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label cut(const drawing::point& location);
      /// @brief Create a system-defined label that represent cut label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label cut(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent cut label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label cut(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent cut label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label cut(const control& parent);
      /// @brief Create a system-defined label that represent cut label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label cut(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent cut label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label cut(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent cut label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label cut(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent del label
      /// @return The created label.
      static label del();
      /// @brief Create a system-defined label that represent del label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label del(const drawing::point& location);
      /// @brief Create a system-defined label that represent del label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label del(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent del label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label del(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent del label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label del(const control& parent);
      /// @brief Create a system-defined label that represent del label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label del(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent del label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label del(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent del label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label del(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent descending label
      /// @return The created label.
      static label descending();
      /// @brief Create a system-defined label that represent descending label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label descending(const drawing::point& location);
      /// @brief Create a system-defined label that represent descending label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label descending(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent descending label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label descending(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent descending label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label descending(const control& parent);
      /// @brief Create a system-defined label that represent descending label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label descending(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent descending label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label descending(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent descending label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label descending(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent down label
      /// @return The created label.
      static label down();
      /// @brief Create a system-defined label that represent down label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label down(const drawing::point& location);
      /// @brief Create a system-defined label that represent down label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label down(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent down label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label down(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent down label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label down(const control& parent);
      /// @brief Create a system-defined label that represent down label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label down(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent down label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label down(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent down label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label down(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent edit label
      /// @return The created label.
      static label edit();
      /// @brief Create a system-defined label that represent edit label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label edit(const drawing::point& location);
      /// @brief Create a system-defined label that represent edit label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label edit(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent edit label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label edit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent edit label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label edit(const control& parent);
      /// @brief Create a system-defined label that represent edit label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label edit(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent edit label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label edit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent edit label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label edit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent execute label
      /// @return The created label.
      static label execute();
      /// @brief Create a system-defined label that represent execute label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label execute(const drawing::point& location);
      /// @brief Create a system-defined label that represent execute label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label execute(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent execute label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label execute(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent execute label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label execute(const control& parent);
      /// @brief Create a system-defined label that represent execute label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label execute(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent execute label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label execute(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent execute label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label execute(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent exit label
      /// @return The created label.
      static label exit();
      /// @brief Create a system-defined label that represent exit label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label exit(const drawing::point& location);
      /// @brief Create a system-defined label that represent exit label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label exit(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent exit label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label exit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent exit label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label exit(const control& parent);
      /// @brief Create a system-defined label that represent exit label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label exit(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent exit label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label exit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent exit label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label exit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent file label
      /// @return The created label.
      static label file();
      /// @brief Create a system-defined label that represent file label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label file(const drawing::point& location);
      /// @brief Create a system-defined label that represent file label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label file(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent file label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label file(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent file label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label file(const control& parent);
      /// @brief Create a system-defined label that represent file label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label file(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent file label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label file(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent file label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label file(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent find label
      /// @return The created label.
      static label find();
      /// @brief Create a system-defined label that represent find label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label find(const drawing::point& location);
      /// @brief Create a system-defined label that represent find label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label find(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent find label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label find(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent find label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label find(const control& parent);
      /// @brief Create a system-defined label that represent find label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label find(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent find label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label find(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent find label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label find(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent first label
      /// @return The created label.
      static label first();
      /// @brief Create a system-defined label that represent first label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label first(const drawing::point& location);
      /// @brief Create a system-defined label that represent first label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label first(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent first label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label first(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent first label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label first(const control& parent);
      /// @brief Create a system-defined label that represent first label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label first(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent first label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label first(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent first label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label first(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent floppy label
      /// @return The created label.
      static label floppy();
      /// @brief Create a system-defined label that represent floppy label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label floppy(const drawing::point& location);
      /// @brief Create a system-defined label that represent floppy label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label floppy(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent floppy label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label floppy(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent floppy label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label floppy(const control& parent);
      /// @brief Create a system-defined label that represent floppy label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label floppy(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent floppy label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label floppy(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent floppy label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label floppy(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent font label
      /// @return The created label.
      static label font();
      /// @brief Create a system-defined label that represent font label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label font(const drawing::point& location);
      /// @brief Create a system-defined label that represent font label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label font(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent font label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label font(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent font label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label font(const control& parent);
      /// @brief Create a system-defined label that represent font label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label font(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent font label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label font(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent font label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label font(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent forward label
      /// @return The created label.
      static label forward();
      /// @brief Create a system-defined label that represent forward label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label forward(const drawing::point& location);
      /// @brief Create a system-defined label that represent forward label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label forward(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent forward label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label forward(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent forward label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label forward(const control& parent);
      /// @brief Create a system-defined label that represent forward label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label forward(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent forward label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label forward(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent forward label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label forward(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent harddisk label
      /// @return The created label.
      static label harddisk();
      /// @brief Create a system-defined label that represent harddisk label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label harddisk(const drawing::point& location);
      /// @brief Create a system-defined label that represent harddisk label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label harddisk(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent harddisk label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label harddisk(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent harddisk label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label harddisk(const control& parent);
      /// @brief Create a system-defined label that represent harddisk label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label harddisk(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent harddisk label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label harddisk(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent harddisk label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label harddisk(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent help label
      /// @return The created label.
      static label help();
      /// @brief Create a system-defined label that represent help label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label help(const drawing::point& location);
      /// @brief Create a system-defined label that represent help label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label help(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent help label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label help(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent help label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label help(const control& parent);
      /// @brief Create a system-defined label that represent help label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label help(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent help label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label help(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent help label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label help(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent home label
      /// @return The created label.
      static label home();
      /// @brief Create a system-defined label that represent home label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label home(const drawing::point& location);
      /// @brief Create a system-defined label that represent home label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label home(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent home label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label home(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent home label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label home(const control& parent);
      /// @brief Create a system-defined label that represent home label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label home(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent home label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label home(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent home label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label home(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent ignore label
      /// @return The created label.
      static label ignore();
      /// @brief Create a system-defined label that represent ignore label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label ignore(const drawing::point& location);
      /// @brief Create a system-defined label that represent ignore label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label ignore(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent ignore label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label ignore(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent ignore label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label ignore(const control& parent);
      /// @brief Create a system-defined label that represent ignore label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label ignore(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent ignore label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label ignore(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent ignore label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label ignore(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent indent label
      /// @return The created label.
      static label indent();
      /// @brief Create a system-defined label that represent indent label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label indent(const drawing::point& location);
      /// @brief Create a system-defined label that represent indent label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label indent(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent indent label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label indent(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent indent label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label indent(const control& parent);
      /// @brief Create a system-defined label that represent indent label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label indent(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent indent label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label indent(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent indent label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label indent(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent index label
      /// @return The created label.
      static label index();
      /// @brief Create a system-defined label that represent index label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label index(const drawing::point& location);
      /// @brief Create a system-defined label that represent index label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label index(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent index label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label index(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent index label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label index(const control& parent);
      /// @brief Create a system-defined label that represent index label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label index(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent index label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label index(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent index label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label index(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent info label
      /// @return The created label.
      static label info();
      /// @brief Create a system-defined label that represent info label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label info(const drawing::point& location);
      /// @brief Create a system-defined label that represent info label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label info(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent info label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label info(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent info label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label info(const control& parent);
      /// @brief Create a system-defined label that represent info label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label info(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent info label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label info(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent info label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label info(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent italic label
      /// @return The created label.
      static label italic();
      /// @brief Create a system-defined label that represent italic label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label italic(const drawing::point& location);
      /// @brief Create a system-defined label that represent italic label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label italic(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent italic label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label italic(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent italic label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label italic(const control& parent);
      /// @brief Create a system-defined label that represent italic label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label italic(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent italic label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label italic(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent italic label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label italic(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent justified label
      /// @return The created label.
      static label justified();
      /// @brief Create a system-defined label that represent justified label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label justified(const drawing::point& location);
      /// @brief Create a system-defined label that represent justified label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label justified(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent justified label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label justified(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent justified label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label justified(const control& parent);
      /// @brief Create a system-defined label that represent justified label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label justified(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent justified label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label justified(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent justified label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label justified(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent jump_to label
      /// @return The created label.
      static label jump_to();
      /// @brief Create a system-defined label that represent jump_to label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label jump_to(const drawing::point& location);
      /// @brief Create a system-defined label that represent jump_to label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label jump_to(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent jump_to label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label jump_to(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent jump_to label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label jump_to(const control& parent);
      /// @brief Create a system-defined label that represent jump_to label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label jump_to(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent jump_to label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label jump_to(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent jump_to label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label jump_to(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent last label
      /// @return The created label.
      static label last();
      /// @brief Create a system-defined label that represent last label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label last(const drawing::point& location);
      /// @brief Create a system-defined label that represent last label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label last(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent last label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label last(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent last label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label last(const control& parent);
      /// @brief Create a system-defined label that represent last label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label last(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent last label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label last(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent last label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label last(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent network label
      /// @return The created label.
      static label network();
      /// @brief Create a system-defined label that represent network label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label network(const drawing::point& location);
      /// @brief Create a system-defined label that represent network label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label network(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent network label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label network(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent network label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label network(const control& parent);
      /// @brief Create a system-defined label that represent network label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label network(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent network label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label network(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent network label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label network(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent new_ label
      /// @return The created label.
      static label new_();
      /// @brief Create a system-defined label that represent new_ label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label new_(const drawing::point& location);
      /// @brief Create a system-defined label that represent new_ label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label new_(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent new_ label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label new_(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent new_ label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label new_(const control& parent);
      /// @brief Create a system-defined label that represent new_ label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label new_(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent new_ label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label new_(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent new_ label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label new_(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent next label
      /// @return The created label.
      static label next();
      /// @brief Create a system-defined label that represent next label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label next(const drawing::point& location);
      /// @brief Create a system-defined label that represent next label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label next(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent next label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label next(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent next label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label next(const control& parent);
      /// @brief Create a system-defined label that represent next label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label next(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent next label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label next(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent next label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label next(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent no label
      /// @return The created label.
      static label no();
      /// @brief Create a system-defined label that represent no label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label no(const drawing::point& location);
      /// @brief Create a system-defined label that represent no label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label no(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent no label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label no(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent no label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label no(const control& parent);
      /// @brief Create a system-defined label that represent no label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label no(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent no label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label no(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent no label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label no(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent ok label
      /// @return The created label.
      static label ok();
      /// @brief Create a system-defined label that represent ok label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label ok(const drawing::point& location);
      /// @brief Create a system-defined label that represent ok label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label ok(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent ok label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label ok(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent ok label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label ok(const control& parent);
      /// @brief Create a system-defined label that represent ok label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label ok(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent ok label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label ok(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent ok label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label ok(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent open label
      /// @return The created label.
      static label open();
      /// @brief Create a system-defined label that represent open label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label open(const drawing::point& location);
      /// @brief Create a system-defined label that represent open label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label open(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent open label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label open(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent open label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label open(const control& parent);
      /// @brief Create a system-defined label that represent open label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label open(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent open label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label open(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent open label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label open(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent options label
      /// @return The created label.
      static label options();
      /// @brief Create a system-defined label that represent options label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label options(const drawing::point& location);
      /// @brief Create a system-defined label that represent options label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label options(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent options label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label options(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent options label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label options(const control& parent);
      /// @brief Create a system-defined label that represent options label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label options(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent options label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label options(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent options label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label options(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent paste label
      /// @return The created label.
      static label paste();
      /// @brief Create a system-defined label that represent paste label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label paste(const drawing::point& location);
      /// @brief Create a system-defined label that represent paste label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label paste(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent paste label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label paste(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent paste label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label paste(const control& parent);
      /// @brief Create a system-defined label that represent paste label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label paste(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent paste label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label paste(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent paste label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label paste(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent preferences label
      /// @return The created label.
      static label preferences();
      /// @brief Create a system-defined label that represent preferences label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label preferences(const drawing::point& location);
      /// @brief Create a system-defined label that represent preferences label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label preferences(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent preferences label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label preferences(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent preferences label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label preferences(const control& parent);
      /// @brief Create a system-defined label that represent preferences label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label preferences(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent preferences label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label preferences(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent preferences label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label preferences(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent previous label
      /// @return The created label.
      static label previous();
      /// @brief Create a system-defined label that represent previous label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label previous(const drawing::point& location);
      /// @brief Create a system-defined label that represent previous label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label previous(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent previous label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label previous(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent previous label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label previous(const control& parent);
      /// @brief Create a system-defined label that represent previous label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label previous(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent previous label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label previous(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent previous label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label previous(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent print label
      /// @return The created label.
      static label print();
      /// @brief Create a system-defined label that represent print label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label print(const drawing::point& location);
      /// @brief Create a system-defined label that represent print label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label print(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent print label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label print(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent print label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label print(const control& parent);
      /// @brief Create a system-defined label that represent print label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label print(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent print label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label print(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent print label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label print(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent print_preview label
      /// @return The created label.
      static label print_preview();
      /// @brief Create a system-defined label that represent print_preview label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label print_preview(const drawing::point& location);
      /// @brief Create a system-defined label that represent print_preview label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label print_preview(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent print_preview label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label print_preview(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent print_preview label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label print_preview(const control& parent);
      /// @brief Create a system-defined label that represent print_preview label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label print_preview(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent print_preview label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label print_preview(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent print_preview label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label print_preview(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent properties label
      /// @return The created label.
      static label properties();
      /// @brief Create a system-defined label that represent properties label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label properties(const drawing::point& location);
      /// @brief Create a system-defined label that represent properties label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label properties(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent properties label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label properties(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent properties label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label properties(const control& parent);
      /// @brief Create a system-defined label that represent properties label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label properties(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent properties label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label properties(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent properties label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label properties(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent quit label
      /// @return The created label.
      static label quit();
      /// @brief Create a system-defined label that represent quit label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label quit(const drawing::point& location);
      /// @brief Create a system-defined label that represent quit label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label quit(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent quit label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label quit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent quit label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label quit(const control& parent);
      /// @brief Create a system-defined label that represent quit label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label quit(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent quit label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label quit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent quit label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label quit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent redo label
      /// @return The created label.
      static label redo();
      /// @brief Create a system-defined label that represent redo label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label redo(const drawing::point& location);
      /// @brief Create a system-defined label that represent redo label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label redo(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent redo label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label redo(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent redo label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label redo(const control& parent);
      /// @brief Create a system-defined label that represent redo label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label redo(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent redo label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label redo(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent redo label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label redo(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent refresh label
      /// @return The created label.
      static label refresh();
      /// @brief Create a system-defined label that represent refresh label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label refresh(const drawing::point& location);
      /// @brief Create a system-defined label that represent refresh label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label refresh(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent refresh label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label refresh(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent refresh label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label refresh(const control& parent);
      /// @brief Create a system-defined label that represent refresh label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label refresh(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent refresh label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label refresh(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent refresh label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label refresh(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent remove label
      /// @return The created label.
      static label remove();
      /// @brief Create a system-defined label that represent remove label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label remove(const drawing::point& location);
      /// @brief Create a system-defined label that represent remove label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label remove(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent remove label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label remove(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent remove label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label remove(const control& parent);
      /// @brief Create a system-defined label that represent remove label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label remove(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent remove label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label remove(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent remove label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label remove(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent replace label
      /// @return The created label.
      static label replace();
      /// @brief Create a system-defined label that represent replace label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label replace(const drawing::point& location);
      /// @brief Create a system-defined label that represent replace label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label replace(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent replace label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label replace(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent replace label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label replace(const control& parent);
      /// @brief Create a system-defined label that represent replace label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label replace(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent replace label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label replace(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent replace label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label replace(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent retry label
      /// @return The created label.
      static label retry();
      /// @brief Create a system-defined label that represent retry label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label retry(const drawing::point& location);
      /// @brief Create a system-defined label that represent retry label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label retry(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent retry label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label retry(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent retry label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label retry(const control& parent);
      /// @brief Create a system-defined label that represent retry label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label retry(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent retry label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label retry(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent retry label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label retry(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent revert_to_saved label
      /// @return The created label.
      static label revert_to_saved();
      /// @brief Create a system-defined label that represent revert_to_saved label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label revert_to_saved(const drawing::point& location);
      /// @brief Create a system-defined label that represent revert_to_saved label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label revert_to_saved(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent revert_to_saved label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label revert_to_saved(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent revert_to_saved label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label revert_to_saved(const control& parent);
      /// @brief Create a system-defined label that represent revert_to_saved label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label revert_to_saved(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent revert_to_saved label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label revert_to_saved(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent revert_to_saved label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label revert_to_saved(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent save label
      /// @return The created label.
      static label save();
      /// @brief Create a system-defined label that represent save label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label save(const drawing::point& location);
      /// @brief Create a system-defined label that represent save label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label save(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent save label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label save(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent save label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label save(const control& parent);
      /// @brief Create a system-defined label that represent save label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label save(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent save label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label save(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent save label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label save(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent save_as label
      /// @return The created label.
      static label save_as();
      /// @brief Create a system-defined label that represent save_as label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label save_as(const drawing::point& location);
      /// @brief Create a system-defined label that represent save_as label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label save_as(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent save_as label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label save_as(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent save_as label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label save_as(const control& parent);
      /// @brief Create a system-defined label that represent save_as label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label save_as(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent save_as label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label save_as(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent save_as label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label save_as(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent search label
      /// @return The created label.
      static label search();
      /// @brief Create a system-defined label that represent search label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label search(const drawing::point& location);
      /// @brief Create a system-defined label that represent search label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label search(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent search label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label search(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent search label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label search(const control& parent);
      /// @brief Create a system-defined label that represent search label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label search(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent search label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label search(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent search label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label search(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent select_all label
      /// @return The created label.
      static label select_all();
      /// @brief Create a system-defined label that represent select_all label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label select_all(const drawing::point& location);
      /// @brief Create a system-defined label that represent select_all label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label select_all(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent select_all label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label select_all(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent select_all label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label select_all(const control& parent);
      /// @brief Create a system-defined label that represent select_all label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label select_all(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent select_all label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label select_all(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent select_all label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label select_all(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent settings label
      /// @return The created label.
      static label settings();
      /// @brief Create a system-defined label that represent settings label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label settings(const drawing::point& location);
      /// @brief Create a system-defined label that represent settings label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label settings(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent settings label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label settings(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent settings label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label settings(const control& parent);
      /// @brief Create a system-defined label that represent settings label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label settings(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent settings label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label settings(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent settings label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label settings(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent spell_check label
      /// @return The created label.
      static label spell_check();
      /// @brief Create a system-defined label that represent spell_check label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label spell_check(const drawing::point& location);
      /// @brief Create a system-defined label that represent spell_check label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label spell_check(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent spell_check label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label spell_check(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent spell_check label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label spell_check(const control& parent);
      /// @brief Create a system-defined label that represent spell_check label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label spell_check(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent spell_check label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label spell_check(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent spell_check label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label spell_check(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent stop label
      /// @return The created label.
      static label stop();
      /// @brief Create a system-defined label that represent stop label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label stop(const drawing::point& location);
      /// @brief Create a system-defined label that represent stop label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label stop(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent stop label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label stop(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent stop label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label stop(const control& parent);
      /// @brief Create a system-defined label that represent stop label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label stop(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent stop label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label stop(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent stop label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label stop(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent strikeout label
      /// @return The created label.
      static label strikeout();
      /// @brief Create a system-defined label that represent strikeout label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label strikeout(const drawing::point& location);
      /// @brief Create a system-defined label that represent strikeout label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label strikeout(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent strikeout label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label strikeout(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent strikeout label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label strikeout(const control& parent);
      /// @brief Create a system-defined label that represent strikeout label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label strikeout(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent strikeout label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label strikeout(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent strikeout label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label strikeout(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent tools label
      /// @return The created label.
      static label tools();
      /// @brief Create a system-defined label that represent tools label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label tools(const drawing::point& location);
      /// @brief Create a system-defined label that represent tools label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label tools(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent tools label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label tools(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent tools label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label tools(const control& parent);
      /// @brief Create a system-defined label that represent tools label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label tools(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent tools label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label tools(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent tools label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label tools(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent top label
      /// @return The created label.
      static label top();
      /// @brief Create a system-defined label that represent top label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label top(const drawing::point& location);
      /// @brief Create a system-defined label that represent top label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label top(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent top label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label top(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent top label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label top(const control& parent);
      /// @brief Create a system-defined label that represent top label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label top(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent top label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label top(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent top label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label top(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent undelete label
      /// @return The created label.
      static label undelete();
      /// @brief Create a system-defined label that represent undelete label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label undelete(const drawing::point& location);
      /// @brief Create a system-defined label that represent undelete label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label undelete(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent undelete label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label undelete(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent undelete label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label undelete(const control& parent);
      /// @brief Create a system-defined label that represent undelete label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label undelete(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent undelete label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label undelete(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent undelete label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label undelete(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent underline label
      /// @return The created label.
      static label underline();
      /// @brief Create a system-defined label that represent underline label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label underline(const drawing::point& location);
      /// @brief Create a system-defined label that represent underline label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label underline(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent underline label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label underline(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent underline label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label underline(const control& parent);
      /// @brief Create a system-defined label that represent underline label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label underline(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent underline label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label underline(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent underline label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label underline(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent undo label
      /// @return The created label.
      static label undo();
      /// @brief Create a system-defined label that represent undo label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label undo(const drawing::point& location);
      /// @brief Create a system-defined label that represent undo label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label undo(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent undo label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label undo(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent undo label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label undo(const control& parent);
      /// @brief Create a system-defined label that represent undo label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label undo(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent undo label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label undo(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent undo label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label undo(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent unindent label
      /// @return The created label.
      static label unindent();
      /// @brief Create a system-defined label that represent unindent label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label unindent(const drawing::point& location);
      /// @brief Create a system-defined label that represent unindent label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label unindent(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent unindent label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label unindent(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent unindent label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label unindent(const control& parent);
      /// @brief Create a system-defined label that represent unindent label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label unindent(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent unindent label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label unindent(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent unindent label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label unindent(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent up label
      /// @return The created label.
      static label up();
      /// @brief Create a system-defined label that represent up label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label up(const drawing::point& location);
      /// @brief Create a system-defined label that represent up label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label up(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent up label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label up(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent up label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label up(const control& parent);
      /// @brief Create a system-defined label that represent up label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label up(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent up label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label up(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent up label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label up(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent view label
      /// @return The created label.
      static label view();
      /// @brief Create a system-defined label that represent view label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label view(const drawing::point& location);
      /// @brief Create a system-defined label that represent view label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label view(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent view label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label view(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent view label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label view(const control& parent);
      /// @brief Create a system-defined label that represent view label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label view(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent view label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label view(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent view label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label view(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent window label
      /// @return The created label.
      static label window();
      /// @brief Create a system-defined label that represent window label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label window(const drawing::point& location);
      /// @brief Create a system-defined label that represent window label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label window(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent window label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label window(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent window label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label window(const control& parent);
      /// @brief Create a system-defined label that represent window label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label window(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent window label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label window(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent window label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label window(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent yes label
      /// @return The created label.
      static label yes();
      /// @brief Create a system-defined label that represent yes label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label yes(const drawing::point& location);
      /// @brief Create a system-defined label that represent yes label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label yes(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent yes label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label yes(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent yes label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label yes(const control& parent);
      /// @brief Create a system-defined label that represent yes label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label yes(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent yes label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label yes(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent yes label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label yes(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent zoom_in label
      /// @return The created label.
      static label zoom_in();
      /// @brief Create a system-defined label that represent zoom_in label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label zoom_in(const drawing::point& location);
      /// @brief Create a system-defined label that represent zoom_in label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label zoom_in(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent zoom_in label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label zoom_in(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent zoom_in label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label zoom_in(const control& parent);
      /// @brief Create a system-defined label that represent zoom_in label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label zoom_in(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent zoom_in label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label zoom_in(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent zoom_in label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label zoom_in(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent zoom_out label
      /// @return The created label.
      static label zoom_out();
      /// @brief Create a system-defined label that represent zoom_out label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label zoom_out(const drawing::point& location);
      /// @brief Create a system-defined label that represent zoom_out label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label zoom_out(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent zoom_out label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label zoom_out(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent zoom_out label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label zoom_out(const control& parent);
      /// @brief Create a system-defined label that represent zoom_out label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label zoom_out(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent zoom_out label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label zoom_out(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent zoom_out label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label zoom_out(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// @brief Create a system-defined label that represent zoom_to_fit label
      /// @return The created label.
      static label zoom_to_fit();
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified location.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label zoom_to_fit(const drawing::point& location);
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified location, and size.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label zoom_to_fit(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified location, size, and name.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label zoom_to_fit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified parent.
      /// @param parent The control that contains the label.
      /// @return The created label.
      static label zoom_to_fit(const control& parent);
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified parent, and location.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @return The created label.
      static label zoom_to_fit(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified parent, location, and size.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @return The created label.
      static label zoom_to_fit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined label that represent zoom_to_fit label with specified parent, location, size, and name.
      /// @param parent The control that contains the label.
      /// @param location The label location in pixels.
      /// @param size The label size in pixels.
      /// @param name The name of the label.
      /// @return The created label.
      static label zoom_to_fit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
    };
  }
}
