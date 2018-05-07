#include <Windows.h>
#include <time.h>

int map[21][11]; // 0 is empty, 1 - 7 is block, 8 is precipitation

int block_type = 0;
int score = 0;
int isPainting = 0;

HWND hWnd;

void Rotate()
{
	if (block_type != 7)
	{
		int i[4], j[4];
		int copy_i[4], copy_j[4];
		int index = 0;
		for (int n = 1; n <= 20; ++n)
		{
			for (int m = 1; m <= 10; ++m)
			{
				if (map[n][m] >= 1 && map[n][m] <= 7)
				{
					map[n][m] = 0;
					i[index] = n;
					j[index] = m;
					copy_i[index] = n;
					copy_j[index] = m;
					++index;
				}
			}
		}
		if (index > 0)
		{
			int i_origin = i[2];
			int j_origin = j[2];
			int move_right = 0;
			int max_right = 0;
			int move_left = 0;
			int max_left = 0;
			int move_down = 0;
			int max_down = 0;
			int move_up = 0;
			int max_up = 0;
			for (int n = 0; n < 4; ++n)
			{
				int tmp_i = i[n];
				int tmp_j = j[n];
				i[n] = tmp_j - j_origin + i_origin;
				j[n] = -(tmp_i - i_origin) + j_origin;
				if (1 - i[n] > max_down)
				{
					move_down = 1 - i[n];
					max_down = move_down;
				}
				if (i[n] - 20 > max_up)
				{
					move_up = i[n] - 20;
					max_up = move_up;
				}
				if (1 - j[n] > max_right)
				{
					move_right = 1 - j[n];
					max_right = move_right;
				}
				if (j[n] - 10 > max_left)
				{
					move_left = j[n] - 10;
					max_left = move_left;
				}
			}
			for (int n = 0; n < 4; ++n)
			{
				i[n] += move_down;
				i[n] -= move_up;
				j[n] += move_right;
				j[n] -= move_left;
			}
			int canRotate = 1;
			for (int n = 0; n < 4; ++n)
			{
				if (map[i[n]][j[n]] == 8)
				{
					canRotate = 0;
					break;
				}
			}
			if (!canRotate)
			{
				for (int n = 0; n < 4; ++n)
				{
					i[n] = copy_i[n];
					j[n] = copy_j[n];
				}
			}
			for (int n = 0; n < 4; ++n)
				map[i[n]][j[n]] = block_type;
		}
		if (!isPainting)
		{
			RECT rc;
			GetClientRect(hWnd, &rc);
			isPainting = 1;
			InvalidateRect(hWnd, &rc, true);
		}
	}
}

void CreateObject(int type)
{
	switch (type)
	{
	case 1:
		map[1][4] = 1;
		map[1][5] = 1;
		map[1][6] = 1;
		map[1][7] = 1;
		break;
	case 2:
		map[1][4] = 2;
		map[2][4] = 2;
		map[2][5] = 2;
		map[2][6] = 2;
		break;
	case 3:
		map[2][4] = 3;
		map[2][5] = 3;
		map[2][6] = 3;
		map[1][6] = 3;
		break;
	case 4:
		map[1][6] = 4;
		map[2][6] = 4;
		map[2][5] = 4;
		map[3][5] = 4;
		break;
	case 5:
		map[1][5] = 5;
		map[2][5] = 5;
		map[2][6] = 5;
		map[3][6] = 5;
		break;
	case 6:
		map[1][5] = 6;
		map[2][4] = 6;
		map[2][5] = 6;
		map[2][6] = 6;
		break;
	case 7:
		map[1][5] = 7;
		map[1][6] = 7;
		map[2][5] = 7;
		map[2][6] = 7;
		break;
	default:
		break;
	}
}

