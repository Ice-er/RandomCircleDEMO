#pragma once


// CDrawShape 对话框

class CDrawShape : public CDialogEx
{
	DECLARE_DYNAMIC(CDrawShape)

public:
	CDrawShape(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDrawShape();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
