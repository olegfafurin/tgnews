import sys, re, itertools as it

if len(sys.argv) < 2:
	print("USAGE: python makestat.py <filename> [-rus]")
	exit(0)

if "-rus" in sys.argv[2:]:
	letters = [chr(o) for o in range(ord('а'), ord('я') + 1)]
else:
	letters = [chr(o) for o in range(ord('a'), ord('z') + 1)]
letters.extend([' ', '-'])
threegrams = {a : 0 for a in list(map(lambda x: "".join(x), it.product(letters, letters, letters)))}
bigrams = {a : 0 for a in list(map(lambda x: "".join(x), it.product(letters, letters)))}

def get3grams(w):
	word = " " + w.lower() + " "
	for i in range(0, len(word) - 2):
		if word[i:i+3] in threegrams:
			threegrams[word[i:i+3]] += 1
	for i in range(0, len(word) - 1):
		if word[i:i+2] in bigrams:
			bigrams[word[i:i+2]] += 1



filename = sys.argv[1]
text = open(filename, "r", encoding = "utf-8").read()
for word in list(map(str.lower, re.findall("\w+", text))):
	get3grams(word)

g = open(filename[:filename.rfind('.')]  + "3.stat", "w+")
for entry in threegrams:
	g.write(entry + ": " + str(threegrams[entry]) + "\n")
g.close()

g = open(filename[:filename.rfind('.')] + "2.stat", "w+")
for entry in bigrams:
	g.write(entry + ": " + str(bigrams[entry]) + "\n")
g.close()
