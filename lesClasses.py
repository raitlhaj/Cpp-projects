class Point:
    def __init__(self,x,y):
        self.x=x
        self.y=y

    def move(self):
        print("move")

    def draw(self):
        print("draw")

    def walk():
      print('walk')

class Person:
    def __init__(self,firstName,lastName,age):
        self.firstName=firstName
        self.lastName=lastName
        self.age=age
        

    def talk(self):
        print("Hello man ")

    def myfirstmethod(name):
      print(f'Hello World again {name}')


def hits(number):
    return number*number;

def decompose( N,  k ):
    if N==1:
        print("END")
    else:
        if k>=2 and N%k!=0 and k<=N:
            k+=1
            decompose(N,k)   
        else: 
             print(k)
             decompose(N/k,k)   

def exp():
    try:
        age=int (input("age : "))
        rsik=1000/age
        print(age)
    except ZeroDivisionError:
        print("Age can't be ZERO !")
    except ValueError:
        print("ERROR")
class Mammal:
    def walk(self):
        print('walk')
class Dog(Mammal):
   pass
class Cat(Mammal):
    pass

#main
decompose(102,2)
#exp()
#point1=Point(2,3)
#point1.draw()
#point2=Point(10,20)
#point1.draw()
#point1.x=10
#point1.y=20
#p1=Person("Rachid","Onaceur",28)
#p1.talk()
#print(point1.x)
#print(point2.x)

d=Dog()
c=Cat()
d.walk()
c.walk()