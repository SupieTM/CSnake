#include "snake.h"
#include "food.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

snake *initalizeSnake(int x, int y, char style) {
  snake *player;
  player = malloc(sizeof(*player));
  snake temp = {.hitbox = {0, 0}, .snakeBody = style};

  temp.hitbox[0][0] = x;
  temp.hitbox[0][1] = y;
  temp.length = 1;

  *player = temp;

  return player;
}

void growSnake(snake *player, int direction) {
  for (int i = player->length; i > 0; i--) {
    player->hitbox[i][0] = player->hitbox[i - 1][0];
    player->hitbox[i][1] = player->hitbox[i - 1][1];
  }
  if (direction == 0) {
    return;
  } else if (direction == 1) {
    if (player->length <= 1) {
      player->hitbox[0][0]--;
    } else {
      player->hitbox[0][0] = player->hitbox[1][0] - 1;
      player->hitbox[0][1] = player->hitbox[1][1];
    }
  } else if (direction == 2) {
    if (player->length <= 1) {
      player->hitbox[0][1]--;
    } else {
      player->hitbox[0][0] = player->hitbox[1][0];
      player->hitbox[0][1] = player->hitbox[1][1] - 1;
    }
  } else if (direction == 3) {
    if (player->length <= 1) {
      player->hitbox[0][0]++;
    } else {
      player->hitbox[0][0] = player->hitbox[1][0] + 1;
      player->hitbox[0][1] = player->hitbox[1][1];
    }

  } else if (direction == 4) {
    if (player->length <= 1) {
      player->hitbox[0][1]++;
    } else {
      player->hitbox[0][0] = player->hitbox[1][0];
      player->hitbox[0][1] = player->hitbox[1][1] + 1;
    }
  }

  player->length++;
}

bool checkSnakeHitbox(int maxscreenW, int maxscreenH, snake *player) {

  for (int i = player->length; i >= 1; i--) {
    if (player->hitbox[i][0] == player->hitbox[0][0] &&
        player->hitbox[i][1] == player->hitbox[0][1]) {
      return true;
    }
  }

  if ((*player).hitbox[0][0] <= 0 || (*player).hitbox[0][0] >= maxscreenW) {
    return true;
  }

  if ((*player).hitbox[0][1] <= 0 || (*player).hitbox[0][1] >= maxscreenH) {
    return true;
  }

  return false;
}

void printSnake(snake *player) {
  int i = 0;
  while ((*player).hitbox[i][0] != 0 && (*player).hitbox[i][1] != 0) {
    printf("x: %d, y: %d\n", (*player).hitbox[i][0], (*player).hitbox[i][1]);
    i++;
  }
}

bool checkSnakePosition(int x, int y, snake *player) {

  int i = 0;

  while ((*player).hitbox[i][1] != 0 && (*player).hitbox[i][0] != 0) {
    if ((*player).hitbox[i][0] == x && (*player).hitbox[i][1] == y) {
      return true;
    }
    i++;
  }

  return false;
}

void pushSnakeBodyBack(snake *player) {
  if ((*player).length <= 1) {
    return;
  } else {
    int i = (*player).length - 1;
    while (i >= 1) {
      (*player).hitbox[i][0] = (*player).hitbox[i - 1][0];
      (*player).hitbox[i][1] = (*player).hitbox[i - 1][1];
      i--;
    }
  }
}

void moveSnake(snake *player, int direction) {
  if (direction == 0) {
    return;
  } else if (direction == 1) {
    pushSnakeBodyBack(player);
    if (player->length <= 1) {
      player->hitbox[0][0]--;
    } else {
      player->hitbox[0][0] = player->hitbox[1][0] - 1;
      player->hitbox[0][1] = player->hitbox[1][1];
    }
  } else if (direction == 2) {
    pushSnakeBodyBack(player);
    if (player->length <= 1) {
      player->hitbox[0][1]--;
    } else {
      player->hitbox[0][0] = player->hitbox[1][0];
      player->hitbox[0][1] = player->hitbox[1][1] - 1;
    }
  } else if (direction == 3) {
    pushSnakeBodyBack(player);
    if (player->length <= 1) {
      player->hitbox[0][0]++;
    } else {
      player->hitbox[0][0] = player->hitbox[1][0] + 1;
      player->hitbox[0][1] = player->hitbox[1][1];
    }

  } else if (direction == 4) {
    pushSnakeBodyBack(player);
    if (player->length <= 1) {
      player->hitbox[0][1]++;
    } else {
      player->hitbox[0][0] = player->hitbox[1][0];
      player->hitbox[0][1] = player->hitbox[1][1] + 1;
    }
  }
}

bool headOnFood(snake *player, food *fd) {
  return (player->hitbox[0][0] == fd->xpos && player->hitbox[0][1] == fd->ypos);
}

bool bodyOnFood(snake *player, food *fd) {

  for (int i = 1; i < player->length; i++) {
    if (player->hitbox[i][0] == fd->xpos && player->hitbox[i][1] == fd->ypos) {
      return true;
    }
  }

  return false;
}
