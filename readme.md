# BSQ Project! The final boss...

## Problem definition:

### The biggest square :

- The aim of this project is to find the biggest square on a map, avoiding obstacles.
- A file containing the map will be provided. It will have to be passed as an argument for your program.
  - The first line of the map contains information on how to read the map :
  - The number of lines on the map;
  - The ***"empty"*** character;
  - The ***"obstacle"*** character;
  - The ***"full"*** character.
- The map is made up of ***"empty"*** characters, lines and ***"obstacle"*** characters.
- The aim of the program is to replace ***"empty"*** characters by ***"full"*** character in order to represent the biggest square possible.
- In the case that more than one solution exists, we’ll choose to represent the square that’s closest to the top of the map, then the one that’s most to the left.
- The program must handle 1 to N files as parameters.

### Definition of a valid map:
- All lines must have the same length.
- There’s at least one line of at least one box.
- At each end of line, there’s a line break.
- The characters on the map can only be those introduced in the first line.
- The map is invalid if a character is missing from the first line, or if two characters (of empty, full and obstacle) are identical.
- The characters can be any printable character, even numbers.
- In case of an invalid map, your program should display map error on the error output followed by a line break. Your program will then move on to the next map.
  
### C Piscine’s final Project BSQ

- When your program receives more than one map in argument, each solution or map error must be followed by a line break.
- Should there be no passed arguments, your program must be able to read on the standard input.
- You should have a valid Makefile that will compile your project. Your Makefile must not relink

---

## Solution approach

### The naive approach
> Time - O(n<sup>4</sup>); Space - O(n<sup>2</sup>);

We could calculate the biggest possible square for each position. This would require:
- A loop through the whole square (Time: O(n<sup>2</sup>))
- In the worst case, scan the remaining positions (Time: O(n<sup>2</sup>)).

Total time: O(n<sup>4</sup>)

### A more sophisticated approach
> Time - O(n<sup>2</sup>); Space - O(n<sup>2</sup>);

We can build a solution based on the positions we have already checked:

| Map | Step #1 | Step #2 | Step #3 |
|:---:|:------:|:------:|:------:|
| 1 1 1 <br> 1 1 1 <br> 0 1 1 | x x 1 <br> x x 1 <br> 0 1 1 | x x 1 <br> x 2 1 <br> 0 1 1 | 2 2 1 <br> 1 2 1 <br> 0 1 1 |

Each position at the end of the resolution will contain the size of the biggest square possible with that position as the top left corner.

#### **Map**

Transforms the map area in:

- 0 - if there is an object;
- 1 - if there is an empty space;

This choice for 0 and 1 is functional to the resolution of the problem.

#### Step #1

Let's focus on the edges and their values. The biggest possible size of the square is either :
- 0 - If the position is occupied by an obstacle;
- 1 - If there is an empty space. Any possible square covers its own position and it is limited by the map edges;

#### Step #2 - How are we going to fill the rest of the matrix??

- Consider the more bottom right position that wasn't yet filled. Let's call this position (x, y), as its position coordinates. We have 3 possible values:

  - ***0*** - if there is an obstacle in position (x, y);
  - ***1*** - if one of the nearby positions (x, y + 1), (x + 1, y + 1), (x + 1, y) has an obstacle;
  - ***2*** - if all the nearby positions (x, y + 1), (x + 1, y + 1), (x + 1, y) are empty spaces;

With the same logic we can fill in all the positions that are 1 space away from the right edge and the bottom edge. When we move to a potential 3x3 situation for position (x, y) we should check all the following positions:

|| Col 1 | Col 2 | Col 3 |
|:-:|:-:|:-:|:-:|
| Line 1 | (x, y) | (x + 1, y) | (x + 2, y) |
| Line 2 | (x, y + 1)| (x + 1, y + 1)| (x + 2, y + 1)|
| Line 3 | (x, y + 2)| (x + 1, y + 2)| (x + 2, y + 2)|

However, in the previous 2x2 examples we checked already the positions (x, y + 1), (x + 1, y + 1), (x + 1, y). The value we assigned to each position tells us a lot about the already filled positions:
- ***A value of 0***: There is an obstacle;
- ***A value of 1***: A position in the +2 positions has an obstacle (max size possible 2);
- ***A value of 2***: All the +2 positions coverable by the checked +1 position are empty spaces.

Beware that:
- Position (x + 2, y) can only be checked by the value of (x + 1, y);
- Position (x + 2, y + 2) can only be checked by the value of (x + 1, y + 1);
- Position (x, y + 2) can only be checked by the value of (x, y + 1);

Therefore, the biggest square possible is given by the lowest of the values available in (x, y + 1), (x + 1, y + 1), (x + 1, y) and it can be simply calculated with the formula:

$$Value(x, y) = 1 + min( Value(x, y + 1), Value(x + 1, y + 1), Value (x + 1, y) )$$

