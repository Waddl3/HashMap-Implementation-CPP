#ifndef ENTRY_H
#define ENTRY_H

template<typename K, typename V>
class Entry{
private:
    K _key;
    V _value;

public:
    Entry(const K& k = K(), const V& v = V())
        : _key(k), _value(v) { }
    const K& key() const { return _key; }
    const V& value() const { return _value; }
    void setKey(const K& k) { _key = k; }
    void setValue(const V& v) { _value = v; }
};

#endif