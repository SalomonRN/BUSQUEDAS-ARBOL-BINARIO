#include <iostream>
#include <conio.h>
using namespace std;
struct Nodo
{
    int dato;
    Nodo *izquierda;
    Nodo *derecha;
};

bool preorden(Nodo *, int);
bool inorden(Nodo *, int);
bool posorden(Nodo *, int);
void preordenArbol(Nodo *);
void inordenArbol(Nodo *);
void posordenArbol(Nodo *);
void insertarArbol(Nodo *&, int);
void mostrarArbol(Nodo *, int);
void eliminar(Nodo *&arbol, int n);
void menu();
Nodo *crearNodo(int);
Nodo *arbol = NULL;
int main()
{
    menu();
    getch();
    return 0;
}
void menu()
{
    int opcion, dato, metodo, cont;
    do
    {

        cout << "\n*MENU\n";
        cout << "1.Quieres Insertar un Elemento?\n";
        cout << "2.Quieres utilizar metodo preOrden\n";
        cout << "3.Quieres utilizar metodo inOrden\n";
        cout << "4.Quieres utilizar metodo posOrden\n";
        cout << "5.Quieres Eliminar un Elemento\n";
        cout << "6.Quieres mostrar un Elemento\n";
        cout << "7.Elimianr Nodo\n";
        cout << "0.SALIR \n";
        cout << "Deseo: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            cout << "Digite numero  ";
            cin >> dato;
            insertarArbol(arbol, dato);
            break;
        case 2:
            preordenArbol(arbol);
            cout << "\nDigite numero a buscar  ";
            cin >> dato;
            preorden(arbol, dato);
            break;
        case 3:
            inordenArbol(arbol);
            cout << "Digite numero a buscar  ";
            cin >> dato;
            inorden(arbol, dato);
            break;
        case 4:
            posordenArbol(arbol);
            cout << "Digite numero a buscar  ";
            cin >> dato;
            posorden(arbol, dato);
            break;
        case 5:
            cout << "Digite numero a eliminar ";
            cin >> dato;
            eliminar(arbol, dato);
            break;
        case 6:
            mostrarArbol(arbol, cont);
            break;
        }
    } while (opcion != 0);
}
Nodo *crearNodo(int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->derecha = NULL;
    nuevo_nodo->izquierda = NULL;
    return nuevo_nodo;
}
void insertarArbol(Nodo *&arbol, int n)
{
    Nodo *nuevo_nodo = new Nodo();
    if (arbol == NULL)
    {
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else
    {
        if (arbol->dato == n)
        {
            cout << "VALOR YA INGRESADO" << endl;
            return;
        }
        int Raiz = arbol->dato;
        if (n < Raiz)
        {
            insertarArbol(arbol->izquierda, n);
        }
        else
        {
            insertarArbol(arbol->derecha, n);
        }
    }
}
void mostrarArbol(Nodo *arbol, int cont)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrarArbol(arbol->derecha, cont + 1);
        for (int i = 0; i < cont; i++)
        {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izquierda, cont + 1);
    }
}
void preordenArbol(Nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        cout << arbol->dato << " - ";
        inordenArbol(arbol->izquierda);
        inordenArbol(arbol->derecha);
    }
}
bool preorden(Nodo *arbol, int n)
{
    if (arbol == NULL)
    {
        return false;
    }

    if (arbol->dato == n)
    {
        cout << "El numero " << n << " fue encontrado " << endl;
        return true;
    }

    cout << arbol->dato << " - ";

    bool encontradoIzquierda = preorden(arbol->izquierda, n);
    if (encontradoIzquierda)
    {
        return true;
    }
    bool encontradoDerecha = preorden(arbol->derecha, n);
    if (encontradoDerecha)
    {
        return true;
    }
    return false;
}
void inordenArbol(Nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        inordenArbol(arbol->izquierda);
        cout << arbol->dato << " - ";
        inordenArbol(arbol->derecha);
    }
}
bool inorden(Nodo *arbol, int n)
{
    if (arbol == NULL)
    {
        return false;
    }

    if (arbol->dato == n)
    {
        cout << "El numero " << n << " fue encontrado " << endl;
        return true;
    }
    bool encontradoIzquierda = preorden(arbol->izquierda, n);
    if (encontradoIzquierda)
    {
        return true;
    }
    cout << arbol->dato << " - ";

    bool encontradoDerecha = preorden(arbol->derecha, n);
    if (encontradoDerecha)
    {
        return true;
    }
    return false;
}
void posordenArbol(Nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        posordenArbol(arbol->izquierda);
        posordenArbol(arbol->derecha);
        cout << arbol->dato << " - ";
    }
}
bool posorden(Nodo *arbol, int n)
{
    if (arbol == NULL)
    {
        return false;
    }

    if (arbol->dato == n)
    {
        cout << "El numero " << n << " fue encontrado " << endl;
        return true;
    }
    bool encontradoIzquierda = preorden(arbol->izquierda, n);
    if (encontradoIzquierda)
    {
        return true;
    }
    bool encontradoDerecha = preorden(arbol->derecha, n);
    if (encontradoDerecha)
    {
        return true;
    }
    cout << arbol->dato << " - ";
    return false;
}

