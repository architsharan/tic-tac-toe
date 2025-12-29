# Tic-Tac-Toe C++ Game

A **console-based Tic-Tac-Toe game** in C++ with colored output, interactive menu, and customizable player names.  

---

## 🎮 Features

- Two-player gameplay
- Interactive menu with options:
  - Start Game
  - Play Again
  - Set Player Names
  - Show Rules
  - Exit
- Colored board display for X (Red) and O (Green)
- Input validation for invalid or occupied cells
- Detects winner or draw
- Replay functionality
- Clear screen and formatted console output

---

## 💻 Tech Stack

- **Language:** C++
- **Libraries:** `<iostream>`, `<cstdlib>`
- **Platform:** Console (Windows/Linux)

---

## ⚡ How to Run

1. Clone the repository:
```bash
git clone https://github.com/architsharan/tic-tac-toe.git
```

2. Navigate to the project folder:
```bash
cd tic-tac-toe/Projects
```

3. Compile the code:
```bash
g++ tic-tac-toe.cpp -o tic-tac-toe.exe
```

4. Run the executable:
```bash
./tic-tac-toe.exe  # Linux/Mac
tic-tac-toe.exe    # Windows
```

---

## 📜 Game Rules

- Two players: Player 1 (X) and Player 2 (O).
- Players take turns entering a number 1-9 to place their symbol.
- First player to align three symbols horizontally, vertically, or diagonally wins.
- If all cells are filled with no winner, the game ends in a draw.
- Cannot place a symbol in an already occupied cell.

---

## 📝 Code Sample
```cpp
// Function to print board symbols in color
string color(char x) {
    if (x == 'X') return string(RED) + x + RESET;
    if (x == 'O') return string(GREEN) + x + RESET;
    return string(WHITE) + x + RESET;
}
```

*(Full code is in tic-tac-toe.cpp)*

---

## 👨‍💻 Author

**Archit Sharan**  
- [GitHub](https://github.com/architsharan)  
- [LinkedIn](https://www.linkedin.com/in/architsharan)  
---

## ⭐ “Constantly learning. Always building.”
