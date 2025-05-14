progress_dialog::show_dialog() // Shows modal progress dialog on appication
progress_dialog::show_dialog(const iwin32_window& owner) // Shows modal progress dialog on a form (specified by handle from iw32_window)
progress_dialog::show_sheet_dialog(const iwin32_window& owner) // Shows sheet modal progress dialog on a form (specified by handle from iw32_window)
progress_dialog::show() // Shows modeless progress dialog
progress_dialog::show(const iwin32_window& owner) // Shows modeless progress dialog on a form (specified by handle from iw32_window)
progress_dialog::show_sheet(const iwin32_window& owner) // Shows sheet modeless progress dialog on a form (specified by handle from iw32_window) 

// Remarks : Sheet is a special dialog mode on macOS :
// * TThe dialog is shown centered on form (if form is specifed) without title.
// * The method is not blocking and you must retrieve the result of the dialog at the closing event.
// * On other platforms than macOS, is a normal dialog, but you must also retrieve the result of the dialog on the close event but the method is blocking (this can be changed in the future).
