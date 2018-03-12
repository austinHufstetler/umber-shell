
![GitHub Logo](logo.png)

# umber-shell

This is an academic project for an Operating Systems course.

Contributors: Austin Hufstetler, Mallory Helms

## Goals
Most shells focus on shorter commands rather than self-explanatory ones. The names of commands like 'mkdir', 'ls', and 'touch' give no indication as to what the commands actually do. One of our goals is to create a shell with easy-to-understand command; such as 'file new'.

Another goal is not related to the shell itself but the code used to write it. Our objective is to write code that is easy to read, easy to follow, and that gives the reader a detailed understanding of what is going on behind the scenes.
Our code has a common flow of main_handler -> category_handler -> method. This makes it very easy to find the code of the command the user would like to see. 

Finally, the biggest goal of this project is to give ourselves and the users a deeper understanding as to how programs interact with an operating system. System calls are methods that the operating systems provide that give users direct access to the services of an operating system. Most programmers simply use the programming languages libraries and never interact with system calls directly. System calls and assembly code are used very frequently in our code, and while they may create more verbose code, they give the reader a deeper understanding of how shells (and other programs) interact with the operating system.

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

print directory - prints all files and folders in current directory


### Math

math subtract a b       - evaluates a - b and prints result

math add a b             - evaluates a + b and prints result

### File
file new foo.fee public   - creates a new file named foo.fee in current folder and gives read, write, execute rights to every user

file new foo.fee private  - creates a new file named foo.fee in current folder and gives read, write rights to current user only

file rename current_name new_name - renames a file

file move file_name directory_name - moves a file from current directory to new directory (example. "file move test.txt test/")

file delete file_name - deletes file called file_name that is in current directory

### Directory
directory new foo public  - creates a new directory named foo in current folder and gives read, write, execute rights to every user

directory new foo private - creates a new directory named foo in current folder and gives read, write rights to current user only

directory change path - changes directory to path name

directory delete empty directory_name - deletes empty(important) directory called directory_name



### Notes
Work in progress

logo credit: 
Check out the new logo that I created on <a href="http://logomakr.com" title="Logo Makr">LogoMakr.com</a> https://logomakr.com/5dNSbP

Check out the new logo that I created on <a href="http://logomakr.com" title="Logo Makr">LogoMakr.com</a> https://logomakr.com/0aieOc

