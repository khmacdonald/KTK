#ifndef _KTK_ERROR_DEFINITIONS_
#define _KTK_ERROR_DEFINITIONS_

#include <stddef.h>

#define _KTK_ERROR_VALUES       4       /**< the number of possible error codes */

#define _KTK_SUCCESS            0       /**< success */
#define _KTK_FAILURE            1       /**< generic failure */
#define _KTK_BADARGS            2       /**< invalid arguments passed */
#define _KTK_NOMEMORY           3       /**< memory allocation failure */

typedef int ktk_error_t;

/**
 * @brief Returns a string detailing the meaning of the KTK error code
 *
 * @param err - the error code for which to get the string
 *
 * @return a pointer to a string (DO NOT FREE THIS POINTER!!)
 */
char * KtkError2String( ktk_error_t err );

#endif
