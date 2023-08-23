/*
 * Dylan Rothbauer
 * Section CS 144-003
 * a program that simulates a day of fishing out on the lake
 * 4/13/22
*/

#include "exam2.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>

double randomRange(double min, double max) {
    double random = (1.0 * rand()) / RAND_MAX;
    return min + random * (max - min);
}


int main() {
    
    FishBucket bluegill("Bluegill");
    FishBucket crappie("Crappie");
    FishBucket walleye("Walleye");
    FishBucket smallMouthBass("Small Mouth Bass");
    
   srand(time(0)); // // Initialize random number generator
    
    // angler will make 1000 casts throughout day
    for (int i = 0; i < 1000; i++) {
        
        double range = (rand() % 100) + 1.0; // range 1 - 100
        double chance = (rand() % 100) + 1.0; // %'s for fish
        double length = 0.0; // fish length
        
        if (range <= 10.0) { // 10% chance to catch something
            if (chance <= 50.0) { //if range is <= 50 ... Bluegill
                length = (rand() % 7) + 4.0; // length between 4 and 10
                bluegill.AddCatch(length);
                
            } else if (chance <= 80.0) { // if range is between <= 80 ... Crappie
                length = (rand() % 5) + 8.0; // length between 8 and 12
                crappie.AddCatch(length);
                
            } else if (chance <= 95.0) { // if range is between <= 95 ... Walleye
                length = (rand() % 9) + 12.0; // length between 12 and 20
                walleye.AddCatch(length);
                
            } else { // if range is between <= 100 ... Small Mouth Bass
                length = (rand() % 5) + 12.0; // length between 12 and 16
                smallMouthBass.AddCatch(length);
            }
        }
        
    }
    
    cout << endl << fixed << setw(25) << "Species";
    cout << setw(10) << "Count" << setw(15) << "Largest" << setw(15) << "Smallest" << setw(15) << "Average" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    
    bluegill.Print("Bluegill");
    crappie.Print("Crappie");
    walleye.Print("Walleye");
    smallMouthBass.Print("Small Mouth Bass");
         
    cout << "================================================================================" << endl;
       
    FishBucket newBucket("Mixed");
    
    // adding contents of each fish in new bucket
    newBucket.AddBucket(bluegill);
    newBucket.AddBucket(crappie);
    newBucket.AddBucket(walleye);
    newBucket.AddBucket(smallMouthBass);
    
    newBucket.Print("Mixed");
    
	return 0;
}
