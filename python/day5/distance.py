def distance(tp1,tp2):
    x1,y1 = tp1[0],tp1[1]
    x2,y2 = tp2[0],tp2[1]
    return ((x1-x2)**2 + (y1-y2)**2)**0.5
print(distance((1,4),(5,1)))