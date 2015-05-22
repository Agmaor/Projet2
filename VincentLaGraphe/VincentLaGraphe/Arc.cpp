#include "Arc.h"




CArc::~CArc(void)
{
}

CArc::CArc(unsigned int uiSommet)
{
	ARCSetDestination(uiSommet);
}


void CArc::ARCSetDestination(unsigned int uiSommet)
{
	uiARCDestination = uiSommet;
}

