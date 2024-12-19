#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Set;
void add(Set *set, char c) { *set |= (1 << (c - 'a')); }
int contains(Set set, char c) { return (set & (1 << (c - 'a'))) > 0; }

int main() {
  int lines, width;
  char *characters, c;
  scanf("%d %d\n", &lines, &width);
  characters = malloc(width * sizeof(char));

  for (int line = 0; line < lines; line++) {
    Set seen = 0, heavy = 0;
    for (int index = 0; index < width; index++) {
      scanf("%c", &c);
      if (contains(seen, c))
        add(&heavy, c);
      else
        add(&seen, c);
      characters[index] = c;
    }
    scanf("%c", &c);
    int isHeavy = contains(heavy, characters[0]), index;

    for (index = 1; index < width; index++) {
      int nextIsHeavy = contains(heavy, characters[index]);
      if (nextIsHeavy == isHeavy) {
        printf("F\n");
        break;
      }
      isHeavy = nextIsHeavy;
    }
    if (index == width)
      printf("T\n");
  }

  free(characters);
  return 0;
}