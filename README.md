# HashMap Implementation

This is a C++ program showcasing a custom implementation of a HashMap data structure using templates. It includes demonstration examples using integer and string keys along with various functionalities like insertion, deletion, and retrieval. The program utilizes a custom hashing function to map keys to values efficiently.

## Usage

### Running the Program

To run the program, ensure you have a C++ compiler available.

Compile the program using the following command:

```bash
g++ -o HashMapProgram HashMapImplementation.cpp
```

Run the compiled program:

```bash
./HashMapProgram
```

### Description

- `intHashCode`: Hash function for integer keys
- `stringHashCode`: Hash function for string keys based on length

The program contains three main sections:

1. **Default HashMap Operations**
   - Initializes a HashMap, performs key-value insertion, search, and deletion.
   - Prints the stored key-value pairs.

2. **Reading from 'small1k.txt'**
   - Reads from the input file 'small1k.txt' and stores the data in the HashMap.
   - Displays a few entries stored from the file.
   
3. **Reading from 'large100k.txt'**
   - Reads from the input file 'large100k.txt' and stores the data in a separate HashMap.
   - Displays a few entries stored from the file.

## Contributors

- Jesus Rodriguez-Luna
- jesusrodriguezluna3616@gmail.com
