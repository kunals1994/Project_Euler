def main():
	sm = 0
	for x in range (1,1001):
		sm += len_num(x)
	print sm


lengths = {}
# 
lengths[0] = 0
lengths[1] = len("one")
lengths[2] = len("two")
lengths[3] = len("three")
lengths[4] = len("four")
lengths[5] = len("five")
lengths[6] = len("six")
lengths[7] = len("seven")
lengths[8] = len("eight")
lengths[9] = len("nine")
lengths[10] = len("ten")
lengths[11] = len("eleven")
lengths[12] = len("twelve")
lengths[13] = len("thirteen")
lengths[14] = len("fourteen")
lengths[15] = len("fifteen")
lengths[16] = len("sixteen")
lengths[17] = len("seventeen")
lengths[18] = len("eighteen")
lengths[19] = len("nineteen")
lengths[20] = len("twenty")
lengths[30] = len("thirty")
lengths[40] = len("forty")
lengths[50] = len("fifty")
lengths[60] = len("sixty")
lengths[70] = len("seventy")
lengths[80] = len("eighty")
lengths[90] = len("ninety")


# Only works for numbers in the range [1,9999]
def len_num(n):
	try:
		return lengths[n]
	except:
		if (n >= 1000):
			if ((100 * (n / 100)) == n):
				lengths [n] = len_num(n/100) + len("thousand")
			else:
				lengths[n] = len_num(100 * (n/100))  + len_num(n - 100 * (n/100))

		elif (n >= 100):
			if ((100 * (n / 100)) == n):
				lengths [n] = len_num(n/100) + len("hundred")
			else:
				lengths[n] = len_num(100 * (n/100)) + len("and") + len_num(n - 100 * (n/100))

		else:
			lengths[n] = len_num(10 * (n/10)) + len_num(n - 10 * (n/10))
		return lengths[n]

main()