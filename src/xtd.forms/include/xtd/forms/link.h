/// @file
/// @brief Contains xtd::forms::link class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <tuple>
#include <xtd/object.h>
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class link_label;
    /// @endcond
    
    /// @brief Represents a link within a xtd::forms::link_label control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The xtd::forms::link_label::link class defines the properties of a link within a xtd::forms::link_label control. You can use these properties to provide data to the xtd::forms::link_label::link_clicked event of the xtd::forms::link_label control to perform tasks when the link is clicked in the control. The xtd::forms::link_label::link_data property enables you to define information that the xtd::forms::link_label::link_clicked event can use to display a URL within your web browser or to open a file.
    /// @remarks In addition to information related to the link, the properties of the xtd::forms::link_label::link class also help define the text of thextd::forms::link_label::lLink and its display state. The xtd::forms::link_label::start and xtd::forms::link_label::length properties define the location and length of text from the text of the xtd::forms::link_label control to display as a link. The xtd::forms::link_label::enabled property allows you to display the link as a disabled link, and the xtd::forms::link_label::visited property can alert the user that they already visited the specified link in the current instance of the xtd::forms::link_label.
    /// @remarks You can display multiple links in a single xtd::forms::link_label control. Each xtd::forms::link_label::link is added into the xtd::forms::link_label::link_collection associated with the xtd::forms::link_label control. To obtain the collection of links defined in a xtd::forms::link_label control, use the xtd::forms::link_label::links property.
    class link : public object {
    public:
      /// @brief Initializes a new instance of the xtd::forms::link class.
      link() = default;
      /// @brief Initializes a new instance of the xtd::forms::link_label::link class with the specified starting location and number of characters after the starting location within the xtd::forms::link_label.
      /// @param start The zero-based starting location of the link area within the text of the xtd::forms::link_label.
      /// @param length The number of characters, after the starting character, to include in the link area.
      link(size_t start, size_t length);
      /// @brief Initializes a new instance of the xtd::forms::link_label::link class with the specified starting location, number of characters after the starting location within the xtd::forms::link_label, and the data associated with the link.
      /// @param start The zero-based starting location of the link area within the text of the xtd::forms::link_label.
      /// @param length The number of characters, after the starting character, to include in the link area.
      /// @param link_data The data associated with the link.
      link(size_t start, size_t length, std::any link_data);
      /// @cond
      link(const link&) = default;
      link(link&&) = default;
      link& operator=(const link&) = default;
      bool operator==(const link& other) const {return enabled_ == other.enabled_ && length_ == other.length_ && name_ == other.name_ && start_ == other.start_;}
      bool operator!=(const link& other) const {return !operator==(other);}
      /// @endcond

      /// @brief Gets a text description of the link.
      /// @return A xtd::ustring representing a text description of the link.
      const xtd::ustring& description() const;
      /// @brief Sets a text description of the link.
      /// @param value A xtd::ustring representing a text description of the link.
      /// @return The current instance of xtd::forms::link_label::link.
      link& description(const xtd::ustring& value);
      
      /// @brief Gets a value indicating whether the link is enabled.
      /// @return true if the link is enabled; otherwise, false.
      /// @remarks You can use this property to display a link in a disabled state within the xtd::forms::link_label control. When a link is disabled, clicking on the link does not cause the xtd::forms::link_label control to raise the xtd::forms::link_label::link_clicked event.
      bool enabled() const;
      /// @brief Sets a value indicating whether the link is enabled.
      /// @param value true if the link is enabled; otherwise, false.
      /// @return The current instance of xtd::forms::link_label::link.
      /// @remarks You can use this property to display a link in a disabled state within the xtd::forms::link_label control. When a link is disabled, clicking on the link does not cause the xtd::forms::link_label control to raise the xtd::forms::link_label::link_clicked event.
      link& enabled(bool value);
      
      /// @brief Gets the number of characters in the link text.
      /// @return The number of characters, including spaces, in the link text.
      /// @remarks To specify text from the xtd::forms::link_label to display as a link, set the xtd::forms::link_label::start property to the location in the text to start creating the link. After the xtd::forms::link_label::start property is set, set the value of the xtd::forms::link_label::length property to the number of characters, including the character position specified in the xtd::forms::link_label::start property, that you want to make the link text. For example, if you want to make the first word of the text "The quick brown fox" a link, you set the xtd::forms::link_label::start property to zero (0) and the xtd::forms::link_label::length property to three (3).
      size_t length() const;
      /// @brief Sets the number of characters in the link text.
      /// @param value The number of characters, including spaces, in the link text.
      /// @return The current instance of xtd::forms::link_label::link.
      /// @remarks To specify text from the xtd::forms::link_label to display as a link, set the xtd::forms::link_label::start property to the location in the text to start creating the link. After the xtd::forms::link_label::start property is set, set the value of the xtd::forms::link_label::length property to the number of characters, including the character position specified in the xtd::forms::link_label::start property, that you want to make the link text. For example, if you want to make the first word of the text "The quick brown fox" a link, you set the xtd::forms::link_label::start property to zero (0) and the xtd::forms::link_label::length property to three (3).
      link& length(size_t value);
      
      /// @brief Gets the data associated with the link.
      /// @return A std::any object representing the data associated with the link.
      /// @remarks You can use this property to supply information related to the link. The information provided by this property can be used within the xtd::forms::link_label::link_clicked event of the xtd::forms::link_label to provide information about the link that can be used to process the link being clicked. For example, you can specify the URL to display in your web browser when the link is clicked as the value of the xtd::forms::link_label::link_data property. You can also use the xtd::forms::link_label::link_data property to identify a dialog to display when the user clicks on the link.
      std::any link_data() const;
      /// @brief Sets the data associated with the link.
      /// @param value A std::any object representing the data associated with the link.
      /// @return The current instance of xtd::forms::link_label::link.
      /// @remarks You can use this property to supply information related to the link. The information provided by this property can be used within the xtd::forms::link_label::link_clicked event of the xtd::forms::link_label to provide information about the link that can be used to process the link being clicked. For example, you can specify the URL to display in your web browser when the link is clicked as the value of the xtd::forms::link_label::link_data property. You can also use the xtd::forms::link_label::link_data property to identify a dialog to display when the user clicks on the link.
      link& link_data(std::any value);
      
      /// @brief Gets the name of the xtd::forms::link_label::link.
      /// @return A xtd::ustring representing the name of the xtd::forms::link_label::link. The default value is the empty string ("").
      const xtd::ustring& name() const;
      /// @brief Sets the name of the xtd::forms::link_label::link.
      /// @param value A xtd::ustring representing the name of the xtd::forms::link_label::link. The default value is the empty string ("").
      /// @return The current instance of xtd::forms::link_label::link.
      link& name(const xtd::ustring& value);

      /// @brief Gets the starting location of the link within the text of the xtd::forms::link_label::link.
      /// @return The location within the text of the the xtd::forms::link_label control where the link starts.
      /// @remarks To specify text from the xtd::forms::link_label to display as a link, set the xtd::forms::link_label::start property to the location in the text to start creating the link. After the xtd::forms::link_label::start property is set, set the value of the xtd::forms::link_label::length property to the number of characters, including the character position specified in the xtd::forms::link_label::start property, that you want to make the link text. For example, if you want to make the first word of the text "The quick brown fox" a link, you set the xtd::forms::link_label::start property to zero (0) and the xtd::forms::link_label::length property to three (3).
      size_t start() const;
      /// @brief Sets the starting location of the link within the text of the xtd::forms::link_label::link.
      /// @param value The location within the text of the the xtd::forms::link_label control where the link starts.
      /// @return The current instance of xtd::forms::link_label::link.
      /// @remarks To specify text from the xtd::forms::link_label to display as a link, set the xtd::forms::link_label::start property to the location in the text to start creating the link. After the xtd::forms::link_label::start property is set, set the value of the xtd::forms::link_label::length property to the number of characters, including the character position specified in the xtd::forms::link_label::start property, that you want to make the link text. For example, if you want to make the first word of the text "The quick brown fox" a link, you set the xtd::forms::link_label::start property to zero (0) and the xtd::forms::link_label::length property to three (3).
      link& start(size_t value);
      
      /// @brief Gets the object that contains data about the xtd::forms::link_label::link.
      /// @return An std::any object that contains data about the control. The default has no value.
      std::any tag() const;
      /// @brief Sets the object that contains data about the xtd::forms::link_label::link.
      /// @param value An std::any object that contains data about the control. The default has no value.
      /// @return The current instance of xtd::forms::link_label::link.
      link& tag(std::any value);
      
      /// @brief Gets a value indicating whether the user has visited the link.
      /// @return true if the link has been visited; otherwise, false.
      /// @remarks A xtd::forms::link_label control does not automatically denote that a link is a visited link. To display the link as a visited link, you can set the value of this property to true in an event handler for the xtd::forms::link_label::link_clicked event of a xtd::forms::link_label. A visited link is displayed using the color specified in the xtd::forms::link_label::visited_link_color property of the xtd::forms::link_label control. Once the form containing the xtd::forms::link_label control is closed, the all display state associated with the link is deleted. In order to retain the display state of the link, you need to store the display state of the link in a registry setting associated with your application.
      /// @note If you have only one link specified in a xtd::forms::link_label control, you can use the xtd::forms::link_label::link_visited property of the xtd::forms::link_label to specify the link as visited. You can also use the xtd::forms::link_label::link_visited property if you have multiple links defined, but the setting only applies to the first link defined in the control.
      bool visited() const;
      /// @brief Sets a value indicating whether the user has visited the link.
      /// @param value true if the link has been visited; otherwise, false.
      /// @return The current instance of xtd::forms::link_label::link.
      /// @remarks A xtd::forms::link_label control does not automatically denote that a link is a visited link. To display the link as a visited link, you can set the value of this property to true in an event handler for the xtd::forms::link_label::link_clicked event of a xtd::forms::link_label. A visited link is displayed using the color specified in the xtd::forms::link_label::visited_link_color property of the xtd::forms::link_label control. Once the form containing the xtd::forms::link_label control is closed, the all display state associated with the link is deleted. In order to retain the display state of the link, you need to store the display state of the link in a registry setting associated with your application.
      /// @note If you have only one link specified in a xtd::forms::link_label control, you can use the xtd::forms::link_label::link_visited property of the xtd::forms::link_label to specify the link as visited. You can also use the xtd::forms::link_label::link_visited property if you have multiple links defined, but the setting only applies to the first link defined in the control.
      link& visited(bool value);

    private:
      friend link_label;
      xtd::ustring description_;
      bool enabled_ = true;
      size_t length_ = 0;
      std::any link_data_;
      xtd::ustring name_;
      size_t start_ = 0;
      std::any tag_;
      bool visited_ = false;
      bool active_ = false;
    };
  }
}

