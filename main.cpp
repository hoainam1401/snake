#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

using namespace std;

bool gameOver;
const int width = 30;
const int height = 8;
int x, y, foodX, foodY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void setup() {
  gameOver = false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  srand(time(0)); // Seed the random number generator
  foodX = rand() % width;
  foodY = rand() % height;
  score = 0;

  // Initialize ncurses
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  curs_set(0);
  timeout(100); // Add explicit timeout setting
}

void draw() {
  clear();

  // Draw top border
  for (int i = 0; i < width + 2; i++)
    printw("#");
  printw("\n");

  // Draw sides and game area
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0)
        printw("#");

      if (i == y && j == x)
        printw("O");
      else if (i == foodY && j == foodX)
        printw("X");
      else {
        bool printed = false;
        for (int k = 0; k < nTail; k++) {
          if (tailX[k] == j && tailY[k] == i) {
            printw("o");
            printed = true;
            break;
          }
        }
        if (!printed)
          printw(" ");
      }

      if (j == width - 1)
        printw("#");
    }
    printw("\n");
  }

  // Draw bottom border
  for (int i = 0; i < width + 2; i++)
    printw("#");
  printw("\n");

  // Print score
  printw("Score: %d\n", score);
  refresh();
}

void input() {
  // Add a refresh to ensure the terminal state is updated
  refresh();
  
  int ch = getch();
  if (ch != ERR) {
    switch (ch) {
    case 'a':
    case KEY_LEFT:
      if (dir != RIGHT) // Prevent moving directly into yourself
        dir = LEFT;
      break;
    case 'd':
    case KEY_RIGHT:
      if (dir != LEFT)
        dir = RIGHT;
      break;
    case 'w':
    case KEY_UP:
      if (dir != DOWN)
        dir = UP;
      break;
    case 's':
    case KEY_DOWN:
      if (dir != UP)
        dir = DOWN;
      break;
    case 'x':
    case 'q':
      gameOver = true;
      break;
    }
  }
}

void logic() {
  int prevX = tailX[0];
  int prevY = tailY[0];
  int prev2X, prev2Y;
  tailX[0] = x;
  tailY[0] = y;
  for (int i = 1; i < nTail; i++) {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }
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
  for (int i = 0; i < nTail; i++) {
    if (tailX[i] == x && tailY[i] == y) {
      gameOver = true; // Collision with tail
    }
  }
  if (x == foodX && y == foodY) {
    score += 10;
    foodX = rand() % width;
    foodY = rand() % height;
    nTail++;
  }
}

int main() {
  setup();
  while (!gameOver) {
    draw();
    input();
    logic();
    usleep(100000); // Sleep for 100ms to control game speed
  }
  endwin(); // Clean up ncurses
  return 0;
}
