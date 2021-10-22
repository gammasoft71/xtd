/// @file
/// @brief Contains xtd::io::file_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "file_system_info.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @cond
    class directory_info;
    /// @endcond
    
    /// @brief Provides static methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of std::fstream objects.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ file_info : public xtd::io::file_system_info {
    public:
      file_info(const xtd::ustring& path);
      
      xtd::io::directory_info directory() const;
      
      xtd::ustring directory_name() const;
      
      bool exists() const override;
      
      bool is_read_only() const;
      
      size_t length() const;
      
      xtd::ustring name() const override;

      void remove() override;
    };
  }
}
