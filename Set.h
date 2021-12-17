#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <set>
#include <string>

using namespace std;

class Set {
private:
    set<string> _elements;
public:
    // Default constructor
    Set();

    // Constructor to initialization
    Set(set<string> elements);

    // Destructor
    ~Set();

    // Method insert, inserts an element in the set
    void insert(const string& element);

    // Method read, reads the elements of the set by keyboard
    void read(unsigned int size);

    // Method print, prints the set on the screen.
    void print();

    // Method get union, gets the union between the set and the set c
    Set get_union(const Set& c);

    // Method get intersection, gets the intersection between the set and the set c
    Set get_intersection(Set c);

    // Method get difference, gets the difference between the set and the set c
    Set get_difference(Set c);
};

#endif //CONJUNTO_H