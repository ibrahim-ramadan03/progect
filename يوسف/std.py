def calculate(hours, minutes, name):
    full_time = hours * 60 + minutes

    if full_time <= 9 * 60 + 30:   # 9:30
        print(f"Your Name: {name}")
        print("Degree: 95\n")
    elif full_time <= 9 * 60 + 40:   # 9:40
        print(f"Your Name: {name}")
        print("Degree: 80\n")
    elif full_time <= 9 * 60 + 45:   # 9:45
        print(f"Your Name: {name}")
        print("Degree: 60\n")
    else:
        print(f"Your Name: {name}")
        print("Degree: 50\n")

# القوائم (مثل vector في C++)
hours = [9, 9, 9]
minutes = [30, 40, 45]
names = ["Yousef", "Ibrahim", "Hossam"]

# حلقة لمعالجة كل طالب
for i in range(len(hours)):
    calculate(hours[i], minutes[i], names[i])
