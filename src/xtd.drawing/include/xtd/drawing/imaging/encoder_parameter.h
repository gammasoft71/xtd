/// @file
/// @brief Contains xtd::drawing::imaging::encoder_parameter class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "encoder.h"
#include "encoder_parameter_value_type.h"
#include <xtd/iequatable>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd.drawing.imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder_parameter class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief Used to pass a value, or an array of values, to an image encoder.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      class encoder_parameter final : public object, public xtd::iequatable<encoder_parameter> {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified xtd::drawing::imaging::encoder object and one unsigned 8-bit integer. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to xtd::drawing::imaging::encoder_parameter_value_type::value_type_byte, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to 1.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param value An 8-bit unsigned integer that specifies the value stored in the xtd::drawing::imaging::encoder_parameter object.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, xtd::byte value);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified xtd::drawing::imaging::encoder object and one unsigned 16-bit integer. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to xtd::drawing::imaging::encoder_parameter_value_type::value_type_short, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to 1.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param value An 16-bit signed integer that specifies the value stored in the xtd::drawing::imaging::encoder_parameter object.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, int16 value);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified xtd::drawing::imaging::encoder object and one unsigned 16-bit integer. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to xtd::drawing::imaging::encoder_parameter_value_type::value_type_long, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to 1.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param value A 64-bit integer that specifies the value stored in the xtd::drawing::imaging::encoder_parameter object. Must be nonnegative. This parameter is converted to a 32-bit integer before it is stored in the xtd::drawing::imaging::encoder_parameter object.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, int64 value);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified xtd::drawing::imaging::encoder object and a character string. The string is converted to a null-terminated ASCII string before it is stored in the xtd::drawing::imaging::encoder_parameter object. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to xtd::drawing::imaging::encoder_parameter_value_type::value_type_ascii, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to the length of the ASCII string including the NULL terminator.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param value A xtd::utring that specifies the value stored in the xtd::drawing::imaging::encoder_parameter object.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, const xtd::ustring& value);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified Encoder object and one 8-bit value. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to xtd::drawing::imaging::encoder_parameter_value_type::value_type_undefined or xtd::drawing::imaging::encoder_parameter_value_type::value_type_byte, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to 1.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param value A byte that specifies the value stored in the xtd::drawing::imaging::encoder_parameter object.
        /// @param undefined If true, the xtd::drawing::imaging::encoder_parameter::value_type property is set to xtd::drawing::imaging::encoder_parameter_value_type::value_type_undefined; otherwise, the xtd::drawing::imaging::encoder_parameter::value_type property is set to xtd::drawing::imaging::encoder_parameter_value_type::value_type_byte.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, xtd::byte value, bool undefined);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified Encoder object and an array of unsigned 8-bit integers. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to xtd::drawing::imaging::encoder_parameter_value_type::value_type_byte, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to the number of elements in the array.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param value An array of 8-bit unsigned integers that specifies the values stored in the xtd::drawing::imaging::encoder_parameter object.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<xtd::byte> value);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified Encoder object and an array of signed 16-bit integers. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to ValueTypeShort, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to the number of elements in the array.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param value An array of 16-bit signed integers that specifies the values stored in the xtd::drawing::imaging::encoder_parameter object.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<int16> value);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified Encoder object and an array of signed 32-bit integers. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to ValueTypeLong, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to the number of elements in the array.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param value An array of 32-bit signed integers that specifies the values stored in the xtd::drawing::imaging::encoder_parameter object.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<int32> value);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified Encoder object and an array of signed 32-bit integers. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to ValueTypeLong, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to the number of elements in the array.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param value An array of 64-bit integers that specifies the values stored in the xtd::drawing::imaging::encoder_parameter object. The integers in the array must be nonnegative. The 64-bit integers are converted to 32-bit integers before they are stored in the xtd::drawing::imaging::encoder_parameter object.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<int64> value);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified Encoder object and an array of bytes. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to xtd::drawing::imaging::encoder_parameter_value_type::value_type_undefined or xtd::drawing::imaging::encoder_parameter_value_type::value_type_byte, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to the number of elements in the array.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param value An array of bytes that specifies the values stored in the xtd::drawing::imaging::encoder_parameter object.
        /// @param undefined If true, the xtd::drawing::imaging::encoder_parameter::value_type property is set to xtd::drawing::imaging::encoder_parameter_value_type::value_type_undefined; otherwise, the xtd::drawing::imaging::encoder_parameter::value_type property is set to xtd::drawing::imaging::encoder_parameter_value_type::value_type_byte.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<xtd::byte> value, bool undefined);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified xtd::drawing::imaging::encoder object and a pair of 32-bit integers. The pair of integers represents a fraction, the first integer being the numerator, and the second integer being the denominator. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to xtd::drawing::imaging::encoder_parameter_value_type:value_type_rational, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to 1.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param numerator A 32-bit integer that represents the numerator of a fraction. Must be nonnegative.
        /// @param denominator A 32-bit integer that represents the denominator of a fraction. Must be nonnegative.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, int32 numerator, int32 denominator);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified Encoder object and four, 32-bit integers. The four integers represent a range of fractions. The first two integers represent the smallest fraction in the range, and the remaining two integers represent the largest fraction in the range. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to ValueTypeRationalRange, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to 1.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param numerator1 A 32-bit integer that represents the numerator of the smallest fraction in the range. Must be nonnegative.
        /// @param denominator1 A 32-bit integer that represents the denominator of the smallest fraction in the range. Must be nonnegative.
        /// @param numerator2 A 32-bit integer that represents the denominator of the smallest fraction in the range. Must be nonnegative.
        /// @param denominator2 A 32-bit integer that represents the numerator of the largest fraction in the range. Must be nonnegative.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, int32 numerator1, int32 denominator1, int32 numerator2, int32 denominator2);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified Encoder object and two arrays of 32-bit integers. The two arrays represent an array of fractions. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to ValueTypeRational, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to the number of elements in the numerator array, which must be the same as the number of elements in the denominator array.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param numerator An array of 32-bit integers that specifies the numerators of the fractions. The integers in the array must be nonnegative.
        /// @param denominator1 An array of 32-bit integers that specifies the denominators of the fractions. The integers in the array must be nonnegative. A denominator of a given index is paired with the numerator of the same index.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<int32> numerator, std::vector<int32> denominator);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified Encoder object and two arrays of 64-bit integers. The two arrays represent an array integer ranges. Sets the xtd::drawing::imaging::encoder_parameter::value_type property to ValueTypeLongRange, and sets the xtd::drawing::imaging::encoder_parameter::number_of_values property to the number of elements in the rangebegin array, which must be the same as the number of elements in the rangeend array.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param rangebegin An array of 64-bit integers that specifies the minimum values for the integer ranges. The integers in the array must be nonnegative. The 64-bit integers are converted to 32-bit integers before they are stored in the xtd::drawing::imaging::encoder_parameter object.
        /// @param rangeend An array of 64-bit integers that specifies the maximum values for the integer ranges. The integers in the array must be nonnegative. The 64-bit integers are converted to 32-bit integers before they are stored in the EncoderParameters object. A maximum value of a given index is paired with the minimum value of the same index.
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, std::vector<int64> rangebegin, std::vector<int64> rangeend);
        /// @brief Initializes a new instance of the xtd::drawing::imaging::encoder_parameter class with the specified Encoder object, number of values, data type of the values, and a pointer to the values stored in the xtd::drawing::imaging::encoder_parameter object.
        /// @param encoder An xtd::drawing::imaging::encoder object that encapsulates the globally unique identifier of the parameter category.
        /// @param type
        /// @param value
        encoder_parameter(const xtd::drawing::imaging::encoder& encoder, int32 number_values, xtd::drawing::imaging::encoder_parameter_value_type type, const std::vector<xtd::byte>& value);
        /// @}
        
        /// @cond
        encoder_parameter() = default;
        encoder_parameter(const encoder_parameter&) = default;
        encoder_parameter& operator =(const encoder_parameter&) = default;
        /// @endcond
        
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the Encoder object associated with this xtd::drawing::imaging::encoder_parameter object. The Encoder object encapsulates the globally unique identifier (GUID) that specifies the category (for example Quality, ColorDepth, or Compression) of the parameter stored in this xtd::drawing::imaging::encoder_parameter object.
        /// @return An Encoder object that encapsulates the GUID that specifies the category of the parameter stored in this xtd::drawing::imaging::encoder_parameter object.
        const xtd::drawing::imaging::encoder& encoder() const noexcept;
        /// @brief Sets the Encoder object associated with this xtd::drawing::imaging::encoder_parameter object. The Encoder object encapsulates the globally unique identifier (GUID) that specifies the category (for example Quality, ColorDepth, or Compression) of the parameter stored in this xtd::drawing::imaging::encoder_parameter object.
        /// @param value An Encoder object that encapsulates the GUID that specifies the category of the parameter stored in this xtd::drawing::imaging::encoder_parameter object.
        /// @return This current instance.
        encoder_parameter& encoder(const xtd::drawing::imaging::encoder& value);
        
        /// @brief Gets the number of elements in the array of values stored in this xtd::drawing::imaging::encoder_parameter object.
        /// @return An integer that indicates the number of elements in the array of values stored in this xtd::drawing::imaging::encoder_parameter object.
        size_t number_of_values() const noexcept;
        
        /// @brief Gets the data type of the values stored in this xtd::drawing::imaging::encoder_parameter object.
        /// @return A member of the EncoderParameterValueType enumeration that indicates the data type of the values stored in this xtd::drawing::imaging::encoder_parameter object.
        xtd::drawing::imaging::encoder_parameter_value_type value_type() const noexcept;
        
        /// @brief Gets The data value.
        /// @return The data value.
        const std::vector<xtd::byte>& value() const noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const encoder_parameter& value) const noexcept override;
        /// @}
        
      private:
        xtd::drawing::imaging::encoder encoder_;
        
        size_t number_of_values_ = 0;
        
        xtd::drawing::imaging::encoder_parameter_value_type type_ = static_cast<xtd::drawing::imaging::encoder_parameter_value_type>(0);
        
        std::vector<xtd::byte> value_;
      };
    }
  }
}
