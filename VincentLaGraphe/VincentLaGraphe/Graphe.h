/*************************************************************************
**************************** CLASS DESCRIPTION****************************
**************************************************************************/

/**
* @brief  This class provides methods to do basics computations on matrix.
*/

#pragma once
#include <stdio.h>
#include "Sommet.h"

class CGraphe
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
	CGraphe();
	CGraphe(const CGraphe & gGraphe);
	~CGraphe();

	/**************************************************************************
	*****************************     METHODS     *****************************
	***************************************************************************/
	void GRAAjouterSommet(unsigned int uiSommet);
	void GRAModifierSommet(unsigned int uiSommet, unsigned int uiNouveauSommet);
	void GRASupprimerSommet(unsigned int uiSommet);
	void GRAAjouterArc(unsigned int uiSommetSource, unsigned int uiSommetDestination);
	void GRAModifierArc(unsigned int uiSource, unsigned int uiDestination, unsigned int uiNouvelleDestination);
	void GRASupprimerArc(unsigned int uiSource, unsigned int uiDestination);
	void GRAAfficherGraphe();
	
	/**************************************************************************
	************************     GETTERS/SETTERS     **************************
	***************************************************************************/
	CSommet * GRAGetSommet(unsigned int uiIndice);
	unsigned int GRAGetTailleSommet();

	/**************************************************************************
	*****************************    OPERATOR     *****************************
	***************************************************************************/
	CGraphe & operator=(const CGraphe & gGraphe);
	
private:

	CSommet ** psGRASommet;
	unsigned int uiGRATailleSommet;
};