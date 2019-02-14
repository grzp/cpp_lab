#include <iostream>
#include <cmath>

using namespace std;

class Vector2D {
public:
    Vector2D(double x, double y) : x_{x}, y_{y} {}

    Vector2D(const Vector2D &other) {
        cout << "copy constructor: ";
        x_ = other.x_;
        y_ = other.y_;
    }

    Vector2D(Vector2D &&other) {
        cout << "move constructor: ";
        x_ = other.x_;
        y_ = other.y_;

        //
        other.x_ = 0;
        other.y_ = 0;
    }

    Vector2D& operator=(const Vector2D &other) {
        cout << "copy assignment: ";

        //check for self-assignment
        if (&other != this) {
            this->x_ = other.x_;
            this->y_ = other.y_;
        }

        return *this;
    }

    Vector2D& operator=(Vector2D &&other) {
        cout << "move assignment: ";

        //check for self-assignment
        if (&other != this) {
            this->x_ = other.x_;
            this->y_ = other.y_;

            //
            other.x_ = 0;
            other.y_ = 0;
        }

        return *this;
    }

    double length() const { return sqrt(x_ * x_ + y_ * y_); }
    double x() const { return x_; }
    double y() const { return y_; }

    Vector2D & operator+=(double x) {
        x_ += x;
        y_ += x;
        return *this;
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
    Vector2D res{v1.x() + v2.x(), v1.y() + v2.y()};
    return std::move(res);
    //return Vector2D {v1.x() + v2.x(), v1.y() + v2.y()};
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
//    Vector2D v3 = v1 + v2;
//    cout << "(v1 + v2) = " << (v1 + v2) << endl;
//    double ex = (v1 + v3) * v2;
//    cout << "(v1 + v3) * v2 = " << ex << endl;
//    cout << "v3 = " << v3 << endl;
//    v3 += 1;
//    //(v3 += 1) += 1;
//    v3.operator+=(1);
//    cout << "v3 = " << v3 << endl;
//    (v3 += v2) += v1;
//    v3.operator+=(v2);
//    cout << "v3 = " << v3 << endl;

    Vector2D v4{v1};
    cout << "v4 = " << v4 << endl;
    v4 = v2;
    v4 = std::move(v2);
    cout << "v4 = " << v4 << endl;
    return 0;
}


















//class Vector2D {
//public:
//    Vector2D(double x, double y) : x_{x}, y_{y} {}
//    double length() const { return sqrt(x_ * x_ + y_ * y_); }

//    Vector2D(const Vector2D &other) {
//        cout << "copy constructor" << endl;
//        this->x_ = other.x_;
//        this->y_ = other.y_;
//    }

//    // non-copy-and-swap assignment
//    Vector2D & operator=(const Vector2D &other) {
//        cout << "copy operator=" << endl;

//        // first, check for self-assignment
//        if (&other != this) {
//            this->x_ = other.x_;
//            this->y_ = other.y_;
//        }

//        return *this;
//    }

//    // Move constructor
//    Vector2D(Vector2D &&other) {
//        cout << "move constructor" << endl;

//        this->x_ = other.x_;
//        this->y_ = other.y_;
//        //this->x_ = std::move(other.x_);
//        //this->y_ = std::move(other.y_);

//        other.x_ = 0;
//        other.y_ = 0;
//    }

//    // Move assignment operator
//    Vector2D & operator=(Vector2D &&other) {
//        cout << "move operator=" << endl;

//        if (&other != this) {
//            this->x_ = other.x_;
//            this->y_ = other.y_;
//            //this->x_ = std::move(other.x_);
//            //this->y_ = std::move(other.y_);

//            other.x_ = 0;
//            other.y_ = 0;
//        }

//        return *this;
//    }
//private:
//    double x_;
//    double y_;
//    friend Vector2D operator+(const Vector2D &, const Vector2D &);
//    friend double operator*(const Vector2D &v1, const Vector2D &v2);
//    friend std::ostream &operator<<(std::ostream &, const Vector2D &v);
//};

//std::ostream &operator<<(std::ostream &os, const Vector2D &v)
//{
//    os << "[" << v.x_ << ", " << v.y_ << "]";
//    return os;
//}

//Vector2D operator+(const Vector2D &v1, const Vector2D &v2) {
//    Vector2D res{v1.x_ + v2.x_, v1.y_ + v2.y_};
//    //return std::move(res); // it prevents copy elision!
//    return res;
//    //return Vector2D {v1.x_ + v2.x_, v1.y_ + v2.y_};
//}

//double operator*(const Vector2D &v1, const Vector2D &v2) {
//    return v1.x_ * v2.x_ + v1.y_ * v2.y_;
//}

//int main()
//{
//    Vector2D v1{1,2};
//    Vector2D v2{3,4};
//    //Vector2D v3{v1};
//    //Vector2D v4 = v2;
//    Vector2D v5{0,0};
//    v5 = v1;
////    v5 = std::move(v1);
//    //Vector2D v4{std::move(v1)};
//    //cout << v1 << endl;

////    cout << (v1 + v2) << endl;
//    cout << (v1 * v2) << endl;
//    return 0;
//}
