# Wiggly 

## FLTK

* Wiggly.cpp

```cp
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/fl_draw.H>
#include <string>
#include <array>
#include <cmath>

class Wiggly_Widget : public Fl_Widget {
public:
  Wiggly_Widget(int x, int y, int width, int height) : Fl_Widget(x, y, width, height) {
    Fl::add_timeout(0.06, TimerCallback, this);
  }
  
  auto set_text(const std::string& t) -> void {
    text_ = t;
    redraw();
  }
  
private:
  static auto TimerCallback(void* widget) -> void {
    static_cast<Wiggly_Widget*>(widget)->step_++;
    static_cast<Wiggly_Widget*>(widget)->redraw();
    Fl::repeat_timeout(0.06, TimerCallback, widget);
  }
  
  auto draw() -> void override {
    static constexpr auto sins = std::array {0, 38, 71, 92, 100, 92, 71, 38, 0, -38, -71, -92, -100, -92, -71, -38};
    
    fl_color(color());
    fl_rectf(x(), y(), w(), h());
    
    fl_font(FL_HELVETICA, 24);
    
    auto text_w = 0, text_h = 0;
    fl_measure(text_.c_str(), text_w, text_h, false);
    
    auto pos_x = x() + (w() - text_w) / 2;
    auto pos_y = y() + (h() + text_h / 2) / 2;
    
    for (auto i = 0z; i < text_.size(); ++i) {
      auto index = (step_ + i) % sins.size();
      
      auto [r, g, b] = hsv_to_rgb(static_cast<double>(index) / sins.size(), 1.0, 0.75);
      fl_color(fl_rgb_color(r, g, b));
      
      auto ch = std::array {text_[i], '\0'};
      auto cw = 0, chh = 0;
      fl_measure(ch.data(), cw, chh, false);
      
      fl_draw(ch.data(), pos_x, pos_y - (sins[index] * chh) / 400);
      pos_x += cw;
    }
  }
  
  auto hsv_to_rgb(double h, double s, double v) -> std::tuple<std::uint8_t, std::uint8_t, std::uint8_t> {
    if (s == 0.0) return {};

    h = std::fmod(h, 1.0);
    if (h < 0) h += 1.0;
    auto hf = h * 6.0;
    auto i = static_cast<int>(std::floor(hf));
    auto f = hf - i;
    auto p = v * (1.0 - s);
    auto q = v * (1.0 - s * f);
    auto t = v * (1.0 - s * (1.0 - f));
    
    auto r = 0.0, g = 0.0, b = 0.0;
    switch (i) {
      case 0: r = v; g = t; b = p; break;
      case 1: r = q; g = v; b = p; break;
      case 2: r = p; g = v; b = t; break;
      case 3: r = p; g = q; b = v; break;
      case 4: r = t; g = p; b = v; break;
      default: r = v; g = p; b = q; break;
    }
    return std::make_tuple(static_cast<std::uint8_t>(r * 255), static_cast<std::uint8_t>(g * 255), static_cast<std::uint8_t>(b * 255));
  }

  std::string text_;
  int step_ = 0;
};

class MainWindow : public Fl_Window {
public:
  MainWindow() : Fl_Window(330, 130, "Wiggly") {
    input.when(FL_WHEN_CHANGED);
    input.callback([](Fl_Widget* sender, void* window) {
      static_cast<MainWindow*>(window)->wiggly.set_text(static_cast<Fl_Input*>(sender)->value());
    }, this);
    input.value("Habemus papam");
    input.do_callback(&input, this, FL_REASON_CHANGED);
    end();
  }
  
private:
  Wiggly_Widget wiggly {20, 20, 290, 60};
  Fl_Input input {20, 90, 290, 25};
};

auto main() -> int {
  auto win = MainWindow {};
  win.show();
  return Fl::run();
}
```

## Qt

* Wiggly.h

