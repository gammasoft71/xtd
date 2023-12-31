/// @file
/// @brief Contains xtd::drawing::imaging::frame_dimension class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/guid>
#include <xtd/iequatable>
#include <xtd/object>
#include <cstdint>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd.drawing.imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief Provides properties that get the frame dimensions of an image. Not inheritable.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      class frame_dimension final : public object, public xtd::iequatable<frame_dimension> {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the FrameDimension class using the specified Guid structure.
        /// @param guid A xtd::guid structure that contains a GUID for this frame_dimension object.
        explicit frame_dimension(const xtd::guid& guid) : guid_(guid) {}
        /// @}
        
        /// @cond
        frame_dimension(const frame_dimension&) = default;
        frame_dimension& operator =(const frame_dimension&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets a globally unique identifier (GUID) that represents this frame_dimension object.
        /// @return An xtd::guid structure that contains a GUID that represents this frame_dimension object.
        const xtd::guid& guid() const noexcept {return guid_;}
        
        /// @brief Gets the page dimension.
        /// @return The page dimension.
        static frame_dimension page() noexcept {return frame_dimension(xtd::guid("7462dc86-6180-4c7e-8e3f-ee7333a7a483"));}
        
        /// @brief Gets the resolution dimension.
        /// @return The resolution dimension.
        static frame_dimension resolution() noexcept {return frame_dimension(xtd::guid("84236f7b-3bd3-428f-8dab-4ea1439ca315"));}
        
        /// @brief Gets the time dimension.
        /// @return The time dimension.
        static frame_dimension time() noexcept {return frame_dimension(xtd::guid("6aedbd6d-3fb5-418a-83a6-7f45229dc872"));}
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const frame_dimension& value) const noexcept override {return guid_ == value.guid_;}
        /// @}
        
      private:
        xtd::guid guid_;
      };
    }
  }
}
