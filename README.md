# simple-meeting-planner
simple meeting planner using c++ and data-structure
Meeting Planner


1	Overview

•	This code helps people to arrange their to-do list or meetings and this helping in time management.

•	This code also tells the user if there is a meeting in this time to avoid conflict between meetings. The user can add, delete, and modify a meeting and also it can show the meeting list ordered by day and hours and it can show if there is meeting in a certain date or not


 ![image](https://user-images.githubusercontent.com/78000492/133077195-847a5db1-2c86-45bc-b19b-51c449f1a04f.png)

Figure 1 binary search tree structure

2	Main Flows

As we see from figure 1 the binary search tree that used in code arranges the meetings as always left child smaller than the head and right child are bigger than the head.
Node content

•	Meeting title : it is string and it must be between double quotation, it can be anything it can contains characters or numbers or signs

•	Meeting day: it is integer number between 1 and 365 and it describes in what day meeting is

•	Meeting hour: it is integer number between 0 and 23 and it describes in what time meeting is 

•	Link (pointer) to lift and right children 

First thing the code takes the file name that contains the commands and starts to handle the file line by line according to command and check if there is invalid title or day or hour according to previous information
After handling the commands the code shows the outputs on the screen and write it in the file so the user can keep the output with the user without needing to run the program
The following diagrams shows simply how the code works 
 
 ![image](https://user-images.githubusercontent.com/78000492/133077251-ccec30ed-e782-493b-9fa1-5172a9d8681d.png)

Figure 2 flowchart of main function


 ![image](https://user-images.githubusercontent.com/78000492/133077288-b2410d16-d05c-4a0a-8a9a-32eb805e83c5.png)

Figure 3 delete function

Note: string symbols in flowchart instead off (*) and, (.)  Instead of (->) because I cannot put it correctly  
 
 ![image](https://user-images.githubusercontent.com/78000492/133077331-c679a3bf-9403-411b-9059-03742215f3b0.png)

Figure 4 add function
 
 ![image](https://user-images.githubusercontent.com/78000492/133077352-4ad0e8b0-cb58-44cc-80ce-a3f1a42dbe5c.png)

Figure 5 print function

 
 ![image](https://user-images.githubusercontent.com/78000492/133077394-12639453-254e-4e63-b7c5-f1ab105c3338.png)

Figure 6 modify function
 
 ![image](https://user-images.githubusercontent.com/78000492/133077422-15a212c3-9809-45ec-836f-b2afd1390241.png)

Figure 7 find function




3	General notes 

•	In main.cpp I convert the code into small functions as (getcommand(),gettitle(),…) so I can use it in each line and just to make it easy for me while debugging

•	Sometimes I used flags just for error handling 

•	This BST that used in this project all allocated in heap to avoid waste of memory or the user can add meetings as he wants (linked representation)

•	The meetings are sorted ascending by hours and days as example (meeting in day 0 time 3 before meeting in day 0 time 23 and all before meeting in day 1 time 0) and so on

•	this tree is ordered and provides fast insertion and search
