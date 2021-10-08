| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

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