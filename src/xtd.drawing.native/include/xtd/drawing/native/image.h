#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <istream>
#include <map>
#include <tuple>
#include <vector>
#include <xtd/static.h>
#include <xtd/types.h>
#include <xtd/ustring.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class bitmap;
    class image;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains image native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ image final static_ {
        friend xtd::drawing::bitmap;
        friend xtd::drawing::image;
      protected:
        /// @brief Encapsulates a metadata property to be included in an image file.
        struct property_item {
          /// @brief The ID of the property.
          /// @remarks The following table shows the property tags and their IDs.
          /// | ID     | Property tag                                  |
          /// | ------ | --------------------------------------------- |
          /// | 0x000  | property_tag_gps_ver                          |
          /// | 0x001  | property_tag_gps_latitude_ref                 |
          /// | 0x002  | property_tag_gps_latitude                     |
          /// | 0x003  | property_tag_gp_longitude_ref                 |
          /// | 0x004  | property_tag_gps_longitude                    |
          /// | 0x005  | property_tag_gps_altitude_ref                 |
          /// | 0x006  | property_tag_gps_altitude                     |
          /// | 0x007  | property_tag_gps_gps_time                     |
          /// | 0x008  | property_tag_gps_gps_satellites               |
          /// | 0x009  | property_tag_gps_gps_status                   |
          /// | 0x00A  | property_tag_gps_gps_measure_mode             |
          /// | 0x00B  | property_tag_gps_gps_dop                      |
          /// | 0x00C  | property_tag_gps_speed_ref                    |
          /// | 0x00D  | property_tag_gps_speed                        |
          /// | 0x00E  | property_tag_gps_track_ref                    |
          /// | 0x00F  | property_tag_gps_track                        |
          /// | 0x010  | property_tag_gps_img_dir_ref                  |
          /// | 0x011  | property_tag_gps_img_dir                      |
          /// | 0x012  | property_tag_gps_map_datum                    |
          /// | 0x013  | property_tag_gps_dest_lat_ref                 |
          /// | 0x014  | property_tag_gps_dest_lat                     |
          /// | 0x015  | property_tag_gps_Dest_long_ref                |
          /// | 0x016  | property_tag_gps_dest_long                    |
          /// | 0x017  | property_tag_gps_dest_bear _ref               |
          /// | 0x018  | property_tag_gps_dest_bear                    |
          /// | 0x019  | property_tag_gps_dest_dist_ref                |
          /// | 0x01A  | property_tag_gps_dest_dist                    |
          /// | 0x0FE  | property_tag_new_subfile_type                 |
          /// | 0x0FF  | property_tag_subfileType                      |
          /// | 0x100  | property_tag_image_width                      |
          /// | 0x101  | property_tag_image_height                     |
          /// | 0x102  | property_tag_bits_per_sample                  |
          /// | 0x103  | property_tag_compression                      |
          /// | 0x106  | property_tag_photometric_interp               |
          /// | 0x107  | property_tag_thresh_holding                   |
          /// | 0x108  | property_tag_cell_width                       |
          /// | 0x109  | property_tag_Cell_height                      |
          /// | 0x10A  | property_tag_fill_order                       |
          /// | 0x10D  | property_tag_document_name                    |
          /// | 0x10E  | property_tag_image_description                |
          /// | 0x10F  | property_tag_equip_make                       |
          /// | 0x110  | property_tag_equip_model                      |
          /// | 0x111  | property_tag_strip_offsets                    |
          /// | 0x112  | property_tag_orientation                      |
          /// | 0x115  | property_tag_Samples_per_pixel                |
          /// | 0x116  | property_tag_rows_per_strip                   |
          /// | 0x117  | property_tag_strip_bytes_count                |
          /// | 0x118  | property_tag_min_sample_value                 |
          /// | 0x119  | property_tag_max_sample_value                 |
          /// | 0x11A  | property_tag_xresolution                      |
          /// | 0x11B  | property_tag_yresolution                      |
          /// | 0x11C  | property_tag_planar_config                    |
          /// | 0x11D  | property_tag_page_name                        |
          /// | 0x11E  | property_tag_xposition                        |
          /// | 0x11F  | property_tag_yposition                        |
          /// | 0x120  | property_tag_free_offset                      |
          /// | 0x121  | property_tag_free_byte_counts                 |
          /// | 0x122  | property_tag_gray_response_unit               |
          /// | 0x123  | property_tag_gray_response_curve              |
          /// | 0x124  | property_tag_t4_option                        |
          /// | 0x125  | property_tag_t6_option                        |
          /// | 0x128  | property_tag_resolution_unit                  |
          /// | 0x129  | property_tag_page_number                      |
          /// | 0x12D  | property_tag_transfer_function                |
          /// | 0x131  | property_tag_software_used                    |
          /// | 0x132  | property_tag_date_time                        |
          /// | 0x13B  | property_tag_artist                           |
          /// | 0x13C  | property_tag_host_computer                    |
          /// | 0x13D  | property_tag_predictor                        |
          /// | 0x13E  | property_tag_white_point                      |
          /// | 0x13F  | property_tag_primary_chromaticities           |
          /// | 0x140  | property_tag_color_map                        |
          /// | 0x141  | property_tag_halftone_hints                   |
          /// | 0x142  | property_tag_tile_width                       |
          /// | 0x143  | property_tag_tile_length                      |
          /// | 0x144  | property_tag_tile_offset                      |
          /// | 0x145  | property_tag_tile_byte_counts                 |
          /// | 0x14C  | property_tag_ink_set                          |
          /// | 0x14D  | property_tag_ink_names                        |
          /// | 0x14E  | property_tag_number_of_inks                   |
          /// | 0x150  | property_tag_dot_range                        |
          /// | 0x151  | property_tag_target_printer                   |
          /// | 0x152  | property_tag_extra_samples                    |
          /// | 0x153  | property_tag_sample_format                    |
          /// | 0x154  | property_tag_smin_sample_value                |
          /// | 0x155  | property_tag_smax_sample_value                |
          /// | 0x156  | property_tag_transfer_range                   |
          /// | 0x200  | property_tag_jpeg_proc                        |
          /// | 0x201  | property_tag_jpeg_inter_format                |
          /// | 0x202  | property_tag_jpeg_Inter_length                |
          /// | 0x203  | property_tag_jpeg_restart_interval            |
          /// | 0x205  | property_tag_jpeg_lossless_predictors         |
          /// | 0x206  | property_tag_jpeg_point_transforms            |
          /// | 0x207  | property_tag_jpeg_qtables                     |
          /// | 0x208  | property_tag_jpeg_dctables                    |
          /// | 0x209  | property_tag_jpeg_actables                    |
          /// | 0x211  | property_tag_ycb_cr_coefficients              |
          /// | 0x212  | property_tag_ycb_cr_subsampling               |
          /// | 0x213  | property_tag_ycb_cr_positioning               |
          /// | 0x214  | property_tag_refblack_white                   |
          /// | 0x301  | property_tag_gamma                            |
          /// | 0x302  | property_tag_iccprofile_descriptor            |
          /// | 0x303  | property_tag_srgbrendering_intent             |
          /// | 0x320  | property_tag_image_title                      |
          /// | 0x5001 | property_tag_resolution_xunit                 |
          /// | 0x5002 | property_tag_resolution_yunit                 |
          /// | 0x5003 | property_tag_resolution_xlength_unit          |
          /// | 0x5004 | property_tag_resolution_ylength_unit          |
          /// | 0x5005 | property_tag_print_flags                      |
          /// | 0x5006 | property_tag_print_flags_version              |
          /// | 0x5007 | property_tag_print_flags_crop                 |
          /// | 0x5008 | property_tag_print_flags_bleed_width          |
          /// | 0x5009 | property_tag_print_flags_bleed_width_scale    |
          /// | 0x500A | property_tag_halfton_elpi                     |
          /// | 0x500B | property_tag_halfton_elpi_unit                |
          /// | 0x500C | property_tag_halfton_edegree                  |
          /// | 0x500D | property_tag_halfton_eshape                   |
          /// | 0x500E | property_tag_halfton_emisc                    |
          /// | 0x500F | property_tag_halfton_escreen                  |
          /// | 0x5010 | property_tag_jpeg_quality                     |
          /// | 0x5011 | property_tag_grid_size                        |
          /// | 0x5012 | property_tag_thumbnail_format                 |
          /// | 0x5013 | property_tag_thumbnail_width                  |
          /// | 0x5014 | property_tag_thumbnail_height                 |
          /// | 0x5015 | property_tag_thumbnail_color_depth            |
          /// | 0x5016 | property_tag_thumbnail_planes                 |
          /// | 0x5017 | property_tag_thumbnail_raw_bytes              |
          /// | 0x5018 | property_tag_thumbnail_size                   |
          /// | 0x5019 | property_tag_thumbnail_compressed_size        |
          /// | 0x501A | property_tag_color_transfer_function          |
          /// | 0x501B | property_tag_thumbnail_data                   |
          /// | 0x5020 | property_tag_thumbnail_image_width            |
          /// | 0x5021 | property_tag_thumbnail_image_height           |
          /// | 0x5022 | property_tag_thumbnail_bits_per_sample        |
          /// | 0x5023 | property_tag_thumbnail_compression            |
          /// | 0x5024 | property_tag_thumbnail_photometric_interp     |
          /// | 0x5025 | property_tag_thumbnail_image_description      |
          /// | 0x5026 | property_tag_thumbnail_equip_make             |
          /// | 0x5027 | property_tag_thumbnail_equip_model            |
          /// | 0x5028 | property_tag_thumbnail_strip_offsets          |
          /// | 0x5029 | property_tag_thumbnail_orientation            |
          /// | 0x502A | property_tag_thumbnail_samples_per_pixel      |
          /// | 0x502B | property_tag_thumbnail_rows_per_strip         |
          /// | 0x502C | property_tag_thumbnail_strip_bytes_count      |
          /// | 0x502D | property_tag_thumbnail_resolution_x           |
          /// | 0x502E | property_tag_thumbnail_resolution_y           |
          /// | 0x502F | property_tag_thumbnail_planar_config          |
          /// | 0x5030 | property_tag_thumbnail_resolution_unit        |
          /// | 0x5031 | property_tag_thumbnail_transfer_function      |
          /// | 0x5032 | property_tag_thumbnail_doftware_used          |
          /// | 0x5033 | property_tag_thumbnail_date_time              |
          /// | 0x5034 | property_tag_thumbnail_artist                 |
          /// | 0x5035 | property_tag_thumbnail_white_point            |
          /// | 0x5036 | property_tag_thumbnail_primary_chromaticities |
          /// | 0x5037 | property_tag_thumbnail_ycb_cr_coefficients    |
          /// | 0x5038 | property_tag_thumbnail_ycb_cr_subsampling     |
          /// | 0x5039 | property_tag_thumbnail_ycb_cr_positioning     |
          /// | 0x503A | property_tag_thumbnail_ref_black_white        |
          /// | 0x503B | property_tag_thumbnail_copyRight              |
          /// | 0x5090 | property_tag_luminance_table                  |
          /// | 0x5091 | property_tag_chrominance_table                |
          /// | 0x5100 | property_tag_frame_delay                      |
          /// | 0x5101 | property_tag_loop_count                       |
          /// | 0x5102 | property_tag_global_palette                   |
          /// | 0x5103 | property_tag_index_background                 |
          /// | 0x5104 | property_tag_index_transparent                |
          /// | 0x5110 | property_tag_pixel_unit                       |
          /// | 0x5111 | property_tag_pixel_per_unit_x                 |
          /// | 0x5112 | property_tag_pixel_per_unit_y                 |
          /// | 0x5113 | property_tag_palette_histogram                |
          /// | 0x8298 | property_tag_copyright                        |
          /// | 0x829A | property_tag_exif_exposureTime                |
          /// | 0x829D | property_tag_exif_fnumber                     |
          /// | 0x8769 | property_tag_exif_ifd                         |
          /// | 0x8773 | property_tag_icc_profile                      |
          /// | 0x8822 | property_tag_exif_exposure_prog               |
          /// | 0x8824 | property_tag_exif_spectral_sense              |
          /// | 0x8825 | property_tag_gps_ifd                          |
          /// | 0x8827 | property_tag_exif_iso_speed                   |
          /// | 0x8828 | property_tag_exif_oecf                        |
          /// | 0x9000 | property_tag_exif_ver                         |
          /// | 0x9003 | property_tag_exif_dt_orig                     |
          /// | 0x9004 | property_tag_exif__dt_digitized               |
          /// | 0x9101 | property_tag_exif_comp_config                 |
          /// | 0x9102 | property_tag_exif_comp_bpp                    |
          /// | 0x9201 | property_tag_exif_shutter_speed               |
          /// | 0x9202 | property_tag_exif_aperture                    |
          /// | 0x9203 | property_tag_exif_brightness                  |
          /// | 0x9204 | property_tag_exif_exposure_bias               |
          /// | 0x9205 | property_tag_exif_max_aperture                |
          /// | 0x9206 | property_tag_exif_subject_dist                |
          /// | 0x9207 | property_tag_exif_metering_mode               |
          /// | 0x9208 | property_tag_exif_light_source                |
          /// | 0x9209 | property_tag_exif_flash                       |
          /// | 0x920A | property_tag_exif_focal_length                |
          /// | 0x927C | property_tag_exif_maker_note                  |
          /// | 0x9286 | property_tag_exif_user_comment                |
          /// | 0x9290 | property_tag_exif_dt_subsec                   |
          /// | 0x9291 | property_tag_exif_dt_orig_ss                  |
          /// | 0x9292 | property_tag_exif_dt_dig_ss                   |
          /// | 0xA000 | property_tag_exif_fpx_ver                     |
          /// | 0xA001 | property_tag_exif_color_space                 |
          /// | 0xA002 | property_tag_exif_pix_x_dim                   |
          /// | 0xA003 | property_tag_exif_pix_y_dim                   |
          /// | 0xA004 | property_tag_exif_related_wav                 |
          /// | 0xA005 | property_tag_exif_interop                     |
          /// | 0xA20B | property_tag_exif_flash_energy                |
          /// | 0xA20C | property_tag_exif_spatial_fr                  |
          /// | 0xA20E | property_tag_exif_focal_x_res                 |
          /// | 0xA20F | property_tag_exif_focal_y_res                 |
          /// | 0xA210 | property_tag_exif_focal_res_unit              |
          /// | 0xA214 | property_tag_exif_subject_loc                 |
          /// | 0xA215 | property_tag_exif_exposure_index              |
          /// | 0xA217 | property_tag_exif_sensing_method              |
          /// | 0xA300 | property_tag_exif_file_Source                 |
          /// | 0xA301 | property_tag_exif_scene_type                  |
          /// | 0xA302 | property_tag_exif_cfa_pattern                 |
          int32 id = 0;
          /// @brief The length (in bytes) of the value property.
          int32 len = 0;
          /// @brief An integer that defines the type of data contained in the value property.
          /// @remarks The following table shows integers and the types they represent.
          /// | Integer | Represented Type                                                                                                                                                                                                                                            |
          /// | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
          /// | 1       | Specifies that Value is an array of bytes.                                                                                                                                                                                                                  |
          /// | 2       | Specifies that Value is a null-terminated ASCII string. If you set the type data member to ASCII type, you should set the Len property to the length of the string including the null terminator. For example, the string "Hello" would have a length of 6. |
          /// | 3       | Specifies that Value is an array of unsigned short (16-bit) integers.                                                                                                                                                                                       |
          /// | 4       | Specifies that Value is an array of unsigned long (32-bit) integers.                                                                                                                                                                                        |
          /// | 5       | Specifies that Value data member is an array of pairs of unsigned long integers. Each pair represents a fraction; the first integer is the numerator and the second integer is the denominator.                                                             |
          /// | 6       | Specifies that Value is an array of bytes that can hold values of any data type.                                                                                                                                                                            |
          /// | 7       | Specifies that Value is an array of signed long (32-bit) integers.                                                                                                                                                                                          |
          /// | 10      | Specifies that Value is an array of pairs of signed long integers. Each pair represents a fraction; the first integer is the numerator and the second integer is the denominator.                                                                           |
          int32 type = 1;
          /// @brief the value of the property item.
          std::vector<xtd::byte> value;
        };
        
        /// @name Protected methods
        
        /// @{
        
        /// @brief Blurs the image whith the specified radius.
        /// @param image The image handle.
        /// @param radius The radius of the blur, specified as a <length>
        /// @note No blur effect, if the radius is 0.
        /// @return The new blurred image handle.
        /// @warning Internal use only
        static intptr blur(intptr handle, int32 radius);
        
        /// @brief Gets the color palette used for the image.
        /// @param image The image handle.
        /// @param entries A std::vector<std::tuple<xtd::byte, xtd::byte, xtd::byte, xtd::byte>> (alpha, red, green and blue componenents of color) that represents the color palette used for the image.
        /// @param flags A value that specifies how to interpret the color information in the array of colors
        /// @remarks The following flag values are valid:
        /// * 0x00000001 The color values in the array contain alpha information.
        /// * 0x00000002 The colors in the array are grayscale values.
        /// * 0x00000004 The colors in the array are halftone values.
        /// @warning Internal use only
        static void color_palette(intptr image, std::vector<std::tuple<xtd::byte, xtd::byte, xtd::byte, xtd::byte>>& entries, int32& flags);
        
        /// @brief Creates an image from specified filename and get the frame_solution collection.
        /// @param filename The filename of the image.
        /// @param frame_resolutions an std::map<size_t, size_t> containing the frame dimention and the image count collection (see frame_dimension.h for more information).
        /// @return A new image handle.
        /// @remarks This method returns information about multiple-frame images, which come in two styles: multiple page and multiple resolution.
        /// @remarks A multiple-page image is an image that contains more than one image. Each page contains a single image (or frame). These pages (or images, or frames) are typically displayed in succession to produce an animated sequence, such as an animated .gif file.
        /// @remarks A multiple-resolution image is an image that contains more than one copy of an image at different resolutions. This is commonly used by MIP mapping where the displayed image size determines the resolution of the image used for drawing. GDI+ can support an arbitrary number of pages (or images, or frames), as well as an arbitrary number of resolutions. The defined dimensions are properties of the frame_dimension.
        /// @warning Internal use only
        static intptr create(const xtd::ustring& filename, std::map<size_t, size_t>& frame_resolutions);
        /// @brief Creates an image from specified filename and get the frame_solution collection.
        /// @param filename The filename of the image.
        /// @param frame_resolutions an std::map<size_t, size_t> containing the frame dimention and the image count collection (see frame_dimension.h for more information).
        /// @param use_icm true to use color correction for this Bitmap; otherwise, false.
        /// @return A new image handle.
        /// @remarks This method returns information about multiple-frame images, which come in two styles: multiple page and multiple resolution.
        /// @remarks A multiple-page image is an image that contains more than one image. Each page contains a single image (or frame). These pages (or images, or frames) are typically displayed in succession to produce an animated sequence, such as an animated .gif file.
        /// @remarks A multiple-resolution image is an image that contains more than one copy of an image at different resolutions. This is commonly used by MIP mapping where the displayed image size determines the resolution of the image used for drawing. GDI+ can support an arbitrary number of pages (or images, or frames), as well as an arbitrary number of resolutions. The defined dimensions are properties of the frame_dimension.
        /// @warning Internal use only
        static intptr create(const xtd::ustring& filename, bool use_icm, std::map<size_t, size_t>& frame_resolutions);
        /// @brief Creates an image from specified std::istream and get the frame_solution collection.
        /// @param stream The std::istream containing the image.
        /// @param frame_resolutions an std::map<size_t, size_t> containing the frame dimention and the image count collection (see frame_dimension.h for more information).
        /// @return A new image handle.
        /// @remarks This method returns information about multiple-frame images, which come in two styles: multiple page and multiple resolution.
        /// @remarks A multiple-page image is an image that contains more than one image. Each page contains a single image (or frame). These pages (or images, or frames) are typically displayed in succession to produce an animated sequence, such as an animated .gif file.
        /// @remarks A multiple-resolution image is an image that contains more than one copy of an image at different resolutions. This is commonly used by MIP mapping where the displayed image size determines the resolution of the image used for drawing. GDI+ can support an arbitrary number of pages (or images, or frames), as well as an arbitrary number of resolutions. The defined dimensions are properties of the frame_dimension.
        /// @warning Internal use only
        static intptr create(std::istream& stream, std::map<size_t, size_t>& frame_resolutions);
        /// @brief Creates an image from specified std::istream and get the frame_solution collection.
        /// @param stream The std::istream containing the image.
        /// @param use_icm true to use color correction for this Bitmap; otherwise, false.
        /// @param frame_resolutions an std::map<size_t, size_t> containing the frame dimention and the image count collection (see frame_dimension.h for more information).
        /// @return A new image handle.
        /// @remarks This method returns information about multiple-frame images, which come in two styles: multiple page and multiple resolution.
        /// @remarks A multiple-page image is an image that contains more than one image. Each page contains a single image (or frame). These pages (or images, or frames) are typically displayed in succession to produce an animated sequence, such as an animated .gif file.
        /// @remarks A multiple-resolution image is an image that contains more than one copy of an image at different resolutions. This is commonly used by MIP mapping where the displayed image size determines the resolution of the image used for drawing. GDI+ can support an arbitrary number of pages (or images, or frames), as well as an arbitrary number of resolutions. The defined dimensions are properties of the frame_dimension.
        /// @warning Internal use only
        static intptr create(std::istream& stream, bool use_icm, std::map<size_t, size_t>& frame_resolutions);
        /// @brief Creates an image from bits.
        /// @param bits The bits containing the image.
        /// @return A new image handle.
        /// @remarks This method is used for creating an imgae from an XPM (or XBM) image.
        /// @warning Internal use only
        static intptr create(const char* const* bits);
        /// @brief Creates an empty image from size.
        /// @param width The width for the empty image.
        /// @param height The height for the empty image.
        /// @return A new image handle.
        /// @warning Internal use only
        static intptr create(int32 width, int32 height);
        /// @brief Creates an empty image from size, and horzontal and vertical resolution.
        /// @param width The width for the new image.
        /// @param height The height for the new image.
        /// @return A new image handle.
        /// @warning Internal use only
        static intptr create(int32 width, int32 height, float horizontal_resolution, float vertical_resolution);
        /// @brief Creates an empty image from size, and pixel format.
        /// @param width The width for the empty image.
        /// @param height The height for the empty image.
        /// @param format The pixel format for the new image.
        /// @return A new image handle.
        /// @warning Internal use only
        static intptr create(int32 width, int32 height, int32 format);
        /// @brief Creates an empty image from size, pixel format and pixel datas.
        /// @param width The width for the empty image.
        /// @param height The height for the empty image.
        /// @param stride Integer that specifies the byte offset between the beginning of one scan line and the next. This is usually (but not necessarily) the number of bytes in the pixel format (for example, 2 for 16 bits per pixel) multiplied by the width of the bitmap. The value passed to this parameter must be a multiple of four.
        /// @param format The pixel format for the new image.
        /// @param scan0 Pointer to an array of bytes that contains the pixel data.
        /// @return A new image handle.
        /// @warning Internal use only
        static intptr create(int32 width, int32 height, int32 stride, int32 format, intptr scan0);
        /// @brief Creates and rescales an image from specified image, and size.
        /// @param image The image source handle.
        /// @param width The width for the new image.
        /// @param height The height for the new image.
        /// @return A new image handle.
        /// @warning Internal use only
        static intptr create(intptr image, int32 width, int32 height);
        /// @brief Creates and crops an image from specified image, position and size.
        /// @param image The image source handle.
        /// @param left The left for the new image.
        /// @param top The top of for new image.
        /// @param width The width for the new image.
        /// @param height The height for the new image.
        /// @return A new image handle.
        /// @warning Internal use only
        static intptr create(intptr image, int32 left, int32 top, int32 width, int32 height);
        
        /// @brief Destroys the image.
        /// @param image The image handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr image);
        
        /// @brief Gets attribute flags for the pixel data of this Image.
        /// @param image The image handle.
        /// @return The integer representing a bitwise combination of image flags for this Image (see image_flags.h for more information).
        /// @warning Internal use only
        static size_t flags(intptr image);
        
        /// @brief Creates a bitmap from a Windows handle to an icon.
        /// @param hicon A handle to an icon.
        /// @return A new bitmap handle.
        /// @warning Internal use only
        static intptr from_hicon(intptr icon);
        
        /// @brief Get the access to the alpah from this image.
        /// @param image A handle to an image.
        /// @return An alpha pointer of the image.
        /// @warning Internal use only
        static intptr get_alpha(intptr image);
        
        /// @brief Get the access to the data from this image.
        /// @param image A handle to an image.
        /// @return A data pointer of the image.
        /// @warning Internal use only
        static intptr get_data(intptr image);
        
        /// @brief Creates a GDI bitmap object from this image.
        /// @param image A handle to an image.
        /// @return A new bitmap handle.
        /// @warning Internal use only
        static intptr get_hbitmap(intptr image);
        
        /// @brief Creates a GDI bitmap object from this image.
        /// @param image A handle to an image.
        /// @param a The alpha componant of the background color.
        /// @param r The red componant of the background color.
        /// @param g The green componant of the background color.
        /// @param b The blue componant of the background color.
        /// @return A new bitmap handle.
        /// @warning Internal use only
        static intptr get_hbitmap(intptr image, xtd::byte a, xtd::byte r, xtd::byte g, xtd::byte b);
        
        /// @brief Returns the handle to an icon.
        /// @param image A handle to an image.
        /// @return A new icon handle.
        /// @warning Internal use only
        static intptr get_hicon(intptr image);
        
        /// @brief Gets the color of the specified pixel in the image.
        /// @param image The image handle.
        /// @param x The x-coordinate of the pixel to retrieve.
        /// @param y The y-coordinate of the pixel to retrieve.
        /// @param a The alpha component of the color of the specified pixel.
        /// @param r The red component of the color of the specified pixel.
        /// @param g The green component of the color of the specified pixel.
        /// @param b The blue component of the color of the specified pixel.
        /// @warning Internal use only
        static std::tuple<xtd::byte, xtd::byte, xtd::byte, xtd::byte> get_pixel(intptr image, int32 x, int32 y);
        
        /// @brief Gets the horizontal resolution, in pixels per inch, of the image.
        /// @param image The image handle.
        /// @return The horizontal resolution, in pixels per inch, of the image.
        /// @warning Internal use only
        static float horizontal_resolution(intptr image);
        
        /// @brief Locks a xtd::drawing::bitmap into system memory.
        /// @param image The image handle.
        /// @param top An int32 that specifies the top of the bitmap to lock.
        /// @param left An int32 that specifies the left of the bitmap to lock.
        /// @param width An int32 that specifies the width of the bitmap to lock.
        /// @param height An int32 that specifies the height of the bitmap to lock.
        /// @param flags An image lock mode value that specifies the access level (read/write) for the bitmap.
        /// @param format A pixel format value that specifies the data format of this bitmap.
        /// @param image_data_height The pixel height of the bitmap object. Also sometimes referred to as the number of scan lines.
        /// @param image_data_pixel_format A pixel format that specifies the format of the pixel information in the associated bitmap.
        /// @param image_data_reserved Reserved. Do not use.
        /// @param image_data_scan0 The address of the first pixel data in the bitmap.
        /// @param image_data_stride The stride width (also called scan width), in bytes, of the bitmap.
        /// @param image_data_width The pixel width of the bitmap. This can also be thought of as the number of pixels in one scan line.
        /// @return A xtd::drawing::imaging::bitmap_data that contains information about this lock operation.
        static void lock_bits(intptr image, int32 left, int32 top, int32 width, int32 height, int32 flags, int32 format, int32& image_data_height, int32& image_data_pixel_format, int32& image_data_reserved, intptr& image_data_scan0, int32& image_data_stride, int32& image_data_width);
        
        /// @brief Makes the specified color transparent for this bitmap.
        /// @param image The image handle.
        /// @param transprent_color_a The byte that represents the alpha component of the color to make transparent.
        /// @param transprent_color_r The byte that represents the red component of the color to make transparent.
        /// @param transprent_color_g The byte that represents the green component of the color to make transparent.
        /// @param transprent_color_b The byte that represents the blue component of the color to make transparent.
        static void make_transparent(intptr image, xtd::byte transparent_color_a, xtd::byte transparent_color_r, xtd::byte transparent_color_g, xtd::byte transparent_color_b);
        
        /// @brief Gets the width and height of this image.
        /// @param image The image handle.
        /// @param width A int32 that represents the width of the image.
        /// @param height A int32 that represents the height of the image.
        /// @warning Internal use only
        static void physical_dimension(intptr image, int32& width, int32& height);
        
        /// @brief Gets IDs of the property items stored in the image.
        /// @param image The image handle.
        /// @return An array of the property IDs, one for each property item stored in the image.
        /// @warning Internal use only
        static std::vector<int32> property_id_list(intptr image);
        
        /// @brief Gets all the property items (pieces of metadata) stored in the image.
        /// @param image The image handle.
        /// @return An array of xtd::drawing::native::image::property_item strutures, one for each property item stored in the image.
        /// @warning Internal use only
        static std::vector<property_item> property_items(intptr image);
        
        /// @brief Gets the pixel format for the image.
        /// @param image The image handle.
        /// @return A pixel_format that represents the pixel format for the image.
        /// @warning Internal use only
        static size_t pixel_format(intptr image);
        
        /// @brief Gets the file format of the image.
        /// @param image The image handle.
        /// @return The image format that represents the file format of this image (see image_formats.h for more information).
        /// @warning Internal use only
        static size_t raw_format(intptr image);
        
        /// @brief Gets the width and height, in pixels, of the image.
        /// @param image The image handle.
        /// @param width The width, in pixels, of the image.
        /// @param height The height, in pixels, of the image.
        /// @warning Internal use only
        static void size(intptr image, int32& width, int32& height);
        
        /// @brief Gets the vertical resolution, in pixels per inch, of the image.
        /// @param image The image handle.
        /// @return The vertical resolution, in pixels per inch, of the image.
        /// @warning Internal use only
        static float vertical_resolution(intptr image);
        
        /// @brief Rotates, flips, or rotates and flips the image.
        /// @param image The image handle.
        /// @param rotate_flip_type A value that specifies the type of rotation and flip to apply to the image (see rotate_flip_types.h for more information).
        /// @warning Internal use only
        static void rotate_flip(intptr image, int32 rotate_flip_type);
        
        /// @brief Sets the color of the specified pixel in the image.
        /// @param image The image handle.
        /// @param x The x-coordinate of the pixel to retrieve.
        /// @param y The y-coordinate of the pixel to retrieve.
        /// @param a The alpha component of the color of the specified pixel.
        /// @param r The red component of the color of the specified pixel.
        /// @param g The green component of the color of the specified pixel.
        /// @param b The blue component of the color of the specified pixel.
        /// @warning Internal use only
        static void set_pixel(intptr image, int32 x, int32 y, xtd::byte a, xtd::byte r, xtd::byte g, xtd::byte b);
        
        /// @brief Sets the resolution for this bitmap.
        /// @param image The image handle.
        /// @param x_dpi The horizontal resolution, in dots per inch, of the xtd::drawing::bitmap.
        /// @param y_dpi The vertical resolution, in dots per inch, of the xtd::drawing::bitmap.
        static void set_resolution(intptr image, int32 x_dpi, int32 y_dpi);
        
        /// @brief Saves image to the specified output filename.
        /// @param image The image handle.
        /// @param filename The file to save to.
        /// @warning Internal use only
        static void save(intptr image, const xtd::ustring& filename);
        /// @brief Saves image to the specified output filename and raw format.
        /// @param image The image handle.
        /// @param filename The file to save to.
        /// @param raw_format The image format that represents the file format of this image (see image_formats.h for more information).
        /// @warning Internal use only
        static void save(intptr image, const xtd::ustring& filename, size_t raw_format);
        /// @brief Saves image to the specified stream and raw format.
        /// @param image The image handle.
        /// @param stream The stream to save to.
        /// @param raw_format The image format that represents the file format of this image (see image_formats.h for more information).
        /// @warning Internal use only
        static void save(intptr image, std::ostream& stream, size_t raw_format);
        
        /// @brief Get the screen dpi.
        /// @return The screen dpi.
        /// @warning Internal use only
        static float screen_dpi();
        
        /// @brief Unlocks this Bitmap from system memory.
        /// @param image The image handle.
        /// @param image_data_height The pixel height of the bitmap object. Also sometimes referred to as the number of scan lines.
        /// @param image_data_pixel_format A pixel format that specifies the format of the pixel information in the associated bitmap.
        /// @param image_data_reserved Reserved. Do not use.
        /// @param image_data_scan0 The address of the first pixel data in the bitmap.
        /// @param image_data_stride The stride width (also called scan width), in bytes, of the bitmap.
        /// @param image_data_width The pixel width of the bitmap. This can also be thought of as the number of pixels in one scan line.
        static void unlock_bits(intptr image, int32& image_data_height, int32& image_data_pixel_format, int32& image_data_reserved, intptr& image_data_scan0, int32& image_data_stride, int32& image_data_width);
        /// @}
      };
    }
  }
}
