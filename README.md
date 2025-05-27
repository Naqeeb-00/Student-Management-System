# 🎓 Student Management System in C++

This project is a console-based Student Management System developed in C++ as part of a Data Structures and Algorithms (DSA) course. The system efficiently manages student records using a combination of Binary Search Trees (BST), Doubly Linked Lists (DLL), and a custom stack-based undo feature.

---

## 📌 Features

- ✅ Add, update, and delete student records
- 🔍 Search by:
  - Roll Number (via BST for fast lookup)
  - CGPA (via DLL for flexible traversal)
- 📊 Sort student records by:
  - Roll Number (Inorder traversal of BST)
  - CGPA (Bubble Sort on DLL)
- 🔁 Undo last operation using a custom stack
- 💾 Persistent file storage with file read/write support
- 👨‍💻 Simple and interactive command-line interface

---

## 🧠 Data Structures Used

| Structure            | Purpose                                      |
|---------------------|----------------------------------------------|
| Binary Search Tree  | Roll number-based search and sorting         |
| Doubly Linked List  | CGPA-related operations and traversal        |
| Stack (DLL-based)   | Undo feature to revert previous operations   |

---

## 📂 Project Structure

