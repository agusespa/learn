import time
import re

with open("input.txt", 'r') as file:
    lines = file.readlines()

# only for testing performance
start_time = time.time()

def cv1(s):
  ms = re.findall(r'\d', s)
  return (int(ms[0]) * 10) + int(ms[-1])

pt1 = sum([cv1(l) for l in lines])
print(f"Pt 1: {pt1}")

def pn(s):
  if re.match('\d', s):
    return int(s)

  return {
    'one': 1,
    'two': 2,
    'three': 3,
    'four': 4,
    'five': 5,
    'six': 6,
    'seven': 7,
    'eight': 8,
    'nine': 9
  }[s]

def cv2(s):
  fms = re.findall(r'\d|one|two|three|four|five|six|seven|eight|nine', s)
  lms = re.findall(r'\d|eno|owt|eerht|ruof|evif|xis|neves|thgie|enin', "".join(reversed(s)))
  return (pn(fms[0]) * 10) + pn("".join(reversed(lms[0])))

pt2 = sum([cv2(l) for l in lines])
print(f"Pt 2: {pt2}")


# only for testing performance
end_time = time.time()
execution_time = end_time - start_time
print("Execution Time:", execution_time, "seconds")
