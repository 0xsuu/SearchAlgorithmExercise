//
//  state.hpp
//  SearchAlgorithm
//
//  Created by Suu on 05/02/2016.
//  Copyright © 2016 suu. All rights reserved.
//

#ifndef state_hpp
#define state_hpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class State
{
public:
    State(vector<int> *expression, vector<int> *availableNumbers);
    
    vector<int> *expression;
    vector<int> *availableNumbers;
    
    double value();
    string getExpresstion();
    
    double fitness();
    double heuristic();
    int totalCost();
    
    bool sameState(State *st);
    
private:
    double calculate(double a, int op, double b);
    char realOp(int op);
};

#endif /* state_hpp */
