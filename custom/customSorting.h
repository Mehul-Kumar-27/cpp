#ifndef CUSTOMSORTING_H

#define CUSTOMSORTING_H

#include <vector>

int findMinIndex(const std::vector<int> &vec, int index);
int findMaxIndex(const std::vector<int> &vec, int index);
void printVector(std ::vector<int> v);
void selectionSort(std ::vector<int> &v);
void bubbleSort(std ::vector<int> &v);
void insertionSort(std ::vector<int> &v);
void quickSort(std ::vector<int> &v, int low, int high);
void mergeSort(std ::vector<int> &v, int low, int high);
#endif
