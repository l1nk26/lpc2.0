#include <iostream>
#include "lpc/List.hpp"

using namespace std;

void readInput() {

}

int main() {

    readInput();

    List<int> l;
    l.insertEnd(3);
    cout << l << " ";

    l.insertEnd(4);
    l.insertEnd(5);
    l.insertEnd(6);
    l.insertEnd(6);

    cout << l << " ";

    



    return 0;
}