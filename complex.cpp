#include <cstdio>
#include <iostream>

using namespace std;

class Complex
{
    private:
        double re;
        double im;
    public:
        Complex(double re = 0, double im = 0) : re(re), im(im) {};
        Complex(const Complex& other)
        {
            re = other.re;
            im = other.im;
        }
        double Re() const { return re; }
        double& Re() { return re; }
        double Im() const { return im; }
        double& Im() { return im; }
        Complex operator+(const Complex& other) const
        {
            return Complex(re+other.re, im+other.im);
        }
        Complex operator+=(const Complex& other)
        {
            re = re + other.re;
            im = im + other.im;
            return *this;
        }

};

ostream& operator<<(ostream& out, const Complex& number)
{
    return out << number.Re() << " + i * " << number.Im()  << endl;
}
istream& operator>>(istream& in, Complex& number){
    return in >> number.Re() >> number.Im();
}
int main()
{
    Complex digit_0;
    cin >> digit_0;
    cout << digit_0;
    Complex digit;
    digit = Complex(1, 2);
    cout << digit;
    Complex digit_2;
    digit_2 = Complex(2, 3);
    cout << digit + digit_2;
    digit += digit_2;
    digit += digit_2;
    cout << digit;
    return 0;
}