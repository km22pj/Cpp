#include <iostream>
#include <vector>

using namespace std;

class myPolynomial;

class myTerm {
public:
    myTerm(int c = 0, unsigned e = 0) : coeff(c), exp(e) {}
    myTerm(const myTerm& term) : coeff(term.coeff), exp(term.exp) {}
    void setCoeff(int c) {
        coeff = c;
    }
    void setExp(int e){
        exp = e;
    }
    int  getCoeff() const{
        return coeff;
    }
    int getExp()const {
        return exp;
    }

    myTerm ddx() const {
        myTerm t;
        if (exp == 0) {
            return t;
        }
        else {
            t.coeff = coeff * exp;
            t.exp = exp - 1;
            return t;
        }
    }

    bool operator ==(const myTerm& term) const{
        return (coeff == term.coeff) && (exp == term.exp);
    }
    bool operator != (const myTerm& term) const {
        return (coeff != term.coeff) || (exp != term.exp);
    }
    bool operator <(const myTerm& term) const {
        return exp < term.exp;
    }
    bool operator >(const myTerm& term) const {
        return exp > term.exp;
    }
    myTerm operator -() const {
        return myTerm(-coeff, exp);
    }


    friend ostream& operator << (ostream& cout, const myTerm& term);
    friend myPolynomial;

private:
    int coeff;
    unsigned exp;
};

ostream& operator <<(ostream& cout, const myTerm& term) {
    if (term.exp == 0) {
        if (term.coeff == 0) return cout;
        else return cout << term.coeff;
    }

    if (term.coeff == 1) cout << "x";
    else if (term.coeff == -1) cout << "-x";
    else cout << term.coeff << "x";
    if (term.exp == 1) return cout;
    else return cout << "^" << term.exp;
}






class myPolynomial {
public:
    myPolynomial(int c=0, unsigned e=0): coeff(c), exp(e){
        if (c == 0) {
            NumTerms = 0;
            degree = 0;
        }
        else {
            monopoly[0] = c;
            monopoly[1] = e;
            NumTerms = 1;
            degree = e;
        }
    }
    myPolynomial(int nTerms, int mono[]) {
        NumTerms = nTerms;
        for (int i = 0; i < 2 * NumTerms; i++) {
            monopoly[i] = mono[i];
        }

        for (int i = 0; i < NumTerms - 1; i++) {
            int maxIdx = i;
            for (int j = i + 1; j < NumTerms; j++) {
                if (monopoly[j * 2 + 1] > monopoly[maxIdx * 2 + 1]) {
                    maxIdx = j;
                }
            }
            if (maxIdx != i) {
                int temp1 = monopoly[i * 2];
                int temp2 = monopoly[i * 2 + 1];
                monopoly[i * 2] = monopoly[maxIdx * 2];
                monopoly[i * 2 + 1] = monopoly[maxIdx * 2 + 1];
                monopoly[maxIdx * 2] = temp1;
                monopoly[maxIdx * 2 + 1] = temp2;
            }
        }

        if (NumTerms > 0)
            degree = monopoly[1];
        else
            degree = 0;
    }
    myPolynomial(const myPolynomial& poly) {
        degree = poly.degree;
        coeff = poly.coeff;
        exp = poly.exp;
        NumTerms = poly.NumTerms;
        for (int i = 0; i < 2*NumTerms; i++) {
            monopoly[i] = poly.monopoly[i];
        }
    }

    long operator()(int x)const { 
        long sum = 0;
        for (int i = 0; i < NumTerms; i++) {
            int tmp = monopoly[i * 2];
            for (int j = 0; j < monopoly[i * 2 + 1]; j++) {
                tmp *= x;
            }
            sum += tmp;
        }
        return sum;
    }
    int getDegree()const {
        return degree;
    }
    unsigned getNumTerms() {
        return NumTerms;
    }
    void setCoeff(int c) {
        coeff = c;
    }
    myPolynomial ddx() const {
        myPolynomial p;
        p.NumTerms = 0;
        for (int i=0; i < NumTerms; i++) {
            myTerm t(monopoly[i * 2], monopoly[i * 2 + 1]);
            t = t.ddx();
            p.monopoly[i * 2] = t.coeff;
            p.monopoly[i * 2 + 1] = t.exp;
            p.NumTerms++;
        }
        return p;
    }


