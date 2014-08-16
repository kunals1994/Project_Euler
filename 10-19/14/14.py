length = {}
length[1] = 1

def main ():
	maximum = 0
	maximum_length = 0
	for x in range (1, 1000000):
		if(get_length(x) > maximum_length):
			maximum = x
			maximum_length = length[x]
	print maximum
	return maximum


def get_length(n):
	try:
		return length[n]
	except:
		if(n%2 == 0):
			length[n] = 1 + get_length(n/2)
		else:
			length[n] = 1 + get_length(3 * n + 1)
	return length [n]

main()
