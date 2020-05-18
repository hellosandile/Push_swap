# Push_swap

## The “checker” program 

The first, named checker which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.

```
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

## The “push_swap” program

The second one called push_swap which calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts integer arguments received. There’s only a few moves you’re allowed to used to manipulate the stacks that we’re going to called “Actions”. The main goal of this project is to organize Stack A in as few actions as possible.

```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

### Instruction set
For the following instructions, if the instruction is not possible, the part of it that can't be executed won't.

Code	| Instruction			| Action
--------|-----------------------|----------------------------------------------
`sa`	| swap a				| swaps the 2 top elements of stack a
`sb`	| swap b				| swaps the 2 top elements of stack b
`ss`	| swap a + swap b		| both `sa` and `sb`
`pa`	| push a				| moves the top element of stack b at the top of stack a
`pb`	| push b				| moves the top element of stack a at the top of stack b
`ra`	| rotate a				| shifts all elements of stack a from bottom to top
`rb`	| rotate b				| shifts all elements of stack b from bottom to top
`rr`	| rotate a + rotate b	| both `ra` and `rb`
`rra`	| reverse rotate a		| shifts all elements of stack a from top to bottom
`rrb`	| reverse rotate b		| shifts all elements of stack b from top to bottom
`rrr`	| reverse rotate a + reverse rotate b	| both `rra` and `rrb`

## Compile

```
run make

```

### Usage
Change "puts (1..100)...." range for desired number range
```
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
```

## Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language)) - The Programming language


## Authors

* **Sandile Mkhize** -  [@hellosandile](https://twitter.com/hellosandile)

## Acknowledgments
* Hive five to everyone at [@WeThinkCode_](https://www.wethinkcode.co.za/) who helped me where I got stuck.