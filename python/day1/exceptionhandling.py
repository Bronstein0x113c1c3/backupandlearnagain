try: 
    numerator = int(input("Enter a number to divide: "))
    denominator = int(input("Enter a number to divide by: "))
    result = numerator/denominator
except Exception as e:
    print(e)
else:
    print(result)
finally: 
    print("always excute without interruption")