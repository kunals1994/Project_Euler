
let num_digits = 3;;

(* Reverses digits of of the inputted number*)
let reverse_digits n = 
	let rec reverse_digits_helper inp out = 
		if (inp == 0) then
			out
		else
			reverse_digits_helper (inp/10) (out * 10 + (inp mod 10))
	in
	reverse_digits_helper n 0
in

(*
 *	Generates potential palindromes in descending order, and checks if fun_in returns true, returning the value of the highest palindrome that does. 
*)
let perform_on_potential_palindromes func_in num_digits = 
	let rec find_palindrome_helper curr = 
		(*Printf.printf "%f\n" curr; *)
		if(curr < 10.0**(float_of_int (num_digits - 1))) then
			(0-1)
		else
			let potential = (int_of_float curr) * int_of_float (10.0**(float_of_int num_digits)) + (reverse_digits (int_of_float curr)) in 
			if ((func_in potential num_digits)) then
				potential
			else
				find_palindrome_helper (float_of_int((int_of_float curr) - 1))
	in 
	let rec find_palindrome_helper_shorter curr = 
		if(curr < 10.0**(float_of_int (num_digits - 1))) then
			(0-1)
		else
			let potential = (int_of_float curr) * int_of_float (10.0**(float_of_int(num_digits - 1))) + (reverse_digits ( (int_of_float(curr) / 10))) in 
			if (func_in potential num_digits) then
				potential
			else
				find_palindrome_helper_shorter (float_of_int ( (int_of_float curr) - 1))
	in
	let highest_running = find_palindrome_helper (float_of_int ( (int_of_float(10.0**(float_of_int num_digits)) - 1))) in
	if (highest_running >= 0 ) then
		highest_running
	else
		find_palindrome_helper_shorter (float_of_int ( (int_of_float(10.0**(float_of_int num_digits)) - 1)))

in
(*
 * Checks if there are 2 multiples of x with n digits
*)
let divisible_by_n_digits x n = 
	let rec check_divisibility_helper possibility = 
		if (possibility < 10.0**(float_of_int(n - 1))) then 
			false
		else
			let temp = x/(int_of_float possibility) in
			if( (temp * (int_of_float possibility) == x) &&  temp > (int_of_float(10.0**(float_of_int(n - 1)))) && (float_of_int temp) < 10.0**(float_of_int n)) then
				true
			else
				check_divisibility_helper (float_of_int ((int_of_float possibility) - 1))
	in
	check_divisibility_helper (float_of_int ( (int_of_float (10.0** (float_of_int n))) - 1))
in

(* The main function *)
let main n = (perform_on_potential_palindromes divisible_by_n_digits n) in

print_int (main num_digits);;
print_char '\n';;

