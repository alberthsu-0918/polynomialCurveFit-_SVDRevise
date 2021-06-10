
// polynomialCurveFit.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CpolynomialCurveFitApp:
// See polynomialCurveFit.cpp for the implementation of this class
//

class CpolynomialCurveFitApp : public CWinApp
{
public:
	CpolynomialCurveFitApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CpolynomialCurveFitApp theApp;