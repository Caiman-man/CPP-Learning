#include <windows.h>
#include <time.h>
#include <iostream>
#include<stdlib.h>
#include<stdio.h>

//1. Реализовать программу "Калькулятор", который имеет функционал стандартного калькулятора Windows

#define ID_EDIT          99
#define ID_BUTTON_0     100
#define ID_BUTTON_1     101
#define ID_BUTTON_2     102
#define ID_BUTTON_3     103
#define ID_BUTTON_4     104
#define ID_BUTTON_5     105
#define ID_BUTTON_6     106
#define ID_BUTTON_7     107
#define ID_BUTTON_8     108
#define ID_BUTTON_9     109
#define ID_BUTTON_ADD   110
#define ID_BUTTON_SUB   111
#define ID_BUTTON_MUL   112
#define ID_BUTTON_DIV   113
#define ID_BUTTON_RES   114
#define ID_BUTTON_POINT 115
#define ID_BUTTON_C     116
#define ID_BUTTON_CE    117
#define ID_BUTTON_BKSPC 118
#define ID_BUTTON_PROC  119

// назание класса главного окна
char className[] = "WindowCalculator";
// структура, хранящая сообщение 
MSG msg;
// адрес приложения
HINSTANCE hInst;
// адреса кнопок
HWND hButton[20], hEdit;

// строка-буфер
char buffer[100];
// результат
double res = 0;
// последнее введенное число
double num = 0;
// знак арифметической операции
char oper;

// ---------------------------------------------------------------------------------------------------
// оконная функция
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        // сообщение, в обработчике которого создаётся UI
    case WM_CREATE:
    {
        hEdit = CreateWindow("edit", "0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 10, 10, 315, 60, wnd, (HMENU)ID_EDIT, hInst, 0);
        hButton[0]  = CreateWindow("Button", "0", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 90, 340, 75, 60, wnd, (HMENU)ID_BUTTON_0, hInst, 0);
        hButton[1]  = CreateWindow("Button", "1", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 275, 75, 60, wnd, (HMENU)ID_BUTTON_1, hInst, 0);
        hButton[2]  = CreateWindow("Button", "2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 90, 275, 75, 60, wnd, (HMENU)ID_BUTTON_2, hInst, 0);
        hButton[3]  = CreateWindow("Button", "3", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 170, 275, 75, 60, wnd, (HMENU)ID_BUTTON_3, hInst, 0);
        hButton[4]  = CreateWindow("Button", "4", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 210, 75, 60, wnd, (HMENU)ID_BUTTON_4, hInst, 0);
        hButton[5]  = CreateWindow("Button", "5", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 90, 210, 75, 60, wnd, (HMENU)ID_BUTTON_5, hInst, 0);
        hButton[6]  = CreateWindow("Button", "6", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 170, 210, 75, 60, wnd, (HMENU)ID_BUTTON_6, hInst, 0);
        hButton[7]  = CreateWindow("Button", "7", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 145, 75, 60, wnd, (HMENU)ID_BUTTON_7, hInst, 0);
        hButton[8]  = CreateWindow("Button", "8", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 90, 145, 75, 60, wnd, (HMENU)ID_BUTTON_8, hInst, 0);
        hButton[9]  = CreateWindow("Button", "9", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 170, 145, 75, 60, wnd, (HMENU)ID_BUTTON_9, hInst, 0);
        hButton[10] = CreateWindow("Button", "+", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 340, 75, 60, wnd, (HMENU)ID_BUTTON_ADD, hInst, 0);
        hButton[11] = CreateWindow("Button", "-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 275, 75, 60, wnd, (HMENU)ID_BUTTON_SUB, hInst, 0);
        hButton[12] = CreateWindow("Button", "*", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 210, 75, 60, wnd, (HMENU)ID_BUTTON_MUL, hInst, 0);
        hButton[13] = CreateWindow("Button", "/", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 145, 75, 60, wnd, (HMENU)ID_BUTTON_DIV, hInst, 0);
        hButton[14] = CreateWindow("Button", "=", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 170, 340, 75, 60, wnd, (HMENU)ID_BUTTON_RES, hInst, 0);
        hButton[15] = CreateWindow("Button", ".", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 340, 75, 60, wnd, (HMENU)ID_BUTTON_POINT, hInst, 0);
        hButton[16] = CreateWindow("Button", "C", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 170, 80, 75, 60, wnd, (HMENU)ID_BUTTON_C, hInst, 0);
        hButton[17] = CreateWindow("Button", "CE", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 90, 80, 75, 60, wnd, (HMENU)ID_BUTTON_CE, hInst, 0);
        hButton[18] = CreateWindow("Button", "<-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 250, 80, 75, 60, wnd, (HMENU)ID_BUTTON_BKSPC, hInst, 0);
        hButton[19] = CreateWindow("Button", "%", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 80, 75, 60, wnd, (HMENU)ID_BUTTON_PROC, hInst, 0);
        srand(time(0));
        return 0;
    }

    // обработка сообщений дочерних элементов
    case WM_COMMAND:
    {
        //0
        if ((LOWORD(wParam) == ID_BUTTON_0) && (HIWORD(wParam) == BN_CLICKED))
        {
            //если было нажато "=", то обнуляю показания на дисплее
            if (oper == '=')
            {
                SetWindowText(hEdit, "");
                oper = 0;
            }
            //считываю данные с дисплея в буфер игнорируя знаки, точки и т.д.
            GetWindowText(hEdit, buffer, sizeof(buffer));
            if (buffer[0] == '0' && buffer[1] != '0' && buffer[1] != '.')
                buffer[0] = '0';
            else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
                buffer[0] = '0';
            else
                strcat(buffer, "0");
            SetWindowText(hEdit, buffer);
        }

        //1
        if ((LOWORD(wParam) == ID_BUTTON_1) && (HIWORD(wParam) == BN_CLICKED))
        {
            //если было нажато "=", то обнуляю показания на дисплее
            if (oper == '=')
            {
                SetWindowText(hEdit, "");
                oper = 0;
            }
            //считываю данные с дисплея в буфер игнорируя знаки, точки и т.д.
            GetWindowText(hEdit, buffer, sizeof(buffer));
            if (buffer[0] == '0' && buffer[1] != '0' && buffer[1] != '.')
                buffer[0] = '1';
            else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
                buffer[0] = '1';
            else
                strcat(buffer, "1");
            SetWindowText(hEdit, buffer);
        }

        //2
        if ((LOWORD(wParam) == ID_BUTTON_2) && (HIWORD(wParam) == BN_CLICKED))
        {
            //если было нажато "=", то обнуляю показания на дисплее
            if (oper == '=')
            {
                SetWindowText(hEdit, "");
                oper = 0;
            }
            //считываю данные с дисплея в буфер игнорируя знаки, точки и т.д.
            GetWindowText(hEdit, buffer, sizeof(buffer));
            if (buffer[0] == '0' && buffer[1] != '0' && buffer[1] != '.')
                buffer[0] = '2';
            else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
                buffer[0] = '2';
            else
                strcat(buffer, "2");
            SetWindowText(hEdit, buffer);
        }

        //3
        if ((LOWORD(wParam) == ID_BUTTON_3) && (HIWORD(wParam) == BN_CLICKED))
        {
            //если было нажато "=", то обнуляю показания на дисплее
            if (oper == '=')
            {
                SetWindowText(hEdit, "");
                oper = 0;
            }
            //считываю данные с дисплея в буфер игнорируя знаки, точки и т.д.
            GetWindowText(hEdit, buffer, sizeof(buffer));
            if (buffer[0] == '0' && buffer[1] != '0' && buffer[1] != '.')
                buffer[0] = '3';
            else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
                buffer[0] = '3';
            else
                strcat(buffer, "3");
            SetWindowText(hEdit, buffer);
        }

        //4
        if ((LOWORD(wParam) == ID_BUTTON_4) && (HIWORD(wParam) == BN_CLICKED))
        {
            //если было нажато "=", то обнуляю показания на дисплее
            if (oper == '=')
            {
                SetWindowText(hEdit, "");
                oper = 0;
            }
            //считываю данные с дисплея в буфер игнорируя знаки, точки и т.д.
            GetWindowText(hEdit, buffer, sizeof(buffer));
            if (buffer[0] == '0' && buffer[1] != '0' && buffer[1] != '.')
                buffer[0] = '4';
            else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
                buffer[0] = '4';
            else
                strcat(buffer, "4");
            SetWindowText(hEdit, buffer);
        }

        //5
        if ((LOWORD(wParam) == ID_BUTTON_5) && (HIWORD(wParam) == BN_CLICKED))
        {
            //если было нажато "=", то обнуляю показания на дисплее
            if (oper == '=')
            {
                SetWindowText(hEdit, "");
                oper = 0;
            }
            //считываю данные с дисплея в буфер игнорируя знаки, точки и т.д.
            GetWindowText(hEdit, buffer, sizeof(buffer));
            if (buffer[0] == '0' && buffer[1] != '0' && buffer[1] != '.')
                buffer[0] = '5';
            else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
                buffer[0] = '5';
            else
                strcat(buffer, "5");
            SetWindowText(hEdit, buffer);
        }

        //6
        if ((LOWORD(wParam) == ID_BUTTON_6) && (HIWORD(wParam) == BN_CLICKED))
        {
            //если было нажато "=", то обнуляю показания на дисплее
            if (oper == '=')
            {
                SetWindowText(hEdit, "");
                oper = 0;
            }
            //считываю данные с дисплея в буфер игнорируя знаки, точки и т.д.
            GetWindowText(hEdit, buffer, sizeof(buffer));
            if (buffer[0] == '0' && buffer[1] != '0' && buffer[1] != '.')
                buffer[0] = '6';
            else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
                buffer[0] = '6';
            else
                strcat(buffer, "6");
            SetWindowText(hEdit, buffer);
        }

        //7
        if ((LOWORD(wParam) == ID_BUTTON_7) && (HIWORD(wParam) == BN_CLICKED))
        {
            //если было нажато "=", то обнуляю показания на дисплее
            if (oper == '=')
            {
                SetWindowText(hEdit, "");
                oper = 0;
            }
            //считываю данные с дисплея в буфер игнорируя знаки, точки и т.д.
            GetWindowText(hEdit, buffer, sizeof(buffer));
            if (buffer[0] == '0' && buffer[1] != '0' && buffer[1] != '.')
                buffer[0] = '7';
            else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
                buffer[0] = '7';
            else
                strcat(buffer, "7");
            SetWindowText(hEdit, buffer);
        }

        //8
        if ((LOWORD(wParam) == ID_BUTTON_8) && (HIWORD(wParam) == BN_CLICKED))
        {
            //если было нажато "=", то обнуляю показания на дисплее
            if (oper == '=')
            {
                SetWindowText(hEdit, "");
                oper = 0;
            }
            //считываю данные с дисплея в буфер игнорируя знаки, точки и т.д.
            GetWindowText(hEdit, buffer, sizeof(buffer));
            if (buffer[0] == '0' && buffer[1] != '0' && buffer[1] != '.')
                buffer[0] = '8';
            else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
                buffer[0] = '8';
            else
                strcat(buffer, "8");
            SetWindowText(hEdit, buffer);
        }

        //9
        if ((LOWORD(wParam) == ID_BUTTON_9) && (HIWORD(wParam) == BN_CLICKED))
        {
            //если было нажато "=", то обнуляю показания на дисплее
            if (oper == '=')
            {
                SetWindowText(hEdit, "");
                oper = 0;
            }
            //считываю данные с дисплея в буфер игнорируя знаки, точки и т.д.
            GetWindowText(hEdit, buffer, sizeof(buffer));
            if (buffer[0] == '0' && buffer[1] != '0' && buffer[1] != '.')
                buffer[0] = '9';
            else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
                buffer[0] = '9';
            else
                strcat(buffer, "9");
            SetWindowText(hEdit, buffer);
        }

        //POINT
        if ((LOWORD(wParam) == ID_BUTTON_POINT) && (HIWORD(wParam) == BN_CLICKED))
        {
            int point_cnt = 0;
            GetWindowText(hEdit, buffer, sizeof(buffer));
            //если на дисплее стоит ноль или любая другая цифра
            if ((strlen(buffer) == 1) && buffer[1] != '0')
            {
                strcat(buffer, ".");
                point_cnt++;
            }
            //проверяем на повторение
            else if ((strlen(buffer) > 1))
            {
                for (int i = 0; buffer[i] != 0; i++)
                {
                    if (buffer[i] == '.')
                    {
                        point_cnt++;
                        if (point_cnt >= 1)
                            break;
                    }
                }
                if (point_cnt == 0)
                    strcat(buffer, ".");
            }
            SetWindowText(hEdit, buffer);
        }

        //C
        if ((LOWORD(wParam) == ID_BUTTON_C) && (HIWORD(wParam) == BN_CLICKED))
        {
            SetWindowText(hEdit, "0");
            buffer[0] = 0;
            res = 0;
            num = 0;
            oper = 0;
        }

        //CE
        if ((LOWORD(wParam) == ID_BUTTON_CE) && (HIWORD(wParam) == BN_CLICKED))
        {
            SetWindowText(hEdit, "0");
            buffer[0] = 0;
            res = 0;
            num = 0;
            oper = 0;
        }

        //BACKSPACE
        if ((LOWORD(wParam) == ID_BUTTON_BKSPC) && (HIWORD(wParam) == BN_CLICKED))
        {
            if (strlen(buffer) > 0)
                buffer[strlen(buffer) - 1] = '\0';
            SetWindowText(hEdit, buffer);
            if (strlen(buffer) == 0)
                SetWindowText(hEdit, "0");
        }

        //PROCENT
        if ((LOWORD(wParam) == ID_BUTTON_PROC) && (HIWORD(wParam) == BN_CLICKED))
        {
            GetWindowText(hEdit, buffer, sizeof(buffer));
            if (strlen(buffer) > 0)
            {
                double a = strtod(buffer, nullptr);
                a = a * 0.01;
                buffer[0] = 0;
                _gcvt(a, 10, buffer);
            }
            SetWindowText(hEdit, buffer);
        }

        //ADD
        if ((LOWORD(wParam) == ID_BUTTON_ADD) && (HIWORD(wParam) == BN_CLICKED))
        {
            if (oper == '=')
                SetWindowText(hEdit, "");
            num = strtod(buffer, nullptr);
            if (oper == 0) res = num;
            if (oper == '+') res = res + num;
            if (oper == '-') res = res - num;
            if (oper == '*') res = res * num;
            if (oper == '/') res = res / num;
            SetWindowText(hEdit, "+");
            oper = '+';
            buffer[0] = 0;
        }

        //SUB
        if ((LOWORD(wParam) == ID_BUTTON_SUB) && (HIWORD(wParam) == BN_CLICKED))
        {
            if (oper == '=')
                SetWindowText(hEdit, "");
            num = strtod(buffer, nullptr);
            if (oper == 0) res = num;
            if (oper == '+') res = res + num;
            if (oper == '-') res = res - num;
            if (oper == '*') res = res * num;
            if (oper == '/') res = res / num;
            SetWindowText(hEdit, "-");
            oper = '-';
            buffer[0] = 0;
        }

        //MUL
        if ((LOWORD(wParam) == ID_BUTTON_MUL) && (HIWORD(wParam) == BN_CLICKED))
        {
            if (oper == '=')
                SetWindowText(hEdit, "");
            num = strtod(buffer, nullptr);
            if (oper == 0) res = num;
            if (oper == '+') res = res + num;
            if (oper == '-') res = res - num;
            if (oper == '*') res = res * num;
            if (oper == '/') res = res / num;
            SetWindowText(hEdit, "*");
            oper = '*';
            buffer[0] = 0;
        }

        //DIV
        if ((LOWORD(wParam) == ID_BUTTON_DIV) && (HIWORD(wParam) == BN_CLICKED))
        {
            if (oper == '=')
                SetWindowText(hEdit, "");
            num = strtod(buffer, nullptr);
            if (oper == 0) res = num;
            if (oper == '+') res = res + num;
            if (oper == '-') res = res - num;
            if (oper == '*') res = res * num;
            if (oper == '/') res = res / num;
            SetWindowText(hEdit, "/");
            oper = '/';
            buffer[0] = 0;
        }

        //RESULT
        if ((LOWORD(wParam) == ID_BUTTON_RES) && (HIWORD(wParam) == BN_CLICKED))
        {
            GetWindowText(hEdit, buffer, sizeof(buffer));
            num = strtod(buffer, nullptr);
            if (oper == '+') res = res + num;
            if (oper == '-') res = res - num;
            if (oper == '*') res = res * num;
            if (oper == '/') res = res / num;
            _gcvt(res, 10, buffer);
            if (buffer[strlen(buffer) - 1] == '.')
                buffer[strlen(buffer) - 1] = '\0';
            SetWindowText(hEdit, buffer);
            //обнуляем данные и ставим признак, что было нажато "="
            res = 0;
            num = 0;
            oper = '=';
            buffer[0] = 0;
        }
        return 0;
    }

    //закрытие программы
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
    // структура-класс окна, хранящая свойства окна
    WNDCLASS wc;
    // адрес главного окна
    HWND hwnd;
    // адрес приложения
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
    // регистрация оконного класса в Windows
    int k = RegisterClass(&wc);
    // создание главного окна
    hwnd = CreateWindow(className, "Calculator v1.0", WS_VISIBLE | WS_OVERLAPPEDWINDOW, 300, 300, 350, 450, NULL, NULL, hInstance, 0);
    // если главное окно не удалось создать, то выйти с ошибкой
    if (!hwnd) return false;
    while (GetMessage(&msg, 0, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 1;
}
