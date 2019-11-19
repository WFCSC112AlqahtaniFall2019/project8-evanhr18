//
// Created by Henry Evans on 11/19/19.
//

#ifndef PROJECT8_DATA_H
#define PROJECT8_DATA_H

using namespace std;
#include <iostream>



class Data {
    public:
        string playerName;
        int points;
        int rebounds;
        int assists;
        int blocks;
        friend ostream& operator << (ostream &out, const Data& print);
        bool operator< (const Data& object) const;
        Data();
        Data(string name, int pts, int rebs, int ast, int blk);
    };


#endif //PROJECT8_DATA_H
