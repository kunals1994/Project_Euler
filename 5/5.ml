let rec gcd x y = 
	if (y == 0) then 
		x
	else
		gcd y (x mod y)
	in

let lcm x y = (x*y)/(gcd x y) in

let rec lcm_list l_in = 
	match  l_in with 
		[] -> 1 |
		h::[] -> h 	|
		h1::h2::[] -> (lcm h1 h2) |
		h1::t -> (lcm h1 (lcm_list t))
in

let range x y = 
	let rec range_helper curr ret = 
		if (curr == x) then 
			curr::ret
		else
			range_helper (curr - 1) (curr::ret)
	in
	range_helper y []
in

let output_int = lcm_list (range 1 20) in 

print_int output_int;;
print_char('\n');;