
// calcDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CcalcDlg �Ի���
class CcalcDlg : public CDialogEx
{
// ����
public:
	CcalcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