    bool operator==(const myPolynomial& poly)const {
        bool flag = true;
        for (int i = 0; i < NumTerms; i++) {
            myTerm a(monopoly[i * 2], monopoly[i * 2 + 1]);
            myTerm b(poly.monopoly[i * 2], poly.monopoly[i * 2 + 1]);
            if (a == b) continue;
            else { flag = false; break; }
        }
        return flag;
    }
    bool operator!=(const myPolynomial& poly)const {
        return  !((*this) == poly);
    }

    myPolynomial operator+(const myPolynomial& poly)const {
        myPolynomial p;
        int temp[100] = { 0 };
        int tempNumTerms = 0;
        int idx1 = 0, idx2 = 0;

        while (idx1 < NumTerms*2 && idx2 < poly.NumTerms*2) {
            if (monopoly[idx1+1] > poly.monopoly[idx2+1]) {
                if (monopoly[idx1] != 0) {
                    temp[tempNumTerms] = monopoly[idx1];
                    temp[tempNumTerms + 1] = monopoly[idx1+1];
                    tempNumTerms += 2;
                }
                idx1+=2;
            }
            else if (monopoly[idx1+1] < poly.monopoly[idx2+1]) {
                if (poly.monopoly[idx2] != 0) {
                    temp[tempNumTerms] = poly.monopoly[idx2];
                    temp[tempNumTerms + 1] = poly.monopoly[idx2+1];
                    tempNumTerms += 2;
                }
                idx2+=2;
            }
            else {
                if ((monopoly[idx1] + poly.monopoly[idx2]) != 0) {
                    temp[tempNumTerms] = monopoly[idx1] + poly.monopoly[idx2];
                    temp[tempNumTerms + 1] = monopoly[idx1+1];
                    tempNumTerms += 2;
                }
                idx1+=2; idx2+=2;
            }
        }
        if (idx1 < NumTerms*2) {
            while (idx1 < NumTerms * 2) {
                if (monopoly[idx1] != 0) {
                    temp[tempNumTerms] = monopoly[idx1];
                    temp[tempNumTerms + 1] = monopoly[idx1+1];
                    tempNumTerms += 2;
                }
                idx1 += 2;
            }
        }
        if (idx2 < NumTerms * 2) {
            while (idx2 < NumTerms * 2) {
                if (poly.monopoly[idx2] != 0) {
                    temp[tempNumTerms] = poly.monopoly[idx2];
                    temp[tempNumTerms + 1] = poly.monopoly[idx2+1];
                    tempNumTerms += 2;
                }
                idx2 += 2;
            }
        }

        for (int i = 0; i < tempNumTerms; i++) {
            p.monopoly[i] = temp[i];
        }
        //for (int i = tempNumTerms; i < 2 * 50; i++) {
        //    p.monopoly[i] = 0;
        //}
        p.NumTerms = tempNumTerms / 2;

        return p;

    }
    myPolynomial operator-(const myPolynomial& poly)const {

        myPolynomial p;
        int temp[100] = { 0 };
        int tempNumTerms = 0;
        int idx1 = 0, idx2 = 0;

        while (idx1 < NumTerms * 2 && idx2 < poly.NumTerms * 2) {
            if (monopoly[idx1+1] > poly.monopoly[idx2+1]) {
                if (monopoly[idx1] != 0) {
                    temp[tempNumTerms] = monopoly[idx1];
                    temp[tempNumTerms + 1] = monopoly[idx1+1];
                    tempNumTerms += 2;
                }
                 idx1 += 2;
            }
            else if (monopoly[idx1+1] < poly.monopoly[idx2+1]) {
                if (poly.monopoly[idx2] != 0) {
                    temp[tempNumTerms] = -poly.monopoly[idx2];
                    temp[tempNumTerms + 1] = poly.monopoly[idx2+1];
                    tempNumTerms += 2;
                }
                idx2 += 2;
            }
            else {
                if ((monopoly[idx1] - poly.monopoly[idx2]) != 0) {
                    temp[tempNumTerms] = monopoly[idx1] - poly.monopoly[idx2];
                    temp[tempNumTerms + 1] = monopoly[idx1+1];
                    tempNumTerms += 2;
                }
                idx1 += 2; idx2 += 2;
            }
        }
        if (idx1 < NumTerms * 2) {
            while (idx1 < NumTerms * 2) {
                if (monopoly[idx1] != 0) {
                    temp[tempNumTerms] = monopoly[idx1];
                    temp[tempNumTerms + 1] = monopoly[idx1+1];
                    tempNumTerms += 2;
                }
                idx1 += 2;
            }
        }
        if (idx2 < NumTerms * 2) {
            while (idx2 < NumTerms * 2) {
                if (poly.monopoly[idx2] != 0) {
                    temp[tempNumTerms] = -poly.monopoly[idx2];
                    temp[tempNumTerms + 1] = poly.monopoly[idx2+1];
                    tempNumTerms += 2;
                }
                idx2 += 2;
            }
        }
        for (int i = 0; i < tempNumTerms; i++) {
            p.monopoly[i] = temp[i];
        }
        //for (int i = tempNumTerms; i < 2 * 50; i++) {
        //    p.monopoly[i] = 0;
        //}
        p.NumTerms = tempNumTerms / 2;
        return p;
    }

