# 🎆 The Ultimate Polymorphic Fireworks Show

A high-performance physics-based fireworks simulation built with **C++** and **SFML 3.0**.
This project demonstrates modern C++ architecture, focusing on **Object-Oriented Programming (OOP)**, **Polymorphism**, and **RAII Memory Management**.

![Fireworks Animation](/Animation.gif)

## 🚀 Overview

The simulation features a realistic particle system where every entity is an independent object governed by physics laws. 
* **Rockets** launch with upward velocity and leave a fading trail.
* **Sparks** explode upon rocket death, affected by gravity and drag.
* **Rendering** utilizes additive blending for realistic lighting effects.

## 🛠️ Tech Stack & Key Concepts

* **Language:** C++ (C++20 Standard)
* **Library:** SFML 3.0 (Simple and Fast Multimedia Library)
* **IDE:** Visual Studio 2026

### Core Engineering Concepts Implemented:

1.  **Polymorphism & Inheritance:**
    * Abstract base class `Particle` defines the interface.
    * Derived classes `Rocket` and `Spark` override `update()` and `draw()` with unique behaviors.
    
2.  **Smart Memory Management (RAII):**
    * Strict use of `std::unique_ptr` for automatic resource management.
    * **Rule of Zero:** No manual `new` or `delete` calls. The container handles lifecycle and cleanup automatically.

3.  **Modern STL Algorithms:**
    * Dynamic storage using `std::vector`.
    * Efficient memory cleanup using the **Erase-Remove Idiom** (`std::erase_if`) to prune dead particles every frame.

4.  **Physics Engine:**
    * **Euler Integration** for movement logic (`position += velocity`).
    * Gravity simulation (`velocity.y += gravity`) for creating parabolic arcs.
    * Mathematical trigonometry (`sin`, `cos`) for calculating circular explosion vectors.

## 💻 Code Highlight

The core engine loop demonstrates polymorphism in action. The main loop doesn't know *what* particle it updates, only that it is a `Particle`.

```cpp
// 1. Polymorphic Update
for (auto& p : particles) {
    p->update(); // Virtual function call
}

// 2. Dynamic Explosion Handling
if (p->isDead()) {
    // Dynamic cast to check if the dead particle was a Rocket
    if (auto* rocket = dynamic_cast<Rocket*>(p.get())) {
        createExplosion(rocket->getPosition(), rocket->getColor());
    }
}

// 3. Automatic Cleanup
std::erase_if(particles, [](const auto& p) {
    return p->isDead();
});

⚙️ How to Build & Run
Clone the repository.

Open the solution in Visual Studio.

Ensure SFML 3.0 is correctly linked (Include and Library directories).

Important: Copy the SFML .dll files (sfml-graphics-3.dll, etc.) into the folder containing the executable (x64/Debug or x64/Release).

Build and Run!

👨‍💻 About
Built by Ran Almagor. Software developer passionate about C++