/////////////////////////////////////////////////////////////////////////////
// Name:        wx/generic/busyinfo.h
// Purpose:     Information window (when app is busy)
// Author:      Vaclav Slavik
// Copyright:   (c) 1999 Vaclav Slavik
// RCS-ID:      $Id: busyinfo.h,v 1.2 2006/01/26 18:58:40 ABX Exp $
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef __BUSYINFO_H__
#define __BUSYINFO_H__

#include "wx/defs.h"

#if wxUSE_BUSYINFO

class WXDLLIMPEXP_CORE wxFrame;

//--------------------------------------------------------------------------------
// wxBusyInfo
//                  Displays progress information
//                  Can be used in exactly same way as wxBusyCursor
//--------------------------------------------------------------------------------

class WXDLLEXPORT wxBusyInfo : public wxObject
{
public:
    wxBusyInfo(const wxString& message, wxWindow *parent = NULL);

    virtual ~wxBusyInfo();

private:
    wxFrame *m_InfoFrame;

    DECLARE_NO_COPY_CLASS(wxBusyInfo)
};


#endif // wxUSE_BUSYINFO

#endif // __BUSYINFO_H__
