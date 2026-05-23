#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;   // числитель
    int denominator; // знаменатель

    // Метод для сокращения дроби
    void reduce() {
        int a = numerator;
        int b = denominator;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        numerator /= a;
        denominator /= a;
    }

public:
    // Конструктор по умолчанию
    Fraction(int n = 0, int d = 1) {
        numerator = n;
        denominator = (d != 0) ? d : 1; // защита от 0
        reduce();
    }

    // Перегрузка оператора сложения
    Fraction operator+(const Fraction& other) const {
        int n = numerator * other.denominator + other.numerator * denominator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }

    // Метод для вывода дроби
    void display() const {
        cout << numerator << "/" << denominator;
    }
};

int main() {
    Fraction f1, f2, f3;
    int n, d;

    // Ввод первой дроби
    cout << "Введите числитель и знаменатель первой дроби: ";
    cin >> n >> d;
    f1 = Fraction(n, d);

    // Ввод второй дроби
    cout << "Введите числитель и знаменатель второй дроби: ";
    cin >> n >> d;
    f2 = Fraction(n, d);

    // Ввод третьей дроби
    cout << "Введите числитель и знаменатель третьей дроби: ";
    cin >> n >> d;
    f3 = Fraction(n, d);

    // Сумма дробей
    Fraction sum = f1 + f2 + f3;

    // Вывод результата
    cout << "Сумма дробей ";
    f1.display(); cout << " + ";
    f2.display(); cout << " + ";
    f3.display(); cout << " = ";
    sum.display();
    cout << endl;

    return 0;
}
