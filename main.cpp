//
//  main.cpp
//  lab28
//
//  Created by Vivek Kumar on 4/9/20.
//  Copyright © 2020 Vivek Kumar. All rights reserved.
//

#include <iostream>
using namespace std;
#include "citylist.h"

City cityArray[] = { {"Los Angeles",4340174},{"San Diego",1591688},{"San Francisco",871421},{"Sacramento", 505628},{"Stockton", 323761},{"Redding",90292},{"Las Vegas",711926},{"Reno",289485},{"Portland",730428},{"Seattle",752180},{"Eugene",221452} };
CityList cityList;




int main() {
    for (int i = 0; i < 11; i++) {
        CityNode* cn = new CityNode(cityArray[i]);
        cityList.append(cn);
    }
    cout << "Initializing cityList with cityArray[] using appending:" << endl;
    cityList.printCityList();
    cout << endl;
    cityList.insertionSortByPopulation();
    cout << "Insertion sort of cityList by population:" << endl;
    cityList.printCityList();
}
