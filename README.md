# C++ OOP — Examples & Exercises

![The four pillars of OOP: classes, objects, encapsulation, inheritance, polymorphism](images/oop-pillars-overview.jpeg)

A structured set of C++ object-oriented programming exercises, organized by topic. Each
numbered lesson folder contains worked **examples** you can read/run and a **homework** set
for students to complete. Written for a mixed audience — complete beginners through
experienced engineers brushing up on C++ specifics.

## Philosophy

**OOP is not something you memorize. It is something you deeply understand and learn to build with.**

This is a **complete theoretical and practical guide to Object-Oriented Programming** designed to take you from the basics to a deep, practical mastery of OOP — something most resources fail to provide.

Start from the fundamentals. Understand **why OOP exists, how its concepts actually work, and how to apply them in real software**. Then reinforce that understanding through practical implementations and increasingly complex problems.

### Why OOP?

OOP has a reputation for being difficult — not only for beginners, but even for experienced developers.

Many experienced developers jump straight into **Design Patterns** and **SOLID principles** without first developing a deep understanding of OOP itself. That often turns into memorizing rules instead of understanding the ideas behind them.

**Master OOP first, and Design Patterns and SOLID become much easier to understand.**

### OOP Is the Gateway to Real Projects

You can learn syntax without mastering OOP.

But sooner or later, serious software projects demand it.

**Backend. Frontend. Mobile. Game development. ML/AI. Large-scale systems.**

The tools and frameworks change. **The fundamental concepts don't.**

> **Don't just learn how to use OOP. Understand it deeply enough to design with it.**

**Learn the theory. Build the concepts. Practice the patterns. Master OOP.**

## Structure

```
1-CLASSES-OBJECTS-AND-DATA-STRUCTURES/   classes, objects, and 4 data structures (linked list, stack, queue, BST)
2-INHERITANCE/                           base/derived classes, access control, constructors & destructors
3-POLYMORPHISM/                          virtual functions, abstract classes, static/dynamic binding
```

Every lesson follows the exact same layout. Here's what it looks like for real, using
`2-INHERITANCE/` as a concrete example:

```
2-INHERITANCE/
├── README.md
│     ↳ start here — topic list for this lesson, plus an overview diagram
├── images/
│   └── inheritance-types-overview.jpg
│         ↳ diagrams shown at the top of README.md (not every lesson has these)
├── examples/
│   ├── 01-introduction-to-inheritance/
│   │   └── main.cpp
│   ├── 02-protected-members/
│   │   └── main.cpp
│   └── ...
│         ↳ read these next, in numeric order — one folder per topic,
│           worked code you can run as-is
├── homework/
│   ├── homework-01-protected-members.cpp
│   ├── homework-02-library-management-system.cpp
│   └── ...
│         ↳ then solve these, one at a time, in order — no solutions provided
└── playground.cpp
      ↳ a free scratch file for experimenting — overwrite it locally, it's not graded
```

`1-CLASSES-OBJECTS-AND-DATA-STRUCTURES/` and `3-POLYMORPHISM/` mirror this exact structure,
just with different topics inside. Quick reference:

| Folder / file | What's in it | What you do with it |
|---|---|---|
| `README.md` | The lesson's topic list, and a diagram if one exists | Read first |
| `images/` | Diagrams referenced by `README.md` | Nothing — just context |
| `examples/NN-topic/main.cpp` | Instructor-provided code, one concept per folder, in teaching order | Read it, run it, then move to homework |
| `homework/homework-NN-*.cpp` | Exercises with no solutions given | Solve one at a time, in order |
| `playground.cpp` | A free scratch file, not part of the curriculum | Overwrite freely while experimenting |

## Setup and Requirements

### What is Git?

Git is a version-control system — a time machine for your code. It lets you:

- Commit snapshots of your work.
- Revert to any earlier state.
- Experiment safely on branches.

### What is GitHub?

GitHub hosts Git repositories in the cloud and adds collaboration tools:

- Private/public storage for your code.
- Pull requests and code review.
- Issue tracking and an online portfolio.

### What is a fork?

A fork is your own personal copy of someone else's repository, created on GitHub with one click.
It lives under your own account and is completely independent — you can edit, commit, and push
to it freely without touching the original.

**Why fork?** You don't have write access to this repo. Forking gives you a copy you fully own,
so you have somewhere to save your homework solutions as commits.

### What is a clone?

Cloning downloads a copy of a repository from GitHub onto your own computer, so you have real
files on disk you can open in an editor, compile, and run.

**Why clone?** A fork only exists on GitHub's servers. You need a local copy to actually write
and test code — cloning creates that local copy and wires it up (as `origin`) so you can push
your changes back to your fork.

