# wxStyles

## Default styles

wxDEFAULT_FRAME_STYLE  = wxSYSTEM_MENU wxRESIZE_BORDER wxMINIMIZE_BOX wxMAXIMIZE_BOX wxCLOSE_BOX wxCAPTION wxCLIP_CHILDREN

wxDEFAULT_DIALOG_STYLE = wxSYSTEM_MENU                                               wxCLOSE_BOX wxCAPTION

## Style values examples with decomposition

0x20401840

0x20001800

* 0x20000000 --> wxCAPTION
* 0x00001000 --> wxCLOSE_BOX
* 0x00000800 --> wxSYSTEM_MENU

## wxStyles definitions

```c++
#define wxDOUBLE_BORDER          0x10000000
#define wxCAPTION                0x20000000
#define wxCLIP_SIBLINGS          0x20000000
#define wxHSCROLL                0x40000000
#define wxVSCROLL                0x80000000

#define wxSTATIC_BORDER          0x01000000
#define wxBORDER                 0x02000000
#define wxSIMPLE_BORDER          0x02000000
#define wxRAISED_BORDER          0x04000000
#define wxSUNKEN_BORDER          0x08000000

#define wxTRANSPARENT_WINDOW     0x00100000
#define wxNO_BORDER              0x00200000
#define wxCLIP_CHILDREN          0x00400000
#define wxALWAYS_SHOW_SB         0x00800000

#define wxFULL_REPAINT_ON_RESIZE 0x00010000
#define wxRETAINED               0x00020000
#define wxWANTS_CHARS            0x00040000
#define wxTAB_TRAVERSAL          0x00080000

#define wxCLOSE_BOX              0x00001000
#define wxMAXIMIZE               0x00002000
#define wxICONIZE                0x00004000
#define wxMINIMIZE               0x00004000
#define wxSTAY_ON_TOP            0x00008000

#define wxMAXIMIZE_BOX           0x00000200
#define wxMINIMIZE_BOX           0x00000400
#define wxSYSTEM_MENU            0x00000800

#define wxRESIZE_BORDER          0x00000040
#define wxTINY_CAPTION           0x00000080
```


