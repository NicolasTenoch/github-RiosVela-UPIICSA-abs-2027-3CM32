#include <iostream>
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
class Fractales
{
private:
    char lienzo[81][81];
    int alto;
    int ancho;
    void limpiar()
    {
        for (int i = 0; i < 81; i++)
        {
            char *fila = *(lienzo + i);
            for (int j = 0; j < 81; j++)
            {
                *(fila + j) = ' ';
            }
        }
    }
    void marcar(int fila, int columna, char simbolo)
    {
        if (fila >= 0 && fila < alto && columna >= 0 && columna < ancho)
        {
            char *destino = *(lienzo + fila) + columna;
            *destino = simbolo;
        }
    }
    void dibujar()
    {
        for (int i = 0; i < alto; i++)
        {
            char *fila = *(lienzo + i);
            for (int j = 0; j < ancho; j++)
            {
                cout << *(fila + j);
            }
            cout << endl;
        }
        cout << endl;
    }
    void sierpinskiRec(int fila, int columna, int tamano, int nivel)
    {
        if (nivel == 0)
        {
            marcar(fila, columna, '*');
            return;
        }
        int mitad = tamano / 2;
        sierpinskiRec(fila, columna, mitad, nivel - 1);
        sierpinskiRec(fila + mitad, columna - mitad, mitad, nivel - 1);
        sierpinskiRec(fila + mitad, columna + mitad, mitad, nivel - 1);
    }
    void cantorRec(int fila, int columna, int lado, int nivel)
    {
        if (nivel == 0)
        {
            marcar(fila, columna, '#');
            return;
        }
        int tercio = lado / 3;
        cantorRec(fila, columna, tercio, nivel - 1);
        cantorRec(fila, columna + 2 * tercio, tercio, nivel - 1);
        cantorRec(fila + 2 * tercio, columna, tercio, nivel - 1);
        cantorRec(fila + 2 * tercio, columna + 2 * tercio, tercio, nivel - 1);
    }
public:
    Fractales()
    {
        alto = 0;
    }
        ancho = 0;
        limpiar();
    bool mostrarSierpinski(int nivel)
    {
        if (nivel < 1 || nivel > 5)
        {
            cout << "El nivel debe estar entre 1 y 5." << endl;
            return false;
        }
        int tamano = 1;
        for (int i = 0; i < nivel; i++)
        {
            tamano = tamano * 2;
        }
        alto = tamano;
        ancho = 2 * tamano - 1;
        limpiar();
        sierpinskiRec(0, tamano - 1, tamano, nivel);
        cout << "Triangulo de Sierpinski, nivel " << nivel << endl << endl;
        dibujar();
        return true;
    }
    bool mostrarCantor(int nivel)
    {
        if (nivel < 1 || nivel > 4)
        {
            cout << "El nivel debe estar entre 1 y 4." << endl;
            return false;
        }
        int lado = 1;
        for (int i = 0; i < nivel; i++)
        {
            lado = lado * 3;
        }
        alto = lado;
        ancho = lado;
        limpiar();
        cantorRec(0, 0, lado, nivel);
        cout << "Polvo de Cantor, nivel " << nivel << endl << endl;
        dibujar();
        return true;
    }
};
int main()
{
    Fractales fractal;
    Fractales *ptr = &fractal;
    int opcion;
    int nivel;
    do
    {
        cout << "===== MENU =====" << endl;
        cout << "1. Mostrar triangulo de Sierpinski" << endl;
        cout << "2. Mostrar polvo de Cantor" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        opcion = leerEntero();
        cout << endl;
        switch (opcion)
        {
        case 1:
            cout << "Nivel (1 a 5): ";
            nivel = leerEntero();
            cout << endl;
            ptr->mostrarSierpinski(nivel);
            break;
        case 2:
            cout << "Nivel (1 a 4): ";
            nivel = leerEntero();
            cout << endl;
            ptr->mostrarCantor(nivel);
            break;
        case 3:
            cout << "Fin del programa." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl << endl;
        }
    } while (opcion != 3);
    return 0;
}