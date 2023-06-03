import time
import collections

filename = "corpus.txt"
string = ''
word = ''
wordMap = dict()


def addToMap(word):
    if word not in wordMap:
        wordMap[word] = 1
    else:
        wordMap[word] += 1


def cleanWord(word):
    word = word.replace(".", "")
    word = word.replace(",", "")
    word = word.replace("\"", "")
    word = word.replace("!", "")
    word = word.replace("?", "")
    word = word.replace(";", "")
    return word


with open(filename) as f:
    string = f.read()

start = start_time = time.time()

for word in string.lower().split():
    addToMap(cleanWord(word))

# alt 2
# for char in string:
#     if char == ' ':
#         if string == '':
#             continue
#         else:
#             addToMap(cleanWord(word))
#             word = ''
#     elif char in ['.', ',', '\"', '?', '!', ':', ';']:
#         continue
#     else:
#         word += char.lower()

finish = time.time()
elapsed = finish - start
print("Elapsed time:", elapsed, "seconds")

d = collections.Counter(wordMap)
for word, count in d.most_common(10):
    print(word, ": ", count)
