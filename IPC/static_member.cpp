#include <iostream>
#if HK
class A
{
public:
    static int val = 0;
private:
    static int val2;
};

int main()
{
    A a1,a2;
    std::cout << a1.val << std::endl; 
    
    a1.val = 5;
    //a2.val2 = 10;
    std::cout << a1.val << std::endl; 
    std::cout << a2.val << std::endl; 


    return 0;
}

#endif


class A
{
public:
    static int val;
private:
    static int val2;
};

// Definition of static members outside the class
int A::val = 0;
int A::val2 = 0;

int main()
{
    A a1, a2;
    std::cout << a1.val << std::endl;  // This will print the initial value of val which is 0
    
    a1.val = 5;
    //a2.val2 = 10;  // This line will cause a compilation error because val2 is private
    
    std::cout << a1.val << std::endl;  // This will print 5
    std::cout << a2.val << std::endl;  // This will also print 5 because val is static and shared among all instances of A

    return 0;
}
