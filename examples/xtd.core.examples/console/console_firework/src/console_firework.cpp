#include <xtd/console>
#include <xtd/is>
#include <xtd/random>
#include <xtd/startup>
#include <memory>
#include <vector>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace xtd;

namespace console_firework_example {
  class firework abstract_ {
  public:
    firework(int x, int y, console_color color, int delay_) : x_(x), y_(y), color_(color), delay_(delay_) {}
    firework(const firework& firework) : x_(firework.x_), y_(firework.y_), color_(firework.color_), delay_(firework.delay_) {}
    
    int delay() {return delay_;}
    
    virtual void paint() const = 0;
    
  protected:
    static void write(int x, int y, const ustring& str) {
      console::set_cursor_position(x, y);
      console::write(str);
    }
    
    int x_ = 0;
    int y_ = 0;
    console_color color_ = console_color::black;
    int delay_ = 0;
  };
  
  class firework_start : public firework {
  public:
    firework_start(int x, int y, console_color color, int speed) : console_firework_example::firework(x, y, color, speed) {}
    explicit firework_start(const firework& firework) : console_firework_example::firework(firework) {}
    
    void paint() const override {
      console::foreground_color(color_);
      write(x_, y_, "+");
    }
  };
  
  class firework_exploded : public firework {
  public:
    firework_exploded(int x, int y, console_color color, int speed) : console_firework_example::firework(x, y, color, speed) {}
    explicit firework_exploded(const firework& firework) : console_firework_example::firework(firework) {}
    
    void paint() const override {
      console::foreground_color(color_);
      write(x_ - 1, y_ - 1, " - ");
      write(x_ - 1, y_, "-+-");
      write(x_ - 1, y_ + 1, " - ");
    }
  };
  
  class firework_start_expanded1 : public firework {
  public:
    firework_start_expanded1(int x, int y, console_color color, int speed) : console_firework_example::firework(x, y, color, speed) {}
    explicit firework_start_expanded1(const firework& firework) : console_firework_example::firework(firework) {}
    
    void paint() const override {
      console::foreground_color(color_);
      write(x_ - 2, y_ - 2, " --- ");
      write(x_ - 2, y_ - 1, "-+++-");
      write(x_ - 2, y_, "-+#+-");
      write(x_ - 2, y_ + 1, "-+++-");
      write(x_ - 2, y_ + 2, " --- ");
    }
  };
  
  class firework_start_expanded2 : public firework {
  public:
    firework_start_expanded2(int x, int y, console_color color, int speed) : console_firework_example::firework(x, y, color, speed) {}
    explicit firework_start_expanded2(const firework& firework) : console_firework_example::firework(firework) {}
    
    void paint() const override {
      console::foreground_color(color_);
      write(x_ - 2, y_ - 2, " +++ ");
      write(x_ - 2, y_ - 1, "++#++");
      write(x_ - 2, y_, "-# #-");
      write(x_ - 2, y_ + 1, "++#++");
      write(x_ - 2, y_ + 2, " +++ ");
    }
  };
  
  class firework_start_expanded3 : public firework {
  public:
    firework_start_expanded3(int x, int y, console_color color, int speed) : console_firework_example::firework(x, y, color, speed) {}
    explicit firework_start_expanded3(const firework& firework) : console_firework_example::firework(firework) {}
    
    void paint() const override {
      console::foreground_color(color_);
      write(x_ - 2, y_ - 2, "  #  ");
      write(x_ - 2, y_ - 1, "## ##");
      write(x_ - 2, y_, "#   #");
      write(x_ - 2, y_ + 1, "## ##");
      write(x_ - 2, y_ + 2, "  #  ");
    }
  };
  
  class firework_start_expanded4 : public firework {
  public:
    firework_start_expanded4(int x, int y, console_color color, int speed) : console_firework_example::firework(x, y, color, speed) {}
    explicit firework_start_expanded4(const firework& firework) : console_firework_example::firework(firework) {}
    
    void paint() const override {
      console::foreground_color(color_);
      write(x_ - 2, y_ - 2, " # # ");
      write(x_ - 2, y_ - 1, "#   #");
      write(x_ - 2, y_, "     ");
      write(x_ - 2, y_ + 1, "#   #");
      write(x_ - 2, y_ + 2, " # # ");
    }
  };
  
  class firework_end : public firework {
  public:
    firework_end(int x, int y, console_color color, int speed) : console_firework_example::firework(x, y, color, speed) {}
    explicit firework_end(const firework& firework) : console_firework_example::firework(firework) {}
    
    void paint() const override {
      console::foreground_color(color_);
      write(x_ - 2, y_ - 2, "     ");
      write(x_ - 2, y_ - 1, "     ");
      write(x_ - 2, y_, "     ");
      write(x_ - 2, y_ + 1, "     ");
      write(x_ - 2, y_ + 2, "     ");
    }
  };
  
  class program static_ {
  public:
    static void main() {
      console::write_line("Adjuste window size and pres any key when ready to start...");
      auto console_height = console::window_height();
      auto console_width = console::window_width();
      console::read_key(false);
      console::cursor_visible(false);
      console::clear();
      
      xtd::random rand;
      list < shared_ptr<firework >> fireworks;
      vector colors = {console_color::blue, console_color::green, console_color::cyan, console_color::red, console_color::magenta, console_color::yellow, console_color::white};
      
      while (!console::key_available()) {
        fireworks.push_back(make_shared<firework_start>(rand.next(2, console_width - 2), rand.next(2, console_height - 2), colors[rand.next(colors.size())], rand.next(1, 5)));
        
        list < shared_ptr<firework >> fireworks_to_removed;
        for (auto& firework : fireworks) {
          if (is<firework_end>(firework)) fireworks_to_removed.push_back(firework);
          explode(firework);
        }
        
        for (auto& firework : fireworks_to_removed)
          fireworks.remove(firework);
        
        sleep_for(100_ms);
      }
      
      console::reset_color();
      console::clear();
      console::cursor_visible(true);
    }

  private:
    static void explode(shared_ptr<firework>& firework) {
      firework->paint();
      if (is<firework_start_expanded4>(firework)) firework = make_shared<firework_end>(*firework);
      if (is<firework_start_expanded3>(firework)) firework = make_shared<firework_start_expanded4>(*firework);
      if (is<firework_start_expanded2>(firework)) firework = make_shared<firework_start_expanded3>(*firework);
      if (is<firework_start_expanded1>(firework)) firework = make_shared<firework_start_expanded2>(*firework);
      if (is<firework_exploded>(firework)) firework = make_shared<firework_start_expanded1>(*firework);
      if (date_time::now().ticks().count() % firework->delay() == 0 && is<firework_start>(firework)) firework = make_shared<firework_exploded>(*firework);
    }

  };
}

startup_(console_firework_example::program);

// This code can produces the following output with colors:
//
//
//        # #
//       #   #                                                                  -
//                                                                             -+-
//       #   #                                                                  -
//        # #
//
//                                                                 +++
//                                                                ++#++
//                                                                -# #-
//                                                                ++#++
//                                  ---                            +++
//                                 -+++-
//                                 -+#+-
//                                 -+++-
//                                  ---
//
//                                                         ---
//                                                        -+++-
//                                                        -+#+-
//                                                        -+++-
//                                         +               ---
//
//
//
