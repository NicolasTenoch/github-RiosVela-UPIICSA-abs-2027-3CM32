#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 10;
struct Auto
{
    double precio;
    int anio;
};
int pedirCantidad()
{
    int n;
    do
    {
        cout << "Cuantos elementos deseas ingresar (1 a " << MAX << "): ";
        cin >> n;
    } while (n < 1 || n > MAX);
    return n;
}
void capturarEnteros(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }
}
void mostrarEnteros(int arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}
int particionEnteros(int arreglo[], int inicio, int fin)
{
    int pivote = arreglo[fin];
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++)
    {
        if (arreglo[j] <= pivote)
        {
            i++;
            int temporal = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temporal;
        }
    }
    int temporal = arreglo[i + 1];
    arreglo[i + 1] = arreglo[fin];
    arreglo[fin] = temporal;
    return i + 1;
}
void quickSortEnteros(int arreglo[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int posicionPivote = particionEnteros(arreglo, inicio, fin);
        quickSortEnteros(arreglo, inicio, posicionPivote - 1);
        quickSortEnteros(arreglo, posicionPivote + 1, fin);
    }
}
void capturarCaracteres(char arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }
}
void mostrarCaracteres(char arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arreglo[i] << " ";
    }
}
    cout << endl;
int particionCaracteres(char arreglo[], int inicio, int fin)
{
    char pivote = arreglo[fin];
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++)
    {
        if (arreglo[j] <= pivote)
        {
            i++;
            char temporal = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temporal;
        }
    }
    char temporal = arreglo[i + 1];
    arreglo[i + 1] = arreglo[fin];
    arreglo[fin] = temporal;
    return i + 1;
}
void quickSortCaracteres(char arreglo[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int posicionPivote = particionCaracteres(arreglo, inicio, fin);
        quickSortCaracteres(arreglo, inicio, posicionPivote - 1);
        quickSortCaracteres(arreglo, posicionPivote + 1, fin);
    }
}
void capturarAutos(Auto arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Auto " << i + 1 << endl;
        cout << "  Precio: ";
        cin >> arreglo[i].precio;
        cout << "  Anio: ";
        cin >> arreglo[i].anio;
    }
}
void mostrarAutos(Auto arreglo[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Auto " << i + 1 << " - Precio: $" << fixed << setprecision(2)
             << arreglo[i].precio << " - Anio: " << arreglo[i].anio << endl;
    }
}
bool autoMenorOIgual(Auto a, Auto b)
{
    if (a.precio < b.precio)
    {
        return true;
    }
    if (a.precio == b.precio && a.anio <= b.anio)
    {
        return true;
    }
    return false;
}
int particionAutos(Auto arreglo[], int inicio, int fin)
{
    Auto pivote = arreglo[fin];
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++)
    {
        if (autoMenorOIgual(arreglo[j], pivote))
        {
            i++;
            Auto temporal = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temporal;
        }
    }
    Auto temporal = arreglo[i + 1];
    arreglo[i + 1] = arreglo[fin];
    arreglo[fin] = temporal;
    return i + 1;
}
void quickSortAutos(Auto arreglo[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int posicionPivote = particionAutos(arreglo, inicio, fin);
        quickSortAutos(arreglo, inicio, posicionPivote - 1);
        quickSortAutos(arreglo, posicionPivote + 1, fin);
    }
}
class AutoPOO
{
private:
    double precio;
    int anio;
public:
    void capturar()
    {
        cout << "  Precio: ";
        cin >> precio;
        cout << "  Anio: ";
        cin >> anio;
    }
    void mostrar()
    {
        cout << "Precio: $" << fixed << setprecision(2) << precio << " - Anio: " << anio << endl;
    }
    bool esMenorOIgual(AutoPOO otro)
    {
        if (precio < otro.precio)
        {
            return true;
        }
        if (precio == otro.precio && anio <= otro.anio)
        {
            return true;
        }
        return false;
    }
};
class OrdenadorQuickSort
{
private:
    int enteros[MAX];
    char caracteres[MAX];
    AutoPOO autos[MAX];
    int cantEnteros;
    int cantCaracteres;
    int cantAutos;
    int particionEnteros(int inicio, int fin)
    {
        int pivote = enteros[fin];
        int i = inicio - 1;
        for (int j = inicio; j < fin; j++)
        {
            if (enteros[j] <= pivote)
            {
                i++;
                int temporal = enteros[i];
                enteros[i] = enteros[j];
                enteros[j] = temporal;
            }
        }
        int temporal = enteros[i + 1];
        enteros[i + 1] = enteros[fin];
        enteros[fin] = temporal;
        return i + 1;
    }
    void quickSortEnteros(int inicio, int fin)
    {
        if (inicio < fin)
        {
            int posicionPivote = particionEnteros(inicio, fin);
            quickSortEnteros(inicio, posicionPivote - 1);
            quickSortEnteros(posicionPivote + 1, fin);
        }
    }
    int particionCaracteres(int inicio, int fin)
    {
        char pivote = caracteres[fin];
        int i = inicio - 1;
        for (int j = inicio; j < fin; j++)
        {
            if (caracteres[j] <= pivote)
            {
                i++;
                char temporal = caracteres[i];
                caracteres[i] = caracteres[j];
                caracteres[j] = temporal;
            }
        }
        char temporal = caracteres[i + 1];
        caracteres[i + 1] = caracteres[fin];
        caracteres[fin] = temporal;
        return i + 1;
    }
    void quickSortCaracteres(int inicio, int fin)
    {
        if (inicio < fin)
        {
            int posicionPivote = particionCaracteres(inicio, fin);
            quickSortCaracteres(inicio, posicionPivote - 1);
            quickSortCaracteres(posicionPivote + 1, fin);
        }
    }
    int particionAutos(int inicio, int fin)
    {
        AutoPOO pivote = autos[fin];
        int i = inicio - 1;
        for (int j = inicio; j < fin; j++)
        {
            if (autos[j].esMenorOIgual(pivote))
            {
                i++;
                AutoPOO temporal = autos[i];
                autos[i] = autos[j];
                autos[j] = temporal;
            }
        }
        AutoPOO temporal = autos[i + 1];
        autos[i + 1] = autos[fin];
        autos[fin] = temporal;
        return i + 1;
    }
    void quickSortAutos(int inicio, int fin)
    {
        if (inicio < fin)
        {
            int posicionPivote = particionAutos(inicio, fin);
            quickSortAutos(inicio, posicionPivote - 1);
            quickSortAutos(posicionPivote + 1, fin);
        }
    }
public:
    OrdenadorQuickSort()
    {
        cantEnteros = 0;
        cantCaracteres = 0;
        cantAutos = 0;
    }
    void capturarEnteros()
    {
        cantEnteros = pedirCantidad();
        for (int i = 0; i < cantEnteros; i++)
        {
            cout << "Elemento " << i + 1 << ": ";
            cin >> enteros[i];
        }
    }
    void mostrarEnteros()
    {
        for (int i = 0; i < cantEnteros; i++)
        {
            cout << enteros[i] << " ";
        }
        cout << endl;
    }
    void ordenarEnteros()
    {
        quickSortEnteros(0, cantEnteros - 1);
    }
    void capturarCaracteres()
    {
        cantCaracteres = pedirCantidad();
        for (int i = 0; i < cantCaracteres; i++)
        {
            cout << "Elemento " << i + 1 << ": ";
            cin >> caracteres[i];
        }
    }
    void mostrarCaracteres()
    {
        for (int i = 0; i < cantCaracteres; i++)
        {
            cout << caracteres[i] << " ";
        }
        cout << endl;
    }
    void ordenarCaracteres()
    {
        quickSortCaracteres(0, cantCaracteres - 1);
    }
    void capturarAutos()
    {
        cantAutos = pedirCantidad();
        for (int i = 0; i < cantAutos; i++)
        {
            cout << "Auto " << i + 1 << endl;
            autos[i].capturar();
        }
    }
    void mostrarAutos()
    {
        for (int i = 0; i < cantAutos; i++)
        {
            cout << "Auto " << i + 1 << " - ";
            autos[i].mostrar();
        }
    }
    void ordenarAutos()
    {
        quickSortAutos(0, cantAutos - 1);
    }
};
int menuSecundario(const char* version)
{
    int opcion;
    cout << endl;
    cout << "===== QUICK SORT CON " << version << " =====" << endl;
    cout << "1. Ordenar numeros enteros" << endl;
    cout << "2. Ordenar caracteres" << endl;
    cout << "3. Ordenar automoviles" << endl;
    cout << "4. Regresar" << endl;
    cout << "Elige una opcion: ";
    cin >> opcion;
    return opcion;
}
int main()
{
    int enteros[MAX];
    char caracteres[MAX];
    Auto autos[MAX];
    OrdenadorQuickSort ordenador;
    int principal;
    int secundario;
    int n;
    do
    {
        cout << endl;
        cout << "===== QUICK SORT =====" << endl;
        cout << "1. Quick Sort con PE" << endl;
        cout << "2. Quick Sort con POO" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> principal;
        if (principal == 1)
        {
            do
            {
                secundario = menuSecundario("PE");
                switch (secundario)
                {
                case 1:
                    n = pedirCantidad();
                    capturarEnteros(enteros, n);
                    cout << endl << "Arreglo original:" << endl;
                    mostrarEnteros(enteros, n);
                    quickSortEnteros(enteros, 0, n - 1);
                    cout << endl << "Arreglo ordenado:" << endl;
                    mostrarEnteros(enteros, n);
                    break;
                case 2:
                    n = pedirCantidad();
                    capturarCaracteres(caracteres, n);
                    cout << endl << "Arreglo original:" << endl;
                    mostrarCaracteres(caracteres, n);
                    quickSortCaracteres(caracteres, 0, n - 1);
                    cout << endl << "Arreglo ordenado:" << endl;
                    mostrarCaracteres(caracteres, n);
                    break;
                case 3:
                    n = pedirCantidad();
                    capturarAutos(autos, n);
                    cout << endl << "Arreglo original:" << endl;
                    mostrarAutos(autos, n);
                    quickSortAutos(autos, 0, n - 1);
                    cout << endl << "Arreglo ordenado:" << endl;
                    mostrarAutos(autos, n);
                    break;
                case 4:
                    break;
                default:
                    cout << "Opcion no valida." << endl;
                }
            } while (secundario != 4);
        }
        else if (principal == 2)
        {
            do
            {
                secundario = menuSecundario("POO");
                switch (secundario)
                {
                case 1:
                    ordenador.capturarEnteros();
                    cout << endl << "Arreglo original:" << endl;
                    ordenador.mostrarEnteros();
                    ordenador.ordenarEnteros();
                    cout << endl << "Arreglo ordenado:" << endl;
                    ordenador.mostrarEnteros();
                    break;
                case 2:
                    ordenador.capturarCaracteres();
                    cout << endl << "Arreglo original:" << endl;
                    ordenador.mostrarCaracteres();
                    ordenador.ordenarCaracteres();
                    cout << endl << "Arreglo ordenado:" << endl;
                    ordenador.mostrarCaracteres();
                    break;
                case 3:
                    ordenador.capturarAutos();
                    cout << endl << "Arreglo original:" << endl;
                    ordenador.mostrarAutos();
                    ordenador.ordenarAutos();
                    cout << endl << "Arreglo ordenado:" << endl;
                    ordenador.mostrarAutos();
                    break;
                case 4:
                    break;
                default:
                    cout << "Opcion no valida." << endl;
                }
            } while (secundario != 4);
        }
        else if (principal == 3)
        {
            cout << "Programa terminado." << endl;
        }
        else
        {
            cout << "Opcion no valida." << endl;
        }
    } while (principal != 3);
    return 0;
}