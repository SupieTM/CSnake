#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "inputHandler.h"
#include "snake.h"
#include "window.h"

//Game Settings
//frameTime is defined in ms, the snake moves once per frame
#define winHeight 20
#define winWidth 20
#define charSnake 'O'
#define charFood 'X'
#define charBoundaries '#'
#define frameTime 250

int main(int argc, char *argv[]) {
  snake *player;
  food *fd = createFood(winHeight + 2, winWidth + 2, charFood);

  player = initalizeSnake(winHeight / 2, winWidth / 2, charSnake);

  int input = 1;
  int prevposarray[5] = {0, 3, 4, 1, 2};
  int points = 0;

  time_t starttimer, currenttimer;

  starttimer = clock();

  bool foodEaten = false;
  bool lost = false;

  drawScreen(charBoundaries, player, fd, winHeight + 1, winWidth + 1);
  
  //MainLoop
  while (!lost) {
    currenttimer = clock();

    if (currenttimer - starttimer > frameTime) {
      printf("\033c");
      printf("Score: %d\n", points);
      starttimer = clock();

      if (foodEaten) {
        growSnake(player, input);
        foodEaten = false;
      } else {
        moveSnake(player, input);
      }

      drawScreen(charBoundaries, player, fd, winHeight + 1, winWidth + 1);

      if (checkSnakeHitbox(winHeight + 2, winWidth + 2, player)) {
        lost = true;
      }

      if (headOnFood(player, fd)) {
        foodEaten = true;
        points++;
        fd = replaceFood(fd, winHeight + 2, winWidth + 2, charFood);
      }

      while (bodyOnFood(player, fd)) {
        fd = replaceFood(fd, winHeight + 2, winWidth + 2, charFood);
      }
    }

    int temp;

    if ((temp = getInput()) > 0) {
      if (temp != prevposarray[input]) {
        input = temp;
      }
    }
  }
  printf("\033c");
  printf("You lost\nYou scored: %d Points", points);

  return EXIT_SUCCESS;
}
