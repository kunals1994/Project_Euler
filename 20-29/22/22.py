import sys

def main(args):
	if(len(args)<2):
		print "Usage: " + args[0] + " file_in"
		return

	names = []
	ret = 0
	index = 1
	base = ord('A') - 1

	with open(args[1], 'rb') as file_in:
		for line in file_in:
			names_in = line.split(",")
			for name in names_in:
				names.append(name.replace('"', ''))


	list.sort(names)

	for name in names:
		score = 0
		for letter in name:
			score += (ord(letter) - base) 

		ret += score * index
		index += 1

	print ret

main(sys.argv)