#include "Graphe.h"


CGraphe::CGraphe(void)
{
	psGRASommet = nullptr;
	uiGRATailleSommet = 0;
}

CGraphe::CGraphe(const CGraphe & gGraphe)
{
	*this = gGraphe;
}

CGraphe::~CGraphe(void)
{
	for(unsigned int uiIndex = 0; uiIndex < uiGRATailleSommet; uiIndex++)
		delete psGRASommet[uiIndex];

	delete[] psGRASommet;
}

void CGraphe::GRAAjouterSommet(unsigned int uiSommet)
{
	if(GRAGetSommetById(uiSommet) != nullptr)
		throw Cexception(SOMMET_ALREADY_EXISTS_EXCEPTION);

	uiGRATailleSommet++;
	
	CSommet ** psNewSommet = (CSommet **) realloc(psGRASommet, sizeof(CSommet *) * uiGRATailleSommet);
	if(psNewSommet == nullptr)
		throw Cexception(MEMORY_ALLOCATION_EXCEPTION);

	//free(psGRASommet);
	psGRASommet = psNewSommet;
	psGRASommet[uiGRATailleSommet - 1] = new CSommet(uiSommet);
}

void CGraphe::GRAModifierSommet(unsigned int uiSommet, unsigned int uiNouveauSommet)
{
	CSommet * sSommet = GRAGetSommetById(uiSommet);
	if(sSommet == nullptr)
		throw Cexception(NONEXISTENT_SOMMET_EXCEPTION);
	if (GRAGetSommetById(uiNouveauSommet) != nullptr)
		throw Cexception(SOMMET_ALREADY_EXISTS_EXCEPTION);

	sSommet->SOMSetNumero(uiNouveauSommet);
}

void CGraphe::GRASupprimerSommet(unsigned int uiSommet)
{
	if(GRAGetSommetById(uiSommet) == nullptr)
		throw Cexception(NONEXISTENT_SOMMET_EXCEPTION);

	uiGRATailleSommet--;
	CSommet ** psNewSommets = (CSommet **) realloc(psGRASommet, sizeof(CSommet *) * uiGRATailleSommet);
	if(psNewSommets == nullptr)
		throw Cexception(MEMORY_ALLOCATION_EXCEPTION);

	int offset = 0;
	CSommet * psToRemove = GRAGetSommetById(uiSommet);
	
	//uiIndex <= uiGRATailleSommet because we still want to loop over all the nodes from psGRASommet
	for(unsigned int uiIndex = 0; uiIndex <= uiGRATailleSommet; uiIndex++)
	{
		//Then we delete vertices from all nodes from which ingoing vertices come to the node to remove
		for(unsigned int uiSubIndex = 0; uiSubIndex < psToRemove->SOMGetTaillePartant(); uiSubIndex++)
		{
			CArc * paArcToRemove = psToRemove->SOMGetArcPartant(uiSubIndex);

			if(psGRASommet[uiIndex]->SOMGetNumero() == paArcToRemove->ARCGetDestination())
			{
				psGRASommet[uiIndex]->SOMSupprimerArcArrivant(paArcToRemove);
				uiIndex--;
			}
		}
		
		//We only copy the nodes that are not to be deleted
		if(psGRASommet[uiIndex] != psToRemove)
		{
			psNewSommets[uiIndex + offset] = psGRASommet[uiIndex];
		}
		else
		{
			offset -= 1;
		}
	}

	delete psToRemove;
	free(psGRASommet);
	
	psGRASommet = psNewSommets;
}

void CGraphe::GRAAjouterArc(unsigned int uiSommetSource, unsigned int uiSommetDestination)
{
	CSommet * psSource = GRAGetSommetById(uiSommetSource);
	CSommet * psDest = GRAGetSommetById(uiSommetDestination);

	if(psSource == nullptr || psDest == nullptr)
		throw Cexception(NONEXISTENT_SOMMET_EXCEPTION);

	CArc * paArc = psSource->SOMCreerArcPartant(uiSommetDestination);
	psDest->SOMAjouterArcArrivant(paArc);
}