void eliminar(Nodo *&arbol, int n)
{
    // SE RETORNA CUANDO NO EXISTE NADA MAS QUE COMPROBAR, O SI EL ARBOL ESTA VACIO
    if (arbol == NULL)
    {
        return;
    }
    if (n < arbol->dato) // BUSCAR POR IZQUIERDA
    {
        // SE MANDA LA RAMA DE LA IZQUIERDA JUNTO CON EL NUMERO A BUSCAR
        eliminar(arbol->izquierda, n);
    }
    else if (n > arbol->dato) // BUSCAR POR DERECHA
    {
        // SE MANDA LA RAMA DE LA DERECHA JUNTO CON EL NUMERO A BUSCAR
        eliminar(arbol->derecha, n);
    }
    // CUANDO EL VALOR YA SE ENCONTRÓ (ES LA RAMA ACTUAL)
    else
    {

        if (arbol->izquierda == NULL && arbol->derecha == NULL) // LA RAMA NO TIENE HIJOS
        {
            arbol = NULL; // SE VUELVE NULO EL NODO actual de Arbol
        }
        // La RAMA tiene un hijo
        else if (arbol->izquierda == NULL) // VALIDA SI NO TIENE HIJO IZQUIERDO
        {
            Nodo *aux = arbol;      // SE DUPLICA EL VALOR DE ARBOL
            arbol = arbol->derecha; // SE REEMPLAZA EL NODO ACTUAL AL NODO HIJO DE LA DERECHA
            aux = NULL;             // SE VUELVE NULO EL NODO actual de Arbol
        }
        else if (arbol->derecha == NULL) // NO TIENE HIJO DERECHO
        {
            Nodo *aux = arbol;        // SE DUPLICA EL VALOR DE ARBOL
            arbol = arbol->izquierda; // SE REEMPLAZA EL NODO ACTUAL AL NODO HIJO DE LA DERECHA
            aux = NULL;               // SE VUELVE NULO EL NODO actual de Arbol
        }
        // LA RAMA TIENE 2 HIJOS
        else
        {
            // SE RECORRE PARA ENCONTRAR EL VALOR MAS PEQUEÑO DE LA RAMA DE LA DERECHA
            Nodo *aux = arbol->derecha;
            while (aux->izquierda != NULL)
            {
                aux = aux->izquierda;
            }
            // SE DUPLICA EL VALOR DE LA RAMA ACTUAL (QUE ES EL DATO A ELIMINAR) AL VALOR MAS PEQUEÑO DE LA PARTE DE LA DERECHA
            arbol->dato = aux->dato;
            /**
             * Ahora se vuelve a llamar a la funcion para eliminar el Nodo "REPETIDO" (VALOR MAS PEQUEÑO) PARA QUE NO QUEDEN DOS VALORES IGUALES
             * (EN ESTOS MOMENTOS HAY DOS DATOS IGUALES, ENTONCES TOCA ELIMINAR EL REPETIDO NUMERO 2 PORQUE ESE VALOR FUE 'MOVIDO' A LA POSICION QUE SE QUERIA ELIMINAR)
             * SE LE PASA LA RAMA DE LA DERECHA DEL ARBOL ACTUAL, JUNTO CON EL VALOR DE DICHA RAMA A QUITAR (SE LE PASA LA RAMA DE LA DERECHA PORQUE SI SE PASA LA ACTUAL ELIMINARIA LA RAMA ACTUAL, Y LO QUE SE QUIERE ES QUE ELIMINE EL NODO DEL FINAL)
             */
            eliminar(arbol->derecha, aux->dato);
        }
    }
}