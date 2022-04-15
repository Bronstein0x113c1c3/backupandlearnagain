def triangle(tp1,tp2,tp3):
    x1,y1 = tp1[0],tp1[1]
    x2,y2 = tp2[0],tp2[1]
    x3,y3 = tp3[0],tp3[1]
    #return perimeter and area
    if abs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2)==0:
        print("invalid")
    else:
        #print the perimeter and area
        side1 = ((x1-x2)**2+(y1-y2)**2)**0.5
        side2 = ((x2-x3)**2+(y2-y3)**2)**0.5
        side3 = ((x1-x3)**2+(y1-y3)**2)**0.5
        print("chu vi:", side1+side2+side3) 
        print("dien tich:",abs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2))
triangle((1, 1), (1, 4), (5, 1))