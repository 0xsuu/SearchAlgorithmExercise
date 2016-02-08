//
//  state.cpp
//  SearchAlgorithm
//
//  Created by Suu on 05/02/2016.
//  Copyright © 2016 suu. All rights reserved.
//

#include "State.hpp"

using namespace std;


double State::calculate(double a, int op, double b)
{
    double retVal = 0;
    if(op == 0b00)
    {
        retVal = a+b;
    }
    else if (op == 0b01)
    {
        retVal = a-b;
    }
    else if (op == 0b10)
    {
        retVal = a*b*1.0;
    }
    else if (op == 0b11)
    {
        retVal = a*1.0/b;
    }
    
    return retVal;
}

char State::realOp(int op)
{
    char retVal = 0;
    if(op == 0b00)
    {
        retVal = '+';
    }
    else if (op == 0b01)
    {
        retVal = '-';
    }
    else if (op == 0b10)
    {
        retVal = '*';
    }
    else if (op == 0b11)
    {
        retVal = '/';
    }
    
    return retVal;
}



State::State(vector<int> *expression, vector<int> *availableNumbers)
{
    this->expression = expression;
    this->availableNumbers = availableNumbers;
}

double State::value()
{
    double retValue = expression->front();
    if (expression->size() == 1)
    {
        return retValue;
    }
    
    int i = 0;
    while (i<expression->size()-1)
    {
        retValue = calculate(retValue, expression->at(i+1), expression->at(i+2));
        i+=2;
    }
    
    return retValue;
}

string State::getExpresstion()
{
    string retStr = "";
    for (int i = 0;i < expression->size(); i++)
    {
        if (i % 2 == 0)
        {
            retStr += to_string(expression->at(i));
        }
        else
        {
            retStr += this->realOp(expression->at(i));
        }
    }
    return retStr;
}

bool State::sameState(State *st)
{
    return (this->value()==st->value() && distance(availableNumbers->begin(), availableNumbers->end()) == distance(st->availableNumbers->begin(), st->availableNumbers->end()) && equal(availableNumbers->begin(), availableNumbers->end(), st->availableNumbers->begin()));
}




double State::fitness()
{
    return this->totalCost()+this->heuristic();
}

double State::heuristic()
{
    double retVal = this->value()-24;
    if (retVal<0) retVal*=-1.0;
    
    return retVal;
}

int State::totalCost()
{
    //return (int)this->getExpresstion().length()/2;
    return 0;
}
