# Data-Structures-and-Algorithms
Sample implementations of data structures and algorithms in any programming language.

# Implementation
- Every single data structures or algorithms are implemented in a separate directory.
- We can run any of the implemented algorithms using the program run.py.

# How to do a proper implementation
- Implement the algorithm in a separate directory.
- Using Makefile is optional.
- There must be a shell script named 'run.sh' which contains commands to build and execute the algorithm. However it is
  done is the implementor's concern, but it should successfully execute the code. See 'run.sh' of the directory
  'Singly Linked List' to have a taste of it.
- Next step is to enter the exact name of the directory which contains the algorithm in the file 'ROOT/Register' in a
  separate line. Otherwise, 'run.py' will fail to detect your implementation.
- Run 'run.py'.
- If all OK, then the algorithm will run as expected.
