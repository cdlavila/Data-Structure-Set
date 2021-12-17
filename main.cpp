#include <iostream>
#include <vector>
#include "Set.h"
using namespace std;

// Gets the difference between all sets
Set get_difference(vector<Set> sets) {
  Set d = sets[0];
  unsigned int number_of_sets = sets.size();
  for (int i = 1; i < number_of_sets; i++) {
    d = d.get_difference(sets[i]);
  }
  return d;
}

// Gets the intersection between all sets
Set get_intersection(vector<Set> sets) {
  Set n = sets[0];
  unsigned int number_of_sets = sets.size();
  for (int i = 1; i < number_of_sets; i++) {
    n = n.get_intersection(sets[i]);
  }
  return n;
}

// Gets the union between all sets
Set get_union(vector<Set> sets) {
  Set u = sets[0];
  unsigned int number_of_sets = sets.size();
  for (int i = 1; i < number_of_sets; i++) {
    u = u.get_union(sets[i]);
  }
  return u;
}

// Print all sets
void print_sets(vector<Set> sets) {
  unsigned int n = sets.size();
  for (int i = 0; i < n; i++) {
    cout << "\nSet " <<i+1 <<" = ";
    sets[i].print();
  }
}

// Read all sets
vector<Set> read_sets(int number_of_sets) {
  // Validate if the number of sets is between 2 and 4.
  if (!(number_of_sets >= 2 && number_of_sets <= 4)) {
    cout << "\nThe number of sets must be between 2 and 4.";
    exit(1);
  }
  // Reads the sets one by one and returns a vector with all the sets.
  vector<Set> sets(number_of_sets);
  for (int i = 0; i < number_of_sets; i++) {
    cout << "\nEnter the size of the set " <<i+1 <<":";
    int size;
    cin >> size;
    sets[i].read(size);
  }
  return sets;
}

// Main function
int main(){
  cout << "Enter the number of sets:";
  int number_of_sets;
  cin >> number_of_sets;
  vector<Set> sets = read_sets(number_of_sets);

  cout << "\nThe sets that have been entered are:";
  print_sets(sets);

  Set u = get_union(sets);
  Set n = get_intersection(sets);
  Set d = get_difference(sets);

  cout << "\n\nThe operations between the sets are:";
  cout << "\nUnion: ";
  u.print();
  cout << "\nIntersection: ";
  n.print();
  cout << "\nDifference: ";
  d.print();

  return 0;
}