void CGraphe::GRAModifierArc(unsigned int uiSource, unsigned int uiDestination, unsigned int uiNouvelleDestination)
{
	if(uiDestination == uiNouvelleDestination)
		throw Cexception(INCORRECT_ARGUMENT_EXCEPTION);

	CSommet * psSource = GRAGetSommetById(uiSource);
	CSommet * psOldDest = GRAGetSommetById(uiDestination);
	CSommet * psNewDest = GRAGetSommetById(uiNouvelleDestination);

	if(psSource == nullptr || psOldDest == nullptr || psNewDest == nullptr)
		throw Cexception(NONEXISTENT_SOMMET_EXCEPTION);

	CArc * paArc = psSource->SOMGetArcReliant(uiDestination);
	if(paArc == nullptr)
		throw Cexception(NONEXISTENT_ARC_EXCEPTION);
	
	psOldDest->SOMSupprimerArcArrivant(paArc);
	paArc->ARCSetDestination(uiNouvelleDestination);
	psNewDest->SOMAjouterArcArrivant(paArc);


}

void CGraphe::GRASupprimerArc(unsigned int uiSource, unsigned int uiDestination)
{
	CSommet * psSource = GRAGetSommetById(uiSource);
	CSommet * psDest = GRAGetSommetById(uiDestination);

	if(psSource == nullptr || psDest == nullptr)
		throw Cexception(NONEXISTENT_SOMMET_EXCEPTION);

	//We delete all outgoing vertices which go to the node to remove
	CArc * paArc = psSource->SOMGetArcReliant(uiDestination);
	if(paArc == nullptr)
		throw Cexception(NONEXISTENT_ARC_EXCEPTION);
	
	psDest->SOMSupprimerArcArrivant(paArc);
	psSource->SOMSupprimerArcPartant(uiDestination);
}

void CGraphe::GRAAfficherGraphe()
{
	for(unsigned int uiBoucle = 0; uiBoucle < uiGRATailleSommet; uiBoucle++)
	{
		for(unsigned int uiBoucle2 = 0; uiBoucle2 < psGRASommet[uiBoucle]->SOMGetTaillePartant(); uiBoucle2++)
		{
			printf("%d\t------>\t%d\n",psGRASommet[uiBoucle]->SOMGetNumero(), psGRASommet[uiBoucle]->SOMGetArcPartant(uiBoucle2)->ARCGetDestination());
		}
		printf("\n");
	}
}
	
CSommet * CGraphe::GRAGetSommet(unsigned int uiIndice)
{
	if(uiIndice < 0 || uiIndice >= uiGRATailleSommet)
		throw Cexception(INCORRECT_INDEX_EXCEPTION);
	
	return psGRASommet[uiIndice];
}

CGraphe & CGraphe::operator=(const CGraphe & gGraphe)
{
	uiGRATailleSommet = gGraphe.uiGRATailleSommet;

	psGRASommet = (CSommet **) malloc(sizeof(CSommet *) * uiGRATailleSommet);
	if(psGRASommet == nullptr)
		throw Cexception(MEMORY_ALLOCATION_EXCEPTION);
	
	for(unsigned int uiBoucle = 0; uiBoucle < uiGRATailleSommet; uiBoucle++)
		psGRASommet[uiBoucle] = new CSommet(* gGraphe.psGRASommet[uiBoucle]);

	return *this;
}

CSommet * CGraphe::GRAGetSommetById(unsigned int uiId)
{
	for(unsigned int uiBoucle = 0; uiBoucle < uiGRATailleSommet; uiBoucle++)
	{
		if(psGRASommet[uiBoucle]->SOMGetNumero() == uiId)
			return psGRASommet[uiBoucle];
	}

	return nullptr;
}