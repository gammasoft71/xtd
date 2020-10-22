# Doxygen dark theme

Theme implements dark colors implementation for doxygen documentation generator.
Selected colors are inspiration from Sublime Text syntax highligher for C language.

## Demo

Demo of the dark theme is available at https://majerle.eu/documentation/esp_at/html/index.html

# How to use it

Usage is very simple. You just need to modify your doxygen input file

```
# Add files to extra stylesheet

HTML_EXTRA_STYLESHEET  = "custom.css" \
                         "custom_dark_theme.css"
```

If you wish to use custom made HTML header and footer, enable this feature with

```
# Custom header
HTML_HEADER            = "html_header.html"

# Custom footer
HTML_FOOTER            = "html_footer.html"
```
