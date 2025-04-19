#pragma once
#include <vector>
#include <cstdlib>

class Map{
public:
  Map(int width, int height);
  void render(int playerX, int playerY);
  bool isWalkable(int x, int y);

private:
  int width, height;
  std::vector<std::vector<char>> tiles;
};
