#include <string>
#include <iostream>

class Foo 
{
public:
    std::string key;
    int value;
    Foo(const std::string& key, const int& value)
    : key(key), value(value) 
    {
        std::cout << "Created Foo." << "\n";
    }
};
