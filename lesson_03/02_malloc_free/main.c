#include <stdio.h>
#include <stdlib.h>

int main() {
  int* intArray;
  // Отводим память
  intArray = malloc(100);

  if(intArray == NULL) {
    // Памяти не хватило
    printf("No memory :(");
    return;
  }

  intArray[0] = 10;

  // Освобождение памяти
  free(intArray);

  return 0;
}
