
#ifndef DIDACTICS_CORE_ERRORHANDLING_ERRNOMAPPER_HPP
#define DIDACTICS_CORE_ERRORHANDLING_ERRNOMAPPER_HPP
#include <experimental/system_error>
#include <vector>
#include <didactics/core/errorhandling/Exceptions.hpp>

class ErrnoMapper : public std::system_error
{
public:

    ErrnoMapper();
    virtual ~ErrnoMapper();
    /*!
     * @brief Move constructor
     */
    ErrnoMapper(const ErrnoMapper & orig) = default;
    /*!
     * @brief Move constructor
     */
    ErrnoMapper(ErrnoMapper &&) = default;
    /*!
     * @brief Copy assignment operator
     */
    ErrnoMapper & operator = (const ErrnoMapper &) & = default;
    /*!
     * @brief Move assignment operator
     */
    ErrnoMapper & operator = (ErrnoMapper &&) & = default;
    ErrnoMapper(const std::error_code code) noexcept;
    ErrnoMapper(const std::error_code code , const char * const what) noexcept;
    ErrnoMapper(const int code , const std::error_category & category) noexcept;
    ErrnoMapper(const int code) noexcept;
    ErrnoMapper(const int code , const std::error_category & category , const char * const what) noexcept;
    /*!
     * @brief Receive notification of a warning.
     */
    virtual void onWarning () = 0;
    /*!
     * @brief Receive notification of a recoverable error(system is in error conditions).
     */
    virtual void error () = 0;
    /*!
     * @brief Receive notification of a non-recoverable error.
     */
    virtual void fatalError () = 0;
    /*!
     * @brief Receive notification of a critical conditions.
     */
    virtual void criticalError () = 0;
    /*!
     * @brief Receive notification that an action must be taken immediately.
     */
    virtual void alertError () = 0;
    /*!
     * @brief Receive notification that system is unusable.
     */
    virtual void emergencyError () = 0;
    /*!
     * @brief Called when a Exception (or a subclass) caused the thread to terminate.
     */
    virtual void exception (const Exceptions & exc);
    /*!
     * @brief Called when a std::exception (or a subclass) caused the thread to terminate.
     */
    virtual void exception (const std::exception & exc);
    /*!
     * @brief Invokes the currently registered Error.
     */
    static void handle (const Exceptions & exc);
    /*!
     * @brief Invokes the currently registered Error.
     */
    static void handle (const std::exception & exc);
    /*!
     * @brief Invokes the currently registered Error.
     */
    void addErrorProperties ();
    /*!
     * @brief
     */
    void isErrorPropertiesActive ();
    /*!
     * @brief
     */
    void clearErrorProperties ();

protected:

private:

    std::vector<std::pair<std::string , std::string> > errorProperties;
};

#endif
