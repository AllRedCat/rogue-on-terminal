#include "Map.h"
#include <ncurses.h>

Map::Map(int width, int height) : width(width), height(height) {
  tiles.resize(height, std::vector<char>(width, ' '));

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      tiles[y][x] = (rand() % 10 < 3) ? '#' : ' ';
    }
  }
}

void Map::render(int playerX, int playerY) {
  for (int y = 0; y < height; y++){
    for (int x = 0; x < width; x++) {
      if (abs(x - playerX) <= 5 &&  abs(y - playerY) <= 5) {
        mvaddch(y, x, tiles[y][x]);
      } else {
        mvaddch(y, x, ':');
      }
    }
  }
}

bool Map::isWalkable(int x, int y) {
  return x >= 0 && y >= 0 && x < width && y < height && tiles[y][x] == ' ';
}
