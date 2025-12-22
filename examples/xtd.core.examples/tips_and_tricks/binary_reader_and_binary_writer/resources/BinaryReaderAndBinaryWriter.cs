namespace BinaryReaderAndBinaryWriter {
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
