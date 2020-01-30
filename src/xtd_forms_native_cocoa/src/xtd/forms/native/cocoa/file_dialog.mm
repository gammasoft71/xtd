#if defined(__WXOSX__)
#include <xtd/xtd.strings>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/file_dialog.hpp>
#include <xtd/forms/file_dialog_flags.hpp>
#include <utility>
#include <vector>
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

using namespace xtd;
using namespace xtd::forms::native;

namespace {
  static bool PatternCompare(const std::string& fileName, const std::vector<std::string>& patterns);
  
  static void IgnoreMessages() {
    @autoreleasepool {
      NSEvent *ignoredEvent;
      do
        ignoredEvent = [NSApp nextEventMatchingMask:(NSEventMaskAny & ~NSEventMaskSystemDefined) untilDate:[NSDate dateWithTimeIntervalSinceNow:0] inMode:NSDefaultRunLoopMode dequeue:YES];
      while (ignoredEvent);
    }
  }
}

@interface OpenDelegate : NSObject <NSOpenSavePanelDelegate> {
  NSPopUpButton *popUpButton;
  std::vector<std::pair<std::string, std::vector<std::string>>> filters;
}
- (OpenDelegate*)setPopUpButton:(NSPopUpButton*)popUpButton setFilterPetterns:(const std::vector<std::pair<std::string, std::vector<std::string>>>&)filters;
- (BOOL)panel:(id)sender shouldShowFilename:(NSString *)filename;
- (BOOL)panel:(id)sender shouldEnableURL:(NSURL *)url;
@end

@implementation OpenDelegate
- (OpenDelegate*)setPopUpButton:(NSPopUpButton*)popUp setFilterPetterns:(const std::vector<std::pair<std::string, std::vector<std::string>>>&)fls {
  self->popUpButton = popUp;
  self->filters = fls;
  return self;
}

- (BOOL)panel:(id)sender shouldShowFilename:(NSString *)filename {
  if ( [popUpButton indexOfSelectedItem] == [popUpButton numberOfItems] - 1) return YES;
  BOOL isdir = NO;
  [[NSFileManager defaultManager] fileExistsAtPath:filename isDirectory:&isdir];
  if (isdir) return YES;
  if (PatternCompare([filename fileSystemRepresentation], filters[(int)[popUpButton indexOfSelectedItem]].second)) return YES;
  return NO;
}

- (BOOL)panel:(id)sender shouldEnableURL:(NSURL *)url {
  return [self panel:sender shouldShowFilename:[url path]];
}
@end

@interface ColorPanelCocoa : NSColorPanel {
  bool close;
}
- (BOOL)windowShouldClose:(id)sender;
- (void) show;

@end

@implementation ColorPanelCocoa
- (BOOL)windowShouldClose:(id)sender {
  self->close = true;
  return YES;
}

- (void) show {
  self->close = false;
  do {
    application::do_events();
  } while (self->close == false);
}
@end

@interface FontPanelCocoa : NSFontPanel {
  bool close;
}
- (BOOL)windowShouldClose:(id)sender;
- (void) show;

@end

@implementation FontPanelCocoa
- (BOOL)windowShouldClose:(id)sender {
  self->close = true;
  return YES;
}

- (void) show {
  self->close = false;
  do {
    application::do_events();
  } while (self->close == false);
}
@end

namespace {
  static bool PatternCompare(const std::string& fileName, const std::string& pattern) {
    if (pattern.empty())
      return fileName.empty();

    if (fileName.empty())
      return false;

    if (pattern == "*" || pattern == "*.*")
      return true;

    if (pattern[0] == '*')
      return PatternCompare(fileName, strings::substring(pattern, 1)) || PatternCompare(strings::substring(fileName, 1), pattern);

    return ((pattern[0] == '?') || (fileName[0] == pattern[0])) && PatternCompare(strings::substring(fileName, 1), strings::substring(pattern, 1));
  }

  static bool PatternCompare(const std::string& fileName, const std::vector<std::string>& patterns) {
    for (auto pattern : patterns)
      if (PatternCompare(fileName, pattern))
        return true;
    return false;
  }

  static NSView* CreateFilterViewForFileDialog(NSSavePanel* savePanel, const std::vector<std::pair<std::string, std::vector<std::string>>>& filters, int filterIndex) {
    NSPopUpButton* popUpButton = [[[NSPopUpButton alloc ] initWithFrame:NSMakeRect(62, 0, 256, 30) pullsDown:NO] autorelease];
    for (auto filter : filters)
      [popUpButton addItemWithTitle:[NSString stringWithUTF8String:filter.first.c_str()]];
    [popUpButton setAction:@selector(validateVisibleColumns)];
    [popUpButton setTarget:(NSObject*)savePanel];
    [popUpButton selectItemAtIndex:filterIndex];
    OpenDelegate *openDelegate = [[[OpenDelegate alloc] init] autorelease];
    [openDelegate setPopUpButton:popUpButton setFilterPetterns:filters];
    [(NSOpenPanel*)savePanel setDelegate:openDelegate];

    NSBox* box = [[[NSBox alloc] initWithFrame:NSMakeRect(0, 3, 140, 20 )] autorelease];
    [box setBorderType:NSNoBorder];
    [box setTitle:@"File type:"];
    [box setTitleFont:[NSFont controlContentFontOfSize:NSControlSizeRegular]];
    [box sizeToFit];
    NSPoint boxLocation = [box frame].origin;
    boxLocation.x = [popUpButton frame].origin.x - [box frame].size.width + 15;
    [box setFrameOrigin:boxLocation];

    NSView* view = [[[NSView alloc] initWithFrame:NSMakeRect(5, 5, 350, 30 )] autorelease];
    [view addSubview:box];
    [view addSubview:popUpButton];

    return view;
  }

