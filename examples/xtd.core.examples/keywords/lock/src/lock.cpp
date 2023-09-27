#include <xtd/threading/thread_pool>
#include <xtd/console>
#include <xtd/lock>
#include <xtd/random>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace examples {
  class account : public object {
  public:
    explicit account(int initial) : balance(initial) {}
    
    void do_transactions() {
      for (auto i = 0; i < 100; ++i)
        withdraw(random.next(1, 100));
    }
    
  private:
    int withdraw(int amount) {
      // This condition never is true unless the lock statement is commented out.
      if (balance < 0) throw system_exception {"Negative Balance", csf_};
      
      // Comment out the next line to see the effect of leaving out the lock keyword.
      lock_(balance) {
        if (balance < amount) return 0;
        console::write_line("Balance before Withdrawal :  {0}", balance);
        console::write_line("Amount to Withdraw        : -{0}", amount);
        balance = balance - amount;
        console::write_line("Balance after Withdrawal  :  {0}", balance);
        return amount;
      }
      return 0;
    }

    int balance = 0;
    xtd::random random;
  };
  
  class program {
  public:
    static void main() {
      auto account = examples::account {1000};
      
      for (auto i = 0; i < 10; ++i)
        thread_pool::queue_user_work_item({account, &account::do_transactions});
      
      thread_pool::close();
    }
  };
}

startup_(examples::program::main);

// This code can produce the following output:
//
// Balance before Withdrawal :  1000
// Amount to Withdraw        : -75
// Balance after Withdrawal  :  925
// Balance before Withdrawal :  925
// Amount to Withdraw        : -84
// Balance after Withdrawal  :  841
// Balance before Withdrawal :  841
// Amount to Withdraw        : -69
// Balance after Withdrawal  :  772
// Balance before Withdrawal :  772
// Amount to Withdraw        : -71
// Balance after Withdrawal  :  701
// Balance before Withdrawal :  701
// Amount to Withdraw        : -84
// Balance after Withdrawal  :  617
// Balance before Withdrawal :  617
// Amount to Withdraw        : -81
// Balance after Withdrawal  :  536
// Balance before Withdrawal :  536
// Amount to Withdraw        : -15
// Balance after Withdrawal  :  521
// Balance before Withdrawal :  521
// Amount to Withdraw        : -93
// Balance after Withdrawal  :  428
// Balance before Withdrawal :  428
// Amount to Withdraw        : -6
// Balance after Withdrawal  :  422
// Balance before Withdrawal :  422
// Amount to Withdraw        : -54
// Balance after Withdrawal  :  368
// Balance before Withdrawal :  368
// Amount to Withdraw        : -52
// Balance after Withdrawal  :  316
// Balance before Withdrawal :  316
// Amount to Withdraw        : -67
// Balance after Withdrawal  :  249
// Balance before Withdrawal :  249
// Amount to Withdraw        : -93
// Balance after Withdrawal  :  156
// Balance before Withdrawal :  156
// Amount to Withdraw        : -60
// Balance after Withdrawal  :  96
// Balance before Withdrawal :  96
// Amount to Withdraw        : -7
// Balance after Withdrawal  :  89
// Balance before Withdrawal :  89
// Amount to Withdraw        : -42
// Balance after Withdrawal  :  47
// Balance before Withdrawal :  47
// Amount to Withdraw        : -1
// Balance after Withdrawal  :  46
// Balance before Withdrawal :  46
// Amount to Withdraw        : -22
// Balance after Withdrawal  :  24
// Balance before Withdrawal :  24
// Amount to Withdraw        : -18
// Balance after Withdrawal  :  6
// Balance before Withdrawal :  6
// Amount to Withdraw        : -2
// Balance after Withdrawal  :  4
// Balance before Withdrawal :  4
// Amount to Withdraw        : -2
// Balance after Withdrawal  :  2
// Balance before Withdrawal :  2
// Amount to Withdraw        : -2
// Balance after Withdrawal  :  0
