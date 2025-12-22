# binary_reader_and_binary_writer

Demonstrates that binary files created with [xtd::io::binary_writer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__writer) and read with [xtd::io::binary_reader](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__reader) are fully compatible with .NET's [BinaryWriter](https://learn.microsoft.com/en-us/dotnet/api/system.io.binarywriter) and [BinaryReader](https://learn.microsoft.com/en-us/dotnet/api/system.io.binaryreader). The files produced by xtd and .NET are identical, ensuring seamless cross-language interoperability.

## Sources

* [src/binary_reader_and_binary_writer.cpp](src/binary_reader_and_binary_writer.cpp)

## Properties

* [properties/resources.cmake](properties/resources.cmake)

## Resources

* [resources/BinaryReaderAndBinaryWriter.cs](resources/BinaryReaderAndBinaryWriter.cs)
* [resources/file_dotnet.dat](resources/file_dotnet.dat)
* [resources/file_xtd.dat](resources/file_xtd.dat)

## CMake files

* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Write binary file

Read binary file
  1.25
  This is a string
  42
  true

Print binary files from xtd and dotnet
  file_dotnet -> [0, 0, 160, 63, 16, 84, 104, 105, 115, 32, 105, 115, 32, 97, 32, 115, 116, 114, 105, 110, 103, 42, 0, 0, 0, 1]
  file_xtd    -> [0, 0, 160, 63, 16, 84, 104, 105, 115, 32, 105, 115, 32, 97, 32, 115, 116, 114, 105, 110, 103, 42, 0, 0, 0, 1]

Same code in c#
\```csharp
﻿namespace BinaryReaderAndBinaryWriter {
  class MainClass {
    static void WriteBinaryFile(string FileName, Tuple<float, string, int, bool> items) {
      using (var writer = new BinaryWriter(new FileStream(FileName, FileMode.OpenOrCreate))) {
        writer.Write(items.Item1);
        writer.Write(items.Item2);
        writer.Write(items.Item3);
        writer.Write(items.Item4);
      }
    }

    static Tuple<float, string, int, bool> ReadBinaryFile(string FileName) {
      if (!File.Exists(FileName)) return Tuple.Create(.0f, "", 0, false);
      using (var reader = new BinaryReader(new FileStream(FileName, FileMode.Open)))
        return Tuple.Create(reader.ReadSingle(), reader.ReadString(), reader.ReadInt32(), reader.ReadBoolean());
    }

    public static void Main() {
      var fileName = "file_dotnet.dat";

      Console.WriteLine("Write binary file");

      Console.WriteLine("\nRead binary file");
      WriteBinaryFile(fileName, Tuple.Create(1.25f, "This is a string", 42, true));
      var items = ReadBinaryFile(fileName);
      Console.WriteLine(items.Item1);
      Console.WriteLine(items.Item2);
      Console.WriteLine(items.Item3);
      Console.WriteLine(items.Item4);
    }
  }
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
\```
```
