#load "nums.cma"
open Big_int


(*Ocaml Brute Force Solution*)

(* Declare some big int objects *)

let num_input = (big_int_of_int 100);;

let one  = (big_int_of_int 1) ;;
let ten  = (big_int_of_int 10);;
let zero = (big_int_of_int 0) ;;

let rec digit_sum x = 
	(*
	if(x==1) then 1
	else if (x % 10 == 0) then (digit_sum x/10)
	else digit_sum (x - 1) + 1
	*)
	if (eq_big_int x one) then one
	else if(eq_big_int (mod_big_int x ten) zero) then (digit_sum (div_big_int x ten))
	else (add_big_int (digit_sum(sub_big_int x one)) one);;

let rec factorial x = 
	(*
	if(x == 1) then 1
	else (x * factorial(x - 1))
	*)
	if (eq_big_int x one) then one
	else (mult_big_int x (factorial(sub_big_int x one)));;

let solution = digit_sum(factorial num_input);;

(* Crunch solution and display *)
print_string (string_of_big_int solution);;
print_char '\n';;
