## P02 - AutoComplete
### Cooper Wolf
### Description:

The program implements a stack of characters to determine if the string entered by the user is a palindrome or not. This is done by pushing every letter onto the stack and poping it off. Doing this allows you to have a string of the original word and another string of the reversed word. Then to determine if its a palidrome, attempt to set them equal to eachother. This program will ask the user for an output file to send the results to. It will then ask the user to enter in strings. The program will continue asking the user to enter in strings until the user types 'n'. When the user enters 'n' the program will print the results to the desired output file of the user and the program will terminate. The goal of this program is to create of multi file program that implements of stack.

### Files

|   #   | File             | Description                                            |
| :---: | ---------------- | --------------------------------------------------     |
|   1   |    [Main.cpp](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/main.cpp)      | Main driver of my project.                     |
|   2   |    [json.hpp](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/json.hpp)      | Cpp file for stack class.                |
|   3   |    [mygetch.hpp](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/mygetch.hpp)   | header file for stack calss.                |
|   4   |    [animals.txt](https://github.com/Coop-Wolf/3013-Algorithms/blob/main/Assignments/P02/animals.txt)   | 

### Instructions

- The program will ask the user to enter in a output file to send the results to.
- My program expects the user to input strings.
- To terminate the program, key in 'n'.

- Example Commands:
    - Would you like to enter a string?
    - Would you like to enter another string?

- Example Output:

Mom is a palindrome.
RaceCar is a palindrome.
Dog is not a palindrome.
Computer is not a palindrome.