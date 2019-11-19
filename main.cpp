#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include "Data.h"

using namespace std;

int main() {

    ifstream in;                // declaring variables
    ofstream out;
    string firstName;
    string lastName;
    string name;
    string pts;
    string rebs;
    string ast;
    string blk;

    in.open("../NBA Projected Stats 2019.csv");         //opening input file
    if (!in.is_open()) {
        cout << "Could not open input file" << endl;        //checking to see if file is open
        return 1;
    }
    out.open("../stacked.txt");                         // opening stacked file
    if (!out.is_open()) {
        cout << "Could not open stacked file" << endl;      // checking to see if file is open
        return 1;
    }

    cout << "Reading input file" << endl;
    stack<Data> stack1;                                     // declaring container variables
    queue<Data> queue1;
    priority_queue<Data> priority1;

    while (!in.eof()) {                 // reading data
        in >> firstName;
        in >> lastName;
        in >> pts;
        in >> rebs;
        in >> ast;
        in >> blk;

        name = firstName + " " + lastName;

        Data object(name, stoi(pts), stoi(rebs), stoi(ast), stoi(blk));
        stack1.push(object);
        queue1.push(object);
        priority1.push(object);
    }

    in.close();

    while (!stack1.empty()) {           // copying data into stack
        out << stack1.top();
        stack1.pop();
    }
    out.close();

    out.open("../queued.txt");

    while (!queue1.empty()) {           // copying data into queue
        out << queue1.front();
        queue1.pop();
    }
    out.close();

    out.open("../sorted.txt");      // copying data to sorted
    while (!priority1.empty()) {
        out << priority1.top();
        priority1.pop();
    }
    out.close();



    return 0;
}