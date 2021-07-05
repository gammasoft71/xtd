#pragma once
#include "level.h"
#include <xtd/xtd>

namespace minesweeper {
  class input_name_dialog : public xtd::forms::form {
  public:
    input_name_dialog();
    
    minesweeper::level level() const;
    void level(minesweeper::level level);
    
    std::string gammer_name() const;
    void gammer_name(const std::string& gammer_name);
    
  private:
    std::string level_to_string();
    
    xtd::forms::label message_label_;
    xtd::forms::text_box name_text_box_;
    xtd::forms::button ok_button_;
    minesweeper::level level_ = level::beginner;
    std::string gammer_name_ = xtd::translator::translate("Anonymous");
  };
}
