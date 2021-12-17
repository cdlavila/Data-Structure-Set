#include "Set.h"
#include <iostream>
#include <set>
#include <string>

using namespace std;

// Default constructor implementation
Set::Set() = default;

// Configured constructor implementation
Set::Set(set<string> elements) {
  _elements = elements;
}

// Destructor implementation
Set::~Set() = default;

// Insert method implementation
void Set::insert(const string& element) {
  _elements.insert(element);
}

// Read method implementation
void Set::read(unsigned int size) {
  // Validate if the set is empty, in order to read it
  if (!_elements.empty()) {
    cout << "The set must be empty to can be read";
    exit(1);
  }
  // Validate if the set size is between 1 and 50
  if (!(size >= 1 && size <= 50)) {
    cout << "\nThe set size must between 1 and 50";
    exit(1);
  }
  // Read the set
  for (int j = 0; j < size; j++) {
    cout << "Enter the element " <<j+1 <<":";
    string element;
    cin >> element;
    _elements.insert(element);
  }
}

// Print method implementation
void Set::print() {
  cout << "{ ";
  // This is the way to traverse a set
  for (const auto & _element : _elements)
    cout << _element  <<" ";
  cout << "}";
}

// Implementation of the get union method
Set Set::get_union(const Set& c) {
  Set u = _elements;
  for (const auto & _element : c._elements)
    u.insert(_element);
  return u;
}

// Implementation of the get intersection method
Set Set::get_intersection(Set c) {
  Set n;
  for (const auto & _element : _elements) {
    if (c._elements.find(_element) != c._elements.end()) { // If the element [i] of the set "_elements" is in the set "c"
      n.insert(_element);
    }
  }
  return n;
}

// Implementation of the get difference method
Set Set::get_difference(Set c) {
  Set d;
  for (const auto & _element : _elements) {
    if (!(c._elements.find(_element) != c._elements.end())) { // If the element [i] of the set "_elements" is not in the set "c"
      d.insert(_element);
    }
  }
  return d;
}
