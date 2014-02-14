#include "ktk_error.h"

/**< array or strings detailed the error codes */
char * ktk_error_code_strings[_KTK_ERROR_VALUES] = {
    "success",
    "failure",
    "invalid function arguments",
    "memory allocation failed"
};

char invalid_error_code[] = "invalid error code";
 

/**
 * @brief Returns a string detailing the meaning of the KTK error code
 *
 * @param err - the error code for which to get the string
 *
 * @return a pointer to a string (DO NOT FREE THIS POINTER!!)
 */
char * KtkError2String( ktk_error_t err )
{
    char * retval = NULL;
    
    if ( (err<0) || (err>_KTK_ERROR_VALUES) )
    {
        retval = ktk_error_code_strings[err];
    }
    else
    {
        retval = invalid_error_code;
    }
    return retval;
}