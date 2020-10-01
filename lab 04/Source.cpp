#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	printf(" <-0-> ");
}
void erase_ship(int x, int y) {
	gotoxy(x, y);
	printf("       ");
}
int main()
{
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a'){
				if (x<=0)
				{
					x = 1;
				}
			 draw_ship(--x, y); }

			
			if (ch == 'd'){
				if (x >= 74) {
					x = 74;

			}
			 draw_ship(++x, y); }
			
			if (ch == 'w') 
			{
				if (y <= 0)
				{
					y = 1;
				}
				erase_ship(x, y);
				
				draw_ship(x, --y); }
			
			if (ch == 's') 
			{	if(y>=23)
			{
				y = 23;
			}
				erase_ship( x, y);
				draw_ship(x, ++y); }
			
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}
