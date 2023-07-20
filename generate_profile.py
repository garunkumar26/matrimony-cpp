from faker import Faker
import random 

fake = Faker()
genders = ['M','F']

with open("fake.txt","w") as file:
    for _ in range(1000):
        name = fake.name()
        age = random.randint(18,65)
        address = fake.address().replace("\n"," ")
        phone = fake.phone_number()
        email = fake.email()
        gender = fake.random_element(elements = genders)

        #write to the file
        file.write(name) 
        file.write("\n")
        file.write(str(age))
        file.write("\n")
        file.write(address)
        file.write("\n")
        file.write(phone)
        file.write("\n")
        file.write(email)
        file.write("\n")

        file.write(gender)
        file.write("\n")

    
        #now we can write a new form of method where in we will find how to take input from the text file.....

        #file.write("\n")

