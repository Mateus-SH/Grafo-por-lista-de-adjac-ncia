#include "altgrafo.h"
#include <stdio.h>
#include <stdlib.h>


struct Grafo *criarGrafo()
{
	struct Grafo *novo =(struct Grafo*)malloc(sizeof(struct Grafo));
	novo->primeiroLista = NULL;
	return novo;
}


struct Vertice *inserirVertice(struct Vertice *listaVertice,int rotulo)
{
	struct Vertice *aux = listaVertice;
	struct Vertice *anterior = NULL;
	struct Vertice *novoVertice = (struct Vertice *)malloc(sizeof(struct Vertice));

	if (novoVertice == NULL)
		return listaVertice;
	if (rotulo < 0)
	{
		free(novoVertice);
		return listaVertice;
	}
	if (listaVertice == NULL)
	{
		novoVertice->rotulo = rotulo;
		novoVertice->adj = NULL;
		novoVertice->prox = NULL;
		return novoVertice;
	}

	while(aux != NULL)
	{
		if(aux->rotulo == rotulo)
		{
			printf("Rotulo repetido\n");
			return listaVertice;
		}

		anterior = aux;
		aux = aux->prox;
	}
	
	novoVertice->rotulo = rotulo;
	novoVertice->adj = NULL;
	novoVertice->prox = NULL;
	anterior->prox = novoVertice;
	return listaVertice;
}

/*Função incompleta*/
struct Vertice *removerVertice(struct Vertice *listaVertice, int rotulo)
{
	struct Vertice *anterior = NULL;
	struct Vertice *aux = listaVertice;

	while(aux != NULL && aux->rotulo != rotulo)
	{
		anterior = aux ;
		aux = aux->prox;
	}

	if (aux == NULL)
		return listaVertice;
	if (anterior == NULL)
	{
		listaVertice = aux->prox;
	}
	else
	{
		anterior->prox = aux->prox;
	}
	free(aux);

	return listaVertice;
}




void listarVertice(struct Vertice *lista)
{


	printf("Vertices\n");
	while(lista->prox != NULL)
	{
		printf("%d-->",lista->rotulo);
		lista = lista->prox;
	}
	printf("%d-->NULL\n",lista->rotulo);


}
