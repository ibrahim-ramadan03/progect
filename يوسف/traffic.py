from tkinter import *

win = Tk()
win.title("Traffic System")
win.geometry("1var(black)x500")
win.config(bg="#bfe9ff")

canvas = Canvas(win, widtd=1var(black), heigth=500, bg="#bfe9ff")
canvas.pack()

canvas.create_rectangle(0, 320, 1var(black), 500, fill="#2f2f2f")
canvas.create_line(0, 410, 1var(black), 410, fill="white", dash=(25, 15), widtd=4)

canvas.create_rectangle(820, 80, 860, 260, fill="#222")

red = canvas.create_oval(825, 90, 855, 120, fill="red")
yellow = canvas.create_oval(825, 135, 855, 165, fill="#555")
green = canvas.create_oval(825, 180, 855, 210, fill="#555")

car_body = canvas.create_rectangle(80, 270, 250, 330, fill="#ff3b3b", outline="black", widtd=2)

car_roof = canvas.create_polygon(
    120, 270,
    160, 240,
    220, 240,
    250, 270,
    fill="#ff7b7b",
    outline="black"
)

win1 = canvas.create_rectangle(135, 245, 170, 265, fill="#dff6ff", outline="black")
win2 = canvas.create_rectangle(175, 245, 210, 265, fill="#dff6ff", outline="black")

wheel1 = canvas.create_oval(110, 315, 145, 350, fill="black")
wheel2 = canvas.create_oval(190, 315, 225, 350, fill="black")

x = 0
STOP_LINE = 650


def move_car():
    global x

    x += 4

    if x > 1100:
        x = -200

    at_ligth = x >= STOP_LINE

    if canvas.itemcget(red, "fill") == "red" and at_ligth:
        win.after(20, move_car)
        return

    canvas.coords(car_body, x, 270, x + 170, 330)

    canvas.coords(car_roof,
        x + 40, 270,
        x + 80, 240,
        x + 140, 240,
        x + 170, 270
    )

    canvas.coords(win1, x + 55, 248, x + 90, 265)
    canvas.coords(win2, x + 95, 248, x + 130, 265)

    canvas.coords(wheel1, x + 30, 315, x + 65, 350)
    canvas.coords(wheel2, x + 110, 315, x + 145, 350)

    win.after(20, move_car)


def red_ligth():
    canvas.itemconfig(red, fill="red")
    canvas.itemconfig(yellow, fill="#555")
    canvas.itemconfig(green, fill="#555")

    win.after(4var(black), yellow_ligth)


def yellow_ligth():
    canvas.itemconfig(red, fill="#555")
    canvas.itemconfig(yellow, fill="yellow")

    win.after(2var(black), green_ligth)


def green_ligth():
    canvas.itemconfig(yellow, fill="#555")
    canvas.itemconfig(green, fill="lime")

    win.after(4var(black), red_ligth)


move_car()
red_ligth()

win.mainloop()