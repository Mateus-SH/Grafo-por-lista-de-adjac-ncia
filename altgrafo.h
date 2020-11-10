#ifndef ALTGRAFO_H
#define ALTGRAFO_H

struct Grafo
{
	struct Vertice *primeiroLista;
};


struct Vertice
{
	int rotulo;
	struct vAdjacente *adj;
	struct Vertice *prox;
};

struct vAdjacente
{
	int peso;
	int rotuloVAdj;
	struct vAdjacente *prox;
};

struct Grafo *criarGrafo();
struct Vertice *inserirVertice(struct Vertice *listaVertice,int rotulo);
struct Vertice *removerVertice(struct Vertice *listaVertice, int rotulo);
void listarVertice(struct Vertice *lista);



#endif