#include <vector>

namespace xtd {
  namespace forms {
    namespace layout {
      template<typename type_t>
      class arranged_element_collerction {
      public:
        arranged_element_collerction() = default;
        
        /// @cond
        arranged_element_collerction(const arranged_element_collerction&) = default;
        arranged_element_collerction& operator=(const arranged_element_collerction&) = default;
        /// @endcond
        
      private:
        std::vector<type_t> collection_;
      };
    }
  }
}
