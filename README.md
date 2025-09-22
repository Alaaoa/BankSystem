📌 Overview

This project is a Banking Management System written in C++.
It allows you to manage clients (accounts, balances) and users (system login with permissions).
The system includes secure login, file storage, and permissions-based access control.

🚀 Features
👤 Client Management

Add new clients

Update existing client information

Delete clients

Find a client by account number

List all clients

💰 Transactions

Deposit money into an account

Withdraw money from an account

Show total balances across all clients

🔐 User Management

Add new system users

Update users (username, password, permissions)

Delete users

Find a user by username

List all system users

🛡️ Security

Login system with username & password

Role-based permissions using bit flags:

View clients

Add clients

Update clients

Delete clients

Transactions

Manage users

Full access

💾 File Handling

Client records are stored in Clients.txt

User records are stored in Users.txt

Data persists between program runs

🛠️ Tech Stack

Language: C++17

Compiler: g++ / MSVC

Storage: Text files (.txt)


 ┣ 📜 Clients.txt       # Client records
 ┣ 📜 Users.txt         # User records
 ┣ 📜 README.md         # Documentation
