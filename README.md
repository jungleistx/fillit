# fillit

First pair-project of Hive Helsinki <br>
The program tries to find the smallest possible square to fit pieces given as a file. <br> 
If multiple possible solutions, the program tries to fit the pieces in order starting from the upperleft corner. <br>
My partner in this project: jhaukile.

## Valid pieces (typical tetris pieces)
Pieces can be anywhere in the 4x4 grid. The grid can hold only 1 piece. <br>
The empty spaces are represented as '.' and part of the piece as '#'.
```
##..  ####  #...  ##..  ##..  ###.  ###.  #...  ...#  #...  ..#.  ##..  .##.  ##..  ##..  #...  .#..  ###.  .#..
##..  ....  #...  #...  .#..  #...  ..#.  #...  ...#  ###.  ###.  .##.  ##..  .#..  #...  ##..  ##..  .#..  ###.
....  ....  #...  #...  .#..  ....  ....  ##..  ..##  ....  ....  ....  ....  .#..  #...  #...  .#..  ....  ....
....  ....  #...  ....  ....  ....  ....  ....  ....  ....  ....  ....  ....  ....  ....  ....  ....  ....  ....
```
## Few invalid pieces
```
####  ##..  ##.   AAAA  ....
....  .###  ##... ....  ....
....  ....  ....  ....  ....
####  ....  ....  ....  ....
```
## Input (file)
The file must have valid pieces anywhere between 1 and 26. <br>
The pieces must be separated by an empty line, and the file must have a trailing empty line. <br>

Examples of a valid input file:
``` 
....  ....  ....
..##  ....  ....
..#.  ####  ####
..#.  ....  ....

##..        #...  
##..        #...
....        #...
....        #...

            ....
            ....
            ....
            ####
``` 
Output of those file:
```
AA.   AAAA  AAAAB
ABB   ....  C...B
ABB   ....  C...B
      ....  C...B
            C....
``` 

## Instructions
1.  make
2.  ./fillit [file]

Note: adding testfiles later.
