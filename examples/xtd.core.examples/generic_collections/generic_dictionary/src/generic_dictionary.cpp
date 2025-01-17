#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

class example {
public:
  static auto main() -> void {
    // Create a new dictionary of strings, with string keys.
    //
    auto open_with = dictionary<string, string> {};
    
    // Add some elements to the dictionary. There are no
    // duplicate keys, but some of the values are duplicates.
    open_with.add("txt", "notepad.exe");
    open_with.add("bmp", "paint.exe");
    open_with.add("dib", "paint.exe");
    open_with.add("rtf", "wordpad.exe");
    
    // The Add method throws an exception if the new key is
    // already in the dictionary.
    try {
      open_with.add("txt", "winword.exe");
    } catch (const argument_exception&) {
      console::write_line("An element with key = \"txt\" already exists.");
    }
    
    // The operator [] is another name for the indexer, so you
    // can omit its name when accessing elements.
    console::write_line("For key = \"rtf\", value = {0}.", xtd::as_const(open_with)["rtf"]);
    
    // The indexer can be used to change the value associated with a key.
    open_with["rtf"] = "winword.exe";
    console::write_line("For key = \"rtf\", value = {0}.", xtd::as_const(open_with)["rtf"]);
    
    // If a key does not exist, setting the indexer for that key
    // adds a new key/value pair.
    open_with["doc"] = "winword.exe";
    
    // The indexer throws an exception if the requested key is not in the dictionary.
    try {
      console::write_line("For key = \"tif\", value = {0}.", xtd::as_const(open_with)["tif"]);
    } catch (const key_not_found_exception&) {
      console::write_line("key = \"tif\" is not found.");
    }
    
    // When a program often has to try keys that turn out not to
    // be in the dictionary, try_get_value can be a more efficient
    // way to retrieve values.
    auto value = ""_s;
    if (open_with.try_get_value("tif", value))
      console::write_line("For key = \"tif\", value = {0}.", value);
    else
      console::write_line("key = \"tif\" is not found.");
    
    // contains_key can be used to test keys before inserting them.
    if (!open_with.contains_key("ht")) {
      open_with.add("ht", "hypertrm.exe");
      console::write_line("value added for key = \"ht\": {0}", xtd::as_const(open_with)["ht"]);
    }
    
    // When you use for each to enumerate dictionary elements,
    // the elements are retrieved as key_value_pair objects.
    console::write_line();
    for (const key_value_pair<string, string>& kvp : open_with)
      console::write_line("key = {0}, value = {1}", kvp.key(), kvp.value());
    
    // To get the values alone, use the values property.
    dictionary<string, string>::value_collection values = open_with.values();
    
    // The elements of the value_collection are strongly typed
    // with the type that was specified for dictionary values.
    console::write_line();
    for(const auto& s : values)
      console::write_line("value = {0}", s);
    
    // To get the keys alone, use the keys property.
    dictionary<string, string>::key_collection keys = open_with.keys();
    
    // The elements of the key_collection are strongly typed
    // with the type that was specified for dictionary keys.
    console::write_line();
    for(const string& s : keys)
      console::write_line("key = {0}", s);
    
    // Use the remove method to remove a key/value pair.
    console::write_line("\nRemove(\"doc\")");
    open_with.remove("doc");
    
    if (!open_with.contains_key("doc"))
      console::write_line("key \"doc\" is not found.");
  }
};

startup_(example::main);

// This code produces the following output :
//
// An element with key = "txt" already exists.
// For key = "rtf", value = wordpad.exe.
// For key = "rtf", value = winword.exe.
// key = "tif" is not found.
// key = "tif" is not found.
// value added for key = "ht": hypertrm.exe
//
// key = doc, value = winword.exe
// key = rtf, value = winword.exe
// key = bmp, value = paint.exe
// key = ht, value = hypertrm.exe
// key = dib, value = paint.exe
// key = txt, value = notepad.exe
//
// value = winword.exe
// value = winword.exe
// value = paint.exe
// value = hypertrm.exe
// value = paint.exe
// value = notepad.exe
//
// key = doc
// key = rtf
// key = bmp
// key = ht
// key = dib
// key = txt
//
// Remove("doc")
// key "doc" is not found.
