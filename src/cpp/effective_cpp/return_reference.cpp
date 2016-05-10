#include <iostream>
using namespace std;


class Rational
{
  public:
    Rational(int numerator = 0, int denominator = 1)
        : n(numerator), d(denominator) { }
    void display() const
    {
        cout << n << "/" << d << endl;
    }
  private:
    int n;
    int d;
    friend const Rational operator* (const Rational& lhs,
                                     const Rational& rhs);
};

inline const Rational operator* (const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}

void test()
{
    Rational r1(1, 2);
    Rational r2(3, 5);
    Rational r3 = r1 * r2;
    r3.display();
}

int main()
{
    test();
    return 0;
}

