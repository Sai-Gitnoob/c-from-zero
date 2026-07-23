#include <stdio.h>

int main() {
    int i = -3;
    while (i<3){
      printf("This is the while loop statement\n");
      if (i==1){
          printf("this has entered the break Statement");
          break;
      }
      printf("this is executed if i != 1");
      i+=1;
    }

    return 0;
}
//Same concept works with the do while loop