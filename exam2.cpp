#include "exam2.h"

FishBucket::FishBucket(string species): species(species){}
 
 string FishBucket::GetSpecies() const {
    return species;
}
 
int FishBucket::GetCount() const {
    /* int count = 0;
     
    for(int i = 0; i < liveWell.size(); i++) {
        count++;
    }
    return count;
     */
     
    return liveWell.size();
 }
 
 double FishBucket::GetSmallestSize() const {

    // assuming there is something in the bucket :(
     double smallest = liveWell.at(0);
     
     for (int i = 1; i < liveWell.size(); i++) {
         if (smallest > liveWell.at(i)) {
             smallest = liveWell.at(i);
         }
        
    }
     return smallest;
 }
 
double FishBucket::GetLargestSize() const {
     
    double largest = liveWell.at(0);
     
     for (int i = 1; i < liveWell.size(); i++) {
         if (largest < liveWell.at(i)) {
             largest = liveWell.at(i);
         }
    }
    return largest;
 }
 
 double FishBucket::GetAverageSize() const {
     
     double count = 0.0;
     double total = 0.0;
     
     // count how many in vector
     for(int i = 0; i < liveWell.size(); i++) {
        count++;
    }
    
    // add up each length in vector
    for (int i = 0; i < liveWell.size(); i++) {
        total += liveWell.at(i);
    }
    
    // return average
    return total / count;
 }
 
void FishBucket::AddCatch(double length) {
     
    liveWell.push_back(length);
 }
 
 void FishBucket::AddBucket(FishBucket bucket) {
     
     // adds contents of each fish in new bucket
     for (int i = 0; i < bucket.liveWell.size(); i++) {
         liveWell.push_back(bucket.liveWell.at(i));
     }
 }

void FishBucket::Print(string name) const {
    cout << fixed << setw(25) << name << setw(10) << GetCount() 
         << setw(15) << setprecision(1) << GetLargestSize() 
         << setw(15) << setprecision(1) << GetSmallestSize() 
         << setw(15) << setprecision(1) << GetAverageSize() << endl;
}