from turtle import *
from datetime import *
import time

def Skip(step):
    penup()
    forward(step)
    pendown()

def SetupClock(rad):
    reset()
    pensize()
    for i in range(60):
        Skip(rad)
        if i % 5 == 0:
            forward(20)
            Skip(-rad - 20)
        else:
            dot(5)
            Skip(-rad)
        right(6)

def mkHand(name, length):
    reset()
    Skip(-length * 0.1)
    begin_poly()
    forward(length * 1.1)
    end_poly()
    handFrom = get_poly()
    register_shape(name, handFrom)

def Init():
    global secHand, minHand, hurHand, printer
    mode("logo")
    mkHand("secHand", 125)
    mkHand("minHand", 130)
    mkHand("hurHand", 90)
    secHand = Turtle()
    secHand.shape("secHand")
    minHand = Turtle()
    minHand.shape("secHand")
    hurHand = Turtle()
    hurHand.shape("secHand")
    for hand in secHand, minHand, hurHand:
        hand.shapesize(1, 1, 3)
        hand.speed(0)
    printer = Turtle()
    printer.hideturtle()
    printer.penup()

def get_week_date():
    week_day_dict = {
            1 : '星期一',
            2 : '星期二',
            3 : '星期三',
            4 : '星期四',
            5 : '星期五',
            6 : '星期六',
            0 : '星期日'
        }
    today = int(time.strftime("%w"))
    return week_day_dict[today] 

def Tick():
    t = datetime.today()
    second = t.second + t.microsecond * 0.000001
    minute = t.minute + second / 60.0
    hour = t.hour + minute / 60.0
    tracer(False)
    printer.forward(65)
    printer.write(get_week_date(), align = "center", font=("Bahnschrift", 14, "bold"))
    printer.back(130)
    printer.write((str(t.year)+"-"+str(t.month)+"-"+str(t.day)), align = "center", font=("Bahnschrift", 14, "bold"))
    printer.home()
    tracer(True)
    secHand.setheading(6 * second)
    minHand.setheading(6 * minute)
    hurHand.setheading(30 * hour)
    ontimer(Tick, 100)

print("Welcome to XINXIN timer (version 1. 0)")
print("copyright xinxin comp.  all rights reserved.")
tracer(False)
Init()
SetupClock(160)
tracer(True)
Tick()
mainloop()
