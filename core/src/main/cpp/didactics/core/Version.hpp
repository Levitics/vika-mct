
#ifndef SPHYNX_CORE_VERSION_HPP
#define SPHYNX_CORE_VERSION_HPP

// #include <SPHYNX/Api.hpp>
#include <didactics/core/Api.hpp>
#include <string>

/*!
 * @brief ReleaseLevel indicates the release level of this API
 *          This enum follows the release level convention used by python.
 * @ref https://docs.python.org/3/c-api/apiabiversion.html
 * @ref https://docs.python.org/3.7/c-api/apiabiversion.html
 * @ref https://hg.python.org/cpython/file/3.6/Include/patchlevel.h
 */
enum ReleaseLevel
{
    RELEASE_LEVEL_ALPHA        = 0xA0 ,

    /**< API is in alpha state, i.e. work in progress. */
    RELEASE_LEVEL_BETA         = 0xB0 ,

    /**< API is in beta state, i.e. close to be finished. */
    RELEASE_LEVEL_CANDIDATE    = 0xC0 ,

    /**< API is in release candidate state. */
    RELEASE_LEVEL_FINAL        = 0xF0 ,

    /**< API is in final state, i.e. officially approved. */
};

#define VERSION_REVISION 0x
#define RELEASE_LEVEL   ReleaseLevel::RELEASE_LEVEL_FINAL
#define RELEASE_SERIAL  0


/*!
 * @brief Version as a single 4-byte hex number, e.g. 0x010502B2 == 1.5.2b2.
 *        Use this for numeric comparisons, e.g. #if PY_VERSION_HEX >= ...
 */
#define VERSION_HEX (                                           \
        (1 << 24)     |   \
        (0 << 16)     |   \
        (1 <<  8)     |   \
        (RELEASE_LEVEL <<  4)               |   \
        (RELEASE_SERIAL << 0)                   \
        )

#define EQ_VERSION_GT( MAJOR , MINOR , PATCH )                         \
    ( (1 > MAJOR) ||                                       \
      (1 == MAJOR && (0 > MINOR ||            \
                      (0 == MINOR && 1 > PATCH))))

#define EQ_VERSION_GE( MAJOR , MINOR , PATCH )                         \
    ( (1 > MAJOR) ||                                       \
      (1 == MAJOR && (0 > MINOR ||            \
                      (0 == MINOR && 1 >= PATCH))))

#define EQ_VERSION_LT( MAJOR , MINOR , PATCH )                         \
    ( (1 < MAJOR) ||                                       \
      (1 == MAJOR && (0 < MINOR ||            \
                      (0 == MINOR && 1 < PATCH))))

#define EQ_VERSION_LE( MAJOR , MINOR , PATCH )                         \
    ( (1 < MAJOR) ||                                       \
      (1 == MAJOR && (0 < MINOR ||            \
                      (0 == MINOR && 1 = PATCH))))

/*!
 * @brief The current major version.
 */
#define SPH_VERSION_MAJOR 1

/*!
 * @brief  The current minor version.
 */
#define SPH_VERSION_MINOR 0

/*!
 * @brief  The current micro version.
 */
#define SPH_VERSION_MICRO 1

/*!
 * @brief  The current patch level.
 */
#define SPH_VERSION_PATCH

/*!
 * @brief The current SCM revision.
 */
#define SPH_VERSION_REVISION 0x

/*!
 * @brief  The current binary interface.
 */
#define SPH_VERSION_ABI

/*!
 * @brief  True if the current version is newer than the given one.
 */
#define SPH_VERSION_GT( MAJOR , MINOR , PATCH )       \
    ( (SPH_VERSION_MAJOR > MAJOR) ||                     \
      (SPH_VERSION_MAJOR == MAJOR && (SPH_VERSION_MINOR > MINOR || \
                                      (SPH_VERSION_MINOR == MINOR && SPH_VERSION_PATCH > PATCH))))

/*!
 * @brief True if the current version is equal or newer to the given.
 */
#define SPH_VERSION_GE( MAJOR , MINOR , PATCH )       \
    ( (SPH_VERSION_MAJOR > MAJOR) ||                     \
      (SPH_VERSION_MAJOR == MAJOR && (SPH_VERSION_MINOR > MINOR || \
                                      (SPH_VERSION_MINOR == MINOR && SPH_VERSION_PATCH >= PATCH))))

/*!
 * @brief  True if the current version is older than the given one.
 */
#define SPH_VERSION_LT( MAJOR , MINOR , PATCH )       \
    ( (SPH_VERSION_MAJOR < MAJOR) ||                     \
      (SPH_VERSION_MAJOR == MAJOR && (SPH_VERSION_MINOR < MINOR || \
                                      (SPH_VERSION_MINOR == MINOR && SPH_VERSION_PATCH < PATCH))))

/*!
 * @brief  True if the current version is older or equal to the given.
 */
#define SPH_VERSION_LE( MAJOR , MINOR , PATCH )       \
    ( (SPH_VERSION_MAJOR < MAJOR) ||                     \
      (SPH_VERSION_MAJOR == MAJOR && (SPH_VERSION_MINOR < MINOR || \
                                      (SPH_VERSION_MINOR == MINOR && SPH_VERSION_PATCH <= PATCH))))


class SPH_API Version
{
public:

    Version();
    Version(const Version & orig);
    virtual ~Version();

    /*!
     *  @return the current major version of .
     */
    static int getMajor ();

    /*!
     * @return the current minor version of .
     */
    static int getMinor ();

    /*!
     * @return the current patch level of .
     */
    static int getPatch ();

    /*!
     * @return the current  version (MM.mm.pp).
     */
    static std::string getString ();

    /*!
     * @return the SCM revision.
     */
    static unsigned long long getRevision ();

    /*!
     *  @return the current binary interface version of .
     */
    static int getABI ();

    /*!
     * @return the current  version plus the git SHA hash (MM.mm.pp.rev).
     */
    static std::string getRevString ();
    /*!
     * @brief Runtime check for ABI compatibility.
     *          Call from code using . Will fail if the executable
     *          was compiled against a version incompatible with the runtime version.
     * @return true if the link-time and compile-time DSO are compatible.
     */

    static bool check ()
    {
        return getMajor() == SPH_VERSION_MAJOR &&
               getMinor() == SPH_VERSION_MINOR;
    }

    /*!
     * @return JSON schema describing this object.
     */

    static std::string getSchema ()
    {
        return
            R"(
                {
                  "title": "Version",
                  "type": "object",
                  "description": "Version information of the running application",
                  "properties": {
                    "major": { "type": "integer" },
                    "minor": { "type": "integer" },
                    "patch": { "type": "integer" },
                    "abi": { "type": "integer" },
                    "revision": { "type": "string" }
                  }
               }
               )";
    }

    /*!
     *  @return JSON-encoded data for this object.
     */

    static std::string toJSON ()
    {
        return
            R"(
               {
                 "major": 1,
                 "minor": 0,
                 "patch": ,
                 "abi": ,
                 "revision": ""
               }
               )";
    }

private:

};

#endif
