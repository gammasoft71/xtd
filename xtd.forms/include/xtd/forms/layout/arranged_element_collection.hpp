#include <vector>

namespace xtd {
  namespace forms {
    namespace layout {
      template<typename type_t>
      class arranged_element_collection {
      public:
        arranged_element_collection() = default;
        
        /// @cond
        arranged_element_collection(const arranged_element_collection&) = default;
        arranged_element_collection& operator=(const arranged_element_collection&) = default;
        /// @endcond
        
      private:
        std::vector<type_t> collection_;
      };
    }
  }
}
