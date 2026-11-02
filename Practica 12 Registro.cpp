#include <iostream>
#include <string>
using namespace std;
class Persona
{
private:
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    string genero;
    int edad;
public:
    Persona()
    {
        nombre = "";
        apellidoPaterno = "";
        apellidoMaterno = "";
        genero = "";
        edad = 0;
    }
    void capturar()
    {
        cout << "Nombre: ";
        getline(cin, nombre);
        cout << "Apellido paterno: ";
        getline(cin, apellidoPaterno);
        cout << "Apellido materno: ";
        getline(cin, apellidoMaterno);
        cout << "Genero: ";
        getline(cin, genero);
        cout << "Edad: ";
        cin >> edad;
        cin.ignore(1000, '\n');
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido paterno: " << apellidoPaterno << endl;
        cout << "Apellido materno: " << apellidoMaterno << endl;
    }
        cout << "Genero: " << genero << endl;
        cout << "Edad: " << edad << endl;
};
class Auto
{
private:
    double precio;
    int anio;
public:
    Auto()
    {
        precio = 0;
        anio = 0;
    }
    void capturar()
    {
        cout << "Precio: ";
        cin >> precio;
        cout << "Anio: ";
        cin >> anio;
        cin.ignore(1000, '\n');
    }
    void mostrar()
    {
        cout << "Precio: $" << precio << endl;
        cout << "Anio: " << anio << endl;
    }
};
class Registro
{
private:
    Persona personas[5];
    Auto autos[5];
public:
    void registrarPersonas()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "--- Persona " << i + 1 << " ---" << endl;
            Persona *p = &personas[i];
            p->capturar();
            cout << endl;
        }
    }
    void registrarAutos()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "--- Auto " << i + 1 << " ---" << endl;
            Auto *a = &autos[i];
            a->capturar();
            cout << endl;
        }
    }
    void mostrarPersonas()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "--- Persona " << i + 1 << " ---" << endl;
            Persona *p = &personas[i];
            p->mostrar();
            cout << endl;
        }
    }
    void mostrarAutos()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "--- Auto " << i + 1 << " ---" << endl;
            Auto *a = &autos[i];
            a->mostrar();
            cout << endl;
        }
    }
};
int main()
{
    Registro registro;
    Registro *ptr = &registro;
    int opcion;
    do
    {
        cout << "===== MENU =====" << endl;
        cout << "1. Registrar personas" << endl;
        cout << "2. Registrar automoviles" << endl;
        cout << "3. Mostrar personas" << endl;
        cout << "4. Mostrar automoviles" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        cin.ignore(1000, '\n');
        cout << endl;
        switch (opcion)
        {
        case 1:
            ptr->registrarPersonas();
            break;
        case 2:
            ptr->registrarAutos();
            break;
        case 3:
            ptr->mostrarPersonas();
            break;
        case 4:
            ptr->mostrarAutos();
            break;
        case 5:
            cout << "Fin del programa." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl << endl;
        }
    } while (opcion != 5);
    return 0;
}