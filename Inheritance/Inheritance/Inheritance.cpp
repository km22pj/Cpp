#include <iostream>
using namespace std;



//����� ���� ���� ������
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
        cout << a; // OK (public �� public)
        cout << b; // OK (protected �� protected)
        // cout << c; //  private�� ��ӵ��� ����
    }
};


class Child2 : protected Parent {
public:
    void f() {
        cout << a; // OK (public �� protected)        �ܺο��� ��ü chid2.a�� �������� ����, �����ڰ� protected���� �ٲ���� ����
        cout << b; // OK (protected �� protected)
    }
};


class Child3 : private Parent {
public:
    void f() {
        a = 10;
        cout << a; // OK (public �� private)         �ܺ�, ��ӹ��� ����Ŭ���������� ��ü chid3.a, chid3.b�� �������� ����, �����ڰ� private�� �ٲ���� ����
        cout << b; // OK (protected �� private)      
    }
};




// �������̵�
class Car {
    int speed;

public:
    int getHP() { return 100; }
};

class SportsCar : public Car {
    bool turbo;

public:
    int getHP() { return 300; }             // ���� ����Լ��� ��������
};


int main() {
    SportsCar c;
    cout << c.getHP() << endl;              // �������̵� �� �Լ��� ȣ���
    cout << c.Car::getHP() << endl;         // ������ Ȯ���ϰ� �����ϸ� �θ� Ŭ������ ����Լ� ȣ���� ������

    return 0;
}