/// @file
/// @brief Contains xtd::drawing::international_system_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::international_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ international_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::international_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/international_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ international_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets the international system image "flag-af".
      /// @return The xtd::drawing::image "flag-af".
      [[nodiscard]] static auto flag_af() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-af" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-af".
      [[nodiscard]] static auto flag_af(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ax".
      /// @return The xtd::drawing::image "flag-ax".
      [[nodiscard]] static auto flag_ax() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ax" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ax".
      [[nodiscard]] static auto flag_ax(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-al".
      /// @return The xtd::drawing::image "flag-al".
      [[nodiscard]] static auto flag_al() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-al" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-al".
      [[nodiscard]] static auto flag_al(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-dz".
      /// @return The xtd::drawing::image "flag-dz".
      [[nodiscard]] static auto flag_dz() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-dz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-dz".
      [[nodiscard]] static auto flag_dz(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-as".
      /// @return The xtd::drawing::image "flag-as".
      [[nodiscard]] static auto flag_as() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-as" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-as".
      [[nodiscard]] static auto flag_as(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ad".
      /// @return The xtd::drawing::image "flag-ad".
      [[nodiscard]] static auto flag_ad() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ad" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ad".
      [[nodiscard]] static auto flag_ad(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ao".
      /// @return The xtd::drawing::image "flag-ao".
      [[nodiscard]] static auto flag_ao() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ao" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ao".
      [[nodiscard]] static auto flag_ao(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ai".
      /// @return The xtd::drawing::image "flag-ai".
      [[nodiscard]] static auto flag_ai() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ai" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ai".
      [[nodiscard]] static auto flag_ai(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-aq".
      /// @return The xtd::drawing::image "flag-aq".
      [[nodiscard]] static auto flag_aq() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-aq" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-aq".
      [[nodiscard]] static auto flag_aq(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ag".
      /// @return The xtd::drawing::image "flag-ag".
      [[nodiscard]] static auto flag_ag() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ag" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ag".
      [[nodiscard]] static auto flag_ag(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ar".
      /// @return The xtd::drawing::image "flag-ar".
      [[nodiscard]] static auto flag_ar() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ar" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ar".
      [[nodiscard]] static auto flag_ar(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-am".
      /// @return The xtd::drawing::image "flag-am".
      [[nodiscard]] static auto flag_am() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-am" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-am".
      [[nodiscard]] static auto flag_am(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-aw".
      /// @return The xtd::drawing::image "flag-aw".
      [[nodiscard]] static auto flag_aw() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-aw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-aw".
      [[nodiscard]] static auto flag_aw(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-au".
      /// @return The xtd::drawing::image "flag-au".
      [[nodiscard]] static auto flag_au() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-au" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-au".
      [[nodiscard]] static auto flag_au(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-at".
      /// @return The xtd::drawing::image "flag-at".
      [[nodiscard]] static auto flag_at() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-at" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-at".
      [[nodiscard]] static auto flag_at(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-az".
      /// @return The xtd::drawing::image "flag-az".
      [[nodiscard]] static auto flag_az() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-az" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-az".
      [[nodiscard]] static auto flag_az(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bs".
      /// @return The xtd::drawing::image "flag-bs".
      [[nodiscard]] static auto flag_bs() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bs" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bs".
      [[nodiscard]] static auto flag_bs(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bh".
      /// @return The xtd::drawing::image "flag-bh".
      [[nodiscard]] static auto flag_bh() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bh".
      [[nodiscard]] static auto flag_bh(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bd".
      /// @return The xtd::drawing::image "flag-bd".
      [[nodiscard]] static auto flag_bd() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bd" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bd".
      [[nodiscard]] static auto flag_bd(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bb".
      /// @return The xtd::drawing::image "flag-bb".
      [[nodiscard]] static auto flag_bb() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bb" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bb".
      [[nodiscard]] static auto flag_bb(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-by".
      /// @return The xtd::drawing::image "flag-by".
      [[nodiscard]] static auto flag_by() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-by" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-by".
      [[nodiscard]] static auto flag_by(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-be".
      /// @return The xtd::drawing::image "flag-be".
      [[nodiscard]] static auto flag_be() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-be" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-be".
      [[nodiscard]] static auto flag_be(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bz".
      /// @return The xtd::drawing::image "flag-bz".
      [[nodiscard]] static auto flag_bz() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bz".
      [[nodiscard]] static auto flag_bz(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bj".
      /// @return The xtd::drawing::image "flag-bj".
      [[nodiscard]] static auto flag_bj() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bj" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bj".
      [[nodiscard]] static auto flag_bj(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bm".
      /// @return The xtd::drawing::image "flag-bm".
      [[nodiscard]] static auto flag_bm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bm".
      [[nodiscard]] static auto flag_bm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bt".
      /// @return The xtd::drawing::image "flag-bt".
      [[nodiscard]] static auto flag_bt() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bt".
      [[nodiscard]] static auto flag_bt(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bo".
      /// @return The xtd::drawing::image "flag-bo".
      [[nodiscard]] static auto flag_bo() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bo" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bo".
      [[nodiscard]] static auto flag_bo(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bq".
      /// @return The xtd::drawing::image "flag-bq".
      [[nodiscard]] static auto flag_bq() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bq" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bq".
      [[nodiscard]] static auto flag_bq(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ba".
      /// @return The xtd::drawing::image "flag-ba".
      [[nodiscard]] static auto flag_ba() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ba" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ba".
      [[nodiscard]] static auto flag_ba(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bw".
      /// @return The xtd::drawing::image "flag-bw".
      [[nodiscard]] static auto flag_bw() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bw".
      [[nodiscard]] static auto flag_bw(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bv".
      /// @return The xtd::drawing::image "flag-bv".
      [[nodiscard]] static auto flag_bv() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bv".
      [[nodiscard]] static auto flag_bv(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-br".
      /// @return The xtd::drawing::image "flag-br".
      [[nodiscard]] static auto flag_br() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-br" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-br".
      [[nodiscard]] static auto flag_br(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-io".
      /// @return The xtd::drawing::image "flag-io".
      [[nodiscard]] static auto flag_io() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-io" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-io".
      [[nodiscard]] static auto flag_io(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bn".
      /// @return The xtd::drawing::image "flag-bn".
      [[nodiscard]] static auto flag_bn() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bn".
      [[nodiscard]] static auto flag_bn(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bg".
      /// @return The xtd::drawing::image "flag-bg".
      [[nodiscard]] static auto flag_bg() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bg".
      [[nodiscard]] static auto flag_bg(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bf".
      /// @return The xtd::drawing::image "flag-bf".
      [[nodiscard]] static auto flag_bf() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bf".
      [[nodiscard]] static auto flag_bf(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bi".
      /// @return The xtd::drawing::image "flag-bi".
      [[nodiscard]] static auto flag_bi() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bi" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bi".
      [[nodiscard]] static auto flag_bi(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cv".
      /// @return The xtd::drawing::image "flag-cv".
      [[nodiscard]] static auto flag_cv() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cv".
      [[nodiscard]] static auto flag_cv(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-kh".
      /// @return The xtd::drawing::image "flag-kh".
      [[nodiscard]] static auto flag_kh() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-kh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kh".
      [[nodiscard]] static auto flag_kh(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cm".
      /// @return The xtd::drawing::image "flag-cm".
      [[nodiscard]] static auto flag_cm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cm".
      [[nodiscard]] static auto flag_cm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ca".
      /// @return The xtd::drawing::image "flag-ca".
      [[nodiscard]] static auto flag_ca() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ca" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ca".
      [[nodiscard]] static auto flag_ca(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ky".
      /// @return The xtd::drawing::image "flag-ky".
      [[nodiscard]] static auto flag_ky() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ky" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ky".
      [[nodiscard]] static auto flag_ky(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cf".
      /// @return The xtd::drawing::image "flag-cf".
      [[nodiscard]] static auto flag_cf() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cf".
      [[nodiscard]] static auto flag_cf(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-td".
      /// @return The xtd::drawing::image "flag-td".
      [[nodiscard]] static auto flag_td() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-td" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-td".
      [[nodiscard]] static auto flag_td(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cl".
      /// @return The xtd::drawing::image "flag-cl".
      [[nodiscard]] static auto flag_cl() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cl".
      [[nodiscard]] static auto flag_cl(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cn".
      /// @return The xtd::drawing::image "flag-cn".
      [[nodiscard]] static auto flag_cn() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cn".
      [[nodiscard]] static auto flag_cn(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cx".
      /// @return The xtd::drawing::image "flag-cx".
      [[nodiscard]] static auto flag_cx() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cx" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cx".
      [[nodiscard]] static auto flag_cx(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cc".
      /// @return The xtd::drawing::image "flag-cc".
      [[nodiscard]] static auto flag_cc() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cc".
      [[nodiscard]] static auto flag_cc(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-co".
      /// @return The xtd::drawing::image "flag-co".
      [[nodiscard]] static auto flag_co() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-co" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-co".
      [[nodiscard]] static auto flag_co(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-km".
      /// @return The xtd::drawing::image "flag-km".
      [[nodiscard]] static auto flag_km() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-km" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-km".
      [[nodiscard]] static auto flag_km(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cg".
      /// @return The xtd::drawing::image "flag-cg".
      [[nodiscard]] static auto flag_cg() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cg".
      [[nodiscard]] static auto flag_cg(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cd".
      /// @return The xtd::drawing::image "flag-cd".
      [[nodiscard]] static auto flag_cd() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cd" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cd".
      [[nodiscard]] static auto flag_cd(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ck".
      /// @return The xtd::drawing::image "flag-ck".
      [[nodiscard]] static auto flag_ck() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ck" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ck".
      [[nodiscard]] static auto flag_ck(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cr".
      /// @return The xtd::drawing::image "flag-cr".
      [[nodiscard]] static auto flag_cr() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cr".
      [[nodiscard]] static auto flag_cr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ci".
      /// @return The xtd::drawing::image "flag-ci".
      [[nodiscard]] static auto flag_ci() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ci" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ci".
      [[nodiscard]] static auto flag_ci(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-hr".
      /// @return The xtd::drawing::image "flag-hr".
      [[nodiscard]] static auto flag_hr() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-hr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-hr".
      [[nodiscard]] static auto flag_hr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cu".
      /// @return The xtd::drawing::image "flag-cu".
      [[nodiscard]] static auto flag_cu() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cu".
      [[nodiscard]] static auto flag_cu(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cw".
      /// @return The xtd::drawing::image "flag-cw".
      [[nodiscard]] static auto flag_cw() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cw".
      [[nodiscard]] static auto flag_cw(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cy".
      /// @return The xtd::drawing::image "flag-cy".
      [[nodiscard]] static auto flag_cy() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cy" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cy".
      [[nodiscard]] static auto flag_cy(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-cz".
      /// @return The xtd::drawing::image "flag-cz".
      [[nodiscard]] static auto flag_cz() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-cz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cz".
      [[nodiscard]] static auto flag_cz(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-dk".
      /// @return The xtd::drawing::image "flag-dk".
      [[nodiscard]] static auto flag_dk() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-dk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-dk".
      [[nodiscard]] static auto flag_dk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-dj".
      /// @return The xtd::drawing::image "flag-dj".
      [[nodiscard]] static auto flag_dj() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-dj" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-dj".
      [[nodiscard]] static auto flag_dj(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-dm".
      /// @return The xtd::drawing::image "flag-dm".
      [[nodiscard]] static auto flag_dm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-dm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-dm".
      [[nodiscard]] static auto flag_dm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-do".
      /// @return The xtd::drawing::image "flag-do".
      [[nodiscard]] static auto flag_do() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-do" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-do".
      [[nodiscard]] static auto flag_do(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ec".
      /// @return The xtd::drawing::image "flag-ec".
      [[nodiscard]] static auto flag_ec() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ec" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ec".
      [[nodiscard]] static auto flag_ec(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-eg".
      /// @return The xtd::drawing::image "flag-eg".
      [[nodiscard]] static auto flag_eg() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-eg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-eg".
      [[nodiscard]] static auto flag_eg(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sv".
      /// @return The xtd::drawing::image "flag-sv".
      [[nodiscard]] static auto flag_sv() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sv".
      [[nodiscard]] static auto flag_sv(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gq".
      /// @return The xtd::drawing::image "flag-gq".
      [[nodiscard]] static auto flag_gq() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gq" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gq".
      [[nodiscard]] static auto flag_gq(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-er".
      /// @return The xtd::drawing::image "flag-er".
      [[nodiscard]] static auto flag_er() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-er" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-er".
      [[nodiscard]] static auto flag_er(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ee".
      /// @return The xtd::drawing::image "flag-ee".
      [[nodiscard]] static auto flag_ee() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ee" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ee".
      [[nodiscard]] static auto flag_ee(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sz".
      /// @return The xtd::drawing::image "flag-sz".
      [[nodiscard]] static auto flag_z() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sz".
      [[nodiscard]] static auto flag_z(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-et".
      /// @return The xtd::drawing::image "flag-et".
      [[nodiscard]] static auto flag_et() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-et" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-et".
      [[nodiscard]] static auto flag_et(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-fk".
      /// @return The xtd::drawing::image "flag-fk".
      [[nodiscard]] static auto flag_fk() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-fk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fk".
      [[nodiscard]] static auto flag_fk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-fo".
      /// @return The xtd::drawing::image "flag-fo".
      [[nodiscard]] static auto flag_fo() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-fo" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fo".
      [[nodiscard]] static auto flag_fo(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-fj".
      /// @return The xtd::drawing::image "flag-fj".
      [[nodiscard]] static auto flag_fj() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-fj" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fj".
      [[nodiscard]] static auto flag_fj(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-fi".
      /// @return The xtd::drawing::image "flag-fi".
      [[nodiscard]] static auto flag_fi() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-fi" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fi".
      [[nodiscard]] static auto flag_fi(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-fr".
      /// @return The xtd::drawing::image "flag-fr".
      [[nodiscard]] static auto flag_fr() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-fr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fr".
      [[nodiscard]] static auto flag_fr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gf".
      /// @return The xtd::drawing::image "flag-gf".
      [[nodiscard]] static auto flag_gf() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gf".
      [[nodiscard]] static auto flag_gf(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-pf".
      /// @return The xtd::drawing::image "flag-pf".
      [[nodiscard]] static auto flag_pf() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-pf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pf".
      [[nodiscard]] static auto flag_pf(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tf".
      /// @return The xtd::drawing::image "flag-tf".
      [[nodiscard]] static auto flag_tf() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tf".
      [[nodiscard]] static auto flag_tf(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ga".
      /// @return The xtd::drawing::image "flag-ga".
      [[nodiscard]] static auto flag_ga() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ga" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ga".
      [[nodiscard]] static auto flag_ga(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gm".
      /// @return The xtd::drawing::image "flag-gm".
      [[nodiscard]] static auto flag_gm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gm".
      [[nodiscard]] static auto flag_gm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ge".
      /// @return The xtd::drawing::image "flag-ge".
      [[nodiscard]] static auto flag_ge() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ge" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ge".
      [[nodiscard]] static auto flag_ge(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-de".
      /// @return The xtd::drawing::image "flag-de".
      [[nodiscard]] static auto flag_de() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-de" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-de".
      [[nodiscard]] static auto flag_de(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gh".
      /// @return The xtd::drawing::image "flag-gh".
      [[nodiscard]] static auto flag_gh() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gh".
      [[nodiscard]] static auto flag_gh(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gi".
      /// @return The xtd::drawing::image "flag-gi".
      [[nodiscard]] static auto flag_gi() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gi" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gi".
      [[nodiscard]] static auto flag_gi(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gr".
      /// @return The xtd::drawing::image "flag-gr".
      [[nodiscard]] static auto flag_gr() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gr".
      [[nodiscard]] static auto flag_gr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gl".
      /// @return The xtd::drawing::image "flag-gl".
      [[nodiscard]] static auto flag_gl() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gl".
      [[nodiscard]] static auto flag_gl(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gd".
      /// @return The xtd::drawing::image "flag-gd".
      [[nodiscard]] static auto flag_gd() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gd" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gd".
      [[nodiscard]] static auto flag_gd(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gp".
      /// @return The xtd::drawing::image "flag-gp".
      [[nodiscard]] static auto flag_gp() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gp" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gp".
      [[nodiscard]] static auto flag_gp(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gu".
      /// @return The xtd::drawing::image "flag-gu".
      [[nodiscard]] static auto flag_gu() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gu".
      [[nodiscard]] static auto flag_gu(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gt".
      /// @return The xtd::drawing::image "flag-gt".
      [[nodiscard]] static auto flag_gt() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gt".
      [[nodiscard]] static auto flag_gt(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gg".
      /// @return The xtd::drawing::image "flag-gg".
      [[nodiscard]] static auto flag_gg() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gg".
      [[nodiscard]] static auto flag_gg(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gn".
      /// @return The xtd::drawing::image "flag-gn".
      [[nodiscard]] static auto flag_gn() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gn".
      [[nodiscard]] static auto flag_gn(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gw".
      /// @return The xtd::drawing::image "flag-gw".
      [[nodiscard]] static auto flag_gw() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gw".
      [[nodiscard]] static auto flag_gw(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gy".
      /// @return The xtd::drawing::image "flag-gy".
      [[nodiscard]] static auto flag_gy() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gy" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gy".
      [[nodiscard]] static auto flag_gy(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ht".
      /// @return The xtd::drawing::image "flag-ht".
      [[nodiscard]] static auto flag_ht() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ht" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ht".
      [[nodiscard]] static auto flag_ht(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-hm".
      /// @return The xtd::drawing::image "flag-hm".
      [[nodiscard]] static auto flag_hm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-hm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-hm".
      [[nodiscard]] static auto flag_hm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-va".
      /// @return The xtd::drawing::image "flag-va".
      [[nodiscard]] static auto flag_va() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-va" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-va".
      [[nodiscard]] static auto flag_va(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-hn".
      /// @return The xtd::drawing::image "flag-hn".
      [[nodiscard]] static auto flag_hn() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-hn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-hn".
      [[nodiscard]] static auto flag_hn(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-hk".
      /// @return The xtd::drawing::image "flag-hk".
      [[nodiscard]] static auto flag_hk() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-hk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-hk".
      [[nodiscard]] static auto flag_hk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-hu".
      /// @return The xtd::drawing::image "flag-hu".
      [[nodiscard]] static auto flag_hu() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-hu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-hu".
      [[nodiscard]] static auto flag_hu(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-is".
      /// @return The xtd::drawing::image "flag-is".
      [[nodiscard]] static auto flag_is() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-is" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-is".
      [[nodiscard]] static auto flag_is(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-in".
      /// @return The xtd::drawing::image "flag-in".
      [[nodiscard]] static auto flag_in() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-in" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-in".
      [[nodiscard]] static auto flag_in(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-id".
      /// @return The xtd::drawing::image "flag-id".
      [[nodiscard]] static auto flag_id() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-id" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-id".
      [[nodiscard]] static auto flag_id(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ir".
      /// @return The xtd::drawing::image "flag-ir".
      [[nodiscard]] static auto flag_ir() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ir" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ir".
      [[nodiscard]] static auto flag_ir(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-iq".
      /// @return The xtd::drawing::image "flag-iq".
      [[nodiscard]] static auto flag_iq() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-iq" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-iq".
      [[nodiscard]] static auto flag_iq(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ie".
      /// @return The xtd::drawing::image "flag-ie".
      [[nodiscard]] static auto flag_ie() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ie" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ie".
      [[nodiscard]] static auto flag_ie(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-im".
      /// @return The xtd::drawing::image "flag-im".
      [[nodiscard]] static auto flag_im() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-im" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-im".
      [[nodiscard]] static auto flag_im(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-il".
      /// @return The xtd::drawing::image "flag-il".
      [[nodiscard]] static auto flag_il() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-il" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-il".
      [[nodiscard]] static auto flag_il(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-it".
      /// @return The xtd::drawing::image "flag-it".
      [[nodiscard]] static auto flag_it() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-it" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-it".
      [[nodiscard]] static auto flag_it(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-jm".
      /// @return The xtd::drawing::image "flag-jm".
      [[nodiscard]] static auto flag_jm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-jm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-jm".
      [[nodiscard]] static auto flag_jm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-jp".
      /// @return The xtd::drawing::image "flag-jp".
      [[nodiscard]] static auto flag_jp() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-jp" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-jp".
      [[nodiscard]] static auto flag_jp(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-je".
      /// @return The xtd::drawing::image "flag-je".
      [[nodiscard]] static auto flag_je() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-je" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-je".
      [[nodiscard]] static auto flag_je(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-jo".
      /// @return The xtd::drawing::image "flag-jo".
      [[nodiscard]] static auto flag_jo() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-jo" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-jo".
      [[nodiscard]] static auto flag_jo(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-kz".
      /// @return The xtd::drawing::image "flag-kz".
      [[nodiscard]] static auto flag_kz() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-kz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kz".
      [[nodiscard]] static auto flag_kz(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ke".
      /// @return The xtd::drawing::image "flag-ke".
      [[nodiscard]] static auto flag_ke() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ke" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ke".
      [[nodiscard]] static auto flag_ke(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ki".
      /// @return The xtd::drawing::image "flag-ki".
      [[nodiscard]] static auto flag_ki() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ki" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ki".
      [[nodiscard]] static auto flag_ki(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-kp".
      /// @return The xtd::drawing::image "flag-kp".
      [[nodiscard]] static auto flag_kp() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-kp" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kp".
      [[nodiscard]] static auto flag_kp(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-kr".
      /// @return The xtd::drawing::image "flag-kr".
      [[nodiscard]] static auto flag_kr() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-kr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kr".
      [[nodiscard]] static auto flag_kr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-kw".
      /// @return The xtd::drawing::image "flag-kw".
      [[nodiscard]] static auto flag_kw() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-kw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kw".
      [[nodiscard]] static auto flag_kw(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-kg".
      /// @return The xtd::drawing::image "flag-kg".
      [[nodiscard]] static auto flag_kg() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-kg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kg".
      [[nodiscard]] static auto flag_kg(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-la".
      /// @return The xtd::drawing::image "flag-la".
      [[nodiscard]] static auto flag_la() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-la" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-la".
      [[nodiscard]] static auto flag_la(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-lv".
      /// @return The xtd::drawing::image "flag-lv".
      [[nodiscard]] static auto flag_lv() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-lv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lv".
      [[nodiscard]] static auto flag_lv(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-lb".
      /// @return The xtd::drawing::image "flag-lb".
      [[nodiscard]] static auto flag_lb() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-lb" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lb".
      [[nodiscard]] static auto flag_lb(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ls".
      /// @return The xtd::drawing::image "flag-ls".
      [[nodiscard]] static auto flag_ls() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ls" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ls".
      [[nodiscard]] static auto flag_ls(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-lr".
      /// @return The xtd::drawing::image "flag-lr".
      [[nodiscard]] static auto flag_lr() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-lr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lr".
      [[nodiscard]] static auto flag_lr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ly".
      /// @return The xtd::drawing::image "flag-ly".
      [[nodiscard]] static auto flag_ly() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ly" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ly".
      [[nodiscard]] static auto flag_ly(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-li".
      /// @return The xtd::drawing::image "flag-li".
      [[nodiscard]] static auto flag_li() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-li" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-li".
      [[nodiscard]] static auto flag_li(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-lt".
      /// @return The xtd::drawing::image "flag-lt".
      [[nodiscard]] static auto flag_lt() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-lt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lt".
      [[nodiscard]] static auto flag_lt(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-lu".
      /// @return The xtd::drawing::image "flag-lu".
      [[nodiscard]] static auto flag_lu() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-lu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lu".
      [[nodiscard]] static auto flag_lu(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mo".
      /// @return The xtd::drawing::image "flag-mo".
      [[nodiscard]] static auto flag_mo() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mo" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mo".
      [[nodiscard]] static auto flag_mo(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mg".
      /// @return The xtd::drawing::image "flag-mg".
      [[nodiscard]] static auto flag_mg() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mg".
      [[nodiscard]] static auto flag_mg(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mw".
      /// @return The xtd::drawing::image "flag-mw".
      [[nodiscard]] static auto flag_mw() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mw".
      [[nodiscard]] static auto flag_mw(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-my".
      /// @return The xtd::drawing::image "flag-my".
      [[nodiscard]] static auto flag_my() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-my" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-my".
      [[nodiscard]] static auto flag_my(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mv".
      /// @return The xtd::drawing::image "flag-mv".
      [[nodiscard]] static auto flag_mv() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mv".
      [[nodiscard]] static auto flag_mv(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ml".
      /// @return The xtd::drawing::image "flag-ml".
      [[nodiscard]] static auto flag_ml() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ml" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ml".
      [[nodiscard]] static auto flag_ml(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mt".
      /// @return The xtd::drawing::image "flag-mt".
      [[nodiscard]] static auto flag_mt() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mt".
      [[nodiscard]] static auto flag_mt(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mh".
      /// @return The xtd::drawing::image "flag-mh".
      [[nodiscard]] static auto flag_mh() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mh".
      [[nodiscard]] static auto flag_mh(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mq".
      /// @return The xtd::drawing::image "flag-mq".
      [[nodiscard]] static auto flag_mq() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mq" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mq".
      [[nodiscard]] static auto flag_mq(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mr".
      /// @return The xtd::drawing::image "flag-mr".
      [[nodiscard]] static auto flag_mr() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mr".
      [[nodiscard]] static auto flag_mr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mu".
      /// @return The xtd::drawing::image "flag-mu".
      [[nodiscard]] static auto flag_mu() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mu".
      [[nodiscard]] static auto flag_mu(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-yt".
      /// @return The xtd::drawing::image "flag-yt".
      [[nodiscard]] static auto flag_yt() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-yt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-yt".
      [[nodiscard]] static auto flag_yt(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mx".
      /// @return The xtd::drawing::image "flag-mx".
      [[nodiscard]] static auto flag_mx() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mx" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mx".
      [[nodiscard]] static auto flag_mx(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-fm".
      /// @return The xtd::drawing::image "flag-fm".
      [[nodiscard]] static auto flag_fm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-fm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fm".
      [[nodiscard]] static auto flag_fm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-md".
      /// @return The xtd::drawing::image "flag-md".
      [[nodiscard]] static auto flag_md() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-md" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-md".
      [[nodiscard]] static auto flag_md(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mc".
      /// @return The xtd::drawing::image "flag-mc".
      [[nodiscard]] static auto flag_mc() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mc".
      [[nodiscard]] static auto flag_mc(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mn".
      /// @return The xtd::drawing::image "flag-mn".
      [[nodiscard]] static auto flag_mn() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mn".
      [[nodiscard]] static auto flag_mn(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-me".
      /// @return The xtd::drawing::image "flag-me".
      [[nodiscard]] static auto flag_me() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-me" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-me".
      [[nodiscard]] static auto flag_me(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ms".
      /// @return The xtd::drawing::image "flag-ms".
      [[nodiscard]] static auto flag_ms() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ms" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ms".
      [[nodiscard]] static auto flag_ms(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ma".
      /// @return The xtd::drawing::image "flag-ma".
      [[nodiscard]] static auto flag_ma() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ma" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ma".
      [[nodiscard]] static auto flag_ma(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mz".
      /// @return The xtd::drawing::image "flag-mz".
      [[nodiscard]] static auto flag_mz() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mz".
      [[nodiscard]] static auto flag_mz(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mm".
      /// @return The xtd::drawing::image "flag-mm".
      [[nodiscard]] static auto flag_mm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mm".
      [[nodiscard]] static auto flag_mm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-na".
      /// @return The xtd::drawing::image "flag-na".
      [[nodiscard]] static auto flag_na() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-na" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-na".
      [[nodiscard]] static auto flag_na(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-nr".
      /// @return The xtd::drawing::image "flag-nr".
      [[nodiscard]] static auto flag_nr() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-nr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nr".
      [[nodiscard]] static auto flag_nr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-np".
      /// @return The xtd::drawing::image "flag-np".
      [[nodiscard]] static auto flag_np() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-np" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-np".
      [[nodiscard]] static auto flag_np(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-nl".
      /// @return The xtd::drawing::image "flag-nl".
      [[nodiscard]] static auto flag_nl() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-nl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nl".
      [[nodiscard]] static auto flag_nl(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-nc".
      /// @return The xtd::drawing::image "flag-nc".
      [[nodiscard]] static auto flag_nc() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-nc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nc".
      [[nodiscard]] static auto flag_nc(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-nz".
      /// @return The xtd::drawing::image "flag-nz".
      [[nodiscard]] static auto flag_nz() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-nz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nz".
      [[nodiscard]] static auto flag_nz(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ni".
      /// @return The xtd::drawing::image "flag-ni".
      [[nodiscard]] static auto flag_ni() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ni" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ni".
      [[nodiscard]] static auto flag_ni(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ne".
      /// @return The xtd::drawing::image "flag-ne".
      [[nodiscard]] static auto flag_ne() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ne" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ne".
      [[nodiscard]] static auto flag_ne(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ng".
      /// @return The xtd::drawing::image "flag-ng".
      [[nodiscard]] static auto flag_ng() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ng" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ng".
      [[nodiscard]] static auto flag_ng(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-nu".
      /// @return The xtd::drawing::image "flag-nu".
      [[nodiscard]] static auto flag_nu() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-nu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nu".
      [[nodiscard]] static auto flag_nu(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-nf".
      /// @return The xtd::drawing::image "flag-nf".
      [[nodiscard]] static auto flag_nf() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-nf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nf".
      [[nodiscard]] static auto flag_nf(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mk".
      /// @return The xtd::drawing::image "flag-mk".
      [[nodiscard]] static auto flag_mk() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mk".
      [[nodiscard]] static auto flag_mk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mp".
      /// @return The xtd::drawing::image "flag-mp".
      [[nodiscard]] static auto flag_mp() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mp" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mp".
      [[nodiscard]] static auto flag_mp(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-no".
      /// @return The xtd::drawing::image "flag-no".
      [[nodiscard]] static auto flag_no() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-no" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-no".
      [[nodiscard]] static auto flag_no(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-om".
      /// @return The xtd::drawing::image "flag-om".
      [[nodiscard]] static auto flag_om() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-om" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-om".
      [[nodiscard]] static auto flag_om(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-pk".
      /// @return The xtd::drawing::image "flag-pk".
      [[nodiscard]] static auto flag_pk() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-pk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pk".
      [[nodiscard]] static auto flag_pk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-pw".
      /// @return The xtd::drawing::image "flag-pw".
      [[nodiscard]] static auto flag_pw() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-pw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pw".
      [[nodiscard]] static auto flag_pw(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ps".
      /// @return The xtd::drawing::image "flag-ps".
      [[nodiscard]] static auto flag_ps() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ps" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ps".
      [[nodiscard]] static auto flag_ps(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-pa".
      /// @return The xtd::drawing::image "flag-pa".
      [[nodiscard]] static auto flag_pa() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-pa" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pa".
      [[nodiscard]] static auto flag_pa(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-pg".
      /// @return The xtd::drawing::image "flag-pg".
      [[nodiscard]] static auto flag_pg() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-pg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pg".
      [[nodiscard]] static auto flag_pg(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-py".
      /// @return The xtd::drawing::image "flag-py".
      [[nodiscard]] static auto flag_py() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-py" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-py".
      [[nodiscard]] static auto flag_py(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-pe".
      /// @return The xtd::drawing::image "flag-pe".
      [[nodiscard]] static auto flag_pe() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-pe" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pe".
      [[nodiscard]] static auto flag_pe(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ph".
      /// @return The xtd::drawing::image "flag-ph".
      [[nodiscard]] static auto flag_ph() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ph" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ph".
      [[nodiscard]] static auto flag_ph(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-pn".
      /// @return The xtd::drawing::image "flag-pn".
      [[nodiscard]] static auto flag_pn() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-pn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pn".
      [[nodiscard]] static auto flag_pn(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-pl".
      /// @return The xtd::drawing::image "flag-pl".
      [[nodiscard]] static auto flag_pl() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-pl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pl".
      [[nodiscard]] static auto flag_pl(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-pt".
      /// @return The xtd::drawing::image "flag-pt".
      [[nodiscard]] static auto flag_pt() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-pt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pt".
      [[nodiscard]] static auto flag_pt(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-pr".
      /// @return The xtd::drawing::image "flag-pr".
      [[nodiscard]] static auto flag_pr() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-pr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pr".
      [[nodiscard]] static auto flag_pr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-qa".
      /// @return The xtd::drawing::image "flag-qa".
      [[nodiscard]] static auto flag_qa() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-qa" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-qa".
      [[nodiscard]] static auto flag_qa(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-re".
      /// @return The xtd::drawing::image "flag-re".
      [[nodiscard]] static auto flag_re() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-re" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-re".
      [[nodiscard]] static auto flag_re(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ro".
      /// @return The xtd::drawing::image "flag-ro".
      [[nodiscard]] static auto flag_ro() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ro" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ro".
      [[nodiscard]] static auto flag_ro(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ru".
      /// @return The xtd::drawing::image "flag-ru".
      [[nodiscard]] static auto flag_ru() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ru" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ru".
      [[nodiscard]] static auto flag_ru(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-rw".
      /// @return The xtd::drawing::image "flag-rw".
      [[nodiscard]] static auto flag_rw() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-rw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-rw".
      [[nodiscard]] static auto flag_rw(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-bl".
      /// @return The xtd::drawing::image "flag-bl".
      [[nodiscard]] static auto flag_bl() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-bl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bl".
      [[nodiscard]] static auto flag_bl(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sh".
      /// @return The xtd::drawing::image "flag-sh".
      [[nodiscard]] static auto flag_sh() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sh".
      [[nodiscard]] static auto flag_sh(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-kn".
      /// @return The xtd::drawing::image "flag-kn".
      [[nodiscard]] static auto flag_kn() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-kn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kn".
      [[nodiscard]] static auto flag_kn(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-lc".
      /// @return The xtd::drawing::image "flag-lc".
      [[nodiscard]] static auto flag_lc() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-lc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lc".
      [[nodiscard]] static auto flag_lc(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-mf".
      /// @return The xtd::drawing::image "flag-mf".
      [[nodiscard]] static auto flag_mf() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-mf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mf".
      [[nodiscard]] static auto flag_mf(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-pm".
      /// @return The xtd::drawing::image "flag-pm".
      [[nodiscard]] static auto flag_pm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-pm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pm".
      [[nodiscard]] static auto flag_pm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-vc".
      /// @return The xtd::drawing::image "flag-vc".
      [[nodiscard]] static auto flag_vc() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-vc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-vc".
      [[nodiscard]] static auto flag_vc(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ws".
      /// @return The xtd::drawing::image "flag-ws".
      [[nodiscard]] static auto flag_ws() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ws" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ws".
      [[nodiscard]] static auto flag_ws(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sm".
      /// @return The xtd::drawing::image "flag-sm".
      [[nodiscard]] static auto flag_sm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sm".
      [[nodiscard]] static auto flag_sm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-st".
      /// @return The xtd::drawing::image "flag-st".
      [[nodiscard]] static auto flag_st() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-st" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-st".
      [[nodiscard]] static auto flag_st(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sa".
      /// @return The xtd::drawing::image "flag-sa".
      [[nodiscard]] static auto flag_sa() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sa" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sa".
      [[nodiscard]] static auto flag_sa(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sn".
      /// @return The xtd::drawing::image "flag-sn".
      [[nodiscard]] static auto flag_sn() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sn".
      [[nodiscard]] static auto flag_sn(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-rs".
      /// @return The xtd::drawing::image "flag-rs".
      [[nodiscard]] static auto flag_rs() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-rs" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-rs".
      [[nodiscard]] static auto flag_rs(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sc".
      /// @return The xtd::drawing::image "flag-sc".
      [[nodiscard]] static auto flag_sc() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sc".
      [[nodiscard]] static auto flag_sc(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sl".
      /// @return The xtd::drawing::image "flag-sl".
      [[nodiscard]] static auto flag_sl() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sl".
      [[nodiscard]] static auto flag_sl(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sg".
      /// @return The xtd::drawing::image "flag-sg".
      [[nodiscard]] static auto flag_sg() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sg".
      [[nodiscard]] static auto flag_sg(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sx".
      /// @return The xtd::drawing::image "flag-sx".
      [[nodiscard]] static auto flag_sx() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sx" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sx".
      [[nodiscard]] static auto flag_sx(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sk".
      /// @return The xtd::drawing::image "flag-sk".
      [[nodiscard]] static auto flag_sk() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sk".
      [[nodiscard]] static auto flag_sk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-si".
      /// @return The xtd::drawing::image "flag-si".
      [[nodiscard]] static auto flag_si() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-si" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-si".
      [[nodiscard]] static auto flag_si(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sb".
      /// @return The xtd::drawing::image "flag-sb".
      [[nodiscard]] static auto flag_sb() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sb" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sb".
      [[nodiscard]] static auto flag_sb(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-so".
      /// @return The xtd::drawing::image "flag-so".
      [[nodiscard]] static auto flag_so() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-so" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-so".
      [[nodiscard]] static auto flag_so(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-za".
      /// @return The xtd::drawing::image "flag-za".
      [[nodiscard]] static auto flag_za() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-za" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-za".
      [[nodiscard]] static auto flag_za(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gs".
      /// @return The xtd::drawing::image "flag-gs".
      [[nodiscard]] static auto flag_gs() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gs" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gs".
      [[nodiscard]] static auto flag_gs(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ss".
      /// @return The xtd::drawing::image "flag-ss".
      [[nodiscard]] static auto flag_ss() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ss" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ss".
      [[nodiscard]] static auto flag_ss(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-es".
      /// @return The xtd::drawing::image "flag-es".
      [[nodiscard]] static auto flag_es() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-es" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-es".
      [[nodiscard]] static auto flag_es(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-lk".
      /// @return The xtd::drawing::image "flag-lk".
      [[nodiscard]] static auto flag_lk() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-lk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lk".
      [[nodiscard]] static auto flag_lk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sd".
      /// @return The xtd::drawing::image "flag-sd".
      [[nodiscard]] static auto flag_sd() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sd" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sd".
      [[nodiscard]] static auto flag_sd(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sr".
      /// @return The xtd::drawing::image "flag-sr".
      [[nodiscard]] static auto flag_sr() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sr".
      [[nodiscard]] static auto flag_sr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sj".
      /// @return The xtd::drawing::image "flag-sj".
      [[nodiscard]] static auto flag_sj() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sj" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sj".
      [[nodiscard]] static auto flag_sj(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-se".
      /// @return The xtd::drawing::image "flag-se".
      [[nodiscard]] static auto flag_se() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-se" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-se".
      [[nodiscard]] static auto flag_se(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ch".
      /// @return The xtd::drawing::image "flag-ch".
      [[nodiscard]] static auto flag_ch() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ch" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ch".
      [[nodiscard]] static auto flag_ch(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-sy".
      /// @return The xtd::drawing::image "flag-sy".
      [[nodiscard]] static auto flag_sy() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-sy" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sy".
      [[nodiscard]] static auto flag_sy(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tw".
      /// @return The xtd::drawing::image "flag-tw".
      [[nodiscard]] static auto flag_tw() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tw".
      [[nodiscard]] static auto flag_tw(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tj".
      /// @return The xtd::drawing::image "flag-tj".
      [[nodiscard]] static auto flag_tj() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tj" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tj".
      [[nodiscard]] static auto flag_tj(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tz".
      /// @return The xtd::drawing::image "flag-tz".
      [[nodiscard]] static auto flag_tz() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tz".
      [[nodiscard]] static auto flag_tz(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-th".
      /// @return The xtd::drawing::image "flag-th".
      [[nodiscard]] static auto flag_th() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-th" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-th".
      [[nodiscard]] static auto flag_th(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tl".
      /// @return The xtd::drawing::image "flag-tl".
      [[nodiscard]] static auto flag_tl() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tl".
      [[nodiscard]] static auto flag_tl(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tg".
      /// @return The xtd::drawing::image "flag-tg".
      [[nodiscard]] static auto flag_tg() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tg".
      [[nodiscard]] static auto flag_tg(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tk".
      /// @return The xtd::drawing::image "flag-tk".
      [[nodiscard]] static auto flag_tk() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tk".
      [[nodiscard]] static auto flag_tk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-to".
      /// @return The xtd::drawing::image "flag-to".
      [[nodiscard]] static auto flag_to() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-to" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-to".
      [[nodiscard]] static auto flag_to(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tt".
      /// @return The xtd::drawing::image "flag-tt".
      [[nodiscard]] static auto flag_tt() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tt".
      [[nodiscard]] static auto flag_tt(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tn".
      /// @return The xtd::drawing::image "flag-tn".
      [[nodiscard]] static auto flag_tn() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tn".
      [[nodiscard]] static auto flag_tn(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tr".
      /// @return The xtd::drawing::image "flag-tr".
      [[nodiscard]] static auto flag_tr() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tr".
      [[nodiscard]] static auto flag_tr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tm".
      /// @return The xtd::drawing::image "flag-tm".
      [[nodiscard]] static auto flag_tm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tm".
      [[nodiscard]] static auto flag_tm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tc".
      /// @return The xtd::drawing::image "flag-tc".
      [[nodiscard]] static auto flag_tc() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tc".
      [[nodiscard]] static auto flag_tc(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-tv".
      /// @return The xtd::drawing::image "flag-tv".
      [[nodiscard]] static auto flag_tv() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-tv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tv".
      [[nodiscard]] static auto flag_tv(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ug".
      /// @return The xtd::drawing::image "flag-ug".
      [[nodiscard]] static auto flag_ug() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ug" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ug".
      [[nodiscard]] static auto flag_ug(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ua".
      /// @return The xtd::drawing::image "flag-ua".
      [[nodiscard]] static auto flag_ua() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ua" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ua".
      [[nodiscard]] static auto flag_ua(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ae".
      /// @return The xtd::drawing::image "flag-ae".
      [[nodiscard]] static auto flag_ae() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ae" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ae".
      [[nodiscard]] static auto flag_ae(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-gb".
      /// @return The xtd::drawing::image "flag-gb".
      [[nodiscard]] static auto flag_gb() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-gb" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gb".
      [[nodiscard]] static auto flag_gb(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-us".
      /// @return The xtd::drawing::image "flag-us".
      [[nodiscard]] static auto flag_us() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-us" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-us".
      [[nodiscard]] static auto flag_us(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-um".
      /// @return The xtd::drawing::image "flag-um".
      [[nodiscard]] static auto flag_um() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-um" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-um".
      [[nodiscard]] static auto flag_um(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-uy".
      /// @return The xtd::drawing::image "flag-uy".
      [[nodiscard]] static auto flag_uy() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-uy" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-uy".
      [[nodiscard]] static auto flag_uy(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-uz".
      /// @return The xtd::drawing::image "flag-uz".
      [[nodiscard]] static auto flag_uz() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-uz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-uz".
      [[nodiscard]] static auto flag_uz(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-vu".
      /// @return The xtd::drawing::image "flag-vu".
      [[nodiscard]] static auto flag_vu() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-vu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-vu".
      [[nodiscard]] static auto flag_vu(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ve".
      /// @return The xtd::drawing::image "flag-ve".
      [[nodiscard]] static auto flag_ve() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ve" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ve".
      [[nodiscard]] static auto flag_ve(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-vn".
      /// @return The xtd::drawing::image "flag-vn".
      [[nodiscard]] static auto flag_vn() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-vn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-vn".
      [[nodiscard]] static auto flag_vn(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-vg".
      /// @return The xtd::drawing::image "flag-vg".
      [[nodiscard]] static auto flag_vg() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-vg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-vg".
      [[nodiscard]] static auto flag_vg(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-vi".
      /// @return The xtd::drawing::image "flag-vi".
      [[nodiscard]] static auto flag_vi() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-vi" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-vi".
      [[nodiscard]] static auto flag_vi(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-wf".
      /// @return The xtd::drawing::image "flag-wf".
      [[nodiscard]] static auto flag_wf() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-wf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-wf".
      [[nodiscard]] static auto flag_wf(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-eh".
      /// @return The xtd::drawing::image "flag-eh".
      [[nodiscard]] static auto flag_eh() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-eh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-eh".
      [[nodiscard]] static auto flag_eh(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-ye".
      /// @return The xtd::drawing::image "flag-ye".
      [[nodiscard]] static auto flag_ye() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-ye" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ye".
      [[nodiscard]] static auto flag_ye(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-zm".
      /// @return The xtd::drawing::image "flag-zm".
      [[nodiscard]] static auto flag_zm() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-zm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-zm".
      [[nodiscard]] static auto flag_zm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the international system image "flag-zw".
      /// @return The xtd::drawing::image "flag-zw".
      [[nodiscard]] static auto flag_zw() noexcept -> xtd::drawing::image;
      /// @brief Gets the international system image "flag-zw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-zw".
      [[nodiscard]] static auto flag_zw(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of images.
      /// @return The array of images.
      [[nodiscard]] static auto get_images() noexcept -> const xtd::array<xtd::drawing::image>&;
      /// @brief Gets an array of images with specified size.
      /// @param size The images size in pixels.
      /// @return The array of images.
      [[nodiscard]] static auto get_images(const xtd::drawing::size& size) noexcept -> xtd::array<xtd::drawing::image>;
      
      /// @brief Gets an array of image names.
      /// @return The array of image names.
      [[nodiscard]] static auto get_image_names() noexcept -> const xtd::array<xtd::string>&;
      /// @}
    };
  }
}
