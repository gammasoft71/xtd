# Style sheets reference

Style Sheets support various properties, states, and subcontrols that make it possible to customize the look of control.

## List of System colors

The following table lists the system colors that can be customized using style sheets:

| Color                                                                                                                                          | Type                            | Description                                                                       |
|------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------|-----------------------------------------------------------------------------------|
| [accent](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a77eb861710eace25ba504b40e5b88ac2)                    | [color](#list-of-property-type) | Gets the color used to accent a control.                                          |
| [accent-text](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#ac8752bc4cd0b4cbea00bfa048d3dc213)               | [color](#list-of-property-type) | Gets the color of the text used to accent a control.                              |
| [active-border](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#ad34e4d2271162cf60ed269cd68e40ed7)             | [color](#list-of-property-type) | Gets the color of the active window's border.                                     |
| [active-caption](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a2443f7bdc3d85a6d92ca5656492f1841)            | [color](#list-of-property-type) | Gets the color of the background of the active window's title bar.                |
| [active-caption-text](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#aca50220aec7e7f797393fc92b07bc046)       | [color](#list-of-property-type) | Gets the color of the text in the active window's title bar.                      |
| [app-workspace](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a6ba40a364207f7917cd13e2723738174)             | [color](#list-of-property-type) | Gets the color of the application workspace.                                      |
| [button-face](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a2445d28bec80b10c4650c83bce81f26c)               | [color](#list-of-property-type) | Gets the face color of a 3-D element.                                             |
| [button-highlight](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#aae09d313a5ca9bacb4df47bb2c9d467f)          | [color](#list-of-property-type) | Gets the highlight color of a 3-D element.                                        |
| [button-shadow](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#ad1a13217f7961fd5fabfaa5a3c7d69b6)             | [color](#list-of-property-type) | Gets the shadow color of a 3-D element.                                           |
| [control](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#aaee26ec4d36ad4a99550bec18c258d84)                   | [color](#list-of-property-type) | Gets the face color of a 3-D element.                                             |
| [control-dark](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#ae4dc7250adfe9c039b2ae7359e56aa89)              | [color](#list-of-property-type) | Gets the shadow color of a 3-D element.                                           |
| [control-dark-dark](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#ad5994da0d32f0b00ea00a7e3f7caa39b)         | [color](#list-of-property-type) | Gets the dark shadow color of a 3-D element.                                      |
| [control-light](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#af662ced36c4405037f57c980f55a54f5)             | [color](#list-of-property-type) | Gets the light color of a 3-D element.                                            |
| [control-light-light](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a0ad4c006921a5fe3ca3ee02b1f8c5ee2)       | [color](#list-of-property-type) | Gets the highlight color of a 3-D element.                                        |
| [control-text](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a14fdf665a24633df3bcfe9523b0ad08c)              | [color](#list-of-property-type) | Gets the color of text in a 3-D element.                                          |
| [desktop](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#aaf42b49c300458e4fed3272071367415)                   | [color](#list-of-property-type) | Gets the color of the desktop.                                                    |
| [gradient-active-caption](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#abb5874b1bd537f3c71269a364ae761d5)   | [color](#list-of-property-type) | Gets the lightest color in the color gradient of an active window's title bar.    |
| [gradient-inactive-caption](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a0480d205045d45fae2b03729fb6fb969) | [color](#list-of-property-type) | Gets the lightest color in the color gradient of an inactive window's title bar.  |
| [gray-text](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#abee96e855513c498c5b19ac87d8c6363)                 | [color](#list-of-property-type) | Gets the color of dimmed text.                                                    |
| [highlight](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#ad392f5a9d5da08bd0a707cb56bff2274)                 | [color](#list-of-property-type) | Gets the color of the background of selected items.                               |
| [highlight-text](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a91fd1bd11db640a5ed33935bcc6db130)            | [color](#list-of-property-type) | Gets the color of the text of selected items.                                     |
| [hot-track](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a79b3f416c913a2d06c37783be43e5ba2)                 | [color](#list-of-property-type) | Gets the color used to designate a hot-tracked item.                              |
| [inactive-border](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a8df8f93c0b71ba16ef1d1625237b77e5)           | [color](#list-of-property-type) | Gets the color of an inactive window's border.                                    |
| [inactive-caption](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a5e30f9d8eb6c5bce6c919ed7e59adf6f)          | [color](#list-of-property-type) | Gets the color of the background of an inactive window's title bar.               |
| [inactive-caption-text](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#aca3cbd700dc165c3fd32dded0cb2bba5)     | [color](#list-of-property-type) | Gets the color of the text in an inactive window's title bar.                     |
| [info](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#aa5a390170a0429c49c8288d29a676bbe)                      | [color](#list-of-property-type) | Gets the color of the background of a xtd::forms::tool_tip.                       |
| [info-text](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a6750d40c23599b9de6362722c2320178)                 | [color](#list-of-property-type) | Gets the color of the text of a xtd::forms::tool_tip.                             |
| [menu](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a0b711825c7e16a3e1e555e0c948b4479)                      | [color](#list-of-property-type) | Gets the color of a menu's background.                                            |
| [menu-bar](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#ac45113882befd17734e86ea43a3ad7de)                  | [color](#list-of-property-type) | Gets the color of the background of a menu bar.                                   |
| [menu-highlight](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a0b30b0f26f0eac2fa5f2449b9018b6e0)            | [color](#list-of-property-type) | Gets the color used to highlight menu items when the menu appears as a flat menu. |
| [menu-text](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#ab7bcb5946102c20a39a269a82cda0257)                 | [color](#list-of-property-type) | Gets the color of a menu's text.                                                  |
| [scroll-bar](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#aae3f874c37c40a5d2ffd9981a0501cce)                | [color](#list-of-property-type) | Gets the color of the background of a scroll bar.                                 |
| [text-box](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a6b034212bc8b82c2ca5260ca0b1c24b8)                  | [color](#list-of-property-type) | Gets the color of the background of a text box.                                   |
| [text-box-text](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a3d9e99b3359fc17c05f427f8b1b26b71)             | [color](#list-of-property-type) | Gets the color of the text of a text box.                                         |
| [window](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a992da4fbd53fb2974dd5e0607392c1a5)                    | [color](#list-of-property-type) | Gets the color of the background in the client area of a window.                  |
| [window-frame](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a90ff9cd9df6bb66872cb9f1e2ae36dff)              | [color](#list-of-property-type) | Gets the color of a window frame.                                                 |
| [window-text](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1drawing_1_1system__colors.html#a0d078de37b3018a352b080d4866fef8e)               | [color](#list-of-property-type) | Gets the color of the text in the client area of a window.                        |


## List of stylable controls

The following table lists the xtd controls that can be customized using style sheets:

| Control                                                                                                     | How to style                                         |
|-------------------------------------------------------------------------------------------------------------|------------------------------------------------------|
| [button](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1button.html)                             |                                                      |
| [check_box](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1check__box.html)                      |                                                      |
| [checked_list_box](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1checked__list__box.html)       |                                                      |
| [choice](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1choice.html)                             |                                                      |
| [color_picker](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1color__picker.html)                |                                                      |
| [combo_box](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1combo__box.html)                      |                                                      |
| [check_box](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1check__box.html)                      |                                                      |
| [command_link_button](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1command__link__button.html) |                                                      |
| [date_time_picker](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1date__time__picker.html)       |                                                      |
| [domain_up_down](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1domain__up__down.html)           |                                                      |
| [font_picker](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1font__picker.html)                  |                                                      |
| [h_scroll_bar](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1h__scroll__bar.html)               |                                                      |
| [label](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1label.html)                               |                                                      |
| [light_button](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1light__button.html)                |                                                      |
| [link_label](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1link__label.html)                    |                                                      |
| [list_box](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1list__box.html)                        |                                                      |
| [month_calendar](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1month__calendar.html)            |                                                      |
| [numeric_up_down](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1numeric__up__down.html)         |                                                      |
| [picture_box](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1picture__box.html)                  |                                                      |
| [progress_bar](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1progress__bar.html)                |                                                      |
| [radio_button](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1radio__button.html)                |                                                      |
| [switch_button](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1switch__button.html)              |                                                      |
| [text_box](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1text__box.html)                        |                                                      |
| [toggle_button](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1toggle__button.html)              |                                                      |
| [track_bar](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1track__bar.html)                      |                                                      |
| [up_down_button](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1up__down__button.html)           |                                                      |
| [v_scroll_bar](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1v__scroll__bar.html)               |                                                      |

## List of properties

## List of images

## List of property type

| Type  | Syntax                                           | Description                                                                                                                                                |
|-------|--------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------|
| color | \| #aarrggbb<br>\| color name<br>\| system color | Specifies a color as ARGB in hexadecimal (e.g. blue : #FF0000FF)<br>Specifie a color by name (e.g. darkblue)<br>Specifie a system color (e.g. button-face) |

## List of states

## List of sub-controls

