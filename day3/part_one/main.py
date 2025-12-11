with open("../input.txt", "r") as f:
    lines = f.read()

joltage_total = 0
for line in lines.splitlines():
    m = 0
    n = len(line)
    for i in range(n):
        for j in range(i + 1, n):
            val = int(line[i] + line[j])
            if val > m:
                m = val

    joltage_total += m

print(joltage_total)
