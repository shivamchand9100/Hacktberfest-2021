from datetime import date, timedelta

sdate = date(2021, 6, 7)  # start date
edate = date(2021, 7, 26)  # end date

delta = edate - sdate  # as timedelta
count = 0

for i in range(delta.days + 1):
    day = sdate + timedelta(days=i)
    count += 1
    print(day)

print("\nDays: {}".format(count))

ss2402@heatcliff24:~$ cd os_lab

QUES 1. 

A) Create the file names under the directories as mentioned in the figure and write some relevant data into the files.

ss2402@heatcliff24:~/os_lab$ mkdir 2005535

ss2402@heatcliff24:~/os_lab$ cd 2005535
ss2402@heatcliff24:~/os_lab/2005535$ mkdir KIIT

ss2402@heatcliff24:~/os_lab/2005535$ cd KIIT
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ mkdir SCE SCIVE SEE SME SETCE
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ cd SCE

ss2402@heatcliff24:~/os_lab/2005535/KIIT/SCE$ mkdir CSE IT CSSE CSCE
ss2402@heatcliff24:~/os_lab/2005535/KIIT/SCE$ cd IT

ss2402@heatcliff24:~/os_lab/2005535/KIIT/SCE/IT$ cat>info.txt
This is a test file for Assignment 1
File name is info.txt
^C
ss2402@heatcliff24:~/os_lab/2005535/KIIT/SCE/IT$ cat>first.c
#include <stdio.h>
void main()
{
    printf("First.c file");
}
^C

ss2402@heatcliff24:~/os_lab/2005535/KIIT/SCE/IT$ cd ..
ss2402@heatcliff24:~/os_lab/2005535/KIIT/SCE$ cd ..
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ cd SEE

ss2402@heatcliff24:~/os_lab/2005535/KIIT/SEE$ mkdir M.Tech

ss2402@heatcliff24:~/os_lab/2005535/KIIT/SEE$ cd M.Tech
ss2402@heatcliff24:~/os_lab/2005535/KIIT/SEE/M.Tech$ cat>student
Test file
File name is student   
^C

ss2402@heatcliff24:~/os_lab/2005535/KIIT/SEE/M.Tech$ cd ..
ss2402@heatcliff24:~/os_lab/2005535/KIIT/SEE$ cd ..
ss2402@heatcliff24:~/os_lab/2005535/KIIT/SCE$ cd ..
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ cd SETCE
ss2402@heatcliff24:~/os_lab/2005535/KIIT/SETCE$ mkdir ETC CE ECE
ss2402@heatcliff24:~/os_lab/2005535/KIIT/SETCE$ cd ETC
ss2402@heatcliff24:~/os_lab/2005535/KIIT/SETCE/ETC$ mkdir LIBRARY
ss2402@heatcliff24:~/os_lab/2005535/KIIT/SETCE/ETC$ cd ..
ss2402@heatcliff24:~/os_lab/2005535/KIIT/SETCE$ cd ..


B) Rename the file info.txt as itstudentsdata.txt.

ss2402@heatcliff24:~/os_lab/2005535/KIIT$ mv SCE/IT/info.txt SCE/IT/itsstudentdata.txt
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ cat SCE/IT/itsstudentdata.txt
This is a test file for Assignment 1
File name is info.txt


C) Copy the file first.c into the directory CE with the same name.

ss2402@heatcliff24:~/os_lab/2005535/KIIT$ cp SCE/IT/first.c SETCE/CE/
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ cat SETCE/CE/first.c
#include <stdio.h>
void main()
{
    printf("First.c file");
}


D) Copy the file first.c into the directory SME with a new name as hello.c.

ss2402@heatcliff24:~/os_lab/2005535/KIIT$ cp SCE/IT/first.c SME/hello.c
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ cat SME/hello.c
#include <stdio.h>
void main()
{
    printf("First.c file");
}


E) Transfer the file student into the directory SCIVE and check whether transferred or not.

ss2402@heatcliff24:~/os_lab/2005535/KIIT$ mv SEE/M.Tech/student SCIVE/
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ ls SCIVE
student
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ cat SCIVE/student
Test file
File name is student


F) Rename CSSE to SYSTEM ENGG

ss2402@heatcliff24:~/os_lab/2005535/KIIT$ ls SCE
 CSCE  CSE  CSSE  IT
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ mv SCE/CSSE SCE/'SYSTEM ENGG'
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ ls SCE
 CSCE   CSE   IT  'SYSTEM ENGG'


G) Delete ECE directory.

ss2402@heatcliff24:~/os_lab/2005535/KIIT$ rmdir SETCE/ECE
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ ls SETCE/ECE
ls: cannot access 'SETCE/ECE': No such file or directory
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ ls SETCE
CE  ETC


H) Delete SEE directory.

ss2402@heatcliff24:~/os_lab/2005535/KIIT$ ls
SCE  SCIVE  SEE  SETCE  SME
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ rm -r SEE
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ ls SEE
ls: cannot access 'SEE': No such file or directory
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ ls
SCE  SCIVE  SETCE  SME


I) Copy IT directory to LIBRARY

ss2402@heatcliff24:~/os_lab/2005535/KIIT$ cp -r SCE/IT SETCE/ETC/LIBRARY
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ ls SETCE/ETC/LIBRARY
IT
ss2402@heatcliff24:~/os_lab/2005535/KIIT$ tree SETCE
SETCE
├── CE
│   └── first.c
└── ETC
    └── LIBRARY
        └── IT
            ├── first.c
            └── itsstudentdata.txt

4 directories, 3 files


Final Directory

ss2402@heatcliff24:~/os_lab/2005535/KIIT$ cd ..
ss2402@heatcliff24:~/os_lab/2005535$ cd ..
ss2402@heatcliff24:~/os_lab$ tree 2005535
2005535
└── KIIT
    ├── SCE
    │   ├── CSCE
    │   ├── CSE
    │   ├── IT
    │   │   ├── first.c
    │   │   └── itsstudentdata.txt
    │   └── SYSTEM ENGG
    ├── SCIVE
    │   └── student
    ├── SETCE
    │   ├── CE
    │   │   └── first.c
    │   └── ETC
    │       └── LIBRARY
    │           └── IT
    │               ├── first.c
    │               └── itsstudentdata.txt
    └── SME
        └── hello.c

13 directories, 7 files
