// Calculadora.h : main header file for the CALCULADORA application
//

#if !defined(AFX_CALCULADORA_H__F3291E9D_6188_4631_A933_BC7419165192__INCLUDED_)
#define AFX_CALCULADORA_H__F3291E9D_6188_4631_A933_BC7419165192__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCalculadoraApp:
// See Calculadora.cpp for the implementation of this class
//

class CCalculadoraApp : public CWinApp
{
public:
	CCalculadoraApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculadoraApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCalculadoraApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULADORA_H__F3291E9D_6188_4631_A933_BC7419165192__INCLUDED_)
