#include <map>
#include <vector>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/graphics_path.h>
#include <xtd/drawing/native/toolkit.h>
#include "../../../../../include/xtd/drawing/native/hdc_wrapper.h"
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <wx/graphics.h>
#include <xtd/as.h>
#include <xtd/math.h>
#include <xtd/static.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing::native;

namespace {
  class figures static_ {
  public:
    static void close_figure(wxGraphicsPath* path) {
      auto it = figures_.find(path);
      if (it != figures_.end()) {
        path->CloseSubpath();
        it->second.erase(it->second.begin() + it->second.size() - 1);
      }
    }
    
    static void close_all_figure(wxGraphicsPath* path) {
      auto it = figures_.find(path);
      if (it != figures_.end()) {
        path->CloseSubpath();
        figures_.erase(it);
      }
    }
    
    static void new_figure(wxGraphicsPath* path) noexcept {
      figures_[path].push_back(false);
    }
    
    static void start(wxGraphicsPath* path, double current_point_x, double current_point_y) {
      start(path, wxPoint2DDouble(current_point_x, current_point_y));
    }
    
    static void start(wxGraphicsPath* path, const wxPoint2DDouble& current_point) {
      auto it = figures_.find(path);
      if (it != figures_.end()) {
        if (it->second[it->second.size() - 1]) return;
        path->MoveToPoint(current_point.m_x, current_point.m_y);
        it->second[it->second.size() - 1] = true;
      }
    }
    
    static void start(wxGraphicsPath* path) {
      start(path, path->GetCurrentPoint());
    }
    
  private:
    inline static std::map<wxGraphicsPath*, vector<bool>> figures_;
  };
}

intptr graphics_path::create() {
  toolkit::initialize(); // Must be first
  static wxBitmap bmp(1, 1);
  wxMemoryDC mdc(bmp);
  wxGraphicsContext* mgc = wxGraphicsContext::Create(mdc);
  auto path = new wxGraphicsPath(mgc->CreatePath());
  figures::new_figure(path);
  return reinterpret_cast<intptr>(path);
}

void graphics_path::destroy(intptr handle) {
  if (!handle) return;
  figures::close_all_figure(reinterpret_cast<wxGraphicsPath*>(handle));
  delete reinterpret_cast<wxGraphicsPath*>(handle);
}

void graphics_path::add_arc(intptr handle, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!handle) return;
  figures::start(reinterpret_cast<wxGraphicsPath*>(handle), x, y);
  reinterpret_cast<wxGraphicsPath*>(handle)->AddArc(x + width / 2, y + height / 2, math::max(width, height) / 2, math::degrees_to_radians(start_angle), math::degrees_to_radians(start_angle + sweep_angle), true);
}

void graphics_path::add_bezier(intptr handle, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
  if (!handle) return;
  figures::start(reinterpret_cast<wxGraphicsPath*>(handle), x1, y1);
  reinterpret_cast<wxGraphicsPath*>(handle)->AddLineToPoint(x1, y1);
  reinterpret_cast<wxGraphicsPath*>(handle)->AddCurveToPoint(x2, y2, x3, y3, x4, y4);
}

void graphics_path::add_beziers(intptr handle, std::vector<std::pair<float, float>> points) {
  if (!handle) return;
  figures::start(reinterpret_cast<wxGraphicsPath*>(handle), points[0].first, points[0].second);
  reinterpret_cast<wxGraphicsPath*>(handle)->AddLineToPoint(points[0].first, points[0].second);
  for (auto index = 1_sz; points.size(); index += 3)
    reinterpret_cast<wxGraphicsPath*>(handle)->AddCurveToPoint(points[index].first, points[index].second, points[index + 1].first, points[index + 1].second, points[index + 2].first, points[index + 2].second);
}

void graphics_path::add_closed_curve(intptr handle, std::vector<std::pair<float, float>> points, float tension) {
  if (!handle) return;
  // Not supported by wxWidgets 3.1.5...
}

void graphics_path::add_curve(intptr handle, std::vector<std::pair<float, float>> points, size_t offset, size_t number_of_segments, float tension) {
  if (!handle) return;
  // Not supported by wxWidgets 3.1.5...
}

