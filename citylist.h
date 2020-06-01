//
//  citylist.h
//  lab28
//
//  Created by Vivek Kumar on 4/9/20.
//  Copyright © 2020 Vivek Kumar. All rights reserved.
//
#ifndef CITYLIST_H
#define CITYLIST_H
#include<string>
#include "citynode.h"


class CityList {
public:

    CityList() {
        head = tail = nullptr;
        struct CityNode {
            CityNode* prev;
            CityNode* next;
            int data;
        };
    }
    void append(CityNode* cityNode) {
        if (head == nullptr) {
            head = cityNode;
            tail = cityNode;
        }
        else {
            tail->next = cityNode;
            cityNode->prev = tail;
            tail = cityNode;
        }
    }

    void prepend(CityNode* cityNode) {
        if (head == nullptr) {
            head = cityNode;
            tail = cityNode;
        }
        else {
            cityNode->next = head;
            head->prev = cityNode;
            head = cityNode;
        }
    }

    void printCityList() {
        CityNode* cityNode = head;
        while (cityNode != nullptr) {
            cityNode->data.printInfo();
            cityNode = cityNode->next;
        }
    }

    CityNode* search(string cityName) {
        CityNode* cityNode;
        cityNode = head;
        while (cityNode != nullptr) {
            if (cityNode->data.getName() == cityName) {
                return cityNode;
            }
            cityNode = cityNode->next;
        }
        return NULL;
    }
    void insert(CityNode* currNode, CityNode* cityNode) {
        CityNode* sucNode;
        if (head == nullptr) {
            head = cityNode;
            tail = cityNode;
        }
        else if (currNode == tail) {
            tail->next = cityNode;
            cityNode->prev = tail;
            tail = cityNode;
        }
        else {
            sucNode = currNode->next;
            cityNode->next = sucNode;
            cityNode->prev = currNode;
            currNode->next = cityNode;
            sucNode->prev = cityNode;
        }
    }

    void remove(CityNode* currNode) {
        CityNode* sucNode = currNode->next;
        CityNode* predNode = currNode->prev;
        if (sucNode != nullptr) {
            sucNode->prev = predNode;
        }
        if (predNode != nullptr) {
            predNode->next = sucNode;
        }
        if (currNode == head) {
            head = sucNode;
        }
        if (currNode == tail) {
            tail = predNode;
        }
    }

    void insertionSortByPopulation() {
        CityNode* currNode = head->next;
        while (currNode != nullptr) {
            CityNode* nextNode = currNode->next;
            CityNode* searchNode = currNode->prev;
            while (searchNode != nullptr && searchNode->data.getPopulation() > currNode->data.getPopulation()) {
                searchNode = searchNode->prev;
            }
            remove(currNode);
            if (searchNode == nullptr) {
                currNode->prev = nullptr;
                prepend(currNode);
            }
            else {
                insert(searchNode, currNode);
            }
            currNode = nextNode;
        }
    }
private:
    CityNode* head;
    CityNode* tail;
};
#endif
