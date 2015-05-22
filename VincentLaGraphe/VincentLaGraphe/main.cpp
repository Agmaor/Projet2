#include "Graphe.h"

int main()
{
	CGraphe graphe;
	graphe.GRAAjouterSommet(0);
	graphe.GRAAjouterSommet(1);
	graphe.GRAAjouterSommet(2);

	graphe.GRAAjouterArc(0, 2);
	graphe.GRAAjouterArc(1, 2);
	graphe.GRAAjouterArc(2, 0);

	graphe.GRAAfficherGraphe();

	return 0;
}