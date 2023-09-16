#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include <cmath>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/graphics.h>
#include <xtd/types.h>

class wxConicalGradient {
public:
  static wxBitmap CreateBitmap(const wxSize& size, const wxGraphicsGradientStops& gradientStops, const wxPoint& center, float offset) noexcept {
    wxImage image(size.GetWidth(), size.GetHeight());
    image.InitAlpha();
    for (xtd::int32 y = 0; y < size.GetHeight(); y++)
      for (xtd::int32 x = 0; x < size.GetWidth(); x++)
        image.SetAlpha(x, y, 0);
    wxBitmap bitmap(image);
    auto dc = wxMemoryDC(bitmap);
    auto graphics = wxGraphicsContext::Create(dc);
    auto radius = static_cast<double>(std::max(size.GetWidth(), size.GetHeight())) * std::sqrt(2);
    auto length = 2 * PI * radius;
    SetColor(graphics, size, gradientStops, offset, length, center);
    SetAlpha(bitmap, size, gradientStops, offset, length, center);
    return bitmap;
  }
  
private:
  wxConicalGradient() = delete;
  
  static constexpr double PI = 3.14159265358979323846;
  
  static double DegreesToRadians(double degrees) noexcept {
    return degrees * (PI / 180);
  }
  
  static xtd::byte Alpha(float angle, float startAngle, float endAngle, const wxColour& startColor, const wxColor& endColor) noexcept {
    auto percent = (angle - startAngle) / (endAngle - startAngle);
    return LerpAlpha(startColor, endColor, percent);
  }
  
  static wxColour Color(float angle, float startAngle, float endAngle, const wxColour& startColor, const wxColor& endColor) noexcept {
    auto percent = (angle - startAngle) / (endAngle - startAngle);
    return LerpColor(startColor, endColor, percent);
  }
  
  static void SetAlpha(wxBitmap& bitmap, const wxSize& size, const wxGraphicsGradientStops& gradientStops, float offset, double length, const wxPoint& center) noexcept {
    wxImage image = bitmap.ConvertToImage();
    for (auto index = 0u; index < gradientStops.GetCount() - 1; ++index) {
      auto startColor = gradientStops.Item(index).GetColour();
      auto endColor = gradientStops.Item(index + 1).GetColour();
      auto startAngle = offset + gradientStops.Item(index).GetPosition() * 360.0;
      auto endAngle = offset + gradientStops.Item(index + 1).GetPosition() * 360.0;
      for (auto angle = startAngle; angle < endAngle; angle += 360.0 / length) {
        auto alpha = Alpha(angle, startAngle, endAngle, startColor, endColor);
        auto point = GetPointForAngle(angle, size, center);
        for (auto p : GetPointsOnLine(center.x, center.y, point.x, point.y)) {
          if (p.x >= 0 && p.x < size.GetWidth() && p.y >= 0 && p.y < size.GetHeight())
            image.SetAlpha(p.x, p.y, alpha);
        }
      }
    }
    bitmap = image;
  }
  
  static void SetColor(wxGraphicsContext* graphics, const wxSize& size, const wxGraphicsGradientStops& gradientStops, float offset, double length, const wxPoint& center) noexcept {
    for (auto index = 0u; index < gradientStops.GetCount() - 1; ++index) {
      auto startColor = gradientStops.Item(index).GetColour();
      auto endColor = gradientStops.Item(index + 1).GetColour();
      auto startAngle = offset + gradientStops.Item(index).GetPosition() * 360.0;
      auto endAngle = offset + gradientStops.Item(index + 1).GetPosition() * 360.0;
      for (auto angle = startAngle; angle < endAngle; angle += 360.0 / length) {
        auto path = graphics->CreatePath();
        wxPen pen(wxColour(Color(angle, startAngle, endAngle, startColor, endColor)));
        pen.SetCap(wxPenCap::wxCAP_BUTT);
        graphics->SetPen(graphics->CreatePen(pen));
        auto point = GetPointForAngle(angle, size, center);
        graphics->StrokeLine(center.x, center.y, point.x, point.y);
      }
    }
  }
  
  static wxColour LerpColor(const wxColour& startColor, const wxColour& endColor, float percent) noexcept {
    auto red = static_cast<float>(startColor.Red()) + percent * (endColor.Red() - startColor.Red());
    auto green = static_cast<float>(startColor.Green()) + percent * (endColor.Green() - startColor.Green());
    auto blue = static_cast<float>(startColor.Blue()) + percent * (endColor.Blue() - startColor.Blue());
    return wxColour(red, green, blue);
  }
  
  static xtd::byte LerpAlpha(const wxColour& startColor, const wxColour& endColor, float percent) noexcept {
    return static_cast<xtd::byte>(static_cast<float>(startColor.Alpha()) + percent * (endColor.Alpha() - startColor.Alpha()));
  }
  
  static wxPoint GetPointForAngle(double angle, const wxSize& size, const wxPoint& center) noexcept {
    auto longerSide = std::max(size.GetWidth(), size.GetHeight());
    auto radius = static_cast<double>(longerSide) * std::sqrt(2);
    auto rad = DegreesToRadians(angle);
    auto x = center.x + radius * std::cos(rad);
    auto y = center.y + radius * std::sin(rad);
    return {static_cast<xtd::int32>(x), static_cast<xtd::int32>(y)};
  }
  