    myPolynomial operator*(const myPolynomial& poly)const {
        myPolynomial p;
        int temp[200] = { 0, 0 };
        int tempNumTerms = 0;

        for (unsigned i = 0; i < NumTerms; i++) {
            int a_coeff = monopoly[i * 2];
            int a_exp = monopoly[i * 2 + 1];

            for (unsigned j = 0; j < poly.NumTerms; j++) {
                int b_coeff = poly.monopoly[j * 2];
                int b_exp = poly.monopoly[j * 2 + 1];

                int new_coeff = a_coeff * b_coeff;
                int new_exp = a_exp + b_exp;
                if (new_coeff == 0) continue;
                bool merged = false;
                for (int k = 0; k < tempNumTerms; k++) {
                    if (temp[k * 2 + 1] == new_exp) {
                        temp[k * 2] += new_coeff;
                        merged = true;
                        break;
                    }
                }
                if (!merged) {
                    temp[tempNumTerms * 2] = new_coeff;
                    temp[tempNumTerms * 2 + 1] = new_exp;
                    tempNumTerms++;
                }
            }
        }
        p.NumTerms = 0;
        for (int i = 0; i < tempNumTerms; i++) {
            if (temp[i * 2] != 0) {
                p.monopoly[p.NumTerms * 2] = temp[i * 2];
                p.monopoly[p.NumTerms * 2 + 1] = temp[i * 2 + 1];
                p.NumTerms++;
            }
        }

        return p;
    }

    myPolynomial operator*(int value)const {
        myPolynomial p;
        if (value == 0) {
            p.NumTerms = 1;
            p.monopoly[0] = 0;
            p.monopoly[1] = 0;
            p.degree = 0;
            return p;
        }
        p.NumTerms = NumTerms;
        for (int i = 0; i < NumTerms; i++) {
            p.monopoly[i * 2] = monopoly[i * 2]*value;
            p.monopoly[i * 2 + 1] = monopoly[i * 2 + 1];
        }
        return p;
    }

    myPolynomial& operator+=(const myPolynomial& poly){
        (*this) = (*this) + poly;
        return *this;
    }
    myPolynomial& operator-=(const myPolynomial& poly){
        (*this) = (*this) - poly;
        return *this;
    }
    myPolynomial& operator*=(const myPolynomial& poly){
        (*this) = (*this) * poly;
        return *this;
    }

    myPolynomial& operator*=(int value){
        (*this) = (*this)*value;
        return *this;
    }

    myPolynomial operator-() const{
        myPolynomial p;
        p.NumTerms = NumTerms;
        for (int i = 0; i < NumTerms; i++) {
            p.monopoly[i * 2] = -monopoly[i * 2];
            p.monopoly[i * 2 + 1] = monopoly[i * 2 + 1];
        }
        return p;
    }


    friend myPolynomial operator*(int value, const myPolynomial& poly);
    friend ostream& operator << (ostream& cout, const myPolynomial& poly);

    static const myPolynomial ZERO;
    static const myPolynomial ONE;
    static const myPolynomial X;


private:
    int degree;
    int coeff;
    unsigned exp;
    unsigned NumTerms;
    int monopoly[100] = {0,0};
};


myPolynomial operator*(int value, const myPolynomial& poly) {
    myPolynomial p;
    if (value == 0) {
        p.NumTerms = 1;
        p.monopoly[0] = 0;
        p.monopoly[1] = 0;
        p.degree = 0;
        return p;
    }
    p.NumTerms = poly.NumTerms;
    for (int i = 0; i < poly.NumTerms; i++) {
        p.monopoly[i * 2] = poly.monopoly[i * 2] * value;
        p.monopoly[i * 2 + 1] = poly.monopoly[i * 2 + 1];
    }
    return p;
}

