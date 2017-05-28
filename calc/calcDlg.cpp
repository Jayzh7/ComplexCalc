
// calcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calc.h"
#include "calcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CcalcDlg �Ի���



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


// CcalcDlg ��Ϣ�������

BOOL CcalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//��ʼ��combobox
	plus_minus.AddString(_T("+"));
	plus_minus.AddString(_T("-"));
	plus_minus.AddString(_T("*"));
	plus_minus.AddString(_T("/"));

	plus_minus.SetCurSel(3);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalcDlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalcDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CcalcDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalcDlg::OnCbnSelchangeCombo2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CcalcDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalcDlg::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalcDlg::OnEnChangeEdit7()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CcalcDlg::OnBnClickedOk()
{
	 //TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();

	UpdateData(TRUE);
	ima1 = ima2 = 0;
	rea1 = rea2 = 0;
	rea3 = ima3 = 0;
	UpdateData(FALSE);
}
