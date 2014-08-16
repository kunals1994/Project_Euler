def main():
	print sum_digits(1<<1000)

def sum_digits(n):
	sm = 0
	for char in str(n):
		sm += int(char)
	return sm

main()
