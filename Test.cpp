#include <algorithm>
#include "TestFunctions.h"
#include <iostream>
template <class T> class numerate
{
public:
    numerate(T start = 0, T _shift = 1) : seed(start), shift(_shift) {};
    T operator () () { T old = seed; seed += shift; return old; }
private:
    T seed, shift;
};
template <class T, class C>
T sum(const C& c) {
    T res = 0;
    typename C::ConstIterator it = c.cbegin();  
    while (it != c.cend()) {
        res += *it;
        ++it;
    }
    return res;
}

int TestStart()
{
    std::cout << "Test 1 " << std::endl;
    Test1();
    std::cout << "Test 2 " << std::endl;
    Test2();
    std::cout << "Test 3 " << std::endl;
    Test3();
    std::cout << "Test 4 " << std::endl;
    Test4();
    return 0;
}
void Test1()
{
    Queue<int> s1;
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);

    std::cout << s1 << std::endl;
    std::cout << s1.Size() << std::endl;

    Queue<int> s2(s1), s3;

    s1.Pop();
    s1.Push(4);
    s1.Push(5);

    s2.Pop();
    s2.Push(6);

    std::cout << s1 << std::endl;
    std::cout << s1.Size() << std::endl;

    std::cout << s2 << std::endl;
    std::cout << s2.Size() << std::endl;

    s3 = s1;

    s1.Pop();
    s1.Push(7);
    s1.Push(8);

    s3.Pop();
    s3.Push(9);

    std::cout << s1 << std::endl;
    std::cout << s1.Size() << std::endl;

    std::cout << s2 << std::endl;
    std::cout << s2.Size() << std::endl;

    std::cout << s3 << std::endl;
    std::cout << s3.Size() << std::endl;
}
void Test2()
{
    Queue<int> s1, s2;
    numerate<int> f(100);

    s1.Push(1);
    s1.Push(2);
    s1.Push(3);

    s2.Push(5);
    s2 = s1;
    s2.Push(4);
    std::cout << s1 << std::endl;          // 1->2->3
    std::cout << s1.Size() << std::endl;

    std::cout << s2 << std::endl;          // 1->2->3->4
    std::cout << s2.Size() << std::endl;

    swap(s1, s2);

    std::cout << s1 << std::endl;          // 1->2->3->4
    std::cout << s1.Size() << std::endl;

    std::cout << s2 << std::endl;          // 1->2->3
    std::cout << s2.Size() << std::endl;

    std::generate(s1.begin(), s1.end(), f);

    std::cout << s1 << std::endl;          // 100->101->102->103
    std::cout << s1.Size() << std::endl;

    std::cout << sum<int, Queue<int>>(s2)<< std::endl;     // 6
}
void Test3() 
{
    Stack<int> s1;
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);

    std::cout << s1 << std::endl;
    std::cout << s1.Size() << std::endl;

    Stack<int> s2(s1), s3;

    s1.Pop();
    s1.Push(4);
    s1.Push(5);

    s2.Pop();
    s2.Push(6);

    std::cout << s1 << std::endl;
    std::cout << s1.Size() << std::endl;

    std::cout << s2 << std::endl;
    std::cout << s2.Size() << std::endl;

    s3 = s1;

    s1.Pop();
    s1.Push(7);
    s1.Push(8);

    s3.Pop();
    s3.Push(9);

    std::cout << s1 << std::endl;
    std::cout << s1.Size() << std::endl;

    std::cout << s2 << std::endl;
    std::cout << s2.Size() << std::endl;

    std::cout << s3 << std::endl;
    std::cout << s3.Size() << std::endl;
}
void Test4()
{
    Stack<int> s1, s2;
    numerate<int> f(100);

    s1.Push(1);
    s1.Push(2);
    s1.Push(3);

    s2.Push(5);
    s2 = s1;
    s2.Push(4);
    std::cout << s1 << std::endl;          // 1->2->3
    std::cout << s1.Size() << std::endl;

    std::cout << s2 << std::endl;          // 1->2->3->4
    std::cout << s2.Size() << std::endl;

    swap(s1, s2);

    std::cout << s1 << std::endl;          // 1->2->3->4
    std::cout << s1.Size() << std::endl;

    std::cout << s2 << std::endl;          // 1->2->3
    std::cout << s2.Size() << std::endl;

    std::generate(s1.begin(), s1.end(), f);

    std::cout << s1 << std::endl;          // 100->101->102->103
    std::cout << s1.Size() << std::endl;

    std::cout << sum<int, Stack<int>>(s2) << std::endl;     // 6
}