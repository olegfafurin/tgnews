import sys

if len(sys.argv) < 3:
	print("USAGE: python findtop.py <file with stat> <size of top> [--rev] [--vowels]")
	exit(0)

filename = sys.argv[1]
n = int(sys.argv[2])
l = open(filename, "r", encoding='utf-8').readlines()
d = dict()
for u, v in list(map(lambda x: x[:-1].split(": "), l)):
	d[u] = int(v)

if "--rev" in sys.argv[2:]:
	ds = sorted(d, key=lambda x: (d[x], x))
else:
	ds = sorted(d, key=lambda x: (-d[x], x))

if "--rev" in sys.argv[2:] and "--vowels" in sys.argv[2:]:
	ds = list(filter(lambda x: ("-" not in x) and (len(x) != 3 or x[1] != " ") and ("a" in x or "e" in x or "o" in x or "i" in x or "y" in x or "u" in x), ds))

ds = ds[:n]
for el in ds:
	print('"' + el + '" ' + str(d[el]))

