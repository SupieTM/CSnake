#ifndef __WINDOWH
#define __WINDOWH
#include "snake.h"
#include "food.h"


void drawScreen(char boundaries, snake *player, food* fd, int maxW, int maxH);

void drawScreen_S(char boundaries, snake *player, food* fd, int maxW, int maxH);
#endif //WindowH
