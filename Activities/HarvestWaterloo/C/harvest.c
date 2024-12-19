#include <stdio.h>
#include <stdlib.h>

struct Element {
  int row;
  int column;
  int reward;
  struct Element *next;
};

struct Element *head = NULL;

void push(int row, int column, int reward) {
  struct Element *p = head;
  head = malloc(sizeof(struct Element));
  head->row = row;
  head->column = column;
  head->reward = reward;
  head->next = p;
}

void pop(int *row, int *column, int *reward) {
  *row = head->row;
  *column = head->column;
  *reward = head->reward;
  struct Element *p = head->next;
  free(head);
  head = p;
}

int isEmpty() { return head == NULL; }

#define POP                                                                    \
  {                                                                            \
    pop(&r, &c, &reward);                                                      \
    total += reward;                                                           \
  }

#define OKAY_TO_PUSH_NEIGHBOR                                                  \
  (nr >= 0) && (nr < rows) && (nc >= 0) && (nc < columns) && (patch[nr][nc])

#define PUSH_NEIGHBOR                                                          \
  {                                                                            \
    push(nr, nc, patch[nr][nc]);                                               \
    patch[nr][nc] = 0;                                                         \
  }

int main() {
  int rows, columns, startRow, startColumn, total = 0;
  char ch;

  scanf("%d", &rows);
  scanf("%d", &columns);

  int **patch = malloc(rows * sizeof(int *));

  for (int r = 0; r < rows; r++) {
    patch[r] = malloc(columns * sizeof(int));
    scanf("%c", &ch);
    for (int c = 0; c < columns; c++) {
      scanf("%c", &ch);
      if (ch == '*')
        patch[r][c] = 0;
      if (ch == 'L')
        patch[r][c] = 10;
      if (ch == 'M')
        patch[r][c] = 5;
      if (ch == 'S')
        patch[r][c] = 1;
    }
  }

  scanf("%d", &startRow);
  scanf("%d", &startColumn);

  push(startRow, startColumn, patch[startRow][startColumn]);
  patch[startRow][startColumn] = 0;

  while (!isEmpty()) {
    int r, c, nr, nc, reward;
    POP;

    nr = r;
    nc = c + 1;
    if (OKAY_TO_PUSH_NEIGHBOR)
      PUSH_NEIGHBOR;

    nr = r - 1;
    nc = c;
    if (OKAY_TO_PUSH_NEIGHBOR)
      PUSH_NEIGHBOR;

    nr = r;
    nc = c - 1;
    if (OKAY_TO_PUSH_NEIGHBOR)
      PUSH_NEIGHBOR;

    nr = r + 1;
    nc = c;
    if (OKAY_TO_PUSH_NEIGHBOR)
      PUSH_NEIGHBOR;
  }

  printf("%d\n", total);

  for (int r = 0; r < rows; r++)
    free(patch[r]);
  free(patch);

  return 0;
}
