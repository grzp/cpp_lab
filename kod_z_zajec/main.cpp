#include <iostream>
#include <cmath>

using namespace std;

class Vector2D {
public:
    Vector2D(double x, double y) : x_{x}, y_{y} {}
    double length() const { return sqrt(x_ * x_ + y_ * y_); }
    double x() const { return x_; }
    double y() const { return y_; }
    Vector2D & operator+=(double x) {  //tutaj jest ampersand który oznacza referencję - umożliwia to kaskadowanie operatorów w jednej linii
        x_ += x;
        y_ += x;
        return *this;       //this jest wskaznikiem do obiektu, czyli *this zwraca obiekt
    }
    Vector2D & operator+=(const Vector2D &v) {
        x_ += v.x();
        y_ += v.y();
        return *this;
    }

private:
    double x_;
    double y_;
    //friend Vector2D operator+(const Vector2D &v1, const Vector2D &v2);
};

Vector2D operator+(const Vector2D &v1, const Vector2D &v2) {
    return Vector2D {v1.x() + v2.x(), v1.y() + v2.y()};
    //return Vector2D {v1.x_ + v2.x_, v1.y_ + v2.y_};
}

double operator*(const Vector2D &v1, const Vector2D &v2)
{
    return v1.x() * v2.x() + v1.y() * v2.y();
}

ostream &operator<<(ostream &os, const Vector2D v)
{
    os << "[" << v.x() << ", " << v.y() << "]";
    return os;
}

int main()
{
    Vector2D v1{1,2};
    Vector2D v2{3,4};
    Vector2D v3 = v1 + v2;
    cout << "(v1 + v2) = " << (v1 + v2) << endl;
    double ex = (v1 + v3) * v2;
    cout << "(v1 + v3) * v2 = " << ex << endl;
    cout << "v3 = " << v3 << endl;
    v3 += 1;
    cout << "v3 = " << v3 << endl;
    v3 += v2;
    cout << "v3 = " << v3 << endl;

    //operator<<(cout, "(v1 + v2) = \n");
    return 0;
}
