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
void ordenarEnteros(int arreglo[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arreglo[j] > arreglo[j + 1])
            {
                int temporal = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temporal;
            }
        }
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
    cout << endl;
}
void ordenarCaracteres(char arreglo[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arreglo[j] > arreglo[j + 1])
            {
                char temporal = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temporal;
            }
        }
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
void ordenarAutos(Auto arreglo[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            bool intercambiar = false;
            if (arreglo[j].precio > arreglo[j + 1].precio)
            {
                intercambiar = true;
            }
            else if (arreglo[j].precio == arreglo[j + 1].precio && arreglo[j].anio > arreglo[j + 1].anio)
            {
                intercambiar = true;
            }
            if (intercambiar)
            {
                Auto temporal = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temporal;
            }
        }
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
    double obtenerPrecio()
    {
        return precio;
    }
    int obtenerAnio()
    {
        return anio;
    }
};
class OrdenadorBurbuja
{
private:
    int enteros[MAX];
    char caracteres[MAX];
    AutoPOO autos[MAX];
    int cantEnteros;
    int cantCaracteres;
    int cantAutos;
public:
    OrdenadorBurbuja()
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
        for (int i = 0; i < cantEnteros - 1; i++)
        {
            for (int j = 0; j < cantEnteros - i - 1; j++)
            {
                if (enteros[j] > enteros[j + 1])
                {
                    int temporal = enteros[j];
                    enteros[j] = enteros[j + 1];
                    enteros[j + 1] = temporal;
                }
            }
        }
    }
    void capturarCaracteres()
    {
        cantCaracteres = pedirCantidad();
        for (int i = 0; i < cantCaracteres; i++)
        {
        }
            cout << "Elemento " << i + 1 << ": ";
            cin >> caracteres[i];
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
        for (int i = 0; i < cantCaracteres - 1; i++)
        {
            for (int j = 0; j < cantCaracteres - i - 1; j++)
            {
                if (caracteres[j] > caracteres[j + 1])
                {
                    char temporal = caracteres[j];
                    caracteres[j] = caracteres[j + 1];
                    caracteres[j + 1] = temporal;
                }
            }
        }
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
        for (int i = 0; i < cantAutos - 1; i++)
        {
            for (int j = 0; j < cantAutos - i - 1; j++)
            {
                bool intercambiar = false;
                if (autos[j].obtenerPrecio() > autos[j + 1].obtenerPrecio())
                {
                    intercambiar = true;
                }
                else if (autos[j].obtenerPrecio() == autos[j + 1].obtenerPrecio()
                    && autos[j].obtenerAnio() > autos[j + 1].obtenerAnio())
                {
                    intercambiar = true;
                }
                if (intercambiar)
                {
                    AutoPOO temporal = autos[j];
                    autos[j] = autos[j + 1];
                    autos[j + 1] = temporal;
                }
            }
        }
    }
};
int main()
{
    int enteros[MAX];
    char caracteres[MAX];
    Auto autos[MAX];
    OrdenadorBurbuja ordenador;
    int opcion;
    int n;
    do
    {
        cout << endl;
        cout << "===== ORDENAMIENTO BURBUJA =====" << endl;
        cout << "--- Programacion estructurada (PE) ---" << endl;
        cout << "1. Ordenar numeros enteros" << endl;
        cout << "2. Ordenar caracteres" << endl;
        cout << "3. Ordenar autos" << endl;
        cout << "--- Programacion orientada a objetos (POO) ---" << endl;
        cout << "4. Ordenar numeros enteros" << endl;
        cout << "5. Ordenar caracteres" << endl;
        cout << "6. Ordenar autos" << endl;
        cout << "7. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            n = pedirCantidad();
            capturarEnteros(enteros, n);
            cout << endl << "Arreglo original:" << endl;
            mostrarEnteros(enteros, n);
            ordenarEnteros(enteros, n);
            cout << endl << "Arreglo ordenado:" << endl;
            mostrarEnteros(enteros, n);
            break;
        case 2:
            n = pedirCantidad();
            capturarCaracteres(caracteres, n);
            cout << endl << "Arreglo original:" << endl;
            mostrarCaracteres(caracteres, n);
            ordenarCaracteres(caracteres, n);
            cout << endl << "Arreglo ordenado:" << endl;
            mostrarCaracteres(caracteres, n);
            break;
        case 3:
            n = pedirCantidad();
            capturarAutos(autos, n);
            cout << endl << "Arreglo original:" << endl;
            mostrarAutos(autos, n);
            ordenarAutos(autos, n);
            cout << endl << "Arreglo ordenado:" << endl;
            mostrarAutos(autos, n);
            break;
        case 4:
            ordenador.capturarEnteros();
            cout << endl << "Arreglo original:" << endl;
            ordenador.mostrarEnteros();
            ordenador.ordenarEnteros();
            cout << endl << "Arreglo ordenado:" << endl;
            ordenador.mostrarEnteros();
            break;
        case 5:
            ordenador.capturarCaracteres();
            cout << endl << "Arreglo original:" << endl;
            ordenador.mostrarCaracteres();
            ordenador.ordenarCaracteres();
            cout << endl << "Arreglo ordenado:" << endl;
            ordenador.mostrarCaracteres();
            break;
        case 6:
            ordenador.capturarAutos();
            cout << endl << "Arreglo original:" << endl;
            ordenador.mostrarAutos();
            ordenador.ordenarAutos();
            cout << endl << "Arreglo ordenado:" << endl;
            ordenador.mostrarAutos();
            break;
        case 7:
            cout << "Programa terminado." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != 7);
    return 0;
}