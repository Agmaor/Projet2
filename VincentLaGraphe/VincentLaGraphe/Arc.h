/*************************************************************************
**************************** CLASS DESCRIPTION****************************
**************************************************************************/

/**
* @brief  This class provides methods to do basics computations on matrix.
*/

#pragma once
class CArc
{
public:

	/**************************************************************************
	*******************     CONSTRUCTORS/DESTRUCTORS     **********************
	***************************************************************************/
	/**
	* @brief CArc constructors :
	* @details Causes : Create the object and initiliazeui ARCDestination with uiSommet
	*
	* @b Needs : {}
	* @param : unsigned int : uiSommet
	* @return None
	*/
	CArc(unsigned int uiSommet);
	/**
	* @brief CArc destructor :
	* @details Causes : Delete the object
	*
	* @b Needs : {}
	* @param : None
	* @return None
	*/
	~CArc(void);

	/**************************************************************************
	*****************************     METHODS     *****************************
	***************************************************************************/

	/**************************************************************************
	************************     GETTERS/SETTERS     **************************
	***************************************************************************/
	/**
	* @brief Getters - ARCGetDestination :
	* @details Causes : Get the value of uIARCDestination
	*
	* @b Needs : {}
	* @param : None
	* @return uiARCDestination : unsigned int
	*/
	unsigned int ARCGetDestination(){return uiARCDestination;}

	/**
	* @brief Setters - ARCGetDestination :
	* @details Causes : Set the value of uiARCDestination
	*
	* @b Needs : {}
	* @param : uiARCDestination : The value you want to set
	* @return None
	*/
	void ARCSetDestination(unsigned int uiSommet);

	/**************************************************************************
	*****************************    OPERATOR     *****************************
	***************************************************************************/

private:
	/** @details A variable containing the ID of node*/
		unsigned int uiARCDestination;


};

