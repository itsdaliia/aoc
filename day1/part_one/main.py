with open("../input.txt") as f:
    i = f.read()

psw = 0
dial = 50
for line in i.splitlines():
    if line[:1] == "L":
        dial -= int(line[1:])
        while dial < 0:
            dial += 100
    else:
        dial += int(line[1:])
        while dial >= 100:
            dial -= 100

    if dial == 0:
        psw += 1

print(psw)