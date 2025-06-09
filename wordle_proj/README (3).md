# Wordle (C++ Remake)

A terminal-based implementation of the popular Wordle game where players have 6 attempts to guess a random 5-letter word.

## Features

- **Random Word Generation**: A random 5-letter word is selected from a predefined list.
- **Color-coded Feedback**:
  - **Green** for correct letters in the correct position.
  - **Yellow** for correct letters but in the wrong position.
  - **Gray** for incorrect letters.
- **Grid Layout**: Each guess is displayed in a formatted grid with dashed lines.
- **Input Validation**: Ensures only valid 5-letter English words are accepted.

## How to Compile

1. Open a terminal and navigate to the directory with `wordle.cpp` and `valid-wordle-words.txt`.
2. Compile using:
    ```bash
    g++ -std=c++11 wordle.cpp -o wordle
    ```
3. Run the program:
    ```bash
    ./wordle
    ```

## How to Play

1. You have **6 attempts** to guess the correct 5-letter word.
2. After each guess:
   - Letters in the correct position will be **green**.
   - Letters in the wrong position will be **yellow**.
   - Incorrect letters will be **gray**.
3. Keep guessing until you find the word or run out of attempts. If unsuccessful, the game will reveal the correct word.

## Example
<img width="405" alt="Screenshot 2024-09-18 at 4 16 55 PM" src="https://github.com/user-attachments/assets/8d5fa0bd-c142-4b8d-86ca-5ea4cb562bf7">
<img width="454" alt="Screenshot 2024-09-18 at 4 17 13 PM" src="https://github.com/user-attachments/assets/3f8c7de0-fab8-42eb-ae68-7012f6c8542a">
<img width="502" alt="Screenshot 2024-09-18 at 4 17 02 PM" src="https://github.com/user-attachments/assets/45748605-4a0c-4d7c-9588-0d92ff2c888e">


