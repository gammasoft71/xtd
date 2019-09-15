#include <map>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/form.hpp>
#include "wx_form.hpp"
#include <wx/apptrait.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

/*
namespace {
  std::map<intptr_t, wxEventLoopBase*> dialog_event_loops;
}
 */

void form::close(intptr_t form) {
  reinterpret_cast<wx_form*>(form)->control()->Close();
}

int32_t form::show_dialog(intptr_t form) {
  /*
  wxTheApp->SuspendProcessingOfPendingEvents();
  dialog_event_loops[form] = wxTheApp->GetTraits()->CreateEventLoop();
  wxEventLoopBase::SetActive(dialog_event_loops[form]);
  int32_t dialog_result = dialog_event_loops[form]->Run();
  delete dialog_event_loops[form];
  dialog_event_loops.erase(form);
  wxTheApp->ResumeProcessingOfPendingEvents();
  wxEventLoopBase::SetActive(wxTheApp->GetMainLoop());
  return dialog_result;
   */
  return static_cast<wxDialog*>(reinterpret_cast<wx_form*>(form)->control())->ShowModal();
}

void form::end_dialog(intptr_t form, int32_t result) {
  /*
  if (dialog_event_loops.find(form) != dialog_event_loops.end())
    dialog_event_loops[form]->ScheduleExit(result);
   */
  static_cast<wxDialog*>(reinterpret_cast<wx_form*>(form)->control())->EndModal(result);
}
