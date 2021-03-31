# Conference Quiz 2021

## Quiz

[quiz.c](./quiz.c) can be used with the solutions to the crossword puzzle to get the solution phrase.

Just replace the numbers, ```[n]```, in the ```str``` variable in the code with the letter in the numbered box on the puzzle.

Example box number 3 on puzzle contains the letter "L"...

```char *str = "HE[3]LO";```

...changes to....

```char *str = "HE[3]LO";```

## Bonus Points

- Add unit tests to demonstrate that the decoder works

- Make sure that the code can compile successfully using ```gcc -std=c89 -pedantic -Werror -Wall -Wextra quiz.c``` or another compiler with similar ANSI 89 and strictest warnings as errors. *Note* take care on MacOS that you are using real gcc (not gcc mapped to clang).

- Remove all loop statements (tip: recursion)

- There is a defect in this code which makes the solution sometimes print additional characters. What is the cause? What is the fix? (tip: use a memory debugger and/or read C compiler standards and/or use static analysis)
