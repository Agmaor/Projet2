#pragma once
#include "Sommet.h"
#include "Graphe.h"
class CGrapheFile
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
	CGrapheFile(const char* pcFilePath);
	~CGrapheFile(void);

	/**************************************************************************
	*****************************     METHODS     *****************************
	***************************************************************************/

	/**************************************************************************
	************************     GETTERS/SETTERS     **************************
	***************************************************************************/
	const char * GRFGetFilePath(){return pcGRFFilePath;};
	CGraphe GRFParseGraphe();

private:
	CSommet ** psGRASommet;
	char * pcGRFFilePath;

	char * readFile();
};

