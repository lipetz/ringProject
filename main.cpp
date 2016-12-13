/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dlipetz
 *
 * Created on December 12, 2016, 8:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "ring.h"
using namespace std;

/*
 * 
 */
int main() {
//Im now fooling with GIT in fool branch
    ring<string> myRing(3);
    myRing.add("one");
    myRing.add("two");
    myRing.add("three");
    myRing.add("four");
    myRing.add("five");
    
    for(int i = 0; i < myRing.size(); ++i)
    {
        cout << myRing.get(i) << " ";
    }
    cout << "\nanother way :" << endl;
    
    //Need iterator begin(), end(), ++, *, != to use the below:
    // for(ring<string>::iterator it = myRing.begin(); it != myRing.end(); ++it)
    // cout << *it ;
    for(auto value: myRing)
    {
        cout << value << " ";
    }
    
    return 0;
}

