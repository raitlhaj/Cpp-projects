from typing import Mapping

mappingNum ={
    "0":"Zero",
    "1":"One",
    "2":"Two",
    "3":"Tree",
    "4":"Four",
    "5":"Five",
    "6":"Six",
    "7":"Seven",
    "8":"Eigth",
    "9":"Nine"
}

phoneNum=input("Enter your phone number ?:")
Output=""

for ch in phoneNum:
    Output+=mappingNum.get(ch,ch)+" "
    
print(Output)    