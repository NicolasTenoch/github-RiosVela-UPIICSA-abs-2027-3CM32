#include <iostream>
using namespace std;
class Estadisticas
{
private:
    static const int TAMANO = 5;
    double numeros[TAMANO];
    double* ptr;
    double suma;
    double promedio;
    double mayor;
    double menor;
public:
    Estadisticas()
    {
        ptr = numeros;
        suma = 0;
        promedio = 0;
        mayor = 0;
        menor = 0;
    }
    void capturar()
    {
        for (int i = 0; i < TAMANO; i++)
        {
            cout << "Ingresa el numero " << i + 1 << ": ";
            cin >> *(ptr + i);
        }
    }
    void calcular()
    {
        suma = 0;
        mayor = *ptr;
        menor = *ptr;
        for (int i = 0; i < TAMANO; i++)
        {
            suma = suma + *(ptr + i);
            if (*(ptr + i) > mayor)
            {
                mayor = *(ptr + i);
            }
            if (*(ptr + i) < menor)
            {
                menor = *(ptr + i);
            }
        }
        promedio = suma / TAMANO;
    }
    void mostrar()
    {
        cout << endl;
        cout << "===== NUMEROS CAPTURADOS =====" << endl;
        for (int i = 0; i < TAMANO; i++)
        {
            cout << "Numero " << i + 1 << ": " << *(ptr + i) << endl;
        }
        cout << endl;
        cout << "===== RESULTADOS =====" << endl;
        cout << "Suma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Media aritmetica: " << promedio << endl;
        cout << "Valor maximo: " << mayor << endl;
        cout << "Valor minimo: " << menor << endl;
    }
};
int main()
{
    Estadisticas objeto;
    Estadisticas* pObjeto = &objeto;
    pObjeto->capturar();
    pObjeto->calcular();
    pObjeto->mostrar();
    return 0;
}