//
//  city.h
//  lab28
//
//  Created by Vivek Kumar on 4/9/20.
//  Copyright © 2020 Vivek Kumar. All rights reserved.
//

#ifndef CITY_H
#define CITY_H
#include <iostream>
#include<string>
using namespace std;

class City {
public:
    City() {
        name = "N/A";
        population = 0;
    }
    City(string nm, unsigned int pop) {
        name = nm;
        population = pop;
    }
    void setName(string name) { this->name = name; }
    void setPopulation(unsigned int population)
    {
        this->population = population;
    }
    string getName() const { return this->name; }
    unsigned int getPopulation() const { return this->population; }
    virtual void printInfo() const {
        cout << getName() << ": " << getPopulation() << endl;
    }
protected:
    string name;
    unsigned int population;
};
#endif

