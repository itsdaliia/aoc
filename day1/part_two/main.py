with open("../input.txt") as f:
    i = f.read()

psw = 0
dial = 50
for line in i.splitlines():
    if line[:1] == "L":
        for n in range(0, int(line[1:])):
            dial -= 1
            if dial < 0:
                dial += 100

            if dial == 0:
                psw += 1
    else:
        for n in range(0, int(line[1:])):
            dial += 1
            if dial > 99:
                dial -= 100

            if dial == 0:
                psw += 1

print(psw)