### A C++ compiler

Any C++17-capable compiler works. Examples below use `g++`, but any option gets you there.

**macOS**

```bash
xcode-select --install
```

This installs Clang (aliased as `g++`) via the Xcode Command Line Tools. Verify it worked:

```bash
g++ --version
```

**Windows — recommended: WSL (a real Linux environment inside Windows)**

Open PowerShell **as Administrator** and run:

```powershell
wsl --install
```

Restart your computer when prompted, then open **Ubuntu** from the Start menu and follow the
"Ubuntu / Debian" steps below inside it. This gets you the exact same commands as macOS/Linux
users, with no PATH setup.

**Windows — alternative: MSYS2 (native, no restart required)**

In PowerShell:

```powershell
winget install -e --id MSYS2.MSYS2
```

Then open **MSYS2 UCRT64** from the Start menu and run:

```bash
pacman -Syu --noconfirm
pacman -S --noconfirm mingw-w64-ucrt-x86_64-gcc
```

Add `C:\msys64\ucrt64\bin` to your `PATH` (Windows Settings → *Edit the system environment
variables* → *Environment Variables* → edit `Path` → *New* → paste it in), then open a **new**
terminal and verify:

```powershell
g++ --version
```

**Ubuntu / Debian**

```bash
sudo apt update && sudo apt install -y build-essential
```

Verify it worked:

```bash
g++ --version
```

---

## Getting Started

### 1. Install Git

**macOS**

```bash
brew install git
```

**Windows**

1. Download Git for Windows: [https://git-scm.com/download/win](https://git-scm.com/download/win)
2. Run the installer and accept the defaults.
3. Verify installation:

```powershell
git --version
```

**Ubuntu / Debian**

```bash
sudo apt update
sudo apt install git
```

### 2. Initialize your Git identity (one-time)

Git stamps every commit with a name and email — set these once per machine:

```bash
git config --global user.name  "Your Name"
git config --global user.email "you@example.com"
```

### 3. Fork the repository

Click **Fork** on [github.com/rusterman/cpp-oop-examples-and-exercises](https://github.com/rusterman/cpp-oop-examples-and-exercises)
to create your own copy under your GitHub account. You'll work and commit inside your fork, not
the original.

### 4. Clone your fork (if you haven't already)

Replace `<your-username>` with your GitHub username:

```bash
git clone https://github.com/<your-username>/cpp-oop-examples-and-exercises.git
cd cpp-oop-examples-and-exercises
```

Optionally, add the original repo as `upstream` so you can pull in future updates:

```bash
git remote add upstream https://github.com/rusterman/cpp-oop-examples-and-exercises.git
git remote -v   # origin = your fork, upstream = original
```

### 5. Build and run an example

No build system is required — each example/homework compiles standalone:

```sh
cd 2-INHERITANCE/examples/02-protected-members
g++ -std=c++17 -Wall -o main main.cpp
./main
```

---

## How to Work Through This Guide

1. **Go in lesson order** — `1-CLASSES-OBJECTS-AND-DATA-STRUCTURES` → `2-INHERITANCE` →
   `3-POLYMORPHISM`. Each builds on the last.
2. **Read the lesson's `README.md` first** for the topic list and, where included, a diagram
   giving you the big picture before the code.
3. **Study every file in `examples/` in order**, numbered `01`, `02`, ... Read the code, run it,
   change something and re-run it — don't just read.
4. **Then work through `homework/` one exercise at a time**, in numeric order. Each file name
   hints at what it's testing (e.g. `homework-05-online-shop-system.cpp`).
5. **Don't modify anything under `examples/`.** Keep it untouched so you can always diff your
   solution against the original reference. Compiled binaries, IDE settings, and OS files
   (`.DS_Store`, `.idea/`, `.vscode/`, `*.exe`, extensionless build output, etc.) are already
   excluded via `.gitignore` — you shouldn't need to touch it.

## Submitting Your Homework

Use one branch per person, named after your GitHub username, so your solutions are easy to find
and never collide with anyone else's fork history:

| Step | Command |
|------|---------|
| Create your solution branch | `git checkout -b solutions/<your-username>` |
| Work locally, commit per exercise | `git add .`<br>`git commit -m "2: homework 03 - multiple inheritance"` |
| Push your branch to your fork | `git push -u origin solutions/<your-username>` |

Replace `<your-username>` with your actual GitHub username. Commit each homework exercise
separately with a clear message (`<lesson-number>: homework <NN> - <short description>`) so your
progress is easy to follow. Once pushed, you can open a pull request from
`solutions/<your-username>` into your own fork's `main` for a clean, reviewable diff of your work.
