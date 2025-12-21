with open("../input.txt", "r") as f:
    lines = f.read().splitlines()

grid = [list(line) for line in lines]
rows = len(grid)
cols = len(grid[0])

start = None
for c in range(cols):
    if grid[0][c] == 'S':
        start = c
        break

count = 0
visited = set()
beams = [(0, start)]

while beams:
    row, col = beams.pop(0)
    if row >= rows or col < 0 or col >= cols:
        continue

    if (row, col) in visited:
        continue

    visited.add((row, col))
    cell = grid[row][col]

    if cell == '^':
        count += 1
        beams.append((row + 1, col - 1))
        beams.append((row + 1, col + 1))
    else:
        beams.append((row + 1, col))

print(count)
