# Student Data Storing Program

## Overview

By: Ali Faiyaz

This C++ program allows users to manage and persist student records. The program runs in a terminal window and supports commands for adding, finding, removing student records, and stopping the application.

## Student Record Structure

A student record consists of the following fields:

- **student_ID:** Unsigned integer representing the student's ID.
- **name:** String containing the student's name.
- **age:** Unsigned short representing the student's age.
  
## Commands

- `ADD student_ID name age`: Adds a student record with the specified ID, name, and age.
- `FIND condition`: Prints all records satisfying the given condition.
- `REMOVE condition`: Removes records based on the specified condition.
- `STOP`: Exits the application and saves changes to a hard disk.

## Implementation

### Classes

- **Parser:** Responsible for parsing user commands into tokens.
- **Manager:** Manages the core functionalities (ADD, FIND, REMOVE, STOP) based on parsed commands.
- **DiskManager:** Handles reading from and writing to a file on the hard disk.

### Compilation

To compile the program, use the following command:

```bash
g++ -std=c++17 *.cpp -o application
```

### How to Run
- Compile the program using the provided command.
- Run the compiled application.
- Enter commands in the terminal to perform various operations.

## Example Usage

```bash
$ ./application
ADD 67412 Smith,John 21
ADD 8723333 "Ann Smith" 33
FIND age = 21
REMOVE id < 50000
STOP
```


