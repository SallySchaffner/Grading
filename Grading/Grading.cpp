// Get 5 test scores for a number of students from a data file. Calculate the average test score for each student, 
// determine the letter grade and write a report showing the average test score and letter grade for each student
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAXROWS = 50;
const int NCOLS = 6;
const string fileName = "StudentData.txt";

// Read student data off a file
// Preconditions - Expects reference to names array and scores array, which will empty, maximum number of rows (capacity)
// Postconditions - Return the actual number of rows on the file, store the data from the file in the arrays in memory
int getTestScores(string names[], double scores[][NCOLS], int MaxRows);

// Calculate average test score for each student
//Preconditions - receives a table of raw scores for each student and the number of students
//Postcondition - The average test score is calculated and placed at the end of each row in the table
void calcAverages(double scores[][NCOLS], int numRows);

//Transforms a numeric score into a letter grade
//Precondition: Takes in a score (between 1 - 100)
//Postcondition: returns A, B, C, D, or F
char getLetterGrade(double average);



int main()
{
    string students[MAXROWS];
    double testScores[MAXROWS][NCOLS];
    int numRecords;

    numRecords = getTestScores(students, testScores, MAXROWS);
    calcAverages(testScores, numRecords);






    for (int i = 0; i < numRecords; i++)
    {
        cout << students[i] << " ";
        for (int j = 0; j < NCOLS; j++)
            cout << testScores[i][j] << " ";
        cout << getLetterGrade(testScores[i][NCOLS]) << endl;
    }
        

}

int getTestScores(string names[], double scores[][NCOLS], int MaxRows)
{
    ifstream inFile;
    int rows = 0;
    inFile.open(fileName);
    if (!inFile.is_open())
    {
        cout << "Could not open file\n";
        return -1;
    }
    
    inFile >> names[rows];
    while(!inFile.eof() && !(rows >= MaxRows))
    {
        for (int i = 0; i < NCOLS-1; i++)
        {
            inFile >> scores[rows][i];
        }
        rows++;
        inFile >> names[rows];
    }
    inFile.close();
    return rows;
}

void calcAverages(double scores[][NCOLS], int numRows)
{
    double sum = 0;
    for (int i = 0; i < numRows; i++)
    {
        sum = 0;
        for (int j = 0; j < NCOLS - 1; j++)
            sum += scores[i][j];
        scores[i][NCOLS - 1] = sum / (NCOLS - 1);
    }
}

char getLetterGrade(double average)
{
    cout << average << endl;
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




