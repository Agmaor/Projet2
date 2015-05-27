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
	//Detruit tout les arcs restant
	for(unsigned int uiBoucle = 0; uiBoucle < SOMGetTaillePartant(); uiBoucle++)
	{
		delete paSOMPartant[uiBoucle];
	}
	//On libère les tableaux
	free(paSOMPartant);
	free(paSOMArrivant);

}
	
void CSommet::SOMAjouterArcArrivant(CArc * paArrivant)
{
	//On realloue notre tableau en augmentant la taille de 1
	CArc ** paArrivantTemp =(CArc**)realloc(paSOMArrivant,(uiSOMTailleArrivant+1) * sizeof(CArc*));
	if(paArrivantTemp == nullptr)throw Cexception(MEMORY_ALLOCATION_EXCEPTION);

	paSOMArrivant = paArrivantTemp;
	
	//On ajoute notre arc à notre tableau
	paSOMArrivant[uiSOMTailleArrivant] = paArrivant;
	uiSOMTailleArrivant++;
}

CArc * CSommet::SOMCreerArcPartant(unsigned int uiIdDestination)
{
	//On test si l'arc existe déjà. Si oui, on déclenche l'exception ARC_ALREADY_EXCEPTION
	for(int uiBoucle = 0 ; uiBoucle < uiSOMTaillePartant; uiBoucle++)
	{
		if(uiIdDestination == paSOMPartant[uiBoucle]->ARCGetDestination())
			throw Cexception(ARC_ALREADY_EXISTS_EXCEPTION);
	}

	//Creation du nouvel arc
	CArc * newArc = new CArc(uiIdDestination);
	
	//On réalloue notre tableau en augmentant la taille de 1
	CArc ** paPartantTemp =(CArc**) realloc(paSOMPartant, (uiSOMTaillePartant+1) * sizeof(CArc*));
	if(paPartantTemp == nullptr)throw Cexception(MEMORY_ALLOCATION_EXCEPTION);

	paSOMPartant = paPartantTemp;
	
	//On ajoute à notre tableau d'arc partant l'arc nouvelement crée.
	paSOMPartant[uiSOMTaillePartant] = newArc;
	uiSOMTaillePartant++;

	return newArc;
}

void CSommet::SOMSupprimerArcPartant(unsigned int uiDestination)
{
	//On test la présence de l'ARC dans le tableau ArcPartant, si il n'y est pas, on déclenche l'exception NONEXISTENT_SOMMET_EXCEPTION
	if(SOMGetArcReliant(uiDestination)==nullptr) throw Cexception(NONEXISTENT_SOMMET_EXCEPTION);

	//Allocation d'un tableau de taille N-1
	CArc ** paPartantTemp = (CArc**) malloc(sizeof(CArc*) * (uiSOMTaillePartant-1));

	//On copie les elements de paSOMPartant vers notre tableau temporaire, sauf l'element que l'on souhaite supprimé.
	int uiIndexTemp = 0;
	for(unsigned int uiIndex = 0; uiIndex < uiSOMTaillePartant; uiIndex++)
	{
		if(uiDestination == paSOMPartant[uiIndex]->ARCGetDestination())
		{
			//On supprime l'arc
			free(paSOMPartant[uiIndex]);
		}
		else
		{
			paPartantTemp[uiIndexTemp] = paSOMPartant[uiIndex];
			uiIndexTemp++;
		}		
	}
	//Suppression de l'ancien tableau
	free(paSOMPartant);
	//On donne à notre tableau l'adresse du tableau temporaire
	paSOMPartant = paPartantTemp;
	uiSOMTaillePartant--;
}

void CSommet::SOMSupprimerArcArrivant(CArc * paSource)
{
	//Pour vérifier la présence du sommet, on utilise un booleen qui se met à vrai si le sommet est trouvé.
	bool presence = false;

	//Allocation d'un tableau de taille N-1.
	CArc ** paArrivantTemp = (CArc**) malloc(sizeof(CArc*) * (uiSOMTailleArrivant - 1));
	int uiIndexTemp = 0;
	for(unsigned int uiIndex = 0; uiIndex < uiSOMTailleArrivant; uiIndex++)
	{
		if(paSource == paSOMArrivant[uiIndex])
		{
			presence = true;
		}
		else
		{
			paArrivantTemp[uiIndexTemp] = paSOMArrivant[uiIndex];
			uiIndexTemp++;
		}
		
	}
	free(paSOMArrivant);
	paSOMArrivant = paArrivantTemp;

	//Si le booleen n'est pas à vrai, alors on déclenche l'exception NONEXISTENT_SOMMET_EXCEPTION
	if(!presence) throw Cexception(NONEXISTENT_SOMMET_EXCEPTION);

	uiSOMTailleArrivant--;
}

	
CArc * CSommet::SOMGetArcReliant(unsigned int uiDestination)
{
	//On cherche la présence de l'Arc dans le tableau d'arc Partant.
	for(unsigned int uiIndex = 0; uiIndex < uiSOMTaillePartant; uiIndex++)
	{
		if(paSOMPartant[uiIndex]->ARCGetDestination() == uiDestination) return paSOMPartant[uiIndex];
	}
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
	//On assigne à chaque Arc arrivant, le nouveau numero de sommet.
	for(unsigned int uiIndex = 0; uiIndex < uiSOMTailleArrivant; uiIndex++)
	{
		paSOMArrivant[uiIndex]->ARCSetDestination(uiNumero);
	}
}
