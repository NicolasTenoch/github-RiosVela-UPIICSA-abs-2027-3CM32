#include <iostream>
using namespace std;
class Calculadora
{
public:
    int sumar(int* a, int* b)
    {
        return *a + *b;
    }
};
int main()
{
    Calculadora calc;
    int num1;
    int num2;
    cout << "Ingresa el primer numero: ";
    cin >> num1;
    cout << "Ingresa el segundo numero: ";
    cin >> num2;
    int resultado = calc.sumar(&num1, &num2);
    cout << "La suma es: " << resultado << endl;
    return 0;
}