#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Generate a random number.
int randomGen()
{
  srand (time(NULL));

  int randomNum = rand() % 20 + 1;
  cout << "The Random Number is: " << randomNum << endl;
  return randomNum;
}

//Fill both arrays with random values.
void fillArrays(int array1[], int array2[])
{
  srand (time(NULL));

  cout << "Array 1 = ";
  for (int i = 0; i < 5; i++)
  {
    array1[i] = rand() % 15 + 1;
    cout << array1[i];
    if (i != 4)
    {
      cout << ", ";
    }

  }
  cout << endl;

  cout << "Array 2 = ";
  for (int i = 0; i < 5; i++)
  {
    array2[i] = rand() % 15 + 1;
    cout << array2[i];

    if (i != 4)
    {
      cout << ", ";
    }
  }

  cout << endl;
}

//Calculate which pair of values are closest to our random number;
void calculateClosest(int array1[], int array2[], int &tempV, const int randomNum, int &currentV, int &index1, int &index2)
{

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      tempV = array1[i] + array2[j];
      tempV = tempV - randomNum;
      tempV = abs (tempV);

      if (tempV <= currentV)
      {
        currentV = tempV;
        index1 = i;
        index2 = j;
      }
    }
  }
}

int main() {
  //initialize variables
  int array1[5];
  int array2[5];
  int currentV = 1000;
  int tempV = 0;
  int randomNum = 0;
  int index1 = 0;
  int index2 = 0;

  //Perform functions
  randomNum = randomGen();
  fillArrays(array1, array2);
  calculateClosest(array1, array2, tempV, randomNum, currentV, index1, index2);

  //Print the answer;
  cout << endl << "Index " << index1 << " in Array 1 (which is equal to " << array1[index1] << ") and Index " << index2 << " in Array 2 (which is equal to " << array2[index2] << ") give the closest sum to our random number of " << randomNum << endl;

 return 0;
}
