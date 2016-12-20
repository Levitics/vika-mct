#ifndef @NAME@_VERSION_H
#define @NAME@_VERSION_H

#include <@INCLUDE_NAME@/Api.hpp>
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
    RELEASE_LEVEL_ALPHA        = 0xA0,    /**< API is in alpha state, i.e. work in progress. */
    RELEASE_LEVEL_BETA         = 0xB0,    /**< API is in beta state, i.e. close to be finished. */
    RELEASE_LEVEL_CANDIDATE    = 0xC0,    /**< API is in release candidate state. */
    RELEASE_LEVEL_FINAL        = 0xF0,    /**< API is in final state, i.e. officially approved. */
};

#define RELEASE_LEVEL	ReleaseLevel::RELEASE_LEVEL_FINAL
#define RELEASE_SERIAL	0
        
/*!
 * @brief Version as a single 4-byte hex number, e.g. 0x010502B2 == 1.5.2b2.
 *        Use this for numeric comparisons, e.g. #if PY_VERSION_HEX >= ... 
 */
#define VERSION_HEX (
                        (@PROJECT_VERSION_MAJOR@ << 24)    | \
                	(@PROJECT_VERSION_MINOR@ << 16) | \
			(@PROJECT_VERSION_MICRO@ <<  8) | \
			(RELEASE_LEVEL <<  4) | \
			(RELEASE_SERIAL << 0))

    /*! 
     * @brief The current major version. 
     */
#   define @NAMESPACE@_VERSION_MAJOR @PROJECT_VERSION_MAJOR@

    /*!
     * @brief  The current minor version. 
     */
#   define @NAMESPACE@_VERSION_MINOR @PROJECT_VERSION_MINOR@

    /*!
     * @brief  The current micro version. 
     */
#   define @NAMESPACE@_VERSION_MICRO @PROJECT_VERSION_MICRO@
                                
    /*!
     * @brief  The current patch level.
     */
#   define @NAMESPACE@_VERSION_PATCH @PROJECT_VERSION_PATCH@

    /*! 
     * @brief The current SCM revision. 
     */
#   define @NAMESPACE@_VERSION_REVISION 0x@GIT_REVISION@

    /*!
     * @brief  The current binary interface. 
     */
#   define @NAMESPACE@_VERSION_ABI @PROJECT_VERSION_ABI@ull

/*!
 * @brief  True if the current version is newer than the given one. 
 */
#   define @NAMESPACE@_VERSION_GT( MAJOR, MINOR, PATCH )       \
    ( (@NAMESPACE@_VERSION_MAJOR>MAJOR) ||                     \
      (@NAMESPACE@_VERSION_MAJOR==MAJOR && (@NAMESPACE@_VERSION_MINOR>MINOR || \
          (@NAMESPACE@_VERSION_MINOR==MINOR && @NAMESPACE@_VERSION_PATCH>PATCH))))

/*! 
 * @brief True if the current version is equal or newer to the given. 
 */
#   define @NAMESPACE@_VERSION_GE( MAJOR, MINOR, PATCH )       \
    ( (@NAMESPACE@_VERSION_MAJOR>MAJOR) ||                     \
      (@NAMESPACE@_VERSION_MAJOR==MAJOR && (@NAMESPACE@_VERSION_MINOR>MINOR || \
          (@NAMESPACE@_VERSION_MINOR==MINOR && @NAMESPACE@_VERSION_PATCH>=PATCH))))

/*!
 * @brief  True if the current version is older than the given one. 
 */
#   define @NAMESPACE@_VERSION_LT( MAJOR, MINOR, PATCH )       \
    ( (@NAMESPACE@_VERSION_MAJOR<MAJOR) ||                     \
      (@NAMESPACE@_VERSION_MAJOR==MAJOR && (@NAMESPACE@_VERSION_MINOR<MINOR || \
          (@NAMESPACE@_VERSION_MINOR==MINOR && @NAMESPACE@_VERSION_PATCH<PATCH))))

/*!
 * @brief  True if the current version is older or equal to the given. 
 */
#   define @NAMESPACE@_VERSION_LE( MAJOR, MINOR, PATCH )       \
    ( (@NAMESPACE@_VERSION_MAJOR<MAJOR) ||                     \
      (@NAMESPACE@_VERSION_MAJOR==MAJOR && (@NAMESPACE@_VERSION_MINOR<MINOR || \
        (@NAMESPACE@_VERSION_MINOR==MINOR && @NAMESPACE@_VERSION_PATCH<=PATCH))))


class @NAMESPACE@_API Version {
public:
    Version();
    Version(const Version& orig);
    virtual ~Version();
    
    /*!
     *  @return the current major version of @Name@. 
     */
    static int getMajor();

    /*! 
     * @return the current minor version of @Name@. 
     */
    static int getMinor();

    /*! 
     * @return the current patch level of @Name@. 
     */
    static int getPatch();

    /*! 
     * @return the current @Name@ version (MM.mm.pp). 
     */
    static std::string getString();

    /*! 
     * @return the SCM revision. 
     */
    static unsigned long long getRevision();

    /*!
     *  @return the current binary interface version of @Name@. 
     */
    static int getABI();

    /*! 
     * @return the current @Name@ version plus the git SHA hash (MM.mm.pp.rev). 
     */
    static std::string getRevString() 
    /*!
     * @brief Runtime check for ABI compatibility.
     *          Call from code using @Name@. Will fail if the executable
     *          was compiled against a version incompatible with the runtime version.
     * @return true if the link-time and compile-time DSO are compatible.
     */    
    static bool check()
    {
        return getMajor()==@NAMESPACE@_VERSION_MAJOR &&
               getMinor()==@NAMESPACE@_VERSION_MINOR;
    }
    /*! 
     * @return JSON schema describing this object. 
     */
    static std::string getSchema()
    {
        return R"(
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
    static std::string toJSON()
    {
        return R"(
               {
                 "major": @PROJECT_VERSION_MAJOR@,
                 "minor": @PROJECT_VERSION_MINOR@,
                 "patch": @PROJECT_VERSION_PATCH@,
                 "abi": @PROJECT_VERSION_ABI@,
                 "revision": "@GIT_REVISION@"
               }
               )";
    }    
private:

};

#endif

