#include "Cexception.h"


Cexception::Cexception(unsigned int uiValue)
{
	uiEXCValue = uiValue;
}


Cexception::~Cexception(void)
{
}

void Cexception::EXCPrintMessage()
{
	switch(uiEXCValue)
	{
		case MEMORY_ALLOCATION_EXCEPTION :
			printf("Error : Unable to allocate memory\n");
			break;
		case INCORRECT_INDEX_EXCEPTION :
			printf("Error : Index out of bound\n");
			break;
		case SOMMET_ALREADY_EXISTS_EXCEPTION :
			printf("Graphe error : This node already exists\n");
			break;
		case ARC_ALREADY_EXISTS_EXCEPTION :
			printf("Graphe error : This vertex already exists\n");
			break;
		case NONEXISTENT_SOMMET_EXCEPTION :
			printf("Graphe error : This node doesn't exists\n");
			break;
		case NONEXISTENT_ARC_EXCEPTION :
			printf("Graphe error : This vertex doesn't exists\n");
			break;
		case INCORRECT_ARGUMENT_EXCEPTION :
			printf("Graphe error : Wrong argument is given\n");
			break;
		default:
			printf("This error code is unknown : %d\n", uiEXCValue);
			break;
	}

}