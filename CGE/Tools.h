#ifndef TOOLS_H
#define TOOLS_H

#include <cstdlib>
#include <sstream>
#include <map>

#define PI 3.141592653589793238462643383
#define TO_RADIANS(n) ((n) * PI / 180.0)

namespace CGE
{
    inline bool hasContent(const char* inText)
    {
        return inText && *inText;
    }

    bool caseInsensitiveEquals(const char* inA, const char* inB);

    char* fileToBuffer(const char* inFile, size_t* inLength = NULL);

    template<class T>
    T linearInterpolate(const T& inMin, const T& inMax, double inT)
    {
        return (inMin * (1.0 - inT)) + (inMax * inT);
    }

    template<typename T>
    inline void readBytes(void* inData, T& outResult)
    {
        outResult = *reinterpret_cast<T*>(inData);
    }

    template<typename T>
    bool tryParse(const std::string& inString, T& inTarget)
    {
        std::stringstream ss(inString);
        return ss >> inTarget;
    }

    template<class TKey, class TValue>
    const TValue* tryGet(const std::map<TKey, TValue>& inMap, const TKey& inKey)
    {
        const TValue* outResult = NULL;

        typename std::map<TKey, TValue>::const_iterator i = inMap.find(inKey);

        if (i != inMap.end())
        {
            outResult = &i->second;
        }

        return outResult;
    }

}

#endif

