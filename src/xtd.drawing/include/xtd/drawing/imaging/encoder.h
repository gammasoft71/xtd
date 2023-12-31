/// @file
/// @brief Contains xtd::drawing::imaging::encoder class.
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
      /// @brief An Encoder object encapsulates a globally unique identifier (GUID) that identifies the category of an image encoder parameter.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks When you pass a parameter to an image encoder, the parameter is encapsulated in an EncoderParameter object. One of the fields of the EncoderParameter object is a GUID that specifies the category of the parameter. Use the static fields of the Encoder class to retrieve an Encoder that contains parameters of the desired category.
      /// @remarks The image encoders that are built into GDI+ receive parameters that belong to several categories. The following table lists all the categories and the GUID associated with each category.
      /// | Category          | GUID                                 |
      /// | ----------------- | ------------------------------------ |
      /// | chrominance_table | f2e455dc-09b3-4316-8260-676ada32481c |
      /// | color_depth       | 66087055-ad66-4c7c-9a18-38a2310b8337 |
      /// | compression       | e09d739d-ccd4-44ee-8eba-3fbf8be4fc58 |
      /// | luminance_table   | edb33bce-0266-4a77-b904-27216099e717 |
      /// | quality           | 1d5be4b5-fa4a-452d-9cdd-5db35105e7eb |
      /// | render_method     | 6d42c53a-229a-4825-8bb7-5c99e2b9a8b8 |
      /// | save_flag         | 292266fc-ac40-47bf-8cfc-a85b89a655de |
      /// | scan_method       | 3a4e2661-3109-4e56-8536-42c156e7dcfa |
      /// | transformation    | 8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9 |
      /// | version           | 24d18c76-814a-41a4-bf53-1c219cccf797 |
      class encoder final : public object, public xtd::iequatable<encoder> {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder class from the specified globally unique identifier (GUID). The GUID specifies an image encoder parameter category.
        /// @param guid A globally unique identifier that identifies an image encoder parameter category.
        explicit encoder(const xtd::guid& guid) : guid_(guid) {}
        /// @}
        
        /// @cond
        encoder() = default;
        encoder(const encoder&) = default;
        encoder& operator =(const encoder&) = default;
        /// @endcond
        
        
        /// @name Fileds
        
        /// @{
        /// @brief An Encoder object that is initialized with the globally unique identifier for the chrominance table parameter category.
        /// @return The encoder.
        /// @remarks When you pass a parameter to an image encoder, the parameter is encapsulated in an xtd::drawing::image::encoder_parameter object. One of the fields of the xtd::drawing::image::encoder_parameter object is a GUID that specifies the category of the parameter. Use the static fields of the xtd::drawing::imaging:encoder class to retrieve an xtd::drawing::imaging:encoder that contains parameters of the desired category.
        /// @remarks The image encoders that are built into GDI+ receive parameters that belong to several categories. The following table lists all the categories and the GUID associated with each category.
        /// * xtd::drawing::imaging:encoder::chrominance_table f2e455dc-09b3-4316-8260-676ada32481c
        /// * xtd::drawing::imaging:encoder::color_depth 66087055-ad66-4c7c-9a18-38a2310b8337
        /// * xtd::drawing::imaging:encoder::compression e09d739d-ccd4-44ee-8eba-3fbf8be4fc58
        /// * xtd::drawing::imaging:encoder::luminance_table edb33bce-0266-4a77-b904-27216099e717
        /// * xtd::drawing::imaging:encoder::quality 1d5be4b5-fa4a-452d-9cdd-5db35105e7eb
        /// * xtd::drawing::imaging:encoder::render_method 6d42c53a-229a-4825-8bb7-5c99e2b9a8b8
        /// * xtd::drawing::imaging:encoder::save_flag 292266fc-ac40-47bf-8cfc-a85b89a655de
        /// * xtd::drawing::imaging:encoder::scan_method 3a4e2661-3109-4e56-8536-42c156e7dcfa
        /// * xtd::drawing::imaging:encoder::transformation 8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9
        /// * xtd::drawing::imaging:encoder::version 24d18c76-814a-41a4-bf53-1c219cccf797
        static encoder chrominance_table() noexcept {return encoder(xtd::guid("f2e455dc-09b3-4316-8260-676ada32481c"));}
        
        /// @brief An Encoder object that is initialized with the globally unique identifier for the color depth parameter category.
        /// @return The encoder.
        /// @remarks When you pass a parameter to an image encoder, the parameter is encapsulated in an xtd::drawing::image::encoder_parameter object. One of the fields of the xtd::drawing::image::encoder_parameter object is a GUID that specifies the category of the parameter. Use the static fields of the xtd::drawing::imaging:encoder class to retrieve an xtd::drawing::imaging:encoder that contains parameters of the desired category.
        /// @remarks The image encoders that are built into GDI+ receive parameters that belong to several categories. The following table lists all the categories and the GUID associated with each category.
        /// * xtd::drawing::imaging:encoder::chrominance_table f2e455dc-09b3-4316-8260-676ada32481c
        /// * xtd::drawing::imaging:encoder::color_depth 66087055-ad66-4c7c-9a18-38a2310b8337
        /// * xtd::drawing::imaging:encoder::compression e09d739d-ccd4-44ee-8eba-3fbf8be4fc58
        /// * xtd::drawing::imaging:encoder::luminance_table edb33bce-0266-4a77-b904-27216099e717
        /// * xtd::drawing::imaging:encoder::quality 1d5be4b5-fa4a-452d-9cdd-5db35105e7eb
        /// * xtd::drawing::imaging:encoder::render_method 6d42c53a-229a-4825-8bb7-5c99e2b9a8b8
        /// * xtd::drawing::imaging:encoder::save_flag 292266fc-ac40-47bf-8cfc-a85b89a655de
        /// * xtd::drawing::imaging:encoder::scan_method 3a4e2661-3109-4e56-8536-42c156e7dcfa
        /// * xtd::drawing::imaging:encoder::transformation 8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9
        /// * xtd::drawing::imaging:encoder::version 24d18c76-814a-41a4-bf53-1c219cccf797
        static encoder color_depth() noexcept {return encoder(xtd::guid("66087055-ad66-4c7c-9a18-38a2310b8337"));}
        
        /// @brief An Encoder object that is initialized with the globally unique identifier for the compression parameter category.
        /// @return The encoder.
        /// @remarks When you pass a parameter to an image encoder, the parameter is encapsulated in an xtd::drawing::image::encoder_parameter object. One of the fields of the xtd::drawing::image::encoder_parameter object is a GUID that specifies the category of the parameter. Use the static fields of the xtd::drawing::imaging:encoder class to retrieve an xtd::drawing::imaging:encoder that contains parameters of the desired category.
        /// @remarks The image encoders that are built into GDI+ receive parameters that belong to several categories. The following table lists all the categories and the GUID associated with each category.
        /// * xtd::drawing::imaging:encoder::chrominance_table f2e455dc-09b3-4316-8260-676ada32481c
        /// * xtd::drawing::imaging:encoder::color_depth 66087055-ad66-4c7c-9a18-38a2310b8337
        /// * xtd::drawing::imaging:encoder::compression e09d739d-ccd4-44ee-8eba-3fbf8be4fc58
        /// * xtd::drawing::imaging:encoder::luminance_table edb33bce-0266-4a77-b904-27216099e717
        /// * xtd::drawing::imaging:encoder::quality 1d5be4b5-fa4a-452d-9cdd-5db35105e7eb
        /// * xtd::drawing::imaging:encoder::render_method 6d42c53a-229a-4825-8bb7-5c99e2b9a8b8
        /// * xtd::drawing::imaging:encoder::save_flag 292266fc-ac40-47bf-8cfc-a85b89a655de
        /// * xtd::drawing::imaging:encoder::scan_method 3a4e2661-3109-4e56-8536-42c156e7dcfa
        /// * xtd::drawing::imaging:encoder::transformation 8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9
        /// * xtd::drawing::imaging:encoder::version 24d18c76-814a-41a4-bf53-1c219cccf797
        static encoder compression() noexcept {return encoder(xtd::guid("e09d739d-ccd4-44ee-8eba-3fbf8be4fc58"));}
        
        /// @brief An Encoder object that is initialized with the globally unique identifier for the luminance table parameter category.
        /// @return The encoder.
        /// @remarks When you pass a parameter to an image encoder, the parameter is encapsulated in an xtd::drawing::image::encoder_parameter object. One of the fields of the xtd::drawing::image::encoder_parameter object is a GUID that specifies the category of the parameter. Use the static fields of the xtd::drawing::imaging:encoder class to retrieve an xtd::drawing::imaging:encoder that contains parameters of the desired category.
        /// @remarks The image encoders that are built into GDI+ receive parameters that belong to several categories. The following table lists all the categories and the GUID associated with each category.
        /// * xtd::drawing::imaging:encoder::chrominance_table f2e455dc-09b3-4316-8260-676ada32481c
        /// * xtd::drawing::imaging:encoder::color_depth 66087055-ad66-4c7c-9a18-38a2310b8337
        /// * xtd::drawing::imaging:encoder::compression e09d739d-ccd4-44ee-8eba-3fbf8be4fc58
        /// * xtd::drawing::imaging:encoder::luminance_table edb33bce-0266-4a77-b904-27216099e717
        /// * xtd::drawing::imaging:encoder::quality 1d5be4b5-fa4a-452d-9cdd-5db35105e7eb
        /// * xtd::drawing::imaging:encoder::render_method 6d42c53a-229a-4825-8bb7-5c99e2b9a8b8
        /// * xtd::drawing::imaging:encoder::save_flag 292266fc-ac40-47bf-8cfc-a85b89a655de
        /// * xtd::drawing::imaging:encoder::scan_method 3a4e2661-3109-4e56-8536-42c156e7dcfa
        /// * xtd::drawing::imaging:encoder::transformation 8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9
        /// * xtd::drawing::imaging:encoder::version 24d18c76-814a-41a4-bf53-1c219cccf797
        static encoder luminance_table() noexcept {return encoder(xtd::guid("edb33bce-0266-4a77-b904-27216099e717"));}
        
        /// @brief An Encoder object that is initialized with the globally unique identifier for the quality parameter category.
        /// @return The encoder.
        /// @remarks When you pass a parameter to an image encoder, the parameter is encapsulated in an xtd::drawing::image::encoder_parameter object. One of the fields of the xtd::drawing::image::encoder_parameter object is a GUID that specifies the category of the parameter. Use the static fields of the xtd::drawing::imaging:encoder class to retrieve an xtd::drawing::imaging:encoder that contains parameters of the desired category.
        /// @remarks The image encoders that are built into GDI+ receive parameters that belong to several categories. The following table lists all the categories and the GUID associated with each category.
        /// * xtd::drawing::imaging:encoder::chrominance_table f2e455dc-09b3-4316-8260-676ada32481c
        /// * xtd::drawing::imaging:encoder::color_depth 66087055-ad66-4c7c-9a18-38a2310b8337
        /// * xtd::drawing::imaging:encoder::compression e09d739d-ccd4-44ee-8eba-3fbf8be4fc58
        /// * xtd::drawing::imaging:encoder::luminance_table edb33bce-0266-4a77-b904-27216099e717
        /// * xtd::drawing::imaging:encoder::quality 1d5be4b5-fa4a-452d-9cdd-5db35105e7eb
        /// * xtd::drawing::imaging:encoder::render_method 6d42c53a-229a-4825-8bb7-5c99e2b9a8b8
        /// * xtd::drawing::imaging:encoder::save_flag 292266fc-ac40-47bf-8cfc-a85b89a655de
        /// * xtd::drawing::imaging:encoder::scan_method 3a4e2661-3109-4e56-8536-42c156e7dcfa
        /// * xtd::drawing::imaging:encoder::transformation 8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9
        /// * xtd::drawing::imaging:encoder::version 24d18c76-814a-41a4-bf53-1c219cccf797
        static encoder quality() noexcept {return encoder(xtd::guid("1d5be4b5-fa4a-452d-9cdd-5db35105e7eb"));}
        
        /// @brief An Encoder object that is initialized with the globally unique identifier for the renderer method category.
        /// @return The encoder.
        /// @remarks When you pass a parameter to an image encoder, the parameter is encapsulated in an xtd::drawing::image::encoder_parameter object. One of the fields of the xtd::drawing::image::encoder_parameter object is a GUID that specifies the category of the parameter. Use the static fields of the xtd::drawing::imaging:encoder class to retrieve an xtd::drawing::imaging:encoder that contains parameters of the desired category.
        /// @remarks The image encoders that are built into GDI+ receive parameters that belong to several categories. The following table lists all the categories and the GUID associated with each category.
        /// * xtd::drawing::imaging:encoder::chrominance_table f2e455dc-09b3-4316-8260-676ada32481c
        /// * xtd::drawing::imaging:encoder::color_depth 66087055-ad66-4c7c-9a18-38a2310b8337
        /// * xtd::drawing::imaging:encoder::compression e09d739d-ccd4-44ee-8eba-3fbf8be4fc58
        /// * xtd::drawing::imaging:encoder::luminance_table edb33bce-0266-4a77-b904-27216099e717
        /// * xtd::drawing::imaging:encoder::quality 1d5be4b5-fa4a-452d-9cdd-5db35105e7eb
        /// * xtd::drawing::imaging:encoder::render_method 6d42c53a-229a-4825-8bb7-5c99e2b9a8b8
        /// * xtd::drawing::imaging:encoder::save_flag 292266fc-ac40-47bf-8cfc-a85b89a655de
        /// * xtd::drawing::imaging:encoder::scan_method 3a4e2661-3109-4e56-8536-42c156e7dcfa
        /// * xtd::drawing::imaging:encoder::transformation 8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9
        /// * xtd::drawing::imaging:encoder::version 24d18c76-814a-41a4-bf53-1c219cccf797
        static encoder render_method() noexcept {return encoder(xtd::guid("6d42c53a-229a-4825-8bb7-5c99e2b9a8b8"));}
        
        /// @brief An Encoder object that is initialized with the globally unique identifier for the save flag category.
        /// @return The encoder.
        /// @remarks When you pass a parameter to an image encoder, the parameter is encapsulated in an xtd::drawing::image::encoder_parameter object. One of the fields of the xtd::drawing::image::encoder_parameter object is a GUID that specifies the category of the parameter. Use the static fields of the xtd::drawing::imaging:encoder class to retrieve an xtd::drawing::imaging:encoder that contains parameters of the desired category.
        /// @remarks The image encoders that are built into GDI+ receive parameters that belong to several categories. The following table lists all the categories and the GUID associated with each category.
        /// * xtd::drawing::imaging:encoder::chrominance_table f2e455dc-09b3-4316-8260-676ada32481c
        /// * xtd::drawing::imaging:encoder::color_depth 66087055-ad66-4c7c-9a18-38a2310b8337
        /// * xtd::drawing::imaging:encoder::compression e09d739d-ccd4-44ee-8eba-3fbf8be4fc58
        /// * xtd::drawing::imaging:encoder::luminance_table edb33bce-0266-4a77-b904-27216099e717
        /// * xtd::drawing::imaging:encoder::quality 1d5be4b5-fa4a-452d-9cdd-5db35105e7eb
        /// * xtd::drawing::imaging:encoder::render_method 6d42c53a-229a-4825-8bb7-5c99e2b9a8b8
        /// * xtd::drawing::imaging:encoder::save_flag 292266fc-ac40-47bf-8cfc-a85b89a655de
        /// * xtd::drawing::imaging:encoder::scan_method 3a4e2661-3109-4e56-8536-42c156e7dcfa
        /// * xtd::drawing::imaging:encoder::transformation 8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9
        /// * xtd::drawing::imaging:encoder::version 24d18c76-814a-41a4-bf53-1c219cccf797
        static encoder save_flag() noexcept {return encoder(xtd::guid("292266fc-ac40-47bf-8cfc-a85b89a655de"));}
        
        /// @brief An Encoder object that is initialized with the globally unique identifier for the scan method category.
        /// @return The encoder.
        /// @remarks When you pass a parameter to an image encoder, the parameter is encapsulated in an xtd::drawing::image::encoder_parameter object. One of the fields of the xtd::drawing::image::encoder_parameter object is a GUID that specifies the category of the parameter. Use the static fields of the xtd::drawing::imaging:encoder class to retrieve an xtd::drawing::imaging:encoder that contains parameters of the desired category.
        /// @remarks The image encoders that are built into GDI+ receive parameters that belong to several categories. The following table lists all the categories and the GUID associated with each category.
        /// * xtd::drawing::imaging:encoder::chrominance_table f2e455dc-09b3-4316-8260-676ada32481c
        /// * xtd::drawing::imaging:encoder::color_depth 66087055-ad66-4c7c-9a18-38a2310b8337
        /// * xtd::drawing::imaging:encoder::compression e09d739d-ccd4-44ee-8eba-3fbf8be4fc58
        /// * xtd::drawing::imaging:encoder::luminance_table edb33bce-0266-4a77-b904-27216099e717
        /// * xtd::drawing::imaging:encoder::quality 1d5be4b5-fa4a-452d-9cdd-5db35105e7eb
        /// * xtd::drawing::imaging:encoder::render_method 6d42c53a-229a-4825-8bb7-5c99e2b9a8b8
        /// * xtd::drawing::imaging:encoder::save_flag 292266fc-ac40-47bf-8cfc-a85b89a655de
        /// * xtd::drawing::imaging:encoder::scan_method 3a4e2661-3109-4e56-8536-42c156e7dcfa
        /// * xtd::drawing::imaging:encoder::transformation 8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9
        /// * xtd::drawing::imaging:encoder::version 24d18c76-814a-41a4-bf53-1c219cccf797
        static encoder scan_method() noexcept {return encoder(xtd::guid("3a4e2661-3109-4e56-8536-42c156e7dcfa"));}
        
        /// @brief An Encoder object that is initialized with the globally unique identifier for the transformation category.
        /// @return The encoder.
        /// @remarks When you pass a parameter to an image encoder, the parameter is encapsulated in an xtd::drawing::image::encoder_parameter object. One of the fields of the xtd::drawing::image::encoder_parameter object is a GUID that specifies the category of the parameter. Use the static fields of the xtd::drawing::imaging:encoder class to retrieve an xtd::drawing::imaging:encoder that contains parameters of the desired category.
        /// @remarks The image encoders that are built into GDI+ receive parameters that belong to several categories. The following table lists all the categories and the GUID associated with each category.
        /// * xtd::drawing::imaging:encoder::chrominance_table f2e455dc-09b3-4316-8260-676ada32481c
        /// * xtd::drawing::imaging:encoder::color_depth 66087055-ad66-4c7c-9a18-38a2310b8337
        /// * xtd::drawing::imaging:encoder::compression e09d739d-ccd4-44ee-8eba-3fbf8be4fc58
        /// * xtd::drawing::imaging:encoder::luminance_table edb33bce-0266-4a77-b904-27216099e717
        /// * xtd::drawing::imaging:encoder::quality 1d5be4b5-fa4a-452d-9cdd-5db35105e7eb
        /// * xtd::drawing::imaging:encoder::render_method 6d42c53a-229a-4825-8bb7-5c99e2b9a8b8
        /// * xtd::drawing::imaging:encoder::save_flag 292266fc-ac40-47bf-8cfc-a85b89a655de
        /// * xtd::drawing::imaging:encoder::scan_method 3a4e2661-3109-4e56-8536-42c156e7dcfa
        /// * xtd::drawing::imaging:encoder::transformation 8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9
        /// * xtd::drawing::imaging:encoder::version 24d18c76-814a-41a4-bf53-1c219cccf797
        static encoder transformation() noexcept {return encoder(xtd::guid("8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9"));}
        
        /// @brief An Encoder object that is initialized with the globally unique identifier for the version category.
        /// @return The encoder.
        /// @remarks When you pass a parameter to an image encoder, the parameter is encapsulated in an xtd::drawing::image::encoder_parameter object. One of the fields of the xtd::drawing::image::encoder_parameter object is a GUID that specifies the category of the parameter. Use the static fields of the xtd::drawing::imaging:encoder class to retrieve an xtd::drawing::imaging:encoder that contains parameters of the desired category.
        /// @remarks The image encoders that are built into GDI+ receive parameters that belong to several categories. The following table lists all the categories and the GUID associated with each category.
        /// * xtd::drawing::imaging:encoder::chrominance_table f2e455dc-09b3-4316-8260-676ada32481c
        /// * xtd::drawing::imaging:encoder::color_depth 66087055-ad66-4c7c-9a18-38a2310b8337
        /// * xtd::drawing::imaging:encoder::compression e09d739d-ccd4-44ee-8eba-3fbf8be4fc58
        /// * xtd::drawing::imaging:encoder::luminance_table edb33bce-0266-4a77-b904-27216099e717
        /// * xtd::drawing::imaging:encoder::quality 1d5be4b5-fa4a-452d-9cdd-5db35105e7eb
        /// * xtd::drawing::imaging:encoder::render_method 6d42c53a-229a-4825-8bb7-5c99e2b9a8b8
        /// * xtd::drawing::imaging:encoder::save_flag 292266fc-ac40-47bf-8cfc-a85b89a655de
        /// * xtd::drawing::imaging:encoder::scan_method 3a4e2661-3109-4e56-8536-42c156e7dcfa
        /// * xtd::drawing::imaging:encoder::transformation 8d0eb2d1-a58e-4ea8-aa14-108074b7b6f9
        /// * xtd::drawing::imaging:encoder::version 24d18c76-814a-41a4-bf53-1c219cccf797
        static encoder version() noexcept {return encoder(xtd::guid("24d18c76-814a-41a4-bf53-1c219cccf797"));}
        /// @}
        
        /// @name Properties
        
        /// @{
        /// @brief Gets a globally unique identifier (GUID) that identifies an image encoder parameter category.
        /// @return The GUID that identifies an image encoder parameter category.
        const xtd::guid& guid() const noexcept {return guid_;}
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const encoder& value) const noexcept override {return guid_ == value.guid_;}
        /// @}
        
      private:
        xtd::guid guid_;
      };
    }
  }
}
