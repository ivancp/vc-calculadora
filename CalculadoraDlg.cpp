// CalculadoraDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculadora.h"
#include "CalculadoraDlg.h"
#include "math.h"

/////////////////////////////////////////////////////////////////////////////
// CCalculadoraDlg dialog

CCalculadoraDlg::CCalculadoraDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculadoraDlg::IDD, pParent)
{
	m_dMemoria = 0;
	m_bHayResultado = false;
	nOperacion = 0;
	m_bHayMemoria = false;
	//{{AFX_DATA_INIT(CCalculadoraDlg)
	m_sNumero = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculadoraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculadoraDlg)
	DDX_Text(pDX, IDC_NUMERO, m_sNumero);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalculadoraDlg, CDialog)
	//{{AFX_MSG_MAP(CCalculadoraDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_C, OnClear)
	ON_BN_CLICKED(IDC_PUNTO, OnPunto)
	ON_BN_CLICKED(IDC_IGUAL, OnIgual)
	ON_BN_CLICKED(IDC_RETRO, OnRetro)
	ON_WM_CTLCOLOR()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_SALIR, OnSalir)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(IDC_0, IDC_9,OnClickNumeros)
	ON_COMMAND_RANGE(IDC_SUMA, IDC_XY,OnClickOperaciones)
	ON_COMMAND_RANGE(IDC_RAIZ, IDC_NFACT,OnClickOperacionesUnarias)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCalculadoraDlg message handlers

BOOL CCalculadoraDlg::OnInitDialog()
{
	m_pEditBkBrush = new CBrush(RGB(255, 255, 255));

	//FUENTE : Negrita
	{
		m_fontBold.CreateStockObject(DEFAULT_GUI_FONT);
		LOGFONT lf;
		m_fontBold.GetLogFont(&lf);
		lf.lfWeight = FW_BOLD;
		strcpy(lf.lfFaceName,"Arial");
		lf.lfHeight = 20;
		m_fontBold.DeleteObject();
		m_fontBold.CreateFontIndirect(&lf);
	}

	CDialog::OnInitDialog();

	GetDlgItem(IDC_0)->SetFont(&m_fontBold);
	GetDlgItem(IDC_1)->SetFont(&m_fontBold);
	GetDlgItem(IDC_2)->SetFont(&m_fontBold);
	GetDlgItem(IDC_3)->SetFont(&m_fontBold);
	GetDlgItem(IDC_4)->SetFont(&m_fontBold);
	GetDlgItem(IDC_5)->SetFont(&m_fontBold);
	GetDlgItem(IDC_6)->SetFont(&m_fontBold);
	GetDlgItem(IDC_7)->SetFont(&m_fontBold);
	GetDlgItem(IDC_8)->SetFont(&m_fontBold);
	GetDlgItem(IDC_9)->SetFont(&m_fontBold);
	GetDlgItem(IDC_NUMERO)->SetFont(&m_fontBold);
	GetDlgItem(IDC_PUNTO)->SetFont(&m_fontBold);
	GetDlgItem(IDC_IGUAL)->SetFont(&m_fontBold);
	


	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

void CCalculadoraDlg::OnClickNumeros(UINT ID) 
{
	UpdateData();
	if (m_bHayResultado)
	{
		m_sNumero = "";
		m_bHayResultado = false;
	}
	int numero = ID - (IDC_0);
	m_sNumero += char(numero + '0');
	UpdateData(FALSE);
}

void CCalculadoraDlg::OnClear() 
{
	m_sNumero = "0";
	m_bHayMemoria = false;
	m_bHayResultado = true;
	UpdateData(FALSE);
}

void CCalculadoraDlg::OnPunto() 
{
	UpdateData();

	if (m_bHayResultado)
	{
		m_sNumero = "";
		m_bHayResultado = false;
	}

	if(m_sNumero.Find(".") == -1)
	{
		m_sNumero += ".";
		UpdateData(FALSE);
	}
}

void CCalculadoraDlg::OnClickOperaciones(UINT ID) 
{
	if(!m_bHayMemoria)
	{
		UpdateData();
		
		m_dMemoria = atof(m_sNumero);
		m_sNumero = "";
		m_bHayMemoria = true;
		UpdateData(FALSE);	
		
	}
	nOperacion = ID;
}

void CCalculadoraDlg::OnIgual() 
{
	UpdateData();
	double dNumeroActual = atof(m_sNumero);
	double dRes = 0;
	switch(nOperacion)
	{
		case IDC_SUMA:		
			dRes = dNumeroActual + m_dMemoria;
			break;
		case IDC_RESTA:
			dRes = m_dMemoria - dNumeroActual ;
			break;
		case IDC_MULT:
			dRes = dNumeroActual * m_dMemoria;
			break;
		case IDC_DIV:
			if(dNumeroActual == 0)
				MessageBox("Division por cero");
			else
				dRes = m_dMemoria/dNumeroActual;
			break;
		case IDC_XY:
			dRes = pow(m_dMemoria,dNumeroActual);
			break;
	}
	m_sNumero.Format("%.10f",dRes);
	m_sNumero.TrimRight('0');
	m_bHayMemoria = false;
	m_bHayResultado = true;
	UpdateData(FALSE);
}

void CCalculadoraDlg::OnClickOperacionesUnarias(UINT ID) 
{
	UpdateData();
	double dNum = atof(m_sNumero);
	double dRes = 0.0;
	OnClear();
	switch(ID)
	{
		case  IDC_RAIZ:
			if(dNum < 0.0)
				MessageBox("Raiz de negativo");
			else
				dRes = sqrt(dNum);
			break;
		case  IDC_SEN:
			dRes = sin(dNum);
			break;
		case  IDC_X3:
			dRes = dNum*dNum*dNum;
			break;
		case  IDC_X2:
			dRes = dNum*dNum;
			break;
		case  IDC_COS:
			dRes = cos(dNum);
			break;
		case  IDC_TAN:
			dRes = tan(dNum);
			break;
		case  IDC_1_X:
			if(dNum == 0.0)
				MessageBox("Division por cero");
			else
				dRes = 1/dNum;
			break;

		case IDC_PI:
			dRes = 3.1415926535897932384626433832795;
			break;
		case IDC_LN:
			if(dNum < 0.0)
				MessageBox("Logaritmo no valido");
			else
				dRes = log(dNum);
			break;
		case IDC_LOG:
			if(dNum < 0.0)
				MessageBox("Logaritmo no valido");
			else
				dRes = log10(dNum);
			break;
		case IDC_NFACT:
			{
				int veces = int(dNum);
				for(int i = 1; i <= veces;i++)
				{
					dRes += dRes * (double)i;
				}
			}
			break;
	}	
	m_sNumero.Format("%.10f",dRes);
	m_sNumero.TrimRight('0');
	m_bHayResultado = true;
	UpdateData(FALSE);
}

void CCalculadoraDlg::OnRetro() 
{
	UpdateData();
	if(m_sNumero.GetLength() > 0)
	{
		m_sNumero.Delete(m_sNumero.GetLength()-1);
	}
	UpdateData(FALSE);
}

HBRUSH CCalculadoraDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	pDC->SetTextColor(RGB(50, 50, 255));
	pDC->SetBkColor(RGB(255, 255, 255));
	return (HBRUSH)(m_pEditBkBrush);
}

void CCalculadoraDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	delete m_pEditBkBrush;	
}

BOOL CCalculadoraDlg::PreTranslateMessage(MSG* pMsg) 
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam >= VK_NUMPAD0  && pMsg->wParam <= VK_NUMPAD9  )
		{
			unsigned int btn = IDC_0 + (pMsg->wParam - VK_NUMPAD0 );
			PostMessage(WM_COMMAND,MAKEWPARAM(btn,BN_CLICKED),(LPARAM)GetDlgItem(btn)->m_hWnd);
			return TRUE;
		}
		if (pMsg->wParam >= '0' && pMsg->wParam <= '9' )
		{
			unsigned int btn = IDC_0 + (pMsg->wParam - '0');
			PostMessage(WM_COMMAND,MAKEWPARAM(btn,BN_CLICKED),(LPARAM)GetDlgItem(btn)->m_hWnd);
			return TRUE;
		}
		if (pMsg->wParam == '=' || pMsg->wParam == VK_RETURN)
		{
			OnIgual();
			return TRUE;
		}
		if (pMsg->wParam == VK_ADD)
		{
			PostMessage(WM_COMMAND,MAKEWPARAM(IDC_SUMA,BN_CLICKED),(LPARAM)GetDlgItem(IDC_SUMA)->m_hWnd);
			return TRUE;
		}

		if (pMsg->wParam == VK_SUBTRACT)
		{
			PostMessage(WM_COMMAND,MAKEWPARAM(IDC_RESTA,BN_CLICKED),(LPARAM)GetDlgItem(IDC_RESTA)->m_hWnd);
			return TRUE;
		}
		if (pMsg->wParam == VK_MULTIPLY)
		{
			PostMessage(WM_COMMAND,MAKEWPARAM(IDC_MULT,BN_CLICKED),(LPARAM)GetDlgItem(IDC_MULT)->m_hWnd);
			return TRUE;
		}

		if (pMsg->wParam == VK_DIVIDE)
		{
			PostMessage(WM_COMMAND,MAKEWPARAM(IDC_DIV,BN_CLICKED),(LPARAM)GetDlgItem(IDC_DIV)->m_hWnd);
			return TRUE;
		}
		if (pMsg->wParam == VK_DECIMAL)
		{
			PostMessage(WM_COMMAND,MAKEWPARAM(IDC_PUNTO,BN_CLICKED),(LPARAM)GetDlgItem(IDC_PUNTO)->m_hWnd);
			return TRUE;
		}
		if (pMsg->wParam == VK_ESCAPE)
		{
			PostMessage(WM_COMMAND,MAKEWPARAM(IDC_C,BN_CLICKED),(LPARAM)GetDlgItem(IDC_C)->m_hWnd);
			return TRUE;
		}
		if (pMsg->wParam == VK_BACK)
		{
			PostMessage(WM_COMMAND,MAKEWPARAM(IDC_RETRO,BN_CLICKED),(LPARAM)GetDlgItem(IDC_C)->m_hWnd);
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CCalculadoraDlg::OnCancel()
{
	//se deja en blanco para evitar que se cierre
}

void CCalculadoraDlg::OnSalir() 
{
	CDialog::OnOK();	
}

void CCalculadoraDlg::OnAbout() 
{
	CString sAbout;
	sAbout = 
		"Programa desarrollado por:\n\n"
		"Ivan Cachicatari\nivancp@latindevelopers.com\n\n"
		"Versión 1.0\n02-05-2004\n\n"
		"Latindevelopers.com";
	MessageBox(sAbout,"Acerca de Calculadora",MB_ICONINFORMATION);
}
