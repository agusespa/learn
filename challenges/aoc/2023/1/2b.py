import time
import re

with open("input.txt", 'r') as file:
    lines = file.readlines()

# only for testing performance
start_time = time.time()

def match_string(s):
    if s == "one":
        return '1'
    elif s == "two":
        return '2'
    elif s == "three":
        return '3'
    elif s == "four":
        return '4'
    elif s == "five":
        return '5'
    elif s == "six":
        return '6'
    elif s == "seven":
        return '7'
    elif s == "eight":
        return '8'
    elif s == "nine":
        return '9'
    else:
        return s

def find_first_last_digits(s):
  first = re.findall(r'\d|one|two|three|four|five|six|seven|eight|nine', s)
  last = re.findall(r'\d|eno|owt|eerht|ruof|evif|xis|neves|thgie|enin', "".join(reversed(s)))
  matched_first = match_string(first[0])
  matched_last = match_string("".join(reversed(last[0])))
  n = matched_first + matched_last
  return int(n)

result = sum([find_first_last_digits(l) for l in lines])
print(f"Result: {result}")


# only for testing performance
end_time = time.time()
execution_time = end_time - start_time
print("Execution Time:", execution_time, "seconds")
