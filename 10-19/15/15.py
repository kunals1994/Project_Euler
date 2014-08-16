lengths = {}
lattice_size = 20

lengths[lattice_size,lattice_size] = 1

def main():
	print get_length(0,0)

def get_length (x, y):
	try:
		return lengths[x,y]
	except:
		if(x == lattice_size):
			lengths[x,y] = get_length(x, y+1)
		elif (y == lattice_size):
			lengths[x,y] = get_length(x+1, y)
		else:
			lengths[x,y] = get_length(x+1, y) + get_length(x, y+1)

		return lengths[x,y]

main()

