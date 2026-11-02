#include <iostream>
using namespace std;
int leerEntero()
{
    int valor;
    while (!(cin >> valor))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada no valida. Intenta de nuevo: ";
    }
    cin.ignore(10000, '\n');
    return valor;
}
class CalculadoraRecursiva
{
private:
    long long factorialRec(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        return n * factorialRec(n - 1);
    }
    long long fibonacciRec(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        return fibonacciRec(n - 1) + fibonacciRec(n - 2);
    }
    long long multiplicarRec(int a, int b)
    {
        if (b == 0)
        {
            return 0;
        }
        return a + multiplicarRec(a, b - 1);
    }
    long long potenciaRec(int base, int exponente)
    {
        if (exponente == 0)
        {
            return 1;
        }
        return base * potenciaRec(base, exponente - 1);
    }
    void dividirRec(int dividendo, int divisor, int *cociente, int *residuo)
    {
        if (dividendo < divisor)
        {
            *cociente = 0;
            *residuo = dividendo;
            return;
        }
        dividirRec(dividendo - divisor, divisor, cociente, residuo);
        *cociente = *cociente + 1;
    }
public:
    bool factorial(int n, long long *resultado)
    {
        if (n < 0 || n > 20)
        {
            cout << "El numero debe estar entre 0 y 20." << endl;
            return false;
        }
        *resultado = factorialRec(n);
        return true;
    }
    bool fibonacci(int n, long long *resultado)
    {
        if (n < 0 || n > 35)
        {
            cout << "La posicion debe estar entre 0 y 35." << endl;
            return false;
        }
        *resultado = fibonacciRec(n);
        return true;
    }
    bool multiplicar(int a, int b, long long *resultado)
    {
        if (a < 0 || a > 100000)
        {
            cout << "El primer numero debe estar entre 0 y 100000." << endl;
            return false;
        }
        if (b < 0 || b > 2000)
        {
            cout << "El segundo numero debe estar entre 0 y 2000." << endl;
            return false;
        }
        *resultado = multiplicarRec(a, b);
        return true;
    }
    bool potencia(int base, int exponente, long long *resultado)
    {
        if (base < 0 || base > 10)
        {
            cout << "La base debe estar entre 0 y 10." << endl;
            return false;
        }
        if (exponente < 0 || exponente > 18)
        {
            cout << "El exponente debe estar entre 0 y 18." << endl;
            return false;
        }
        *resultado = potenciaRec(base, exponente);
        return true;
    }
    bool dividir(int dividendo, int divisor, int *cociente, int *residuo)
    {
        if (dividendo < 0 || dividendo > 2000)
        {
            cout << "El dividendo debe estar entre 0 y 2000." << endl;
            return false;
        }
        if (divisor == 0)
        {
        }
            cout << "No se puede dividir entre cero." << endl;
            return false;
        if (divisor < 0 || divisor > 2000)
        {
            cout << "El divisor debe estar entre 1 y 2000." << endl;
            return false;
        }
        dividirRec(dividendo, divisor, cociente, residuo);
        return true;
    }
};
int main()
{
    CalculadoraRecursiva calculadora;
    CalculadoraRecursiva *ptr = &calculadora;
    int opcion;
    do
    {
        cout << "===== MENU =====" << endl;
        cout << "1. Factorial" << endl;
        cout << "2. Fibonacci" << endl;
        cout << "3. Multiplicacion recursiva" << endl;
        cout << "4. Potencia recursiva" << endl;
        cout << "5. Division recursiva" << endl;
        cout << "6. Salir" << endl;
        cout << "Elige una opcion: ";
        opcion = leerEntero();
        cout << endl;
        long long resultado = 0;
        int cociente = 0;
        int residuo = 0;
        int a = 0;
        int b = 0;
        switch (opcion)
        {
        case 1:
            cout << "Numero (0 a 20): ";
            a = leerEntero();
            if (ptr->factorial(a, &resultado))
            {
                cout << a << "! = " << resultado << endl;
            }
            break;
        case 2:
            cout << "Posicion de Fibonacci (0 a 35): ";
            a = leerEntero();
            if (ptr->fibonacci(a, &resultado))
            {
                cout << "Fibonacci(" << a << ") = " << resultado << endl;
            }
            break;
        case 3:
            cout << "Primer numero (0 a 100000): ";
            a = leerEntero();
            cout << "Segundo numero (0 a 2000): ";
            b = leerEntero();
            if (ptr->multiplicar(a, b, &resultado))
            {
                cout << a << " x " << b << " = " << resultado << endl;
            }
            break;
        case 4:
            cout << "Base (0 a 10): ";
            a = leerEntero();
            cout << "Exponente (0 a 18): ";
            b = leerEntero();
            if (ptr->potencia(a, b, &resultado))
            {
                cout << a << " ^ " << b << " = " << resultado << endl;
            }
            break;
        case 5:
            cout << "Dividendo (0 a 2000): ";
            a = leerEntero();
            cout << "Divisor (1 a 2000): ";
            b = leerEntero();
            if (ptr->dividir(a, b, &cociente, &residuo))
            {
                cout << a << " / " << b << ": cociente = " << cociente
                     << ", residuo = " << residuo << endl;
            }
            break;
        case 6:
            cout << "Fin del programa." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
        cout << endl;
    } while (opcion != 6);
    return 0;
}