Once position (0, 0) is also filled, we will now the biggest square possible for each position in the whole map. Let's check the biggest value and in case of equality, we select the on in the position nearest to the top edge (lowest y value) and in case of more than a solution we choose the most left (lowest x value).

---

# Solution implementation 
### Necessary files and project subdivision
- **[Makefile](./Makefile)**: compiles all the necessary files present in the *[srcs](./srcs/)* folder and potentially of the *[ft.h](./includes/ft.h)* library in *[includes](./includes/)*

- **[srcs](./srcs/)**: Files containing functions required to compile the project;
  - **[main.c](./srcs/main.c)**: Handles arguments entry, calls for argument validations and prepares the space for N calls to the solver functions;
  - **[ft_solver.c](./srcs/solver.c)**: Handles the functions to find the problem's solution;
  - **[ft_print_sol.c](./srcs/ft_print_sol.c)**: Handles the reproduction of the solution map;
  - **[ft_file_check.c](./srcs/ft_file_check.c)**: Reads the input file and transforms information into a 2D matrix of int type 0 and 1;
  - **[ft_file_check_util.c](./srcs/ft_file_check_util.c)**: Complementary file with utility functions to handle input checks
  - **[ft_reader.c](./srcs/ft_reader.c)**: Handles the read functions for files and STDIN passed information
- **[includes](./includes/)**: Folder with header files
  - **[ft.h](./includes/ft.h)**: Header file containing include calls, typedef & struct and functions prototypes;

### Auxiliary files:

- **[test](./test/)**: Folder with test maps to be used to validate the output;
- Perl maps generator (Not added);

---

## Detailed program structure

### [main.c](./srcs/main.c)
Handles the requests from the user at program launch. Should handle N arguments of type file.

- Handles argument parsing with 2 options:
  - ***No argument is passed***: Calls function to handle input from the Standard Input (*ft_read_stdin* in *[ft_reader.c](./srcs/ft_reader.c)*)
  - ***N arguments are passed***: Each map is converted in a string and resolved in *[ft_resolve_files.c](./srcs/main.c)*;

- ***Solver execution***:
  - Creates and initialises the necessary variables;
  - Checks the entry file (*[ft_check_file](./srcs/ft_file_check.c)*):
    - Prints *Map error* in case the map doesn't follow the rules (and returns a **NULL** pointer);
    - Generates a 2D array of integrers with N x M size and values:
      - 0 - Obstacle;
      - 1 - Empty space;
  - Finds the biggest square position (*[ft_get_bsq_pos](./srcs/ft_solver.c)*) and returns its position;
  - Prints the solution on the standard output (*[ft_print_sol](./srcs/ft_print_sol.c)*)
  - Frees the allocated memory (*[free_matrix](./srcs/main.c)*);

- ***Free used matrix***
  - Frees the allocated memory to create the 2D array of integers;

### reader.c
Reads arguments and generates the 2D array

- Reads the arguments *?? one by one ??*, open the file and read the first line to know:
  - Number of lines on the map;
  - The character to be used for *EMPTY* spaces;
  - The character to be used for *OBSTACLES*;
  - The character to be used for *FULL* spaces; -> To be used to print the final solution
  -  Example: 9.ox -> Lines: '9', Empty: '.', Obstacles: 'o', Full: 'x';
- Generates a 2D array map, for which each array contains the line with the read characters;

*ASSUMPTION*: It is assumed that these last 3 CHAR arguments will be passed as an array to the solver function whose prototype will be:
- void	solver(char \*\*map, char \*symbols, int rows, int cols);
------------
## checker.c

Checks that the map passed via the file is correctly defined

- Checks that a map is valid: --> Return error values?
- All lines must have the same length.
- There’s at least one line of at least one box.
- At each end of line, there’s a line break.
- The characters on the map can only be those introduced in the first line.
- The map is invalid if a character is missing from the first line, or if two characters (of empty, full and obstacle) are identical.
- The characters can be any printable character, even numbers.
- In case of an invalid map, your program should display map error on the error output followed by a line break. Your program will then move on to the next map.

-------------
## solver.c: 

Handles the passed map, to solve the problem at hands
- Generates a matrix 2D array of the same size of map (generated with NxN spaces of int this time); *malloc*
- Initialise the matrix with 0 and 1 based on obstacles vs empty space;
- Call the solver algorithm: int ft_get_bsq_pos(int \*\*matrix, int size);
  - The algorithm substitutes all the 1 with the BSQ and should return the position of the upper left corner (the size can be retrieved via matrix\[row\]\[column\])
- Frees the generated matrix information and return; *free*

------------
## printer.c: 
Handles the printing on screen of the solution

- Not yet sure how to do this, probably it will be enough to print every line after substituting the right character in the original 2D matrix
- At the end of the printing returns (void) and frees the original 2D array.
