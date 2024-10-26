from turtle import *
import Snakeh as s
from random import randrange
#variable zone
snake = [[0,0],[10,0],[20,0],[30,0],[40,0],[50,0]]
apple_x = randrange(-20,20) * 10
apple_y = randrange(-20,20) * 10
aim_x = 10
aim_y = 0
sc = 0
#function zone
def change(x,y):
    global aim_x,aim_y
    aim_x = x
    aim_y = y

def inside():
    if -210<=snake[-1][0]<=200 and -210<=snake[-1][1]<=200:
        return True
    else:
        return False
    
def gameLoop():
    global apple_x, apple_y
    clear()
    snake.append([snake[-1][0]+aim_x, snake[-1][1]+aim_y])
    if not inside():
        return
        print("Game Over")
    if snake[-1][0] != apple_x or snake[-1][1] != apple_y:
        snake.pop(0)
    else:
        apple_x = randrange(-20, 20) * 10
        apple_y = randrange(-20, 20) * 10
    for i in range(len(snake)):
        s.square(snake[i][0], snake[i][1], 10, "black")
    s.square(apple_x, apple_y, 10, "red")
    ontimer(gameLoop, 300) 
    update()
#main zone
setup(420, 420, 0, 0)
hideturtle()
tracer(False)
listen()
onkey(lambda: change(0,10),"w")
onkey(lambda: change(0,-10),"s")
onkey(lambda: change(-10,0),"a")
onkey(lambda: change(10,0),"d")
gameLoop()
done()
