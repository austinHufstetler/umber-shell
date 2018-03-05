![Alt text](https://lh3.googleusercontent.com/klFxCjTRWH-sM805LjvYJw8jDTDGtIFukHrG4vLjf7QQsfPe1Pm6VRALcituCXFqRUAJHC0mKyCi0rM6Pers=w1920-h935-rw)

# umber-shell

This is an academic project for an Operating Systems course.

## How to use
1. Clone this project into your workspace
2. In your command line terminal go to the folder with this project
3. type make
4. type bin_files/umber_shell

## Resources Used

A great guide to implementing your own shell
http://www.gnu.org/software/libc/manual/html_node/Implementing-a-Shell.html#Implementing-a-Shell

This repository was used during initial setup
https://github.com/jmreyes/simple-c-shell

## Commands

### Main (without typing subcategory below)
help - prints list of subcategories and their descriptions (math, print, process, etc)

bye - exits shell

### Process
process get id            - prints pid of shell

### Print
print this foo fee fii         - prints whatever comes after this statement

print file foo.txt x -prints text file on shell with only x number of characters printed

print file foo.txt - prints entire text file


### Math

math subtract a b       - evaluates a - b and prints result

math add a b             - evaluates a + b and prints result

### File
file new foo.fee public   - creates a new file named foo.fee in current folder and gives read, write, execute rights to every user

file new foo.fee private  - creates a new file named foo.fee in current folder and gives read, write rights to current user only

### Directory
directory new foo public  - creates a new directory named foo in current folder and gives read, write, execute rights to every user

directory new foo private - creates a new directory named foo in current folder and gives read, write rights to current user only

directory change path - changes directory to path name



### Notes
Work in progress


