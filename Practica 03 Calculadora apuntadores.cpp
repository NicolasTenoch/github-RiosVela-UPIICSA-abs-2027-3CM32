#include <iostream>
using namespace std;
class Calculadora
{
public:
    double sumar(double* a, double* b)
    {
        return *a + *b;
    }
    double restar(double* a, double* b)
    {
        return *a - *b;
    }
    double multiplicar(double* a, double* b)
    {
        return *a * *b;
    }
    double dividir(double* a, double* b)
    {
        return *a / *b;
    }
};
int main()
{
    Calculadora calc;
    double num1 = 0;
    double num2 = 0;
    int opcion;
    do
    {
        cout << endl;
        cout << "===== CALCULADORA =====" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        if (opcion >= 1 && opcion <= 4)
        {
            cout << "Ingresa el primer numero: ";
            cin >> num1;
            cout << "Ingresa el segundo numero: ";
            cin >> num2;
        }
        switch (opcion)
        {
        case 1:
            cout << "Resultado: " << calc.sumar(&num1, &num2) << endl;
            break;
        case 2:
            cout << "Resultado: " << calc.restar(&num1, &num2) << endl;
            break;
        case 3:
            cout << "Resultado: " << calc.multiplicar(&num1, &num2) << endl;
            break;
        case 4:
            if (num2 == 0)
            {
                cout << "Error: no se puede dividir entre cero." << endl;
            }
            else
            {
                cout << "Resultado: " << calc.dividir(&num1, &num2) << endl;
            }
            break;
        case 5:
            cout << "Programa terminado." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != 5);
    return 0;
}