#include <ncurses.h>

int main()
{
	initscr();
	getch();
	move(-1,-1);
	getch();
}
