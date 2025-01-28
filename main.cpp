#include <iostream>
using namespace std;
bool gameOver;
const int width = 10;
const int height = 20;
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
        cout << "F";
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

void input() {}

void logic() {}

int main() {
  setup();
  while (!gameOver) {
    draw();
    input();
    logic();
  }
  return 0;
}
