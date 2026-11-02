#include <iostream>
using namespace std;
class OperacionesArreglo
{
private:
    static const int TAMANO = 5;
    double numeros[TAMANO];
    double suma;
    double promedio;
    double mayor;
    double menor;
public:
    OperacionesArreglo()
    {
        for (int i = 0; i < TAMANO; i++)
        {
            numeros[i] = 0;
        }
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
            cin >> numeros[i];
        }
    }
    void calcular()
    {
        double* pSuma = &suma;
        double* pPromedio = &promedio;
        double* pMayor = &mayor;
        double* pMenor = &menor;
        *pSuma = 0;
        *pMayor = numeros[0];
        *pMenor = numeros[0];
        for (int i = 0; i < TAMANO; i++)
        {
            *pSuma = *pSuma + numeros[i];
            if (numeros[i] > *pMayor)
            {
                *pMayor = numeros[i];
            }
            if (numeros[i] < *pMenor)
            {
                *pMenor = numeros[i];
            }
        }
        *pPromedio = *pSuma / TAMANO;
    }
    void mostrar()
    {
        cout << endl;
        cout << "===== NUMEROS CAPTURADOS =====" << endl;
        for (int i = 0; i < TAMANO; i++)
        {
            cout << "numeros[" << i << "] = " << numeros[i] << endl;
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
    OperacionesArreglo operaciones;
    operaciones.capturar();
    operaciones.calcular();
    operaciones.mostrar();
}
    return 0