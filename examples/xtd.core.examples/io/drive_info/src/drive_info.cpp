#include <xtd/io/drive_info>
#include <xtd/console>
#include <xtd/startup>

using namespace std;
using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    auto all_drives = drive_info::get_drives();
    
    for (auto d : all_drives) {
      console::write_line("Drive {0}", d.name());
      console::write_line("  Drive type: {0}", d.drive_type());
      if (d.is_ready() == true) {
        console::write_line("  Volume label: {0}", d.volume_label());
        console::write_line("  File system: {0}", d.drive_format());
        console::write_line("  Available space to current user:{0, 15} bytes", d.available_free_space());
        console::write_line("  Total available space:          {0, 15} bytes", d.total_free_space());
        console::write_line("  Total size of drive:            {0, 15} bytes", d.total_size());
      }
    }
  }
};

startup_(program);

// This code produces the following output :
//
// Drive A:\
//   Drive type: Removable
// Drive C:\
//   Drive type: Fixed
//   Volume label:
//   File system: FAT32
//   Available space to current user:     4770430976 bytes
//   Total available space:               4770430976 bytes
//   Total size of drive:                10731683840 bytes
// Drive D:\
//   Drive type: Fixed
//   Volume label:
//   File system: NTFS
//   Available space to current user:    15114977280 bytes
//   Total available space:              15114977280 bytes
//   Total size of drive:                25958948864 bytes
// Drive E:\
//   Drive type: CDRom
//
// The actual output of this code will vary based on machine and the permissions
// granted to the user executing it.
