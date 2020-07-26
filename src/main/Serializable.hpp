#ifndef Serializable_hpp
#define Serializable_hpp

#define RAPIDJSON_HAS_STDSTRING 1
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <optional>
#include <vector>
#include <memory>
#include <string>

#include "SerializationException.hpp"

namespace moduru
{
    class Serializable
    {    
    public:
        virtual ~Serializable() {}

    public:
        virtual const std::string serialize() = 0;
        
    protected:
        const void serializeWeaks(std::vector<std::weak_ptr<Serializable>>& serializables, rapidjson::Writer<rapidjson::StringBuffer>& w)
        {
            w.StartArray();
            
            for (auto& s: serializables)
            {
                auto json = s.lock()->serialize();
                w.RawValue(json.c_str(), json.length(), rapidjson::kObjectType);
            }

            w.EndArray();
        }
        
        const void serializeShareds(std::vector<std::shared_ptr<Serializable>>& serializables, rapidjson::Writer<rapidjson::StringBuffer>& w)
        {
            w.StartArray();
            
            for (auto& s: serializables)
            {
                auto json = s->serialize();
                w.RawValue(json.c_str(), json.length(), rapidjson::kObjectType);
            }

            w.EndArray();
        }
        
        const void serializeRaws(const std::vector<std::string>& rawValues, rapidjson::Writer<rapidjson::StringBuffer>& w)
        {
            w.StartArray();
        
            for (auto& rv : rawValues)
            {
                w.RawValue(rv.c_str(), rv.length(), rapidjson::kObjectType);
            }

            w.EndArray();
        }
        
        const void serializeInt64s(const std::vector<uint64_t>& ints, rapidjson::Writer<rapidjson::StringBuffer>& w)
        {
            w.StartArray();
        
            for (auto& i : ints)
            {
                w.Uint64(i);
            }

            w.EndArray();
        }
        
        const void serializeStrings(const std::vector<std::string>& strings, rapidjson::Writer<rapidjson::StringBuffer>& w)
        {
            w.StartArray();

            for (auto& s : strings)
            {
                w.String(s);
            }

            w.EndArray();
        }
        
    };
}

#endif /* serializable_hpp */