```cpp
#pragma once
#include <QBasicTimer>
#include <QFrame>
#include <QLineEdit>
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QVBoxLayout>

namespace WigglyExamples {
  class WigglyWidget : public QWidget {
    Q_OBJECT
  public:
    WigglyWidget(QWidget *parent = nullptr) : QWidget(parent) {
      setBackgroundRole(QPalette::Midlight);
      setAutoFillBackground(true);

      auto newFont = font();
      newFont.setPointSize(newFont.pointSize() + 20);
      setFont(newFont);

      timer.start(60, this);
    }

public slots:
    auto setText(const QString &newText) -> void {text = newText;}

protected:
    auto paintEvent(QPaintEvent* event) -> void override {
      static const std::vector<int> sins = {0, 38, 71, 92, 100, 92, 71, 38, 0, -38, -71, -92, -100, -92, -71, -38};
      QFontMetrics metrics(font());
      auto pos = QPoint {(event->rect().width() - metrics.horizontalAdvance(text)) / 2, (event->rect().height() + metrics.ascent() - metrics.descent()) / 2};
      QPainter painter(this);
      for (auto i = 0; i < text.size(); ++i) {
        auto index = (step + i) % sins.size();
        painter.setPen(QColor::fromHsv(360.0f / sins.size() * index, 255, 191));
        painter.drawText(pos - QPoint {0, (sins[index] * metrics.height()) / 400}, QString(text[i]));
        pos.setX(pos.x() + metrics.horizontalAdvance(text[i]));
      }
    }

    auto timerEvent(QTimerEvent* event) -> void override {
      if (event->timerId() != timer.timerId()) QWidget::timerEvent(event);
      else {
        ++step;
        update();
      }
    }

private:
    QBasicTimer timer;
    QString text;
    int step = 0;
  };

  class Window1 : public QMainWindow {
    Q_OBJECT
  public:
    Window1() {
      setCentralWidget(&frame);
      setWindowTitle("Wiggly");
      resize(330, 130);
      connect(&lineEdit, &QLineEdit::textChanged, &wigglyWidget, &WigglyWidget::setText);

      wigglyWidget.setGeometry(20, 20, 290, 60);

      layout.addWidget(&wigglyWidget);
      layout.addWidget(&lineEdit);
      lineEdit.move(20, 90);
      lineEdit.setGeometry(20, 90, 290, lineEdit.height());
      lineEdit.setText("Habemus papam");
    }

  private:
    QFrame frame;
    QVBoxLayout layout {&frame};
    WigglyWidget wigglyWidget;
    QLineEdit lineEdit;
  };
}
```

* Wiggly.cpp

```cpp
#include <QApplication>
#include "Wiggly.h"

auto main(int argc, char* argv[]) -> int {
  auto application = QApplication {argc, argv};
  auto window1 = WigglyExamples::Window1 {};
  window1.show();
  return application.exec();
}
```

## wxWidgets

* Wiggly.cpp

