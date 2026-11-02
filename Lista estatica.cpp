#include <iostream>
using namespace std;
class Lista
{
private:
    int datos[10];
    int cantidad;
public:
    Lista()
    {
        cantidad = 0;
    }
    void insertarAlFinal(int dato)
    {
        if (cantidad == 10)
        {
            cout << "La lista esta llena. No se puede insertar." << endl;
            return;
        }
        datos[cantidad] = dato;
        cantidad = cantidad + 1;
        cout << "Elemento " << dato << " insertado en la posicion " << cantidad << "." << endl;
    }
    void insertarEnPosicion(int posicion, int dato)
    {
        if (cantidad == 10)
        {
            cout << "La lista esta llena. No se puede insertar." << endl;
            return;
        }
        if (posicion < 1 || posicion > cantidad + 1)
        {
            cout << "Posicion no valida. Debe estar entre 1 y " << cantidad + 1 << "." << endl;
            return;
        }
        int indice = posicion - 1;
        for (int i = cantidad; i > indice; i--)
        {
        }
            datos[i] = datos[i - 1];
        datos[indice] = dato;
        cantidad = cantidad + 1;
        cout << "Elemento " << dato << " insertado en la posicion " << posicion << "." << endl;
    }
    void eliminar(int posicion)
    {
        if (cantidad == 0)
        {
            cout << "La lista esta vacia. No hay elementos que eliminar." << endl;
            return;
        }
        if (posicion < 1 || posicion > cantidad)
        {
            cout << "Posicion no valida. Debe estar entre 1 y " << cantidad << "." << endl;
            return;
        }
        int indice = posicion - 1;
        int eliminado = datos[indice];
        for (int i = indice; i < cantidad - 1; i++)
        {
            datos[i] = datos[i + 1];
        }
        cantidad = cantidad - 1;
        cout << "Elemento " << eliminado << " eliminado de la posicion " << posicion << "." << endl;
    }
    void buscar(int dato)
    {
        if (cantidad == 0)
        {
            cout << "La lista esta vacia." << endl;
            return;
        }
        int encontrados = 0;
        for (int i = 0; i < cantidad; i++)
        {
            if (datos[i] == dato)
            {
                cout << "El numero " << dato << " se encuentra en la posicion " << i + 1 << "." << endl;
                encontrados = encontrados + 1;
            }
        }
        if (encontrados == 0)
        {
            cout << "El numero " << dato << " no se encuentra en la lista." << endl;
        }
    }
    void modificar(int posicion, int nuevoValor)
    {
        if (cantidad == 0)
        {
            cout << "La lista esta vacia. No hay elementos que modificar." << endl;
            return;
        }
        if (posicion < 1 || posicion > cantidad)
        {
            cout << "Posicion no valida. Debe estar entre 1 y " << cantidad << "." << endl;
            return;
        }
        int indice = posicion - 1;
        cout << "Elemento de la posicion " << posicion << " cambiado de " << datos[indice]
             << " a " << nuevoValor << "." << endl;
        datos[indice] = nuevoValor;
    }
    void mostrar()
    {
        if (cantidad == 0)
        {
            cout << "La lista esta vacia." << endl;
            return;
        }
        cout << "Contenido de la lista:" << endl;
        for (int i = 0; i < cantidad; i++)
        {
            cout << i + 1 << ". " << datos[i] << endl;
        }
    }
    void mostrarCantidad()
    {
        cout << "La lista contiene " << cantidad << " de 10 elementos." << endl;
    }
};
int main()
{
    Lista lista;
    int opcion;
    int dato;
    int posicion;
    do
    {
        cout << "===== MENU =====" << endl;
        cout << "1. Insertar elemento al final" << endl;
        cout << "2. Insertar elemento en una posicion" << endl;
        cout << "3. Eliminar elemento" << endl;
        cout << "4. Buscar elemento" << endl;
        cout << "5. Modificar elemento" << endl;
        cout << "6. Mostrar lista" << endl;
        cout << "7. Mostrar cantidad de elementos" << endl;
        cout << "8. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = 0;
        }
        cout << endl;
        switch (opcion)
        {
        case 1:
            cout << "Escribe el numero entero a insertar: ";
            cin >> dato;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Entrada no valida. Debes escribir un numero entero." << endl;
                break;
            }
            lista.insertarAlFinal(dato);
            break;
        case 2:
            cout << "Posicion donde insertar (1 a 10): ";
            cin >> posicion;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Entrada no valida. Debes escribir un numero entero." << endl;
                break;
            }
            cout << "Escribe el numero entero a insertar: ";
            cin >> dato;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Entrada no valida. Debes escribir un numero entero." << endl;
                break;
            }
            lista.insertarEnPosicion(posicion, dato);
            break;
        case 3:
            cout << "Posicion a eliminar (1 a 10): ";
            cin >> posicion;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Entrada no valida. Debes escribir un numero entero." << endl;
                break;
            }
            lista.eliminar(posicion);
            break;
        case 4:
            cout << "Escribe el numero a buscar: ";
            cin >> dato;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Entrada no valida. Debes escribir un numero entero." << endl;
                break;
            }
            lista.buscar(dato);
            break;
        case 5:
            cout << "Posicion a modificar (1 a 10): ";
            cin >> posicion;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Entrada no valida. Debes escribir un numero entero." << endl;
                break;
            }
            cout << "Escribe el nuevo valor: ";
            cin >> dato;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Entrada no valida. Debes escribir un numero entero." << endl;
                break;
            }
            lista.modificar(posicion, dato);
            break;
        case 6:
            lista.mostrar();
            break;
        case 7:
            lista.mostrarCantidad();
            break;
        case 8:
            cout << "Fin del programa." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
        cout << endl;
    } while (opcion != 8);
    return 0;