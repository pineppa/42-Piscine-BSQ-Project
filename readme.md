# Title: BSQ Project! The final boss...

# Task:
The biggest square :\
<ul>
  <li>The aim of this project is to find the biggest square on a map, avoiding obstacles.<\li>
  <li>A file containing the map will be provided. It’ll have to be passed as an argument for your program.</li>
  <li>The first line of the map contains information on how to read the map :
  <ul>
    <li>The number of lines on the map;<\li>
    <li>The "empty" character;</li>
    <li>The "obstacle" character;</li>
    <li>The "full" character.</li>
  </ul></li>
  <li>The map is made up of ’"empty" characters’, lines and ’"obstacle" characters’.</li>
  <li>The aim of the program is to replace ’"empty" characters’ by ’"full" characters’ in order to represent the biggest square possible.</li>
  <li>In the case that more than one solution exists, we’ll choose to represent the square that’s closest to the top of the map, then the one that’s most to the left.</li>
  <li>The program must handle 1 to n files as parameters.</li>
</ul>

Definition of a valid map :
<ul>
  <li>All lines must have the same length.</li>
  <li>There’s at least one line of at least one box.</li>
  <li>At each end of line, there’s a line break.</li>
  <li>The characters on the map can only be those introduced in the first line.</li>
  <li>The map is invalid if a character is missing from the first line, or if two characters (of empty, full and obstacle) are identical.</li>
  <li>The characters can be any printable character, even numbers.</li>
  <li>In case of an invalid map, your program should display map error on the error output followed by a line break. Your program will then move on to the next map.</li>
<\ul>
  
C Piscine’s final Project BSQ
<ul>
  <li>When your program receives more than one map in argument, each solution or map error must be followed by a line break.</li>
  <li>Should there be no passed arguments, your program must be able to read on the standard input.</li>
  <li>You should have a valid Makefile that will compile your project. Your Makefile must not relink</li>
</ul>

# Necessary files and project subdivision
Makefile: to handle the executable creation\
|- Srcs: Files containing functions required to compile the project;\
--| main.c: Handles arguments entry, calls for argument validations and prepares the space for N calls to the solver functions;\
  |- ft_solver.c: Handles the functions to find the problem's solution;\
  |- ft_print_sol.c: Handles the reproduction of the solution map;\
  |- ft_file_check.c: Reads the input file and transforms information into a 2D matrix of int type 0 and 1\
  |- ft_file_check_util.c: Complementary file with utility functions to handle input checks\
  |- ft_reader.c: Handles the read functions for files and STDIN passed information\
|- includes: Folder with header files\
  |- ft.h: Header file containing include calls, typedef & struct and functions prototypes;\

|- test: Test maps to be used to validate the output;

## Auxiliary files:
- Makefile: compiles all the necessary files present in a folder called *srcs* and potentially of a library *ft.h* in *includes*\
-- Perl maps generator (Not added);

# Working structure
◦ main.c : Handles the requests from the user at program launch. Should handle N arguments of type file.
------------
∗ Checks for arguments to be valid;

◦ reader.c : Reads arguments and generates the 2D array
-----------
- Reads the arguments *?? one by one ??*, open the file and read the first line to know:
-- Number of lines on the map;
-- The character to be used for *EMPTY* spaces;
-- The character to be used for *OBSTACLES*;
-- The character to be used for *FULL* spaces; -> To be used to print the final solution
-- Example: 9.ox -> Lines: '9', Empty: '.', Obstacles: 'o', Full: 'x';
- Generates a 2D array map, for which each array contains the line with the read characters;

*ASSUMPTION*: It is assumed that these last 3 CHAR arguments will be passed as an array to the solver function whose prototype will be:
- void	solver(char \*\*map, char \*symbols, int rows, int cols);

◦ checker.c : Checks that the map passed via the file is correctly defined
------------
- Checks that a map is valid :  --> Return error values?
◦ All lines must have the same length.
◦ There’s at least one line of at least one box.
◦ At each end of line, there’s a line break.
◦ The characters on the map can only be those introduced in the first line.
◦ The map is invalid if a character is missing from the first line, or if two characters (of empty, full and obstacle) are identical.
◦ The characters can be any printable character, even numbers.
◦ In case of an invalid map, your program should display map error on the error output followed by a line break. Your program will then move on to the next map.

◦ solver.c: Handles the passed map, to solve the problem at hands
-------------
- Generates a matrix 2D array of the same size of map (generated with NxN spaces of int this time); *malloc*
-- Initialise the matrix with 0 and 1 based on obstacles vs empty space;
-- Call the solver algorithm: int ft_get_bsq_pos(int \*\*matrix, int size);
-- -- The algorithm substitutes all the 1 with the BSQ and should return the position of the upper left corner (the size can be retrieved via matrix\[row\]\[column\])
- Frees the generated matrix information and return; *free*

◦ printer.c: Handles the printing on screen of the solution
------------
- Not yet sure how to do this, probably it will be enough to print every line after substituting the right character in the original 2D matrix
- At the end of the printing returns (void) and frees the original 2D array.

## Solution algorithm
In order to solve this problem, consider the biggest shape that can be built.
Every area on the edges will be:
- 1 if there is an empty space;
- 0 if there is an object;

Start by allocating a 2D array, in order to store a sort of matrix map in parallel to the original one.
Add values going from the bottom right corner, either going up or left one line at the time.

Each internal square can be filled with the maximum square from that position.
The value can be simply calculated with the formula:

Val (i, j) = 1 + min(val(i, j + 1), val(i + 1, j + 1), val (i + 1, j));

Once (i, j) = (0, 0) is also filled, check the biggest value and in case of equality...
