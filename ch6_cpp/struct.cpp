#include <iostream>

struct Marks {
    public:
        int num;
        static int static_num;
    
        Marks(){}
        //Marks():static_num(99){}
        Marks(int x) {num = x;}
    
        void set(int temp) {num = temp;}
        void display(){std::cout << "num=" << num << std::endl; } 
};

// Static member
int Marks::static_num = 1;
 
int main()
{
    Marks m1;
    m1.display();
    m1.set(9);
    m1.display();

    // Constructor creation
    struct Marks m2(2);
    m2.display();

    // Direct intilization
    struct Marks m3;
    m3.num = 7;
    std::cout << m3.num  << std::endl;

    // sizeof()
    struct Marks m4;
    std::cout << "sizeof() " << sizeof(m4)  << std::endl;

    // Static member
    std::cout << "static member " << m1.static_num << std::endl;
    
    return 0; 
}
