#include <iostream>
#include <cstdlib>

#define _MYCOMPLEX_H_

using namespace std;


class myComplex {
public:
    myComplex(int real=0, int image=0) {
        realPart = real;
        imaginaryPart = image;
    }
    myComplex(const myComplex& number) {
        realPart = number.realPart;
        imaginaryPart = number.imaginaryPart;
    }
    int getRealPart() const {
        return realPart;
    }
    int getImaginaryPart() const {
        return imaginaryPart;
    }
    void setRealPart(int real) {
        realPart = real;
    }
    void setImaginaryPart(int imag) {
        imaginaryPart = imag;
    }
    void set(int real, int imag) {
        realPart = real;
        imaginaryPart = imag;
    }

    myComplex operator+(const myComplex& number) const {
        myComplex c;
        c.realPart = realPart + number.realPart;
        c.imaginaryPart = imaginaryPart + number.imaginaryPart;
        return c;
    }
    myComplex operator+(int value)const {
        myComplex c;
        c.realPart = realPart + value;
        c.imaginaryPart = imaginaryPart;
        return c;
    }
    myComplex& operator+=(const myComplex& number) {
        realPart += number.realPart;
        imaginaryPart += number.imaginaryPart;
        return *this;
    }
    myComplex& operator+=(int value) {
        realPart += value;
        return *this;
    }
    myComplex& operator++() {
        ++realPart;
        return (*this);
    }
    myComplex operator++(int) {
        myComplex tmp(*this);
        ++(*this);
        return tmp;
    }
    myComplex operator-(const myComplex& number) const {
        myComplex c;
        c.realPart = realPart - number.realPart;
        c.imaginaryPart = imaginaryPart - number.imaginaryPart;
        return c;
    }

    myComplex operator-(int value) const{
        myComplex c;
        c.realPart = realPart - value;
        c.imaginaryPart = imaginaryPart;
        return c;
    }
    myComplex& operator-=(const myComplex& number) {
        realPart -= number.realPart;
        imaginaryPart -= number.imaginaryPart;
        return *this;
    }
    myComplex& operator-=(int value) {
        realPart -= value;
        return *this;
    }
    myComplex& operator--() {
        --realPart;
        return *this;
    }
    myComplex operator--(int) {
        myComplex tmp(*this);
        --(*this);
        return tmp;
    }
    myComplex operator*(const myComplex& number) const {
        myComplex c;
        c.realPart = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
        c.imaginaryPart = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
        return c;
    }
    myComplex operator*(int value) {
        myComplex c;
        c.realPart = value * realPart;
        c.imaginaryPart = value * imaginaryPart;
        return c;
    }
    myComplex& operator*=(const myComplex& number) {
        *this = (*this) * number;
        return *this;
    }
    myComplex& operator*=(int value)  {
        realPart *= value;
        imaginaryPart *= value;
        return *this;
    }

    myComplex& operator=(const myComplex& number) {
        realPart = number.realPart;
        imaginaryPart = number.imaginaryPart;
        return *this;
    }
    myComplex& operator=(const int value) {
        realPart = value;
        imaginaryPart = 0;
        return *this;
    }
    bool operator==(const myComplex& number) const {
        return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart);
    }
    bool operator!=(const myComplex& number)const {
        return (realPart != number.realPart) || (imaginaryPart != number.imaginaryPart);
    }
    bool operator >(const myComplex& number)const {
        return norm() > number.norm();
    }
    bool operator <(const myComplex& number)const {
        return norm() < number.norm();
    }
    bool operator >=(const myComplex& number)const {
        return norm() >= number.norm();
    }
    bool operator <=(const myComplex& number)const {
        return norm() <= number.norm();
    }
    myComplex operator-() {
        return myComplex(-realPart, -imaginaryPart);
    }
    myComplex operator~() {
        return myComplex(realPart, -imaginaryPart);
    }

    friend myComplex operator+(int value, const myComplex& number);
    friend myComplex operator-(int value, const myComplex& number);
    friend myComplex operator*(int value, const myComplex& number);
    friend ostream& operator << (ostream & cout, const myComplex & number);
    friend istream& operator >> (istream& cin, myComplex& number);



