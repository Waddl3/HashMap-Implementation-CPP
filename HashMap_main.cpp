#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "HashMap.h"  // Include custom HashMap implementation

class intHashCode {
public:
    int operator()(int k) { return k; }  // Hash function for integer keys
};

class stringHashCode {
public:
    int operator()(const std::string& k) { return k.size(); }  // Hash function for string keys based on length
};

void reverseKey(std::string& key) {
    // Function to reverse the order of characters in the input string
    int l = 0;
    int r = key.size() - 1;
    while (l < r) {
        std::swap(key[l], key[r]);
        ++l;
        --r;
    }
}

int main(int argc, char const* argv[]) {
    // Create a HashMap instance with integer keys and string values
    // Using intHashCode as the hashing function, initial size set to 11
    HashMap<int, std::string, intHashCode> mp(11);

    // Insert key-value pairs into the HashMap
    mp.put(13, "31");
    mp.put(21, "12");
    mp.put(5, "5");
    mp.put(37, "73");
    mp.put(15, "51");

    // Display all key-value pairs stored in the HashMap
    for (auto p = mp.begin(); !(p == mp.end()); ++p) {
        std::cout << "{(" << (*p).key() << ", " << (*p).value() << ")}" << std::endl;
    }

    // Check if the key 10 exists, if not print "DNE"
    auto p = mp.find(10);
    if (p == mp.end())
        std::cout << "DNE" << std::endl;
    else
        std::cout << "{(" << (*p).key() << ", " << (*p).value() << ")}" << std::endl;

    // Check if the key 21 exists, if not print "DNE"
    p = mp.find(21);
    if (p == mp.end())
        std::cout << "DNE" << std::endl;
    else
        std::cout << "{(" << (*p).key() << ", " << (*p).value() << ")}" << std::endl;

    // Attempt to erase key 37, if not found, throws 'NonexistentElement'
    mp.erase(37);

    // Check if the key 37 exists after erasing, if not print "DNE"
    p = mp.find(37);
    if (p == mp.end())
        std::cout << "DNE" << std::endl;
    else
        std::cout << "{(" << (*p).key() << ", " << (*p).value() << ")}" << std::endl;

    std::cout << "\n End part 1 \n" << std::endl;

    /*
        FILES PART 2 OF 3
    */

    // Open the input files for reading data
    std::fstream small_inFile("C:/Users/jesus/Documents/GitHub/Hash-Map/small1k.txt", std::ios_base::in);
    std::fstream large_inFile("C:/Users/jesus/Documents/GitHub/Hash-Map/large100k.txt", std::ios_base::in);

    // Create HashMaps to store data from the input files
    HashMap<int, std::string, intHashCode> filesMap(2 * 1000 + 1);
    HashMap<int, std::string, intHashCode> large_fileMaps(2 * 100000 + 1);

    // Read and store input from 'small1k.txt'
    int k = 0;
    std::string v = "";
    clock_t start, end;

    // Check if 'small1k.txt' is open, if not print "Not Found"
    if (!small_inFile.is_open())
        std::cout << "Not Found" << std::endl;

    // Store input from 'small1k.txt' into filesMap
    start = clock();
    while (small_inFile >> k) {
        v = std::to_string(k);
        reverseKey(v);
        filesMap.put(k, v);  // Store key-value pair
    }
    end = clock();
    std::cout << "small1k.txt Running-time: " << end - start << " ms" << std::endl;

    // Display a limited number of entries from 'small1k.txt'
    auto q = filesMap.begin();
    int n = 10;
    while (!(q == filesMap.end()) && n--) {
        std::cout << "{(" << (*q).key() << ", " << (*q).value() << ")}" << std::endl;
        ++q;
    }

    std::cout << "\n\n End part 2 \n\n" << std::endl;

    /*
        FILE PART 3 OF 3
    */

    // Read and store input from 'large100k.txt' into large_fileMaps
    if (!large_inFile.is_open())
        std::cout << "Not Found" << std::endl;

    start = clock();
    while (large_inFile >> k) {
        v = std::to_string(k);
        reverseKey(v);
        large_fileMaps.put(k, v);  // Store key-value pair
    }
    end = clock();

    std::cout << "large100k.txt Running-time: " << end - start << " ms" << std::endl;

    // Display a limited number of entries from 'large100k.txt'
    q = large_fileMaps.begin();
    n = 10;
    while (!(q == large_fileMaps.end()) && n--) {
        std::cout << "{(" << (*q).key() << ", " << (*q).value() << ")}" << std::endl;
        ++q;
    }

    std::cout << "\n\n End part 3 \n\n" << std::endl;

    return 0;
}
