// Этот класс создан для хранения загружаемых из вне ресурсов
// картинок, аудио и т.п.
#include "SFML/Graphics.hpp"

#include "map"
#include "string"

#pragma once

template<typename KeyType, typename ResourceType>
class ResourceHolder{
private:
    using MapType = std::map<KeyType, ResourceType*>;
    // пользуемся указателем, чтобы хранить для каждого отдельное ресурса один экземпляр
public:

    ResourceType* loadFromFile(const std::string& PathToFile, const std::string& Key){
        ResourceType* &resourceRef = Resources[Key]; // проверка на нахождение в структуре
        if(resourceRef != nullptr){
            return resourceRef;
        }

        resourceRef = new ResourceType();

        if(!resourceRef->loadFromFile(PathToFile)){
            delete resourceRef;
        }
        return resourceRef;
    }

    ResourceType* getResources(const std::string& Key){
        ResourceType* &resourceRef = Resources[Key];
        return resourceRef;
    }

    ~ResourceHolder(){
        for(auto i : Resources){
            delete i.second;
        }
    }

    ResourceHolder() = default;
    ResourceHolder(const ResourceHolder&) = delete;
    ResourceHolder(ResourceHolder&&) = delete;
    ResourceHolder& operator=(const ResourceHolder&) = delete;
    ResourceHolder& operator=(ResourceHolder&) = delete;
private:
    MapType Resources;
};

template<typename KeyType, typename ResourceType>
ResourceHolder<KeyType, ResourceType>& getGlobalResourceHolder(){
    static ResourceHolder<KeyType, ResourceType> holder;
    return holder;
}