void graphics_path::add_line(intptr handle, float x1, float y1, float x2, float y2) {
  if (!handle) return;
  figures::start(reinterpret_cast<wxGraphicsPath*>(handle), x1, y1);
  reinterpret_cast<wxGraphicsPath*>(handle)->AddLineToPoint(x1, y1);
  reinterpret_cast<wxGraphicsPath*>(handle)->AddLineToPoint(x2, y2);
}

void graphics_path::add_ellipse(intptr handle, float x, float y, float width, float height) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsPath*>(handle)->AddEllipse(x, y, width, height);
}

void graphics_path::add_path(intptr handle, intptr path, bool connect) {
  if (!handle || !path) return;
  if (connect) {
    auto path_box = reinterpret_cast<wxGraphicsPath*>(path)->GetBox();
    figures::start(reinterpret_cast<wxGraphicsPath*>(handle), path_box.m_x, path_box.m_y);
  }
  reinterpret_cast<wxGraphicsPath*>(handle)->AddPath(*reinterpret_cast<wxGraphicsPath*>(path));
}

void graphics_path::add_pie(intptr handle, float x, float y, float width, float height, float start_angle, float sweep_angle) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsPath*>(handle)->MoveToPoint(x + (width / 2), y + (height / 2));
  reinterpret_cast<wxGraphicsPath*>(handle)->AddArc(x + (width / 2), y + (height / 2), math::max(width, height) / 2, math::degrees_to_radians(start_angle), math::degrees_to_radians(start_angle + sweep_angle), true);
  reinterpret_cast<wxGraphicsPath*>(handle)->AddLineToPoint(x + (width / 2), y + (height / 2));
}

void graphics_path::add_rectangle(intptr handle, float x, float y, float width, float height) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsPath*>(handle)->AddRectangle(x, y, width, height);
}

void graphics_path::add_rounded_rectangle(intptr handle, float x, float y, float width, float height, float radius) {
  if (!handle) return;
  reinterpret_cast<wxGraphicsPath*>(handle)->AddRoundedRectangle(x, y, width, height, radius);
}

void graphics_path::add_string(intptr handle, const xtd::ustring& text, intptr font, float x, float y, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming) {
  if (!handle) return;
  // Not supported by wxWidgets 3.1.5...
}

void graphics_path::add_string(intptr handle, const xtd::ustring& text, intptr font, float x, float y, float w, float h, int32 alignment, int32 line_alignment, int32 hot_key_prefix, int32 trimming) {
  if (!handle) return;
  // Not supported by wxWidgets 3.1.5...
}

void graphics_path::close_all_figures(intptr handle) {
  if (!handle) return;
  figures::close_all_figure(reinterpret_cast<wxGraphicsPath*>(handle));
}

void graphics_path::close_figure(intptr handle) {
  if (!handle) return;
  figures::close_figure(reinterpret_cast<wxGraphicsPath*>(handle));
}

void graphics_path::flatten(intptr handle) {
  // Not supported by wxWidgets 3.1.5...
  if (!handle) return;
}

void graphics_path::reverse(intptr handle) {
  if (!handle) return;
  // Not supported by wxWidgets 3.1.5...
}

void graphics_path::start_figure(intptr handle) {
  if (!handle) return;
  figures::new_figure(reinterpret_cast<wxGraphicsPath*>(handle));
  figures::start(reinterpret_cast<wxGraphicsPath*>(handle));
}

void graphics_path::get_bounds(intptr handle, float& x, float& y, float& width, float& height) {
  if (!handle) return;
  double wx_x, wx_y, wx_width, wx_height;
  reinterpret_cast<wxGraphicsPath*>(handle)->GetBox(&wx_x, &wx_y, &wx_width, &wx_height);
  x = as<float>(wx_x);
  y = as<float>(wx_y);
  width = as<float>(wx_width);
  height = as<float>(wx_height);
}

void graphics_path::get_last_point(intptr handle, float& x, float& y) {
  if (!handle) return;
  auto point = reinterpret_cast<wxGraphicsPath*>(handle)->GetCurrentPoint();
  x = static_cast<float>(point.m_x);
  y = static_cast<float>(point.m_y);
}

bool graphics_path::is_vsible(intptr handle, float x, float y) {
  if (!handle) return false;
  return reinterpret_cast<wxGraphicsPath*>(handle)->Contains(x, y);
}
