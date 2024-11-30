#include <iostream>

int test();

// inline int sqr(int x){
//     return x*x;
// }

static int sqr(int x){
    return x*x;
}

int main(){
    std::cout << "Our sqr: " << sqr(2) << '\n';
    std::cout << "Their test:" << test() << '\n';
    return 0;
}