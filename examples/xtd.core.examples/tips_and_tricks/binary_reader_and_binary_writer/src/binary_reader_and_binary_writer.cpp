#include "../properties/resources.hpp"
#include <xtd/xtd>

auto write_binary_file(auto file_name, auto items) {
  auto writer = binary_writer {file_name};
  writer.write(std::get<0>(items));
  writer.write(std::get<1>(items));
  writer.write(std::get<2>(items));
  writer.write(std::get<3>(items));
}

auto read_binary_file(auto file_name) {
  if (!file::exists(file_name)) return std::make_tuple(.0f, ""_s, 0, false);
  auto reader = binary_reader {file_name};
  return std::make_tuple(reader.read_single(), reader.read_string(), reader.read_int32(), reader.read_boolean());
}

auto main() -> int {
  constexpr auto file_name = "file_xtd.dat";
  
  console::write_line("Write binary file");
  write_binary_file(file_name, std::make_tuple(1.25f, "This is a string", 42, true));
  
  console::write_line("\nRead binary file");
  auto items = read_binary_file(file_name);
  console::write_line("  {}", std::get<0>(items));
  console::write_line("  {}", std::get<1>(items));
  console::write_line("  {}", std::get<2>(items));
  console::write_line("  {}", std::get<3>(items));
  
  using namespace binary_reader_and_binary_writer::properties;
  console::write_line("\nPrint binary files from xtd and dotnet");
  console::write_line("  file_dotnet -> {}", resources::file_dotnet());
  console::write_line("  file_xtd    -> {}", resources::file_xtd());
  
  console::write_line("\nSame code in c#");
  console::write_line("```csharp");
  console::write(string {resources::csharp_source().begin(), resources::csharp_source().end()});
  console::write_line("```");
}

// This code produces the following output :
//
// Write binary file
//
// Read binary file
//   1.25
//   This is a string
//   42
//   true
//
// Print binary files from xtd and dotnet
//   file_dotnet -> [0, 0, 160, 63, 16, 84, 104, 105, 115, 32, 105, 115, 32, 97, 32, 115, 116, 114, 105, 110, 103, 42, 0, 0, 0, 1]
//   file_xtd    -> [0, 0, 160, 63, 16, 84, 104, 105, 115, 32, 105, 115, 32, 97, 32, 115, 116, 114, 105, 110, 103, 42, 0, 0, 0, 1]
//
// Same code in c#
// ```csharp
// namespace BinaryReaderAndBinaryWriter {
//   class MainClass {
//     static void WriteBinaryFile(string FileName, Tuple<float, string, int, bool> items) {
//       using (var writer = new BinaryWriter(new FileStream(FileName, FileMode.OpenOrCreate))) {
//         writer.Write(items.Item1);
//         writer.Write(items.Item2);
//         writer.Write(items.Item3);
//         writer.Write(items.Item4);
//       }
//     }
//
//     static Tuple<float, string, int, bool> ReadBinaryFile(string FileName) {
//       if (!File.Exists(FileName)) return Tuple.Create(.0f, "", 0, false);
//       using (var reader = new BinaryReader(new FileStream(FileName, FileMode.Open)))
//         return Tuple.Create(reader.ReadSingle(), reader.ReadString(), reader.ReadInt32(), reader.ReadBoolean());
//     }
//
//     public static void Main() {
//       var fileName = "file_dotnet.dat";
//
//       Console.WriteLine("Write binary file");
//
//       Console.WriteLine("\nRead binary file");
//       WriteBinaryFile(fileName, Tuple.Create(1.25f, "This is a string", 42, true));
//       var items = ReadBinaryFile(fileName);
//       Console.WriteLine(items.Item1);
//       Console.WriteLine(items.Item2);
//       Console.WriteLine(items.Item3);
//       Console.WriteLine(items.Item4);
//     }
//   }
// }
//
// // This code produces the following output :
// //
// // Write binary file
// //
// // Read binary file
// //   1.25
// //   This is a string
// //   42
// //   true
// ```