  static std::vector<wxPoint> GetPointsOnLine(xtd::int32 x0, xtd::int32 y0, xtd::int32 x1, xtd::int32 y1) noexcept {
    bool steep = std::abs(y1 - y0) > std::abs(x1 - x0);
    if (steep) {
      std::swap(x0, y0);
      std::swap(x1, y1);
    }
    if (x0 > x1) {
      std::swap(x0, x1);
      std::swap(y0, y1);
    }
    xtd::int32 dx = x1 - x0;
    xtd::int32 dy = std::abs(y1 - y0);
    xtd::int32 error = dx / 2;
    xtd::int32 ystep = (y0 < y1) ? 1 : -1;
    xtd::int32 y = y0;
    std::vector<wxPoint> points;
    for (xtd::int32 x = x0; x <= x1; x++) {
      points.push_back(wxPoint((steep ? y : x), (steep ? x : y)));
      error = error - dy;
      if (error < 0) {
        y += ystep;
        error += dx;
      }
    }
    return points;
  }
};

/// The original code for Conical gradient :
/// https://github.com/ekubyshin/conicalGradient
///
/// @code
/// import UIKit
///
/// class ConicalGradient: UIView {
///   override func draw(_ rect: CGRect) {
///     let beginColor = UIColor.red
///     let endColor = UIColor.yellow
///     let center = CGPoint(x: rect.midX, y: rect.midY)
///     let longerSide = max(rect.width, rect.height)
///     let radius = Double(longerSide) * 2.squareRoot()
///     let length = 2 * .pi * radius
///     let step = 360 / length
///     var angle = 0.0
///     while angle <= 360 {
///       let line = UIBezierPath(rect: CGRect.zero)
///       line.move(to: center)
///       let nextCords = coordsForAngel(CGFloat(angle), in: rect)
///       let color = self.color(for: CGFloat(angle), from: beginColor, to: endColor)
///       color.setStroke()
///       line.addLine(to: CGPoint(x: nextCords.0, y: nextCords.1))
///       line.stroke()
///       angle += step
///     }
///   }
///   func coordsForAngel(_ angle: CGFloat, in rect: CGRect) -> (CGFloat, CGFloat) {
///     let longerSide = max(rect.width, rect.height)
///     let radius = longerSide * CGFloat(2.squareRoot())
///     let x0 = rect.midX
///     let y0 = rect.midY
///     let rad = Measurement(value: Double(angle), unit: UnitAngle.degrees).converted(to: UnitAngle.radians).value
///     let x = x0 + radius * CGFloat(cos(rad))
///     let y = y0 + radius * CGFloat(sin(rad))
///     return (x, y)
///   }
///   func color(for angle: CGFloat, from: UIColor, to: UIColor) -> UIColor {
///     let percent = angle / 360
///     return UIColor.lerp(from: from.rgba, to: to.rgba, percent: percent)
///   }
/// }
///
/// private extension UIColor {
///   struct RGBA {
///     var red: CGFloat = 0.0
///     var green: CGFloat = 0.0
///     var blue: CGFloat = 0.0
///     var alpha: CGFloat = 0.0
///
///     init(color: UIColor) {
///       color.getRed(&red, green: &green, blue: &blue, alpha: &alpha)
///     }
///   }
///
///   var rgba: RGBA {
///     return RGBA(color: self)
///   }
///
/// class func lerp(from: RGBA, to: RGBA, percent: CGFloat) -> UIColor {
///     let red = from.red + percent * (to.red - from.red)
///     let green = from.green + percent * (to.green - from.green)
///     let blue = from.blue + percent * (to.blue - from.blue)
///     let alpha = from.alpha + percent * (to.alpha - from.alpha)
///     return UIColor(red: red, green: green, blue: blue, alpha: alpha)
///   }
/// }
///
/// class ViewController: UIViewController {
///   override func viewDidLoad() {
///     super.viewDidLoad()
///     // Do any additional setup after loading the view, typically from a nib.
///   }
///   override func viewDidAppear(_ animated: Bool) {
///     super.viewDidAppear(animated)
///     let size: CGFloat = 400
///     let v = ConicalGradient(frame: CGRect(x: view.frame.midX - size / 2, y: view.frame.midY - size / 2, width: size, height: size))
///     view.addSubview(v)
///   }
///
/// }
///
/// @endcode
/// The original code for GetPointsOnLine function :
///  http://ericw.ca/notes/bresenhams-line-algorithm-in-csharp.html
///
/// @code
/// public static IEnumerable<Point> GetPointsOnLine(xtd::int32 x0, xtd::int32 y0, xtd::int32 x1, xtd::int32 y1)
/// {
///   bool steep = Math.Abs(y1 - y0) > Math.Abs(x1 - x0);
///   if (steep)
///   {
///     xtd::int32 t;
///     t = x0; // swap x0 and y0
///     x0 = y0;
///     y0 = t;
///     t = x1; // swap x1 and y1
///     x1 = y1;
///     y1 = t;
///   }
///   if (x0 > x1)
///   {
///     xtd::int32 t;
///     t = x0; // swap x0 and x1
///     x0 = x1;
///     x1 = t;
///     t = y0; // swap y0 and y1
///     y0 = y1;
///     y1 = t;
///   }
///   xtd::int32 dx = x1 - x0;
///   xtd::int32 dy = Math.Abs(y1 - y0);
///   xtd::int32 error = dx / 2;
///   xtd::int32 ystep = (y0 < y1) ? 1 : -1;
///   xtd::int32 y = y0;
///   for (xtd::int32 x = x0; x <= x1; x++)
///   {
///     yield return new Point((steep ? y : x), (steep ? x : y));
///     error = error - dy;
///     if (error < 0)
///     {
///       y += ystep;
///       error += dx;
///     }
///   }
///   yield break;
/// }
/// @encode
