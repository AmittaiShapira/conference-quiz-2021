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

- Make sure that the code can compile successfully using ```gcc -std=c89 -pedantic -Werror -Wall quiz.c``` or another compiler with similar ANSI 89 and strictest warnings as errors.

- Remove all loop statements (tip: recursion)

- What happens when ```*str``` contains more than 77 characters? How do you fix this?