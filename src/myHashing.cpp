/**
 * @file main.cpp
 * @brief This demonstrates header files, separate cpp files, and some searching.
 * @details Implements and times sequential searching using FIFO class
 * @author Seth McNeill
 * @date 2021 February 17
 * 
 */

#include <iostream> // for cout, cin
#include <vector> // for the vector container
#include <numeric> // for accumulate
#include "fifo.h" // for FIFO structure/container
using namespace std;

/**
 * This class implements storage and hash search examples
 */
class myHashSearch {
public:
    vector<int> storage; //!< Variable that stores the array
    int lenStorage;

    /**
     * Constructor: Only stores values >=0
     */
    myHashSearch(int size) {
        cout << "Added a seqSearch instance" << endl;
        lenStorage = size;
        // create and initialize the storage
        for(int ii = 0; ii < size; ii++) {
            storage.push_back(-1);
        }
    }

    /**
     * Fills storage with sequential numbers starting with start
     * 
     * @param start - The number to start filling at
     */
    void fillStorage(int start) {
        int ind; // index into the hash table
        for(int ii = 0; ii < lenStorage; ii++) {
            cout << "Adding " << start << " at location " << start % lenStorage << endl;
            storage.at(start % lenStorage) = start;
            start++;
        }
    }

    /**
     * prints the contents of storage (beware of calling on large values)
     */
    void printStorage(){
        if(lenStorage < 100) {
            for(int ii = 0; ii < lenStorage; ii++) {
                cout << storage.at(ii) << '\t';
            }
            cout << endl;
        }
    }

    /**
     * Hash search for the value passed
     * 
     * @param searchTerm The term to search for
     * @param N Returns the number of iterations to find searchTerm (Pass by reference)
     * @return Returns the location of searchTerm or -1 if not found
     */
    int search(int searchTerm, int &N) {
       N = 1; // initialize N
       return(storage.at(searchTerm % lenStorage));
    }
  
 };

/**
 * Calculate the average value of a integer vector
 * 
 * This is taken from:
 * https://stackoverflow.com/a/35833470
 * It uses std::accumulate.
 * 
 * @param v is a integer std::vector
 * @returns The average value of the contents of v
 */
double avg1(vector<int> const& v) {
    return 1.0 * accumulate(v.begin(), v.end(), 0LL) / v.size();
}

int main(int, char**) {
    int lenHashTable = 5;
    myHashSearch s1(lenHashTable); 
    int nIterations;
    vector<int> allIters;
    s1.printStorage();
    s1.fillStorage(11);
    s1.printStorage();

    cout << "Hash based searching" << endl;
    for(int ii = 0; ii < (lenHashTable+1); ii++)
    {
        s1.search(ii, nIterations);
        allIters.push_back(nIterations);
    }
    cout << "Calculating the average" << endl;
    cout << "The average number of iterations for hash search is ";
    cout << avg1(allIters) << endl;

}
