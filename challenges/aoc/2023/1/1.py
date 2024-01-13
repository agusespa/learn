import time

with open("input.txt", "r") as file:
    lines = file.readlines()

# only for testing performance
start_time = time.time()

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

# only for testing performance
end_time = time.time()
execution_time = end_time - start_time
print("Execution Time:", execution_time, "seconds")
