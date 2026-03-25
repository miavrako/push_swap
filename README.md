*This project has been created as part of the 42 curriculum by mirarand, miavrako.*

---

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to output the shortest possible sequence of instructions that sorts a list of integers using only two stacks — **stack A** (which holds the initial input) and **stack B** (initially empty) — and a restricted set of eleven operations.

The challenge is not merely to sort, but to do so in as few operations as possible. The project therefore requires selecting and implementing efficient sorting strategies adapted to the size and disorder level of the input.

### Available Operations

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

---

## Instructions

### Requirements

- GCC or Clang compiler
- GNU Make
- Unix-based OS (Linux or macOS)

### Compilation

```bash
# Build the push_swap executable
make

# Build the bonus checker binary
make bonus

# Remove object files
make clean

# Remove object files and binaries
make fclean

# Recompile from scratch
make re
```

### Usage

```bash
# Pass numbers as separate arguments
./push_swap 4 2 7 1 9

# Pass numbers as a single quoted string
./push_swap "4 2 7 1 9"
```

The program outputs one operation per line to stdout. If the input is already sorted, nothing is printed.

### Bonus checker

The `checker` binary reads a list of operations from stdin and verifies whether they correctly sort the given input, printing `OK` or `KO`.

```bash
./push_swap 4 2 7 1 9 | ./checker 4 2 7 1 9
```

### Optional flags

| Flag | Description |
|------|-------------|
| `--simple` | Forces the simple insertion sort strategy |
| `--medium` | Forces the chunk sort strategy |
| `--complex` | Forces the radix sort strategy |
| `--adaptive` | Auto-selects the best strategy (default behavior) |
| `--bench` | Prints benchmark statistics after sorting |

```bash
# Example: force radix sort and display benchmark
./push_swap --complex --bench 9 3 6 1 8 2 7 4 5
```

### Benchmark output example

```
[bench] disorder: 72.34%
[bench] strategy: Adaptive / O(n log n)
[bench] total_ops: 814
[bench] sa: 0 sb: 0 ss: 0 pa: 250 pb: 250
[bench] ra: 134 rb: 87 rr: 0 rra: 52 rrb: 41 rrr: 0
```

---

## Algorithms

This project implements three distinct sorting strategies plus an adaptive dispatcher that selects among them at runtime. The choice of algorithm depends on the size of the input and its disorder level.

### Disorder metric

Before selecting a strategy, the program computes a **disorder metric**: the percentage of inversions in the stack relative to the theoretical maximum. An inversion is a pair (i, j) where i appears before j in the stack but i > j.

```
disorder = (number of inversions) / (n * (n - 1) / 2) * 100
```

This gives a value between 0% (already sorted) and 100% (reverse sorted), and guides the adaptive strategy.

---

### Simple — Insertion sort (`--simple`)

**Principle:** Repeatedly find the minimum element in stack A, rotate it to the top, then push it to stack B. Once only three elements remain in A, sort them with `sort_three`. Finally, push everything back from B to A in order.

**Complexity:** O(n²) rotations in the worst case, since finding and reaching the minimum requires up to n/2 rotations per element.

**Justification:** This strategy is easy to reason about and performs well on small or nearly-sorted inputs where few rotations are needed to reach each minimum. It becomes expensive as n grows, making it best suited for n ≤ ~20 or disorder < 20%.

---

### Medium — Chunk sort (`--medium`)

**Principle:** Assign a rank index to each element (0 to n−1). Divide the ranks into chunks of fixed size (15 for n ≤ 100, 30 for n > 100). In each pass over stack A, push elements whose rank falls within the current chunk window to B, using `rb` to keep larger-ranked elements near the top of B. Once all elements are in B, repeatedly pull the maximum back to A.

**Complexity:** O(n√n) — the chunk size is tuned to minimize the number of passes and rotations. With k chunks of size √n, each pass costs O(n) rotations over A, and retrieving from B costs O(√n) per element.

**Justification:** Chunk sort strikes a balance between the simplicity of insertion sort and the rigidity of radix sort. It adapts naturally to varying input sizes by adjusting chunk width, and performs well across the 100–500 element range targeted by 42 grading criteria.

---

### Complex — Radix sort (LSD) (`--complex`)

**Principle:** Assign a rank index (0 to n−1) to each element. Sort by bits from least significant to most significant. For each bit, scan all elements in A: if the current bit is 0, push to B; if 1, rotate to the bottom of A. After processing all n elements, push everything back from B to A. Repeat for each bit until all bits of the maximum index have been processed.

**Complexity:** O(n log n) — the number of passes equals ⌈log₂(n)⌉, and each pass visits all n elements.

**Justification:** Radix sort is the most operation-efficient strategy for large, highly disordered inputs. It does not depend on comparisons and the number of passes grows only logarithmically with n. The trade-off is that it requires index normalization upfront and can be suboptimal for nearly-sorted inputs where a simpler strategy would terminate early.

---

### Adaptive — Auto-selection (`--adaptive`, default)

**Principle:** Dispatch to one of the three strategies above based on input size and disorder:

| Condition | Strategy selected |
|-----------|------------------|
| n ≤ 5 | Dedicated small-sort (`sort_two`, `sort_three`, `sort_five`) |
| disorder < 20% | Simple (insertion sort) |
| 20% ≤ disorder < 50% | Medium (chunk sort) |
| disorder ≥ 50% | Complex (radix sort) |

