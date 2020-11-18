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
		aux->adj = destruirVAdjacentes(aux->adj);
		listaVertice = aux->prox;
	}
	else
	{
		aux->adj = destruirVAdjacentes(aux->adj);
		anterior->prox = aux->prox;
	}
	free(aux);

	listaVertice =  removerVAdjComRotulo(listaVertice, rotulo);


	return listaVertice;
}

struct Vertice *removerVAdjComRotulo(struct Vertice *lista, int rotuloVAdj)
{	
	struct Vertice *percorrer = lista;

	while(percorrer != NULL)
	{
		struct vAdjacente *aux = percorrer->adj;
		struct vAdjacente *anterior = NULL;
		while(aux != NULL)
		{
			if(aux->rotuloVAdj == rotuloVAdj)
			{
				if (anterior == NULL)
				{
					percorrer->adj = remocaoAresta(aux ,aux->rotuloVAdj,aux->peso);
					aux = percorrer->adj;
				}
				else
				{
					anterior->prox = remocaoAresta(aux ,aux->rotuloVAdj,aux->peso);
					aux = anterior->prox;
				}
			}
			else
			{
				anterior = aux;
				aux = aux->prox;
			}
		} 
		percorrer = percorrer->prox;
	}

	return lista;
}

struct vAdjacente *destruirVAdjacentes(struct vAdjacente *listaAdj)
{
	struct vAdjacente *anterior = NULL;
	while(listaAdj != NULL)
	{
		anterior = listaAdj;
		listaAdj = listaAdj->prox;
		free(anterior);
	}

	return listaAdj;
}


void listarVertice(struct Vertice *lista)
{
	if (lista == NULL)
		printf("Grafo Vazio\n");
	else
	{
		printf("Vertices\n");
		while(lista->prox != NULL)
		{
			printf("%d-->",lista->rotulo);
			lista = lista->prox;
		}
		printf("%d-->NULL\n",lista->rotulo);
	}
}

struct Vertice *existeVertice(struct Vertice *lista , int rotulo)
{
	while(lista != NULL)
	{
		if (lista->rotulo == rotulo)
		{

			printf("Existe\n");			
			return lista; 
		}
		lista = lista->prox;
	}
	printf("Não Existe\n");
	return NULL;
}


struct vAdjacente *existeAresta(struct Vertice *listaVertice, int origem ,int destino , int peso)
{
	while(listaVertice != NULL)
	{
		if (listaVertice->rotulo == origem)
		{	
			struct vAdjacente *vDestino = listaVertice->adj;
			while(vDestino != NULL)
			{
				if (vDestino->rotuloVAdj == destino && vDestino->peso == peso)
				{
					return vDestino;
				}
			    vDestino = vDestino->prox;
			}
		}
		listaVertice = listaVertice->prox;
	}


	return NULL; 
}



struct Vertice *inserirAresta(struct Vertice *listaVertice, int origem, int destino, int peso)
{
	struct Vertice *orig = existeVertice(listaVertice,origem);
	struct Vertice *dest = existeVertice(listaVertice, destino) ;
	struct vAdjacente *vAdj = existeAresta(listaVertice,origem ,destino, peso);
	struct vAdjacente *arestaOrig, *arestaDest;

	if (orig == NULL || dest  == NULL)
	{
		printf("Erro: Inserção de vértice(s) não existentes\n");
		return listaVertice;
	}

	if (vAdj != NULL)
	{
		printf("Aresta já existente\n");
		return listaVertice;
	}

	if (peso < 0)
	{
		printf("Não permite número negativo\n");
		return listaVertice;
	}

	arestaOrig =(struct vAdjacente *)malloc(sizeof(struct vAdjacente));
	arestaDest =(struct vAdjacente *)malloc(sizeof(struct vAdjacente));
	if (arestaOrig == NULL && arestaDest == NULL)
	{
		free(arestaOrig);
		free(arestaDest);
		return listaVertice;
	}

	arestaOrig->rotuloVAdj = destino;
	arestaOrig->peso = peso;
	arestaOrig->prox = NULL;

	arestaDest->rotuloVAdj = origem;
	arestaDest->peso = peso;
	arestaDest->prox = NULL;

	orig->adj = insercaoAresta(orig->adj, arestaOrig);
	dest->adj = insercaoAresta(dest->adj, arestaDest);

	return listaVertice;
}



struct vAdjacente *insercaoAresta(struct vAdjacente *listaAdj, struct vAdjacente *novo)
{
	struct vAdjacente *aux = listaAdj;
	struct vAdjacente *anterior = NULL;

	if (listaAdj == NULL)
	{
		return novo;
	}

	while(aux != NULL)
	{
		anterior = aux;
		aux = aux->prox;
	}

	anterior->prox = novo;

	return listaAdj; 
}

struct Vertice *removerAresta(struct Vertice *listaVertice , int origem , int destino ,int peso)
{
	struct vAdjacente *aresta = existeAresta(listaVertice,origem,destino,peso);
	struct Vertice *vOrig = existeVertice(listaVertice,origem);
	struct Vertice *vDest = existeVertice(listaVertice,destino);

	if (aresta == NULL)
	{
		printf("Erro: Aresta não existente\n");
		return listaVertice;
	}

	vOrig->adj = remocaoAresta(vOrig->adj, destino, peso);
	vDest->adj = remocaoAresta(vDest->adj, origem, peso);

	return listaVertice; 
}


struct vAdjacente *remocaoAresta(struct vAdjacente *vAdj, int rotuloVAdj, int peso)
{
	struct vAdjacente *aux, *anterior;
	aux = vAdj;
	anterior = NULL;

	while(aux != NULL && ((aux->rotuloVAdj != rotuloVAdj || aux->rotuloVAdj == rotuloVAdj ) && aux->peso != peso))
	{
		anterior = aux;
		aux = aux->prox;
	}

	if (aux == NULL)
		return vAdj;
	if (anterior == NULL)
	{
		vAdj = aux->prox;
	}
	else
	{
		anterior->prox = aux->prox;
	}

	free(aux);
	return vAdj;
}


void listaDeAdjacencia(struct Vertice *listaVertice)
{

	if (listaVertice == NULL)
	{
		printf("Grafo Vazio\n");
	}
	else
	{

		while(listaVertice != NULL)
		{
			struct vAdjacente * aux = listaVertice->adj;
			
			printf("[%d]->",listaVertice->rotulo);
			if (listaVertice->adj == NULL)
				printf("NULL\n");
			else
			{

				while(aux != NULL)
				{
					if(aux->prox == NULL)
						printf("|%d| %d |->NULL\n",aux->rotuloVAdj, aux->peso);
					else
					  printf("|%d| %d |->",aux->rotuloVAdj, aux->peso);
					aux = aux->prox;
				}
			}
			listaVertice = listaVertice->prox;
		}
	}
}