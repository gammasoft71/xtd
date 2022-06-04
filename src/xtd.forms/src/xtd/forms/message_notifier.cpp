#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/message_notifier.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../include/xtd/forms/message_notifier.h"
#include <xtd/diagnostics/debug.h>
using namespace xtd;
using namespace xtd::forms;

void message_notifier::show(const iwin32_window& owner)
{
    //TODO: if (notifier_style_ == xtd::forms::notifier_style::system)
    native::message_notifier::show(owner.handle(), title_, message_, icon_, static_cast<uint32_t>(notifier_icon_) + static_cast<uint32_t>(buttons_), close_timeout_enabled_, close_timeout_interval_,
    xtd::delegate<void()>([this]()
    {
        this->on_notifier_closed(notifier_closed_event_args{});
    }));

}

