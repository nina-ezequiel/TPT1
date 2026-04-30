#ifndef TREE_H
#define TREE_H

#include "String.h"

#define STR 1 
#define SET 2
#define LIST 3

typedef struct dataType {
	int nodeType;
	union {
		str str;
		struct {
			struct dataType* data; // Primer elemento (coleccion interna)
			struct dataType* next; // Siguiente elemento en la coleccion
		};
	};
} DataType;

typedef DataType* tData;

// Realiza una copia profunda de un nodo (incluyendo subestructuras)
tData copy_tData(tData original);

// Devuelve 1 si son iguales, 0 en caso contrario
int equal_tData(tData elem1, tData elem2);

// Crea un nodo vacío del tipo indicado (STR, LIST o SET)
tData newNodeTree(int tipo);

// Crea un nodo STR pidiendo un string por teclado
tData newNodeStr();

// Crea una LIST interactiva (puede contener STR, LIST o SET)
tData newNodeList();

// Crea un SET interactivo (sin elementos repetidos)
tData newNodeSet();

// Agrega un elemento al final de una colección (LIST o SET)
void append(tData *coleccion, tData elemento);

void insert_set(tData *coleccion, tData elemento);

void printDataRecursive(tData data);

// Muestra la estructura completa en pantalla
void printData(tData data);

// Libera toda la memoria de la estructura
void free_tData(tData data);

// Verifica si un elemento pertenece al conjunto
int pertainSet(tData elemento, tData set);

// Verifica si set1 está incluido en set2 (set1 c set2)
int inclusionSet(tData set1, tData set2);

// Unión de dos conjuntos (A u B)
tData unionSet(tData set1, tData set2);

// Intersección de dos conjuntos (A n B)
tData intersectionSet(tData set1, tData set2);

// Diferencia de conjuntos (A - B)
tData differenceSet(tData set1, tData set2);

// Devuelve la cantidad de elementos del conjunto
int cardinalitySet(tData set);

// Elimina un elemento del conjunto
tData removeFromSet(tData set, tData elemento);

// Crea nodo STR a partir de un string dado
tData newNodeStrHard(str valor);

// Crea LIST vacía
tData newEmptyNodeList();

// Crea SET vacío
tData newEmptyNodeSet();

// Concatena dos listas (retorna nueva lista)
tData concatData(tData l1, tData l2);

// Busca un elemento en una lista (retorna copia del elemento encontrado o NULL)
tData search(tData list, tData elem);

// Producto cartesiano entre dos estructuras (pueden ser STR, LIST o SET)
tData cartesianProduct(tData elem1, tData elem2);

// Función auxiliar para crear un par ordenado (como lista de 2 elementos)
tData createPair(tData first, tData second);

tData cartesianProduct(tData col1, tData col2);

tData strToList(tData str);

tData listToStr(tData list);

tData strToSet(tData str);

tData setToStr(tData set);

#endif
