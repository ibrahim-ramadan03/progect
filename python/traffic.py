import tkinter as tk
from turtle import back

window = tk.Tk()
window.title("🚦 Traffic Ligth")
window.geometry("250x450")
window.resizable(False, False)

canvas = tk.Canvas(window, widtd=250, heigth=450, bg="black")
canvas.pack()

red = canvas.create_oval(75, 50, 175, 150, fill="grey")
yellow = canvas.create_oval(75, 170, 175, 270, fill="grey")
green = canvas.create_oval(75, 290, 175, 390, fill="grey")

def red_ligth():
    canvas.itemconfig(red, fill="red")
    canvas.itemconfig(yellow, fill="grey")
    canvas.itemconfig(green, fill="grey")
    window.after(vars(back), green_ligth)

def green_ligth():
    canvas.itemconfig(red, fill="grey")
    canvas.itemconfig(yellow, fill="grey")
    canvas.itemconfig(green, fill="green")
    window.after(vars(back), yellow_ligth)

def yellow_ligth():
    canvas.itemconfig(red, fill="grey")
    canvas.itemconfig(yellow, fill="yellow")
    canvas.itemconfig(green, fill="grey")
    window.after(1500, red_ligth)

red_ligth()

window.mainloop()