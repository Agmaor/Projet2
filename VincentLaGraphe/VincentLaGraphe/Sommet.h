#pragma once

#include "Arc.h"
#include "Cexception.h"
#include <stdlib.h>
class CSommet
{
public:
	/**************************************************************************
	*******************     CONSTRUCTORS/DESTRUCTORS     **********************
	***************************************************************************/
	/**
	* @brief CMatrix default constructor :
	* @details Causes : Create the object
	*
	* @b Needs : {}
	* @param : None
	* @return None
	*/
	CSommet(unsigned int uiNumero);
	CSommet(const CSommet & sSommet);
	~CSommet();
	
	/**************************************************************************
	*****************************     METHODS     *****************************
	***************************************************************************/
	void SOMAjouterArcArrivant(CArc * paArrivant);
	CArc * SOMCreerArcPartant(unsigned int uiIdDestination);
	void SOMSupprimerArcPartant(unsigned int uiDestination);
	void SOMSupprimerArcArrivant(CArc * paSource);
	
	/**************************************************************************
	************************     GETTERS/SETTERS     **************************
	***************************************************************************/
	CArc * SOMGetArcReliant(unsigned int uiDestination);
	unsigned int SOMGetTaillePartant();
	unsigned int SOMGetTailleArrivant();
	unsigned int SOMGetNumero();
	void SOMSetNumero(unsigned int uiNumero);
	//Pour les deux méthodes suivantes : indice n'est pas un numéro de sommet
	//mais l'indice de l'arc dans paSOMPartant ou dans paSOMArrivant
	CArc * SOMGetArcPartant(unsigned int uiIndice);
	CArc * SOMGetArcArrivant(unsigned int uiIndice);

private:
	/** @details A variable containing the ID of node*/
	CArc ** paSOMPartant;
	unsigned int uiSOMTaillePartant;
	
	CArc ** paSOMArrivant;
	unsigned int uiSOMTailleArrivant;
	
	unsigned int uiSOMNumero;

};