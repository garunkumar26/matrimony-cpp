# matrimony-cpp

This is a Matrimony project. In which i have generated fake profiles using python's  "faker" library, which is a in-built library used to generate n number no of profiles as per our need. And for this project i have generated 1000 profiles with name,age,address,phone,gender and email. 
The entire program is written in C++ language by using STL and basics, and i have stored all the above generated fake profiles in the Mysql Database.
First an user can register looking for a match by entering their details and it gets stored in the database. And we can look for a match based on the age priority and we will get the details of the perfect match based on the entered details of the user.

I have used Dev C++ for compiling and running the program and used Mysql 8.0 Command Line Client for running the commands to store and retrieve the details from the Mysql database. 
While creating the cpp project create in CONSOLE APPLICATION mode, and then proceed.
Settings i have made after creating the project Matrimony and add the path of:
1. open Program Files -> Mysql -> Mysql Server 8.0 -> include and copy the path in include folder while creating the project
2. next open Program Files -> Mysql -> Mysql Server 8.0 -> include -> mysql and copy the path in include folder
3. next add the library folder which is in path ---> open Program Files -> Mysql -> Mysql Server 8.0 -> lib and copy the path in lib folder.
4. add a statement -->   -lmysql in "linker" part of the project and you are done with proper creation of the project.

Next, add the libmysql.dll file in the folder where in you have created the project.
For creation of Fake profiles, you can just change the "n" in the "for" loop and you can generate as much as profiles we need.
main.cpp is the program where our concept of matrimony is written.
After we compile the main.cpp we will get the main.o (object file)
and Matrimony project.layout file is automatically created when we compile the file and creation of project is successful.
and Finally "fake.txt" is the file where the fake profiles generated are written into.
And finally we will get the perfect match for the user.
