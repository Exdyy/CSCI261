First, refactor the code to place function prototypes in a separate header file named calculator_functions.h.
Then, place the corresponding function definitinos in a separate source file named calculator_functions.cpp.
Finally, modify your Makefile to build the calculator_functions.cpp source file.

Build your program.

Run the executable through the debugger.  Perform the following steps.  For each step, add the command that performs that task.

1a. Add a breakpoint inside the print_result() function.

b print_result

1b. What different in how we need to specify the breakpoint compared to L2D?

We have to tell gdb to add the breakpoint when the function is called, since  we cannot specify a certain line because the function definition is in a separate file.

Alternatively, you can add the breakpoint inside the function file by inputting the following:
b calculator_functions.cpp:15

2. Run the program, requesting to add 4 and 5

run
4
5


3a. Print the stack trace

bt


3b. What's different in how the stack trace is formed compared to L2D?

The stack trace is showing the calls to the calculator_functions.cpp file because that is where the print_result and turn_calculator_on functions are defined.

4. Print the current stack frame

frame

5. Print all local variables and arguments within the scope of the current stack frame

info local
info args

6. Move up one level in the stack frame

up

7. Print all local variables and arguments within the scope of the current stack frame

info local
info args

8. Continue the program, requesting to subtract the values

continue

9. Print the stack trace again

bt

10. Step through the program until we have moved out of the two lower stack frames

finish

11. Print the stack trace again

bt

12. Kill the program

kill
y