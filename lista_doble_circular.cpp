#include <stdio.h>
#include <stdlib.h>

/* Estructura base del nodo
   struct Nodo {
       int dato;
       struct Nodo *anterior;
       struct Nodo *siguiente;
   };
*/
struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

/* Parte B: Lista Doblemente Ligada Circular */

/* Paso B1. Creación y características
   1. Modifica la estructura anterior para volverla circular:
      - El último nodo apunta al primero en su campo siguiente.
      - El primero apunta al último en su campo anterior.
   2. Usa un puntero *inicio que apunte al primer nodo.
   3. Verifica que no haya punteros NULL.
*/

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return;
    }
    nuevo->dato = valor;

    if (*inicio == NULL) {
        /* lista vacia: el nodo se apunta a si mismo */
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *inicio = nuevo;
    } else {
        struct Nodo *ultimo = (*inicio)->anterior;

        /* Paso B2. Inserción circular
           3. Asegúrate de que el nuevo nodo apunte correctamente:
              - siguiente al primero.
              - anterior al último.
              - Que los enlaces del primero y último se actualicen adecuadamente.
           Ejemplo:
           nuevo->siguiente = *inicio;
           nuevo->anterior = (*inicio)->anterior;
           (*inicio)->anterior->siguiente = nuevo;
           (*inicio)->anterior = nuevo;
        */
        nuevo->siguiente = *inicio;
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
        (*inicio)->anterior = nuevo;
    }
}

/* Paso B3. Recorrido circular
   1. Recorre la lista desde el primer nodo hasta volver al inicio.
   2. Muestra los datos y verifica que el enlace circular sea correcto.
*/
void recorrerCircular(struct Nodo *inicio) {
    struct Nodo *actual;

    if (inicio == NULL) {
        printf("Lista doblemente ligada circular vacia\n");
        return;
    }

    printf("Lista doblemente ligada circular: ");
    actual = inicio;
    do {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    } while (actual != inicio);
    printf("\n");
}

/* Paso B4. Eliminación circular
   1. Implementa eliminarCircular(struct Nodo **inicio, int valor) que:
      - Si es el único nodo, libera la lista.
      - Si es el primero o último, actualiza punteros circulares.
      - Si está en medio, ajusta anterior y siguiente.
   2. Muestra la lista resultante después de eliminar.
*/
void eliminarCircular(struct Nodo **inicio, int valor) {
    struct Nodo *actual, *anterior;

    if (*inicio == NULL) {
        printf("Lista circular vacia, no se puede eliminar.\n");
        return;
    }

    actual = *inicio;
    anterior = NULL;

    /* buscar el nodo con ese valor */
    do {
        if (actual->dato == valor) break;
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *inicio);

    if (actual->dato != valor) {
        printf("Valor no encontrado en la lista circular.\n");
        return;
    }

    /* Si es el único nodo, libera la lista. */
    if (actual->siguiente == actual && actual->anterior == actual) {
        free(actual);
        *inicio = NULL;
        return;
    }

    /* Si es el primero o último, actualiza punteros circulares.
       (el caso de último también se ajusta con los enlaces generales)
    */
    if (actual == *inicio) {
        *inicio = actual->siguiente;
    }

    /* Ajusta anterior y siguiente (vale para medio y último). */
    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;

    free(actual);
}

int main() {
    struct Nodo *inicio = NULL;
    struct Nodo *actual, *tmp;
    int n, i, valor, valorEliminar;

    /* Paso B2. Inserción circular
       1. Pide al usuario cuántos valores desea insertar.
       2. Inserta los nodos al final de la lista.
    */
    printf("Cuantos valores deseas insertar en la lista doble circular? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
        recorrerCircular(inicio);
    }

    /* Paso B3. Recorrido circular */
    printf("\nRecorrido final de la lista doble circular:\n");
    recorrerCircular(inicio);

    /* Paso B4. Eliminación circular */
    printf("Que valor deseas eliminar de la lista doble circular? ");
    scanf("%d", &valorEliminar);

    eliminarCircular(&inicio, valorEliminar);

    printf("Lista doble circular despues de eliminar:\n");
    recorrerCircular(inicio);

    /* Liberar memoria de la lista circular (opcional) */
    if (inicio != NULL) {
        actual = inicio->siguiente;
        while (actual != inicio) {
            tmp = actual;
            actual = actual->siguiente;
            free(tmp);
        }
        free(inicio);
    }

    return 0;
}