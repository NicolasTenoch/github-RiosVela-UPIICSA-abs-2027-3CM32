#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
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
    return valor;
}
double leerDecimal()
{
    double valor;
    while (!(cin >> valor))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada no valida. Intenta de nuevo: ";
    }
    return valor;
}
class Matrices
{
private:
    int n;
    double *A;
    double *B;
    double *resultadoConstante;
    double *resultadoProducto;
    double constante;
    bool hayConstante;
    bool hayProducto;
    void liberar()
    {
        delete[] A;
        delete[] B;
        delete[] resultadoConstante;
        delete[] resultadoProducto;
        A = nullptr;
        B = nullptr;
        resultadoConstante = nullptr;
        resultadoProducto = nullptr;
        n = 0;
        hayConstante = false;
        hayProducto = false;
    }
    bool listo()
    {
        if (A == nullptr)
        {
            cout << "Primero selecciona la dimension (opcion 1)." << endl << endl;
            return false;
        }
        return true;
    }
    int elegirLimite()
    {
        cout << "1. Mostrar una seccion de 10x10" << endl;
        cout << "2. Mostrar la matriz completa" << endl;
        cout << "Elige una opcion: ";
        int opcion = leerEntero();
        cout << endl;
        if (opcion == 2)
        {
            return n;
        }
        if (opcion != 1)
        {
            cout << "Opcion no valida, se mostrara la seccion de 10x10." << endl << endl;
        }
        return 10;
    }
    void imprimir(double *matriz, const char *titulo, int limite)
    {
        cout << titulo;
        if (limite < n)
        {
            cout << " (seccion " << limite << "x" << limite << " de " << n << "x" << n << ")";
        }
        cout << endl;
        for (int i = 0; i < limite; i++)
        {
            double *fila = matriz + i * n;
            for (int j = 0; j < limite; j++)
            {
                cout << setw(8) << *(fila + j);
            }
            cout << endl;
        }
        cout << endl;
    }
public:
    Matrices()
    {
        n = 0;
        A = nullptr;
        B = nullptr;
        resultadoConstante = nullptr;
        resultadoProducto = nullptr;
        constante = 0;
        hayConstante = false;
        hayProducto = false;
        srand((unsigned int)time(0));
    }
    ~Matrices()
    {
        liberar();
    }
    void seleccionarDimension()
    {
        cout << "Dimensiones disponibles:" << endl;
        cout << "1. 20 x 20" << endl;
        cout << "2. 50 x 50" << endl;
        cout << "3. 100 x 100" << endl;
        cout << "4. 200 x 200" << endl;
        cout << "Elige una opcion: ";
        int opcion = leerEntero();
        cout << endl;
        int nueva = 0;
        switch (opcion)
        {
        case 1:
            nueva = 20;
            break;
        case 2:
            nueva = 50;
            break;
        case 3:
            nueva = 100;
            break;
        case 4:
            nueva = 200;
            break;
        default:
            cout << "Dimension no valida. No se hicieron cambios." << endl << endl;
            return;
        }
        liberar();
        n = nueva;
        A = new double[n * n];
        B = new double[n * n];
        resultadoConstante = new double[n * n];
        resultadoProducto = new double[n * n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                *(A + i * n + j) = 0;
                *(B + i * n + j) = 0;
                *(resultadoConstante + i * n + j) = 0;
                *(resultadoProducto + i * n + j) = 0;
            }
        }
        cout << "Matrices de " << n << "x" << n << " creadas correctamente." << endl << endl;
    }
    void capturar()
    {
        if (!listo())
        {
            return;
        }
        hayConstante = false;
        hayProducto = false;
        cout << "Captura de la matriz A (" << n * n << " valores)" << endl;
        for (int i = 0; i < n; i++)
        {
            double *fila = A + i * n;
            for (int j = 0; j < n; j++)
            {
                cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
                *(fila + j) = leerDecimal();
            }
        }
        cout << endl << "Captura de la matriz B (" << n * n << " valores)" << endl;
        for (int i = 0; i < n; i++)
        {
            double *fila = B + i * n;
            for (int j = 0; j < n; j++)
            {
                cout << "B[" << i + 1 << "][" << j + 1 << "]: ";
                *(fila + j) = leerDecimal();
            }
        }
        cout << endl;
    }
    void generar()
    {
        if (!listo())
        {
            return;
        }
        hayConstante = false;
        hayProducto = false;
        for (int i = 0; i < n; i++)
        {
            double *filaA = A + i * n;
            double *filaB = B + i * n;
            for (int j = 0; j < n; j++)
            {
            }
                *(filaA + j) = rand() % 10;
                *(filaB + j) = rand() % 10;
        }
        cout << "Matrices A y B generadas con valores aleatorios del 0 al 9." << endl << endl;
    }
    void mostrar()
    {
        if (!listo())
        {
            return;
        }
        int limite = elegirLimite();
        imprimir(A, "Matriz A", limite);
        imprimir(B, "Matriz B", limite);
    }
    void multiplicarPorConstante()
    {
        if (!listo())
        {
            return;
        }
        cout << "Ingresa la constante: ";
        constante = leerDecimal();
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            double *filaA = A + i * n;
            double *filaR = resultadoConstante + i * n;
            for (int j = 0; j < n; j++)
            {
                *(filaR + j) = constante * *(filaA + j);
            }
        }
        hayConstante = true;
        cout << "Multiplicacion por la constante realizada. Consulta la opcion 7." << endl << endl;
    }
    void multiplicarMatrices()
    {
        if (!listo())
        {
            return;
        }
        for (int i = 0; i < n; i++)
        {
            double *filaA = A + i * n;
            double *filaR = resultadoProducto + i * n;
            for (int j = 0; j < n; j++)
            {
                double suma = 0;
                for (int k = 0; k < n; k++)
                {
                    suma = suma + *(filaA + k) * *(B + k * n + j);
                }
                *(filaR + j) = suma;
            }
        }
        hayProducto = true;
        cout << "Multiplicacion A x B realizada. Consulta la opcion 7." << endl << endl;
    }
    void mostrarResultados()
    {
        if (!listo())
        {
            return;
        }
        if (!hayConstante && !hayProducto)
        {
            cout << "Todavia no hay resultados. Usa la opcion 5 o la 6." << endl << endl;
            return;
        }
        int limite = elegirLimite();
        if (hayConstante)
        {
            cout << "Constante utilizada: " << constante << endl;
            imprimir(resultadoConstante, "Resultado de A por la constante", limite);
        }
        if (hayProducto)
        {
            imprimir(resultadoProducto, "Resultado de A x B", limite);
        }
    }
};
int main()
{
    Matrices objeto;
    Matrices *ptr = &objeto;
    int opcion;
    do
    {
        cout << "===== MENU =====" << endl;
        cout << "1. Seleccionar dimension de las matrices" << endl;
        cout << "2. Capturar matrices manualmente" << endl;
        cout << "3. Generar matrices automaticamente" << endl;
        cout << "4. Mostrar matrices A y B" << endl;
        cout << "5. Multiplicar A por una constante" << endl;
        cout << "6. Multiplicar A x B" << endl;
        cout << "7. Mostrar resultados" << endl;
        cout << "8. Salir" << endl;
        cout << "Elige una opcion: ";
        opcion = leerEntero();
        cout << endl;
        switch (opcion)
        {
        case 1:
            ptr->seleccionarDimension();
            break;
        case 2:
            ptr->capturar();
            break;
        case 3:
            ptr->generar();
            break;
        case 4:
            ptr->mostrar();
            break;
        case 5:
            ptr->multiplicarPorConstante();
            break;
        case 6:
            ptr->multiplicarMatrices();
            break;
        case 7:
            ptr->mostrarResultados();
            break;
        case 8:
            cout << "Fin del programa." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl << endl;
        }
    } while (opcion != 8);
    return 0;
}