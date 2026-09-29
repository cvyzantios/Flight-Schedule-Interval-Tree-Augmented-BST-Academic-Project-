# Flight-Schedule-Interval-Tree-Augmented-BST-Academic-Project
Remastered a core Data Structures project originally built in C++

Project Type:
Personal Project / Academic Portfolio

Description:
Remastered a core Data Structures project originally built in C++ into a clean, modern multi-language repository featuring C++20, C# 12 (.NET 8), and Python 3.12.

The project implements an Augmented Interval Tree (based on a Binary Search Tree ordered by departure times) designed for high-performance flight window queries and real-time interval matching.

Key Achievements & Architecture:
• Augmented BST Design: Each node maintains a max_arrival_time field for its entire subtree, reducing range-overlap queries from O(N) linear scans to O(h) tree traversals.
• Key Operations Implemented: Dynamic flight Insertion/Deletion with invariant maintenance (bottom-up subtree updates), single-flight overlap search, full range interval queries ([start, end]), and boundary coverage queries (max arrival before time h).
• Multi-Language Parity: Re-architected the original algorithm across modern C++ (RAII & smart pointers), C# 12 (clean OOP API & pattern matching), and Python 3.12 (type hinting & dataclasses).
