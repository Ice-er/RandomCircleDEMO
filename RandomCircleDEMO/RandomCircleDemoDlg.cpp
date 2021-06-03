
// RandomCircleDemoDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "RandomCircleDemo.h"
#include "RandomCircleDemoDlg.h"
#include "afxdialogex.h"

#include "CDrawShape.h"

#include "RandData.h"

RandData randomShape;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CRandomCircleDemoDlg 对话框



CRandomCircleDemoDlg::CRandomCircleDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RANDOMCIRCLEDEMO_DIALOG, pParent)
	, bClean(FALSE)
	, nDelay(0)
	, nMaxSize(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRandomCircleDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, timerSwitch);
	DDX_Check(pDX, IDC_CHECK1, bClean);
	DDX_Text(pDX, IDC_EDIT1, nDelay);
	DDX_Text(pDX, IDC_EDIT2, nMaxSize);
}

BEGIN_MESSAGE_MAP(CRandomCircleDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CRandomCircleDemoDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CRandomCircleDemoDlg::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT2, &CRandomCircleDemoDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CRandomCircleDemoDlg 消息处理程序

BOOL CRandomCircleDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRandomCircleDemoDlg::OnPaint()
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
HCURSOR CRandomCircleDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRandomCircleDemoDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	//模态对话框
	CDrawShape  Dlg;
	Dlg.DoModal();

	//非模态对话框
	//CDrawShape* pDlg = new CDrawShape;
	//pDlg->Create(IDD_DIALOG2, this);
	//pDlg->ShowWindow(SW_SHOW);

}


void CRandomCircleDemoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	static int nSwitch;
	UpdateData(true);
	if (nSwitch < 1) {
		nSwitch = 1;
		if (nDelay > 0)
		{
			SetTimer(1, nDelay, NULL);
		}
		else
		{
			SetTimer(1, 1000, NULL);
		}
		timerSwitch.SetWindowTextW(_T("停止"));
		randomShape.SetShapeRange(nMaxSize, nMaxSize);
	}
	else {
		nSwitch = 0;
		KillTimer(1);
		timerSwitch.SetWindowTextW(_T("开始"));
	}

}


void CRandomCircleDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	UpdateData(true);
	if (bClean)
	{
		Invalidate();
		UpdateWindow();

	}
	DrawCircle();

	CDialogEx::OnTimer(nIDEvent);
}


void CRandomCircleDemoDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CRandomCircleDemoDlg::DrawCircle()
{
	// TODO: 在此处添加实现代码.
	CDC* pDC = GetDC();
	CBrush* oldBrush, myBrush;
	CPen* oldPen, myPen;
	myBrush.CreateSolidBrush(randomShape.GetColor());
	myPen.CreatePen(PS_SOLID, 1, randomShape.GetColor());
	oldBrush = pDC->SelectObject(&myBrush);
	oldPen = pDC->SelectObject(&myPen);

	CPoint myPoint;
	myPoint = randomShape.GetPosition();
	int width = randomShape.GetShapeSize();
	//int height = randomShape.GetShapeSize();
	int height = width;


	pDC->Ellipse(myPoint.x - width / 2, myPoint.y - height / 2, myPoint.x + width / 2, myPoint.y + height / 2);

	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}
