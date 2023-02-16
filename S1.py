# -*- coding: utf-8 -*-
"""
Created on Fri Feb 18 09:59:35 2022

@author: onace
"""
"""
Name =input("what\'s your name? ")
age=20
is_new_patient=True
print(Name+" likes blue")
"""
"""
weight_lbs=int(input("what\'s your weight? "))
weight_kg=weight_lbs*0.45
print("your weight is "+str(weight_kg))
print("your weight is  ", weight_kg)


#indexation of caracters in python:
    
course='python for beginners'
print(course[0])
print(course[-1])
print(course[-2])
print(course[0:6])  #[start index, end index]
print(course[0:])
print(course[1:])

#Formated strings and methods;
first='Khadija'
last='Onaceur'
message=f'{first}[{last}] is a nice person'
print(message)
print(message.upper())


#if condition

price =10**6
good_credit=False

if good_credit:
    print("you need to put down 10%")
    print("down payment",0.1*price)
else:
    print("you need to put down 20%")
    print("down payment:",0.2*price)

    
 """ 
#operators
"""
name=input("what's your name? ")
if len(name)<3:
    print("Name must be at least 3 charachters!")
elif len(name)>50:
    print("Name can be a max of 50 characters!")
else:
    print("name looks good!")
   
weight=int(input("what's your weight? "))
choice=input("you want it on lbs (L) or kg (k)? ")
if choice =='L' or choice =='l':
   print(f"your wieight is  {weight*0.45} kg")
elif choice=='K' or choice =='k':
   print(f"your wieight is  {weight/0.45} lbs")
else:
    print("pls enter k or l to define the unit!!")

""" 
""" 
matrix=[[1,2,3],[5,6,7],[8,9,10]]
print(matrix)    

#Remove the duplicate in a list:
    #works only with  a duplicate of 2
list=[1,1,1,2,2,3,3,5,5,6,6,6,8,8,9,10]
print(list.count(1))
i=0
for item in list:
    i=list.count(item)
    print(f"{item}:{i}")
    if i>1:
        list.remove(item)
print(list)
""" 
list=[1,1,1,2,2,3,3,5,5,6,6,6,8,8,9,10]
new_list=[]
for item in list:
    if item not in new_list:
        new_list.append(item)
print(new_list)    
    


#dictionnary

phone=input("enter your phone plz! ")
phone_list={"1":"one",
            "2":"two",
            "3":"three",
            "4":"four",
            "5":"five",
            "6":"six",
            "7":"seven",
            "8":"eight",
            "9":"nine"}
output=""
for chr in phone:
   output+=phone_list.get(chr)
print(output)
























    
    
    
    
    
    
    
    
    