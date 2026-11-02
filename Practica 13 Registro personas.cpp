#include <iostream>
#include <string>
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
    cin.ignore(10000, '\n');
    return valor;
}
class Persona
{
private:
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    string genero;
    int edad;
    void capturarEdad()
    {
        cout << "Edad: ";
        edad = leerEntero();
        while (edad < 0 || edad > 120)
        {
            cout << "La edad debe estar entre 0 y 120. Intenta de nuevo: ";
            edad = leerEntero();
        }
    }
public:
    Persona()
    {
        nombre = "";
        apellidoPaterno = "";
        apellidoMaterno = "";
    }
        genero = "";
        edad = 0;
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
        capturarEdad();
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido paterno: " << apellidoPaterno << endl;
        cout << "Apellido materno: " << apellidoMaterno << endl;
        cout << "Genero: " << genero << endl;
        cout << "Edad: " << edad << endl;
    }
    void modificar()
    {
        cout << "Que dato deseas modificar?" << endl;
        cout << "1. Nombre" << endl;
        cout << "2. Apellido paterno" << endl;
        cout << "3. Apellido materno" << endl;
        cout << "4. Genero" << endl;
        cout << "5. Edad" << endl;
        cout << "Elige una opcion: ";
        int opcion = leerEntero();
        switch (opcion)
        {
        case 1:
            cout << "Nuevo nombre: ";
            getline(cin, nombre);
            break;
        case 2:
            cout << "Nuevo apellido paterno: ";
            getline(cin, apellidoPaterno);
            break;
        case 3:
            cout << "Nuevo apellido materno: ";
            getline(cin, apellidoMaterno);
            break;
        case 4:
            cout << "Nuevo genero: ";
            getline(cin, genero);
            break;
        case 5:
            capturarEdad();
            break;
        default:
            cout << "Opcion no valida. No se modifico ningun dato." << endl;
            return;
        }
        cout << "Dato modificado correctamente." << endl;
    }
};
class RegistroPersonas
{
private:
    Persona personas[5];
    Persona *ptrPersona;
    bool registradas;
    bool hayRegistros()
    {
        if (!registradas)
        {
            cout << "Primero registra a las personas (opcion 1)." << endl << endl;
            return false;
        }
        return true;
    }
    int pedirPosicion()
    {
        cout << "Posicion de la persona (1 a 5): ";
        int posicion = leerEntero();
        while (posicion < 1 || posicion > 5)
        {
            cout << "Posicion no valida. Escribe un numero del 1 al 5: ";
            posicion = leerEntero();
        }
    }
        cout << endl;
        return posicion;
public:
    RegistroPersonas()
    {
        ptrPersona = personas;
        registradas = false;
    }
    void registrarPersonas()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "--- Persona " << i + 1 << " ---" << endl;
            (ptrPersona + i)->capturar();
            cout << endl;
        }
        registradas = true;
    }
    void mostrarPersonas()
    {
        if (!hayRegistros())
        {
            return;
        }
        for (int i = 0; i < 5; i++)
        {
            cout << "--- Persona " << i + 1 << " ---" << endl;
            (ptrPersona + i)->mostrar();
            cout << endl;
        }
    }
    void buscarPersona()
    {
        if (!hayRegistros())
        {
            return;
        }
        int posicion = pedirPosicion();
        cout << "--- Persona " << posicion << " ---" << endl;
    }
        (ptrPersona + (posicion - 1))->mostrar();
        cout << endl;
    void modificarPersona()
    {
        if (!hayRegistros())
        {
            return;
        }
        int posicion = pedirPosicion();
        cout << "--- Persona " << posicion << " ---" << endl;
        (ptrPersona + (posicion - 1))->mostrar();
        cout << endl;
        (ptrPersona + (posicion - 1))->modificar();
        cout << endl;
    }
};
int main()
{
    RegistroPersonas registro;
    int opcion;
    do
    {
        cout << "===== MENU =====" << endl;
        cout << "1. Registrar personas" << endl;
        cout << "2. Mostrar personas" << endl;
        cout << "3. Buscar persona" << endl;
        cout << "4. Modificar persona" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opcion: ";
        opcion = leerEntero();
        cout << endl;
        switch (opcion)
        {
        case 1:
            registro.registrarPersonas();
            break;
        case 2:
            registro.mostrarPersonas();
            break;
        case 3:
            registro.buscarPersona();
            break;
        case 4:
            registro.modificarPersona();
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