/// @file
/// @brief Contains xtd::io::drive_info class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
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
    /// @code
    /// class core_export_ drive_info : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::io::drive_info
    /// @par Header
    /// @code #include <xtd/io/drive_info> @endcode
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @par Examples
    /// The following code example demonstrates the use of the xtd::io::drive_info class to display information about all of the drives on the current system.
    /// @include drive_info.cpp
    /// @remarks This class models a drive and provides methods and properties to query for drive information. Use xtd::io::drive_info to determine what drives are available, and what type of drives they are. You can also query to determine the capacity and available free space on the drive.
    class core_export_ drive_info : public xtd::object {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Represents the uninitialized xtd::io::drive_info object. This field is constant.
      static const drive_info empty;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Provides access to information on the specified drive.
      /// @param drive_name A valid drive path or drive letter. This can be either uppercase or lowercase, 'a' to 'z'. A null value is not valid.
      /// @exception xtd::argument_exception drive_name does not refer to a valid drive.
      /// @remarks Use this class to obtain information on drives. The drive name must be either an uppercase or lowercase letter from 'a' to 'z'. You cannot use this method to obtain information on drive names that are null or use UNC (\\server\share) paths.
      explicit drive_info(const xtd::ustring& drive_name);
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Indicates the amount of available free space on a drive, in bytes.
      /// @return The amount of free space available on the drive, in bytes.
      /// @exception xtd::unauthorized_access_exception Access to the drive information is denied.
      /// @exception xtd::io::drive_not_found The drive does not exist or is not mapped.
      /// @exception xtd::io::io_exception An I/O error occurred (for example, a disk error or a drive was not ready).
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::io::drive_info class to display information about all of the drives on the current system.
      /// @include drive_info.cpp
      /// @remarks This property indicates the amount of free space available on the drive. Note that this number may be different from the xtd::io::drive_info::total_free_space number because this property takes into account disk quotas.
      size_t available_free_space() const;
      
      /// @brief Gets the name of the file system, such as NTFS or FAT32.
      /// @return The name of the file system on the specified drive.
      /// @exception xtd::unauthorized_access_exception Access to the drive information is denied.
      /// @exception xtd::io::drive_not_found The drive does not exist or is not mapped.
      /// @exception xtd::io::io_exception An I/O error occurred (for example, a disk error or a drive was not ready).
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::io::drive_info class to display information about all of the drives on the current system.
      /// @include drive_info.cpp
      /// @remarks Use xtd::io::drive_info::drive_format to determine what formatting a drive uses.
      xtd::ustring drive_format() const;
      
      /// @brief Gets the drive type, such as CD-ROM, removable, network, or fixed.
      /// @return One of the enumeration values that specifies a drive type.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::io::drive_info class to display information about all of the drives on the current system.
      /// @include drive_info.cpp
      /// @remarks The xtd::io::drive_info::drive_type property indicates whether a drive is one of the following: CDRom, Fixed, Network, NoRootDirectory, Ram, Removable, or Unknown. These values are described in the xtd::io::drive_type enumeration.
      xtd::io::drive_type drive_type() const;
      
      /// @brief Gets a value that indicates whether a drive is ready.
      /// @return true if the drive is ready; false if the drive is not ready.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::io::drive_info class to display information about all of the drives on the current system.
      /// @include drive_info.cpp
      /// @remarks xtd::io::drive_info::is_ready indicates whether a drive is ready. For example, it indicates whether a CD is in a CD drive or whether a removable storage device is ready for read/write operations. If you do not test whether a drive is ready, and it is not ready, querying the drive using xtd::io::drive_info will raise an xtd::io::io_exception.
      /// @remarks Do not rely on xtd::io::drive_info::is_ready to avoid catching exceptions from other members such as xtd::io::drive_info::total_size, xtd::io::drive_info::total_free_space, and xtd::io::drive_info::drive_format. Between the time that your code checks xtd::io::drive_info::is_ready and then accesses one of the other properties (even if the access occurs immediately after the check), a drive may have been disconnected or a disk may have been removed.
      bool is_ready() const noexcept;
      
      /// @brief Gets the name of a drive, such as C:\.
      /// @return The name of the drive.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::io::drive_info class to display information about all of the drives on the current system.
      /// @include drive_info.cpp
      /// @remarks This property is the name assigned to the drive, such as C:\ or E:\.
      xtd::ustring name() const noexcept;
      
      /// @brief Gets the root directory of a drive.
      /// @return An object that contains the root directory of the drive.
      xtd::io::directory_info root_directory() const noexcept;
      
      /// @brief Gets the total amount of free space available on a drive, in bytes.
      /// @return The total free space available on a drive, in bytes.
      /// @exception xtd::unauthorized_access_exception Access to the drive information is denied.
      /// @exception xtd::io::drive_not_found The drive does not exist or is not mapped.
      /// @exception xtd::io::io_exception An I/O error occurred (for example, a disk error or a drive was not ready).
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::io::drive_info class to display information about all of the drives on the current system.
      /// @include drive_info.cpp
      /// @remarks This property indicates the total amount of free space available on the drive, not just what is available to the current user.
      size_t total_free_space() const;
      
      /// @brief Gets the total size of storage space on a drive, in bytes.
      /// @return The total size of the drive, in bytes.
      /// @exception xtd::unauthorized_access_exception Access to the drive information is denied.
      /// @exception xtd::io::drive_not_found The drive does not exist or is not mapped.
      /// @exception xtd::io::io_exception An I/O error occurred (for example, a disk error or a drive was not ready).
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::io::drive_info class to display information about all of the drives on the current system.
      /// @include drive_info.cpp
      /// @remarks This property indicates the total size of the drive in bytes, not just what is available to the current user.
      size_t total_size() const;
      
      /// @brief Gets the volume label of a drive.
      /// @return The volume label.
      /// @exception xtd::unauthorized_access_exception Access to the drive information is denied.
      /// @exception xtd::io::drive_not_found The drive does not exist or is not mapped.
      /// @exception xtd::io::io_exception An I/O error occurred (for example, a disk error or a drive was not ready).
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::io::drive_info class to display information about all of the drives on the current system.
      /// @include drive_info.cpp
      /// @remarks The label length is determined by the operating system. For example, NTFS allows a volume label to be up to 32 characters long.
      xtd::ustring volume_label() const;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Retrieves the drive names of all logical drives on a computer.
      /// @return An array of type xtd::ioo::drive_info that represents the logical drives on a computer.
      /// @exception xtd::unauthorized_access_exception Access to the drive information is denied.
      /// @exception xtd::io::io_exception An I/O error occurred (for example, a disk error or a drive was not ready).
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::io::drive_info class to display information about all of the drives on the current system.
      /// @include drive_info.cpp
      /// @remarks This method retrieves all logical drive names on a computer. You can use this information to iterate through the array and obtain information on the drives using other xtd::io::drive_info methods and properties. Use the xtd::io::drive_info::is_ready property to test whether a drive is ready because using this method on a drive that is not ready will throw a xtd::io::io_exception.
      static std::vector<xtd::io::drive_info> get_drives() noexcept;
      
      /// @brief Returns a drive name as a string.
      /// @return The name of the drive.
      /// @remarks This method returns the xtd::io::drive_info::name property.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      drive_info() = default;
      
      xtd::ustring drive_name_;
    };
  }
}
