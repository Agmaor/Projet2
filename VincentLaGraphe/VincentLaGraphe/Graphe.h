/*************************************************************************
**************************** CLASS DESCRIPTION****************************
**************************************************************************/

/**
* @brief  This class provides methods to do basics computations on matrix.
*/

#pragma once

#include "Sommet.h"
#include "Cexception.h"

#include <iostream>

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
	CGraphe(const char * filepath);
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
	CSommet * GRAGetSommetById(unsigned int uiId);
	unsigned int GRAGetTailleSommet() { return uiGRATailleSommet; }

	/**************************************************************************
	*****************************    OPERATOR     *****************************
	***************************************************************************/
	CGraphe & operator=(const CGraphe & gGraphe);
	
private:

	CSommet ** psGRASommet;
	unsigned int uiGRATailleSommet;
};