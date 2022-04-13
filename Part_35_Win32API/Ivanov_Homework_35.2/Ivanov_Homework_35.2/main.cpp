#include <windows.h>
#include <time.h>

/*2. ������������ �������� �� ������ ����� � ����,
     � ��� ��� �� �����, ���������� ������, ����� ���� ��� �������� ������ ������ ����.
     �� ���������� ��� ��� ���������������.*/

#define ID_ADD_BUTTON   100

// ������� ������ �������� ����
char className[] = "WindowClass1";
// ���������, �������� ��������� 
MSG msg;
// ����� ����������
HINSTANCE hInst;
// ����� ������
HWND new_button;
//�������
int counter = 1;
//������� ���������� ��� �������� ���������
int current_x, current_y;

// ---------------------------------------------------------------------------------------------------
// ������� �������
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        //������� ����� ������� ����
        case WM_LBUTTONDOWN:
        {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            char s[20];
            _itoa_s(counter++, s, 10);
            new_button = CreateWindow("button", s, WS_CHILD | WS_VISIBLE, x, y, 50, 20, wnd, (HMENU)ID_ADD_BUTTON, hInst, 0);

            //��������� ������� �������� ���������, ��� �� ����� ������ ��������� � ������ �����
            current_x = x;
            current_y = y;

            //��������� ������
            SetTimer(wnd, 1, 1, 0);

            return 0;
        }

        //������
        case WM_TIMER: 
        {
            RECT rect;
            GetWindowRect(wnd, &rect);
            int size = rect.bottom - rect.top - 59;

            //����������� ������
            MoveWindow(new_button, current_x, current_y, 50, 20, 1);

            if (current_y >= size) 
                KillTimer(wnd, 1);
            else
                current_y += 1;

            return 0;
        }

        //�������� ���� � ���������
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
    }
    return DefWindowProc(wnd, msg, wParam, lParam);
}
// ---------------------------------------------------------------------------------------------------
// ����� ����� � ���������
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ���������-����� ����, �������� �������� ����
    WNDCLASS wc;
    // ����� �������� ����
    HWND hwnd;
    // ����� ����������
    hInst = hInstance;
    //��������� ����
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.lpfnWndProc   = WndProc;
    wc.lpszMenuName  = NULL;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = className;
    wc.cbClsExtra    = wc.cbWndExtra = wc.style = 0;
    // ����������� �������� ������ � Windows
    int k = RegisterClass(&wc);
    // �������� �������� ����
    hwnd = CreateWindow(className, "main window", WS_VISIBLE | WS_OVERLAPPEDWINDOW, 300, 300, 720, 400, NULL, NULL, hInstance, 0);
    // ���� ������� ���� �� ������� �������, �� ����� � �������
    if (!hwnd) return false;
    while (GetMessage(&msg, 0, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 1;
}