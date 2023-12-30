import time

def check_string(s):
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
        return '0'


# less performant
# def check_string(s):
#     switch = {
#         "one": '1',
#         "two": '2',
#         "six": '6',
#         "four": '4',
#         "five": '5',
#         "nine": '9',
#         "three": '3',
#         "seven": '7',
#         "eight": '8'
#     }
#     return switch.get(s, '0')


def main():
    with open("input.txt", 'r') as file:
        lines = file.readlines()
    
    # only for testing performance
    start_time = time.time()

    count = 0
    
    for line in lines:
        first = 'x'
        last = 'x'
        left = 0
        right = 0
        
        while left < len(line) - 2:
            if right == len(line) - 1:
                right -= 1

            current_char = line[right]
            
            if current_char.isdigit():
                if right - left < 2:
                    first = current_char
                    break
                else:
                    left += 1
                    right = left + 1
            else:
                if left == right:
                    right += 1
                elif right - left < 2:
                    if right == len(line) - 2:
                        left += 1
                    else: right += 1
                elif right - left > 4:
                    left += 1
                    right = left + 1
                else:
                    number_from_string = check_string(line[left:right + 1])
                    if number_from_string == '0':
                        if right == len(line) - 2:
                            left += 1
                        else: right += 1
                    else:
                        first = number_from_string
                        break

        left = len(line) - 2
        right = left
        while right >= 0:
            current_char = line[left]
            
            if current_char.isdigit():
                if right - left < 2:
                    last = current_char
                    break
                else:
                    right -= 1
                    left = right - 1
            else:
                if left == right:
                    left -= 1
                elif right - left < 2:
                    if left >= 1:
                        left -= 1
                    else: right -= 1
                elif right - left > 4:
                    right -= 1
                    left = right - 1
                else:
                    number_from_string = check_string(line[left:right + 1])
                    if number_from_string == '0':
                        if left >= 1:
                            left -= 1
                        else: right -= 1
                    else:
                        last = number_from_string
                        break
    
        n = first+last
        count += int(n)

    print(f"result: {count}")

    # only for testing performance
    end_time = time.time()
    execution_time = end_time - start_time
    print("Execution Time:", execution_time, "seconds")

main()
