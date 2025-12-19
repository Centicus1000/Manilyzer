#pragma once

#include <string>
#include "utils/json.hpp"

using json = nlohmann::json;

// Template implementation using CRTP for type-safe serialization
template<typename Derived>
class Jsonable {
public:
    
    virtual void WriteJson(json      & jOut) const = 0;
    virtual void ReadJson (json const& jIn ) = 0;
    
    
    void Copy(Derived const& source, Derived& dest) const
    {
        json data;
        source.WriteJson(data);
        dest.ReadJson(data, dest);
    }
    
    std::string Str() const
    {
        json data;
        WriteJson(data);
        return data.dump();
    }
};

