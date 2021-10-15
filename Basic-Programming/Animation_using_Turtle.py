import turtle

turtle.bgcolor("lightblue")
turtle.pensize(1.5)
turtle.speed(0.75)
color = ["red","blue","green","yellow"]
for k in range(9):
    for i in color:
        turtle.color(i)
        turtle.circle(100)
        turtle.left(10)

turtle.mainloop()
