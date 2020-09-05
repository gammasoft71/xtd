#include <map>
#include <vector>
#include <xtd/drawing/native/pen.h>
#include <wx/colour.h>
#include <wx/pen.h>

class wx_pen : public wxPen {
public:
  wx_pen() = default;
  std::vector<wxDash> dashes;
};

using namespace xtd::drawing::native;

intptr_t pen::create() {
  auto pen = new wx_pen();
  pen->SetCap(wxPenCap::wxCAP_ROUND);
  pen->SetJoin(wxPenJoin::wxJOIN_ROUND);
  return reinterpret_cast<intptr_t>(pen);
}

void pen::color(intptr_t pen, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  reinterpret_cast<wxPen*>(pen)->SetColour(wxColour(r, g, b, a));
}

void pen::dash_pattern(intptr_t pen, std::vector<float> dash_pattern) {
  reinterpret_cast<wx_pen*>(pen)->dashes.clear();
  for (auto dash : dash_pattern)
    reinterpret_cast<wx_pen*>(pen)->dashes.push_back(static_cast<wxDash>(dash));
  reinterpret_cast<wxPen*>(pen)->SetDashes(reinterpret_cast<wx_pen*>(pen)->dashes.size(), reinterpret_cast<wx_pen*>(pen)->dashes.data());
}

void pen::dash_style(intptr_t pen, uint32_t dash_style) {
  reinterpret_cast<wx_pen*>(pen)->SetStyle(wxPENSTYLE_USER_DASH);
  switch (dash_style) {
    case 0: reinterpret_cast<wx_pen*>(pen)->dashes = {1}; break;
    case 1: reinterpret_cast<wx_pen*>(pen)->dashes = {3, 2}; break;
    case 2: reinterpret_cast<wx_pen*>(pen)->dashes = {1, 1}; break;
    case 3: reinterpret_cast<wx_pen*>(pen)->dashes = {3, 1, 1, 1}; break;
    case 4: reinterpret_cast<wx_pen*>(pen)->dashes = {3, 1, 1, 1, 1, 1}; break;
    default: break;
  }
  reinterpret_cast<wxPen*>(pen)->SetDashes(reinterpret_cast<wx_pen*>(pen)->dashes.size(), reinterpret_cast<wx_pen*>(pen)->dashes.data());
}

void pen::width(intptr_t pen, float width) {
  reinterpret_cast<wxPen*>(pen)->SetWidth(static_cast<int>(width));
}

void pen::destroy(intptr_t pen) {
  delete reinterpret_cast<wx_pen*>(pen);
}
