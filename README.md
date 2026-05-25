# ⌨️ Typer – my first C++ project

### Description

**Typer** is a simple terminal-based typing practice tool written in C++.

It displays a line of text; you need to retype it exactly. The program:
- Shows the text centered in the terminal.
- Highlights correct letters and mistakes.
- Calculates **WPM** (words per minute) and **accuracy** after finishing.
- Exits by pressing `q` or when the entire text is typed.

> ⚠️ This is my **first C++ project**, written for learning purposes. Some parts are rough, and there are known limitations (see below).

### Build & Run

```bash
# Compile
clang++ -o typer main.cpp tui/Window.cpp
mkdir -p ~/.config/typer/
cp dict.txt ~/.config/typer/
# Run
./typer

