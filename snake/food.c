#include <stdlib.h>

#include "food.h"

food *createFood(int maxWidth, int maxHeight, char foodc) {
  food *temp = malloc(sizeof(*temp));
  temp->xpos = rand() % (maxWidth-1) + 1; 
  temp->ypos = rand() % (maxHeight-1) + 1;
  temp->foodchar = foodc;
  return temp;
}

food* replaceFood(food* prevfood, int maxWidth, int minWidth, char foodc) {
  free(prevfood);
  return createFood(maxWidth, minWidth, foodc);
}
