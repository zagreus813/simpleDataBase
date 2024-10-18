# Simple Database Management in C

This project is a simple database management system implemented in C. It allows you to perform basic operations on records, such as creating, reading, updating, and deleting (CRUD). The database can also be saved to and loaded from a file.

## Features

- Add new records with ID, name, and age.
- Search for records by ID.
- Update existing records.
- Delete records by ID.
- Save the database to a binary file.
- Load the database from a binary file.

## Project Structure

The project consists of the following files:

- `record.h`: Defines the `Record` structure and functions to work with individual records.
- `record.c`: Implements the functions for creating, printing, and comparing records.
- `database.h`: Defines the `Database` structure and CRUD functions.
- `database.c`: Implements the database operations and file I/O.
- `main.c`: Demonstrates how to use the database in a simple program.

## Getting Started

### Prerequisites

To compile and run this project, you need:

- A C compiler (GCC, Clang, etc.)
- A terminal or command line

### Compiling the Project

You can compile the project using the following command:

```bash
gcc main.c record.c database.c -o database_app
