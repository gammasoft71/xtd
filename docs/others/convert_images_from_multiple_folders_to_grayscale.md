# Convert images from multiple folders to grayscale

This document shows how the same task — scanning multiple folders for images and converting them to grayscale — can be implemented using different languages and frameworks.

The goal is twofold:
	•	Clarity: demonstrate how this problem can be solved with clear, modern code, especially using xtd and xtd::linq, which bring concise and expressive constructs to C++.
	•	Comparison: explore how other frameworks (Qt, wxWidgets, Python, C#, etc.) handle the same scenario, and highlight the similarities and differences in style, readability, and maintainability.

The xtd examples progress from straightforward, structured code to more compact one-liners. While these one-liners are not always maintainable, they serve as a fun way to illustrate the expressive power of different approaches.

## xtd

```cpp
#include <xtd/xtd>

auto main() -> int {
  for (auto path : {path::combine(environment::get_folder_path(environment::special_folder::my_pictures), "base_resources"), path::combine(environment::get_folder_path(environment::special_folder::home), "Personal Pictures")})
    for (auto file : directory::get_files(path, "*", search_option::all_directories)) {
      if (io::path::get_extension(file) != "*.png" && io::path::get_extension(file) != "*.jpg") continue;
      auto out_file = io::path::get_file_name_without_extension(file) + "_grayscale" + io::path::get_extension(file);
      drawing::imaging::image_effector::set_effect(drawing::image::from_file(file), drawing::imaging::effects::grayscale_effect()).save(out_file);
      println("Image `{}` converted to grayscale -> : `{}`", file, out_file);
    }
}
```

## xtd (linq)

```cpp
#include <xtd/xtd>

auto main() -> int {
  from({path::combine(environment::get_folder_path(environment::special_folder::my_pictures), "base_resources"), path::combine(environment::get_folder_path(environment::special_folder::home), "Personal Pictures")})
    .to_list().for_each([](auto path) {
      directory::get_files(path, "*", search_option::all_directories)
        .where([](auto file) {return io::path::get_extension(file) == "*.png" || io::path::get_extension(file) == "*.jpg";})
        .to_list().for_each([](auto file) {
          auto out_file = io::path::get_file_name_without_extension(file) + "_grayscale" + io::path::get_extension(file);
          drawing::imaging::image_effector::set_effect(drawing::image::from_file(file), drawing::imaging::effects::grayscale_effect()).save(out_file);
          println("Image `{}` converted to grayscale -> : `{}`", file, out_file);
        });
    });
}
```

## xtd (linq one-liner)

```cpp
#include <xtd/xtd>

auto main() -> int {
  from({path::combine(environment::get_folder_path(environment::special_folder::my_pictures), "base_resources"), path::combine(environment::get_folder_path(environment::special_folder::home), "Personal Pictures")}).to_list().for_each([](auto path) {directory::get_files(path, "*", search_option::all_directories).order_by([](auto file) {return file;}).where([](auto file) {return io::path::get_extension(file) == "*.png" || io::path::get_extension(file) == "*.jpg";}).to_list().for_each([](auto file) {drawing::imaging::image_effector::set_effect(drawing::image::from_file(file), drawing::imaging::effects::grayscale_effect()).save(io::path::get_file_name_without_extension(file) + "_grayscale" + io::path::get_extension(file)), console::write_line("Image `{}` converted to grayscale -> :", file, io::path::get_file_name_without_extension(file) + "_grayscale" + io::path::get_extension(file));});});
}
```

## Qt

```cpp
#include <QCoreApplication>
#include <QDir>
#include <QDirIterator>
#include <QImage>
#include <QFileInfo>
#include <QDebug>

auto main(int argc, char* argv[]) -> int {
  QCoreApplication app(argc, argv);

  for (auto path :{QDir::homePath() + "/Pictures/base_resources", QDir::homePath() + "/Personal Pictures"})
    for (auto it = QDirIterator {path, {"*.png", "*.jpg"}, QDir::Files, QDirIterator::Subdirectories}; it.hasNext(); ) {
      auto filePath = it.next();
      auto image = QImage {filePath};
      if (image.isNull()) continue;
      auto fileInfo = QFileInfo {filePath};
      auto outFile = fileInfo.absolutePath() + "/" + fileInfo.completeBaseName() + "_grayscale." + fileInfo.suffix();
      image.convertToFormat(QImage::Format_Grayscale8).save(outFile);
      qDebug() << "Image `" << filePath << "` converted to grayscale -> `" << outFile << "`";
    }
}
```

## wxWidgets

```cpp
#include <wx/wx.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/image.h>
#include <wx/stdpaths.h>

class MyApp : public wxApp {
public:
  bool OnInit() override {
    wxInitAllImageHandlers();
    
    for (auto& path : {wxFileName::DirName(wxStandardPaths::Get().GetDocumentsDir()).GetPath() + "/Pictures/base_resources", wxFileName::DirName(wxStandardPaths::Get().GetUserConfigDir()).GetPath() + "/Personal Pictures"}) {
      auto files = wxArrayString {};
      wxDir::GetAllFiles(path, &files, "*.png", wxDIR_FILES | wxDIR_DIRS);
      wxDir::GetAllFiles(path, &files, "*.jpg", wxDIR_FILES | wxDIR_DIRS);
      for (auto& file : files) {
        auto image = wxImage {};
        if (!image.LoadFile(file)) continue;
        auto fileName = wxFileName {file};
        auto outFile = fileName.GetPathWithSep() + fileName.GetName() + "_grayscale." + fileName.GetExt();
        image.ConvertToGreyscale().SaveFile(outFile);
        wxPrintf("Image `%s` converted to grayscale -> `%s`\n", file, outFile);
      }
    }
    
    return false;
  }
};

wxIMPLEMENT_APP(MyApp);
```

## Python (Pillow)

```python
import os
from pathlib import Path
from PIL import Image

for path in [Path.home() / "Pictures" / "base_resources", Path.home() / "Personal Pictures"]:
    for root, _, files in os.walk(path):
        for file in files:
            if file.endswith((".png", ".jpg")):
                full_path = Path(root) / file
                out_file = full_path.with_name(full_path.stem + "_grayscale" + full_path.suffix)
                Image.open(full_path).convert("L").save(out_file)
                print(f"Image `{full_path}` converted to grayscale -> `{out_file}`")
```

## C# 

```csharp
using System;
using System.IO;
using System.Drawing;

class Program {
  static void Main() {
    foreach (var path in new[] { Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyPictures), "base_resources"), Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.UserProfile), "Personal Pictures") })
      foreach (var file in Directory.GetFiles(path, "*.*", SearchOption.AllDirectories)) {
        if (Path.GetExtension(file) != ".png" && Path.GetExtension(file) != ".jpg") continue;
        using (var image = Image.FromFile(file)) {
          var gray = new Bitmap(image.Width, image.Height);
          for (var y = 0; y < image.Height; ++y)
            for (var x = 0; x < image.Width; ++x) {
              var c = ((Bitmap)image).GetPixel(x, y);
              var l = (int)(0.3 * c.R + 0.59 * c.G + 0.11 * c.B);
              gray.SetPixel(x, y, Color.FromArgb(l, l, l));
            }        
          var outFile = Path.Combine(Path.GetDirectoryName(file), Path.GetFileNameWithoutExtension(file) + "_grayscale" + Path.GetExtension(file));
          gray.Save(outFile);
          Console.WriteLine($"Image {file} converted to grayscale -> {outFile}");
        }
      }
  }
}
```

## C# (LINQ)

```csharp
using System;
using System.IO;
using System.Drawing;
using System.Linq;

class Program {
  static void Main() {
    new[] {Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyPictures), "base_resources"), Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.UserProfile), "Personal Pictures")}
      .ToList().ForEach(path => {
        Directory.GetFiles(path, "*.*", SearchOption.AllDirectories)
          .Where(file => Path.GetExtension(file) == ".png" || Path.GetExtension(file) == ".jpg")
          .ToList().ForEach(file => {
            using (var image = Image.FromFile(file)) {
              var gray = new Bitmap(image.Width, image.Height);
              for (var y = 0; y < image.Height; ++y)
                for (var x = 0; x < image.Width; ++x) {
                  var c = ((Bitmap)image).GetPixel(x, y);
                  var l = (int)(0.3 * c.R + 0.59 * c.G + 0.11 * c.B);
                  gray.SetPixel(x, y, Color.FromArgb(l, l, l));
                }
              var outFile = Path.Combine(Path.GetDirectoryName(file), Path.GetFileNameWithoutExtension(file) + "_grayscale" + Path.GetExtension(file));
              gray.Save(outFile);
              Console.WriteLine($"Image {file} converted to grayscale -> {outFile}");
            }
          });
      });
  }
}
```

## Comparison Table

| Language / Framework     | Lines of Code (approx.)  | Style              | Strengths                                      | Weaknesses                            |
|--------------------------|--------------------------|--------------------|------------------------------------------------|---------------------------------------|
| **xtd**                  | 11                       | Modern C++         | Concise, readable, close to .NET API           | Requires xtd libraries                |
| **xtd (linq)**           | 14                       | Declarative / LINQ | Expressive, chainable style, functional flavor | Slightly less familiar to non-C# devs |
| **xtd (linq one-liner)** | 1 (compressed)           | Script-like        | Demonstrates expressive power                  | Not maintainable                      |
| **Qt**                   | 21                       | OOP / Qt idioms    | Mature, rich ecosystem, cross-platform         | Verbose, requires Qt knowledge        |
| **wxWidgets**            | 30                       | OOP                | Portable, integrates with native APIs          | Boilerplate-heavy, dated syntax       |
| **Python (Pillow)**      | 12                       | Scripting          | Very concise, readable, easy for quick tasks   | Slower, requires runtime environment  |
| **C#**                   | 24                       | Imperative         | Strong standard library, familiar to many      | More verbose                          |
| **C# (LINQ)**            | 28                      | Declarative / LINQ | Very expressive, idiomatic in C#               | May be harder to debug                |

## Conclusion

This example illustrates the unique strengths of each language and framework for a common task: converting images to grayscale across multiple folders. While most frameworks and languages, such as Qt, wxWidgets, or C#, require explicit loops and temporary objects, **xtd stands out in C++ for its ability to write concise, expressive, and modern code**, even allowing a **one-liner version** reminiscent of Python scripts.  

This capability is possible thanks to **xtd::linq** and the use of **C++ lambdas**, which combine the power of functional programming with the efficiency and safety of C++. It shows that C++ can be as high-level and readable as Python or C#, without sacrificing performance or control.  

In short, xtd allows C++ developers to write **very compact, readable, and cross-platform code**, something almost unique in the C++ ecosystem.
