/// @file
/// @brief Contains xtd::drawing::imaging::encoder_parameters class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "encoder_parameter.h"
#include <xtd/iequatable>
#include <cstdint>
#include <ostream>

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
      class encoder_parameters final : public object, public xtd::iequatable<encoder_parameters> {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameters class that can contain one xtd::drawing::imaging::encoder_parameter object.
        /// @remarks Some of the xtd::drawing::image::save and xtd::drawing::image::ssave_add methods receive an xtd::drawing::imaging::encoder_parameters object as an argument. The xtd::drawing::image::get_encoder_parameter_list method returns an xtd::drawing::imaging::encoder_parameters object.
        explicit encoder_parameters() : params_(std::vector<xtd::drawing::imaging::encoder_parameter>(1u, xtd::drawing::imaging::encoder_parameter())) {}
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameters class that can contain the specified number of xtd::drawing::imaging::encoder_parameter objects.
        /// @param count A size_t that specifies the number of xtd::drawing::imaging::encoder_parameter objects that the xtd::drawing::imaging::encoder_parameters object can contain.
        /// @remarks Some of the xtd::drawing::image::save and xtd::drawing::image::ssave_add methods receive an xtd::drawing::imaging::encoder_parameters object as an argument. The xtd::drawing::image::get_encoder_parameter_list method returns an xtd::drawing::imaging::encoder_parameters object.
        explicit encoder_parameters(size_t count) : params_(std::vector<xtd::drawing::imaging::encoder_parameter>(count, xtd::drawing::imaging::encoder_parameter())) {}
        /// @}
        
        /// @cond
        encoder_parameters(const encoder_parameters&) = default;
        encoder_parameters& operator =(const encoder_parameters&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets an array of EncoderParameter objects.
        /// @return The array of xtd::drawing::imaging::encoder_parameter objects.
        const std::vector<xtd::drawing::imaging::encoder_parameter>& params() const noexcept {return params_;}
        /// @brief Gets an array of EncoderParameter objects.
        /// @return The array of xtd::drawing::imaging::encoder_parameter objects.
        std::vector<xtd::drawing::imaging::encoder_parameter>& params() noexcept {return params_;}
        /// @brief Sets an array of EncoderParameter objects.
        /// @param value The array of xtd::drawing::imaging::encoder_parameter objects.
        void params(const std::vector<xtd::drawing::imaging::encoder_parameter>& value) noexcept {params_ = value;}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        bool equals(const encoder_parameters& value) const noexcept override {return params_ == value.params_;}
        /// @}
        
      private:
        std::vector<xtd::drawing::imaging::encoder_parameter> params_;
      };
    }
  }
}
