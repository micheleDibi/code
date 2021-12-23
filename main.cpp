#include <iostream>
#include "codePuntatori.h"
#include "codeVettoriCircolari.h"

using namespace std;

int main()
{
    /*
    vectorQueue<int> roger;

    roger.insertQueue(10);
    roger.insertQueue(20);
    roger.insertQueue(30);
    roger.insertQueue(40);
    roger.insertQueue(50);
    roger.insertQueue(60);
    roger.insertQueue(70);

    roger.removeQueue();
    roger.removeQueue();

    roger.print();
    */

    linkedQueue<int> frank;

    frank.insertQueue(10);
    frank.insertQueue(20);
    frank.insertQueue(30);
    frank.insertQueue(40);
    frank.insertQueue(50);
    frank.insertQueue(60);
    frank.insertQueue(70);

    frank.removeQueue();
    frank.removeQueue();

    frank.print();

    return 0;
}
