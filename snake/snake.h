#ifndef __snakeH
#define __snakeH

#include <stdbool.h>
#include "food.h"

typedef struct snake {
  int length;
  int hitbox[100][2];
  char snakeBody;
} snake;

snake *initalizeSnake(int x, int y, char style);

void growSnake(snake *player, int direction);

bool checkSnakeHitbox(int maxscreenW, int maxscreenH, snake *player);

void printSnake(snake *player);

bool checkSnakePosition(int x, int y, snake *player);

void pushSnakeBodyBack(snake *player);

void moveSnake(snake *player, int direction);

bool headOnFood(snake *player, food *fd);

bool bodyOnFood(snake *player, food *fd);

#endif
