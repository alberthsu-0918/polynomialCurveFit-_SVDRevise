
// polynomialCurveFitDlg.cpp : implementation file
//

#include "stdafx.h"
#include "polynomialCurveFit.h"
#include "polynomialCurveFitDlg.h"
#include "afxdialogex.h"
#include "MatrixOp.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CpolynomialCurveFitDlg dialog




CpolynomialCurveFitDlg::CpolynomialCurveFitDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CpolynomialCurveFitDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CpolynomialCurveFitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CpolynomialCurveFitDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CpolynomialCurveFitDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CpolynomialCurveFitDlg message handlers

BOOL CpolynomialCurveFitDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CpolynomialCurveFitDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CpolynomialCurveFitDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CpolynomialCurveFitDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CpolynomialCurveFitDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	/*
	int err = -1;
	double **A, **B, **result;
	double det;
	A = new double*[3];
	B = new double*[3];
	result = new double*[3];
	

	for(int i=0;i<3;i++)
	{
		A[i] = new double[3];
		B[i] = new double[2];
		result[i] = new double[2];
	}

	A[0][0] = 1.2;
	A[0][1] = -2.4;
	A[0][2] = 4.1;
	A[1][0] = -5.0098;
	A[1][1] = 2.7782;
	A[1][2] = 0.113;
	A[2][0] = 1.12;
	A[2][1] = 0.177;
	A[2][2] = 3.2256;

	B[0][0] = 1;
	B[0][1] = 2;
	B[1][0] = 3;
	B[1][1] = 4;
	B[2][0] = 5;
	B[2][1] = 6;

	err = multiplyM( A, 3, 3, B, 3, 2, result);
	det = determinant(A, 3);

	double** InvA;
	InvA = new double* [3];
	for(int i=0;i<3;i++)
		InvA[i] = new double [3];
	err = inverse(A, 3, InvA);
	multiplyM( A, 3, 3, InvA, 3, 3, result);
	double TT[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			TT[i][j] = result[i][j];
		}
	}
	Sleep(1);
	*/

	//test: for inverse matrix
	/*
	FILE* testfile = fopen("test.txt", "r");
	double da;
	double **testRead, **invT, **XX;
	testRead = new double* [7];
	invT     = new double* [7];
	XX       = new double* [7];
	for(int i=0;i<7;i++)
	{
		testRead[i] = new double[7];
		invT[i]     = new double[7];
		XX[i]       = new double[7];
	}

	int testCnt = 0, testCnt2 = 0;
	while((fscanf(testfile,"%lf", &da)) !=EOF){
		
		if(testCnt == 7)
		{
			testCnt = 0;
			testCnt2++;
		}
		testRead[testCnt][testCnt2] = da;
		testCnt++;
	}

	fclose(testfile);
	inverse(testRead, 7, invT);
	double tt[7][7];
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
			tt[i][j] = invT[i][j];
	}
	multiplyM( testRead, 7, 7, invT, 7, 7, XX);
	double XXX[7][7];
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
			XXX[i][j] = XX[i][j];
	}
	*/


	// Curve Fit Test: load raw data 
	FILE* svfile, *svfilex , *svfiley;
	svfile = fopen("x.txt", "r");
	double r;
	double *x, *y, xstart, xend;
	int cnt = 0;
	while((fscanf(svfile,"%lf", &r)) !=EOF){
		cnt++;
	}
	fclose(svfile);

	x = new double[cnt];
	y = new double[cnt];

	svfilex = fopen("x.txt", "r");
	svfiley = fopen("y.txt", "r");

	int index = 0;
	while((fscanf(svfilex,"%lf", &r)) !=EOF){
		x[index] = r ;
		index++;
	}
	
	index = 0;
	while((fscanf(svfiley,"%lf", &r) !=EOF)){
		y[index] = r;
		index++;
	}

	fclose(svfilex);
	fclose(svfiley);
	xstart = x[0];
	xend = x[cnt-1];
	//end of load data

	//Curve fitting
	int polyOrder = 6;
	double* coeff = new double [polyOrder+1];

	polynomialCurvFit( x ,  y, cnt, polyOrder, coeff );

	//Find peaks. We are looking for local max and min of our fitting curve. 
	//Since local max and min happen when f'(x) = 0, we'll use newton method repeatly to find roots of f'(x) which are equalivent to local max and min  
	int result = -1;
	double* coeff_d = new double [polyOrder];

	for(int i=0;i<polyOrder; i++)
	{
		coeff_d[i] = (i+1)*coeff[i+1];
	}

	//seperate x to order parts, as initial searching points
	double* initial = new double [polyOrder];
	double* root = new double [polyOrder]; 
	double localMax = 0.0, localmin =0.0; 

	for(int i=0;i<polyOrder;i++)
	{
		initial[i] = (i+1)*(xend - xstart)/polyOrder ;
		result = newtonMethod(coeff_d, &root[i], polyOrder, initial[i], 50, 0.00001);
	}
	//result = newtonMethod(coeff_d, &root[i], polyOrder, 0.2, 50, 0.00001);


	delete [] x;
	delete [] y;
	delete [] coeff;
	delete [] coeff_d;
	delete [] initial;
	delete [] root;

	fclose(svfilex);
	fclose(svfiley);
}

