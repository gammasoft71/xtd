/// @file
/// @brief Contains xtd::drawing::system_images factory.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <map>
#include <xtd/static.h>
#include "../drawing_export.h"
#include "bitmap.h"
#include "size.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class system_icons;
    /// @endcond
    
    /// @brief Each property of the xtd::drawing::system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ system_images final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::system_images
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks Each property of the system_fonts class returns a Font used to display text in a particular Windows display element, such as the title bar of a window. These fonts reflect the current settings in Control Panel.
    class drawing_export_ system_images final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() {return {32, 32};}
      /// @brief Get the image loading.
      /// @return The image loading.
      /// @remarks This is mage can be used when an image is loading.
      static xtd::drawing::image image_loading() {return image_loading(default_size());}
      /// @brief Get the image loading with specified size.
      /// @param size The system image size in pixels.
      /// @return The image loading.
      /// @remarks This is mage can be used when an image is loading.
      static xtd::drawing::image image_loading(const xtd::drawing::size& size) {return system_images::from_name("image-loading", size);}
      /// @brief Get the image missing.
      /// @return The image missing.
      /// @remarks This is mage can be used when an image is missing.
      static xtd::drawing::image image_missing() {return image_missing(default_size());}
      /// @brief Get the image missing with specified size.
      /// @param size The system image size in pixels.
      /// @return The image missing.
      /// @remarks This is mage can be used when an image is missing.
      static xtd::drawing::image image_missing(const xtd::drawing::size& size) {return from_name("image-missing", size);}
      
      /// @brief Get the image context.
      /// @return The image context.
      /// @remarks The system images are groupped by contaxt.
      /// @remarks The following table list the contexts :
      /// | Context       | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
      /// |---------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
      /// | Actions       | Icons which are generally used in menus and dialogs for interacting with the user.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
      /// | Animations    | Animated images used to represent loading web sites, or other background processing which may be less suited to more verbose progress reporting in the user interface. Animations should be a PNG with frames which are the size of the directory the animation is in, tiled in a WxH grid. Implementations should determine the number of frames by dividing the image into its frames, and iterating from left to right, wrapping to the first frame, after rendering the last.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
      /// | Applications  | Icons that describe what an application is, for use in the Programs menu, window decorations, and the task list. These may or may not be generic depending on the application and its purpose. Applications which are to be considered part of the base desktop, such as the calculator or terminal, should use the generic icons specified in this specification, while more advanced applications such as web browsers and office applications should use branded icons which still give the user an idea of what function the application provides.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
      /// | Categories    | Icons that are used for categories in the Programs menu, or the Control Center, for separating applications, preferences, and settings for display to the user.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
      /// | Devices       | Icons for hardware that is contained within or connected to the computing device. Naming for extended devices in this group, is of the form <primary function>-<manufacturer>-<model>. This allows ease of fallback to the primary function device name, or ones more targeted for a specific series of models from a manufacturer. For example, a theme author may want to provide icons for different phones. The specific model icons could be named “phone-samsung-t809”, “phone-motorola-rokr”, and “phone-motorola-pebl”. However, the theme must provide a phone icon in the theme's style, so that devices not matching these models, will still have an appropriate icon. An exception to this rule is that the “media” icons do not need to include manufacturer names, as they are generic items, and may be available from many manufacturers. As a result, for media, the specific icons are to differentiate between different specific types of media. For exmaple, an artist may wish to provide icons for BluRay, DVD, HD-DVD, CD-ROM, and variations thereof. The specific media type icons should be named in the form, <primary function>-<specific format>. Some examples are “media-optical”, “media-optical-bd” and “media-optical-dvd”. |
      /// | Emblems       | Icons for tags and properties of files, that are displayed in the file manager. This context contains emblems for such things as “read-only” or “photos”.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
      /// | Emotes        | Icons for emotions that are expressed through text chat applications such as :-) or :-P in IRC or instant messengers.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
      /// | International | Icons for international denominations such as flags.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
      /// | MimeTypes     | Icons for different types of data, such as audio or image files.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
      /// | Places        | Icons used to represent locations, either on the local filesystem, or through remote connections. Folders, trash, and workgroups are some examples.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
      /// | Status        | Icons for presenting status to the user. This context contains icons for warning and error dialogs, as well as for the current weather, appointment alarms, and battery status.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
      /// | xtd           | Icons for representinf xtd libraries and products.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
      /// @remarks See <a href="https://specifications.freedesktop.org/icon-naming-spec/icon-naming-spec-latest.html">Icon Naming Specification</a> for more information.
      static std::vector<xtd::ustring> contexts();
      static std::map<xtd::ustring, std::vector<xtd::ustring>> context_names();
      static std::vector<xtd::ustring> names();
      static std::vector<xtd::ustring> names(const xtd::ustring& context) {return context_names()[context];}
      static std::vector<xtd::drawing::size> sizes();
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @param name The system image name.
      /// @return An xtd::drawing::image object that contains the system image from specified name.
      /// @remarks The theme is the default system theme.
      /// @remarks The size is the default size (32 x 32).
      static xtd::drawing::image from_name(const xtd::ustring& name) {return from_name(default_theme(), name, default_size());}
      /// @brief Gets system image from specified name and size.
      /// @param name The system image name.
      /// @param size The system image size in pixels.
      /// @return An xtd::drawing::image object that contains the system image from specified name.
      /// @remarks The theme is the default system theme.
      static xtd::drawing::image from_name(const xtd::ustring& name, const xtd::drawing::size& size) {return from_name(default_theme(), name, size);}
      /// @brief Gets system image from specified them and name.
      /// @param theme The system image theme.
      /// @param name The system image name.
      /// @return An xtd::drawing::image object that contains the system image from specified name.
      /// @remarks The size is the default size in pixels (32 x 32).
      static xtd::drawing::image from_name(const xtd::ustring& theme, const xtd::ustring& name) {return from_name(theme, name, default_size());}
      /// @brief Gets system image from specified theme, name and size.
      /// @param theme The system image theme.
      /// @param name The system image name.
      /// @param size The system image size in pixels.
      /// @return An xtd::drawing::image object that contains the system image from specified name.
      static xtd::drawing::image from_name(const xtd::ustring& theme, const xtd::ustring& name, const xtd::drawing::size& size);
      /// @}
      
    private:
      friend class system_icons;
      static xtd::ustring default_theme();
      static xtd::ustring fallback_theme();
      static std::vector<xtd::ustring> themes();
    };
  }
}

