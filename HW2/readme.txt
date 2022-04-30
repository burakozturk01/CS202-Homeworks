Burak Ozturk
21901841
Homework 2

I had to add "-std=gnu++0x" to the compilation command. I used "g++ *.cpp -o hw2.exe -std=gnu++0x" on dijkstra to compile my code. There is a Makefile that I tested on dijkstra in the zip as well.

addNgram function has two important prerequisites when used outside the generateTree function. I included them in the source code as comments as well:
 - All strings added with addNgram function directly must consist of only letters, not spaces.
 - All strings added with addNgram function must have the same length with the ones BST currently holding.

generateTree function has two important prerequisites when used outside the generateTree function. I stated them in the source code as comments as well:
 - Input file must start and end with letters, not space characters.
 - There can't be more than one consecutive space characters.