ostream& operator << (ostream& cout, const myPolynomial& poly) {
    if (poly == myPolynomial::ZERO) return cout << 0;
    if (poly == myPolynomial::ONE) return cout << 1;
    if (poly == myPolynomial::X) return cout << "x";

    for (int i = 0; i < poly.NumTerms; i++) {
        if (poly.monopoly[i * 2] == 0) continue;
        myTerm t(poly.monopoly[i * 2], poly.monopoly[i * 2 + 1]);
        cout << t;
        if (i != (poly.NumTerms - 1)) {
            if (poly.monopoly[(i + 1) * 2] > 0) cout << "+";
            else if (poly.monopoly[(i + 1) * 2] == 0) continue;
        }
    }
    return cout;
}

const myPolynomial myPolynomial::ZERO(0);
const myPolynomial myPolynomial::ONE(1, (unsigned)0);
const myPolynomial myPolynomial::X(1, 1);


    
void testSimpleCase();
void testDataFromFile();


int main() {
    testSimpleCase();
    testDataFromFile();
    return 0;
}




void testSimpleCase()
{
    cout << myPolynomial::ZERO << endl;
    cout << myPolynomial::ONE << endl;
    cout << myPolynomial::X << endl;

    myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);

    int testData4[10] = { 1, 0, 1, 1, 1, 2, 1, 3, 1, 4 };
    int testData5[10] = { -1, 0, -1, 1, -1, 2, -1, 3, -1, 4 };
    int testData6[10] = { 1, 0, -1, 1, 1, 2, -1, 3, 1, 4 };
    int testData7[10] = { 2, 2, 5, 5, 4, 4, 1, 1, 3, 3 };
    int testData8[12] = { 1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 100, 1, 0 };

    myPolynomial p4(5, testData4);
    myPolynomial p5(5, testData5);
    myPolynomial p6(5, testData6);
    myPolynomial p7(5, testData7);
    myPolynomial p8(6, testData8);
    myPolynomial p9(p7);

    cout << p0 << endl << p1 << endl << p2 << endl;
    cout << p4 << endl << p8 << endl;

    cout << p9 << endl;

    cout << p8.getDegree() << " " << p8.getNumTerms() << endl;

    cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
    cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;

    cout << (p7 == p9) << " " << (p7 != p9) << endl;

    cout << myPolynomial::ZERO.ddx() << endl;
    cout << myPolynomial::ONE.ddx() << endl;
    cout << myPolynomial::X.ddx() << endl;
    cout << p4.ddx() << endl;
    cout << p8.ddx() << endl;

    cout << -myPolynomial::ZERO << endl;
    cout << -p4 << endl;

    cout << 3 * myPolynomial::ZERO << endl;
    cout << 3 * myPolynomial::ONE << endl;
    cout << myPolynomial::X * 3 << endl;
    cout << 3 * p4 << " " << p4 * 3 << endl;
    cout << 0 * p5 << " " << p5 * 5 << endl;
    cout << p4 + p5 << endl;
    cout << p6 - p7 << endl;
    cout << p8 * p7 << endl;
    cout << p8 - p8 << endl;
    cout << p4 - p5 << endl;
    cout << p4 * p5 << endl;
    myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
    tmp4 = tmp3 = tmp2 = tmp1;
    cout << (tmp4 *= 3) << endl;
}



void testDataFromFile() {
    int numTestCases;

    cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        int numTerms, terms[100] = { 0,0 };


        cin >> numTerms;
        for (int j = 0; j < numTerms; j++)
            cin >> terms[2 * j] >> terms[2 * j + 1];

        myPolynomial p1(numTerms, terms);

        cin >> numTerms;
        for (int j = 0; j < numTerms; j++)
            cin >> terms[2 * j] >> terms[2 * j + 1];

        myPolynomial p2(numTerms, terms);

        cout << p1 << endl << p2 << endl;
        cout << p1.getDegree() << " " << p2.getNumTerms() << endl;
        cout << p1.ddx() << endl << p2.ddx() << endl;
        cout << (p1 == p2) << " " << (p1 != p2) << endl;
        cout << p1(1) << endl;
        

        myPolynomial p12 = p1 * 2 * p2;
        myPolynomial p11 = 3 * p1;
        myPolynomial p22 = 2 * p2;
        cout << -p22 + p12 + p11 - p1 << endl;

        myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE), p5(myPolynomial::X);
        p3 += p1;
        p4 -= p2;
        p5 *= p4;
        p5 *= 2;

        cout << p5 << endl;
    }
}
