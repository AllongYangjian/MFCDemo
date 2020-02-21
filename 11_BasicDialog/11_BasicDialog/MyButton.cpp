// MyButton.cpp: 实现文件
//

#include "stdafx.h"
#include "11_BasicDialog.h"
#include "MyButton.h"


// MyButton

IMPLEMENT_DYNAMIC(MyButton, CButton)

MyButton::MyButton()
{

}

MyButton::~MyButton()
{
}


BEGIN_MESSAGE_MAP(MyButton, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// MyButton 消息处理程序




void MyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	int x = rand() % 400;
	int y = rand() % 400;
	
	this->MoveWindow(x, y, 144, 144);

	CButton::OnMouseMove(nFlags, point);
}
