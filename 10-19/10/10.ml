let rec sum lst = match lst with [] -> 0 | (h::t) -> h + sum t;;

let range x y = 
	let rec range_helper curr ret = 
		if (curr < x) then ret else range_helper (curr - 1) (curr::ret)
	in
	range_helper y [];;

let rec contains x lst = match lst with [] -> false | (h::t) -> if(h==x) then true else contains x t;;

let rec remove_multiples x lst = match lst with [] -> [] | (h::t) -> if (h mod x == 0 && h!=x) then (remove_multiples x t) else h::(remove_multiples x t);;

let sieve upper_bound = 
	let sq_upper = ((int_of_float (sqrt(float_of_int upper_bound))) + 1) in 
	let ret = ref (range 2 upper_bound) in
	for curr = 2 to sq_upper do
		if(contains curr (!ret)) then
			ret := (remove_multiples curr (!ret));
	done;
	(!ret);;

print_int (sum (sieve 2000000));;
print_char ('\n');;
