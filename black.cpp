#include<afxwin.h>
class CMainFrame : public CFrameWnd {
public:
	CMainFrame() {
		Create(NULL, L"Hi !");
	}
	void OnPaint();
	DECLARE_MESSAGE_MAP()  // jcshim
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
};
class CMy : public CWinApp {
	BOOL InitInstance() {
		CMainFrame* Frm = new CMainFrame();
		m_pMainWnd = Frm;
		Frm->ShowWindow(1);
		return TRUE;
	}
};
CMy theApp;
// jcshim
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_WM_MBUTTONDOWN()
END_MESSAGE_MAP()
void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	CBrush b;
	b.CreateSolidBrush(RGB(0, 0, 0)); // 검은색으로 채우기
	dc.SelectObject(&b);
	CRect r;
	GetClientRect(&r);
	dc.Rectangle(r);  // 사각형 그리기
	ShowCursor(false);  // 커서 감추기
}
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs)) return FALSE;
	int x = GetSystemMetrics(SM_CXSCREEN);  // 스크린 X 크기
	int y = GetSystemMetrics(SM_CYSCREEN);  // 스크린 Y 크기
	cs.style = WS_POPUP;
	cs.x = cs.y = -2; // 테두리까지 포함
	cs.cx = cs.cy = x + 4;
	return TRUE;
}
void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	PostMessageW(WM_CLOSE);
	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
void CMainFrame::OnMButtonDown(UINT nFlags, CPoint point)
{
	PostMessageW(WM_CLOSE);
	CFrameWnd::OnMButtonDown(nFlags, point);
}