/**********************************************************************

  Audacity: A Digital Audio Editor

  ErrorDialog.h

  Jimmy Johnson
  James Crook

**********************************************************************/

#ifndef __AUDACITY_ERRORDIALOG__
#define __AUDACITY_ERRORDIALOG__



#include <wx/defs.h>
#include <wx/msgdlg.h> // to inherit
#include "wxPanelWrapper.h" // to inherit

class AudacityProject;
class wxCollapsiblePaneEvent;

class ErrorDialog /* not final */ : public wxDialogWrapper
{
public:
   // constructors and destructors
   ErrorDialog(wxWindow *parent,
      const TranslatableString & dlogTitle,
      const TranslatableString & message,
      const wxString & helpPage,
<<<<<<< HEAD
      const ManualPageID & helpPage,
=======
>>>>>>> parent of cfbdd2d22 (Type alias ManualPageID for wxString used in many places...)
      const wxString & log,
      const bool Close = true, const bool modal = true);

   virtual ~ErrorDialog(){}

private:
   wxString dhelpPage;
   bool dClose;
   bool dModal;

   void OnPane( wxCollapsiblePaneEvent &event );
   void OnOk( wxCommandEvent &event );
   void OnHelp( wxCommandEvent &event );
   DECLARE_EVENT_TABLE()
};

/// Displays an error dialog with a button that offers help
AUDACITY_DLL_API
void ShowErrorDialog(wxWindow *parent,
                     const TranslatableString &dlogTitle,
                     const TranslatableString &message,
                     const wxString &helpPage,
                     bool Close = true,
                     const wxString &log = {});

/// Displays an error dialog, possibly allowing to send error report.
AUDACITY_DLL_API
void ShowExceptionDialog(
   wxWindow* parent, const TranslatableString& dlogTitle,
   const TranslatableString& message, const wxString& helpPage,
   bool Close = true, const wxString& log = {});

/// Displays a modeless error dialog with a button that offers help
void ShowModelessErrorDialog(wxWindow *parent,
                     const TranslatableString &dlogTitle,
                     const TranslatableString &message,
                     const wxString &helpPage,
                     bool Close = true,
                     const wxString &log = {});

#include <wx/textdlg.h> // to inherit

/**************************************************************************//**
\class AudacityTextEntryDialog
\brief Wrap wxTextEntryDialog so that caption IS translatable.
********************************************************************************/
class AUDACITY_DLL_API AudacityTextEntryDialog
   : public wxTabTraversalWrapper< wxTextEntryDialog >
{
public:
    AudacityTextEntryDialog(
         wxWindow *parent,
         const TranslatableString& message,
         const TranslatableString& caption, // don't use = wxGetTextFromUserPromptStr,
         const wxString& value = {},
         long style = wxTextEntryDialogStyle,
         const wxPoint& pos = wxDefaultPosition)
   : wxTabTraversalWrapper< wxTextEntryDialog>(
      parent,
      message.Translation(), caption.Translation(), value, style, pos )
   {}
   
   void SetInsertionPointEnd();
   bool Show(bool show = true) override;

private:
   bool mSetInsertionPointEnd{};
};

#endif // __AUDACITY_ERRORDIALOG__
