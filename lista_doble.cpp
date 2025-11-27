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

/* Parte A: Lista Doblemente Ligada */

/* Paso A1. Creación de la estructura y funciones básicas
   1. Declara un puntero *inicio inicializado en NULL.
   2. Implementa las funciones:
      - insertarInicio(struct Nodo **inicio, int valor)
      - insertarFinal(struct Nodo **inicio, int valor)
      - recorrerAdelante(struct Nodo *inicio)
      - recorrerAtras(struct Nodo *inicio)
      - eliminar(struct Nodo **inicio, int valor)
      - liberar(struct Nodo *inicio)
   3. Cada nuevo nodo se reserva con malloc() y se conecta con sus punteros
      anterior y siguiente.
*/

void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;

    if (*inicio != NULL) {
        (*inicio)->anterior = nuevo;
    }

    *inicio = nuevo;
}

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    struct Nodo *actual;

    if (nuevo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    if (*inicio == NULL) {
        *inicio = nuevo;
        return;
    }

    actual = *inicio;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
    nuevo->anterior = actual;
}

void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    printf("Lista hacia adelante: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void recorrerAtras(struct Nodo *inicio) {
    struct Nodo *actual = inicio;

    if (actual == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    /* ir al final */
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    printf("Lista hacia atras: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->anterior;
    }
    printf("\n");
}

void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *actual = *inicio;
    struct Nodo *anterior = NULL;

    /* Paso A4. Eliminación
       1. Pregunta al usuario el valor a eliminar.
       2. Considera tres casos:
          - El nodo está al inicio.
          - El nodo está al final.
          - El nodo está en medio.
       3. Ajusta los punteros anterior y siguiente para mantener
          la conexión entre los nodos restantes.
       4. Libera la memoria del nodo eliminado.
    */

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor no encontrado en la lista.\n");
        return;
    }

    /* El nodo está al inicio */
    if (anterior == NULL) {
        *inicio = actual->siguiente;
        if (*inicio != NULL) {
            (*inicio)->anterior = NULL;
        }
    }
    /* El nodo está al final */
    else if (actual->siguiente == NULL) {
        anterior->siguiente = NULL;
    }
    /* El nodo está en medio */
    else {
        anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = anterior;
    }

    free(actual);
}

void liberar(struct Nodo *inicio) {
    struct Nodo *tmp;

    /* Paso A5. Liberación
       Libera toda la memoria de la lista con free() y muestra el mensaje:
       printf("Memoria liberada correctamente.\n");
    */
    while (inicio != NULL) {
        tmp = inicio;
        inicio = inicio->siguiente;
        free(tmp);
    }

    printf("Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *inicio = NULL;
    int n, i, valor, valorEliminar;

    /* Paso A2. Inserción
       1. Pide al usuario cuántos valores desea insertar.
    */
    printf("Cuantos valores deseas insertar al inicio de la lista doble? ");
    scanf("%d", &n);

    /* 2. Inserta los nodos al inicio y muestra la lista hacia adelante. */
    for (i = 0; i < n; i++) {
        printf("Valor %d (inicio): ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
        recorrerAdelante(inicio);
    }

    /* 3. Luego inserta otros valores al final y muestra la lista nuevamente. */
    printf("\nCuantos valores deseas insertar al final de la lista doble? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Valor %d (final): ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
        recorrerAdelante(inicio);
    }

    /* Paso A3. Recorrido en ambos sentidos
       1. Implementa dos funciones de recorrido:
          - recorrerAdelante()
          - recorrerAtras()
       2. Verifica que los punteros se actualicen correctamente y que se pueda
          recorrer la lista en ambos sentidos.
    */
    printf("\nRecorrido final hacia adelante:\n");
    recorrerAdelante(inicio);

    printf("Recorrido final hacia atras:\n");
    recorrerAtras(inicio);

    /* Paso A4. Eliminación: preguntar valor y eliminar. */
    printf("\nQue valor deseas eliminar de la lista doble? ");
    scanf("%d", &valorEliminar);

    eliminar(&inicio, valorEliminar);

    printf("Lista despues de eliminar:\n");
    recorrerAdelante(inicio);

    /* Paso A5. Liberación */
    liberar(inicio);

    return 0;
}