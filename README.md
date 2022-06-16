## MONTY PROGRAMMING LANGUAGE

# DESCRIPTION:
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

# COMPILATION:
The code is compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`

# FUNCTIONS:
| FUNCTIONS | DESCRIPTION |
| --------- | ----------- |
| `get_func` | gets the specified function from a list of functions based on the instruction_t struct |
| `push` | pushes an element on the stack |
| `pall` | prints all the values on the stack, starting from the top |
| `pint` | prints the value at the top of the stack, followed by a new line |
| `pop` | removes the top element of the stack |
| `nop` | this function does nothing |
| `swap` | swaps the top two elements of the stack |
| `add` | adds the values of the top two elements of the stack |
| `sub` | subtracts the top element from the second top element of the stack |
| `div` | divides the second top element by the top element of the stack |
| `mul` | multiplies the top two elements of the stack |
| `*get_token` | gets the tokens of the inputed commands separated by delimiters |
| `is_number` | checks to see if the inputed string is a number |
|`free_stack` | frees the stack |

# AUTHOR:
Nwachukwu Promise Chizaram
