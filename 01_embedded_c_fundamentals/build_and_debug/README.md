# 05 - Build and Debug (Embedded C Fundamentals)

## 🎯 Objective

Understand how C programs are built, linked, and debugged without relying on an IDE.

This section focuses on:

- GCC compilation process
- Makefile basics
- Object files and linking
- ELF file structure
- Memory sections (.text, .data, .bss)
- Basic debugging using GDB

---

## 🧱 Concepts Covered

### 1️⃣ GCC Build Stages

Compilation process:

1. Preprocessing  → `.i`
2. Compilation    → `.s`
3. Assembly       → `.o`
4. Linking        → `.elf`

Example:

```bash
gcc -c file.c -o file.o
gcc file.o -o main  
