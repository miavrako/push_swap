*This project has been created as part of the 42 curriculum by mirarand, miavrako*

## Description
	Push_swap is a 42 school project where the goal is to output the shortest sequence of instructions that sorts a list of integers stored in a stack, using only a restricted  set of operations and two stacks : stack A and stack B

### Available operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top of stack B onto stack A |
| `pb` | Push the top of stack A onto stack B |
| `ra` | Rotate stack A upward (first element goes to the bottom) |
| `rb` | Rotate stack B upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last element goes to the top) |
| `rrb` | Reverse rotate stack B |
| `rrr` | `rra` and `rrb` simultaneously |

## Instructions

### Requirements
	GCC or clang compiler
	GNU Make
	Unix_based OS (LInux/macOS)

### Compilation
	For the compilation of the `push_swap` project you have the following rules :

make all : produces a `push_swap` executable

make clean: remove all object files

make fclean: remove all object files and the executable

make re : recompile

### Usage
	./push_swap n n n n n n n

### Output example
	pb
	pb
	sa
	rra
	...

## Resources
	42 `push_swap` subject
	Visualizer for `push_swap`




