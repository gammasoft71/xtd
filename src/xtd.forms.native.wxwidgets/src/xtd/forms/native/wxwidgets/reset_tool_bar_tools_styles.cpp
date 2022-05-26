// Workaround : When wxWidgets destroy the tool bar tool with a control or drop down menu, it destroy the control and the drop down menu. But with xtd, the control and the drop down menu are managed by xtd and they can be destroyed.
// To prevent destroy control and drop down menu change the tool bar tool style to wxTOOL_STYLE_BUTTON et set drop down menu to null...

#include <wx/toolbar.h>

// We need to access the private members of the wxToolBarToolBase class.
// See https://stackoverflow.com/questions/424104/can-i-access-private-members-from-outside-the-class-without-using-friends for more info.

namespace {
  struct wxToolBarToolBase_dropdownMenu {
    typedef wxMenu* wxToolBarToolBase::* type;
    friend type get(wxToolBarToolBase_dropdownMenu);
  };

  struct wxToolBarToolBase_toolStyle {
    typedef wxToolBarToolStyle wxToolBarToolBase::* type;
    friend type get(wxToolBarToolBase_toolStyle);
  };

  template<typename Tag, typename Tag::type M>
  struct robbery {
    friend typename Tag::type get(Tag) {
      return M;
    }
  };

  template struct robbery<wxToolBarToolBase_dropdownMenu, &wxToolBarToolBase::m_dropdownMenu>;
  template struct robbery<wxToolBarToolBase_toolStyle, &wxToolBarToolBase::m_toolStyle>;
}

void __reset_tool_bar_tools_styles__(wxToolBar* toolBar) {
  for (size_t index = 0; index < toolBar->GetToolsCount(); ++index) {
    auto wx_tool_bar_tool = toolBar->GetToolByPos(static_cast<int32_t>(index));
    wx_tool_bar_tool->*get(wxToolBarToolBase_dropdownMenu()) = nullptr;
    wx_tool_bar_tool->*get(wxToolBarToolBase_toolStyle()) = wxTOOL_STYLE_BUTTON;
  }
}

// end Workaround
