import time

with open("sample.txt", "r") as file:
    # with open("input.txt", 'r') as file:
    lines = file.readlines()

# only for testing performance
start_time = time.time()

content = ""
for line in file:
    content += line + "\n"

print("File content:\n", content)

# only for testing performance
end_time = time.time()
execution_time = end_time - start_time
print("Execution Time:", execution_time, "seconds")
