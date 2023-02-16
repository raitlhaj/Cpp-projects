#typo
try:
 age=int(input("Enter your age :"))
 print(age)
except ValueError:
    print("Invalid value ")
    
#dividing by Zero
try :
 a=int(input("Entrer a :"))
 b=int(input("Entrer b :"))
 print("a/b="+a/b)

except ZeroDivisionError:
    print("Invalid value ")
