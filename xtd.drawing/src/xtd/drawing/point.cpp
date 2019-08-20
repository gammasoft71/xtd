#include "../../../include/xtd/drawing/point.hpp"
#include "../../../include/xtd/drawing/size.hpp"

using namespace xtd;
using namespace xtd::drawing;

const point point::empty;

point::point(const size& size) : x_(size.width()), y_(size.height()) {  
}
