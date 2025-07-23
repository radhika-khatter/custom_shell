# 🐚 Custom Shell in C++

This is a simple command-line shell implemented in C++ for Linux environments (e.g., Ubuntu via WSL). It supports basic command execution, including built-in support for `cd`, and handles system commands using `fork()` and `execvp()`.

---

## 📁 Features

- Custom shell prompt (`$ >>`)
- Command parsing using `getline` and `istringstream`
- Built-in `cd` command handled without creating a child process
- System command execution using `fork()` and `execvp()`
- Graceful `exit` command to terminate the shell

---

## 🚀 Getting Started

### Requirements

- Linux environment (or WSL on Windows)
- g++ compiler

### Compile

```bash
g++ shell.cpp -o shell
