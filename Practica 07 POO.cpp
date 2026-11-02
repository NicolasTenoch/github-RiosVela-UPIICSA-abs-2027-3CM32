#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Auto
{
private:
    double precio;
    int anio;
public:
    void capturar()
    {
        cout << "Precio del auto: ";
        cin >> precio;
        cout << "Anio del auto: ";
        cin >> anio;
    }
    void mostrar()
    {
        cout << fixed << setprecision(2) << "Precio: $" << precio << endl;
        cout << "Anio: " << anio << endl;
    }
};
class Persona
{
private:
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    string genero;
    int edad;
public:
    void capturar()
    {
        cin.ignore();
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
    }
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido paterno: " << apellidoPaterno << endl;
        cout << "Apellido materno: " << apellidoMaterno << endl;
        cout << "Genero: " << genero << endl;
        cout << "Edad: " << edad << endl;
    }
};
int main()
{
    Auto miAuto;
    Persona miPersona;
    Auto* pAuto = &miAuto;
    Persona* pPersona = &miPersona;
    cout << "===== CAPTURA DEL AUTO =====" << endl;
    pAuto->capturar();
    cout << endl;
    cout << "===== CAPTURA DE LA PERSONA =====" << endl;
    pPersona->capturar();
    cout << endl;
    cout << "===== DATOS DEL AUTO =====" << endl;
    pAuto->mostrar();
    cout << endl;
    cout << "===== DATOS DE LA PERSONA =====" << endl;
    pPersona->mostrar();
    return 0;
}