#include <xtd/delegates>
#include <iostream>
#include <string>

using namespace std;
using namespace xtd;

struct control {
  virtual ~control() = default;
  
  const string& text() const {return this->text_;}
  void text(const string& text) {this->text_ = text;}
  
private:
  string text_;
};

struct button : public control {
  
  event_handler<control> click;
};

// The main entry point for the application.
int main() {
  button button1;
  button1.text("button1");
  
  button1.click += [&](const control& sender, const event_args& e)  {
    cout << "button (" << sender.text() << ") clicked!" << endl;
  };
  
  // click simulation
  button1.click(button1, event_args::empty());
}
