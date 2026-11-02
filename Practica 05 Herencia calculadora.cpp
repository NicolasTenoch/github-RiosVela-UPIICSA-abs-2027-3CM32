#include <iostream>
using namespace std;
class Calculadora
{
private:
    void pedirDatos(double* a, double* b)
    {
        cout << "Ingresa el primer numero: ";
        cin >> *a;
        cout << "Ingresa el segundo numero: ";
        cin >> *b;
    }
public:
    void sumar()
    {
        double a, b;
        pedirDatos(&a, &b);
        sumar(a, b);
    }
    void sumar(double a, double b)
    {
        double* pa = &a;
        double* pb = &b;
        cout << "Resultado: " << *pa + *pb << endl;
    }
    void sumar(double a, double b, double c)
    {
        double* pa = &a;
        double* pb = &b;
        double* pc = &c;
        cout << "Resultado: " << *pa + *pb + *pc << endl;
    }
    void restar()
    {
        double a, b;
        pedirDatos(&a, &b);
        restar(a, b);
    }
    void restar(double a, double b)
    {
        double* pa = &a;
        double* pb = &b;
        cout << "Resultado: " << *pa - *pb << endl;
    }
    void restar(double a, double b, double c)
    {
        double* pa = &a;
        double* pb = &b;
        double* pc = &c;
        cout << "Resultado: " << *pa - *pb - *pc << endl;
    }
    void multiplicar()
    {
        double a, b;
        pedirDatos(&a, &b);
        multiplicar(a, b);
    }
    void multiplicar(double a, double b)
    {
        double* pa = &a;
        double* pb = &b;
        cout << "Resultado: " << *pa * *pb << endl;
    }
    void multiplicar(double a, double b, double c)
    {
        double* pa = &a;
        double* pb = &b;
        double* pc = &c;
        cout << "Resultado: " << *pa * *pb * *pc << endl;
    }
    void dividir()
    {
        double a, b;
        pedirDatos(&a, &b);
        dividir(a, b);
    }
    void dividir(double a, double b)
    {
        double* pa = &a;
        double* pb = &b;
        if (*pb == 0)
        {
            cout << "Error: no se puede dividir entre cero." << endl;
        }
        else
        {
            cout << "Resultado: " << *pa / *pb << endl;
        }
    }
    void dividir(double a, double b, double c)
    {
        double* pa = &a;
        double* pb = &b;
        double* pc = &c;
        if (*pb == 0 || *pc == 0)
        {
            cout << "Error: no se puede dividir entre cero." << endl;
        }
        else
        {
            cout << "Resultado: " << *pa / *pb / *pc << endl;
        }
    }
};
class CalculadoraNueva : public Calculadora
{
public:
    void mostrarTitulo()
    {
        cout << "===== CALCULADORA NUEVA =====" << endl;
    }
};
int main()
{
    CalculadoraNueva objeto;
    CalculadoraNueva* calc = &objeto;
    int operacion;
    int modo;
    double n1 = 0;
    double n2 = 0;
    double n3 = 0;
    do
    {
        cout << endl;
        calc->mostrarTitulo();
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una operacion: ";
        cin >> operacion;
        if (operacion == 5)
        {
            cout << "Programa terminado." << endl;
        }
        else if (operacion < 1 || operacion > 4)
        {
            cout << "Opcion no valida." << endl;
        }
        else
        {
            cout << endl;
            cout << "1. Sin parametros (el metodo pide los numeros)" << endl;
            cout << "2. Con dos numeros" << endl;
            cout << "3. Con tres numeros" << endl;
            cout << "Elige el modo: ";
            cin >> modo;
            if (modo < 1 || modo > 3)
            {
                cout << "Modo no valido." << endl;
            }
            else
            {
                if (modo >= 2)
                {
                }
                    cout << "Ingresa el primer numero: ";
                    cin >> n1;
                    cout << "Ingresa el segundo numero: ";
                    cin >> n2;
                if (modo == 3)
                {
                    cout << "Ingresa el tercer numero: ";
                    cin >> n3;
                }
                switch (operacion)
                {
                case 1:
                    if (modo == 1)
                        calc->sumar();
                    else if (modo == 2)
                        calc->sumar(n1, n2);
                    else
                        calc->sumar(n1, n2, n3);
                    break;
                case 2:
                    if (modo == 1)
                        calc->restar();
                    else if (modo == 2)
                        calc->restar(n1, n2);
                    else
                        calc->restar(n1, n2, n3);
                    break;
                case 3:
                    if (modo == 1)
                        calc->multiplicar();
                    else if (modo == 2)
                        calc->multiplicar(n1, n2);
                    else
                        calc->multiplicar(n1, n2, n3);
                    break;
                case 4:
                    if (modo == 1)
                        calc->dividir();
                    else if (modo == 2)
                        calc->dividir(n1, n2);
                    else
                        calc->dividir(n1, n2, n3);
                    break;
                }
            }
        }
    } while (operacion != 5);
    return 0;
}