**Justification:** No single algorithm dominates across all input profiles. A nearly-sorted array of 500 elements is handled far more efficiently by insertion sort (few rotations needed) than by radix sort (which runs all passes regardless). Conversely, a fully reversed input of 500 elements makes insertion sort collapse into O(n²) rotations. The adaptive dispatcher selects the appropriate trade-off at runtime, making the program competitive across all 42 grading test cases.

---

### Small-sort routines

For inputs of 2, 3, or 5 elements, hardcoded optimal sequences are used directly, avoiding the overhead of any general algorithm:

- **`sort_two`**: at most 1 `sa`.
- **`sort_three`**: at most 2 operations, using a case table on the (top, mid, bot) ordering.
- **`sort_five`**: push the two smallest to B with optimal rotations, sort the remaining 3 with `sort_three`, then push back.

---

## Contributions

### mirarand

Core architect of the project. Responsible for the foundational infrastructure, sorting algorithms, and the bonus checker.

**Stack operations**
- `ft_push.c` — `pa` / `pb`: push between stacks
- `ft_rotate.c` — `ra` / `rb` / `rr`: rotate operations
- `ft_rrotate.c` — `rra` / `rrb` / `rrr`: reverse rotate operations
- `ft_swap.c` — `sa` / `sb` / `ss`: swap operations

**Stack management**
- `stack_utils.c` — Size, sort check, min-index search, index assignment
- `stack_init.c` — Node creation, `push_back`, `stack_copy`
- `tiny_sort.c` — Optimized sort for 2, 3 and 5 elements

**Sorting algorithms** *(initial implementation)*
- `algo_adaptive.c` — Auto-selects strategy based on disorder metric
- `algo_complex.c` — Radix sort (LSD) using bit manipulation
- `algo_medium.c` — Chunk-based sort with index ranking
- `disorder_metric.c` — Computes percentage of inversions in the stack

**Entry point & argument handling**
- `push_swap.c` — `main`, argument parsing, split detection, sort dispatch
- `push_swap_utils.c` — Algorithm flag parsing and dispatch (`algo_flag`)

**Bonus checker**
- `checker_bonus.c` — Checker entry point: validates input and prints `OK`/`KO`
- `apply_ops_bonus.c` — Applies `sa`, `sb`, `ss`, `pa`, `pb` from stdin
- `apply_rotate_bonus.c` — Applies `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr` from stdin
- `hide_ops_bonus.c` — Silent stack operations (no operation logging)
- `read_apply_bonus.c` — Reads instruction lines from stdin and dispatches them
- `count_operations.c` — Counts each operation type for the bench report

**Utility functions**
- `ft_split.c` — String split by delimiter
- `ft_strcmp.c` — String comparison
- `ft_utils.c` — `ft_putstr_fd`, `ft_memset`
- `ft_lstclear.c` *(initial)* — Clears and frees the operation linked list

**Headers**
- `push_swap.h` — All structs (`t_stack`, `t_operation`, `t_bench`, `t_program`, `t_run`) and function prototypes
- `push_swap_bonus.h` — Bonus-specific prototypes

---

### miavrako

Responsible for the sorting algorithms, benchmark system, error handling, memory management, and collaborative refinement across the codebase.

**Sorting algorithms**
- `algo_simple.c` — Insertion sort: pushes minimum to B one by one, then restores
- `algo_medium.c` *(final)* — Chunk sort refinements and edge cases
- `algo_complex.c` *(final)* — Radix sort integration and edge cases
- `algo_adaptive.c` *(final)* — Adaptive strategy selection

**Benchmark & reporting**
- `bench_utils.c` — Benchmark initialization, strategy resolution, complexity estimation
- `print_bench.c` — Full benchmark display: disorder metric, strategy, complexity, per-operation counts
- `print_operation.c` — Prints the final operation list to stdout
- `add_operation.c` — Appends an operation string to the linked list
- `count_operations.c` *(final)* — Rotation and reverse-rotation counters

**Error handling & validation**
- `ft_error.c` — `print_error`, integer validation, duplicate check, `stack_a_valid`
- `check_args.c` — Validates that argument array is non-empty
- `check_flag.c` — Validates that `--` flags are recognized

**Memory management**
- `ft_free_stack.c` — Frees all nodes of a stack
- `ft_lstclear.c` *(final)* — Clears and frees the operation linked list
- `ft_atol.c` — Safe string-to-long conversion

**Bonus checker**
- `checker_bonus.c` *(final)* — Input validation and checker output

**Collaborative updates**
- `tiny_sort.c` — Refinements to small-sort logic
- `stack_init.c` — Improvements to stack initialization
- `push_swap.c` — Integration of bench run into the main sort flow
- `push_swap.h` — Struct extensions and prototype additions
- `ft_split.c` — Edge case handling
- `ft_utils.c` — Utility additions
- `disorder_metric.c` *(final)* — Final tuning of the disorder formula

---

## Resources

### Documentation & references

- [42 push_swap subject (PDF)](https://cdn.intra.42.fr/pdf/pdf/136456/en.subject.pdf)
- [push_swap visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Inversions in discrete mathematics — Wikipedia](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))

### Use of AI

AI (Claude by Anthropic) was used during this project for the following tasks:

- **Debugging:** Identifying edge cases in `sort_three` and in the `check_args` / `check_flag` validation pipeline.
- **Benchmarking design:** Helping design the structure of the `t_bench` struct and the logic for resolving strategy labels and complexity strings in `bench_utils.c`.
- **README writing:** Drafting and iterating on this document, in particular the algorithm explanation and justification section.
- **Code review:** Reviewing memory management across `ft_free_stack.c`, `ft_lstclear.c`, and the bonus checker to identify potential leaks.
