#include <windows.h>
#include <time.h>

/*2. ѕользователь нажимает на пустом месте в окне,
     и там где он нажал, по€вл€етс€ кнопка, после чего она начинает плавно падать вниз.
     ѕо достижению дна она останавливаетс€.*/

#define ID_ADD_BUTTON   100

// назание класса главного окна
char className[] = "WindowClass1";
// структура, хран€ща€ сообщение 
MSG msg;
// адрес приложени€
HINSTANCE hInst;
// адрес кнопки
HWND new_button;
//счетчик
int counter = 1;
//внешние переменные дл€ хранени€ координат
int current_x, current_y;

// ---------------------------------------------------------------------------------------------------
// оконна€ функци€
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        //нажатие левой кнопкой мыши
        case WM_LBUTTONDOWN:
        {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            char s[20];
            _itoa_s(counter++, s, 10);
            new_button = CreateWindow("button", s, WS_CHILD | WS_VISIBLE, x, y, 50, 20, wnd, (HMENU)ID_ADD_BUTTON, hInst, 0);

            //присвоить текущие значени€ координат, что бы нова€ кнопка двигалась с нового места
            current_x = x;
            current_y = y;

            //запустить таймер
            SetTimer(wnd, 1, 1, 0);

            return 0;
        }

        //таймер
        case WM_TIMER: 
        {
            RECT rect;
            GetWindowRect(wnd, &rect);
            int size = rect.bottom - rect.top - 59;

            //переместить кнопку
            MoveWindow(new_button, current_x, current_y, 50, 20, 1);

            if (current_y >= size) 
                KillTimer(wnd, 1);
            else
                current_y += 1;

            return 0;
        }

        //закрытие окна и программы
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
    }
    return DefWindowProc(wnd, msg, wParam, lParam);
}
// ---------------------------------------------------------------------------------------------------
// точка входа в программу
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // структура-класс окна, хран€ща€ свойства окна
    WNDCLASS wc;
    // адрес главного окна
    HWND hwnd;
    // адрес приложени€
    hInst = hInstance;
    //параметры окна
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.lpfnWndProc   = WndProc;
    wc.lpszMenuName  = NULL;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = className;
    wc.cbClsExtra    = wc.cbWndExtra = wc.style = 0;
    // регистраци€ оконного класса в Windows
    int k = RegisterClass(&wc);
    // создание главного окна
    hwnd = CreateWindow(className, "main window", WS_VISIBLE | WS_OVERLAPPEDWINDOW, 300, 300, 720, 400, NULL, NULL, hInstance, 0);
    // если главное окно не удалось создать, то выйти с ошибкой
    if (!hwnd) return false;
    while (GetMessage(&msg, 0, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 1;
}