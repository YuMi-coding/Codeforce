import math
import sys

def read_input():
    [input_1,input_2,input_3] = sys.stdin.readlines()
    x1,y1=input_1.strip().split()
    x2,y2=input_2.strip().split()
    x3,y3=input_3.strip().split()
    x1 = float(x1)
    x2 = float(x2)
    x3 = float(x3)
    y1 = float(y1)
    y2 = float(y2)
    y3 = float(y3)
    return x1,x2,x3,y1,y2,y3

def outer_center(x1,x2,x3,y1,y2,y3):
    A1=2*(x2-x1)
    B1=2*(y2-y1)
    C1=x2*x2+y2*y2-x1*x1-y1*y1
    A2=2*(x3-x2)
    B2=2*(y3-y2)
    C2=x3*x3+y3*y3-x2*x2-y2*y2

    x = ((C1*B2)-(C2*B1))/((A1*B2)-(A2*B1))
    y = ((A1*C2)-(A2*C1))/((A1*B2)-(A2*B1))

    return x,y

def get_degree(x1,x2,x3,y1,y2,y3):
    A = math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
    B = math.sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2))
    C = math.sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3))


    c = math.acos((A**2 + B**2 - C**2)/(2 * A * B)) * 180 /math.pi
    b = math.acos((A**2 + C**2 - B**2)/(2 * A * C)) * 180 /math.pi
    a = math.acos((B**2 + C**2 - A**2)/(2 * C * B)) * 180 /math.pi

    return a,b,c

def find_gcd(a,b,c):
    a = int(round(a))
    b = int(round(b))
    c = int(round(c))
    temp1 = math.gcd(a,b)
    temp2 = math.gcd(temp1,c)
    return temp2

def determine_angles(gcd):
    return int(180/gcd)

def get_radius(x0,y0,x1,y1):
    return math.sqrt((x0-x1)**2+(y0-y1)**2)

if __name__ == "__main__":
    eps = 0.001 # Accuracy adjustment
    DEBUG = 0
    x1,x2,x3,y1,y2,y3 = read_input()
    if DEBUG == 1:
        print("success!")
    x,y = outer_center(x1,x2,x3,y1,y2,y3)
    if DEBUG == 1:
        print("x=",x,"y=",y)
    a,b,c = get_degree(x1,x2,x3,y1,y2,y3)
    if DEBUG == 1:
        print("angle A=",a,"angle B=",b,"angle C=",c)
    r = get_radius(x,y,x1,y1)
    if DEBUG == 1:
        print("r=",r)
    if abs(a-round(a))>eps or abs(b-round(b))>eps or abs(c-round(c))>eps:# cannot use direct round for now
        smallest = min(a,min(b,c))
        largest = max(a,max(b,c))
        N = 0
        for i in range(1,2000):
            if abs(smallest*i-round(smallest*i))<eps and (smallest*i-180)>-eps: # potentially find the N
                if abs((smallest * i/180) - round (smallest*i/180)) <eps:
                    gcd_angle = math.gcd(int(round(largest*i)),int(round(smallest*i)))
                    if DEBUG == 1:
                        print("gcd_angle=",gcd_angle)
                    if  gcd_angle == int(round(smallest*i)):
                        N = i
                        if DEBUG == 1:
                            print("hit")
                        break
                    else:
                        t = 180/gcd_angle*i
                        if DEBUG == 1:
                            print("miss", 180/gcd_angle*i)
                        for j in range(1,20):
                            if abs(t*j-round(t*j))<eps:
                                N = int(t*j)
                                break
                        break
        if N == 0:
            N = 46
        if DEBUG == 1:
            print("Using alternative method, N =",N)

    else:
        gcd = find_gcd(a,b,c)
        if DEBUG == 1:
            print("gcd=",gcd)
        N = determine_angles(gcd)
        if DEBUG == 1:
            print("N=",N)
    
    area = 0.5*N*r*r*math.sin(2/N*math.pi)
    print("%.6f"%area)

