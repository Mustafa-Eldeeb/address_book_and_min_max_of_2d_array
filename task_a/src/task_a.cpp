// test_problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>





//find min func
// lets rename func to get max or min

void find_max_or_min( int arr[][3],int * max, int*min,int*row_min,int*row_max,int*col_min,int *col_max)
{
   // int min = arr[0][0];
    //int max = arr[0][0];
    //loop for every element and update min 
    

    
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j=0;j<3;j++)
        {
        
            if (arr[i][j] < *min)
            {
                *min = arr[i][j];
                *row_min = i;
                *col_min = j;
            }
            // lets add  max and update it 

            if (arr[i][j] > *max)
            {
                *max = arr[i][j];
                *row_max= i;
                    *col_max = j;
            }
        }

    }
    
}

//no need for this now
//find max fun
/*
int find_max()
{

}
*/



int main()
{
    
    //driver prog
    

    int arr[3][3] = { {3, 4, 6},

                      {2, 8, 1},

                      {4, 0, 4} };
    
    
    
    int max = arr[0][0];
    int min = arr[0][0];
    int row_min , row_max ,col_min,col_max;



    find_max_or_min(arr, &max, &min, & row_min, &row_max, &col_min, &col_max);
  
    //to calculate index
    int columns =3;
    int index_max = (row_max * 3 )+ col_max;
    int index_min = (row_min * 3 )+ col_min;


    // (index 5, row 2, col 3) and max is 6 (index 2, row 1, col 3)
    std::cout << "The min is "<<min<<" (index "<<index_min<<", row "<<row_min<<", col "<<col_max<<") and max is "<<max<<" (index "<<index_max<<", row "<<row_max<<", col "<<col_max<<")"<<std::endl;
}
