#include <stdio.h>
#include <stdlib.h>

int rows, cols, m;

int value(int r, int c) {
  int v = (r - 1) * cols + (c - 1);
  return v % m + 1;
}

int min(int a, int b) { return a < b ? a : b; }

int main() {
  scanf("%d\n%d\n%d", &rows, &cols, &m);

  int *costs = malloc(sizeof(int) * (cols + 1));
  int *costsBuffer = malloc(sizeof(int) * (cols + 1));
  int c, r;

  for (c = 1; c <= cols; c++)
    costs[c] = value(1, c);

  for (r = 2; r <= rows; r++) {
    for (c = 1; c <= cols; c++) {
      int costHere = value(r, c);
      int cost = costHere + costs[c];
      if (c > 1)
        cost = min(cost, costHere + costs[c - 1]);
      if (c < cols)
        cost = min(cost, costHere + costs[c + 1]);
      costsBuffer[c] = cost;
    }
    for (c = 1; c <= cols; c++)
      costs[c] = costsBuffer[c];
  }
  int leastCost = costs[1];
  for (c = 2; c <= cols; c++)
    leastCost = min(leastCost, costs[c]);

  printf("%d\n", leastCost);

  free(costs);
  free(costsBuffer);
  return 0;
}