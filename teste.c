#include "altgrafo.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct Grafo *grafo = criarGrafo();
	struct Vertice *enderecoVertice = NULL;
	/*struct Aresta *Conjunto;*/
	int numArestas;

	grafo->primeiroLista = inserirVertice(grafo->primeiroLista, 1);
	grafo->primeiroLista = inserirVertice(grafo->primeiroLista, 12);
	grafo->primeiroLista = inserirVertice(grafo->primeiroLista, 2);
	grafo->primeiroLista = inserirVertice(grafo->primeiroLista, 42);


	grafo->primeiroLista = inserirAresta(grafo->primeiroLista,1, 12, 13);
	grafo->primeiroLista = inserirAresta(grafo->primeiroLista,1, 2, 14);
	grafo->primeiroLista = inserirAresta(grafo->primeiroLista,2, 42, 7);
	grafo->primeiroLista = inserirAresta(grafo->primeiroLista,42, 12, 9);
	/*listaDeAdjacencia(grafo->primeiroLista);
	Conjunto = inicializarConjunto(grafo->primeiroLista, &numArestas);
	free(Conjunto);*/


	grafo->primeiroLista = removerVertice(grafo->primeiroLista, 1);
	listaDeAdjacencia(grafo->primeiroLista);	
	printf("\n");
	grafo->primeiroLista = removerVertice(grafo->primeiroLista, 25);
	listaDeAdjacencia(grafo->primeiroLista);
	printf("\n");
	grafo->primeiroLista = removerAresta(grafo->primeiroLista, 2, 42, 7);
	listaDeAdjacencia(grafo->primeiroLista);
	printf("\n");
	grafo->primeiroLista = removerVertice(grafo->primeiroLista, 0);
	grafo->primeiroLista = removerVertice(grafo->primeiroLista, 2);
	listaDeAdjacencia(grafo->primeiroLista);
	printf("\n");
	grafo->primeiroLista = removerVertice(grafo->primeiroLista, 12);
	listaDeAdjacencia(grafo->primeiroLista);
	printf("\n");
	listaDeAdjacencia(grafo->primeiroLista);
	printf("\n");
	grafo->primeiroLista = removerVertice(grafo->primeiroLista, 42);
	listaDeAdjacencia(grafo->primeiroLista);
	printf("\n");





	
	return 0;
}