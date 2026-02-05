# MapleStory C++ Simulation 🎮

## 📌 Overview
This project is a **C++ simulation inspired by MapleStory**, designed as a learning and architecture-focused project.

The goal is to model:
- Characters with different jobs
- Missions (tasks) with execution conditions
- Asynchronous task execution using a custom ThreadPool

The project emphasizes **modern C++ design**, **object-oriented programming**, and **concurrency**, rather than graphics or UI.

---

## 🧠 C++ Concepts & Technologies Used

- Modern C++ (C++17)
- Smart Pointers (`std::unique_ptr`)
- Inheritance & Polymorphism
- Abstract Base Classes
- RAII
- Custom ThreadPool implementation
- Multithreading (`std::thread`)
- Synchronization (`std::mutex`, `std::condition_variable`)
- Lambdas & move semantics
- Separation of concerns (Game / Task / ThreadPool)

---

## 🏗 Architecture Overview

### 🎮 Game
- Owns all characters and missions
- Maintains a queue of missions (`Task`)
- Decides which character can execute a mission
- Submits executable jobs to the ThreadPool

### 🧑 Character (Abstract Base Class)
- Represents a playable character
- Holds common state:
  - name
  - level
  - experience (EXP)
- Defines a common interface:
  - Attack / Defense
  - Job name
  - EXP progression
- Specialized by job classes

#### Implemented Jobs
- Beginner
- Thief
- Magician
- BossCharacter (specialized character type)

---

### 📜 Task (Abstract Base Class)
- Represents a mission that can be executed by a character
- Defines:
  - `canBeExecutedBy(const Character&)`
  - `execute(Character&)`
- Each derived task controls its own logic and difficulty

#### Implemented Tasks
- BeginnerTask
- ThiefTask
- MagicianTask

---

### ⚙ ThreadPool
- Manages a fixed number of worker threads
- Executes submitted jobs asynchronously
- Decoupled from game logic
- Uses condition variables to sleep when no jobs are available

---

## ▶ Current Gameplay Flow

1. Characters are created and added to the game
2. Missions are created and pushed into a mission queue
3. The game checks if a character can execute a mission
4. If allowed:
   - The mission is wrapped in a lambda
   - The lambda is submitted to the ThreadPool
5. Worker threads execute missions concurrently
6. Characters gain EXP upon mission completion

⚠ Currently, mission execution is demonstrated primarily with the **Thief** job, and task assignment is simplified.

---

## 🧪 Current State of the Project

✔ Implemented:
- Character hierarchy
- Task hierarchy
- Custom ThreadPool
- Asynchronous mission execution
- EXP progression

🛠 In Progress / Planned:
- Smarter character selection for missions
- Multiple characters executing tasks concurrently
- Thread-safe character state updates
- Improved task scheduling strategies
- Additional game mechanics (equipment, scaling stats, etc.)

---

## 🛠 Build & Run

The project uses a simple `Makefile`.

```bash
make
./game
