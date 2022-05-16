#include <ncurses.h>
#include <locale>
int main()
{
	initscr();
	setlocale(LC_ALL, "");
	printw("你好世界\n");
	getch();
    	endwin();
}
