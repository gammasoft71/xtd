| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# wxWidgets Windows styles (**Internal use only**)

## Default styles

```c++
#define wxDEFAULT_FRAME_STYLE    wxSYSTEM_MENU|wxRESIZE_BORDER|wxMINIMIZE_BOX|wxMAXIMIZE_BOX|wxCLOSE_BOX|wxCAPTION|wxCLIP_CHILDREN
#define wxDEFAULT_DIALOG_STYLE   wxSYSTEM_MENU|wxCLOSE_BOX|wxCAPTION
```

## wxStyles definitions for wxFrame and wxDialog

```c++
#define wxCENTRE                 0x00000001
#define wxFRAME_NO_TASKBAR       0x00000002
#define wxFRAME_TOOL_WINDOW      0x00000004
#define wxFRAME_FLOAT_ON_PARENT  0x00000008

#define wxFRAME_SHAPED           0x00000010
#define wxDIALOG_NO_PARENT       0x00000020
#define wxRESIZE_BORDER          0x00000040
#define wxTINY_CAPTION           0x00000080

// Not defined value             0x00000100
#define wxMAXIMIZE_BOX           0x00000200
#define wxMINIMIZE_BOX           0x00000400
#define wxSYSTEM_MENU            0x00000800

#define wxCLOSE_BOX              0x00001000
#define wxMAXIMIZE               0x00002000
#define wxMINIMIZE               0x00004000
#define wxSTAY_ON_TOP            0x00008000

#define wxFULL_REPAINT_ON_RESIZE 0x00010000
#define wxRETAINED               0x00020000
#define wxWANTS_CHARS            0x00040000
#define wxTAB_TRAVERSAL          0x00080000

#define wxTRANSPARENT_WINDOW     0x00100000
#define wxBORDER_NONE            0x00200000
#define wxCLIP_CHILDREN          0x00400000
#define wxALWAYS_SHOW_SB         0x00800000

#define wxBORDER_STATIC          0x01000000
#define wxBORDER_SIMPLE          0x02000000
#define wxBORDER_RAISED          0x04000000
#define wxBORDER_SUNKEN          0x08000000

#define wxBORDER_THEME           0x10000000
#define wxBORDER_DOUBLE          0x10000000 // This style is obsolete and should not be used.
#define wxCAPTION                0x20000000
#define wxCLIP_SIBLINGS          0x20000000 // Note we're reusing the wxCAPTION style because we won't need captions for subwindows/control
#define wxHSCROLL                0x40000000
#define wxVSCROLL                0x80000000

#define wxICONIZE                wxMINIMIZE
#define wxBORDER                 wxBORDER_SIMPLE
```

## wxExtraStyles definitions for wxFrame and wxDialog

```c++
#define wxWS_EX_VALIDATE_RECURSIVELY    0x00000000 // This flag is obsolete and should not be used.
#define wxWS_EX_BLOCK_EVENTS            0x00000002
#define wxWS_EX_TRANSIENT               0x00000004
#define wxWS_EX_THEMED_BACKGROUND       0x00000008

#define wxWS_EX_PROCESS_IDLE            0x00000010
#define wxWS_EX_PROCESS_UI_UPDATES      0x00000020
#define wxFRAME_EX_METAL                0x00000040
#define wxWS_EX_CONTEXTHELP             0x00000080

#define wxDIALOG_EX_METAL               wxFRAME_EX_METAL
#define wxFRAME_EX_CONTEXTHELP          wxWS_EX_CONTEXTHELP
#define wxDIALOG_EX_CONTEXTHELP         wxWS_EX_CONTEXTHELP
```

## Style values examples with decomposition

0x20401840

* 0x00000040 --> wxRESIZE_BORDER
* 0x00000800 --> wxSYSTEM_MENU
* 0x00001000 --> wxCLOSE_BOX
* 0x00400000 --> wxCLIP_CHILDREN
* 0x20000000 --> wxCAPTION

## Summary of the bits used (some of them are defined in wx/frame.h and wx/dialog.h)

    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |15|14|13|12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| 1| 0|
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
      |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
      |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  \_ wxCENTRE
      |  |  |  |  |  |  |  |  |  |  |  |  |  |  \____ wxFRAME_NO_TASKBAR
      |  |  |  |  |  |  |  |  |  |  |  |  |  \_______ wxFRAME_TOOL_WINDOW
      |  |  |  |  |  |  |  |  |  |  |  |  \__________ wxFRAME_FLOAT_ON_PARENT
      |  |  |  |  |  |  |  |  |  |  |  \_____________ wxFRAME_SHAPED
      |  |  |  |  |  |  |  |  |  |  \________________ wxDIALOG_NO_PARENT
      |  |  |  |  |  |  |  |  |  \___________________ wxRESIZE_BORDER
      |  |  |  |  |  |  |  |  \______________________ wxTINY_CAPTION
      |  |  |  |  |  |  |  \_________________________
      |  |  |  |  |  |  \____________________________ wxMAXIMIZE_BOX
      |  |  |  |  |  \_______________________________ wxMINIMIZE_BOX
      |  |  |  |  \__________________________________ wxSYSTEM_MENU
      |  |  |  \_____________________________________ wxCLOSE_BOX
      |  |  \________________________________________ wxMAXIMIZE
      |  \___________________________________________ wxMINIMIZE
      \______________________________________________ wxSTAY_ON_TOP


## Summary of the bits used by various styles.

High word, containing styles which can be used with many windows:

    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
      |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
      |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  \_ wxFULL_REPAINT_ON_RESIZE
      |  |  |  |  |  |  |  |  |  |  |  |  |  |  \____ wxPOPUP_WINDOW
      |  |  |  |  |  |  |  |  |  |  |  |  |  \_______ wxWANTS_CHARS
      |  |  |  |  |  |  |  |  |  |  |  |  \__________ wxTAB_TRAVERSAL
      |  |  |  |  |  |  |  |  |  |  |  \_____________ wxTRANSPARENT_WINDOW
      |  |  |  |  |  |  |  |  |  |  \________________ wxBORDER_NONE
      |  |  |  |  |  |  |  |  |  \___________________ wxCLIP_CHILDREN
      |  |  |  |  |  |  |  |  \______________________ wxALWAYS_SHOW_SB
      |  |  |  |  |  |  |  \_________________________ wxBORDER_STATIC
      |  |  |  |  |  |  \____________________________ wxBORDER_SIMPLE
      |  |  |  |  |  \_______________________________ wxBORDER_RAISED
      |  |  |  |  \__________________________________ wxBORDER_SUNKEN
      |  |  |  \_____________________________________ wxBORDER_{DOUBLE,THEME}
      |  |  \________________________________________ wxCAPTION/wxCLIP_SIBLINGS
      |  \___________________________________________ wxHSCROLL
      \______________________________________________ wxVSCROLL
