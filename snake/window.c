#include "food.h"
#include "snake.h"
#include <stdio.h>

void drawScreen(char boundaries, snake *player, food *fd, int maxW, int maxH) {
  maxW++;
  maxH++;
  for (int i = 0; i <= maxH; i++) {
    for (int j = 0; j <= maxW; j++) {
      if (j == 0 || j == maxW) {
        printf("%c", boundaries);
      } else if (i == 0 || i == maxH) {
        printf("%c", boundaries);
      } else if (checkSnakePosition(j, i, player)) {
        printf("%c", player->snakeBody);
      } else if (j == fd->xpos && i == fd->ypos) {
        printf("%c", fd->foodchar);
      } else {
        printf(" ");
      }
    }

    printf("\n");
  }
}
void drawScreen_S(char boundaries, snake *player, food *fd, int maxW, int maxH) {
  maxW++;
  maxH++;
  char printSCR[maxW+2][maxH+1];
  for (int i = 0; i <= maxH; i++) {
    for (int j = 0; j <= maxW + 1; j++) {
      if (j == 0 || j == maxW) {
        printSCR[i][j] = boundaries;
      } else if (i == 0 || i == maxH) {
        printSCR[i][j] = boundaries;
      } else if (checkSnakePosition(j, i, player)) {
        printSCR[i][j] = player->snakeBody;
      } else if (j == fd->xpos && i == fd->ypos) {
        printSCR[i][j] = fd->foodchar;
      } else {
        printSCR[i][j] = ' ';
      }
    }
   printSCR[i][maxW+1] = '\n';
  }
   printSCR[maxH][maxW+1] = '\0';
  for (int i = 0; i <= maxH; i++) {
    for (int j = 0; j <= maxW + 1; j++) {
       printf("%c", printSCR[i][j]);
    }
  }
}
