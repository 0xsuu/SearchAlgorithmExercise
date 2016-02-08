//
//  SearchTree.cpp
//  SearchAlgorithm
//
//  Created by Suu on 06/02/2016.
//  Copyright © 2016 suu. All rights reserved.
//

#include "SearchTree.hpp"

using namespace std;

SearchTree::SearchTree(State *initialState, Fringe *myFringe)
{
    this->rootNode = new Node;
    this->rootNode->value = initialState;
    this->rootNode->successors = new vector<Node *>();
    this->myFringe = myFringe;
    expandedState = new vector<State *>;
}

int countE=0;
void SearchTree::expandNode(Node *expandNode)
{
    /*for (int i = 0; i < expandedState->size(); i++)
    {
        if (expandedState->at(i)->sameState(expandNode->value))
        {
            return;
        }
    }
    expandedState->push_back(expandNode->value);*/
    
    //cout << "Expanding node: " << expandNode->value->getExpresstion() << endl;
    //cout << "Expanding node: " << expandNode->value->value() << " with f()=" << expandNode->value->fitness() << " with fringe: ";
    countE++;
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < expandNode->value->availableNumbers->size(); j++)
        {
            vector<int> *expr = new vector<int>(*expandNode->value->expression);
            expr->push_back(i);
            expr->push_back(expandNode->value->availableNumbers->at(j));
                
            vector<int> *aval = new vector<int>(*expandNode->value->availableNumbers);
            aval->erase(aval->begin()+j);
                
            State *succ = new State(expr, aval);
            Node *nd = new Node;
            nd->value = succ;
            nd->predecessor = expandNode;
            nd->successors = new vector<Node *>();
            expandNode->successors->push_back(nd);
            myFringe->addNode(nd);
            //myFringe->printFringe();
        }
    }
    //myFringe->printFringe();
}

void SearchTree::printTree(int count, Node *startNode)
{
    for (int i = 0; i < count; i++)
    {
        cout << "    ";
    }
    cout << startNode->value->getExpresstion() << "=" << startNode->value->value() << endl;
    count++;
    for (int i = 0; i < startNode->successors->size(); i++)
    {
        this->printTree(count, startNode->successors->at(i));
    }
}





void SearchTree::start()
{
    myFringe->addNode(rootNode);
    
    while (!myFringe->empty())
    {
        Node *expand = myFringe->expandFirstNode();
        if (!expand->value->availableNumbers->size())
        {
            if (expand->value->value()==24)
            {
                cout << expand->value->getExpresstion() << "=24" << endl << "Found, tried: " << countE << " times" << endl;
                exit(0);
            }
        }
        
        expandNode(expand);
        //myFringe->printFringe();
    }
    //this->printTree(0, this->rootNode);
    cout << "Didn't find, tried: " << countE << " times" << endl;
}
