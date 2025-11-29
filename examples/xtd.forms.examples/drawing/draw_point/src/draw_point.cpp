#include <xtd/xtd>

namespace particle_system_example {
  class form1 : public form {
    struct particle {
      point position;
      point velocity;
      color color;
      int size;

      void update(int width, int height) {
        position += velocity;
        if (position.x < 0 || position.x > width) velocity.x = -velocity.x;
        if (position.y < 0 || position.y > height) velocity.y = -velocity.y;
      }
      
      bool operator ==(const particle& other) const noexcept {return position == other.position && velocity == other.velocity && color == other.color && size == other.size;}
    };
    
  public:
    form1() {
      text("Draw point example");
      client_size({600, 400});
      
      generate_particles_timer.interval(50_ms);
      generate_particles_timer.tick += event_handler {*this, &form1::generate_particles};
      generate_particles_timer.start();
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      form::on_paint(e);
      e.graphics().clear(color::black);
      
      for (auto& particule : particles) {
        e.graphics().draw_point(pen(particule.color, particule.size), particule.position.x, particule.position.y);
        particule.update(client_size().width, client_size().height);
      }
    }

  private:
    void generate_particles() {
      static auto rnd = xtd::random {};
      static auto colors = basic_colors::get_colors();
      if (particles.count() < 200)
        particles.add({{rnd.next(client_size().width), rnd.next(client_size().height)}, {rnd.next(-5, 6), rnd.next(-5, 6)}, colors[rnd.next(colors.count())], rnd.next(2, 8)});
      invalidate();
    }
    
    list<particle> particles;
    forms::timer generate_particles_timer;
  };
}

auto main() -> int {
  application::run(particle_system_example::form1{});
}