private:
    int realPart;
    int imaginaryPart;
    int norm() const {
        return realPart * realPart + imaginaryPart * imaginaryPart;
    }
};

myComplex operator+(int value, const myComplex& number) {
    return myComplex(value) + number;
}
myComplex operator-(int value, const myComplex& number) {
    return myComplex(value) - number;
}

myComplex operator*(int value, const myComplex& number) {
    return number * value;
}

ostream& operator<<(ostream& cout, const myComplex& number) {
    cout << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return cout;
}
istream& operator>>(istream& cin, myComplex& number) {
    cin >> number.realPart >> number.imaginaryPart;
    return cin;
}


void testSimpleCase();
void testDataFromFile();


int main() {
    testSimpleCase();
    testDataFromFile();
    return 0;
}



void testSimpleCase()
{
    myComplex c0, c1(1), c2(2, 2);
    myComplex c3(c2);
    myComplex c4, c5, c6, c7, c8, c9;

    cout << c0 << endl << c1 << endl << c2 << endl;
    cout << c3 << endl;
    cout << c3 << endl;

    c3.set(3, 3);
    cout << c3 << endl;

    c3.setRealPart(4);
    cout << c3 << endl;

    c3.setImaginaryPart(4);
    cout << c3 << endl;
    c4 = c1 + c3;
    c5 = c1 - c3;
    c6 = c4 * c5;
    cout << c4 << endl << c5 << endl << c6 << endl;

    c7 = c6 + 2;
    c8 = c6 - 2;
    c9 = c6 * 2;
    cout << c7 << endl << c8 << endl << c9 << endl;
    c7 += c4;
    c8 -= c5;
    c9 *= c6;
    cout << c7 << endl << c8 << endl << c9 << endl;

    c7 += 2;
    c8 -= 2;
    c9 *= 2;
    cout << c7 << endl << c8 << endl << c9 << endl;

    cout << (c8 != c9) << " " << (c8 == c9) << endl;
    cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <=c9) << endl;
    c7 = c8 = c9;
    cout << (c8 != c9) << " " << (c8 == c9) << endl;
    cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <=c9) << endl;

    c7 = -myComplex(2, 3);
    c8 = (++c7) * 2;
    c9 = 2 * (c7++);
    cout << c7 << " " << c8 << " " << c9 << endl;

    c7 = ~myComplex(2, 3);
    c8 = (--c7) * 2;
    c9 = 2 * (c7--);
    cout << c7 << " " << c8 << " " << c9 << endl;

    c1 = myComplex(1, 2);
    c2 = myComplex(2, 3);
    c3 = myComplex(4, 5);
    c4 = myComplex(5, 6);
    c5 = myComplex(6, 7);
    c6 = 3;
    cout << -(c1 * c2) - 2 * c3 + ~c4 * c5 * 3 + 2 - c6 << endl;
}

void testDataFromFile()
{
    int numTestCases;

    cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        myComplex c1, c2, c3, c4;
        myComplex c5, c6, c7, c8, c9;

        cin >> c1 >> c2 >> c3 >> c4;

        cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
        cout << (2 + c1 + 3) + (2 - c2 - 3) * (2 * c3 * 3) - (2 * c4 - 3) <<
            endl;

        c5 = c6 = c7 = c8 = c1;
        cout << (c5 == c2) << " " << (c5 != c2) << endl;
        cout << (c5 > c2) << " " << (c5 >= c2) << " " << (c5 < c2) << " " <<
            (c5 <= c2) << endl;
        cout << (c5 == c6) << " " << (c5 != c6) << endl;
        cout << (c5 > c6) << " " << (c5 >= c6) << " " << (c5 < c6) << " " <<
            (c5 <= c6) << endl;

        c5 += c2;
        c6 -= c3;
        c7 *= c4;
        c8 = c2.getRealPart();
        c9 = c3.getImaginaryPart();
        cout << c5 << " " << c6 << " " << c7 << " " << c8 << " " << c9 << endl;

        c7 = -c6;
        c8 = (++c7) * 2;
        c9 = 2 * (c7++);
        cout << c7 << " " << c8 << " " << c9 << endl;

        c7 = ~c6;
        c8 = (++c7) * 2;
        c9 = 2 * (c7++);
        cout << c7 << " " << c8 << " " << c9 << endl;
    }
}