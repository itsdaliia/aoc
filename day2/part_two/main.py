with open("../input.txt", "r") as f:
    line = f.readline()

sum = 0
found = True
values = line.split(",")
for pair in values:
    for num in range(int(pair.split("-")[0]), int(pair.split("-")[1])):
        s = str(num)
        for i in range(1, len(s)):
            found = True

            if len(s) % i != 0:
                continue

            value = s[:i]
            for j in range(i, len(s), i):
                if s[j:j+i] != value:
                    found = False
                    break

            if found:
                sum += num
                break

print(sum)