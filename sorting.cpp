#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    string name;
    double gpa;
    string id;

public:
    Student(string Name, string ID, double Gpa) : name(Name), id(ID), gpa(Gpa) {}

    Student() {}

    const string &getName() const {
        return name;
    }

    double getGpa() const {
        return gpa;
    }

    const string &getId() const {
        return id;
    }
};

int numberOfComparisons = 0;
void Merge(Student students[],int numStudents,int x);
int mergeSort(Student students[], int start, int end,int x);
int merge(Student students[], int l, int mid, int r,int x);


int main() {
    ifstream inputFile("input.txt");
    int numberOfStudents;
    inputFile >> numberOfStudents;
    inputFile.ignore();
    Student students[numberOfStudents];
    int numStudents = 0;
    string line, name, id;
    double gpa;
    int sz=numberOfStudents;
    while (sz--) {
        getline(inputFile, name);
        inputFile >> id >> gpa;
        inputFile.ignore();
        students[numStudents] = Student(name, id, gpa);
        numStudents++;
    }
    inputFile.close();


    Merge(students,numberOfStudents,1);


    return 0;
}
void Merge(Student students[],int numStudents,int x)
{
    ofstream outputFile;
    if(!x)
        outputFile.open("SortedByName.txt");
    else
        outputFile.open("SortedByGPA.txt");

    auto start = chrono::high_resolution_clock::now();
    numberOfComparisons = mergeSort(students, 0, numStudents - 1,x);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration =end-start;
    outputFile << "Merge Sort\n";
    outputFile << "Number of Comparisons: " << numberOfComparisons << "\n";
    outputFile << "Running Time: " + to_string(duration.count())+ "  numStudents * log(numStudents)\n";
    outputFile << "Sorted Student Elements:\n";
    for (int i = 0; i < numStudents; ++i) {
        outputFile << students[i].getName() << " " << students[i].getId() << " " << students[i].getGpa() << "\n";
    }

    outputFile.close();
}
int mergeSort(Student students[], int start, int end,int x) {
    int comparisons = 0;
    if (start >= end)
        return 0;

    int mid = (start + end) / 2;
    comparisons += mergeSort(students, start, mid,x);
    comparisons += mergeSort(students, mid + 1, end,x);
    comparisons += merge(students, start, mid, end,x);
    return comparisons;
}

int merge(Student students[], int l, int mid, int r,int x) {
    int comparisons = 0;
    int firstSize = mid - l + 1;
    int secondSize = r - mid;

    Student leftArray[firstSize];
    Student rightArray[secondSize];

    for (int i = 0; i < firstSize; i++)
        leftArray[i] = students[l + i];
    for (int j = 0; j < secondSize; j++)
        rightArray[j] = students[mid + 1 + j];

    int i = 0, j = 0;
    int k = l;
    while (i < firstSize && j < secondSize) {
        comparisons++;
        if(x)
        {

        if (leftArray[i].getGpa() <= rightArray[j].getGpa()) {
            students[k++] = leftArray[i++];
        } else {
            students[k++] = rightArray[j++];
        }
        }
        else
        {
            if (leftArray[i].getName() <= rightArray[j].getName()) {
                students[k++] = leftArray[i++];
            } else {
                students[k++] = rightArray[j++];
            }
        }
    }

    while (i < firstSize) {
        students[k++] = leftArray[i++];
    }
    while (j < secondSize) {
        students[k++] = rightArray[j++];
    }

    return comparisons;
}
