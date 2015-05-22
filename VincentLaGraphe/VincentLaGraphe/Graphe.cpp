#include "Graphe.h"


CGraphe::CGraphe(void)
{
}

CGraphe::CGraphe(const CGraphe & gGraphe)
{
	*this = gGraphe;
}


CGraphe::~CGraphe(void)
{
}

void CGraphe::GRAAjouterSommet(unsigned int uiSommet)
{
}

void CGraphe::GRAModifierSommet(unsigned int uiSommet, unsigned int uiNouveauSommet)
{
}

void CGraphe::GRASupprimerSommet(unsigned int uiSommet)
{
}

void CGraphe::GRAAjouterArc(unsigned int uiSommetSource, unsigned int uiSommetDestination)
{
}

void CGraphe::GRAModifierArc(unsigned int uiSource, unsigned int uiDestination, unsigned int uiNouvelleDestination)
{
}

void CGraphe::GRASupprimerArc(unsigned int uiSource, unsigned int uiDestination)
{
}

void CGraphe::GRAAfficherGraphe()
{
	for(unsigned int uiBoucle = 0; uiBoucle < uiGRATailleSommet; uiBoucle++)
	{
		for(unsigned int uiBoucle2 = 0; uiBoucle2 < psGRASommet[uiBoucle]->SOMGetTaillePartant(); uiBoucle2++)
		{
			printf("%d\t------>\t%d\n",psGRASommet[uiBoucle]->SOMGetNumero(), psGRASommet[uiBoucle]->SOMGetArcPartant(uiBoucle2)->ARCGetDestination);
		}
		printf("\n");
	}
}

	
CSommet * CGraphe::GRAGetSommet(unsigned int uiIndice)
{
	return nullptr;
}

unsigned int CGraphe::GRAGetTailleSommet()
{
	return 0;
}

CGraphe & CGraphe::operator=(const CGraphe & gGraphe)
{
	return CGraphe();
}
