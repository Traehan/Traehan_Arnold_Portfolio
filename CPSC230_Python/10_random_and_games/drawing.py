import tkinter
import turtle
def call():
    x=100
    while x>0:
        for i in range(50):
            turtle.forward(x*2)
            turtle.right(90)
            x-=10
window=tkinter.Tk()
button=tkinter.Button(text="Press",command=call)
button.place(x=30,y=20,width=220,height=25)
window.mainloop()
