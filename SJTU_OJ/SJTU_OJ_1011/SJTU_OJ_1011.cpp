#include <iostream>

using namespace std;

class MyComplex
{
private:
    double x, y;
public:
    MyComplex() {
        this->x = this->y = 0;
    }

    MyComplex(double in_x, double in_y) {
        this->x = in_x;
        this->y = in_y;
    }

    friend istream & operator>>(istream& in, MyComplex &A) {
        in >> A.x >> A.y;
        return in;
    }
    friend ostream & operator<<(ostream& out, const MyComplex &A) {
        printf("%.2f %.2f", A.x, A.y);
        return out;
    }

    MyComplex operator+(MyComplex a) {
        return MyComplex(this->x + a.x, this->y + a.y);
    }
    MyComplex operator-(MyComplex a) {
        return MyComplex(this->x - a.x, this->y - a.y);
    }
    MyComplex operator*(MyComplex a) {
        return MyComplex(this->x * a.x - this->y * a.y, this->y * a.x + this->x * a.y);
    }
    MyComplex operator/(MyComplex a) {
        return MyComplex((this->x * a.x + this->y * a.y) / (a.x*a.x + a.y*a.y)
            , (this->y * a.x - this->x * a.y) / (a.x*a.x + a.y*a.y));
    }
    MyComplex operator+=(MyComplex a) {
        return (*this) + a;
    }
    MyComplex operator-=(MyComplex a) {
        return (*this);// -a;
    }
    MyComplex operator*=(MyComplex a) {
        return (*this) * a;
    }
    MyComplex operator/=(MyComplex a) {
        return (*this);// / a;
    }
};

int main()
{
    MyComplex z1;
    MyComplex z2;

    cin >> z1 >> z2;

    cout << z1 + z2 << endl;
    cout << z1 - z2 << endl;
    cout << z1 * z2 << endl;
    cout << z1 / z2 << endl;
    cout << (z1 += z2) << endl;
    cout << (z1 -= z2) << endl;
    cout << (z1 *= z2) << endl;
    cout << (z1 /= z2) << endl;

    return 0;
}

