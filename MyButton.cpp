#include "pch.h"
#include "MyButton.h"
#include "MFCDLLPractice.h"


BEGIN_MESSAGE_MAP(MyButton, CBitmapButton)
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

void MyButton::Init(CString typeName, CRect rect, CWnd* wnd) {
	this->Create(_T("BUTTON"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_OWNERDRAW | BS_BITMAP, rect, wnd, 21001);
	if (typeName == _T("close_button"))
	{
		this->LoadBitmaps(IDB_Close1, NULL, NULL, NULL);
		this->SizeToContent();
		close_button = this->GetDlgCtrlID();
		
	}
	else if (typeName == _T("full_button"))
	{
		this->LoadBitmaps(IDB_Full1, IDB_Full2, IDB_Full2, NULL);
		this->SizeToContent();
		this->isMini = TRUE;
		full_button = this->GetDlgCtrlID();
	}
	else if (typeName == _T("hide_button")) {
		this->LoadBitmaps(IDB_Hide1, IDB_Hide2, NULL, NULL);
		this->SizeToContent();
		hide_button = this->GetDlgCtrlID();
	}
}
void MyButton::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int id = this->GetDlgCtrlID();
	if (id == close_button) {
		this->LoadBitmaps(IDB_Close2, NULL, NULL, NULL);
		this->SizeToContent();
	}
	else if (id == full_button) {
		if (this->isMini) {
			this->LoadBitmaps(IDB_Full2, NULL, NULL, NULL);
			this->SizeToContent();
		}
		else {
			this->LoadBitmaps(IDB_Mini2, NULL, NULL, NULL);
			this->SizeToContent();
		}
	}
	else if (id == hide_button) {
		this->LoadBitmaps(IDB_Hide2, NULL, NULL, NULL);
		this->SizeToContent();
	}

	Invalidate();
	CBitmapButton::OnMouseHover(nFlags, point);
}


void MyButton::OnMouseLeave()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int id = this->GetDlgCtrlID();
	if (id == close_button) {
		this->LoadBitmaps(IDB_Close1, NULL, NULL, NULL);
		this->SizeToContent();
	}
	else if (id == full_button) {
		if (this->isMini) {
			this->LoadBitmaps(IDB_Full1, NULL, NULL, NULL);
			this->SizeToContent();
		}
		else {
			this->LoadBitmaps(IDB_Mini1, NULL, NULL, NULL);
			this->SizeToContent();
		}
	}
	else if (id == hide_button) {
		this->LoadBitmaps(IDB_Hide1, IDB_Hide2, NULL, NULL);
		this->SizeToContent();
	}
	m_bCursorOnButton = FALSE;
	Invalidate();
	CBitmapButton::OnMouseLeave();
}


void MyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bCursorOnButton == FALSE)
	{
		TRACKMOUSEEVENT tme;
		ZeroMemory(&tme, sizeof(TRACKMOUSEEVENT));
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE | TME_HOVER;
		tme.dwHoverTime = 1;
		m_bCursorOnButton = _TrackMouseEvent(&tme);
	}
	CBitmapButton::OnMouseMove(nFlags, point);
}
