import time
from functools import reduce
import numpy as np
import numpy as np
import matplotlib
matplotlib.use("TkAgg")

ALPHABET = list("abcdefghijklmnopqrstuvwxyz")

# only for testing performance
start_time = time.time()

def parse_single_string():
    filename = "input.txt"
    with open(filename, "r") as f:
        data = f.readlines()
    arr = [a.replace("\n", "") for a in data]
    return arr

arr = parse_single_string()

priorities = {ch: i + 1 for i, ch in enumerate(ALPHABET)}
priorities.update({ch.upper(): i + 27 for i, ch in enumerate(ALPHABET)})

ans = 0
for i in range(0, len(arr), 3):
    common = reduce(np.intersect1d, [list(arr[i]), list(arr[i + 1]), list(arr[i + 2])])[0]
    ans += priorities[common]

print("Result:", ans)

# only for testing performance
end_time = time.time()
execution_time = end_time - start_time
print("Execution Time:", execution_time, "seconds") # 0.0053 on 2016 macbook
