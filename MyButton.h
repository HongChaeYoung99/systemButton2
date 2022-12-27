#pragma once
#include <afxwin.h>

class MyButton : public CBitmapButton
{
public:
	MyButton() {
		m_bCursorOnButton = FALSE;
	}
	void Init(CString typeName, CRect rect,CWnd* wnd);
	bool isMini;
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int close_button;
	int full_button;
	int hide_button;


private:
	bool m_bCursorOnButton;

};

