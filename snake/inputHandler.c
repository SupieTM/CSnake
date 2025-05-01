#include <windows.h>
#include "inputHandler.h"

int getInput() {
  if (GetAsyncKeyState(37) < 0 || GetAsyncKeyState('A') < 0) {
    return 1;
  }
  if (GetAsyncKeyState(38) < 0 || GetAsyncKeyState('W') < 0) {
    return 2;
  }
  if (GetAsyncKeyState(39) < 0 || GetAsyncKeyState('D') < 0) {
    return 3;
  }
  if (GetAsyncKeyState(40) < 0 || GetAsyncKeyState('S') < 0) {
    return 4;
  }
  
  return 0;
}
