/// @file
/// @brief Contains xtd::io::file_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "file_system_info.h"
#include <fstream>

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
      static const file_info empty;
      
      file_info(const xtd::ustring& path);
      
      xtd::io::directory_info directory() const;
      
      xtd::ustring directory_name() const;
      
      bool exists() const override;
      
      bool is_read_only() const;
      
      size_t length() const;
      
      xtd::ustring name() const override;
      
      std::ofstream append_text() const;

      xtd::io::file_info copy_to(const xtd::ustring& dest_file_name) const;
      
      xtd::io::file_info copy_to(const xtd::ustring& dest_file_name, bool overwrite) const;
      
      std::ofstream create() const;
      
      std::ofstream create_text() const;
      
      void move_to(const xtd::ustring& dest_file_name);
      
      void move_to(const xtd::ustring& dest_file_name, bool overwrite);
      
      std::fstream open(std::ios::openmode mode) const;
      
      std::ifstream open_read() const;

      std::ifstream open_text() const;
      
      std::ofstream open_write() const;

      void remove() const override;
      
      void replace(const xtd::ustring& destination_file_name, const xtd::ustring& destination_backup_file_name);

    private:
      file_info() = default;
    };
  }
}
