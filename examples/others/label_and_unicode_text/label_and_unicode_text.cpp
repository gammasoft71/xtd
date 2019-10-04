#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    labelArabic.text("Arabic:");
    labelArabic.location({10, 10});
    labelArabic.parent(*this);
    labelArabic.width(150);
    
    labelArabicText.text(L"\u0627\u0644\u0643\u0644\u0645\u0629 \u0627\u0644\u0639\u0631\u0628\u064A\u0629");
    labelArabicText.font(drawing::font(labelArabicText.font(), drawing::font_style::bold));
    labelArabicText.location({160, 10});
    labelArabicText.parent(*this);
    labelArabicText.width(220);
    
    labelTradChinese.text("Trad. Chinese:");
    labelTradChinese.location({10, 40});
    labelTradChinese.parent(*this);
    labelTradChinese.width(150);
    
    labelTradChineseText.text(L"\u4E2D\u570B\u7684\u6F22\u5B57");
    labelTradChineseText.font(drawing::font(labelArabicText.font(), drawing::font_style::bold));
    labelTradChineseText.location({160, 40});
    labelTradChineseText.parent(*this);
    labelTradChineseText.width(220);
    
    labelSimplChinese.text("Simpl. Chinese:");
    labelSimplChinese.location({10, 70});
    labelSimplChinese.parent(*this);
    labelSimplChinese.width(150);
    
    labelSimplChineseText.text(L"\u6C49\u8BED");
    labelSimplChineseText.font(drawing::font(labelArabicText.font(), drawing::font_style::bold));
    labelSimplChineseText.location({160, 70});
    labelSimplChineseText.parent(*this);
    labelSimplChineseText.width(220);
    
    labelFrench.text("French:");
    labelFrench.location({10, 100});
    labelFrench.parent(*this);
    labelFrench.width(150);
    
    labelFrenchText.text(L"Langue fran\u00E7aise");
    labelFrenchText.font(drawing::font(labelArabicText.font(), drawing::font_style::bold));
    labelFrenchText.location({160, 100});
    labelFrenchText.parent(*this);
    labelFrenchText.width(220);
    
    labelGreek.text("Greek:");
    labelGreek.location({10, 130});
    labelGreek.parent(*this);
    labelGreek.width(150);
    
    labelGreekText.text(L"\u0395\u03BB\u03BB\u03B7\u03BD\u03B9\u03BA\u03AE \u03B3\u03BB\u03CE\u03C3\u03C3\u03B1");
    labelGreekText.font(drawing::font(labelArabicText.font(), drawing::font_style::bold));
    labelGreekText.location({160, 130});
    labelGreekText.parent(*this);
    labelGreekText.width(220);
    
    labelHebrew.text("Hebrew:");
    labelHebrew.location({10, 160});
    labelHebrew.parent(*this);
    labelHebrew.width(150);
    
    labelHebrewText.text(L"\u05DB\u05EA\u05D1 \u05E2\u05D1\u05E8\u05D9\u05EA");
    labelHebrewText.font(drawing::font(labelArabicText.font(), drawing::font_style::bold));
    labelHebrewText.location({160, 160});
    labelHebrewText.parent(*this);
    labelHebrewText.width(220);
    
    labelHindi.text("Hindi:");
    labelHindi.location({10, 190});
    labelHindi.parent(*this);
    labelHindi.width(150);
    
    labelHindiText.text(L"\u0939\u093f\u0928\u094d\u0926\u0940 \u092d\u093e\u0937\u093e");
    labelHindiText.font(drawing::font(labelArabicText.font(), drawing::font_style::bold));
    labelHindiText.location({160, 190});
    labelHindiText.parent(*this);
    labelHindiText.width(220);
    
    labelIcelandic.text("Icelandic:");
    labelIcelandic.location({10, 220});
    labelIcelandic.parent(*this);
    labelIcelandic.width(150);
    
    labelIcelandicText.text(L"\u00CDslenska");
    labelIcelandicText.font(drawing::font(labelArabicText.font(), drawing::font_style::bold));
    labelIcelandicText.location({160, 220});
    labelIcelandicText.parent(*this);
    labelIcelandicText.width(220);
    
    labelJapanese.text("Japanese:");
    labelJapanese.location({10, 250});
    labelJapanese.parent(*this);
    labelJapanese.width(150);
    
    labelJapaneseText.text(L"\u65E5\u672C\u8A9E\u306E\u3072\u3089\u304C\u306A, \u6F22\u5B57\u3068\u30AB\u30BF\u30AB\u30CA");
    labelJapaneseText.font(drawing::font(labelArabicText.font(), drawing::font_style::bold));
    labelJapaneseText.location({160, 250});
    labelJapaneseText.parent(*this);
    labelJapaneseText.width(220);
    
    labelKorean.text("Korean:");
    labelKorean.location({10, 280});
    labelKorean.parent(*this);
    labelKorean.width(150);
    
    labelKoreanText.text(L"\uB300\uD55C\uBBFC\uAD6D\uC758 \uD55C\uAE00");
    labelKoreanText.font(drawing::font(labelArabicText.font(), drawing::font_style::bold));
    labelKoreanText.location({160, 280});
    labelKoreanText.parent(*this);
    labelKoreanText.width(220);
    
    labelRussian.text("Russian:");
    labelRussian.location({10, 310});
    labelRussian.parent(*this);
    labelRussian.width(150);
    
    labelRussianText.text(L"\u0420\u0443\u0441\u0441\u043A\u0438\u0439 \u044F\u0437\u044B\u043A");
    labelRussianText.font(drawing::font(labelArabicText.font(), drawing::font_style::bold));
    labelRussianText.location({160, 310});
    labelRussianText.parent(*this);
    labelRussianText.width(220);

    text("labels and Unicode text example");
    client_size({380, 350});
  }

private:
  label labelArabic;
  label labelArabicText;
  label labelTradChinese;
  label labelTradChineseText;
  label labelSimplChinese;
  label labelSimplChineseText;
  label labelFrench;
  label labelFrenchText;
  label labelGreek;
  label labelGreekText;
  label labelHebrew;
  label labelHebrewText;
  label labelHindi;
  label labelHindiText;
  label labelIcelandic;
  label labelIcelandicText;
  label labelJapanese;
  label labelJapaneseText;
  label labelKorean;
  label labelKoreanText;
  label labelRussian;
  label labelRussianText;
};

int main() {
  application::run(form1());
}
