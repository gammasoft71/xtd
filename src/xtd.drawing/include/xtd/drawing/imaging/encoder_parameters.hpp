/// @file
/// @brief Contains xtd::drawing::imaging::encoder_parameters struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "encoder_parameter.hpp"
#include <xtd/array>
#include <xtd/iequatable>
#include <xtd/is>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd.drawing.imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder_parameters class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief Encapsulates an array of EncoderParameter objects.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      struct encoder_parameters final : object, xtd::iequatable<encoder_parameters> {
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameters class that can contain one xtd::drawing::imaging::encoder_parameter object.
        /// @remarks Some of the xtd::drawing::image::save and xtd::drawing::image::ssave_add methods receive an xtd::drawing::imaging::encoder_parameters object as an argument. The xtd::drawing::image::get_encoder_parameter_list method returns an xtd::drawing::imaging::encoder_parameters object.
        explicit encoder_parameters() : params(xtd::size {1}) {}
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameters class that can contain the specified number of xtd::drawing::imaging::encoder_parameter objects.
        /// @param count A size_t that specifies the number of xtd::drawing::imaging::encoder_parameter objects that the xtd::drawing::imaging::encoder_parameters object can contain.
        /// @remarks Some of the xtd::drawing::image::save and xtd::drawing::image::ssave_add methods receive an xtd::drawing::imaging::encoder_parameters object as an argument. The xtd::drawing::image::get_encoder_parameter_list method returns an xtd::drawing::imaging::encoder_parameters object.
        explicit encoder_parameters(xtd::size count) : params(count) {}
        /// @}
        
        /// @cond
        encoder_parameters(const encoder_parameters&) = default;
        encoder_parameters& operator =(const encoder_parameters&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets or sets an array of EncoderParameter objects.
        /// @param params The array of xtd::drawing::imaging::encoder_parameter objects.
        xtd::array<xtd::drawing::imaging::encoder_parameter> params;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        bool equals(const object& obj) const noexcept override {return is<encoder_parameters>(obj) && equals(static_cast<const encoder_parameters&>(obj));}
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param other The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        bool equals(const encoder_parameters& other) const noexcept override {return params == other.params;}
        /// @}
      };
    }
  }
}
