/// @file
/// @brief Contains xtd::iobserver interface.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "interface.hpp"
#include <exception>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename type_t>
  /// @brief Provides a mechanism for receiving push-based notifications.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core interfaces
  /// @tparam type_t The object that provides notification information. This type parameter is contravariant. That is, you can use either the type you specified or any type that is less derived
  /// @par Examples
  /// The following example illustrates the observer design pattern. It defines a @p location class that contains latitude and longitude information.
  /// ```cpp
  /// struct location {
  /// public:
  ///   location(double latitude, double longitude) : latitutde_(latitude), longitude_(longitude) {}
  ///
  ///   double latitude() const noexcept {return latitutde_;}
  ///   double longitude() const noexcept {return longitude_;}
  ///
  /// private:
  ///   double latitutde_ = .0;
  ///   double longitude_ = .0;
  /// };
  /// ```
  /// The @p location_tracker class provides the xtd::iobservable implementation. Its @p track_location method is passed a nullable @p location object that contains the latitude and longitude data. If the Location value is not @p nullopt, the @p track_location method calls the xtd::iobserver::on_next method of each observer.
  /// ```cpp
  /// class location_tracker : public iobservable<location> {
  /// public:
  ///   location_tracker() = default;
  ///
  ///   void subscribe(iobserver<location>& observer) noexcept override {
  ///     if (find(observers_.begin(), observers_.end(), &observer) == observers_.end())
  ///       observers_.push_back(&observer);
  ///   }
  ///
  ///   void unsubscribe(iobserver<location>& observer) noexcept override {
  ///     auto iterator = find(observers_.begin(), observers_.end(), &observer);
  ///     if (iterator != observers_.end())
  ///       observers_.erase(iterator);
  ///   }
  ///
  ///   void track_location(optional<location> loc) {
  ///     for (auto observer : observers_) {
  ///       if (!loc.has_value())
  ///         observer->on_error(location_unknown_exception());
  ///       else
  ///         observer->on_next(loc.value());
  ///     }
  ///   }
  ///
  ///   void end_transmission() {
  ///     for (auto observer : observers_)
  ///       observer->on_completed();
  ///     observers_.clear();
  ///   }
  ///
  /// private:
  ///   std::vector<iobserver<location>*> observers_;
  /// };
  /// ```
  /// If the @p location value is @p nullopt, the @p tack_location method instantiates a @p location_unknown_exception object, which is shown in the following example. It then calls each observer's @p on_error method and passes it the @p location_unknown_exception object. Note that @p location_unknown_exception derives from xtd::exception, but does not add any new members.
  /// ```cpp
  /// class location_unknown_exception : public exception {
  /// public:
  ///   location_unknown_exception() = default;
  /// };
  /// ```
  /// Observers subscribe to receive notifications from an @p location_tracker object by calling its xtd::iobservable::subscribe method. And unsubscribe by calling its xtd::unobservable <type_t>::unsubscribe method. The @p location_tracker class also includes an @ end_transmission method. When no further location data is available, this method calls each observer's xtd::iobserver::on_completed method, and then clears the internal list of observers.
  ///
  /// In this example, the @p location_reporter class provides the xtd::iobserver implementation. It displays information about the current location to the console.
  /// Its constructor includes a @c name parameter, which allows the @c location_reporter instance to identify itself in its string output.
  /// It also includes a @c subscribe method, which wraps a call to the provider's xtd::iobservable::subscribe method.
  /// The @p location_reporter class also includes an @p unsubscribe method, to remove the subscription.
  /// The following code defines the @p location_reporter class.
  /// ```cpp
  /// class location_reporter : iobserver<location> {
  /// public:
  ///   location_reporter(string name) : name_(name) {}
  ///   virtual ~location_reporter() {unsubscribe();}
  ///
  ///   string name() const noexcept {return name_;}
  ///
  ///   virtual void subscribe(iobservable<location>& provider) {
  ///     provider_ = &provider;
  ///     provider_->subscribe(*this);
  ///   }
  ///
  ///   void on_completed() noexcept override {
  ///     console::write_line("The location Tracker has completed transmitting data to {}.", name());
  ///     unsubscribe();
  ///   }
  ///
  ///   void on_error(const exception& e) noexcept override {
  ///     console::write_line("{}: The location cannot be determined.", name());
  ///   }
  ///
  ///   void on_next(const location& value) noexcept override {
  ///     console::write_line("{}: The current location is {}, {}", name(), value.latitude(), value.longitude());
  ///   }
  ///
  ///   virtual void unsubscribe() {
  ///     if (provider_ != nullptr) provider_->unsubscribe(*this);
  ///     provider_ = nullptr;
  ///   }
  ///
  /// private:
  ///   string name_;
  ///   iobservable<location>* provider_ = nullptr;
  /// };
  /// ```
  /// The following code then instantiates the provider and the observer.
  /// ```cpp
  /// auto main() -> int {
  ///   // Define a provider and two observers.
  ///   location_tracker provider;
  ///   location_reporter reporter1 {"Fixed GPS"};
  ///   reporter1.subscribe(provider);
  ///   location_reporter reporter2 {"Mobile GPS"};
  ///   reporter2.subscribe(provider);
  ///
  ///   provider.track_location(location {47.6456, -122.1312});
  ///   reporter1.unsubscribe();
  ///   provider.track_location(location {47.6677, -122.1199});
  ///   provider.track_location(nullopt);
  ///   provider.end_transmission();
  /// }
  ///
  /// // The example displays output similar to the following:
  /// //
  /// // Fixed GPS: The current location is 47.6456, -122.1312
  /// // Mobile GPS: The current location is 47.6456, -122.1312
  /// // Mobile GPS: The current location is 47.6677, -122.1199
  /// // Mobile GPS: The location cannot be determined.
  /// // The location Tracker has completed transmitting data to Mobile GPS.
  /// ```
  /// See You can show this example here
  /// @remarks The xtd::iobserver and xtd::iobservable <type_t> interfaces provide a generalized mechanism for push-based notification, also known as the observer design pattern. The xtd::iobservable interface represents the class that sends notifications (the provider); the xtd::io::bserver <type_t> interface represents the class that receives them (the observer). @p type_t represents the class that provides the notification information. In some push-based notifications, the xtd::iobserver <type_t> implementation and @p type_t can represent the same type.
  /// @remarks The provider must implement two methods :
  /// @remarks * xtd::iobservable::subscribe, that indicates that an observer wants to receive push-based notifications.
  /// @remarks * xtd::iobservable::unsubscribe, that indicates that an observer no longer wants receive push-based notifications.
  /// @remarks At any given time, a given provider may have zero, one, or multiple observers. The provider is responsible for storing references to observers and ensuring that they are valid before it sends notifications. The xtd::iobservable interface does not make any assumptions about the number of observers or the order in which notifications are sent.
  /// @remarks The provider sends the following three kinds of notifications to the observer by calling xtd::iobserver methods:
  /// @remarks * The current data. The provider can call the xtd::iobserver::on_next method to pass the observer a @p type_t object that has current data, changed data, or fresh data.
  /// @remarks * An error condition. The provider can call the xtd::iobserver::on_error method to notify the observer that some error condition has occurred.
  /// @remarks * No further data. The provider can call the xtd::iobserver::on_completed method to notify the observer that it has finished sending notifications.
  class iobserver interface_ {
  public:
    /// @name Public Methods
    
    /// @{
    /// @brief Notifies the observer that the provider has finished sending push-based notifications.
    /// @par Examples
    /// The following example provides an implementation of the OnCompleted method in a latitude/longitude tracking application. The method simply reports that no further data is available and calls the provider's IDisposable.Dispose implementation. See the Example section of the IObserver<T> topic for the complete example.
    /// ```cpp
    /// void on_completed() noexcept override {
    ///   console::write_line("The location Tracker has completed transmitting data to {}.", name());
    ///   unsubscribe();
    /// }
    /// ```
    virtual void on_completed() noexcept = 0;
    
    /// @brief Notifies the observer that the provider has experienced an error condition.
    /// @param error n object that provides additional information about the error.
    /// @par Examples
    /// The following example provides an implementation of the on_error method in a latitude/longitude tracking application. The method simply reports that data is currently unavailable; it does not make use of the std::exception object passed to it as a parameter. See the Example section of the xtd::iobserver<type_t> topic for the complete example.
    /// ```cpp
    /// void on_error(const std::exception& e) noexcept override {
    ///   console::write_line("{}: The location cannot be determined.", name());
    /// }
    /// ```
    virtual void on_error(const std::exception& error) noexcept = 0;
    
    /// @brief Provides the observer with new data.
    /// @param value The current notification information.
    /// @par Examples
    /// The following example provides an implementation of the on_next method in a latitude/longitude tracking application. See the Example section of the iobserver<type_t> topic for the complete example.
    /// ```cpp
    /// void on_next(const location& value) noexcept override {
    ///   console::write_line("{}: The current location is {}, {}", name(), value.latitude(), value.longitude());
    /// }
    /// ```
    virtual void on_next(const type_t& value) noexcept = 0;
    /// @}
  };
}
