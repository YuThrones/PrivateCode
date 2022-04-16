#include <tuple>
#include <iostream>

using namespace std;

int main()
{
    tuple<int, char, double> mytuple(10, 'x', 1.9);
    int size = tuple_size<decltype(mytuple)>::value;
    cout << get<0>(mytuple) << endl;
    get<0>(mytuple) = 100;
    cout << get<0>(mytuple) << endl;
    auto bar = make_tuple("test", 3.1, 14);
    const char* mystr = nullptr;
    double mydou;
    int myint;
    tie(mystr, mydou, ignore) = bar;
    auto mycat = tuple_cat(mytuple, bar);
    size = tuple_size<decltype(mycat)>::value;
    cout << size << endl;
    return 0;
}