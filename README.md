# Number Wordle in C

A terminal-based number guessing game written in C, inspired by the popular word game Wordle. Instead of guessing a five-letter word, the player tries to guess a secret 4-digit number within a limited number of attempts. After every guess, the game gives colored feedback so the player can work out the hidden number logically.

## How to Play

The computer generates a random 4-digit secret number. You get 6 attempts to guess it. After each guess, every digit is marked:

- **Green underline**: correct digit in the correct position
- **Yellow underline**: correct digit but in the wrong position
- **Plain (no color)**: digit is not in the number

Keep guessing until all four digits turn green or your attempts run out.

## Features

- Random secret number generated on every run
- Input validation: rejects anything that is not exactly 4 digits
- Correct handling of repeated digits using a two-pass checking method
- Colored, underlined feedback using ANSI escape codes
- Configurable difficulty: change `LEN` and `MAX_ATTEMPTS` with `#define`

## Concepts Used

- Arrays and strings
- Loops (`for`, `do...while`) and conditions
- Random number generation (`rand`, `srand`, `time`)
- Character handling (`isdigit`) and string length (`strlen`)
- Symbolic constants with `#define
