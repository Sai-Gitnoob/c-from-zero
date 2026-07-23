#include <stdio.h>

int main() {
  int i =0;
    while (i<5){
      printf("The i is less than 5\n");
      printf("%d\n",i);
      if (i==2){
        printf("The current i is 2\n");
        printf("%d\n",i);
        i+=1;
        continue;
      }
      printf("This is executed only if the i value is not 2\n");
      i+=1;
    }


    return 0;
}