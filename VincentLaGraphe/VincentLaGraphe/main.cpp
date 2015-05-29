#include "Graphe.h"

int main()
{
	CGraphe graphe;

	try{
			graphe.GRAAjouterSommet(0);
			graphe.GRAAjouterSommet(1);
			graphe.GRAAjouterSommet(2);
			graphe.GRAAjouterSommet(3);
			graphe.GRAAjouterSommet(4);
			graphe.GRAAjouterArc(0, 2);
			graphe.GRAAjouterArc(1, 2);
			graphe.GRAAjouterArc(2, 0);
			graphe.GRAAfficherGraphe();
	
			graphe.GRAModifierArc(0,2,2);
			graphe.GRAAfficherGraphe();

	}
	catch(Cexception ce)
	{
		ce.EXCPrintMessage();
	}

	return 0;
}