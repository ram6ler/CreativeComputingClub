#include <iostream>
#include <vector>

using namespace std;

int rows, cols, m;

int value(int r, int c) {
  int v = (r - 1) * cols + (c - 1);
  return v % m + 1;
}

int main() {
  cin >> rows >> cols >> m;

  vector<int> costs(cols + 1), costsBuffer(cols + 1);
  int c, r;

  for (c = 1; c <= cols; c++)
    costs[c] = value(1, c);

  for (r = 2; r <= rows; r++) {
    for (c = 1; c <= cols; c++) {
      int costHere = value(r, c), cost = costHere + costs[c];
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
  cout << leastCost << endl;

  return 0;
}