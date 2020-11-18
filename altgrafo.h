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
struct Vertice *existeVertice(struct Vertice *lista , int rotulo);
struct vAdjacente *existeAresta(struct Vertice *listaVertice, int origem ,int destino , int peso);
struct Vertice *inserirAresta(struct Vertice *listaVertice, int origem, int destino, int peso);
struct vAdjacente *insercaoAresta(struct vAdjacente *listaAdj, struct vAdjacente *novo);
struct Vertice *removerAresta(struct Vertice *listaVertice , int origem , int destino ,int peso);
struct vAdjacente *remocaoAresta(struct vAdjacente *vAdj, int rotuloVAdj, int peso);
void listaDeAdjacencia(struct Vertice *listaVertice);
struct vAdjacente *destruirVAdjacentes(struct vAdjacente *listaAdj);
struct Vertice *removerVAdjComRotulo(struct Vertice *lista, int rotuloVAdj);


#endif