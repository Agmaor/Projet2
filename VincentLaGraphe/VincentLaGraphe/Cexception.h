#pragma once

#define MEMORY_ALLOCATION_EXCEPTION 0
#define INCORRECT_INDEX_EXCEPTION 1
#define SOMMET_ALREADY_EXISTS_EXCEPTION 2
#define NONEXISTANT_SOMMET_EXCEPTION 3
#define NONEXISTENT_ARC_EXCEPTION 4
#define INCORRECT_ARGUMENT_EXCEPION 5
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

