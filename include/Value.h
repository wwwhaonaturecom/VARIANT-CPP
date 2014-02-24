/**
 *  Value.h
 *
 *  Value class that can be used as a sort of scripting language
 *  untyped variable.
 *
 *  @copyright 2014
 */

/**
 *  Include guard
 */
#ifndef __COPERNICA_VARIANT_VALUE_H
#define __COPERNICA_VARIANT_VALUE_H

#include "ValueImpl.h"
#include <string>
#include <vector>
#include <map>

/**
 *  Namespace
 */
namespace Variant {

// forward declaration
template <typename T>
class ValueMember;

/**
 *  Class definition
 */
class Value
{
private:
    /**
     *  Typedef for the variant implementation pointer
     */
    using ValueImplPtr = std::unique_ptr<ValueImpl>;

    /**
     *  The actual implementation
     *  @var    impl
     */
    ValueImplPtr _impl;

public:
    /**
     *  Copy constructor
     */
    Value(const Value& that);

    /**
     *  Move constructor
     */
    Value(Value&& that);

    /**
     *  Null constructor
     */
    Value();
    Value(std::nullptr_t value);

    /**
     *  Number constructor
     *  @param  value
     */
    Value(int value);

    /**
     *  String constructor
     *  @param  value
     */
    Value(const char* value);
    Value(const char* value, size_t length);
    Value(const std::string& value);
    Value(std::string&& value);

    /**
     *  Vector constructor
     *  @param  value
     */
    Value(const std::vector<Value>& value);
    Value(std::vector<Value>&& value);
    Value(const std::initializer_list<Value>& value);

    /**
     *  Map constructor
     *  @param  value
     */
    Value(const std::map<std::string, Value>& value);
    Value(std::map<std::string, Value>&& value);
    Value(const std::initializer_list<std::map<std::string, Value>::value_type>& value);

    /**
     *  Assign another variant
     *  @param  value
     */
    Value& operator=(const Value& value);
    Value& operator=(Value&& value);

    /**
     *  Number casting and assignment
     */
    operator int () const;
    Value& operator=(int value);

    /**
     *  String casting and assignment
     */
    operator std::string () const;
    Value& operator=(const char* value);
    Value& operator=(const std::string& value);
    Value& operator=(std::string&& value);

    /**
     *  Get the number of elements in the variant
     *
     *  This is only applicable for vector and map
     *  types. For any other type, 0 is returned
     */
    size_t size() const;

    /**
     *  Array casting, assignment and access
     */
    operator std::vector<Value> () const;
    Value& operator=(const std::vector<Value>& value);
    Value& operator=(std::vector<Value>&& value);
    Value operator [] (int index) const;
    ValueMember<int> operator [] (int index);

    /**
     *  Array casting, assignment and access
     */
    operator std::map<std::string, Value> () const;
    Value& operator=(const std::map<std::string, Value>& value);
    Value& operator=(std::map<std::string, Value>&& value);
    Value operator [] (const char* key) const;
    Value operator [] (const std::string& key) const;
    ValueMember<std::string> operator [] (const char* key);
    ValueMember<std::string> operator [] (const std::string& key);
};

/**
 *  End namespace
 */
}

#endif /* Value.h */