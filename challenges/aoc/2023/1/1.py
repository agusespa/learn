with open("input.txt", "r") as file:
    lines = file.readlines()

count = 0

for line in lines:
    first = 'x'
    last = 'x'

    for char in line:
        if char.isdigit():
            if first == 'x':
                first = char
            else:
                last = char

    if last == 'x':
        last = first

    n = first+last
    count += int(n)

print(f"result: {count}")
