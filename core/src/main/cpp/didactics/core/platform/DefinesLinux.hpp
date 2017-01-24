
#ifndef DEFINESLINUX_HPP
#define DEFINESLINUX_HPP

#include <linux/types.h>
#include <cstdint>

#define OS_SUCCESS                     (0)
#define OS_ERROR                       (-1)
#define OS_INVALID_POINTER             (-2)
#define OS_ERROR_ADDRESS_MISALIGNED    (-3)
#define OS_ERROR_TIMEOUT               (-4)
#define OS_INVALID_INT_NUM             (-5)
#define OS_SEM_FAILURE                 (-6)
#define OS_SEM_TIMEOUT                 (-7)
#define OS_QUEUE_EMPTY                 (-8)
#define OS_QUEUE_FULL                  (-9)
#define OS_QUEUE_TIMEOUT               (-10)
#define OS_QUEUE_INVALID_SIZE          (-11)
#define OS_QUEUE_ID_ERROR              (-12)
#define OS_ERR_NAME_TOO_LONG           (-13)
#define OS_ERR_NO_FREE_IDS             (-14)
#define OS_ERR_NAME_TAKEN              (-15)
#define OS_ERR_INVALID_ID              (-16)
#define OS_ERR_NAME_NOT_FOUND          (-17)
#define OS_ERR_SEM_NOT_FULL            (-18)
#define OS_ERR_INVALID_PRIORITY        (-19)
#define OS_INVALID_SEM_VALUE           (-20)
#define OS_ERR_FILE                    (-27)
#define OS_ERR_NOT_IMPLEMENTED         (-28)
#define OS_TIMER_ERR_INVALID_ARGS      (-29)
#define OS_TIMER_ERR_TIMER_ID          (-30)
#define OS_TIMER_ERR_UNAVAILABLE       (-31)
#define OS_TIMER_ERR_INTERNAL          (-32)
/*!
 * @brief OS_START_ERROR is where the Applicatin specific error values start.
 */
#define OS_START_ERROR     20000
#define OK 0
#define SUCCESS OK
#define FAILURE -1
#define WAIT_FOREVER                ((std::uint32_t) -1)
/*!
 * @brief Type for specifying an error or status code.
 */
#define DECLARE(type) type
/*!
 * @brief OS_ERRSPACE_SIZE is the maximum number of errors you can fit
 *        into one of the error/status ranges below.
 */
#define OS_ERRSPACE_SIZE 60000
/*!
 * @brief UTIL_ERRSPACE_SIZE is the size of the space that is reserved for
 *          use within applocatin. This space is reserved above that used by RTOS
 *          internally.
 */

#define UTIL_ERRSPACE_SIZE 20000

/*!
 * @brief OS_START_STATUS is where the APR specific status codes start.
 */
#define OS_START_STATUS    (OS_START_ERROR + OS_ERRSPACE_SIZE)

#define OS_START_USERERR    (OS_START_STATUS + OS_ERRSPACE_SIZE)
/*!
 * @brief OS_START_CANONERR is where applicatins versions of errno values are defined
 *      on systems which don't have the corresponding errno.
 */
#define OS_START_CANONERR  (OS_START_USERERR + (OS_ERRSPACE_SIZE * 10))
/*!
 * @brief OS_START_EAIERR folds EAI_ error codes from getaddrinfo() into
 *        err_status_t values.
 */
#define OS_START_EAIERR    (OS_START_CANONERR + OS_ERRSPACE_SIZE)
/*!
 * @brief OS_START_SYSERR folds platform-specific system error values into
 *          err_status_t values.
 */
#define OS_START_SYSERR    (OS_START_EAIERR + OS_ERRSPACE_SIZE)
/*!
 * @def FROM_OS_ERROR(os_err_type syserr)
 * @brief Fold a platform specific error into an apr_status_t code.
 * @return err_status_t
 * @param e The platform os error code.
 * @warning  macro implementation; the syserr argument may be evaluated
 *      multiple times.
 */
#define FROM_OS_ERROR(e) (e == 0 ? SUCCESS : e + OS_START_SYSERR)
/*!
 * @def TO_OS_ERROR(apr_status_t statcode)
 * @return os_err_type
 * @brief  Fold an apr_status_t code back to the native platform defined error.
 * @param e The apr_status_t folded platform os error code.
 * @warning  macro implementation; the statcode argument may be evaluated
 *      multiple times.  If the statcode was not created by apr_get_os_error
 *      or FROM_OS_ERROR, the results are undefined.
 */
#define TO_OS_ERROR(e) (e == 0 ? SUCCESS : e - OS_START_SYSERR)

#define get_os_error()    (errno)
#define set_os_error(e)   (errno = (e))

typedef int err_status_t;


#endif
