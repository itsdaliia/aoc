with open("../input.txt", "r") as f:
    lines = f.read()

joltage_total = 0
for line in lines.splitlines():
    digits = list(line.strip())
    n = len(digits)
    k = 12

    selected = []
    start = 0
    while k > 0:
        max_digit = max(digits[start:n - k + 1])
        max_index = digits.index(max_digit, start, n - k + 1)
        selected.append(max_digit)
        start = max_index + 1
        k -= 1

    joltage_total += int("".join(selected))

print(joltage_total)
