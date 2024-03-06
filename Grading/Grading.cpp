// Get 5 test scores for a number of students from a data file. Calculate the average test score for each student, 
// determine the letter grade and write a report showing the average test score and letter grade for each student
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAXROWS = 50;
const int NCOLS = 5;
const string fileName = "StudentData.txt";

struct studentRecord
{
    string name;
    double scores[NCOLS];
    double average;
    char grade;
};

// Read student data off a file
// Preconditions - Expects reference to names array and scores array, which will empty, maximum number of rows (capacity)
// Postconditions - Return the actual number of rows on the file, store the data from the file in the arrays in memory
int getTestScores(studentRecord students[], int MaxRows);

// Calculate average test score for each student
//Preconditions - receives a table of raw scores for each student and the number of students
//Postcondition - The average test score is calculated and placed in the averages list
void calcAverages(studentRecord students[], int numRows);

//Transforms a numeric score into a letter grade
//Precondition: Takes in a score (between 1 - 100)
//Postcondition: returns A, B, C, D, or F
char getLetterGrade(double average);

// Writes a report showing the average test score and letter grade for each student
// Precondtions - Receives the names, the averages, and letter grades
// Postcondition - A formatted report is sent to the display
void writeReport(studentRecord students[], int numRecords);



int main()
{
    studentRecord students[MAXROWS];
    int numRecords;

    numRecords = getTestScores(students, MAXROWS);
    calcAverages(students, numRecords);
    for (int i = 0; i < numRecords; i++)
    {
        students[i].grade = getLetterGrade(students[i].average);
    }

    writeReport(students, numRecords);


    /*for (int i = 0; i < numRecords; i++)
    {
        cout << students[i] << " ";
        for (int j = 0; j < NCOLS; j++)
            cout << testScores[i][j] << " ";
        cout << averages[i] << " ";
        cout << letGrades[i] << endl;
    }*/

    return 0;
}

int getTestScores(studentRecord students[], int MaxRows)
{
    ifstream inFile;
    int rows = 0;
    inFile.open(fileName);
    if (!inFile.is_open())
    {
        cout << "Could not open file\n";
        return -1;
    }
    
    inFile >> students[rows].name;
    while(!inFile.eof() && !(rows >= MaxRows))
    {
        for (int i = 0; i < NCOLS; i++)
        {
            inFile >> students[rows].scores[i];
        }
        rows++;
        inFile >> students[rows].name;
    }
    inFile.close();
    return rows;
}

void calcAverages(studentRecord students[], int numRows)
{
    double sum = 0;
    for (int i = 0; i < numRows; i++)
    {
        sum = 0;
        for (int j = 0; j < NCOLS; j++)
            sum += students[i].scores[j];
        students[i].average = sum / (NCOLS);
    }
}

char getLetterGrade(double average)
{
    char letterGrade;
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}

void writeReport(studentRecord students[], int numRecords)
{
    cout << fixed << setprecision(2) << showpoint;
    cout << "Student      Average   Grade" << endl;
    for (int i = 0; i < numRecords; i++)
        cout << setw(14) << left << students[i].name << setw(6) << right << students[i].average << setw(6) << students[i].grade << endl;
}




