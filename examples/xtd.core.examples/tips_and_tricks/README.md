# Tips & Tricks examples

[This folder](.) contains Tips & Tricks examples used by [Reference Guide](https://gammasoft71.github.io/xtd/reference_guides/latest/) and more.

* [binary_reader_and_binary_writer](binary_reader_and_binary_writer/README.md) demonstrates that binary files created with [xtd::io::binary_writer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__writer) and read with [xtd::io::binary_reader](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__reader) are fully compatible with .NET's [BinaryWriter](https://learn.microsoft.com/en-us/dotnet/api/system.io.binarywriter) and [BinaryReader](https://learn.microsoft.com/en-us/dotnet/api/system.io.binaryreader). The files produced by xtd and .NET are identical, ensuring seamless cross-language interoperability.
* [xtd_collection_indexer](xtd_collection_indexer/README.md) shows how to use indexing operators with [xtd::bpos](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gae5b63301b69ce281ee7db98e2e61941f) (bpos, bpos + 1, bpos + 2), [xtd::epos](https://gammasoft71.github.io/xtd/reference_guides/latest/group__system.html#gaa99759e66edbafa9f3ed0b523c924b5c) (epos, epos - 1, epos - 2, ...) and bitwise operators (~1_z, ~2_z, ...) with xtd collections like [xtd::collections::generic::list](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1list.html).

## Build and run any project

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run -t any_project_name
```
