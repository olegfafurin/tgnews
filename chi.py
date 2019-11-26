import sys, re

if len(sys.argv) < 3:
	print("USAGE: python chi.py <file with stat> <file to check> [--justprint]")
	exit(0)

l = open(sys.argv[1], "r", encoding="utf-8").readlines()
d = dict()
for u, v in list(map(lambda x: x[:-1].split(": "), l)):
	if int(v) == 0 or "-" in u:
		continue
	d[u] = int(v)


rusl = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюя '
corresp = {x: int.from_bytes(x.encode('cp1251'), 'big') for x in rusl}

if "--justprint" in sys.argv[2:]:
	s = '{ '
	for u in list(d.keys()):
		s += "{" + '{' + str(corresp[u[0]]) + "," + str(corresp[u[1]]) + '}' + ", " + str(d[u]) + "},"
	s = s[:-1] + "}"
	print(s)
	exit(0)

g = {key: 0 for key in d}
length = len(list(d.keys())[0])
checkfile = open(sys.argv[2], "r", encoding="utf-8").read()
words = re.findall("\w+", checkfile)
bad = 0
for word in words:
	w = " " + word + " "
	for i in range(len(w) - length + 1):
		if w[i:i+2] in g:
			g[w[i:i+2]] += 1
		elif "_" in w[i:i+2]:
			bad += 1
d["_" * length] = 1
g["_" * length] = bad
sumd = sum(list(d.values()))
sumg = sum(list(g.values()))
for key in list(g.keys()):
	d[key] = d[key] / sumd
	g[key] = g[key] / sumg
	print(key + ": expected " + str(d[key]) + ";  got " + str(g[key]))
chi_squared = sum([(g[key] - d[key]) ** 2 / d[key] for key in list(g.keys())])
print(chi_squared)
