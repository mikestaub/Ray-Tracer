///////////////////////////////////////////////////////////////////////////////
// Name:        wx/msw/apptrait.h
// Purpose:     class implementing wxAppTraits for MSW
// Author:      Vadim Zeitlin
// Modified by:
// Created:     21.06.2003
// RCS-ID:      $Id: apptrait.h,v 1.7 2006/08/13 20:59:59 VZ Exp $
// Copyright:   (c) 2003 Vadim Zeitlin <vadim@wxwidgets.org>
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_MSW_APPTRAIT_H_
#define _WX_MSW_APPTRAIT_H_

// ----------------------------------------------------------------------------
// wxGUI/ConsoleAppTraits: must derive from wxAppTraits, not wxAppTraitsBase
// ----------------------------------------------------------------------------

class WXDLLIMPEXP_BASE wxConsoleAppTraits : public wxConsoleAppTraitsBase
{
public:
    virtual void *BeforeChildWaitLoop();
    virtual void AlwaysYield();
    virtual void AfterChildWaitLoop(void *data);

    virtual bool DoMessageFromThreadWait();
};

#if wxUSE_GUI

class WXDLLIMPEXP_CORE wxGUIAppTraits : public wxGUIAppTraitsBase
{
public:
    virtual void *BeforeChildWaitLoop();
    virtual void AlwaysYield();
    virtual void AfterChildWaitLoop(void *data);

    virtual bool DoMessageFromThreadWait();
    virtual wxPortId GetToolkitVersion(int *majVer, int *minVer) const;
};

#endif // wxUSE_GUI

#endif // _WX_MSW_APPTRAIT_H_

