let lower_range = 1;;
let upper_range = 20;;

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

let main = lcm_list (range lower_range upper_range) in 

print_int main;;
print_char('\n');;