void MoveBlock(int dir) // 0 is left, 1 is right, 2 is down
{
	int canMoveDown = 1;
	int canMoveLeft = 1;
	int canMoveRight = 1;
	for (int i = 1; i <= 20; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			if (map[i][j] >= 1 && map[i][j] <= 7)
			{
				if (i + 1 > 20)
					canMoveDown = 0;
				else if (map[i + 1][j] == 8)
					canMoveDown = 0;
				if (j - 1 < 1)
					canMoveLeft = 0;
				else if (map[i][j - 1] == 8)
					canMoveLeft = 0;
				if (j + 1 > 10)
					canMoveRight = 0;
				else if (map[i][j + 1] == 8)
					canMoveRight = 0;
			}
		}
	}
	switch (dir)
	{
	case 0:
		if (canMoveLeft)
		{
			for (int j = 1; j <= 10; ++j)
			{
				for (int i = 1; i <= 20; ++i)
				{
					if (map[i][j] >= 1 && map[i][j] <= 7)
					{
						map[i][j - 1] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
		}
		break;
	case 1:
		if (canMoveRight)
		{
			for (int j = 10; j >= 1; --j)
			{
				for (int i = 1; i <= 20; ++i)
				{
					if (map[i][j] >= 1 && map[i][j] <= 7)
					{
						map[i][j + 1] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
		}
		break;
	case 2:
		if (canMoveDown)
		{
			for (int i = 20; i >= 1; --i)
			{
				for (int j = 1; j <= 10; ++j)
				{
					if (map[i][j] >= 1 && map[i][j] <= 7)
					{
						map[i + 1][j] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
		}
		break;
	default:
		break;
	}
	if ((canMoveDown || canMoveLeft || canMoveRight) && !isPainting)
	{
		RECT rc;
		GetClientRect(hWnd, &rc);
		isPainting = 1;
		InvalidateRect(hWnd, &rc, true);
	}
}

DWORD WINAPI GameLogic(LPVOID lpParam)
{
	int none_object = 1;
	while (1)
	{
		if (none_object)
		{
			if (map[1][4] != 0 ||
				map[1][5] != 0 ||
				map[1][6] != 0 ||
				map[2][4] != 0 ||
				map[2][5] != 0 ||
				map[2][6] != 0 ||
				map[3][4] != 0 ||
				map[3][5] != 0 ||
				map[3][6] != 0)
				return 1;
			srand((unsigned int)time(NULL));
			block_type = rand() % 7 + 1;
			CreateObject(block_type);
			none_object = 0;
		}
		else
		{
			int canMoveDown = 1;
			for (int i = 1; i <= 20; ++i)
			{
				for (int j = 1; j <= 10; ++j)
				{
					if (map[i][j] >= 1 && map[i][j] <= 7)
					{
						if (i + 1 > 20)
							canMoveDown = 0;
						else if (map[i + 1][j] == 8)
							canMoveDown = 0;
					}
				}
			}
			if (canMoveDown)
			{
				for (int i = 20; i >= 1; --i)
				{
					for (int j = 1; j <= 10; ++j)
					{
						if (map[i][j] >= 1 && map[i][j] <= 7)
						{
							map[i + 1][j] = map[i][j];
							map[i][j] = 0;
						}
					}
				}
			}
			else
			{
				for (int i = 20; i >= 1; --i)
				{
					for (int j = 1; j <= 10; ++j)
					{
						if (map[i][j] >= 1 && map[i][j] <= 7)
							map[i][j] = 8;
					}
				}
				none_object = 1;
			}
			int isFullBottom[21] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			for (int i = 20; i >= 1; --i)
			{
				for (int j = 1; j <= 10; ++j)
				{
					if (map[i][j] != 8)
					{
						isFullBottom[i] = 0;
						break;
					}
				}
			}
			for (int i = 1; i <= 20; ++i)
			{
				if (isFullBottom[i])
				{
					for (int j = 1; j <= 10; ++j)
					{
						map[i][j] = 0;
					}
					for (int j = i - 1; j >= 1; --j)
					{
						for (int k = 0; k <= 10; ++k)
						{
							map[j + 1][k] = map[j][k];
							map[j][k] = 0;
						}
					}
					score += 100;
				}
			}
		}
		if (!isPainting)
		{
			RECT rc;
			GetClientRect(hWnd, &rc);
			isPainting = 1;
			InvalidateRect(hWnd, &rc, true);
		}
		Sleep(500);
	}
}

void Paint(HWND hwnd)
{
	PAINTSTRUCT ps;
	BeginPaint(hwnd, &ps);

	RECT rc;
	GetClientRect(hwnd, &rc);

	HDC buff_hDC = CreateCompatibleDC(ps.hdc);
	HBITMAP bitmap = CreateCompatibleBitmap(ps.hdc, rc.right, rc.bottom);

	SelectObject(buff_hDC, bitmap);

	HPEN borderPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	HPEN blockPen = CreatePen(PS_SOLID, 1, RGB(50, 50, 50));
	
	HBRUSH bgBrush = CreateSolidBrush(RGB(50, 50, 50));
	
	HBRUSH Yellow = CreateSolidBrush(RGB(255, 255, 0));
	HBRUSH Green = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH Red = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH Blue = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH Cyan = CreateSolidBrush(RGB(0, 255, 255));
	HBRUSH Purple = CreateSolidBrush(RGB(255, 0, 255));
	HBRUSH White = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH Gray = CreateSolidBrush(RGB(120, 120, 120));

	SelectObject(buff_hDC, borderPen);
	SelectObject(buff_hDC, bgBrush);

	Rectangle(buff_hDC, 150, 20, 470, 660);

	SelectObject(buff_hDC, blockPen);

	for (int i = 1; i <= 20; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			switch (map[i][j])
			{
			case 0:
				SelectObject(buff_hDC, bgBrush);
				break;
			case 1:
				SelectObject(buff_hDC, White);
				break;
			case 2:
				SelectObject(buff_hDC, Blue);
				break;
			case 3:
				SelectObject(buff_hDC, Green);
				break;
			case 4:
				SelectObject(buff_hDC, Purple);
				break;
			case 5:
				SelectObject(buff_hDC, Cyan);
				break;
			case 6:
				SelectObject(buff_hDC, Red);
				break;
			case 7:
				SelectObject(buff_hDC, Yellow);
				break;
			case 8:
				SelectObject(buff_hDC, Gray);
				break;
			default:
				break;
			}
			Rectangle(buff_hDC, 150 + (j - 1) * 32, 20 + (i - 1) * 32, 150 + j * 32, 20 + i * 32);
		}
	}

	BitBlt(ps.hdc, 0, 0, rc.right, rc.bottom, buff_hDC, 0, 0, SRCCOPY);

	DeleteObject(&borderPen);
	DeleteObject(&bgBrush);
	DeleteObject(&blockPen);
	DeleteObject(&Yellow);
	DeleteObject(&Green);
	DeleteObject(&Blue);
	DeleteObject(&Red);
	DeleteObject(&Cyan);
	DeleteObject(&Gray);
	DeleteObject(&Purple);
	DeleteObject(&White);
	DeleteObject(&bitmap);
	DeleteDC(buff_hDC);

	EndPaint(hwnd, &ps);
}

LRESULT CALLBACK WndProc(
	_In_  HWND hwnd,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
	)
{
	switch (uMsg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			MoveBlock(0);
			break;
		case VK_RIGHT:
			MoveBlock(1);
			break;
		case VK_DOWN:
			MoveBlock(2);
			break;
		case VK_UP:
			Rotate();
			break;
		default:
			break;
		}
		break;
	case WM_PAINT:
		Paint(hwnd);
		isPainting = 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int CALLBACK WinMain(
	_In_  HINSTANCE hInstance,
	_In_  HINSTANCE hPrevInstance,
	_In_  LPSTR lpCmdLine,
	_In_  int nCmdShow
	)
{
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 21; ++j)
			map[i][j] = 0;
	}
	WNDCLASS wc = {};
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = L"mainFrm";
	wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
	RegisterClass(&wc);
	hWnd = CreateWindow(L"mainFrm", L"¶íÂÞË¹·½¿é", WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX, 100, 100, 640, 720, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL)
		return 1;
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	DWORD threadID;
	HANDLE hGameLogicThread = CreateThread(NULL, 0, GameLogic, 0, NULL, &threadID);
	MSG message;
	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return 0;
}