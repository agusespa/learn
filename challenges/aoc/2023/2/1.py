# with open("sample.txt", 'r') as file:
with open("input.txt", 'r') as file:
    lines = file.readlines()

count = 0

for line in lines:
    id = 0

    for block in range(6, len(line)):
        if line[block] == ':':
            id = int(line[5:block])
            line = line[block+1:]
            break

    mainBlocks = line.split(';')

    isValid = True

    for b in mainBlocks:
        red, green, blue = 0, 0, 0
        subBlock = b.split(',')
        for s in subBlock:
            color = s.lstrip().split(' ')
            if color[1].startswith('r'):
                red += int(color[0])
            elif color[1].startswith('g'):
                green += int(color[0])
            elif color[1].startswith('b'):
                blue += int(color[0])

        if red > 12 or green > 13 or blue > 14:
            isValid = False

    if isValid:
        count += id

print("result: ", count)
