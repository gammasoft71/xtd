/// @file
/// @brief Contains xtd::random class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <limits>
#include <optional>
#include <random>
#include "argument_null_exception.h"
#include "argument_out_of_range_exception.h"
#include "core_export.h"
#include "environment.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a pseudo-random number generator, a device that produces a sequence of numbers that meet certain statistical requirements for randomness.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks Pseudo-random numbers are chosen with equal probability from a finite set of numbers. The chosen numbers are not completely random because a definite mathematical algorithm is used to select them, but they are sufficiently random for practical purposes. The current implementation of the random class is based on Donald E. Knuth's subtractive random number generator algorithm. For more information, see D. E. Knuth. "The Art of Computer Programming, volume 2: Seminumerical Algorithms". Addison-Wesley, Reading, MA, second edition, 1981.
  /// @remarks The random number generation starts from a seed value. If the same seed is used repeatedly, the same series of numbers is generated. One way to produce different sequences is to make the seed value time-dependent, thereby producing a different series with each new instance of random. By default, the parameterless constructor of the random class uses the system clock to generate its seed value, while its parameterized constructor can take an int32_t value based on the number of ticks in the current time. However, because the clock has finite resolution, using the parameterless constructor to create different random objects in close succession creates random number generators that produce identical sequences of random numbers. The following example illustrates that two random objects that are instantiated in close succession generate an identical series of random numbers.
  /// @include random1.cpp
  /// @remarks This problem can be avoided by creating a single random object rather than multiple ones.
  /// @remarks To improve performance, create one random object to generate many random numbers over time, instead of repeatedly creating a new random objects to generate one random number.
  /// @par Notes to Callers
  /// The implementation of the random number generator in the random class is not guaranteed to remain the same across major versions of the xtd. As a result, your application code should not assume that the same seed will result in the same pseudo-random sequence in different versions of the xtd.
  /// @par Notes to Inheritors
  /// In xtd, the behavior of the random::next(), random::next(int32_t, int32_t), and next_bytes methods have changed so that these methods do not necessarily call the derived class implementation of the sample method. As a result, classes derived from Rrandom that target the xtd should also virtual these three methods.
  /// @par Examples
  /// The following example creates a single random number generator and calls its next_bytes, next, and next_double methods to generate sequences of random numbers within different ranges.
  /// @include random2.cpp
  /// @par Examples
  /// The following example generates a random integer that it uses as an index to retrieve a string value from an array.
  /// @include random3.cpp
  class random : public object {
  public:
    /// @brief Initializes a new instance of the random class, using a default generated seed value
    random() : generator_(static_cast<uint32_t>(environment::tick_count().count())) {}
    
    /// @brief Initializes a new instance of the random class, using a specified seed value.
    /// @param seed A number used to calculate a starting value for the pseudo-random number sequence.
    explicit random(uint32_t seed) : generator_(seed + 1) {}
    
    /// @brief Initializes a new instance of the random class, using a specified random device value.
    /// @param random_device A random device value.
    explicit random(std::random_device& random_device) : generator_(random_device()) {}
    
    /// @brief Returns a nonnegative random number.
    /// @return A 32-bit signed integer greater than or equal to zero and less than std::numeric_limits<int32_t>::max())
    virtual int32_t next() const {return next(std::numeric_limits<int32_t>::max());}
    
    /// @brief Returns a nonnegative random number.
    /// @return A value_t greater than or equal to zero and less than std::numeric_limits<value_t>::max()
    template<typename value_t>
    value_t next() const {return next(std::numeric_limits<value_t>::max());}
    
    /// @brief Returns a nonnegative random number less than the specified maximum.
    /// @param max_value The exclusive upper bound of the random number to be generated. max_value must be greater than or equal to zero.
    /// @return A 32-bit signed integer greater than or equal to zero and less than max_value
    /// @exception argument_out_of_range_exception max_value is less than zero.
    /// @remarks The next(int32_t) overload returns random integers that range from 0 to max_value – 1. However, if max_value is 0, the method returns 0.
    virtual int32_t next(int32_t max_value) const {return next(0, max_value);}
    
    /// @brief Returns a nonnegative random number less than the specified maximum.
    /// @param max_value The exclusive upper bound of the random number to be generated. max_value must be greater than or equal to zero.
    /// @return A value_t greater than or equal to zero and less than max_value
    /// @exception argument_out_of_range_exception max_value is less than zero.
    /// @remarks The next(value_t) overload returns random integers that range from 0 to max_value – 1. However, if max_value is 0, the method returns 0.
    template<typename value_t>
    value_t next(value_t max_value) const {return next(0, max_value);}

    /// @brief Returns a random number within a specified range.
    /// @param min_value The inclusive lower bound of the random number returned
    /// @param max_value The exclusive upper bound of the random number returned. max_value must be greater than or equal to min_value.
    /// @return A 32-bit signed integer greater than or equal to min_value and less than max_value
    /// @exception argument_out_of_range_exception min_value is greater than max_value.
    /// @remarks The next(int32_t, int32_t) overload returns random integers that range from min_value to max_value – 1. However, if max_value equals min_value, the method returns min_value.
    /// @remarks Unlike the other overloads of the next method, which return only non-negative values, this method can return a negative random integer.
    virtual int32_t next(int32_t min_value, int32_t max_value) const {
      if (min_value > max_value) throw argument_out_of_range_exception(current_stack_frame_);
      if (min_value == max_value) return min_value;
      return min_value + static_cast<int32_t>(std::round(sample() * std::numeric_limits<int32_t>::max())) % ((max_value - 1) - min_value + 1);
    }

    /// @brief Returns a random number within a specified range.
    /// @param min_value The inclusive lower bound of the random number returned
    /// @param max_value The exclusive upper bound of the random number returned. max_value must be greater than or equal to min_value.
    /// @return A value_t greater than or equal to min_value and less than max_value
    /// @exception argument_out_of_range_exception min_value is greater than max_value.
    /// @remarks The next(value_t, value_t) overload returns random integers that range from min_value to max_value – 1. However, if max_value equals min_value, the method returns min_value.
    /// @remarks Unlike the other overloads of the next method, which return only non-negative values, this method can return a negative random integer.
    template<typename value_t>
    value_t next(value_t min_value, value_t max_value) const {
      if (min_value > max_value) throw argument_out_of_range_exception(current_stack_frame_);
      if (min_value == max_value) return min_value;
      return min_value + static_cast<value_t>(std::round(sample() * std::numeric_limits<value_t>::max())) % ((max_value - 1) - min_value + 1);
    }

    /// @brief Fills the elements of a specified array of bytes with random numbers.
    /// @param buffer An array of bytes to contain random numbers.
    /// @remarks Each element of the array of bytes is set to a random number greater than or equal to zero, and less than or equal to std::numeric_limits<uint8_t>::max().
    virtual void next_bytes(std::vector<uint8_t>& buffer) const {next_bytes(buffer.data(), buffer.size());}

    /// @brief Fills the elements of a specified array of bytes with random numbers.
    /// @param buffer An array of bytes to contain random numbers.
    /// @exception argument_null_exception buffer is null.
    /// @remarks Each element of the array of bytes is set to a random number greater than or equal to zero, and less than or equal to std::numeric_limits<uint8_t>::max().
    virtual void next_bytes(uint8_t* buffer, size_t buffer_size) const {
      if (buffer == nullptr) throw argument_null_exception(current_stack_frame_);
      for (size_t index = 0; index < buffer_size; index++)
        buffer[index] = next<uint8_t>(0, std::numeric_limits<uint8_t>::max());
    }

    /// @brief Fills the elements of a specified array of bytes with random numbers.
    /// @param buffer An array of bytes to contain random numbers.
    /// @remarks Each element of the array of bytes is set to a random number greater than or equal to zero, and less than or equal to std::numeric_limits<value_t>::max().
    template<typename value_t>
    void next_values(std::vector<value_t>& buffer) const {next_values(buffer.data(), buffer.size());}
    
    /// @brief Fills the elements of a specified array of bytes with random numbers.
    /// @param buffer An array of value_t to contain random numbers.
    /// @exception argument_null_exception buffer is null.
    /// @remarks Each element of the array of values is set to a random number greater than or equal to zero, and less than or equal to std::numeric_limits<value_t>::max().
    template<typename value_t>
    void next_values(value_t* buffer, size_t buffer_size) const {
      if (buffer == nullptr) throw argument_null_exception(current_stack_frame_);
      for (size_t index = 0; index < buffer_size; index++)
      buffer[index] = next<value_t>(0, std::numeric_limits<value_t>::max());
    }

    /// @brief Returns a random number between 0.0 and 1.0
    /// @return A double-precision floating point number greater than or equal to 0.0, and less than 1.0.
    /// @remarks This method is the public version of the protected method, sample
    virtual double next_double() const{return sample();}
    
  protected:
    /// @brief Returns a random number between 0.0 and 1.0
    /// @return A double-precision floating point number greater than or equal to 0.0, and less than 1.0.
    /// @remarks To produce a different random distribution or a different random number generator principle, derive a class from the random class and virtual the sample method.
    virtual double sample() const {
      static std::uniform_real_distribution<> distribution_(0, 1);
      return distribution_(generator_);
    }

  private:
    mutable std::default_random_engine generator_;
  };
}
