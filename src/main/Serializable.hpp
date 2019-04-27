#ifndef Serializable_hpp
#define Serializable_hpp

#define RAPIDJSON_HAS_STDSTRING 1
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <optional>
#include <vector>

using namespace rapidjson;
using namespace std;

namespace moduru {
    
    class Serializable {
        
    public:
        virtual ~Serializable(){}

    public:
        virtual const string serialize() = 0;
        
    protected:
        const void serializeWeaks(vector<weak_ptr<Serializable>>& serializables, Writer<StringBuffer>& w) {
            w.StartArray();
            for (auto& s: serializables) {
                auto json = s.lock()->serialize();
                w.RawValue(json.c_str(), json.length(), kObjectType);
            }
            w.EndArray();
        }
        
        const void serializeShareds(vector<shared_ptr<Serializable>>& serializables, Writer<StringBuffer>& w) {
            w.StartArray();
            for (auto& s: serializables) {
                auto json = s->serialize();
                w.RawValue(json.c_str(), json.length(), kObjectType);
            }
            w.EndArray();
        }
        
        const void serializeRaws(const vector<string>& rawValues, Writer<StringBuffer>& w) {
            w.StartArray();
            for (auto& rv: rawValues)
                w.RawValue(rv.c_str(), rv.length(), kObjectType);
            w.EndArray();
        }
        
        const void serializeInt64s(const vector<uint64_t>& ints, Writer<StringBuffer>& w) {
            w.StartArray();
            for (auto& i : ints)
                w.Uint64(i);
            w.EndArray();
        }
        
        const void serializeStrings(const vector<string>& strings, Writer<StringBuffer>& w) {
            w.StartArray();
            for (auto& s : strings)
                w.String(s);
            w.EndArray();
        }
        
    };
}

#endif /* serializable_hpp */
