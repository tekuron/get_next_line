# get_next_line
get_next_line function in C for the 42 curriculum, reading files line by line from a file descriptor with proper memory management and buffering.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Bonus Part](#bonus-part)
- [Author](#author)

---

## Overview
get_next_line allows reading from a file descriptor line by line, returning each line including the newline character when present. It handles buffering efficiently and manages memory to avoid leaks. This project was developed as part of the 42 curriculum to practice file I/O, dynamic memory, and buffer management in C.

## Features
get_next_line includes the following core functionalities:
- Reads one line at a time from a given file descriptor
- Supports multiple file descriptors simultaneously
- Handles arbitrary line lengths
- Efficient buffer management using a defined BUFFER_SIZE
- Proper memory allocation and deallocation to avoid leaks

## Project Structure
The repository is organized as follows:
- get_next_line.c / get_next_line_bonus.c: main function implementations
- get_next_line_utils.c / get_next_line_utils_bonus.c: utility functions
- get_next_line.h / get_next_line_bonus.h: header files
- file.txt: sample input file

## Usage
To compile get_next_line, include the source and header files in your program:

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

then run:
```bash
cc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=x
```
replacing ``x`` with the desired buffer size.

## Bonus Part
The bonus version supports reading from multiple file descriptors simultaneously, allowing independent line-by-line reading from each descriptor without interference.

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    char *line1;
    char *line2;

    while ((line1 = get_next_line(fd1)) != NULL ||
           (line2 = get_next_line(fd2)) != NULL)
    {
        if (line1)
        {
            printf("FD1: %s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("FD2: %s", line2);
            free(line2);
        }
    }
    close(fd1);
    close(fd2);
    return 0;
}
```

Use the bonus files for the added features:
```bash
cc main.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=x
```

### Bonus Features
- Supports multiple file descriptors simultaneously
- Maintains separate buffers for each descriptor
- Ensures correct line reading without interference

## Author
- **Name:** Daniel Zamora
- **GitHub:** [tekuron](https://github.com/tekuron)
- **42 Intra:** [danzamor](https://profile-v3.intra.42.fr/users/danzamor)
- **School:** 42
