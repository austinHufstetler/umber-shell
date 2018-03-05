
<img src="https://lh3.googleusercontent.com/Ttxh22Q3TbGkmo_8frVT9xfAtvi65BdSsIVHaIT3gl8UA6Zb5F9XGSB5hgGraz2wSCIHjBGKNmgdmcup6j9R=w1920-h935-rw" width="450">

# umber-shell

This is an academic project for an Operating Systems course.

## Goals
Most shells focus on shorter commands rather than self-explanatory ones. The names of commands like 'mkdir', 'ls', and 'touch' give no indication as to what the commands actually do. One of our goals is to create a shell with easy-to-understand commands.

However, the biggest goal doesn't lie in the shell itself, but the code used to write it. Our main objective is to write code that is easy to read, easy to follow, and that gives the reader a detailed understanding of what is going on behind the scenes.
Our code has a common flow of main_handler -> category_handler -> method. This makes it very easy to find the code of the command the user would like to see. System calls and assembly code are used whenenever appropriate to give the reader (as well as ourselves) a deeper understanding as to what goes on behind the scenes of most shells.

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

logo credit: 
Check out the new logo that I created on <a href="http://logomakr.com" title="Logo Makr">LogoMakr.com</a> https://logomakr.com/5dNSbP

Check out the new logo that I created on <a href="http://logomakr.com" title="Logo Makr">LogoMakr.com</a> https://logomakr.com/0aieOc

