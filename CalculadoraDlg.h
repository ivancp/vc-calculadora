// CalculadoraDlg.h : header file
//

#if !defined(AFX_CALCULADORADLG_H__6CA0AFC1_4721_45E1_AF01_B96C6BC3FCCF__INCLUDED_)
#define AFX_CALCULADORADLG_H__6CA0AFC1_4721_45E1_AF01_B96C6BC3FCCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalculadoraDlg dialog

class CCalculadoraDlg : public CDialog
{
// Construction
public:
	void OnCancel();

	CCalculadoraDlg(CWnd* pParent = NULL);	// standard constructor

	CBrush* m_pEditBkBrush;
	CFont m_fontBold;

// Dialog Data
	//{{AFX_DATA(CCalculadoraDlg)
	enum { IDD = IDD_CALCULADORA_DIALOG };
	CString	m_sNumero;
	//}}AFX_DATA

	//CString m_sNumero;
	double  m_dMemoria;
	bool m_bHayMemoria;
	bool m_bHayResultado;
	int nOperacion;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculadoraDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalculadoraDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClear();
	afx_msg void OnPunto();
	afx_msg void OnIgual();
	afx_msg void OnRetro();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDestroy();
	afx_msg void OnSalir();
	afx_msg void OnAbout();
	//}}AFX_MSG
	afx_msg void OnClickNumeros(UINT nID);
	afx_msg void OnClickOperaciones(UINT nID);
	afx_msg void OnClickOperacionesUnarias(UINT nID);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULADORADLG_H__6CA0AFC1_4721_45E1_AF01_B96C6BC3FCCF__INCLUDED_)
