# Master Object-Oriented Programming in C++

> **Don't memorize OOP. Understand it. Build with it.**

A structured, practical C++ course designed to take you from **OOP fundamentals to deep understanding through real code and exercises**.

OOP is often taught as a collection of syntax, rules, Design Patterns, and SOLID principles.

That approach can make OOP feel complicated.

This repository takes a different approach:

**Understand the fundamentals → Study working code → Experiment → Solve problems → Build real understanding.**

---

## Why OOP?

OOP is one of the most important — and most misunderstood — parts of software engineering.

Beginners often struggle because they learn concepts without understanding **why they exist**.

Experienced developers can make the opposite mistake: jumping directly to **SOLID and Design Patterns** without having a strong mental model of objects, classes, inheritance, composition, and polymorphism.

**Master OOP first. Design Patterns and SOLID become much easier to understand afterward.**

The goal of this repository is not to teach you how to memorize:

```cpp
class MyClass { ... };
```

The goal is to teach you how to think about:

- What should be an object?
- What should an object own?
- What should it expose?
- How should objects communicate?
- When should objects be composed?
- When does inheritance make sense?
- How does polymorphism actually work?
- How do these ideas help us design real software?

> **The syntax is easy. Understanding the design is the real skill.**

---

# Learning Path

The material is organized progressively. Each stage builds on the previous one.

### 1. Classes, Objects & Data Structures

Learn the foundations of object-oriented programming:

- Classes and objects
- Encapsulation
- Constructors and destructors
- Access specifiers
- `this` pointer
- Static members
- Object relationships
- Practical data structures
- Linked lists
- Stacks
- Queues
- Binary search trees
- Memory fundamentals

**Start here.**

[→ Open Classes, Objects & Data Structures](./1-CLASSES-OBJECTS-AND-DATA-STRUCTURES/)

---

### 2. Inheritance

Understand how classes can be extended and how inheritance actually works:

- Base and derived classes
- Access control
- `public`, `protected`, and `private`
- Constructors and destructors
- Inheritance relationships
- Multiple inheritance
- Practical inheritance examples

[→ Open Inheritance](./2-INHERITANCE/)

---

### 3. Polymorphism

Learn one of the most powerful ideas in OOP:

- Virtual functions
- Function overriding
- Dynamic binding
- Static vs dynamic binding
- Abstract classes
- Interfaces
- Runtime polymorphism

[→ Open Polymorphism](./3-POLYMORPHISM/)

---

# How to Learn

Every lesson follows the same learning cycle:

**Understand → Read → Run → Experiment → Solve**

### 1. Understand

Read the lesson `README.md` first.

Build a mental model of the concept before looking deeply at the implementation.

### 2. Study the Examples

Open the examples in numerical order.

Don't just read the code.

**Compile it. Run it. Change it. Break it. Fix it.**

### 3. Experiment

Use `playground.cpp` to experiment freely.

Try changing the examples and predict what will happen before running them.

### 4. Solve the Homework

After studying the examples, solve the exercises in `homework/`.

**Don't look for solutions immediately.**

Struggling with a problem is part of learning the concept.

---

# Repository Structure

Each lesson follows the same structure:

```text
LESSON/
├── README.md
│
├── images/
│
├── examples/
│   ├── 01-topic/
│   │   └── main.cpp
│   ├── 02-topic/
│   │   └── main.cpp
│   └── ...
│
├── homework/
│   ├── homework-01-*.cpp
│   ├── homework-02-*.cpp
│   └── ...
│
└── playground.cpp
```

### `README.md`

Explains the concepts and provides the learning roadmap.

### `examples/`

Worked examples demonstrating each concept.

**Read them in order.**

### `homework/`

Exercises designed to make you implement the concepts yourself.

**No solutions are provided.**

### `playground.cpp`

A scratch space for experimentation.

Change anything you want.

---

# Setup

You need:

- **C++17 or newer**
- A C++ compiler
- Git
- A code editor or IDE

Examples can be compiled directly with `g++`.

```bash
g++ -std=c++17 -Wall -Wextra -o main main.cpp
./main
```

For example:

```bash
cd 2-INHERITANCE/examples/02-protected-members
g++ -std=c++17 -Wall -Wextra -o main main.cpp
./main
```

No build system is required. Each example is designed to compile independently.

---

# Getting the Repository

If you want to keep your homework solutions, fork the repository first and then clone your fork:

```bash
git clone https://github.com/<your-username>/cpp-oop-examples-and-exercises.git
cd cpp-oop-examples-and-exercises
```

Then start with:

```text
1-CLASSES-OBJECTS-AND-DATA-STRUCTURES
```

---

# Rules for Learning

### Don't just read.

Reading code creates familiarity.

**Writing code creates understanding.**

### Don't memorize.

If you understand *why* something works, you don't need to memorize it.

### Don't skip the exercises.

The examples show you **how**.

The exercises test whether you understand **why**.

### Don't rush to Design Patterns.

First understand:

**Objects → Classes → Encapsulation → Composition → Inheritance → Polymorphism**

Then move toward:

**SOLID → Design Patterns → Software Architecture**

---

# The Bigger Goal

This repository is being built around one principle:

> **Deep OOP understanding should come before Design Patterns and SOLID.**

Frameworks change.

Programming languages evolve.

Libraries come and go.

But the ability to reason about **objects, responsibilities, relationships, abstraction, and behavior** remains fundamental to software engineering.

OOP appears sooner or later in many real-world systems:

**Backend · Frontend · Mobile · Games · Desktop · ML/AI · Large-scale systems**

The goal is not simply to finish the exercises.

The goal is to reach the point where you can look at a real software problem and naturally think:

> **What are the objects? What should they own? What should they do? How should they interact?**

That's when you stop *using* OOP and start **thinking in OOP**.

---

## Start Learning

### [1. Classes, Objects & Data Structures →](./1-CLASSES-OBJECTS-AND-DATA-STRUCTURES/)

### [2. Inheritance →](./2-INHERITANCE/)

### [3. Polymorphism →](./3-POLYMORPHISM/)

---

> **Understand OOP. Practice OOP. Master OOP.**