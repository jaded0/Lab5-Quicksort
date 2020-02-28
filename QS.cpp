//
//  QS.cpp
//  Lab5-Quicksort
//
//  Created by Jaden Lorenc on 22/02/2020.
//
//

#include "QS.h"
#include <string>

using namespace std;

QS::QS(): size(0), index(0)  {}
QS::~QS() {}
/*
* sortAll()
*
* Sorts elements of the array.  After this function is called, every
* element in the array is less than or equal its successor.
*
* Does nothing if the array is empty.
*/
void QS::sortAll(){
  cout << sort(0, index-1) << endl;
}
bool QS::sort(int start, int finish){
  cin.ignore();
  //cout << start << " - " << finish << endl;
  if (finish - start>1){
    int pivot = partition(start,finish-1,medianOfThree(start, finish));
    if(pivot == -1) return false;
    //swap(ra[start], ra[pivot]);
    //cout <<  "so far: " << getArray() << endl;
    //cout << "pivot " << pivot << endl;
    sort(start, pivot);
    //cout << "pivot " << pivot << endl;
    sort(pivot+1, finish);
    return true;
  } else return false;
}


void QS::swap(int&c,int&b){
    c=c+b;
    b=c-b;
    c=c-b;
}
/*
* medianOfThree()
*
* The median of three pivot selection has two parts:
*
* 1) Calculates the middle index by averaging the given left and right indices:
*
* middle = (left + right)/2
*
* 2) Then bubble-sorts the values at the left, middle, and right indices.
*
* After this method is called, data[left] <= data[middle] <= data[right].
* The middle index will be returned.
*
* Returns -1 if the array is empty, if either of the given integers
* is out of bounds, or if the left index is not less than the right
* index.
*
* @param left
* 		the left boundary for the subarray from which to find a pivot
* @param right
* 		the right boundary for the subarray from which to find a pivot
* @return
*		the index of the pivot (middle index); -1 if provided with invalid input
*/
int QS::medianOfThree(int first, int last){
  if(index==0 || first >= last || last > index-1  || first < 0) return -1;
  try {
    int middle;
    if(first + last == 0) return -1;
    middle = (first + last)/2;
    //sort!
    if(ra[first] > ra[middle]) { cout << "Aswap " << first << " and " << middle << endl;swap(ra[first], ra[middle]);}
    cout <<  "so far: " << getArray() << endl;
    if(ra[middle] > ra[last]) { cout << "Bswap " << middle << " and " << last << endl;swap(ra[middle], ra[last]);}
    cout <<  "so far: " << getArray() << endl;
    if(ra[first] > ra[middle]) { cout << "Cswap " << first << " and " << middle << endl;swap(ra[first], ra[middle]);}
    cout <<  "so far: " << getArray() << endl;

    return middle;
  } catch(...) {
    return -1;
  }
}

/*
* Partitions a subarray around a pivot value selected according to
* median-of-three pivot selection.  Because there are multiple ways to partition a list,
* we will follow the algorithm on page 611 of the course text when testing this function.
*
* The values which are smaller than the pivot should be placed to the left
* of the pivot; the values which are larger than the pivot should be placed
* to the right of the pivot.
*
* Returns -1 if the array is null, if either of the given integers is out of
* bounds, or if the first integer is not less than the second integer, or if the
* pivot is not within the sub-array designated by left and right.
*
* @param left
* 		the left boundary for the subarray to partition
* @param right
* 		the right boundary for the subarray to partition
* @param pivotIndex
* 		the index of the pivot in the subarray
* @return
*		the pivot's ending index after the partition completes; -1 if
* 		provided with bad input
*/
int QS::partition(int first, int last, int pivotIndex){
  cout <<  "\nstarting out: " << getArray() << endl;
  if(index==0 || pivotIndex == -1 || first >= last || last > index-1 || first < 0 || pivotIndex>last) return -1;
  if (first != pivotIndex) { cout << "1swap " << first << " and " << pivotIndex << endl;swap(ra[first], ra[pivotIndex]);}
  cout << "first: " << first << " last " << last << " pivot index: " << pivotIndex << endl;
  int up = first + 1;
  int down = last;
  cout <<  "so far: " << getArray() << " up: " << up << " down: " << down << endl;

  do {
    while((up != last) && !(ra[first]<ra[up])) ++up;
    cout <<  "so far: " << getArray() << " up: " << up << " down: " << down << endl;

    while (ra[first] < ra[down]) --down;
    cout <<  "so far: " << getArray() << " up: " << up << " down: " << down << endl;

    if (up<down){ cout << "2swap " << up << " and " << down << endl; swap(ra[up], ra[down]); }
    cout <<  "so far: " << getArray() << " up: " << up << " down: " << down << endl;

  } while (up<down);
  if (first != down){ cout << "3swap " << first << " and " << down << endl; swap(ra[first], ra[down]);}
  cout <<  "so far: " << getArray() << " up: " << up << " down: " << down << endl;

  return down;
}

/*
* Produces a comma delimited string representation of the array. For example: if my array
* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
* with no trailing comma.  The number of cells included equals the number of values added.
* Do not include the entire array if the array has yet to be filled.
*
* Returns an empty string, if the array is NULL or empty.
*
* @return
*		the string representation of the current array
*/
string QS::getArray() const{
  string response;
  if (index>0){
    for (size_t i = 0; i < index; i++) {
      response += to_string(ra[i]) + ",";
    }
    return response.substr(0, response.length() - 1);
  } else return "";
}


/*
* Returns the number of elements which have been added to the array.
*/
int QS::getSize() const{
  return index;
}

/*
* Adds the given value to the end of the array starting at index 0.
* For example, the first time addToArray is called,
* the give value should be found at index 0.
* 2nd time, value should be found at index 1.
* 3rd, index 2, etc up to its max capacity.
*
* If the array is filled, do nothing.
* returns true if a value was added, false otherwise.
*/
bool QS::addToArray(int value){
  if (index<size){
    //cout << value << endl;
    ra[index] = value;
    index++;
    return true;
  } else return false;
}

/*
* Dynamically allocates an array with the given capacity.
* If a previous array had been allocated, delete the previous array.
* Returns false if the given capacity is non-positive, true otherwise.
*
* @param
*		size of array
* @return
*		true if the array was created, false otherwise
*/
bool QS::createArray(int capacity){

  if(size != 0) delete[] ra;
  if(capacity>0) {
    ra = new int[capacity];
    size = capacity;
    index = 0;
    //fill in the array with 0s
    for (size_t i = 0; i < size; i++) {
      ra[i] = 0;
    }
    return true;
  }
  return false;
}

/*
* Resets the array to an empty or NULL state.
*/
void QS::clear(){
  if(size != 0) delete[] ra;
  size = 0;
  index = 0;
}
