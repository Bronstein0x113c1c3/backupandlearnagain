students = [("Squidward","F",60),
            ("Sandy","A",33),
            ("Patrick","D",36)]
students.sort(key=lambda student:student[1]) 
for i in students:
    print(i)