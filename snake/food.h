#ifndef __FOODH
#define __FOODH

typedef struct food {
  int xpos;
  int ypos;
  char foodchar;
} food;


food *createFood(int maxWidth, int maxHeight, char foodc);

food* replaceFood(food* prevfood, int maxWidth, int minWidth, char foodc);


#endif
