#include <iostream>

const int n = 5;
const int m = 5;

using namespace std;

class Array
{
private:
  double dArr[m];
public:
  friend void InputArray(Array arr[]);
  friend void OutputArray(Array arr[]);
  friend void SortArray(Array arr[], int n);
  friend void CalcArray(Array arr[]);
};

void InputArray(Array  arr[])
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      cout << "[" << i + 1 << "][" << j + 1 << "] = ";
      cin >> arr[i].dArr[j];
    }
}
void OutputArray(Array  Arr[])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << Arr[i].dArr[j] << "\t";
    }
    cout << endl;
  }
}
void SortArray(Array  arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int BlockSizeIterator = 1; BlockSizeIterator < n; BlockSizeIterator *= 2)
    {
      for (int BlockIterator = 0; BlockIterator < n - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
      {
        int LeftBlockIterator = 0;
        int RightBlockIterator = 0;
        int LeftBorder = BlockIterator;
        int MidBorder = BlockIterator + BlockSizeIterator;
        int RightBorder = BlockIterator + 2 * BlockSizeIterator;
        RightBorder = (RightBorder < n) ? RightBorder : n;
        int* SortedBlock = new int[RightBorder - LeftBorder];

        while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
        {
          if (arr[i].dArr[LeftBorder + LeftBlockIterator] < arr[i].dArr[MidBorder + RightBlockIterator])
          {
            SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].dArr[LeftBorder + LeftBlockIterator];
            LeftBlockIterator++;
          }
          else
          {
            SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].dArr[MidBorder + RightBlockIterator];
            RightBlockIterator++;
          }
        }
        while (LeftBorder + LeftBlockIterator < MidBorder)
        {
          SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].dArr[LeftBorder + LeftBlockIterator];
          LeftBlockIterator++;
        }
        while (MidBorder + RightBlockIterator < RightBorder)
        {
          SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[i].dArr[MidBorder + RightBlockIterator];
          RightBlockIterator++;
        }

        for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
        {
          arr[i].dArr[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
        }
        delete SortedBlock;

      }

    }
  }
}
void CalcArray(Array arr[])
{
  int chu=4;
  double summ = 1.0;
  
  for (int j = 0; j < 5; j++)
  {
    
    double f = 0.0, k = 0;
    for (int i = j + 1; i < 5; i++)
    {
      f += arr[i].dArr[j];
         
        
        
      
    }
    f = f / chu;
    chu--;
    
    cout << "f(" << j + 1 << ") = " << f << "\n";

    summ *= (j == 4 ? 1 : f);

  }
  double avv;
  double N = n;
  
  avv = summ;
  
  cout << "\n" << "F = " << avv << "\n";
}

int main()
{
  cout << "Enter elements of matrix:\n" << endl;
  Array  arr[n];
  InputArray(arr);
  cout << "\nYour matrix:\n" << endl;
  OutputArray(arr);
  SortArray(arr, 5);
  cout << "\nSorted matrix:\n" << endl;
  OutputArray(arr);
  cout << "\nCalculations:\n" << endl;
  CalcArray(arr);
}
