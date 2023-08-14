import numpy as np

def generate(p1):
    seq = np.zeros(10000)

    for i in range(0, 10000):
        num = np.random.random()
        if num <= p1:
            seq[i] = 1

    return seq

def count(seq):
    counter = 0
    count = 0

    for n in seq:
        if n == 1:
            counter += 1
            if counter == 5:
                count += 1
                counter = 0
        else:
            counter = 0

    return count 

def main(p1):
    seq = generate(p1)
    return count(seq)

print(main(0.66))
