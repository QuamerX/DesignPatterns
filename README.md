# Design Patterns in C++

## Overview

This repository contains implementations of common **Design Patterns** in **C++**.
Each pattern illustrates a reusable solution to recurring software design problems, emphasizing **abstraction**, **encapsulation**, **loose coupling**, and **code maintainability**.

Patterns are categorized into **Creational**, **Structural**, and **Behavioral** groups as defined in the original *Gang of Four (GoF)* book.

---

## Creational Patterns

Focus on **object creation mechanisms** that make a system independent of how its objects are created, composed, and represented.

### **1. Singleton**

Ensures that a class has **only one instance** and provides a **global access point** to it.
Used for managing shared resources like configuration or logging systems.

### **2. Factory Method**

Defines an **interface for creating objects**, but lets **subclasses decide which class to instantiate**.
Used when you need to delegate object creation to subclasses.

### **3. Abstract Factory**

Provides an **interface for creating families of related objects** without specifying their concrete classes.
Useful when your system needs to work with multiple product families that must be used together.

### **4. Builder**

Separates the **construction of a complex object** from its representation, allowing the same process to create different representations.
Commonly used for objects that require multiple configuration steps (e.g., creating a custom car or meal).

### **5. Prototype**

Creates new objects by **cloning existing ones** instead of creating them from scratch.
Used when object creation is expensive or complex.

---

## Structural Patterns

Deal with **class and object composition**, forming larger structures while keeping them flexible and efficient.

### **6. Adapter**

Converts the **interface of a class into another interface** expected by the client.
Allows incompatible interfaces to work together (e.g., wrapping a legacy API).

### **7. Bridge**

Decouples an **abstraction from its implementation**, allowing both to vary independently.
Used when you want to separate a stable interface from multiple possible implementations.

### **8. Composite**

Composes objects into **tree structures** to represent part–whole hierarchies.
Treats individual objects and compositions uniformly (e.g., folders and files in a filesystem).

### **9. Decorator**

Attaches **additional behavior** to an object **dynamically** without modifying its class.
Useful for adding features at runtime (e.g., visual UI components or I/O streams).

### **10. Facade**

Provides a **unified, simplified interface** to a complex subsystem.
Used to reduce coupling between clients and subsystems.

### **11. Flyweight**

Reduces memory usage by **sharing common data** between similar objects.
Used for large numbers of fine-grained objects (e.g., characters in a text editor).

### **12. Proxy**

Provides a **surrogate or placeholder** for another object to control access, reduce cost, or add functionality.
Examples include virtual proxies (lazy loading) and remote proxies (network access).

---

## Behavioral Patterns

Focus on **communication between objects** and how responsibilities are distributed.

### **13. Chain of Responsibility**

Passes a request along a **chain of handlers** until one handles it.
Promotes decoupling between senders and receivers (e.g., event propagation or logging).

### **14. Command**

Encapsulates a **request as an object**, allowing you to parameterize, queue, or undo operations.
Common in GUI systems or transaction mechanisms.

### **15. Iterator**

Provides a **standard way to traverse elements** of a collection without exposing its internal structure.
Separates iteration logic from collection logic.

### **16. Mediator**

Defines an object that **coordinates communication** between other objects.
Reduces direct dependencies and promotes loose coupling (e.g., chat rooms or UI dialogs).

### **17. Memento**

Captures and restores an object’s **internal state** without violating encapsulation.
Used for undo/redo mechanisms.

### **18. Observer**

Defines a **one-to-many relationship** between objects so when one changes state, all dependents are notified.
Used in event systems and UI frameworks (e.g., data binding).

### **19. State**

Allows an object to **change its behavior when its internal state changes**.
Used in finite state machines or mode-based systems.

### **20. Strategy**

Defines a **family of algorithms** encapsulated as interchangeable objects.
Lets you switch algorithms at runtime (e.g., sorting strategies, compression types).

### **21. Template Method**

Defines the **skeleton of an algorithm** in a base class, allowing subclasses to override certain steps.
Used to enforce structure while enabling customization.

### **22. Visitor**

Separates **algorithms from the objects** on which they operate.
Allows adding new operations to existing object structures without modifying them.

## References

* *Design Patterns: Elements of Reusable Object-Oriented Software* – Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides
* *Head First Design Patterns* – Eric Freeman & Elisabeth Robson
* [Refactoring.Guru – Design Patterns](https://refactoring.guru/design-patterns)