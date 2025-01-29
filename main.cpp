#include <conio.h>
#include <iostream>
using namespace std;
bool gameOver;
const int width = 30;
const int height = 8;
int x, y, foodX, foodY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
void setup() {
  gameOver = false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  foodX = rand() % width;
  foodY = rand() % height;
  score = 0;
}

void draw() {
  system("clear");
  for (int i = 0; i < width + 2; i++)
    cout << "#";
  cout << endl;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0)
        cout << "#";
      if (i == y && j == x)
        cout << "O";
      else if (i == foodY && j == foodX)
        cout << "X";
      else
        cout << " ";
      if (j == width - 1)
        cout << "#";
    }
    cout << endl;
  }

  for (int i = 0; i < width + 2; i++)
    cout << "#";
  cout << endl;
  cout << "Score:" << score << endl;
}

void input() {
  if (_kbhit()) {
    switch (_getch()) {
    case 'a':
      dir = LEFT;
      break;
    case 'd':
      dir = RIGHT;
      break;
    case 'w':
      dir = UP;
      break;
    case 's':
      dir = DOWN;
      break;
    case 'x':
      gameOver = true;
      break;
    }
  }
}

void logic() {
  switch (dir) {
  case LEFT:
    x--;
    break;
  case RIGHT:
    x++;
    break;
  case UP:
    y--;
    break;
  case DOWN:
    y++;
    break;
  default:
    break;
  }
  if (x >= width)
    x = 0;
  else if (x < 0)
    x = width - 1;

  if (y >= height)
    y = 0;
  else if (y < 0)
    y = height - 1;

  if (x == foodX && y == foodY) {
    score += 10;
    foodX = rand() % width;
    foodY = rand() % height;
  }
}

int main() {
  setup();
  while (!gameOver) {
    draw();
    input();
    logic();
  }
  return 0;
}
