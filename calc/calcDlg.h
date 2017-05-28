
// calcDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CcalcDlg 对话框
class CcalcDlg : public CDialogEx
{
// 构造
public:
	CcalcDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox plus_minus;
	CComboBox plus_minus2;
	int ima1;
	afx_msg void OnEnChangeEdit2();
	int rea1;
	int ima2;
	int rea2;
	int ima3;
	afx_msg void OnEnChangeEdit6();
	int rea3;
	afx_msg void OnEnChangeEdit7();
	CString chosenOp;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
