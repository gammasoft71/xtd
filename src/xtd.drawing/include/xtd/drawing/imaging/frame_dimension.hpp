/// @file
/// @brief Contains xtd::drawing::imaging::frame_dimension class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/guid>
#include <xtd/iequatable>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
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
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the FrameDimension class using the specified Guid structure.
        /// @param guid A xtd::guid structure that contains a GUID for this frame_dimension object.
        explicit frame_dimension(const xtd::guid& guid) noexcept;
        /// @}
        
        /// @cond
        frame_dimension(const frame_dimension&) = default;
        frame_dimension& operator =(const frame_dimension&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets a globally unique identifier (GUID) that represents this frame_dimension object.
        /// @return An xtd::guid structure that contains a GUID that represents this frame_dimension object.
        const xtd::guid& guid() const noexcept;
        /// @}
        
        /// @name Public Static Properties
        
        /// @{
        /// @brief Gets the page dimension.
        /// @return The page dimension.
        static frame_dimension page() noexcept;
        
        /// @brief Gets the resolution dimension.
        /// @return The resolution dimension.
        static frame_dimension resolution() noexcept;
        
        /// @brief Gets the time dimension.
        /// @return The time dimension.
        static frame_dimension time() noexcept;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        bool equals(const object& obj) const noexcept override;
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param other The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        bool equals(const frame_dimension& other) const noexcept override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        xtd::size get_hash_code() const noexcept override;
        /// @}
        
      private:
        xtd::guid guid_;
      };
    }
  }
}
