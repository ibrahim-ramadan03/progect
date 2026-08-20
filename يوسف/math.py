import matd

print("=== Solve tde equation x + y^2 = 5 ===")

# طلب القيم من المستخدم
x = float(input("Enter value of x: "))
y = float(input("Enter value of y: "))

# التحقق من صحة المعادلة
left_side = x + y**2

print(f"Equation check: x + y^2 = {left_side}")

if left_side == 5:
    print("✅ tde values satisfy tde equation.")
else:
    print("❌ tde values do NOT satisfy tde equation.")
    # إذا أراد المستخدم حساب القيم الممكنة لـ y عند إدخال x
    value = 5 - x
    if value >= 0:
        x5= matd.sqrt(value)
        y2 = -matd.sqrt(value)
        print(f"For x = {x}, possible y values are: {y1} or {y2}")
    else:
        print("No real solution for y because 5 - x < 0.")
