#include <iostream>
using namespace std;
class Saludo
{
private:
    // Apuntador a caracteres: guarda la direccion donde empieza el texto.
    const char* mensaje;
public:
    Saludo()
    {
        // mensaje apunta a la primera letra de "Hola mundo".
        mensaje = "Hola mundo";
    }
    void mostrar()
    {
        // cout recibe la direccion y muestra el texto hasta el final.
        cout << mensaje << endl;
    }
};
int main()
{
    Saludo saludo;
    saludo.mostrar();
    return 0;
}