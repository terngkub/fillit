# fillit
A program to find the smallest square that can contain all of the input tetriminos.

### About this project
* This is a group project at [École 42](https://42.fr). My teammate is [fxbabin](https://github.com/fxbabin).
* The objective of this project is to find the smallest square that can contain all of the input tetriminos.
* A tetrimino piece has 4 blocks as shown in the example below (#).
```
##..
.#..
.#..
....
```
* Below is the example of the input and the output
```
$> cat sample.fillit | cat -e
....$
##..$
.#..$
.#..$
$
....$
####$
....$
....$
$
#...$
###.$
....$
....$
$
....$
##..$
.##.$
....$
$> ./fillit sample.fillit | cat -e
DDAA$
CDDA$
CCCA$
BBBB$
```
* The valid tetrimino should have
	* 4 blocks (#) ajacented to each other
	* 12 dots (.) as a blank space
	* 4 characters in each line and the newline character at the end.
* If there is more than one tetriminos, each one should be separated by a newline character.
* If the input isn't valid the program will display "error\n"
```
$> cat sample.fillit | cat -e
....$
....$
####$
....$
$
....$
...$
..##$
..##$
$> ./fillit sample.fillit | cat -e
error$
```

### How to run the program
* First, run make command to create the executable file.
```
make
```
* Then, run the program with an input.
```
./fillit [input_file]
```

### The idea behind the program
We use recursive backtracking to solve this problem. Starting from a very big map, the code will try to put all the pieces into the map. If it can do that, it reduce the map size and try again and again until it fail. Then, print out the last map solution.
