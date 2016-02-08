//
//  main.cpp
//  SearchAlgorithm
//
//  Created by Suu on 05/02/2016.
//  Copyright © 2016 suu. All rights reserved.
//

#include <iostream>
#include <vector>

#include "SearchTree.hpp"
#include "Fringe.hpp"
#include "State.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    for (int i = 0; i < 4; i++)
    {
        vector<int> *initialNumbers = new vector<int>(4,0);
        initialNumbers->at(0) = 3;
        initialNumbers->at(1) = 8;
        initialNumbers->at(2) = 8;
        initialNumbers->at(3) = 10;
        
        vector<int> *initialExpression = new vector<int>(1,0);
        initialExpression->at(0) = initialNumbers->at(i);
        
        initialNumbers->erase(initialNumbers->begin()+i);
        
        State *initialState = new State(initialExpression, initialNumbers);
        
        Fringe *myFringe = new Fringe();
        SearchTree *myTree = new SearchTree(initialState, myFringe);
        
        myTree->start();
        //myFringe->printFringe();
        delete initialNumbers;
        delete initialExpression;
    }
    
    return 0;
}
