#include <stdio.h>

int main() {

  int x, y;
  scanf("%d %d", &x, &y);
  int dist = y - x;
  int speed = 1;
  while (dist >= speed * speed) {
    if (dist == speed * speed) {
      printf("%d", 2 * speed - 1);
      return 0;
    }
    speed++;
  }
  
  speed -= 1;
  int travel_time = speed;
  dist -= speed * (speed + 1) / 2;
  while (dist != 0) {
    if (dist >= (speed * (speed + 1) / 2)) {
      dist -= speed;
    } else {
      speed -= 1;
      dist -= speed;
    }
    travel_time += 1;
  }
  
  printf("%d", travel_time);
  return 0;
}