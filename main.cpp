#include <iostream>
#include "lpc/List.hpp"
#include "lpc/Queue.hpp"
#include "lpc/Stack.hpp"

using namespace std;

void readInput() {

}

int main() {

    readInput();

    List<int> l;
    List<float> l2;
    List<double> l4;
    List<List<int> > l3;
    List<Stack<Queue<int> > > s;
    l.insertEnd(3);
    cout << l << " ";

    l.insertEnd(4);
    l.insertEnd(5);
    l.insertEnd(6);
    l.insertEnd(6);

    cout << l << " ";

    



    return 0;
}