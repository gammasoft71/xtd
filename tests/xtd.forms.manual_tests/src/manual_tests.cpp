#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  /*
  main_menu menu;
  menu.menu_items().push_back("&File");
  menu.menu_items().push_back("&Edit");
  menu.menu_items().push_back("&View");
  menu.menu_items().push_back("&Window");
  menu.menu_items().push_back("&Help");
   */

  form form_main;
  form_main.text("Manual tests");
  //form_main.menu(menu);
  form_main.menu({
    {"&File", {
      {"&New"},
      {"-"},
      {"&Open"},
      {"Open recen", {
        {"File1"},
        {"File2"},
        {"File3"},
        {"File4"},
        {"File5"},
      }},
      {"&Close"},
      {"-"},
      {"&Save"},
      {"Save &As"},
      {"-"},
      {"Page &Seup..."},
      {"&Print"},
      {"-"},
      {"&Exit"},
    }},
    {"&Edit", {
      {"Undo"},
      {"Redo"},
      {"-"},
      {"Cu&t"},
      {"&Copy"},
      {"&Paste"},
      {"-"},
      {"Select &All"},
      {"-"},
      {"Options..."},
    }},
    {"&View", {
      {"Back"},
      {"Forward"},
      {"-"},
      {"Show"},
      {"Hide"},
    }},
    {"&Options", {
      {"Value A"},
      {"Value B"},
      {"Value C"},
      {"-"},
      {"Value D"},
      {"Value E"},
      {"Value F"},
      {"-"},
      {"Value G"},
      {"Value H"},
      {"Value I"},
    }},
    {"&Window"},
    {"&Help", {
      {"&About..."},
    }},
  });
  
  application::run(form_main);
}
