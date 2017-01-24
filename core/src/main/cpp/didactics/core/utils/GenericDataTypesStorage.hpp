
#ifndef GENERICDATATYPESSTORAGE_HPP
#define GENERICDATATYPESSTORAGE_HPP

#include <typeinfo>
#include <unordered_map>
#include <mutex>
#include <stdexcept>
/*!
 * @brief Provide a singleton location for a user to store
 *        generic data in a easily accessible location.
 *
 *        Callback functionality will be implemented to allow
 *        listening for when specific keyed data is changed.
 *
 *        The create and destroy functions must be called
 *        prior to use.
 * @warning
 *      Data types stored on the blackboard must have valid
 *      default and copy constructors defined as well as the
 *      assignment operator.
 *
 *      Only one callback event of each type will be kept for
 *      each key of every value type.
 */

/*!
 * @brief  Base type of the data storage object.
 *         Provide a base point for the templated ValueMap.
 *         objects to inherit from. This allows the
 *         GenericDataTypesStorage to store pointers to the templated versions for storing data.
 */
class BaseMap
{
    BaseMap() = default;
    virtual ~BaseMap() = 0;
    virtual void wipeKey (const std::string & pKey) = 0;
    virtual void wipeAll () = 0;
    virtual void unsubscribe (const std::string & pKey) = 0;
    virtual void clearAllEvents () = 0;
};

template<typename T>

class ValueMap : BaseMap
{
protected:

    std::unordered_map<std::string , T> values;
    //! Store maps for the callback events
    std::unordered_map<std::string , EventKeyCallback<T> > mKeyEvents;
    std::unordered_map<std::string , EventValueCallback<T> > mValueEvents;
    std::unordered_map<std::string , EventKeyValueCallback<T> > mPairEvents;

    //! Privatise the constructor/destructor to prevent external use.
    ValueMap() = default;
    virtual ~ValueMap() override {
    }

    //! Override the functions used to remove keyed information.
    void wipeKey (const std::string & pKey) override;
    void wipeAll () override;
    void unsubscribe (const std::string & pKey) override;
    void clearAllEvents () override;
};

template<typename T>
using EventKeyCallback = void (*)(const std::string &);
template<typename T>
using EventValueCallback = void (*)(const T &);
template<typename T>
using EventKeyValueCallback = void (*)(const std::string & , const T &);

class GenericDataTypesStorage
{
public:

    GenericDataTypesStorage(const GenericDataTypesStorage & orig);

    static bool create ();
    static void destroy ();

    template<typename T>
    static void write (const std::string & pKey , const T & pValue , bool pRaiseCallbacks = true);
    template<typename T>
    static const T & read (const std::string & pKey);
    template<typename T>
    static void wipeTypeKey (const std::string & pKey);
    static void wipeKey (const std::string & pKey);
    static void wipeBoard (bool pWipeCallbacks = false);

    template<typename T>
    static void subscribe (const std::string & pKey , EventKeyCallback<T> pCb);
    template<typename T>
    static void subscribe (const std::string & pKey , EventValueCallback<T> pCb);
    template<typename T>
    static void subscribe (const std::string & pKey , EventKeyValueCallback<T> pCb);
    template<typename T>
    static void unsubscribe (const std::string & pKey);
    static void unsubscribeAll (const std::string & pKey);
    static bool isReady ()
    {
        return (instance != nullptr);
    }

private:

    static GenericDataTypesStorage * instance;

    //! Store a map of all of the different value types
    std::unordered_map<size_t , BaseMap *> mDataStorage;
    //! Store a mutex for locking data when in use
    std::recursive_mutex dataLock;

    //! Convert a template type into a unique ID value
    template<typename T>
    size_t templateToID () const;

    //! Ensure that a ValueMap objects exists for a specific type
    template<typename T>
    size_t supportType ();

    virtual ~GenericDataTypesStorage() = default;
    GenericDataTypesStorage() = default;
};

#endif
