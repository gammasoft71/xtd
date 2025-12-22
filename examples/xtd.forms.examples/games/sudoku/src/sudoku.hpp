
#pragma once
#include <xtd/array>
#include <xtd/istringable>
#include <xtd/random>

namespace sudoku {
  class sudoku : public xtd::istringable {
  public:
    enum class difficulty {
      easy,
      medium,
      hard,
      evil
    };
    
    sudoku(sudoku&&) = default;
    sudoku(const sudoku&) = default;
    sudoku& operator =(sudoku&&) = default;
    sudoku& operator =(const sudoku&) = default;
    
    using grid_type = xtd::array<int, 2>;
    
    auto grid() const -> const grid_type& {return grid_;}
    
    auto solve() -> bool {
      return solve_impl(0, [] {
        auto a = xtd::array<>::create_instance<int>(grid_size);
        for (auto i = 0; i < grid_size; ++i) a[i] = i + 1;
        return a;
      });
    }
    
    auto solve_random() -> bool {
      return solve_impl(0, [] {
        auto rand = xtd::random {};
        auto a = xtd::array<>::create_instance<int>(grid_size);
        for (auto i = 0; i < grid_size; ++i) a[i] = i + 1;
        rand.shuffle(a);
        return a;
      });
    }
    
    auto to_array() const noexcept -> xtd::array<int> {
      return grid_.to_array();
    }
    
    auto to_string() const noexcept -> xtd::string override {
      return xtd::string::join(" ", grid_);
    }
    
    static auto create_empty() noexcept -> sudoku {return sudoku();}
    
    static auto from_array(const xtd::array<int>& items) -> sudoku {
      auto result = create_empty();
      for (auto y = 0_z; y < result.grid_.get_length(0); ++y)
        for (auto x = 0_z; x < result.grid_.get_length(1); ++x)
          result.grid_(y, x) = items[y * sudoku::grid_size + x];
      return result;
    }
    
    static auto make_puzzle(difficulty d) noexcept -> sudoku {return make_puzzle_impl(target_holes(d));}
    
    static auto parse(const xtd::string& value) -> sudoku {return from_array(value.split().cast<int>().to_array());}
    
    static auto try_parse(const xtd::string& value, sudoku& result) noexcept -> bool {
      try {
        result = parse(value);
        return true;
      } catch(...) {
        return false;
      }
    }
    
  private:
    static constexpr auto grid_size = 9;
    
    sudoku() = default;
    
    auto check_grid(int line, int col, int value) const noexcept -> bool {
      auto block = [](int i) noexcept { return (i / 3) * 3; };
      
      for (auto i = 0; i < grid_size; ++i)
        if (grid_(line, i) == value || grid_(i, col) == value)
          return false;
      
      auto y = block(line);
      auto x = block(col);
      for (auto j = y; j < y + 3; ++j)
        for (auto i = x; i < x + 3; ++i)
          if (grid_(j, i) == value)
            return false;
      
      return true;
    }
    
    template<typename order_t>
    auto count_impl(int line, int& count, int limit, order_t&& order) noexcept -> void {
      if (count >= limit)
        return;
      
      if (line == grid_size) {
        ++count;
        return;
      }
      
      for (auto col = 0; col < grid_size; ++col) {
        if (grid_(line, col) != 0)
          continue;
        
        for (auto v : order()) {
          if (!check_grid(line, col, v))
            continue;
          
          grid_(line, col) = v;
          count_impl(line, count, limit, order);
          grid_(line, col) = 0;
          
          if (count >= limit) return;
        }
        
        return;
      }
      
      count_impl(line + 1, count, limit, order);
    }
    
    auto count_solutions(int limit = 2) const noexcept -> int {
      auto copy = self_;
      int count = 0;
      
      copy.count_impl(0, count, limit, [] {
        auto a = xtd::array<>::create_instance<int>(grid_size);
        for (auto i = 0; i < grid_size; ++i)
          a[i] = i + 1;
        return a;
      });
      return count;
    }
    
    static auto generate() noexcept -> sudoku {
      auto rand = xtd::random {};
      auto result = create_empty();
      
      auto line = rand.next(grid_size);
      
      auto numbers = xtd::array<>::create_instance<int>(grid_size);
      for (auto i = 0; i < grid_size; ++i)
        numbers[i] = i + 1;
      rand.shuffle(numbers);
      
      for (auto x = 0; x < grid_size; ++x)
        result.grid_(line, x) = numbers[x];
      
      result.solve_random();
      return result;
    }
    
    static auto make_puzzle_impl(int holes) noexcept -> sudoku {
      auto rand = xtd::random {};
      auto puzzle = generate();
      
      auto cells = rand.shuffle(enumerable::range(grid_size * grid_size).to_array());
      for (auto i = 0_z; i < cells.length() && holes > 0; ++i) {
        auto idx = cells(i);
        auto y = idx / grid_size;
        auto x = idx % grid_size;
        
        auto backup = puzzle.grid_(y, x);
        puzzle.grid_(y, x) = 0;
        
        if (puzzle.count_solutions() == 1) --holes;
        else puzzle.grid_(y, x) = backup;
      }
      
      return puzzle;
    }
    
    template<typename order_t>
    auto solve_impl(int line, order_t&& order) noexcept -> bool {
      if (line == grid_size) return true;
      
      for (auto col = 0; col < grid_size; ++col) {
        if (grid_(line, col) != 0) continue;
        
        for (auto v : order()) {
          if (!check_grid(line, col, v)) continue;
          
          grid_(line, col) = v;
          if (solve_impl(line, order)) return true;
          grid_(line, col) = 0;
        }
        
        return false;
      }
      
      return solve_impl(line + 1, order);
    }
    
    static auto target_holes(difficulty d) noexcept -> int {
      switch (d) {
        case difficulty::easy: return 38;
        case difficulty::medium: return 43;
        case difficulty::hard: return 48;
        case difficulty::evil: return 53;
      }
      return 43;
    }
    
    grid_type grid_ = xtd::array<>::create_instance<int>(grid_size, grid_size);
  };
}
