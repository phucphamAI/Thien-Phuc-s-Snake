#include "Thien Phuc's Snake.h"

int main()
{
	srand(time(NULL));//gieo lại hạt giống cho rand()
	ShowCur(0);
	ve();
	bang_menu();
	Sleep(1500);
	_getch();
}

