#include <iostream>
using namespace std;
class CincoNumeros
{
private:
    double n1;
    double n2;
    double n3;
    double n4;
    double n5;
    double suma;
    double promedio;
    double mayor;
    double menor;
    double sumar(double* a, double* b, double* c, double* d, double* e)
    {
        return *a + *b + *c + *d + *e;
    }
    double maximo(double* a, double* b, double* c, double* d, double* e)
    {
        double resultado = *a;
        if (*b > resultado)
        {
            resultado = *b;
        }
        if (*c > resultado)
        {
            resultado = *c;
        }
        if (*d > resultado)
        {
            resultado = *d;
        }
        if (*e > resultado)
        {
            resultado = *e;
        }
        return resultado;
    }
    double minimo(double* a, double* b, double* c, double* d, double* e)
    {
        double resultado = *a;
        if (*b < resultado)
        {
            resultado = *b;
        }
        if (*c < resultado)
        {
            resultado = *c;
        }
        if (*d < resultado)
        {
            resultado = *d;
        }
        if (*e < resultado)
        {
            resultado = *e;
        }
        return resultado;
    }
public:
    CincoNumeros()
    {
        n1 = 0;
        n2 = 0;
        n3 = 0;
        n4 = 0;
        n5 = 0;
        suma = 0;
        promedio = 0;
        mayor = 0;
        menor = 0;
    }
    void capturar()
    {
        cout << "Ingresa el primer numero: ";
        cin >> n1;
        cout << "Ingresa el segundo numero: ";
        cin >> n2;
        cout << "Ingresa el tercer numero: ";
        cin >> n3;
        cout << "Ingresa el cuarto numero: ";
        cin >> n4;
    }
        cout << "Ingresa el quinto numero: ";
        cin >> n5;
    void calcular()
    {
        double* p1 = &n1;
        double* p2 = &n2;
        double* p3 = &n3;
        double* p4 = &n4;
        double* p5 = &n5;
        suma = sumar(p1, p2, p3, p4, p5);
        promedio = suma / 5;
        mayor = maximo(p1, p2, p3, p4, p5);
        menor = minimo(p1, p2, p3, p4, p5);
    }
    void mostrar()
    {
        cout << endl;
        cout << "===== RESULTADOS =====" << endl;
        cout << "Suma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Media aritmetica: " << promedio << endl;
        cout << "Numero maximo: " << mayor << endl;
        cout << "Numero minimo: " << menor << endl;
    }
};
int main()
{
    CincoNumeros numeros;
    numeros.capturar();
    numeros.calcular();
    numeros.mostrar();
    return 0;
}