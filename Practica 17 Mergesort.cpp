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
void mezclarEnteros(int arreglo[], int inicio, int medio, int fin)
{
    int auxiliar[MAX];
    int i = inicio;
    int j = medio + 1;
    int k = inicio;
    while (i <= medio && j <= fin)
    {
        if (arreglo[i] <= arreglo[j])
        {
            auxiliar[k] = arreglo[i];
            i++;
        }
        else
        {
            auxiliar[k] = arreglo[j];
            j++;
        }
        k++;
    }
    while (i <= medio)
    {
        auxiliar[k] = arreglo[i];
        i++;
        k++;
    }
    while (j <= fin)
    {
        auxiliar[k] = arreglo[j];
        j++;
        k++;
    }
    for (int x = inicio; x <= fin; x++)
    {
        arreglo[x] = auxiliar[x];
    }
}
void mergeSortEnteros(int arreglo[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int medio = (inicio + fin) / 2;
        mergeSortEnteros(arreglo, inicio, medio);
        mergeSortEnteros(arreglo, medio + 1, fin);
        mezclarEnteros(arreglo, inicio, medio, fin);
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
void mezclarCaracteres(char arreglo[], int inicio, int medio, int fin)
{
    char auxiliar[MAX];
    int i = inicio;
    int j = medio + 1;
    int k = inicio;
    while (i <= medio && j <= fin)
    {
        if (arreglo[i] <= arreglo[j])
        {
            auxiliar[k] = arreglo[i];
            i++;
        }
        else
        {
            auxiliar[k] = arreglo[j];
            j++;
        }
        k++;
    }
    while (i <= medio)
    {
        auxiliar[k] = arreglo[i];
        i++;
        k++;
    }
    while (j <= fin)
    {
        auxiliar[k] = arreglo[j];
        j++;
        k++;
    }
    for (int x = inicio; x <= fin; x++)
    {
        arreglo[x] = auxiliar[x];
    }
}
void mergeSortCaracteres(char arreglo[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int medio = (inicio + fin) / 2;
        mergeSortCaracteres(arreglo, inicio, medio);
        mergeSortCaracteres(arreglo, medio + 1, fin);
        mezclarCaracteres(arreglo, inicio, medio, fin);
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
void mezclarAutos(Auto arreglo[], int inicio, int medio, int fin)
{
    Auto auxiliar[MAX];
    int i = inicio;
    int j = medio + 1;
    int k = inicio;
    while (i <= medio && j <= fin)
    {
        if (autoMenorOIgual(arreglo[i], arreglo[j]))
        {
            auxiliar[k] = arreglo[i];
            i++;
        }
        else
        {
            auxiliar[k] = arreglo[j];
            j++;
        }
        k++;
    }
    while (i <= medio)
    {
        auxiliar[k] = arreglo[i];
        i++;
        k++;
    }
    while (j <= fin)
    {
        auxiliar[k] = arreglo[j];
        j++;
        k++;
    }
    for (int x = inicio; x <= fin; x++)
    {
        arreglo[x] = auxiliar[x];
    }
}
void mergeSortAutos(Auto arreglo[], int inicio, int fin)
{
    if (inicio < fin)
    {
        int medio = (inicio + fin) / 2;
        mergeSortAutos(arreglo, inicio, medio);
        mergeSortAutos(arreglo, medio + 1, fin);
        mezclarAutos(arreglo, inicio, medio, fin);
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
};
    }
        return false;
class OrdenadorMergeSort
{
private:
    int enteros[MAX];
    char caracteres[MAX];
    AutoPOO autos[MAX];
    int cantEnteros;
    int cantCaracteres;
    int cantAutos;
    int dividir(int inicio, int fin)
    {
        return (inicio + fin) / 2;
    }
    void combinarEnteros(int inicio, int medio, int fin)
    {
        int auxiliar[MAX];
        int i = inicio;
        int j = medio + 1;
        int k = inicio;
        while (i <= medio && j <= fin)
        {
            if (enteros[i] <= enteros[j])
            {
                auxiliar[k] = enteros[i];
                i++;
            }
            else
            {
                auxiliar[k] = enteros[j];
                j++;
            }
            k++;
        }
        while (i <= medio)
        {
            auxiliar[k] = enteros[i];
            i++;
            k++;
        }
        while (j <= fin)
        {
            auxiliar[k] = enteros[j];
            j++;
            k++;
        }
        for (int x = inicio; x <= fin; x++)
        {
            enteros[x] = auxiliar[x];
        }
    }
    void mergeSortEnteros(int inicio, int fin)
    {
        if (inicio < fin)
        {
            int medio = dividir(inicio, fin);
            mergeSortEnteros(inicio, medio);
            mergeSortEnteros(medio + 1, fin);
            combinarEnteros(inicio, medio, fin);
        }
    }
    void combinarCaracteres(int inicio, int medio, int fin)
    {
        char auxiliar[MAX];
        int i = inicio;
        int j = medio + 1;
        int k = inicio;
        while (i <= medio && j <= fin)
        {
            if (caracteres[i] <= caracteres[j])
            {
                auxiliar[k] = caracteres[i];
                i++;
            }
            else
            {
                auxiliar[k] = caracteres[j];
                j++;
            }
            k++;
        }
        while (i <= medio)
        {
            auxiliar[k] = caracteres[i];
            i++;
            k++;
        }
        while (j <= fin)
        {
            auxiliar[k] = caracteres[j];
            j++;
            k++;
        }
        for (int x = inicio; x <= fin; x++)
        {
            caracteres[x] = auxiliar[x];
        }
    }
    void mergeSortCaracteres(int inicio, int fin)
    {
        if (inicio < fin)
        {
            int medio = dividir(inicio, fin);
            mergeSortCaracteres(inicio, medio);
            mergeSortCaracteres(medio + 1, fin);
            combinarCaracteres(inicio, medio, fin);
        }
    }
    void combinarAutos(int inicio, int medio, int fin)
    {
        AutoPOO auxiliar[MAX];
        int i = inicio;
        int j = medio + 1;
        int k = inicio;
        while (i <= medio && j <= fin)
        {
            if (autos[i].esMenorOIgual(autos[j]))
            {
                auxiliar[k] = autos[i];
                i++;
            }
            else
            {
                auxiliar[k] = autos[j];
                j++;
            }
        }
            k++;
        while (i <= medio)
        {
            auxiliar[k] = autos[i];
            i++;
            k++;
        }
        while (j <= fin)
        {
            auxiliar[k] = autos[j];
            j++;
            k++;
        }
        for (int x = inicio; x <= fin; x++)
        {
            autos[x] = auxiliar[x];
        }
    }
    void mergeSortAutos(int inicio, int fin)
    {
        if (inicio < fin)
        {
            int medio = dividir(inicio, fin);
            mergeSortAutos(inicio, medio);
            mergeSortAutos(medio + 1, fin);
            combinarAutos(inicio, medio, fin);
        }
    }
public:
    OrdenadorMergeSort()
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
        mergeSortEnteros(0, cantEnteros - 1);
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
        mergeSortCaracteres(0, cantCaracteres - 1);
    }
    void capturarAutos()
    {
        cantAutos = pedirCantidad();
        for (int i = 0; i < cantAutos; i++)
        {
        }
            cout << "Auto " << i + 1 << endl;
            autos[i].capturar();
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
        mergeSortAutos(0, cantAutos - 1);
    }
};
int menuSecundario(const char* version)
{
    int opcion;
    cout << endl;
    cout << "===== MERGE SORT CON " << version << " =====" << endl;
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
    OrdenadorMergeSort ordenador;
    int principal;
    int secundario;
    int n;
    do
    {
        cout << endl;
        cout << "===== MERGE SORT =====" << endl;
        cout << "1. Merge Sort con PE" << endl;
        cout << "2. Merge Sort con POO" << endl;
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
                    mergeSortEnteros(enteros, 0, n - 1);
                    cout << endl << "Arreglo ordenado:" << endl;
                    mostrarEnteros(enteros, n);
                    break;
                case 2:
                    n = pedirCantidad();
                    capturarCaracteres(caracteres, n);
                    cout << endl << "Arreglo original:" << endl;
                    mostrarCaracteres(caracteres, n);
                    mergeSortCaracteres(caracteres, 0, n - 1);
                    cout << endl << "Arreglo ordenado:" << endl;
                    mostrarCaracteres(caracteres, n);
                    break;
                case 3:
                    n = pedirCantidad();
                    capturarAutos(autos, n);
                    cout << endl << "Arreglo original:" << endl;
                    mostrarAutos(autos, n);
                    mergeSortAutos(autos, 0, n - 1);
                    cout << endl << "Arreglo ordenado:" << endl;
                    mostrarAutos(autos, n);
                    break;
                case 4:
                    break;
                default:
                    cout << "Opcion no valida." << endl;
        }
                }
            } while (secundario != 4);
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