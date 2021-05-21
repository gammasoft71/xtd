#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/tab_page.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_tab_page.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

void tab_page::image_index(intptr_t control, size_t image_index) {
  if (control == 0) return;
  auto page = static_cast<wxNotebookPage*>(reinterpret_cast<control_handler*>(control)->control());
  auto note_book = static_cast<wxNotebookBase*>(page->GetParent());
  if (note_book) note_book->SetPageImage(note_book->FindPage(page), image_index);
}

void tab_page::text(intptr_t control, const std::string& text) {
  if (control == 0) return;
  auto page = static_cast<wxNotebookPage*>(reinterpret_cast<control_handler*>(control)->control());
  auto note_book = static_cast<wxNotebookBase*>(page->GetParent());
  if (note_book) note_book->SetPageText(note_book->FindPage(page), {text.c_str(), wxMBConvUTF8()});
}