  std::vector<std::pair<std::string, std::vector<std::string>>> split_filter(const std::string& filter) {
    std::vector<std::string> filter_patterns = strings::split(filter, {'|'});
    std::vector<std::pair<std::string, std::vector<std::string>>> filters;
    if (filter_patterns.size() % 2 != 0) throw std::invalid_argument("Filter bad format");
    for (int32_t index = 0; index < filter_patterns.size(); index += 2)
      filters.push_back({filter_patterns[index], strings::split(filter_patterns[index + 1], {';'})});
    return filters;
  }
}

bool file_dialog::run_open_dialog(intptr_t hwnd, const std::string& default_ext, std::string& file_name, std::vector<std::string>& file_names, const std::string& filter, size_t filter_index, const std::string& initial_directory, size_t options, bool support_multi_dotted_extensions, const std::string& title) {
  NSOpenPanel* openPanel = [[[NSOpenPanel alloc] init] autorelease];
  [openPanel setMessage:[NSString stringWithUTF8String:title.c_str()]];
  [openPanel setCanChooseFiles:YES];
  [openPanel setCanChooseDirectories:NO];
  [openPanel setResolvesAliases:(options & OFN_NODEREFERENCELINKS) != OFN_NODEREFERENCELINKS];
  [openPanel setAllowsMultipleSelection:(options & OFN_ALLOWMULTISELECT) == OFN_ALLOWMULTISELECT];
  [openPanel setShowsHiddenFiles:(options & OFN_FORCESHOWHIDDEN) == OFN_FORCESHOWHIDDEN];
  [openPanel setDirectoryURL:[NSURL fileURLWithPath:[NSString stringWithUTF8String:initial_directory.c_str()]]];
  [openPanel setNameFieldStringValue:[NSString stringWithUTF8String:file_name.c_str()]];
  
  std::vector<std::pair<std::string, std::vector<std::string>>> filters = split_filter(filter);
  if (filters.size() != 0) [openPanel setAccessoryView:CreateFilterViewForFileDialog(openPanel, filters, filter_index - 1)];

  NSModalResponse response = [openPanel runModal];
  IgnoreMessages();
  if (response == NSModalResponseCancel) return false;

  if ((options & OFN_ALLOWMULTISELECT) != OFN_ALLOWMULTISELECT)
    file_name = [[(NSURL*)[[openPanel URLs] objectAtIndex:0] path] UTF8String];
  else{
    NSArray *urls = [openPanel URLs];
    std::vector<std::string> fileNames((int32_t)[urls count]);
    for (int32_t index = 0; index < (int32_t)[urls count]; index++)
      fileNames[index] = [[(NSURL*)[urls objectAtIndex:index] path] UTF8String];
    file_name = fileNames[0];
    file_names = fileNames;
  }
  return true;
}

bool file_dialog::run_save_dialog(intptr_t hwnd, const std::string& default_ext, std::string& file_name, std::vector<std::string>& file_names, const std::string& filter, size_t filter_index, const std::string& initial_directory, size_t options, bool support_multi_dotted_extensions, const std::string& title) {
  NSSavePanel* savePanel = [[[NSSavePanel alloc] init] autorelease];
  [savePanel setMessage:[NSString stringWithUTF8String:title.c_str()]];
  [savePanel setCanCreateDirectories:YES];
  [savePanel setShowsHiddenFiles:(options & OFN_FORCESHOWHIDDEN) == OFN_FORCESHOWHIDDEN];
  [savePanel setDirectoryURL:[NSURL fileURLWithPath:[NSString stringWithUTF8String:initial_directory.c_str()]]];
  [savePanel setNameFieldStringValue:[NSString stringWithUTF8String:file_name.c_str()]];
  std::vector<std::pair<std::string, std::vector<std::string>>> filters = split_filter(filter);
  if (filters.size() != 0) [savePanel setAccessoryView:CreateFilterViewForFileDialog(savePanel, filters, filter_index - 1)];

  NSModalResponse response = [savePanel runModal];
  IgnoreMessages();
  if (response == NSModalResponseCancel) return false;

  file_name = [[[savePanel URL] path] UTF8String];
  return true;
}

#endif
