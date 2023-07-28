#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <typeinfo>
#include <random>

#include "ScopeTimer.h"

constexpr char STR_PREFIX[]         = "1:3001:";
constexpr int  MAP_SEARCH_ITEM_SIZE = 10000;

template<template<typename...> class Container>
class MapBenchmark
{
public:
    MapBenchmark(const int mapSize)
        : mapSize(mapSize)
    {
    }

    void Run(const std::vector<std::string> &mapKeyList,
             const std::vector<std::string> &randomSearchList)
    {
        double insertionDuration = InsertKeys(mapKeyList);
        double searchDuration    = MeasureSearch(randomSearchList);

        std::cout << typeid(Container).name() << "Insert duration"
                  << ":"
                  << " : " << insertionDuration << std::endl;
        std::cout << typeid(Container).name() << "Search duration"
                  << ":"
                  << " : " << searchDuration << std::endl;
    }

private:
    double InsertKeys(const std::vector<std::string> &mapKeyList)
    {
        ScopeTimer scopeTimer;
        for ( int i = 0; i < mapKeyList.size(); ++i )
        {
            std::string key = mapKeyList[i];
            stringMap[key]  = i;
        }
        scopeTimer.end();
        return scopeTimer.duration();
    }

    double MeasureSearch(const std::vector<std::string> &randomSearchList)
    {
        ScopeTimer scopeTimer;
        for ( const std::string &stringKey : randomSearchList )
        {
            auto stringIter = stringMap.find(stringKey);
            if ( stringIter == stringMap.end() )
            {
                std::cout << "string not found!" << std::endl;
            }
            else
            {
                //std::cout << "string found!" << std::endl;
            }
        }
        scopeTimer.end();
        return scopeTimer.duration();
    }
    using StringMap = Container<std::string, int>;
    StringMap stringMap;
    int       mapSize;
};

void GenerateOrderedKeyList(const int mapSize, std::vector<std::string> &keyList)
{
    for ( int i = 0; i < mapSize; ++i )
    {
        std::string mapKey = STR_PREFIX + std::to_string(i);
        keyList.push_back(mapKey);
    }
}

void GenerateUnorderedKeyList(const int mapSize, std::vector<std::string> &keyList)
{
    std::vector<int> pattern = {2, 1, 4, 3};

    for ( int i = 0; i < mapSize; ++i )
    {
        int         patternIndex = i % pattern.size();
        int         patternValue = pattern[patternIndex];
        std::string mapKey       = STR_PREFIX + std::to_string(patternValue) + ":" + std::to_string(i);
        keyList.push_back(mapKey);
    }
}

void GenerateSearchItemList(const int mapSize, const int mapSearchItemSize, std::vector<std::string> &keyList, std::vector<std::string> &searchKeyList)
{
    for ( int i = 0; i < keyList.size(); i++ )
    {
        int         random_index = std::rand() % (keyList.size());
        std::string searchKey    = keyList[random_index];
        searchKeyList.push_back(searchKey);
    }
}

void RunBenchmark(const int mapSize, const int mapSearchItemSize, bool generateOrderedKey)
{
    std::cout << "Map size : " << mapSize
              << ", Search item size :" << mapSearchItemSize
              << (generateOrderedKey ? ", Generate ordered Key" : ", Generate unordered key")
              << "\n--------" << std::endl;

    std::vector<std::string> randomSearchList;
    std::vector<std::string> mapKeyList;

    if ( generateOrderedKey )
    {
        GenerateOrderedKeyList(mapSize, mapKeyList);
    }
    else
    {
        GenerateUnorderedKeyList(mapSize, mapKeyList);
    }

    GenerateSearchItemList(mapSize, mapSearchItemSize, mapKeyList, randomSearchList);

    MapBenchmark<std::map> mapBenkmark(mapSize);
    mapBenkmark.Run(mapKeyList, randomSearchList);

    MapBenchmark<std::unordered_map> unorderedMapBenkmark(mapSize);
    unorderedMapBenkmark.Run(mapKeyList, randomSearchList);
    std::cout << std::endl;
}

void RunBenchmark(bool generateOrderedKey)
{
    RunBenchmark(100000, 1000, generateOrderedKey);
    RunBenchmark(1000000, 1000, generateOrderedKey);
    RunBenchmark(10000000, 1000, generateOrderedKey);

    RunBenchmark(5000000, 10000, generateOrderedKey);
    RunBenchmark(5000000, 100000, generateOrderedKey);
    RunBenchmark(5000000, 1000000, generateOrderedKey);
}

int main()
{
    RunBenchmark(true);
    RunBenchmark(false);

    return 0;
}
