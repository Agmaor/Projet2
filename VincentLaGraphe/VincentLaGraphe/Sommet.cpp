#include "Sommet.h"


CSommet::CSommet(unsigned int uiNumero)
{
	paSOMArrivant = nullptr;
	paSOMPartant = nullptr;
	uiSOMTailleArrivant = 0;
	uiSOMTaillePartant = 0;
	SOMSetNumero(uiNumero);
}

CSommet::CSommet(const CSommet & sSommet)
{
	*this = sSommet;
}

CSommet::~CSommet(void)
{
	for(unsigned int uiBoucle = 0 ; uiBoucle < SOMGetTailleArrivant(); uiBoucle++)
	{
		free(paSOMArrivant[uiBoucle]);
	}
	free(paSOMArrivant);

	for(unsigned int uiBoucle = 0; uiBoucle < SOMGetTaillePartant(); uiBoucle++)
	{
		free(paSOMPartant[uiBoucle]);
	}
	free(paSOMPartant);

}
	
void CSommet::SOMAjouterArcArrivant(CArc * paArrivant)
{
	CArc ** paArrivantTemp =(CArc**)realloc(paSOMArrivant,(uiSOMTailleArrivant+1) * sizeof(CArc*));
	if(paArrivantTemp == nullptr)throw Cexception(MEMORY_ALLOCATION_EXCEPTION);

	free(paSOMArrivant);
	paSOMArrivant = paArrivantTemp;
	
	paSOMArrivant[uiSOMTailleArrivant] = paArrivant;
	uiSOMTailleArrivant++;
}

CArc * CSommet::SOMCreerArcPartant(unsigned int uiIdDestination)
{
	CArc * newArc = new CArc(uiIdDestination);
	
	CArc ** paPartantTemp =(CArc**) realloc(paSOMPartant, (uiSOMTaillePartant+1) * sizeof(CArc*));
	if(paPartantTemp == nullptr)throw Cexception(MEMORY_ALLOCATION_EXCEPTION);
	free(paSOMPartant);
	paSOMPartant = paPartantTemp;
	
	paSOMPartant[uiSOMTaillePartant] = newArc;
	uiSOMTaillePartant++;
	return newArc;
}

void CSommet::SOMSupprimerArcPartant(unsigned int uiDestination)
{
	CArc ** paPartantTemp = (CArc**)realloc(paSOMPartant, sizeof(CArc*) * (uiSOMTaillePartant-1));
	int uiIndexTemp = 0;
	for(unsigned int uiIndex = 0; uiIndex < uiSOMTaillePartant; uiIndex++)
	{
		if(uiDestination == paSOMPartant[uiIndex]->ARCGetDestination()) free(paSOMPartant[uiIndex]);
		else
		{
			paPartantTemp[uiIndexTemp] = paSOMPartant[uiIndex];
			uiIndexTemp++;
		}
		if(uiIndexTemp == uiSOMTaillePartant-1) throw Cexception(NONEXISTENT_SOMMET_EXCEPTION);
		
	}
	free(paSOMPartant);
	paSOMPartant = paPartantTemp;
	uiSOMTaillePartant--;
}

void CSommet::SOMSupprimerArcArrivant(CArc * paSource)
{
		CArc ** paArrivantTemp = (CArc**)realloc(paSOMArrivant, sizeof(CArc*) * (uiSOMTailleArrivant-1));
	int uiIndexTemp = 0;
	for(unsigned int uiIndex = 0; uiIndex < uiSOMTailleArrivant; uiIndex++)
	{
		if(paSource->ARCGetDestination() == paSOMPartant[uiIndex]->ARCGetDestination()){}
		else
		{
			paArrivantTemp[uiIndexTemp] = paSOMArrivant[uiIndex];
			uiIndexTemp++;
		}
		if(uiIndexTemp == uiSOMTailleArrivant-1) throw Cexception(NONEXISTENT_SOMMET_EXCEPTION);
		
	}
	free(paSOMArrivant);
	paSOMPartant = paArrivantTemp;
	uiSOMTaillePartant--;
}

	
CArc * CSommet::SOMGetArcReliant(unsigned int uiDestination)
{
	return nullptr;
}

unsigned int CSommet::SOMGetTaillePartant()
{
	return uiSOMTaillePartant;
}

unsigned int CSommet::SOMGetTailleArrivant()
{
	return uiSOMTailleArrivant;
}

unsigned int CSommet::SOMGetNumero()
{
	return uiSOMNumero;
}


CArc * CSommet::SOMGetArcPartant(unsigned int uiIndice)
{
	if(uiIndice >= uiSOMTaillePartant) throw Cexception(INCORRECT_INDEX_EXCEPTION);
	return paSOMPartant[uiIndice];
}

CArc * CSommet::SOMGetArcArrivant(unsigned int uiIndice)
{
	if(uiIndice >= uiSOMTailleArrivant) throw Cexception(INCORRECT_INDEX_EXCEPTION);
	return paSOMArrivant[uiIndice];
}

void CSommet::SOMSetNumero(unsigned int uiNumero)
{
	uiSOMNumero = uiNumero;
	for(unsigned uiIndex = 0; uiIndex < uiSOMTailleArrivant; uiIndex++)
	{
		paSOMArrivant[uiIndex]->ARCSetDestination(uiNumero);
	}
}
