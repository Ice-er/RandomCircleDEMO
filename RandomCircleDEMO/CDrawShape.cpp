// CDrawShape.cpp: 实现文件
//

#include "pch.h"
#include "RandomCircleDemo.h"
#include "CDrawShape.h"
#include "afxdialogex.h"


// CDrawShape 对话框

IMPLEMENT_DYNAMIC(CDrawShape, CDialogEx)

CDrawShape::CDrawShape(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDrawShape::~CDrawShape()
{
}

void CDrawShape::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDrawShape, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDrawShape::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CDrawShape::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDrawShape::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDrawShape::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDrawShape::OnBnClickedButton4)
END_MESSAGE_MAP()


// CDrawShape 消息处理程序


void CDrawShape::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CDrawShape::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//绘制弧
	Invalidate();
	UpdateWindow();
	CDC* pDC = GetDC();
	CRect myRect;
	CPoint center;

	myRect.SetRect(50, 50, 400, 400);
	center.x = myRect.left + myRect.Width() / 2;
	center.y = myRect.top + myRect.Height() / 2;

	pDC->Rectangle(myRect);

	pDC->MoveTo(center);
	pDC->AngleArc(center.x, center.y, 120, 0, 110);

	CPoint pt1, pt2;
	pt1.SetPoint(100, 80);
	pt2.SetPoint(200, 320);
	pDC->MoveTo(center);
	pDC->LineTo(pt1);
	pDC->MoveTo(center);
	pDC->LineTo(pt2);

	pDC->TextOutW(pt1.x, pt1.y, _T("p1"));
	pDC->TextOutW(pt2.x, pt2.y, _T("p2"));
	pDC->Arc(myRect, pt1, pt2);
}


void CDrawShape::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
		//绘制饼图
	Invalidate();
	UpdateWindow();
	CDC* pDC = GetDC();
	CRect myRect;
	myRect.SetRect(150, 50, 550, 400);
	pDC->Rectangle(myRect);
	CPoint pt1, pt2;
	pt1.SetPoint(100, 80);
	pt2.SetPoint(200, 320);
	pDC->Pie(myRect, pt1, pt2);
	pDC->TextOutW(pt1.x, pt1.y, _T("p1"));
	pDC->TextOutW(pt2.x, pt2.y, _T("p2"));
}


void CDrawShape::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	// 绘制封闭区域
	Invalidate();
	UpdateWindow();
	CDC* pDC = GetDC();
	int x, y;
	x = 30;
	y = 20;
	CPoint myCurve[5];
	myCurve[0].SetPoint(x + 120, y + 30);
	myCurve[1].SetPoint(x + 150, y + 175);
	myCurve[2].SetPoint(x + 230, y + 250);
	myCurve[3].SetPoint(x + 300, y + 130);
	myCurve[4].SetPoint(x + 350, y + 60);
	pDC->Polygon(myCurve, 5);
}


void CDrawShape::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//绘制曲线
	Invalidate();
	UpdateWindow();
	CDC* pDC = GetDC();
	CPoint myStart;
	myStart.x = 200;
	myStart.y = 150;
	CPoint myCurve[5];
	myCurve[0].SetPoint(myStart.x + 200, myStart.y + 30);
	myCurve[1].SetPoint(myStart.x + 20, myStart.y + 35);
	myCurve[2].SetPoint(myStart.x + 30, myStart.y + 50);
	myCurve[3].SetPoint(myStart.x + 15, myStart.y + 130);
	myCurve[4].SetPoint(myStart.x + 80, myStart.y + 60);

	pDC->Polyline(myCurve, 5);
}
