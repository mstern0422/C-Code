#include <iostream>

using namespace std;

class Shape
{
public:
    virtual void DisplayShape() = 0;
    virtual void DisplayArea() = 0;
};

class Circle:public Shape{
protected:
    int radius;
public:
    Circle();
    void DisplayShape();
    void DisplayArea();
};

Circle::Circle() {
    radius = 6;
}

void Circle::DisplayShape(){
    float dist;
    for (int i = 0; i <= 2 * radius; i++) {
        for (int j = 0; j <= 2 * radius; j++) {
            dist = sqrt((i - radius) * (i - radius) +
                        (j - radius) * (j - radius));
            if (dist > radius - 0.5 && dist < radius + 0.5)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}


void Circle::DisplayArea(){
    cout << "Circle Area: " << 3.14159 * pow(radius, 2) << "\n";
}

class Triangle:public Shape{
protected:
    int base;
    int height;
public:
    Triangle();
    void DisplayShape();
    void DisplayArea();
};

Triangle::Triangle() {
    base = 6;
    height = 4;
}

void Triangle::DisplayShape(){
    for (int i = 1; i <= base; i++) {
        for (int j = 0; j < base - i; j++)
            cout << " ";

        for (int j = 1; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
}


void Triangle::DisplayArea(){
    cout << "Triangle Area: " << (base * height)/2 << "\n";
}

int main(){
    Circle myCircle;
    myCircle.DisplayShape();
    myCircle.DisplayArea();
    Triangle myTriangle;
    myTriangle.DisplayShape();
    myTriangle.DisplayArea();
    return 0;
}