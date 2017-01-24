
#ifndef DIDACTICS_CORE_ERRORHANDLING_EXCEPTIONS_HPP
#define DIDACTICS_CORE_ERRORHANDLING_EXCEPTIONS_HPP

#include <exception>
#include <string>
#include <iostream>
/*!
 * @brief Base class for every exception thrown in <>.
 */
class Exceptions : public std::exception
{
    /*!
     *  @brief  Wrapper class to define a different terminate handler. The terminate
     *          handler is the function that will be called by the runtime system when
     *          exception handling must be abandoned.
     */
    class TerminateHandler
    {
        /*!
         * @brief Options that set the behavior of this class:
         */
        enum TerminateAction
        {
            NOTHING           = 0x0 ,

            /*! Do nothing. Don't even install termination handlers. */
            BACKTRACE         = 0x1 ,

            /*! Load gdb and get a stack dump using gdb bt command.  */
            WEAK_BACKTRACE    = 0x2 ,

            /*! Get backtrace using glibc::backtrace. */
            TRAP_MANY_SIGNALS = 0x4 ,

            /*! Trap a lot of signals not normally trapped. */
            USE_CURRENT       = 0x8 ,

            /*! Inherit values already existing in previous handlers. */
            LOCAL_VARIABLES   = 0x10   /*! Attempt to additionaly display local variables. */
        };

public:

        /*!
         * @brief  Constructor. Register @a handler as the current terminate handler.
         */
        explicit TerminateHandler(std::terminate_handler handler)
        {
            oldHandler = std::set_terminate(handler);
        }

        /*!
         * @brief Destructor. Unregister the current terminate handler; reset to
         *        previous handler.
         */
        virtual ~TerminateHandler()
        {
            std::set_terminate(oldHandler);
        }

private:

        /*!
         * @brief  This is the old terminate handler. We need it in the destructor.
         */
        std::terminate_handler oldHandler;
    };

public:

    Exceptions();
    Exceptions(const Exceptions & orig);
    Exceptions & operator = (const Exceptions & exc);
    virtual ~Exceptions();
    /*!
     * @brief
     */
    Exceptions(int code = 0);
    /*!
     * @brief Constructs an exeption with message and error code.
     */
    Exceptions(const std::string & msg , int code = 0);
    /*!
     * @brief Constructor.
     * @param code Error code.
     * @throw std::runtime_error When socket could not be created.
     */
    Exceptions(const std::string & msg , const Exceptions & nested , int code = 0);
    /*!
     * @brief methodName Method raising the exception.
     */
    const std::string & methodName ();
    /*!
     * @brief message Message explaining the reason of exception.
     */
    const std::string & errorDescription ();
    /*!
     * @brief errorCode Error code corresponding to errno.h values.
     * @return
     */
    int errorCode () const;
    /*!
     * @brief Gets the nested exception which caused this exception.
     * @return The nested exception, or <code>NULL</code> if there is none.
     */
    const Exceptions * cause () const throw ();
    /*!
     * @brief Return a description of the error
     * @return Pointer to a string containing the error message
     */
    const char * what () const throw ();
    /*!
     * @brief Return the error location (file + line + function)
     * @return String containing the error location
     */
    virtual const char * where () const throw ();
    /*!
     * @brief Return the error summary description
     * @return String containing the error location
     */
    virtual std::string summary () const;

private:

    std::string message;        ///< Error message.
    std::string location;       ///< Location of the error : file, line and procedure)
    int code;                   ///< Error code
};

#endif
