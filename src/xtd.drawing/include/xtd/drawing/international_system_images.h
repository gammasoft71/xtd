/// @file
/// @brief Contains xtd::drawing::international_system_images factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::international_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ international_system_images final : private system_images_base
    /// @endcode
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::international_system_images
    /// @par Header
    /// @code #include <xtd/drawing/international_system_images> @endcode
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ international_system_images final : private system_images_base {
    public:
      /// @name Static properties

      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;

      /// @brief Gets the international system image "flag-af".
      /// @return The xtd::drawing::image "flag-af".
      static xtd::drawing::image flag_af() noexcept;
      /// @brief Gets the international system image "flag-af" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-af".
      static xtd::drawing::image flag_af(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ax".
      /// @return The xtd::drawing::image "flag-ax".
      static xtd::drawing::image flag_ax() noexcept;
      /// @brief Gets the international system image "flag-ax" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ax".
      static xtd::drawing::image flag_ax(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-al".
      /// @return The xtd::drawing::image "flag-al".
      static xtd::drawing::image flag_al() noexcept;
      /// @brief Gets the international system image "flag-al" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-al".
      static xtd::drawing::image flag_al(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-dz".
      /// @return The xtd::drawing::image "flag-dz".
      static xtd::drawing::image flag_dz() noexcept;
      /// @brief Gets the international system image "flag-dz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-dz".
      static xtd::drawing::image flag_dz(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-as".
      /// @return The xtd::drawing::image "flag-as".
      static xtd::drawing::image flag_as() noexcept;
      /// @brief Gets the international system image "flag-as" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-as".
      static xtd::drawing::image flag_as(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ad".
      /// @return The xtd::drawing::image "flag-ad".
      static xtd::drawing::image flag_ad() noexcept;
      /// @brief Gets the international system image "flag-ad" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ad".
      static xtd::drawing::image flag_ad(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ao".
      /// @return The xtd::drawing::image "flag-ao".
      static xtd::drawing::image flag_ao() noexcept;
      /// @brief Gets the international system image "flag-ao" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ao".
      static xtd::drawing::image flag_ao(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ai".
      /// @return The xtd::drawing::image "flag-ai".
      static xtd::drawing::image flag_ai() noexcept;
      /// @brief Gets the international system image "flag-ai" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ai".
      static xtd::drawing::image flag_ai(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-aq".
      /// @return The xtd::drawing::image "flag-aq".
      static xtd::drawing::image flag_aq() noexcept;
      /// @brief Gets the international system image "flag-aq" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-aq".
      static xtd::drawing::image flag_aq(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ag".
      /// @return The xtd::drawing::image "flag-ag".
      static xtd::drawing::image flag_ag() noexcept;
      /// @brief Gets the international system image "flag-ag" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ag".
      static xtd::drawing::image flag_ag(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ar".
      /// @return The xtd::drawing::image "flag-ar".
      static xtd::drawing::image flag_ar() noexcept;
      /// @brief Gets the international system image "flag-ar" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ar".
      static xtd::drawing::image flag_ar(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-am".
      /// @return The xtd::drawing::image "flag-am".
      static xtd::drawing::image flag_am() noexcept;
      /// @brief Gets the international system image "flag-am" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-am".
      static xtd::drawing::image flag_am(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-aw".
      /// @return The xtd::drawing::image "flag-aw".
      static xtd::drawing::image flag_aw() noexcept;
      /// @brief Gets the international system image "flag-aw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-aw".
      static xtd::drawing::image flag_aw(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-au".
      /// @return The xtd::drawing::image "flag-au".
      static xtd::drawing::image flag_au() noexcept;
      /// @brief Gets the international system image "flag-au" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-au".
      static xtd::drawing::image flag_au(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-at".
      /// @return The xtd::drawing::image "flag-at".
      static xtd::drawing::image flag_at() noexcept;
      /// @brief Gets the international system image "flag-at" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-at".
      static xtd::drawing::image flag_at(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-az".
      /// @return The xtd::drawing::image "flag-az".
      static xtd::drawing::image flag_az() noexcept;
      /// @brief Gets the international system image "flag-az" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-az".
      static xtd::drawing::image flag_az(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bs".
      /// @return The xtd::drawing::image "flag-bs".
      static xtd::drawing::image flag_bs() noexcept;
      /// @brief Gets the international system image "flag-bs" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bs".
      static xtd::drawing::image flag_bs(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bh".
      /// @return The xtd::drawing::image "flag-bh".
      static xtd::drawing::image flag_bh() noexcept;
      /// @brief Gets the international system image "flag-bh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bh".
      static xtd::drawing::image flag_bh(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bd".
      /// @return The xtd::drawing::image "flag-bd".
      static xtd::drawing::image flag_bd() noexcept;
      /// @brief Gets the international system image "flag-bd" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bd".
      static xtd::drawing::image flag_bd(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bb".
      /// @return The xtd::drawing::image "flag-bb".
      static xtd::drawing::image flag_bb() noexcept;
      /// @brief Gets the international system image "flag-bb" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bb".
      static xtd::drawing::image flag_bb(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-by".
      /// @return The xtd::drawing::image "flag-by".
      static xtd::drawing::image flag_by() noexcept;
      /// @brief Gets the international system image "flag-by" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-by".
      static xtd::drawing::image flag_by(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-be".
      /// @return The xtd::drawing::image "flag-be".
      static xtd::drawing::image flag_be() noexcept;
      /// @brief Gets the international system image "flag-be" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-be".
      static xtd::drawing::image flag_be(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bz".
      /// @return The xtd::drawing::image "flag-bz".
      static xtd::drawing::image flag_bz() noexcept;
      /// @brief Gets the international system image "flag-bz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bz".
      static xtd::drawing::image flag_bz(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bj".
      /// @return The xtd::drawing::image "flag-bj".
      static xtd::drawing::image flag_bj() noexcept;
      /// @brief Gets the international system image "flag-bj" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bj".
      static xtd::drawing::image flag_bj(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bm".
      /// @return The xtd::drawing::image "flag-bm".
      static xtd::drawing::image flag_bm() noexcept;
      /// @brief Gets the international system image "flag-bm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bm".
      static xtd::drawing::image flag_bm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bt".
      /// @return The xtd::drawing::image "flag-bt".
      static xtd::drawing::image flag_bt() noexcept;
      /// @brief Gets the international system image "flag-bt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bt".
      static xtd::drawing::image flag_bt(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bo".
      /// @return The xtd::drawing::image "flag-bo".
      static xtd::drawing::image flag_bo() noexcept;
      /// @brief Gets the international system image "flag-bo" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bo".
      static xtd::drawing::image flag_bo(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bq".
      /// @return The xtd::drawing::image "flag-bq".
      static xtd::drawing::image flag_bq() noexcept;
      /// @brief Gets the international system image "flag-bq" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bq".
      static xtd::drawing::image flag_bq(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ba".
      /// @return The xtd::drawing::image "flag-ba".
      static xtd::drawing::image flag_ba() noexcept;
      /// @brief Gets the international system image "flag-ba" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ba".
      static xtd::drawing::image flag_ba(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bw".
      /// @return The xtd::drawing::image "flag-bw".
      static xtd::drawing::image flag_bw() noexcept;
      /// @brief Gets the international system image "flag-bw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bw".
      static xtd::drawing::image flag_bw(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bv".
      /// @return The xtd::drawing::image "flag-bv".
      static xtd::drawing::image flag_bv() noexcept;
      /// @brief Gets the international system image "flag-bv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bv".
      static xtd::drawing::image flag_bv(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-br".
      /// @return The xtd::drawing::image "flag-br".
      static xtd::drawing::image flag_br() noexcept;
      /// @brief Gets the international system image "flag-br" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-br".
      static xtd::drawing::image flag_br(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-io".
      /// @return The xtd::drawing::image "flag-io".
      static xtd::drawing::image flag_io() noexcept;
      /// @brief Gets the international system image "flag-io" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-io".
      static xtd::drawing::image flag_io(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bn".
      /// @return The xtd::drawing::image "flag-bn".
      static xtd::drawing::image flag_bn() noexcept;
      /// @brief Gets the international system image "flag-bn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bn".
      static xtd::drawing::image flag_bn(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bg".
      /// @return The xtd::drawing::image "flag-bg".
      static xtd::drawing::image flag_bg() noexcept;
      /// @brief Gets the international system image "flag-bg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bg".
      static xtd::drawing::image flag_bg(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bf".
      /// @return The xtd::drawing::image "flag-bf".
      static xtd::drawing::image flag_bf() noexcept;
      /// @brief Gets the international system image "flag-bf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bf".
      static xtd::drawing::image flag_bf(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bi".
      /// @return The xtd::drawing::image "flag-bi".
      static xtd::drawing::image flag_bi() noexcept;
      /// @brief Gets the international system image "flag-bi" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bi".
      static xtd::drawing::image flag_bi(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cv".
      /// @return The xtd::drawing::image "flag-cv".
      static xtd::drawing::image flag_cv() noexcept;
      /// @brief Gets the international system image "flag-cv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cv".
      static xtd::drawing::image flag_cv(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-kh".
      /// @return The xtd::drawing::image "flag-kh".
      static xtd::drawing::image flag_kh() noexcept;
      /// @brief Gets the international system image "flag-kh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kh".
      static xtd::drawing::image flag_kh(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cm".
      /// @return The xtd::drawing::image "flag-cm".
      static xtd::drawing::image flag_cm() noexcept;
      /// @brief Gets the international system image "flag-cm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cm".
      static xtd::drawing::image flag_cm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ca".
      /// @return The xtd::drawing::image "flag-ca".
      static xtd::drawing::image flag_ca() noexcept;
      /// @brief Gets the international system image "flag-ca" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ca".
      static xtd::drawing::image flag_ca(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ky".
      /// @return The xtd::drawing::image "flag-ky".
      static xtd::drawing::image flag_ky() noexcept;
      /// @brief Gets the international system image "flag-ky" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ky".
      static xtd::drawing::image flag_ky(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cf".
      /// @return The xtd::drawing::image "flag-cf".
      static xtd::drawing::image flag_cf() noexcept;
      /// @brief Gets the international system image "flag-cf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cf".
      static xtd::drawing::image flag_cf(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-td".
      /// @return The xtd::drawing::image "flag-td".
      static xtd::drawing::image flag_td() noexcept;
      /// @brief Gets the international system image "flag-td" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-td".
      static xtd::drawing::image flag_td(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cl".
      /// @return The xtd::drawing::image "flag-cl".
      static xtd::drawing::image flag_cl() noexcept;
      /// @brief Gets the international system image "flag-cl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cl".
      static xtd::drawing::image flag_cl(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cn".
      /// @return The xtd::drawing::image "flag-cn".
      static xtd::drawing::image flag_cn() noexcept;
      /// @brief Gets the international system image "flag-cn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cn".
      static xtd::drawing::image flag_cn(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cx".
      /// @return The xtd::drawing::image "flag-cx".
      static xtd::drawing::image flag_cx() noexcept;
      /// @brief Gets the international system image "flag-cx" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cx".
      static xtd::drawing::image flag_cx(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cc".
      /// @return The xtd::drawing::image "flag-cc".
      static xtd::drawing::image flag_cc() noexcept;
      /// @brief Gets the international system image "flag-cc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cc".
      static xtd::drawing::image flag_cc(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-co".
      /// @return The xtd::drawing::image "flag-co".
      static xtd::drawing::image flag_co() noexcept;
      /// @brief Gets the international system image "flag-co" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-co".
      static xtd::drawing::image flag_co(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-km".
      /// @return The xtd::drawing::image "flag-km".
      static xtd::drawing::image flag_km() noexcept;
      /// @brief Gets the international system image "flag-km" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-km".
      static xtd::drawing::image flag_km(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cg".
      /// @return The xtd::drawing::image "flag-cg".
      static xtd::drawing::image flag_cg() noexcept;
      /// @brief Gets the international system image "flag-cg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cg".
      static xtd::drawing::image flag_cg(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cd".
      /// @return The xtd::drawing::image "flag-cd".
      static xtd::drawing::image flag_cd() noexcept;
      /// @brief Gets the international system image "flag-cd" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cd".
      static xtd::drawing::image flag_cd(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ck".
      /// @return The xtd::drawing::image "flag-ck".
      static xtd::drawing::image flag_ck() noexcept;
      /// @brief Gets the international system image "flag-ck" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ck".
      static xtd::drawing::image flag_ck(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cr".
      /// @return The xtd::drawing::image "flag-cr".
      static xtd::drawing::image flag_cr() noexcept;
      /// @brief Gets the international system image "flag-cr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cr".
      static xtd::drawing::image flag_cr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ci".
      /// @return The xtd::drawing::image "flag-ci".
      static xtd::drawing::image flag_ci() noexcept;
      /// @brief Gets the international system image "flag-ci" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ci".
      static xtd::drawing::image flag_ci(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-hr".
      /// @return The xtd::drawing::image "flag-hr".
      static xtd::drawing::image flag_hr() noexcept;
      /// @brief Gets the international system image "flag-hr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-hr".
      static xtd::drawing::image flag_hr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cu".
      /// @return The xtd::drawing::image "flag-cu".
      static xtd::drawing::image flag_cu() noexcept;
      /// @brief Gets the international system image "flag-cu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cu".
      static xtd::drawing::image flag_cu(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cw".
      /// @return The xtd::drawing::image "flag-cw".
      static xtd::drawing::image flag_cw() noexcept;
      /// @brief Gets the international system image "flag-cw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cw".
      static xtd::drawing::image flag_cw(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cy".
      /// @return The xtd::drawing::image "flag-cy".
      static xtd::drawing::image flag_cy() noexcept;
      /// @brief Gets the international system image "flag-cy" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cy".
      static xtd::drawing::image flag_cy(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-cz".
      /// @return The xtd::drawing::image "flag-cz".
      static xtd::drawing::image flag_cz() noexcept;
      /// @brief Gets the international system image "flag-cz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-cz".
      static xtd::drawing::image flag_cz(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-dk".
      /// @return The xtd::drawing::image "flag-dk".
      static xtd::drawing::image flag_dk() noexcept;
      /// @brief Gets the international system image "flag-dk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-dk".
      static xtd::drawing::image flag_dk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-dj".
      /// @return The xtd::drawing::image "flag-dj".
      static xtd::drawing::image flag_dj() noexcept;
      /// @brief Gets the international system image "flag-dj" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-dj".
      static xtd::drawing::image flag_dj(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-dm".
      /// @return The xtd::drawing::image "flag-dm".
      static xtd::drawing::image flag_dm() noexcept;
      /// @brief Gets the international system image "flag-dm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-dm".
      static xtd::drawing::image flag_dm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-do".
      /// @return The xtd::drawing::image "flag-do".
      static xtd::drawing::image flag_do() noexcept;
      /// @brief Gets the international system image "flag-do" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-do".
      static xtd::drawing::image flag_do(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ec".
      /// @return The xtd::drawing::image "flag-ec".
      static xtd::drawing::image flag_ec() noexcept;
      /// @brief Gets the international system image "flag-ec" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ec".
      static xtd::drawing::image flag_ec(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-eg".
      /// @return The xtd::drawing::image "flag-eg".
      static xtd::drawing::image flag_eg() noexcept;
      /// @brief Gets the international system image "flag-eg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-eg".
      static xtd::drawing::image flag_eg(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sv".
      /// @return The xtd::drawing::image "flag-sv".
      static xtd::drawing::image flag_sv() noexcept;
      /// @brief Gets the international system image "flag-sv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sv".
      static xtd::drawing::image flag_sv(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gq".
      /// @return The xtd::drawing::image "flag-gq".
      static xtd::drawing::image flag_gq() noexcept;
      /// @brief Gets the international system image "flag-gq" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gq".
      static xtd::drawing::image flag_gq(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-er".
      /// @return The xtd::drawing::image "flag-er".
      static xtd::drawing::image flag_er() noexcept;
      /// @brief Gets the international system image "flag-er" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-er".
      static xtd::drawing::image flag_er(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ee".
      /// @return The xtd::drawing::image "flag-ee".
      static xtd::drawing::image flag_ee() noexcept;
      /// @brief Gets the international system image "flag-ee" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ee".
      static xtd::drawing::image flag_ee(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sz".
      /// @return The xtd::drawing::image "flag-sz".
      static xtd::drawing::image flag_sz() noexcept;
      /// @brief Gets the international system image "flag-sz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sz".
      static xtd::drawing::image flag_sz(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-et".
      /// @return The xtd::drawing::image "flag-et".
      static xtd::drawing::image flag_et() noexcept;
      /// @brief Gets the international system image "flag-et" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-et".
      static xtd::drawing::image flag_et(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-fk".
      /// @return The xtd::drawing::image "flag-fk".
      static xtd::drawing::image flag_fk() noexcept;
      /// @brief Gets the international system image "flag-fk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fk".
      static xtd::drawing::image flag_fk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-fo".
      /// @return The xtd::drawing::image "flag-fo".
      static xtd::drawing::image flag_fo() noexcept;
      /// @brief Gets the international system image "flag-fo" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fo".
      static xtd::drawing::image flag_fo(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-fj".
      /// @return The xtd::drawing::image "flag-fj".
      static xtd::drawing::image flag_fj() noexcept;
      /// @brief Gets the international system image "flag-fj" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fj".
      static xtd::drawing::image flag_fj(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-fi".
      /// @return The xtd::drawing::image "flag-fi".
      static xtd::drawing::image flag_fi() noexcept;
      /// @brief Gets the international system image "flag-fi" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fi".
      static xtd::drawing::image flag_fi(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-fr".
      /// @return The xtd::drawing::image "flag-fr".
      static xtd::drawing::image flag_fr() noexcept;
      /// @brief Gets the international system image "flag-fr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fr".
      static xtd::drawing::image flag_fr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gf".
      /// @return The xtd::drawing::image "flag-gf".
      static xtd::drawing::image flag_gf() noexcept;
      /// @brief Gets the international system image "flag-gf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gf".
      static xtd::drawing::image flag_gf(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-pf".
      /// @return The xtd::drawing::image "flag-pf".
      static xtd::drawing::image flag_pf() noexcept;
      /// @brief Gets the international system image "flag-pf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pf".
      static xtd::drawing::image flag_pf(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tf".
      /// @return The xtd::drawing::image "flag-tf".
      static xtd::drawing::image flag_tf() noexcept;
      /// @brief Gets the international system image "flag-tf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tf".
      static xtd::drawing::image flag_tf(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ga".
      /// @return The xtd::drawing::image "flag-ga".
      static xtd::drawing::image flag_ga() noexcept;
      /// @brief Gets the international system image "flag-ga" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ga".
      static xtd::drawing::image flag_ga(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gm".
      /// @return The xtd::drawing::image "flag-gm".
      static xtd::drawing::image flag_gm() noexcept;
      /// @brief Gets the international system image "flag-gm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gm".
      static xtd::drawing::image flag_gm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ge".
      /// @return The xtd::drawing::image "flag-ge".
      static xtd::drawing::image flag_ge() noexcept;
      /// @brief Gets the international system image "flag-ge" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ge".
      static xtd::drawing::image flag_ge(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-de".
      /// @return The xtd::drawing::image "flag-de".
      static xtd::drawing::image flag_de() noexcept;
      /// @brief Gets the international system image "flag-de" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-de".
      static xtd::drawing::image flag_de(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gh".
      /// @return The xtd::drawing::image "flag-gh".
      static xtd::drawing::image flag_gh() noexcept;
      /// @brief Gets the international system image "flag-gh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gh".
      static xtd::drawing::image flag_gh(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gi".
      /// @return The xtd::drawing::image "flag-gi".
      static xtd::drawing::image flag_gi() noexcept;
      /// @brief Gets the international system image "flag-gi" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gi".
      static xtd::drawing::image flag_gi(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gr".
      /// @return The xtd::drawing::image "flag-gr".
      static xtd::drawing::image flag_gr() noexcept;
      /// @brief Gets the international system image "flag-gr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gr".
      static xtd::drawing::image flag_gr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gl".
      /// @return The xtd::drawing::image "flag-gl".
      static xtd::drawing::image flag_gl() noexcept;
      /// @brief Gets the international system image "flag-gl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gl".
      static xtd::drawing::image flag_gl(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gd".
      /// @return The xtd::drawing::image "flag-gd".
      static xtd::drawing::image flag_gd() noexcept;
      /// @brief Gets the international system image "flag-gd" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gd".
      static xtd::drawing::image flag_gd(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gp".
      /// @return The xtd::drawing::image "flag-gp".
      static xtd::drawing::image flag_gp() noexcept;
      /// @brief Gets the international system image "flag-gp" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gp".
      static xtd::drawing::image flag_gp(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gu".
      /// @return The xtd::drawing::image "flag-gu".
      static xtd::drawing::image flag_gu() noexcept;
      /// @brief Gets the international system image "flag-gu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gu".
      static xtd::drawing::image flag_gu(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gt".
      /// @return The xtd::drawing::image "flag-gt".
      static xtd::drawing::image flag_gt() noexcept;
      /// @brief Gets the international system image "flag-gt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gt".
      static xtd::drawing::image flag_gt(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gg".
      /// @return The xtd::drawing::image "flag-gg".
      static xtd::drawing::image flag_gg() noexcept;
      /// @brief Gets the international system image "flag-gg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gg".
      static xtd::drawing::image flag_gg(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gn".
      /// @return The xtd::drawing::image "flag-gn".
      static xtd::drawing::image flag_gn() noexcept;
      /// @brief Gets the international system image "flag-gn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gn".
      static xtd::drawing::image flag_gn(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gw".
      /// @return The xtd::drawing::image "flag-gw".
      static xtd::drawing::image flag_gw() noexcept;
      /// @brief Gets the international system image "flag-gw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gw".
      static xtd::drawing::image flag_gw(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gy".
      /// @return The xtd::drawing::image "flag-gy".
      static xtd::drawing::image flag_gy() noexcept;
      /// @brief Gets the international system image "flag-gy" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gy".
      static xtd::drawing::image flag_gy(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ht".
      /// @return The xtd::drawing::image "flag-ht".
      static xtd::drawing::image flag_ht() noexcept;
      /// @brief Gets the international system image "flag-ht" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ht".
      static xtd::drawing::image flag_ht(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-hm".
      /// @return The xtd::drawing::image "flag-hm".
      static xtd::drawing::image flag_hm() noexcept;
      /// @brief Gets the international system image "flag-hm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-hm".
      static xtd::drawing::image flag_hm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-va".
      /// @return The xtd::drawing::image "flag-va".
      static xtd::drawing::image flag_va() noexcept;
      /// @brief Gets the international system image "flag-va" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-va".
      static xtd::drawing::image flag_va(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-hn".
      /// @return The xtd::drawing::image "flag-hn".
      static xtd::drawing::image flag_hn() noexcept;
      /// @brief Gets the international system image "flag-hn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-hn".
      static xtd::drawing::image flag_hn(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-hk".
      /// @return The xtd::drawing::image "flag-hk".
      static xtd::drawing::image flag_hk() noexcept;
      /// @brief Gets the international system image "flag-hk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-hk".
      static xtd::drawing::image flag_hk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-hu".
      /// @return The xtd::drawing::image "flag-hu".
      static xtd::drawing::image flag_hu() noexcept;
      /// @brief Gets the international system image "flag-hu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-hu".
      static xtd::drawing::image flag_hu(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-is".
      /// @return The xtd::drawing::image "flag-is".
      static xtd::drawing::image flag_is() noexcept;
      /// @brief Gets the international system image "flag-is" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-is".
      static xtd::drawing::image flag_is(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-in".
      /// @return The xtd::drawing::image "flag-in".
      static xtd::drawing::image flag_in() noexcept;
      /// @brief Gets the international system image "flag-in" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-in".
      static xtd::drawing::image flag_in(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-id".
      /// @return The xtd::drawing::image "flag-id".
      static xtd::drawing::image flag_id() noexcept;
      /// @brief Gets the international system image "flag-id" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-id".
      static xtd::drawing::image flag_id(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ir".
      /// @return The xtd::drawing::image "flag-ir".
      static xtd::drawing::image flag_ir() noexcept;
      /// @brief Gets the international system image "flag-ir" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ir".
      static xtd::drawing::image flag_ir(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-iq".
      /// @return The xtd::drawing::image "flag-iq".
      static xtd::drawing::image flag_iq() noexcept;
      /// @brief Gets the international system image "flag-iq" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-iq".
      static xtd::drawing::image flag_iq(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ie".
      /// @return The xtd::drawing::image "flag-ie".
      static xtd::drawing::image flag_ie() noexcept;
      /// @brief Gets the international system image "flag-ie" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ie".
      static xtd::drawing::image flag_ie(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-im".
      /// @return The xtd::drawing::image "flag-im".
      static xtd::drawing::image flag_im() noexcept;
      /// @brief Gets the international system image "flag-im" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-im".
      static xtd::drawing::image flag_im(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-il".
      /// @return The xtd::drawing::image "flag-il".
      static xtd::drawing::image flag_il() noexcept;
      /// @brief Gets the international system image "flag-il" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-il".
      static xtd::drawing::image flag_il(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-it".
      /// @return The xtd::drawing::image "flag-it".
      static xtd::drawing::image flag_it() noexcept;
      /// @brief Gets the international system image "flag-it" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-it".
      static xtd::drawing::image flag_it(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-jm".
      /// @return The xtd::drawing::image "flag-jm".
      static xtd::drawing::image flag_jm() noexcept;
      /// @brief Gets the international system image "flag-jm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-jm".
      static xtd::drawing::image flag_jm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-jp".
      /// @return The xtd::drawing::image "flag-jp".
      static xtd::drawing::image flag_jp() noexcept;
      /// @brief Gets the international system image "flag-jp" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-jp".
      static xtd::drawing::image flag_jp(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-je".
      /// @return The xtd::drawing::image "flag-je".
      static xtd::drawing::image flag_je() noexcept;
      /// @brief Gets the international system image "flag-je" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-je".
      static xtd::drawing::image flag_je(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-jo".
      /// @return The xtd::drawing::image "flag-jo".
      static xtd::drawing::image flag_jo() noexcept;
      /// @brief Gets the international system image "flag-jo" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-jo".
      static xtd::drawing::image flag_jo(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-kz".
      /// @return The xtd::drawing::image "flag-kz".
      static xtd::drawing::image flag_kz() noexcept;
      /// @brief Gets the international system image "flag-kz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kz".
      static xtd::drawing::image flag_kz(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ke".
      /// @return The xtd::drawing::image "flag-ke".
      static xtd::drawing::image flag_ke() noexcept;
      /// @brief Gets the international system image "flag-ke" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ke".
      static xtd::drawing::image flag_ke(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ki".
      /// @return The xtd::drawing::image "flag-ki".
      static xtd::drawing::image flag_ki() noexcept;
      /// @brief Gets the international system image "flag-ki" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ki".
      static xtd::drawing::image flag_ki(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-kp".
      /// @return The xtd::drawing::image "flag-kp".
      static xtd::drawing::image flag_kp() noexcept;
      /// @brief Gets the international system image "flag-kp" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kp".
      static xtd::drawing::image flag_kp(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-kr".
      /// @return The xtd::drawing::image "flag-kr".
      static xtd::drawing::image flag_kr() noexcept;
      /// @brief Gets the international system image "flag-kr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kr".
      static xtd::drawing::image flag_kr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-kw".
      /// @return The xtd::drawing::image "flag-kw".
      static xtd::drawing::image flag_kw() noexcept;
      /// @brief Gets the international system image "flag-kw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kw".
      static xtd::drawing::image flag_kw(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-kg".
      /// @return The xtd::drawing::image "flag-kg".
      static xtd::drawing::image flag_kg() noexcept;
      /// @brief Gets the international system image "flag-kg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kg".
      static xtd::drawing::image flag_kg(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-la".
      /// @return The xtd::drawing::image "flag-la".
      static xtd::drawing::image flag_la() noexcept;
      /// @brief Gets the international system image "flag-la" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-la".
      static xtd::drawing::image flag_la(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-lv".
      /// @return The xtd::drawing::image "flag-lv".
      static xtd::drawing::image flag_lv() noexcept;
      /// @brief Gets the international system image "flag-lv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lv".
      static xtd::drawing::image flag_lv(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-lb".
      /// @return The xtd::drawing::image "flag-lb".
      static xtd::drawing::image flag_lb() noexcept;
      /// @brief Gets the international system image "flag-lb" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lb".
      static xtd::drawing::image flag_lb(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ls".
      /// @return The xtd::drawing::image "flag-ls".
      static xtd::drawing::image flag_ls() noexcept;
      /// @brief Gets the international system image "flag-ls" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ls".
      static xtd::drawing::image flag_ls(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-lr".
      /// @return The xtd::drawing::image "flag-lr".
      static xtd::drawing::image flag_lr() noexcept;
      /// @brief Gets the international system image "flag-lr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lr".
      static xtd::drawing::image flag_lr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ly".
      /// @return The xtd::drawing::image "flag-ly".
      static xtd::drawing::image flag_ly() noexcept;
      /// @brief Gets the international system image "flag-ly" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ly".
      static xtd::drawing::image flag_ly(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-li".
      /// @return The xtd::drawing::image "flag-li".
      static xtd::drawing::image flag_li() noexcept;
      /// @brief Gets the international system image "flag-li" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-li".
      static xtd::drawing::image flag_li(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-lt".
      /// @return The xtd::drawing::image "flag-lt".
      static xtd::drawing::image flag_lt() noexcept;
      /// @brief Gets the international system image "flag-lt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lt".
      static xtd::drawing::image flag_lt(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-lu".
      /// @return The xtd::drawing::image "flag-lu".
      static xtd::drawing::image flag_lu() noexcept;
      /// @brief Gets the international system image "flag-lu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lu".
      static xtd::drawing::image flag_lu(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mo".
      /// @return The xtd::drawing::image "flag-mo".
      static xtd::drawing::image flag_mo() noexcept;
      /// @brief Gets the international system image "flag-mo" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mo".
      static xtd::drawing::image flag_mo(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mg".
      /// @return The xtd::drawing::image "flag-mg".
      static xtd::drawing::image flag_mg() noexcept;
      /// @brief Gets the international system image "flag-mg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mg".
      static xtd::drawing::image flag_mg(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mw".
      /// @return The xtd::drawing::image "flag-mw".
      static xtd::drawing::image flag_mw() noexcept;
      /// @brief Gets the international system image "flag-mw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mw".
      static xtd::drawing::image flag_mw(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-my".
      /// @return The xtd::drawing::image "flag-my".
      static xtd::drawing::image flag_my() noexcept;
      /// @brief Gets the international system image "flag-my" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-my".
      static xtd::drawing::image flag_my(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mv".
      /// @return The xtd::drawing::image "flag-mv".
      static xtd::drawing::image flag_mv() noexcept;
      /// @brief Gets the international system image "flag-mv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mv".
      static xtd::drawing::image flag_mv(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ml".
      /// @return The xtd::drawing::image "flag-ml".
      static xtd::drawing::image flag_ml() noexcept;
      /// @brief Gets the international system image "flag-ml" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ml".
      static xtd::drawing::image flag_ml(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mt".
      /// @return The xtd::drawing::image "flag-mt".
      static xtd::drawing::image flag_mt() noexcept;
      /// @brief Gets the international system image "flag-mt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mt".
      static xtd::drawing::image flag_mt(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mh".
      /// @return The xtd::drawing::image "flag-mh".
      static xtd::drawing::image flag_mh() noexcept;
      /// @brief Gets the international system image "flag-mh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mh".
      static xtd::drawing::image flag_mh(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mq".
      /// @return The xtd::drawing::image "flag-mq".
      static xtd::drawing::image flag_mq() noexcept;
      /// @brief Gets the international system image "flag-mq" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mq".
      static xtd::drawing::image flag_mq(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mr".
      /// @return The xtd::drawing::image "flag-mr".
      static xtd::drawing::image flag_mr() noexcept;
      /// @brief Gets the international system image "flag-mr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mr".
      static xtd::drawing::image flag_mr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mu".
      /// @return The xtd::drawing::image "flag-mu".
      static xtd::drawing::image flag_mu() noexcept;
      /// @brief Gets the international system image "flag-mu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mu".
      static xtd::drawing::image flag_mu(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-yt".
      /// @return The xtd::drawing::image "flag-yt".
      static xtd::drawing::image flag_yt() noexcept;
      /// @brief Gets the international system image "flag-yt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-yt".
      static xtd::drawing::image flag_yt(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mx".
      /// @return The xtd::drawing::image "flag-mx".
      static xtd::drawing::image flag_mx() noexcept;
      /// @brief Gets the international system image "flag-mx" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mx".
      static xtd::drawing::image flag_mx(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-fm".
      /// @return The xtd::drawing::image "flag-fm".
      static xtd::drawing::image flag_fm() noexcept;
      /// @brief Gets the international system image "flag-fm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-fm".
      static xtd::drawing::image flag_fm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-md".
      /// @return The xtd::drawing::image "flag-md".
      static xtd::drawing::image flag_md() noexcept;
      /// @brief Gets the international system image "flag-md" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-md".
      static xtd::drawing::image flag_md(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mc".
      /// @return The xtd::drawing::image "flag-mc".
      static xtd::drawing::image flag_mc() noexcept;
      /// @brief Gets the international system image "flag-mc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mc".
      static xtd::drawing::image flag_mc(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mn".
      /// @return The xtd::drawing::image "flag-mn".
      static xtd::drawing::image flag_mn() noexcept;
      /// @brief Gets the international system image "flag-mn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mn".
      static xtd::drawing::image flag_mn(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-me".
      /// @return The xtd::drawing::image "flag-me".
      static xtd::drawing::image flag_me() noexcept;
      /// @brief Gets the international system image "flag-me" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-me".
      static xtd::drawing::image flag_me(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ms".
      /// @return The xtd::drawing::image "flag-ms".
      static xtd::drawing::image flag_ms() noexcept;
      /// @brief Gets the international system image "flag-ms" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ms".
      static xtd::drawing::image flag_ms(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ma".
      /// @return The xtd::drawing::image "flag-ma".
      static xtd::drawing::image flag_ma() noexcept;
      /// @brief Gets the international system image "flag-ma" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ma".
      static xtd::drawing::image flag_ma(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mz".
      /// @return The xtd::drawing::image "flag-mz".
      static xtd::drawing::image flag_mz() noexcept;
      /// @brief Gets the international system image "flag-mz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mz".
      static xtd::drawing::image flag_mz(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mm".
      /// @return The xtd::drawing::image "flag-mm".
      static xtd::drawing::image flag_mm() noexcept;
      /// @brief Gets the international system image "flag-mm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mm".
      static xtd::drawing::image flag_mm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-na".
      /// @return The xtd::drawing::image "flag-na".
      static xtd::drawing::image flag_na() noexcept;
      /// @brief Gets the international system image "flag-na" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-na".
      static xtd::drawing::image flag_na(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-nr".
      /// @return The xtd::drawing::image "flag-nr".
      static xtd::drawing::image flag_nr() noexcept;
      /// @brief Gets the international system image "flag-nr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nr".
      static xtd::drawing::image flag_nr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-np".
      /// @return The xtd::drawing::image "flag-np".
      static xtd::drawing::image flag_np() noexcept;
      /// @brief Gets the international system image "flag-np" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-np".
      static xtd::drawing::image flag_np(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-nl".
      /// @return The xtd::drawing::image "flag-nl".
      static xtd::drawing::image flag_nl() noexcept;
      /// @brief Gets the international system image "flag-nl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nl".
      static xtd::drawing::image flag_nl(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-nc".
      /// @return The xtd::drawing::image "flag-nc".
      static xtd::drawing::image flag_nc() noexcept;
      /// @brief Gets the international system image "flag-nc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nc".
      static xtd::drawing::image flag_nc(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-nz".
      /// @return The xtd::drawing::image "flag-nz".
      static xtd::drawing::image flag_nz() noexcept;
      /// @brief Gets the international system image "flag-nz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nz".
      static xtd::drawing::image flag_nz(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ni".
      /// @return The xtd::drawing::image "flag-ni".
      static xtd::drawing::image flag_ni() noexcept;
      /// @brief Gets the international system image "flag-ni" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ni".
      static xtd::drawing::image flag_ni(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ne".
      /// @return The xtd::drawing::image "flag-ne".
      static xtd::drawing::image flag_ne() noexcept;
      /// @brief Gets the international system image "flag-ne" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ne".
      static xtd::drawing::image flag_ne(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ng".
      /// @return The xtd::drawing::image "flag-ng".
      static xtd::drawing::image flag_ng() noexcept;
      /// @brief Gets the international system image "flag-ng" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ng".
      static xtd::drawing::image flag_ng(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-nu".
      /// @return The xtd::drawing::image "flag-nu".
      static xtd::drawing::image flag_nu() noexcept;
      /// @brief Gets the international system image "flag-nu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nu".
      static xtd::drawing::image flag_nu(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-nf".
      /// @return The xtd::drawing::image "flag-nf".
      static xtd::drawing::image flag_nf() noexcept;
      /// @brief Gets the international system image "flag-nf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-nf".
      static xtd::drawing::image flag_nf(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mk".
      /// @return The xtd::drawing::image "flag-mk".
      static xtd::drawing::image flag_mk() noexcept;
      /// @brief Gets the international system image "flag-mk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mk".
      static xtd::drawing::image flag_mk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mp".
      /// @return The xtd::drawing::image "flag-mp".
      static xtd::drawing::image flag_mp() noexcept;
      /// @brief Gets the international system image "flag-mp" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mp".
      static xtd::drawing::image flag_mp(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-no".
      /// @return The xtd::drawing::image "flag-no".
      static xtd::drawing::image flag_no() noexcept;
      /// @brief Gets the international system image "flag-no" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-no".
      static xtd::drawing::image flag_no(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-om".
      /// @return The xtd::drawing::image "flag-om".
      static xtd::drawing::image flag_om() noexcept;
      /// @brief Gets the international system image "flag-om" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-om".
      static xtd::drawing::image flag_om(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-pk".
      /// @return The xtd::drawing::image "flag-pk".
      static xtd::drawing::image flag_pk() noexcept;
      /// @brief Gets the international system image "flag-pk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pk".
      static xtd::drawing::image flag_pk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-pw".
      /// @return The xtd::drawing::image "flag-pw".
      static xtd::drawing::image flag_pw() noexcept;
      /// @brief Gets the international system image "flag-pw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pw".
      static xtd::drawing::image flag_pw(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ps".
      /// @return The xtd::drawing::image "flag-ps".
      static xtd::drawing::image flag_ps() noexcept;
      /// @brief Gets the international system image "flag-ps" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ps".
      static xtd::drawing::image flag_ps(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-pa".
      /// @return The xtd::drawing::image "flag-pa".
      static xtd::drawing::image flag_pa() noexcept;
      /// @brief Gets the international system image "flag-pa" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pa".
      static xtd::drawing::image flag_pa(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-pg".
      /// @return The xtd::drawing::image "flag-pg".
      static xtd::drawing::image flag_pg() noexcept;
      /// @brief Gets the international system image "flag-pg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pg".
      static xtd::drawing::image flag_pg(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-py".
      /// @return The xtd::drawing::image "flag-py".
      static xtd::drawing::image flag_py() noexcept;
      /// @brief Gets the international system image "flag-py" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-py".
      static xtd::drawing::image flag_py(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-pe".
      /// @return The xtd::drawing::image "flag-pe".
      static xtd::drawing::image flag_pe() noexcept;
      /// @brief Gets the international system image "flag-pe" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pe".
      static xtd::drawing::image flag_pe(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ph".
      /// @return The xtd::drawing::image "flag-ph".
      static xtd::drawing::image flag_ph() noexcept;
      /// @brief Gets the international system image "flag-ph" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ph".
      static xtd::drawing::image flag_ph(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-pn".
      /// @return The xtd::drawing::image "flag-pn".
      static xtd::drawing::image flag_pn() noexcept;
      /// @brief Gets the international system image "flag-pn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pn".
      static xtd::drawing::image flag_pn(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-pl".
      /// @return The xtd::drawing::image "flag-pl".
      static xtd::drawing::image flag_pl() noexcept;
      /// @brief Gets the international system image "flag-pl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pl".
      static xtd::drawing::image flag_pl(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-pt".
      /// @return The xtd::drawing::image "flag-pt".
      static xtd::drawing::image flag_pt() noexcept;
      /// @brief Gets the international system image "flag-pt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pt".
      static xtd::drawing::image flag_pt(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-pr".
      /// @return The xtd::drawing::image "flag-pr".
      static xtd::drawing::image flag_pr() noexcept;
      /// @brief Gets the international system image "flag-pr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pr".
      static xtd::drawing::image flag_pr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-qa".
      /// @return The xtd::drawing::image "flag-qa".
      static xtd::drawing::image flag_qa() noexcept;
      /// @brief Gets the international system image "flag-qa" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-qa".
      static xtd::drawing::image flag_qa(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-re".
      /// @return The xtd::drawing::image "flag-re".
      static xtd::drawing::image flag_re() noexcept;
      /// @brief Gets the international system image "flag-re" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-re".
      static xtd::drawing::image flag_re(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ro".
      /// @return The xtd::drawing::image "flag-ro".
      static xtd::drawing::image flag_ro() noexcept;
      /// @brief Gets the international system image "flag-ro" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ro".
      static xtd::drawing::image flag_ro(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ru".
      /// @return The xtd::drawing::image "flag-ru".
      static xtd::drawing::image flag_ru() noexcept;
      /// @brief Gets the international system image "flag-ru" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ru".
      static xtd::drawing::image flag_ru(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-rw".
      /// @return The xtd::drawing::image "flag-rw".
      static xtd::drawing::image flag_rw() noexcept;
      /// @brief Gets the international system image "flag-rw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-rw".
      static xtd::drawing::image flag_rw(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-bl".
      /// @return The xtd::drawing::image "flag-bl".
      static xtd::drawing::image flag_bl() noexcept;
      /// @brief Gets the international system image "flag-bl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-bl".
      static xtd::drawing::image flag_bl(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sh".
      /// @return The xtd::drawing::image "flag-sh".
      static xtd::drawing::image flag_sh() noexcept;
      /// @brief Gets the international system image "flag-sh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sh".
      static xtd::drawing::image flag_sh(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-kn".
      /// @return The xtd::drawing::image "flag-kn".
      static xtd::drawing::image flag_kn() noexcept;
      /// @brief Gets the international system image "flag-kn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-kn".
      static xtd::drawing::image flag_kn(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-lc".
      /// @return The xtd::drawing::image "flag-lc".
      static xtd::drawing::image flag_lc() noexcept;
      /// @brief Gets the international system image "flag-lc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lc".
      static xtd::drawing::image flag_lc(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-mf".
      /// @return The xtd::drawing::image "flag-mf".
      static xtd::drawing::image flag_mf() noexcept;
      /// @brief Gets the international system image "flag-mf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-mf".
      static xtd::drawing::image flag_mf(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-pm".
      /// @return The xtd::drawing::image "flag-pm".
      static xtd::drawing::image flag_pm() noexcept;
      /// @brief Gets the international system image "flag-pm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-pm".
      static xtd::drawing::image flag_pm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-vc".
      /// @return The xtd::drawing::image "flag-vc".
      static xtd::drawing::image flag_vc() noexcept;
      /// @brief Gets the international system image "flag-vc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-vc".
      static xtd::drawing::image flag_vc(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ws".
      /// @return The xtd::drawing::image "flag-ws".
      static xtd::drawing::image flag_ws() noexcept;
      /// @brief Gets the international system image "flag-ws" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ws".
      static xtd::drawing::image flag_ws(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sm".
      /// @return The xtd::drawing::image "flag-sm".
      static xtd::drawing::image flag_sm() noexcept;
      /// @brief Gets the international system image "flag-sm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sm".
      static xtd::drawing::image flag_sm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-st".
      /// @return The xtd::drawing::image "flag-st".
      static xtd::drawing::image flag_st() noexcept;
      /// @brief Gets the international system image "flag-st" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-st".
      static xtd::drawing::image flag_st(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sa".
      /// @return The xtd::drawing::image "flag-sa".
      static xtd::drawing::image flag_sa() noexcept;
      /// @brief Gets the international system image "flag-sa" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sa".
      static xtd::drawing::image flag_sa(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sn".
      /// @return The xtd::drawing::image "flag-sn".
      static xtd::drawing::image flag_sn() noexcept;
      /// @brief Gets the international system image "flag-sn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sn".
      static xtd::drawing::image flag_sn(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-rs".
      /// @return The xtd::drawing::image "flag-rs".
      static xtd::drawing::image flag_rs() noexcept;
      /// @brief Gets the international system image "flag-rs" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-rs".
      static xtd::drawing::image flag_rs(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sc".
      /// @return The xtd::drawing::image "flag-sc".
      static xtd::drawing::image flag_sc() noexcept;
      /// @brief Gets the international system image "flag-sc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sc".
      static xtd::drawing::image flag_sc(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sl".
      /// @return The xtd::drawing::image "flag-sl".
      static xtd::drawing::image flag_sl() noexcept;
      /// @brief Gets the international system image "flag-sl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sl".
      static xtd::drawing::image flag_sl(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sg".
      /// @return The xtd::drawing::image "flag-sg".
      static xtd::drawing::image flag_sg() noexcept;
      /// @brief Gets the international system image "flag-sg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sg".
      static xtd::drawing::image flag_sg(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sx".
      /// @return The xtd::drawing::image "flag-sx".
      static xtd::drawing::image flag_sx() noexcept;
      /// @brief Gets the international system image "flag-sx" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sx".
      static xtd::drawing::image flag_sx(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sk".
      /// @return The xtd::drawing::image "flag-sk".
      static xtd::drawing::image flag_sk() noexcept;
      /// @brief Gets the international system image "flag-sk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sk".
      static xtd::drawing::image flag_sk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-si".
      /// @return The xtd::drawing::image "flag-si".
      static xtd::drawing::image flag_si() noexcept;
      /// @brief Gets the international system image "flag-si" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-si".
      static xtd::drawing::image flag_si(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sb".
      /// @return The xtd::drawing::image "flag-sb".
      static xtd::drawing::image flag_sb() noexcept;
      /// @brief Gets the international system image "flag-sb" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sb".
      static xtd::drawing::image flag_sb(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-so".
      /// @return The xtd::drawing::image "flag-so".
      static xtd::drawing::image flag_so() noexcept;
      /// @brief Gets the international system image "flag-so" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-so".
      static xtd::drawing::image flag_so(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-za".
      /// @return The xtd::drawing::image "flag-za".
      static xtd::drawing::image flag_za() noexcept;
      /// @brief Gets the international system image "flag-za" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-za".
      static xtd::drawing::image flag_za(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gs".
      /// @return The xtd::drawing::image "flag-gs".
      static xtd::drawing::image flag_gs() noexcept;
      /// @brief Gets the international system image "flag-gs" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gs".
      static xtd::drawing::image flag_gs(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ss".
      /// @return The xtd::drawing::image "flag-ss".
      static xtd::drawing::image flag_ss() noexcept;
      /// @brief Gets the international system image "flag-ss" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ss".
      static xtd::drawing::image flag_ss(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-es".
      /// @return The xtd::drawing::image "flag-es".
      static xtd::drawing::image flag_es() noexcept;
      /// @brief Gets the international system image "flag-es" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-es".
      static xtd::drawing::image flag_es(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-lk".
      /// @return The xtd::drawing::image "flag-lk".
      static xtd::drawing::image flag_lk() noexcept;
      /// @brief Gets the international system image "flag-lk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-lk".
      static xtd::drawing::image flag_lk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sd".
      /// @return The xtd::drawing::image "flag-sd".
      static xtd::drawing::image flag_sd() noexcept;
      /// @brief Gets the international system image "flag-sd" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sd".
      static xtd::drawing::image flag_sd(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sr".
      /// @return The xtd::drawing::image "flag-sr".
      static xtd::drawing::image flag_sr() noexcept;
      /// @brief Gets the international system image "flag-sr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sr".
      static xtd::drawing::image flag_sr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sj".
      /// @return The xtd::drawing::image "flag-sj".
      static xtd::drawing::image flag_sj() noexcept;
      /// @brief Gets the international system image "flag-sj" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sj".
      static xtd::drawing::image flag_sj(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-se".
      /// @return The xtd::drawing::image "flag-se".
      static xtd::drawing::image flag_se() noexcept;
      /// @brief Gets the international system image "flag-se" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-se".
      static xtd::drawing::image flag_se(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ch".
      /// @return The xtd::drawing::image "flag-ch".
      static xtd::drawing::image flag_ch() noexcept;
      /// @brief Gets the international system image "flag-ch" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ch".
      static xtd::drawing::image flag_ch(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-sy".
      /// @return The xtd::drawing::image "flag-sy".
      static xtd::drawing::image flag_sy() noexcept;
      /// @brief Gets the international system image "flag-sy" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-sy".
      static xtd::drawing::image flag_sy(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tw".
      /// @return The xtd::drawing::image "flag-tw".
      static xtd::drawing::image flag_tw() noexcept;
      /// @brief Gets the international system image "flag-tw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tw".
      static xtd::drawing::image flag_tw(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tj".
      /// @return The xtd::drawing::image "flag-tj".
      static xtd::drawing::image flag_tj() noexcept;
      /// @brief Gets the international system image "flag-tj" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tj".
      static xtd::drawing::image flag_tj(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tz".
      /// @return The xtd::drawing::image "flag-tz".
      static xtd::drawing::image flag_tz() noexcept;
      /// @brief Gets the international system image "flag-tz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tz".
      static xtd::drawing::image flag_tz(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-th".
      /// @return The xtd::drawing::image "flag-th".
      static xtd::drawing::image flag_th() noexcept;
      /// @brief Gets the international system image "flag-th" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-th".
      static xtd::drawing::image flag_th(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tl".
      /// @return The xtd::drawing::image "flag-tl".
      static xtd::drawing::image flag_tl() noexcept;
      /// @brief Gets the international system image "flag-tl" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tl".
      static xtd::drawing::image flag_tl(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tg".
      /// @return The xtd::drawing::image "flag-tg".
      static xtd::drawing::image flag_tg() noexcept;
      /// @brief Gets the international system image "flag-tg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tg".
      static xtd::drawing::image flag_tg(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tk".
      /// @return The xtd::drawing::image "flag-tk".
      static xtd::drawing::image flag_tk() noexcept;
      /// @brief Gets the international system image "flag-tk" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tk".
      static xtd::drawing::image flag_tk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-to".
      /// @return The xtd::drawing::image "flag-to".
      static xtd::drawing::image flag_to() noexcept;
      /// @brief Gets the international system image "flag-to" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-to".
      static xtd::drawing::image flag_to(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tt".
      /// @return The xtd::drawing::image "flag-tt".
      static xtd::drawing::image flag_tt() noexcept;
      /// @brief Gets the international system image "flag-tt" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tt".
      static xtd::drawing::image flag_tt(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tn".
      /// @return The xtd::drawing::image "flag-tn".
      static xtd::drawing::image flag_tn() noexcept;
      /// @brief Gets the international system image "flag-tn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tn".
      static xtd::drawing::image flag_tn(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tr".
      /// @return The xtd::drawing::image "flag-tr".
      static xtd::drawing::image flag_tr() noexcept;
      /// @brief Gets the international system image "flag-tr" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tr".
      static xtd::drawing::image flag_tr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tm".
      /// @return The xtd::drawing::image "flag-tm".
      static xtd::drawing::image flag_tm() noexcept;
      /// @brief Gets the international system image "flag-tm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tm".
      static xtd::drawing::image flag_tm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tc".
      /// @return The xtd::drawing::image "flag-tc".
      static xtd::drawing::image flag_tc() noexcept;
      /// @brief Gets the international system image "flag-tc" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tc".
      static xtd::drawing::image flag_tc(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-tv".
      /// @return The xtd::drawing::image "flag-tv".
      static xtd::drawing::image flag_tv() noexcept;
      /// @brief Gets the international system image "flag-tv" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-tv".
      static xtd::drawing::image flag_tv(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ug".
      /// @return The xtd::drawing::image "flag-ug".
      static xtd::drawing::image flag_ug() noexcept;
      /// @brief Gets the international system image "flag-ug" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ug".
      static xtd::drawing::image flag_ug(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ua".
      /// @return The xtd::drawing::image "flag-ua".
      static xtd::drawing::image flag_ua() noexcept;
      /// @brief Gets the international system image "flag-ua" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ua".
      static xtd::drawing::image flag_ua(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ae".
      /// @return The xtd::drawing::image "flag-ae".
      static xtd::drawing::image flag_ae() noexcept;
      /// @brief Gets the international system image "flag-ae" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ae".
      static xtd::drawing::image flag_ae(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-gb".
      /// @return The xtd::drawing::image "flag-gb".
      static xtd::drawing::image flag_gb() noexcept;
      /// @brief Gets the international system image "flag-gb" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-gb".
      static xtd::drawing::image flag_gb(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-us".
      /// @return The xtd::drawing::image "flag-us".
      static xtd::drawing::image flag_us() noexcept;
      /// @brief Gets the international system image "flag-us" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-us".
      static xtd::drawing::image flag_us(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-um".
      /// @return The xtd::drawing::image "flag-um".
      static xtd::drawing::image flag_um() noexcept;
      /// @brief Gets the international system image "flag-um" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-um".
      static xtd::drawing::image flag_um(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-uy".
      /// @return The xtd::drawing::image "flag-uy".
      static xtd::drawing::image flag_uy() noexcept;
      /// @brief Gets the international system image "flag-uy" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-uy".
      static xtd::drawing::image flag_uy(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-uz".
      /// @return The xtd::drawing::image "flag-uz".
      static xtd::drawing::image flag_uz() noexcept;
      /// @brief Gets the international system image "flag-uz" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-uz".
      static xtd::drawing::image flag_uz(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-vu".
      /// @return The xtd::drawing::image "flag-vu".
      static xtd::drawing::image flag_vu() noexcept;
      /// @brief Gets the international system image "flag-vu" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-vu".
      static xtd::drawing::image flag_vu(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ve".
      /// @return The xtd::drawing::image "flag-ve".
      static xtd::drawing::image flag_ve() noexcept;
      /// @brief Gets the international system image "flag-ve" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ve".
      static xtd::drawing::image flag_ve(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-vn".
      /// @return The xtd::drawing::image "flag-vn".
      static xtd::drawing::image flag_vn() noexcept;
      /// @brief Gets the international system image "flag-vn" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-vn".
      static xtd::drawing::image flag_vn(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-vg".
      /// @return The xtd::drawing::image "flag-vg".
      static xtd::drawing::image flag_vg() noexcept;
      /// @brief Gets the international system image "flag-vg" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-vg".
      static xtd::drawing::image flag_vg(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-vi".
      /// @return The xtd::drawing::image "flag-vi".
      static xtd::drawing::image flag_vi() noexcept;
      /// @brief Gets the international system image "flag-vi" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-vi".
      static xtd::drawing::image flag_vi(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-wf".
      /// @return The xtd::drawing::image "flag-wf".
      static xtd::drawing::image flag_wf() noexcept;
      /// @brief Gets the international system image "flag-wf" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-wf".
      static xtd::drawing::image flag_wf(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-eh".
      /// @return The xtd::drawing::image "flag-eh".
      static xtd::drawing::image flag_eh() noexcept;
      /// @brief Gets the international system image "flag-eh" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-eh".
      static xtd::drawing::image flag_eh(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-ye".
      /// @return The xtd::drawing::image "flag-ye".
      static xtd::drawing::image flag_ye() noexcept;
      /// @brief Gets the international system image "flag-ye" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-ye".
      static xtd::drawing::image flag_ye(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-zm".
      /// @return The xtd::drawing::image "flag-zm".
      static xtd::drawing::image flag_zm() noexcept;
      /// @brief Gets the international system image "flag-zm" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-zm".
      static xtd::drawing::image flag_zm(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the international system image "flag-zw".
      /// @return The xtd::drawing::image "flag-zw".
      static xtd::drawing::image flag_zw() noexcept;
      /// @brief Gets the international system image "flag-zw" with specified size.
      /// @param size The international system image size in pixels.
      /// @return The xtd::drawing::image "flag-zw".
      static xtd::drawing::image flag_zw(const xtd::drawing::size& size) noexcept;

      /// @}

      /// @name Static methods

      /// @{
      /// @brief Gets an array of images.
      /// @return The array of images.
      static const std::vector<xtd::drawing::image>& get_images() noexcept;
      /// @brief Gets an array of images with specified size.
      /// @param size The images size in pixels.
      /// @return The array of images.
      static std::vector<xtd::drawing::image> get_images(const xtd::drawing::size& size) noexcept;

      /// @brief Gets an array of image names.
      /// @return The array of image names.
      static const std::vector<xtd::ustring>& get_image_names() noexcept;
      /// @}
    };
  }
}
