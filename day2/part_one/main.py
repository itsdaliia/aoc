with open("../input.txt", "r") as f:
    line = f.readline()

sum = 0
values = line.split(",")
for pair in values:
    for num in range(int(pair.split("-")[0]), int(pair.split("-")[1])):
        if len(str(num)) % 2 != 0:
            continue

        cut = int(len(str(num)) / 2)
        value = str(num)[:cut]

        if num == int(value + value):
            sum += num

print(sum)