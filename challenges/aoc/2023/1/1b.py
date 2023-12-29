with open("input.txt", "r") as file:
    lines = file.readlines()

count = 0

for line in lines:
    first = 'x'
    last = 'x'

    for char in line:
        if char.isdigit():
            first = char
            break

    for i in range(len(line)-1, -1, -1):
        if line[i].isdigit():
            last = line[i]
            break

    n = first+last
    count += int(n)

print(f"result: {count}")
