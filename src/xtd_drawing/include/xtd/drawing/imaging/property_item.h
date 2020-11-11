#pragma once
#include <cstdint>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd.drawing.imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief Encapsulates a metadata property to be included in an image file. Not inheritable.
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks The data consists of: an identifier, the length (in bytes) of the property, the property type, and a pointer to the property value.
      /// @remarks A property_item is not intended to be used as a stand-alone object. A property_item object is intended to be used by classes that are derived from image. A property_item object is used to retrieve and to change the metadata of existing image files, not to create the metadata. Therefore, the property_item class does not have a defined Public constructor, and you cannot create an instance of a property_item object.
      /// @remarks To work around the absence of a Public constructor, use an existing property_item object instead of creating a new instance of the property_item class. For more information, see image.Getproperty_item.
      class property_item final {
      public:
        /// @cond
        property_item() = default;
        /// @endcond
        
        /// @brief Gets the ID of the property.
        /// @return The integer that represents the ID of the property.
        /// @remarks The following table shows the property tags and their IDs.
        /// | ID     | Property tag                                  |
        /// |--------|-----------------------------------------------|
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
        /// | 0xA214 | property_tag_exif_dubject_loc                 |
        /// | 0xA215 | property_tag_exif_exposure_index              |
        /// | 0xA217 | property_tag_exif_sensing_method              |
        /// | 0xA300 | property_tag_exif_file_Source                 |
        /// | 0xA301 | property_tag_exif_scene_type                  |
        /// | 0xA302 | property_tag_exif_cfa_pattern                 |
        int32_t id() const {return this->id_;}
        /// @brief Sets the ID of the property.
        /// @param id The integer that represents the ID of the property.
        /// @remarks The following table shows the property tags and their IDs.
        /// | ID     | Property tag                                  |
        /// |--------|-----------------------------------------------|
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
        /// | 0xA214 | property_tag_exif_dubject_loc                 |
        /// | 0xA215 | property_tag_exif_exposure_index              |
        /// | 0xA217 | property_tag_exif_sensing_method              |
        /// | 0xA300 | property_tag_exif_file_Source                 |
        /// | 0xA301 | property_tag_exif_scene_type                  |
        /// | 0xA302 | property_tag_exif_cfa_pattern                 |
        void id(int32_t id) {this->id_ = id;}
        
        /// @brief Gets the length (in bytes) of the value property.
        /// @return An integer that represents the length (in bytes) of the value byte array.
        int32_t len() const {return this->len_;}
        /// @brief Sets the length (in bytes) of the value property.
        /// &param len An integer that represents the length (in bytes) of the value byte array.
        void len(int32_t len) {this->len_ = len;}
        
        /// @brief Gets an integer that defines the type of data contained in the value property.
        /// @return An integer that defines the type of data contained in value.
        /// @remarks The following table shows integers and the types they represent.
        /// | Integer | Represented Type                                                                                                                                                                                                                                            |
        /// |---------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        /// | 1       | Specifies that Value is an array of bytes.                                                                                                                                                                                                                  |
        /// | 2       | Specifies that Value is a null-terminated ASCII string. If you set the type data member to ASCII type, you should set the Len property to the length of the string including the null terminator. For example, the string "Hello" would have a length of 6. |
        /// | 3       | Specifies that Value is an array of unsigned short (16-bit) integers.                                                                                                                                                                                       |
        /// | 4       | Specifies that Value is an array of unsigned long (32-bit) integers.                                                                                                                                                                                        |
        /// | 5       | Specifies that Value data member is an array of pairs of unsigned long integers. Each pair represents a fraction; the first integer is the numerator and the second integer is the denominator.                                                             |
        /// | 6       | Specifies that Value is an array of bytes that can hold values of any data type.                                                                                                                                                                            |
        /// | 7       | Specifies that Value is an array of signed long (32-bit) integers.                                                                                                                                                                                          |
        /// | 10      | Specifies that Value is an array of pairs of signed long integers. Each pair represents a fraction; the first integer is the numerator and the second integer is the denominator.                                                                           |
        int16_t type() const {return this->type_;}
        /// @brief Sets an integer that defines the type of data contained in the value property.
        /// @param type An integer that defines the type of data contained in value.
        /// @remarks The following table shows integers and the types they represent.
        /// | Integer | Represented Type                                                                                                                                                                                                                                            |
        /// |---------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
        /// | 1       | Specifies that Value is an array of bytes.                                                                                                                                                                                                                  |
        /// | 2       | Specifies that Value is a null-terminated ASCII string. If you set the type data member to ASCII type, you should set the Len property to the length of the string including the null terminator. For example, the string "Hello" would have a length of 6. |
        /// | 3       | Specifies that Value is an array of unsigned short (16-bit) integers.                                                                                                                                                                                       |
        /// | 4       | Specifies that Value is an array of unsigned long (32-bit) integers.                                                                                                                                                                                        |
        /// | 5       | Specifies that Value data member is an array of pairs of unsigned long integers. Each pair represents a fraction; the first integer is the numerator and the second integer is the denominator.                                                             |
        /// | 6       | Specifies that Value is an array of bytes that can hold values of any data type.                                                                                                                                                                            |
        /// | 7       | Specifies that Value is an array of signed long (32-bit) integers.                                                                                                                                                                                          |
        /// | 10      | Specifies that Value is an array of pairs of signed long integers. Each pair represents a fraction; the first integer is the numerator and the second integer is the denominator.                                                                           |
        void type(int16_t type) {this->type_ = type;}
        
        /// @brief Gets the value of the property item.
        /// @return A byte array that represents the value of the property item.
        /// @remarks The byte array returned by the Value property contains data in one of several different primitive types. To use the data, determine the data type using the type property and convert the byte array accordingly.
        const std::vector<uint8_t>& value() const {return this->value_;}
        /// @brief Gets the value of the property item.
        /// @return A byte array that represents the value of the property item.
        /// @remarks The byte array returned by the Value property contains data in one of several different primitive types. To use the data, determine the data type using the type property and convert the byte array accordingly.
        std::vector<uint8_t>& value() {return this->value_;}
        /// @brief Sets the value of the property item.
        /// @param value A byte array that represents the value of the property item.
        /// @remarks The byte array returned by the Value property contains data in one of several different primitive types. To use the data, determine the data type using the type property and convert the byte array accordingly.
        void value(const std::vector<uint8_t>& value) {this->value_ = value;}

      private:
        int32_t id_ = 0;
        int32_t len_ = 0;
        int16_t type_ = 1;
        std::vector<uint8_t> value_;
      };
    }
  }
}
