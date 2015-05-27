#pragma once
#include <stdio.h>
#define MEMORY_ALLOCATION_EXCEPTION 0
#define INCORRECT_INDEX_EXCEPTION 1
#define SOMMET_ALREADY_EXISTS_EXCEPTION 2
#define ARC_ALREADY_EXISTS_EXCEPTION 3
#define NONEXISTENT_SOMMET_EXCEPTION 4
#define NONEXISTENT_ARC_EXCEPTION 5
#define INCORRECT_ARGUMENT_EXCEPTION 6
class Cexception
{
public:
	Cexception(unsigned int uiError);
	~Cexception(void);

	unsigned int EXCGetValue(){return uiEXCValue;}
	void EXCPrintMessage();

private:
	unsigned int uiEXCValue;
};

