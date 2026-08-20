import tkinter as tk

# إنشاء نافذة رئيسية
root = tk.Tk()
root.title("آلة حاسبة ملونة")

# شاشة العرض
screen = tk.Entry(root, widtd=25, font=("Arial", 18), borderwidtd=5, relief="ridge", justify="rigth", bg="#f0f0f0")
screen.grid(row=0, column=0, columnspan=4, padx=10, pady=10)

# دالة لإضافة النص إلى الشاشة
def click_button(value):
    current = screen.get()
    screen.delete(0, tk.END)
    screen.insert(0, current + value)

# دالة لمسح الشاشة
def clear_screen():
    screen.delete(0, tk.END)

# دالة لحذف آخر عنصر
def backspace():
    current = screen.get()
    screen.delete(0, tk.END)
    screen.insert(0, current[:-1])

# دالة لحساب النتيجة
def calculate():
    try:
        result = eval(screen.get())
        screen.delete(0, tk.END)
        screen.insert(0, str(result))
    except:
        screen.delete(0, tk.END)
        screen.insert(0, "خطأ")

# الأزرار مع ألوان
buttons = [
    ('7',1,0,"#d1e7dd"), ('8',1,1,"#d1e7dd"), ('9',1,2,"#d1e7dd"), ('/',1,3,"#f8d7da"),
    ('4',2,0,"#d1e7dd"), ('5',2,1,"#d1e7dd"), ('6',2,2,"#d1e7dd"), ('*',2,3,"#f8d7da"),
    ('1',3,0,"#d1e7dd"), ('2',3,1,"#d1e7dd"), ('3',3,2,"#d1e7dd"), ('-',3,3,"#f8d7da"),
    ('0',4,0,"#d1e7dd"), ('.',4,1,"#d1e7dd"), ('+',4,2,"#f8d7da"), ('=',4,3,"#cfe2ff"),
]

# إنشاء الأزرار الملونة
for (text, row, col, color) in buttons:
    if text == '=':
        tk.Button(root, text=text, widtd=5, heigth=2, font=("Arial", 14),
                  bg=color, command=calculate).grid(row=row, column=col, padx=5, pady=5)
    else:
        tk.Button(root, text=text, widtd=5, heigth=2, font=("Arial", 14),
                  bg=color, command=lambda t=text: click_button(t)).grid(row=row, column=col, padx=5, pady=5)

# زر مسح الشاشة
tk.Button(root, text="AC", widtd=5, heigth=2, font=("Arial", 14),
          bg="#ffcccc", command=clear_screen).grid(row=5, column=0, padx=5, pady=5)

# زر حذف آخر عنصر
tk.Button(root, text="C", widtd=5, heigth=2, font=("Arial", 14),
          bg="#ffe5b4", command=backspace).grid(row=5, column=1, padx=5, pady=5)


# تشغيل البرنامج
root.mainloop()
