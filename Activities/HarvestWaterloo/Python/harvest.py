rows = int(input())
columns = int(input())

score = {"*": 0, "L": 10, "M": 5, "S": 1}
patch = [[score[c] for c in input()] for _ in range(rows)]

start_row = int(input())
start_column = int(input())

stack = list[tuple[int, int, int]]()
stack.append(
    (
        start_row,
        start_column,
        patch[start_row][start_column],
    )
)
patch[start_row][start_column] = 0

total = 0
while stack:
    r, c, reward = stack.pop()
    total += reward
    for dr, dc in ((0, 1), (-1, 0), (0, -1), (1, 0)):
        nr, nc = r + dr, c + dc
        if 0 <= nr < rows and 0 <= nc < columns and patch[nr][nc]:
            stack.append((nr, nc, patch[nr][nc]))
            patch[nr][nc] = 0

print(total)
