#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}   //default constructor  and this is a iniliazed list giving the values to real and imag inspecific 

    Complex(double r, double i) : real(r), imag(i) {}  //parameterized constructor  

    // Overloaded + operator to add two complex numbers
    Complex operator+(const Complex& other) const {                          //syntax: return_type operater operator_to_be_overloaded(arg)
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloaded * operator to multiply two complex numbers
    Complex operator*(const Complex& other) const {
        double newReal = real * other.real - imag * other.imag;
        double newImag = real * other.imag + imag * other.real;
        return Complex(newReal, newImag);
    }

    // Overloaded << operator to print a complex number
    //friend function allows to access the private members of class.The return type of the function is a reference to std::ostream. 
    //This allows you to chain multiple << operators.
friend std::ostream& operator<<(std::ostream& os, const Complex& num) {   //os ha ostream cha object create kela
        os << num.real;                //just like cout we use os
        if (num.imag >= 0) {
            os << " + " << num.imag << "i";
        } else {
            os << " - " << -num.imag << "i";
        }
        return os;
    }

    // Overloaded >> operator to read a complex number
    friend std::istream& operator>>(std::istream& is, Complex& num) {  //is ha istream cha object ahe
        std::cout << "Enter real part: ";
        is >> num.real;
        std::cout << "Enter imaginary part: ";
        is >> num.imag;
        return is;
    }
};

int main() {
    Complex num1, num2;

    std::cout << "Enter the first complex number:\n";
    std::cin >> num1;

    std::cout << "Enter the second complex number:\n";
    std::cin >> num2;

    Complex sum = num1 + num2;
    Complex product = num1 * num2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}
