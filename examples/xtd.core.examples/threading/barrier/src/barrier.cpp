#include <xtd/threading/barrier>
#include <xtd/threading/interlocked>
#include <xtd/threading/thread_pool>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::threading;

namespace barrier_example {
  class program {
  public:
    static void main() {
      auto count = 0;
      
      // Create a barrier with three participants
      // Provide a post-phase action that will print out certain information
      // And the third time through, it will throw an exception
      auto barrier = threading::barrier {3, action<threading::barrier&> {[&](threading::barrier& b) {
        console::write_line("Post-Phase action: count={0}, phase={1}", count, b.current_phase_number());
        if (b.current_phase_number() == 2) throw system_exception("D'oh!", csf_);
      }}};
      
      // Nope -- changed my mind.  Let's make it five participants.
      barrier.add_participants(2);
      
      // Nope -- let's settle on four participants.
      barrier.remove_participant();
      
      auto action = [&] {
        interlocked::increment(count);
        barrier.signal_and_wait(); // during the post-phase action, count should be 4 and phase should be 0
        interlocked::increment(count);
        barrier.signal_and_wait(); // during the post-phase action, count should be 8 and phase should be 1
        
        // The third time, SignalAndWait() will throw an exception and all participants will see it
        interlocked::increment(count);
        try {
          barrier.signal_and_wait();
        } catch (const barrier_post_phase_exception& bppe) {
          console::write_line("Caught barrier_post_phase_exception: {0}", bppe.message());
        }
        
        // The fourth time should be hunky-dory
        interlocked::increment(count);
        barrier.signal_and_wait(); // during the post-phase action, count should be 16 and phase should be 3
      };

      // Now launch 4 parallel actions to serve as 4 participants
      for (auto index = 0; index < 4; ++index)
        thread_pool::queue_user_work_item(action);
      
      // It's good form to join all thread and  close() a barrier when you're done with it.
      thread::join_all();
      barrier.close();
    }
  };
}

startup_(barrier_example::program::main);

// This example produces output similar to the following:
//
// Post-Phase action: count=4, phase=0
// Post-Phase action: count=8, phase=1
// Post-Phase action: count=12, phase=2
// Post-Phase action: count=16, phase=3
