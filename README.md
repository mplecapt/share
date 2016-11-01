# share

c.bash (the .bash is implied) is a bash script which will compile c-99 code into a temporary file and run the code, making it much easier to test and debug code.

1. Download the file onto your system, preferably in the same directory as the c code, but not necessarily.
2. Give the c script permission by running the following command from the same directory:
  ~# chmod 755 c
3. To run test.c:
  ~# ./c test arg1 arg2 .........
      (test is the name of the file without the .c extension)
      (list any/all arguments after as if you were running ./test)
      
Keep in mind you may need to add flags to gcc that were not already included in the script.

Output from the script displays in red.
It will also clear your terminal before running. If you do not want this then just remove the clear command from the script.
