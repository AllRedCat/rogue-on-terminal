#include <ncurses.h>
#include "Map.h"

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);

  Map map(50, 20);
  int playerX = 1, playerY = 1;

  bool running = true;
  while (running) {
    clear();

    map.render(playerX, playerY);
    mvaddch(playerY, playerX, '@');
    
    int key = getch();
    switch (key) {
      case 'q': running = false; break;
      case 'w': if (map.isWalkable(playerX, playerY - 1)) playerY--; break;
      case 's': if (map.isWalkable(playerX, playerY + 1)) playerY++; break;
      case 'a': if (map.isWalkable(playerX - 1, playerY)) playerX--; break;
      case 'd': if (map.isWalkable(playerX + 1, playerY)) playerX++; break;
    }
  }

  endwin();
  return 0;
}
