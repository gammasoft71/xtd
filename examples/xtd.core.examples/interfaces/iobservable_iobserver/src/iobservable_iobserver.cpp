#include <xtd/xtd>

struct location {
public:
  location(double latitude, double longitude) : latitutde_(latitude), longitude_(longitude) {}
  
  double latitude() const noexcept {return latitutde_;}
  double longitude() const noexcept {return longitude_;}
  
private:
  double latitutde_ = .0;
  double longitude_ = .0;
};

class location_unknown_exception : public system_exception {
public:
  location_unknown_exception() {}
};

class location_tracker : public iobservable<location> {
public:
  location_tracker() = default;
  
  void subscribe(iobserver<location>& observer) noexcept override {
    if (!observers_.exists([&](auto item) {return item == &observer;}))
      observers_.add(&observer);
  }
  
  void unsubscribe(iobserver<location>& observer) noexcept override {
    if (observers_.exists([&](auto item) {return item == &observer;}))
      observers_.remove(&observer);
  }
  
  void track_location(std::optional<location> loc) {
    for (auto observer : observers_) {
      if (!loc.has_value())
        observer->on_error(location_unknown_exception());
      else
        observer->on_next(loc.value());
    }
  }
  
  void end_transmission() {
    for (auto observer : observers_)
      observer->on_completed();
    observers_.clear();
  }
  
private:
  list<iobserver<location>*> observers_;
};

class location_reporter : iobserver<location> {
public:
  location_reporter(string name) : name_(name) {}
  virtual ~location_reporter() {unsubscribe();}
  
  string name() const noexcept {return name_;}
  
  virtual void subscribe(iobservable<location>& provider) {
    provider_ = &provider;
    provider_->subscribe(*this);
  }
  
  void on_completed() noexcept override {
    console::write_line("The location Tracker has completed transmitting data to {}.", name());
    unsubscribe();
  }
  
  void on_error(const std::exception& e) noexcept override {
    console::write_line("{}: The location cannot be determined.", name());
  }
  
  void on_next(const location& value) noexcept override {
    console::write_line("{}: The current location is {}, {}", name(), value.latitude(), value.longitude());
  }
  
  virtual void unsubscribe() {
    if (provider_ != nullptr) provider_->unsubscribe(*this);
    provider_ = nullptr;
  }
  
private:
  string name_;
  iobservable<location>* provider_ = nullptr;
};

auto main() -> int {
  // Define a provider and two observers.
  auto provider = location_tracker {};
  auto reporter1 = location_reporter {"Fixed GPS"};
  reporter1.subscribe(provider);
  auto reporter2 = location_reporter {"Mobile GPS"};
  reporter2.subscribe(provider);
  
  provider.track_location(location {47.6456, -122.1312});
  reporter1.unsubscribe();
  provider.track_location(location {47.6677, -122.1199});
  provider.track_location(std::nullopt);
  provider.end_transmission();
}

// The example displays output similar to the following:
//
// Fixed GPS: The current location is 47.6456, -122.1312
// Mobile GPS: The current location is 47.6456, -122.1312
// Mobile GPS: The current location is 47.6677, -122.1199
// Mobile GPS: The location cannot be determined.
// The location Tracker has completed transmitting data to Mobile GPS.
