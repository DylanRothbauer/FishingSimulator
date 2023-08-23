#ifndef EXAM2_H
#define EXAM2_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class FishBucket {
private:
    string species;
    vector<double>liveWell;
    
public:
    FishBucket(string species);
    string GetSpecies() const;
    int GetCount() const;
    double GetSmallestSize() const;
    double GetLargestSize() const;
    double GetAverageSize() const;
    void AddCatch(double length);
    void AddBucket(FishBucket bucket);
    void Print(string name) const;
    
};










#endif // EXAM2_H