```cpp
#pragma once
#include <wx/wx.h>
#include <wx/image.h>
#include <wx/timer.h>

namespace wxWiggly {
  class WigglyWidget : public wxPanel {
  public:
    WigglyWidget(wxWindow* parent) : wxPanel {parent} {
      SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
      
      auto f = GetFont();
      f.SetPointSize(f.GetPointSize() + 12);
      SetFont(f);
      
      Bind(wxEVT_PAINT, &WigglyWidget::OnPaint, this);
      Bind(wxEVT_TIMER, &WigglyWidget::OnTimer, this);
      
      timer.Start(60);
    }
    
    auto SetText(const wxString& t) -> void {
      text = t;
      Refresh();
    }
    
  private:
    auto OnPaint(wxPaintEvent&) -> void {
      static constexpr auto sins = std::array {0, 38, 71, 92, 100, 92, 71, 38, 0, -38, -71, -92, -100, -92, -71, -38};
      
      auto dc = wxPaintDC {this};
      dc.SetFont(GetFont());
      
      auto size = GetClientSize();
      auto textSize = dc.GetTextExtent(text);
      
      auto pos = wxPoint {(size.x - textSize.x) / 2, (size.y - textSize.y) / 2};
      
      for (auto i = 0z; i < text.size(); ++i) {
        auto index = (step + i) % sins.size();
        auto rgb = wxImage::HSVtoRGB(wxImage::HSVValue {static_cast<double>(index) / sins.size(), 1.0, 0.75});
        auto color = wxColour {rgb.red, rgb.green, rgb.blue};
        dc.SetTextForeground(color);
        
        auto ch = text.Mid(i, 1);
        auto charSize = dc.GetTextExtent(ch);
        dc.DrawText(ch, pos.x, pos.y - (sins[index] * charSize.y) / 400);
        pos.x += charSize.x;
      }
    }
    
    auto OnTimer(wxTimerEvent&) -> void {
      step++;
      Refresh();
    }
    
    wxTimer timer {this};
    wxString text = "Habemus papam";
    int step = 0;
  };
  
  class Frame1 : public wxFrame {
  public:
    Frame1() : wxFrame(nullptr, wxID_ANY, "Wiggly") {
      SetClientSize(330, 130);
      auto panel = new wxPanel(this);
      wiggly = new WigglyWidget(panel);
      textBox = new wxTextCtrl(panel, wxID_ANY, "Habemus papam");
      
      auto vbox = new wxBoxSizer(wxVERTICAL);
      vbox->Add(wiggly, 1, wxEXPAND | wxALL, 10);
      vbox->Add(textBox, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 10);
      panel->SetSizer(vbox);
      
      textBox->Bind(wxEVT_TEXT, &Frame1::OnTextChanged, this);
    }
    
  private:
    auto OnTextChanged(wxCommandEvent& evt) -> void {wiggly->SetText(evt.GetString());}
    
    WigglyWidget* wiggly;
    wxTextCtrl* textBox;
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame1())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(wxWiggly::Application);
```

## xtd

* wiggly.cpp

```cpp
#include <xtd/xtd>

namespace wiggly_example {
  class wiggly : public user_control {
  public:
    wiggly() {
      back_color(system_colors::window());
      font({font(), font().size() + 12});
      timer.interval(60_ms);
      timer.tick += [&] {
        step++;
        invalidate();
      };
      timer.enabled(true);
    }
    
  protected:
    auto on_paint(paint_event_args& e) -> void override {
      static const auto sins = array {0, 38, 71, 92, 100, 92, 71, 38, 0, -38, -71, -92, -100, -92, -71, -38};
      auto pos = point {(e.clip_rectangle().size().width - as<int>(e.graphics().measure_string(text(), font()).width)) / 2, (e.clip_rectangle().size().height - as<int>(e.graphics().measure_string(text(), font()).height)) / 2};
      auto wiggly_text = text().to_u32string();
      for (auto i = 0_z; i < wiggly_text.length(); i++) {
        auto index = (step + i) % sins.length();
        e.graphics().draw_string(string::format("{}", wiggly_text[i]), font(), solid_brush {color::from_hsb(360.0f / sins.length() * index, 1.0f, 0.75f)}, point::subtract(pos, point(0, sins[index] * font().height() / 400)));
        pos.x = pos.x + as<int>(e.graphics().measure_string(string::format("{}", wiggly_text[i]), font()).width);
      }
    }
    
  private:
    forms::timer timer;
    int step = 0;
  };
}
  
auto main() -> int {
  auto main_form = form::create("Wiggly");
  main_form.client_size({330, 130});
  
  auto wiggly = control::create<wiggly_example::wiggly>(main_form, "Habemus papam", {20, 20}, {290, 60});
  wiggly.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::right | anchor_styles::bottom);

  auto text_box = forms::text_box::create(main_form, wiggly.text(), {20, 90}, {290, 25});
  text_box.anchor(anchor_styles::left | anchor_styles::bottom | anchor_styles::right)
    .text_changed += [&] {wiggly.text(text_box.text());};
  text_box.focus();

  application::run(main_form);
}
```
