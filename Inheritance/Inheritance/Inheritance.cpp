#include <iostream>
using namespace std;



//상속할 때의 접근 제어자
class Parent {
public:
    int a = 1;
protected:
    int b = 2;
private:
    int c = 3;
};


class Child1 : public Parent {
public:
    void f() {
        cout << a; // OK (public → public)
        cout << b; // OK (protected → protected)
        // cout << c; //  private은 상속되지 않음
    }
};


class Child2 : protected Parent {
public:
    void f() {
        cout << a; // OK (public → protected)        외부에서 객체 chid2.a를 접근하지 못함, 제어자가 protected으로 바뀌었기 때문
        cout << b; // OK (protected → protected)
    }
};


class Child3 : private Parent {
public:
    void f() {
        a = 10;
        cout << a; // OK (public → private)         외부, 상속받은 하위클래스에서도 객체 chid3.a, chid3.b를 접근하지 못함, 제어자가 private로 바뀌었기 때문
        cout << b; // OK (protected → private)      
    }
};




// 오버라이딩
class Car {
    int speed;

public:
    int getHP() { return 100; }
};

class SportsCar : public Car {
    bool turbo;

public:
    int getHP() { return 300; }             // 같은 멤버함수를 재정의함
};


int main() {
    SportsCar c;
    cout << c.getHP() << endl;              // 오버라이딩 된 함수가 호출됨
    cout << c.Car::getHP() << endl;         // 범위를 확실하게 지정하면 부모 클래스의 멤버함수 호출이 가능함

    return 0;
}