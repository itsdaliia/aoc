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

timelines = {(0, start): 1}
for row in range(rows):
    for col in range(cols):
        if (row, col) not in timelines:
            continue

        count = timelines[(row, col)]
        cell = grid[row][col]

        if cell == '^':
            left = (row + 1, col - 1)
            right = (row + 1, col + 1)
            timelines[left] = timelines.get(left, 0) + count
            timelines[right] = timelines.get(right, 0) + count
        else:
            down = (row + 1, col)
            if down[0] < rows and 0 <= down[1] < cols:
                timelines[down] = timelines.get(down, 0) + count

result = 0
for (r, c), cnt in timelines.items():
    if r == rows - 1:
        if grid[r][c] == '^':
            result += cnt * 2
        else:
            result += cnt

print(result)