
// calcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calc.h"
#include "calcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalcDlg 对话框



CcalcDlg::CcalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
	, ima1(0)
	, rea1(0)
	, ima2(0)
	, rea2(0)
	, ima3(0)
	, rea3(0)
	, chosenOp(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, plus_minus);
	DDX_Text(pDX, IDC_EDIT1, ima1);
	DDX_Text(pDX, IDC_EDIT2, rea1);
	DDX_Text(pDX, IDC_EDIT3, ima2);
	DDX_Text(pDX, IDC_EDIT4, rea2);
	DDX_Text(pDX, IDC_EDIT5, ima3);
	DDX_Text(pDX, IDC_EDIT6, rea3);
	DDX_CBString(pDX, IDC_COMBO2, chosenOp);
}

BEGIN_MESSAGE_MAP(CcalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO2, &CcalcDlg::OnCbnSelchangeCombo2)
	ON_EN_CHANGE(IDC_EDIT2, &CcalcDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT6, &CcalcDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDOK, &CcalcDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CcalcDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CcalcDlg 消息处理程序

BOOL CcalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//初始化combobox
	plus_minus.AddString(_T("+"));
	plus_minus.AddString(_T("-"));
	plus_minus.AddString(_T("*"));
	plus_minus.AddString(_T("/"));

	plus_minus.SetCurSel(3);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalcDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcalcDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CcalcDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcalcDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CcalcDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcalcDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcalcDlg::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CcalcDlg::OnBnClickedOk()
{
	 //TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	double base = 0;
	UpdateData(TRUE);

	if (chosenOp == '+') {
		rea3 = rea1 + rea2;
		ima3 = ima1 + ima2;
	}
	else if (chosenOp == '-') {
		rea3 = rea1 - rea2;
		ima3 = ima1 - ima2;
	}
	else if (chosenOp == '*') {
		rea3 = rea1*rea2 - ima1*ima2;
		ima3 = rea1*ima2 + rea2*ima1;
	}
	else if (chosenOp == '/') {
		base = ima2*ima2 + rea2*rea2;

		rea3 = (rea1*rea2 + ima1*ima2) / base;
		ima3 = (rea1*ima2 - rea2*ima1) / base;
	}
	else {
		//error 
	}

	UpdateData(false);
}


void CcalcDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();

	UpdateData(TRUE);
	ima1 = ima2 = 0;
	rea1 = rea2 = 0;
	rea3 = ima3 = 0;
	UpdateData(FALSE);
}
