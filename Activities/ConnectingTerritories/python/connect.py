rows = int(input())
cols = int(input())
m = int(input())


def value(r, c):
    v = (r - 1) * cols + (c - 1)
    return v % m + 1


costs = [0] * (cols + 1)
costs_buffer = [0] * (cols + 1)
for c in range(1, cols + 1):
    costs[c] = value(1, c)
for r in range(2, rows + 1):
    for c in range(1, cols + 1):
        cost_here = value(r, c)
        cost = cost_here + costs[c]
        if c > 1:
            cost = min(cost, cost_here + costs[c - 1])
        if c < cols:
            cost = min(cost, cost_here + costs[c + 1])
        costs_buffer[c] = cost
    for c in range(1, cols + 1):
        costs[c] = costs_buffer[c]

least_cost = costs[1]
for c in range(2, cols + 1):
    if costs[c] < least_cost:
        least_cost = costs[c]
print(least_cost)
