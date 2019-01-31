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
struct tvec1
{
	union { T x, r, s; } ;
	union { T y, g, t; } ;
};

template<typename T>
struct tvec2
{
	union { T x, r, s; } chicken;
	union { T y, g, t; } duck;
};

void unionexample()
{
	tvec1<float> u;
	u.x = 1.2f;
	u.r = 2.3f;
	u.s = 3.4f;
    u.y = 4.5f;
	u.g = 5.6f;


	tvec2<int> v;
	v.chicken.x = 1;
	v.chicken.r = 2;
	v.chicken.s = 3;
	v.duck.y = 12;
	v.duck.g = 13;
	v.duck.t = 14;

	// Set breakpoint on the below line
	printf("hello");
}

int main(int argc, char **argv)
{
    //mapExample();
    //vectorExample();
    unionexample();
    return 0;
}