# push_swap

An algorithmic sorting project from School 21: sort integers using two stacks and a deliberately limited instruction set.

The goal is not only to produce the correct order, but to minimize the number of operations. This implementation received **125/125**, including the bonus checker.

## Allowed operations

| Group | Operations |
| --- | --- |
| Swap | `sa`, `sb`, `ss` |
| Push | `pa`, `pb` |
| Rotate | `ra`, `rb`, `rr` |
| Reverse rotate | `rra`, `rrb`, `rrr` |

## Build

```bash
make
make bonus
```

## Usage

```bash
./push_swap 4 2 1 3
```

The program prints the operation sequence to standard output. Validate it with the checker:

```bash
ARG="4 2 1 3"
./push_swap $ARG | ./checker_Mac $ARG
```

## Implementation notes

- input validation rejects duplicates, malformed values, and integer overflow;
- small inputs use dedicated short paths;
- larger inputs are organized around stack operations and move reduction;
- the bonus checker executes an instruction stream and validates the final state.

## Project status

Learning project preserved as part of my School 21 portfolio. Thanks to [KankurovFarkhad](https://github.com/KankurovFarkhad) for help with the checker.
