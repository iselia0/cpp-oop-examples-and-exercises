# C++ OOP — Examples & Exercises

![The four pillars of OOP: classes, objects, encapsulation, inheritance, polymorphism](images/oop-pillars-overview.jpeg)

A structured set of C++ object-oriented programming exercises, organized by topic. Each
numbered lesson folder contains worked **examples** you can read/run and a **homework** set
for students to complete. Written for a mixed audience — complete beginners through
experienced engineers brushing up on C++ specifics.

## Structure

```
16-classes-objects-and-data-structures/   classes, objects, and 4 data structures (linked list, stack, queue, BST)
17-inheritance/                           base/derived classes, access control, constructors & destructors
18-polymorphism/                          virtual functions, abstract classes, static/dynamic binding
```

Each lesson has its own `README.md` with a full topic list. The layout inside is the same
everywhere:

```
NN-topic-name/
├── README.md
├── images/                 # diagrams referenced at the top of this lesson's README.md
│   └── some-diagram.png
├── examples/
│   ├── 01-first-subtopic/
│   │   └── main.cpp        # supporting headers (person.h, ...) live alongside main.cpp
│   ├── 02-second-subtopic/
│   │   └── main.cpp
│   └── ...
├── homework/
│   ├── homework-01-short-description.cpp   # single-file exercise
│   ├── homework-02-short-description.cpp
│   └── ...
└── playground.cpp          # scratch file for experimenting, not part of the curriculum
```

- **`images/`** — reference diagrams shown at the top of the lesson's `README.md` for a quick
  visual overview before diving into the examples. Not every lesson needs one.
- **`examples/`** — instructor-provided code demonstrating one concept each, numbered in
  teaching order. Read these first, then attempt the homework.
- **`homework/`** — exercises for students, provided without solutions. Each file name hints
  at what the exercise is about (e.g. `homework-05-online-shop-system.cpp`).
- **`playground.cpp`** — a free scratch file per lesson for trying things out. Feel free to
  overwrite it locally; it's not graded content.

### Naming conventions

- Folders and files use `kebab-case`.
- Numeric prefixes are zero-padded (`01`, `02`, … `10`) so they always sort correctly.
- Homework numbers follow the original exercise numbering — if a number is missing (e.g.
  lesson 18 has no homework 13), that exercise was never assigned; it isn't a mistake.
- A topic folder with a single source file names it `main.cpp`; multi-file topics keep the
  class name as the file name (e.g. `cylinder.h`, `Order.cpp`).
- Images in an `images/` folder are named for what they show, not their source
  (e.g. `inheritance-types-overview.jpg`, not `inheritance.jpg` or `IMG_0231.jpg`).

## Building and running an example

No build system is required — each example/homework compiles standalone:

```sh
cd 17-inheritance/examples/02-protected-members
g++ -std=c++17 -Wall -o main main.cpp
./main
```

## For students: forking this repo

1. Fork the repository to your own GitHub account.
2. Clone your fork locally.
3. Work inside each lesson's `homework/` folder — do not modify `examples/`, so you can
   always diff against the original for reference.
4. Commit your solutions with clear messages (e.g. `git commit -m "17: homework 03 - multiple inheritance"`).
5. Compiled binaries, IDE settings, and OS files (`.DS_Store`, `.idea/`, `.vscode/`, `*.exe`,
   extensionless build output, etc.) are already excluded via `.gitignore` — you shouldn't need
   to touch it.

## Known gaps

- `16-.../homework/homework-13-stack.cpp` depends on a `LinkedList.h` that isn't in the repo yet.
- `18-.../homework/` has no exercise numbered 13 (skipped in the original course numbering).
