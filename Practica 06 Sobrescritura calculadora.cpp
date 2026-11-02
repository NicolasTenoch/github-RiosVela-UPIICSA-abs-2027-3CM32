#include <iostream>
using namespace std;
class Calculadora
{
public:
    virtual void sumar(int a, int b)
    {
        int* pa = &a;
        int* pb = &b;
        cout << "[Padre] Suma: " << *pa + *pb << endl;
    }
    virtual void restar(int a, int b)
    {
        int* pa = &a;
        int* pb = &b;
        cout << "[Padre] Resta: " << *pa - *pb << endl;
    }
    virtual void multiplicar(int a, int b)
    {
        int* pa = &a;
        int* pb = &b;
        cout << "[Padre] Multiplicacion con el operador *: " << *pa * *pb << endl;
    }
    virtual void dividir(int a, int b)
    {
        int* pa = &a;
        int* pb = &b;
        if (*pb == 0)
        {
            cout << "Error: no se puede dividir entre cero." << endl;
        }
        else
        {
            cout << "[Padre] Division con el operador /: " << *pa / *pb << endl;
        }
    }
    virtual void potencia(int a, int b)
    {
        int* pa = &a;
        int* pb = &b;
        int resultado = 1;
        for (int i = 0; i < *pb; i++)
        {
            resultado = resultado * *pa;
        }
        cout << "[Padre] Potencia con el operador *: " << resultado << endl;
    }
};
class CalculadoraNueva : public Calculadora
{
private:
    int multiplicarSuma(int* x, int* y)
    {
        int base = *x;
        int veces = *y;
        bool negativo = false;
        if (base < 0)
        {
            base = -base;
            negativo = !negativo;
        }
        if (veces < 0)
        {
            veces = -veces;
            negativo = !negativo;
        }
        int resultado = 0;
        for (int i = 0; i < veces; i++)
        {
            resultado = resultado + base;
        }
        if (negativo)
        {
            resultado = -resultado;
        }
        return resultado;
    }
public:
    void multiplicar(int a, int b) override
    {
        int* pa = &a;
        int* pb = &b;
    }
        cout << "[Hija] Multiplicacion con sumas sucesivas: " << multiplicarSuma(pa, pb) << endl;
    void dividir(int a, int b) override
    {
        int* pa = &a;
        int* pb = &b;
        if (*pb == 0)
        {
            cout << "Error: no se puede dividir entre cero." << endl;
        }
        else
        {
            int dividendo = *pa;
            int divisor = *pb;
            bool negativo = false;
            if (dividendo < 0)
            {
                dividendo = -dividendo;
                negativo = !negativo;
            }
            if (divisor < 0)
            {
                divisor = -divisor;
                negativo = !negativo;
            }
            int cociente = 0;
            while (dividendo >= divisor)
            {
                dividendo = dividendo - divisor;
                cociente++;
            }
            if (negativo)
            {
                cociente = -cociente;
            }
            cout << "[Hija] Division con restas sucesivas: " << cociente << endl;
        }
    }
    void potencia(int a, int b) override
    {
        int* pa = &a;
        int* pb = &b;
        int resultado = 1;
        for (int i = 0; i < *pb; i++)
        {
            resultado = multiplicarSuma(&resultado, pa);
        }
        cout << "[Hija] Potencia con multiplicaciones sucesivas: " << resultado << endl;
    }
};
int main()
{
    Calculadora padre;
    CalculadoraNueva hija;
    Calculadora* calc;
    int opcion;
    int n1 = 0;
    int n2 = 0;
    do
    {
        cout << endl;
        cout << "===== CALCULADORA =====" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "5. Potencia" << endl;
        cout << "6. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        if (opcion == 6)
        {
            cout << "Programa terminado." << endl;
        }
        else if (opcion < 1 || opcion > 5)
        {
            cout << "Opcion no valida." << endl;
        }
        else
        {
            if (opcion == 5)
            {
                cout << "Ingresa la base: ";
                cin >> n1;
                do
                {
                    cout << "Ingresa el exponente (entero no negativo): ";
                    cin >> n2;
                } while (n2 < 0);
            }
            else
            {
                cout << "Ingresa el primer numero: ";
                cin >> n1;
                cout << "Ingresa el segundo numero: ";
                cin >> n2;
            }
            for (int i = 0; i < 2; i++)
            {
                if (i == 0)
                {
                    calc = &padre;
                    cout << endl << "Usando el objeto padre:" << endl;
                }
                else
                {
                    calc = &hija;
                    cout << endl << "Usando el objeto hija:" << endl;
                }
                switch (opcion)
                {
                case 1:
                    calc->sumar(n1, n2);
                    break;
                case 2:
                    calc->restar(n1, n2);
                    break;
                case 3:
                    calc->multiplicar(n1, n2);
                    break;
                case 4:
                    calc->dividir(n1, n2);
                    break;
                case 5:
                    calc->potencia(n1, n2);
                    break;
                }
            }
        }
    } while (opcion != 6);
}
    return 0