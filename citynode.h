//
//  citynode.h
//  lab28
//
//  Created by Vivek Kumar on 4/9/20.
//  Copyright © 2020 Vivek Kumar. All rights reserved.
//
#ifndef CITYNODE_H
#define CITYNODE_H
#include<string>
#include<iostream>
#include "city.h"
using namespace std;
class CityNode {
public:
    City data;
    CityNode* next;
    CityNode* prev;
    CityNode(City city) {
        data = city;
        next = nullptr;
        prev = nullptr;
    }
};
#endif

