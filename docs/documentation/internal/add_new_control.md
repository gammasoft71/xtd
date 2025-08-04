# Add new control (**Internal use only**)

This procedure describes how to add a new control.

For the example we create the control light_button.

# Procedure

## xtd.forms.native

1. Add new class native API : [light_button.h](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native/include/xtd/forms/native/light_button.h)
2. Update the file [xtd.forms.native.h](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native/include/xtd/xtd.forms.native.h) and add new file created light_button.h.
3. Update the file [CMakeLists.txt](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native/CMakeLists.txt) and add new file created light_button.h.

## xtd.forms.native.wxWidgets

1. Add new wxwidgestt helper class : [wx_light_button.h](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.wxwidgets/includde/xtd/forms/native/wxwigets/wx_light_button.h)
2. Add new native source file : [light_button.cpp](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.wxwidgets/src/xtd/forms/native/wxwigets/light_button.cpp)
3. Update the file [CMakeLists.txt](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.wxwidgets/CMakeLists.txt) and add new files created wx_light_button.h and light_button.cpp.
4. Update [control.cpp](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms.native.wxwidgets/src/xtd/forms/native/wxwigets/control.cpp) :
  * Add wx_light_button include file.
  * add in control::crrate method the following line :
  ```
  if (create_params.class_name() == "lightbutton") return set_control_extra_options(reinterpret_cast<intptr_t>(new wx_light_button(create_params)));
  ```

## xtd.forms

1. Add new class header file : [light_button.h](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms/include/xtd/forms/light_button.h)
2. Add new class source file : [light_button.h](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms/src/xtd/forms/light_button.cpp)
3. Update the file [xtd.forms.h](https://github.com/gammasoft71/xtd/tree/master/src/xtd.forms/include/xtd/xtd.forms.h) and add new file created light_button.h.

As all methods of xtd::form::native::light_button are protected , if you need access to its methos, verify that xtd::forms::light_button class is friend of xtd::forms::native::light_button class.
As all methods of xtd::form::native::control are protected, verify that xtd::forms::light_button class is friend of xtd::forms::native::control class.

## Test

Create un simple test to verify the chain is correct.

## Implementation

Add the specific implemntation for the new control...

## Documentation

Add Doxygen documentation for API.

## Example

Add an example of basic usage.
