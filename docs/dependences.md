# Dependences

## Libraries :

### tunit
* xtd.tunit :

### properties
* xtd.properties : (xtd.tunit)

### system
* xtd.delegates : (xtd.tunit)
* xtd.io : (xtd.tunit)
* xtd.strings : (xtd.tunit)
* xtd.diagnostics : xtd.io xtd.strings (xtd.tunit)
* xtd.core : xtd.io std.strings (xtd.tunit)

### console
* xtd.console : xtd.delegate xtd.diagnostics xtd.core xtd.io xtd.strings (xtd.tunit)

### winforms
* xtd.drawing : xtd.core xtd.strings (xtd.tunit)
* xtd.forms : xtd.delegates xtd.diagnostics xtd.drawing xtd.core xtd.io xtd.strings (xtd.tunit)

### xtd
* xtd : xtd.console xtd.delegates xtd.diagnostics xtd.drawing xtd.core xtd.forms xtd.io xtd.strings xtd.tunit