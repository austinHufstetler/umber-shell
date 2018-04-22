
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
* <strong>help</strong> - prints list of subcategories and their descriptions (math, print, process, etc)

* <strong>exit</strong> - exits shell

### Process
* <strong>process get id  </strong>          - prints pid of shell

* <strong>process replace path args  </strong>          - replaces shell with new process

### Print
* <strong>print this foo fee fii</strong>         - prints whatever comes after this statement

* <strong>print file foo.txt x</strong> -prints text file on shell with only x number of characters printed

* <strong>print file foo.txt</strong> - prints entire text file

* <strong>print directory</strong> - prints all files and folders in current directory


### Math

* <strong>math subtract a b</strong>       - evaluates a - b and prints result

* <strong>math add a b</strong>             - evaluates a + b and prints result

* <strong>math multiply a b</strong>             - evaluates a * b and prints result

* <strong>math divide a b</strong>       - evaluates a / b and prints result

* <strong>math mod a b</strong>             - evaluates a % b and prints result


### File
* <strong>file new foo.fee public</strong>   - creates a new file named foo.fee in current folder and gives read, write, execute rights to every user

* <strong>file new foo.fee private</strong>  - creates a new file named foo.fee in current folder and gives read, write rights to current user only

* <strong>file new foo.fee none</strong>  - creates a new file named foo.fee in current folder and gives read, write rights to no one :) (not very useful, but interesting to see how to do it)

* <strong>file rename current_name new_name</strong> - renames a file

* <strong>file move file_name directory_name</strong> - moves a file from current directory to new directory (example. "file move test.txt test/")

* <strong>file delete file_name</strong> - deletes file called file_name that is in current directory

### Directory
* <strong>directory new foo public</strong>  - creates a new directory named foo in current folder and gives read, write, execute rights to every user

* <strong>directory new foo private</strong> - creates a new directory named foo in current folder and gives read, write rights to current user only

* <strong>directory change path</strong> - changes directory to path name

* <strong>directory delete empty directory_name</strong> - deletes empty(important) directory called directory_name



### Notes
Work in progress

logo credit: 
Check out the new logo that I created on <a href="http://logomakr.com" title="Logo Makr">LogoMakr.com</a> https://logomakr.com/5dNSbP

Check out the new logo that I created on <a href="http://logomakr.com" title="Logo Makr">LogoMakr.com</a> https://logomakr.com/0aieOc

