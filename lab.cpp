#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

double f(double a, double b, double c) {
    double denominator = sin(pow(a * b + pow(c, 2), 2));
    if (denominator == 0) {
        throw runtime_error("Ділення на нуль у функції f!");
    }
    return (a + b + c) / denominator;
}

double calculate(double s, double t) {
    double f1 = f(t, s, 2);
    double f2 = f(1, s + t, t - s);
    double f3 = f(1, 1, pow(t, 2) + pow(s, 2));
    return (f1 + f2) / (1 + pow(f3, 2));
}

void read(double& s, double& t) {
    cout << "Введіть значення s: ";
    cin >> s;
    cout << "Введіть значення t: ";
    cin >> t;
}

int main() {
    try {
        double s, t;
        read(s, t);

        double result = calculate(s, t);

        cout << "Результат: " << result << endl;
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}
