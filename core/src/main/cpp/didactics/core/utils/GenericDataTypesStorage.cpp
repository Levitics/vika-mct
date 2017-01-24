
#include <didactics/core/utils/GenericDataTypesStorage.hpp>

//! Define the Blackboards static singleton instance
GenericDataTypesStorage * GenericDataTypesStorage::instance = nullptr;

GenericDataTypesStorage::GenericDataTypesStorage() {
}

GenericDataTypesStorage::GenericDataTypesStorage(const GenericDataTypesStorage & orig) {
}

GenericDataTypesStorage::~GenericDataTypesStorage() {
}

bool GenericDataTypesStorage::create ()
{
    if (isReady())
    {
        destroy();
    }

    instance = new GenericDataTypesStorage();

    return (instance != nullptr);
}

void GenericDataTypesStorage::destroy ()
{
    if (instance)
    {
        instance->dataLock.lock();

        for (auto pair : instance->mDataStorage)
        {
            delete pair.second;
        }

        instance->dataLock.unlock();
        delete instance;

        instance = nullptr;
    }
}

void GenericDataTypesStorage::wipeKey (const std::string & pKey)
{
    std::lock_guard<std::recursive_mutex> guard(instance->dataLock);

    for (auto pair : instance->mDataStorage)
    {
        pair.second->wipeKey(pKey);
    }
}

void GenericDataTypesStorage::wipeBoard (bool pWipeCallbacks)
{
    std::lock_guard<std::recursive_mutex> guard(instance->dataLock);

    for (auto pair : instance->mDataStorage)
    {
        pair.second->wipeAll();

        if (pWipeCallbacks)
        {
            pair.second->clearAllEvents();
        }
    }
}

void GenericDataTypesStorage::unsubscribeAll (const std::string & pKey)
{
    // Lock the data
    std::lock_guard<std::recursive_mutex> guard(instance->dataLock);

    for (auto pair : instance->mDataStorage)
    {
        pair.second->unsubscribe(pKey);
    }
}

template<typename T>
size_t GenericDataTypesStorage::templateToID () const
{
    const std::type_info & type = typeid(T);
    return type.hash_code();
}

template<typename T>
size_t GenericDataTypesStorage::supportType ()
{
    size_t key = templateToID<T>();

    // If there isn't a entry for the hash code create a new map
    if (mDataStorage.find(key) == mDataStorage.end())
    {
        mDataStorage[key] = new GenericDataTypesStorage::ValueMap<T>();
    }

    return key;
}

template<typename T>
void GenericDataTypesStorage::write (const std::string & pKey ,
                                     const T & pValue ,
                                     bool pRaiseCallbacks)
{
    std::lock_guard<std::recursive_mutex>guard(instance->dataLock);
    size_t key = instance->supportType<T>(); // Ensure the key for this type is supported.
    ValueMap<T> * map = (ValueMap<T> *)(instance->mDataStorage[key]); // Cast the Value Map to the type of T.
    // map->mValues[pKey] = pValue;

    if (pRaiseCallbacks)
    {
        // Check for events to raise
        if (map->mKeyEvents.find(pKey) != map->mKeyEvents.end() && map->mKeyEvents[pKey])
        {
            map->mKeyEvents[pKey](pKey);
        }

        if (map->mValueEvents.find(pKey) != map->mValueEvents.end() && map->mValueEvents[pKey])
        {
            map->mValueEvents[pKey](map->mValues[pKey]);
        }

        if (map->mPairEvents.find(pKey) != map->mPairEvents.end() && map->mPairEvents[pKey])
        {
            map->mPairEvents[pKey](pKey , map->mValues[pKey]);
        }
    }
}

template<typename T>
const T & GenericDataTypesStorage::read (const std::string & pKey)
{
    std::lock_guard<std::recursive_mutex> guard(instance->dataLock);
    size_t key = instance->supportType<T>();
    ValueMap<T> * map = (ValueMap<T> *)(instance->mDataStorage[key]);
    return map->mValues[pKey];
}

template<typename T>
void GenericDataTypesStorage::wipeTypeKey (const std::string & pKey)
{
    std::lock_guard<std::recursive_mutex> guard(instance->dataLock);
    size_t key = instance->supportType<T>();
    ValueMap<T> * map = (ValueMap<T> *)(instance->mDataStorage[key]);
    map->wipeKey(pKey);
}

template<typename T>
void GenericDataTypesStorage::subscribe (const std::string & pKey ,
                                         EventKeyCallback<T> pCb)
{
    std::lock_guard<std::recursive_mutex> guard(instance->dataLock);
    size_t key = instance->supportType<T>();
    ValueMap<T> * map = (ValueMap<T> *)(instance->mDataStorage[key]);
    map->mKeyEvents[pKey] = pCb;
}

template<typename T>
void GenericDataTypesStorage::subscribe (const std::string & pKey ,
                                         EventValueCallback<T> pCb)
{
    std::lock_guard<std::recursive_mutex> guard(instance->dataLock);
    size_t key = instance->supportType<T>();
    ValueMap<T> * map = (ValueMap<T> *)(instance->mDataStorage[key]);
    map->mValueEvents[pKey] = pCb;
}

template<typename T>
void GenericDataTypesStorage::subscribe (const std::string & pKey ,
                                         EventKeyValueCallback<T> pCb)
{
    std::lock_guard<std::recursive_mutex> guard(instance->dataLock);
    size_t key = instance->supportType<T>();
    ValueMap<T> * map = (ValueMap<T> *)(instance->mDataStorage[key]);
    map->mPairEvents[pKey] = pCb;
}

template<typename T>
void GenericDataTypesStorage::unsubscribe (const std::string & pKey)
{
    std::lock_guard<std::recursive_mutex> guard(instance->dataLock);
    size_t key = instance->supportType<T>();
    ValueMap<T> * map = (ValueMap<T> *)(instance->mDataStorage[key]);
    map->unsubscribe(pKey);
}

template<typename T>
void GenericDataTypesStorage::ValueMap<T>::wipeKey (const std::string & pKey)
{
    mValues.erase(pKey);
}

template<typename T>
void GenericDataTypesStorage::ValueMap<T>::wipeAll ()
{
    mValues.clear();
}

template<typename T>
void GenericDataTypesStorage::ValueMap<T>::unsubscribe (const std::string & pKey)
{
    auto key = mKeyEvents.find(pKey);
    auto val = mValueEvents.find(pKey);
    auto pair = mPairEvents.find(pKey);

    if (key != mKeyEvents.end())
    {
        mKeyEvents.erase(key);
    }

    if (val != mValueEvents.end())
    {
        mValueEvents.erase(val);
    }

    if (pair != mPairEvents.end())
    {
        mPairEvents.erase(pair);
    }
}

template<typename T>
void GenericDataTypesStorage::ValueMap<T>::clearAllEvents ()
{
    mKeyEvents.clear();
    mValueEvents.clear();
    mPairEvents.clear();
}
