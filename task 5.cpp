#include <iostream>
class ComplexNumber {
    double real, imag;
public:
    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}
    ComplexNumber operator+(const ComplexNumber& c) { return ComplexNumber(real + c.real, imag + c.imag); }
    ComplexNumber operator-(const ComplexNumber& c) { return ComplexNumber(real - c.real, imag - c.imag); }
    ComplexNumber operator*(const ComplexNumber& c) {
        return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
    bool operator==(const ComplexNumber& c) { return (real == c.real && imag == c.imag); }
    double magnitude() {
        double n = real * real + imag * imag;
        if (n == 0) return 0;
        double x = n;
        double y = 1;
        double e = 0.000001;
        while (x - y > e) {
            x = (x + y) / 2;
            y = n / x;
        }
        return x;
    }
    void display() { std::cout << real << " + " << imag << "i" << std::endl; }
};
int main() {
    ComplexNumber c1(3.0, 4.0), c2(1.0, 2.0);
    ComplexNumber sum = c1 + c2;
    ComplexNumber prod = c1 * c2;
    std::cout << "Sum: "; sum.display();
    std::cout << "Product: "; prod.display();
    std::cout << "Magnitude of c1: " << c1.magnitude() << std::endl;
    return 0;
}
