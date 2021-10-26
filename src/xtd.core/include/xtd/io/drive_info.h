/// @file
/// @brief Contains xtd::io::drive_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../core_export.h"
#include "../object.h"
#include "directory_info.h"
#include "drive_type.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Provides access to information on a drive.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ drive_info : public object {
    public:
      drive_info(const xtd::ustring& drive_name);

      size_t available_free_space() const;

      xtd::ustring drive_format() const;
      
      xtd::io::drive_type drive_type() const;
      
      bool is_ready() const noexcept;
      
      xtd::ustring name() const noexcept;
      
      xtd::io::directory_info root_directory() const noexcept;

      size_t total_free_space() const;
      
      size_t total_size() const;
      
      xtd::ustring volume_label() const;
      
      static std::vector<xtd::io::drive_info> get_drives() noexcept;
      
      xtd::ustring to_string() const noexcept override;

    private:
      drive_info() = default;
      
      xtd::ustring drive_name_;
    };
  }
}
