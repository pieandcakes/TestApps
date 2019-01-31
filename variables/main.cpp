#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "foo.h"

void unorderedMapExample()
{
    std::unordered_map<int, int> vMap = {{1,2},{2,4}};

    for (auto iterator = vMap.begin(); iterator != vMap.end(); ++iterator)
    {
        if (iterator->first == 2)
            printf("hello!");

        if (iterator->second == 2)
            printf("goodbye");
    }
}

struct X
{
    int a, b;
};

struct Xcmp 
{
    bool operator()(const X& x1, const X& x2)
    {
        return x1.a < x2.a || (x1.a == x2.a && x1.b < x2.b);
    }
};

void mapExample()
{
    std::map<X, int, Xcmp> m;
    m[{1, 2}] = 14;
    m[{5, 7}] = 227;
    m[{3, 4}] = 3;
    m[{5, 23}] = 43;
    m[{34, 23}] = 1234;
    printf("done");
}

void vectorExample()
{
    std::vector<Foo> collection {
        { "test 0", 0 },
        { "test 1", 1 },
        { "test 2", 2 },
        { "test 3", 3 }
    };

    std::string key = "test 1";

    const auto predicate = [&key](const Foo& foo) { return foo.key == key; };
    
    const auto first = std::find_if(collection.begin(), collection.end(), predicate);

    first;      // Works ok.
    *first;     // Fails on hover.
    &(*first);  // Fails on hover.
}

template<typename T>
struct tvec2
{
    union {T x, r, s;};
    union {T y, g, t;};
};

void unionexample()
{
    tvec2<int> v;
    v.x = 1;
    v.r = 2;
    v.s = 3;
    v.y = 12;
    v.g = 13;
    v.t = 14;

    printf("hello");
}

int main(int argc, char **argv)
{
    //mapExample();
    //vectorExample();
    unionexample();
    return 0;
}