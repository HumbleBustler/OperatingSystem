#include <bits/stdc++.h> 
#include<pthread.h>
using namespace std; 
  
// maximum size of matrix 
#define MAX_row 4 
#define MAX_col 3  
// maximum number of threads 
#define MAX_THREAD 4 
  
int matA[MAX_row][MAX_col]; 
int matB[MAX_col][MAX_row]; 
int matC[MAX_row][MAX_row]; 
int step_i = 0; 
  
void* multi(void* arg) 
{ 
    int core = step_i++; 
  
    // Each thread computes 1/4th of matrix multiplication 
    for (int i = core * MAX_row / 4; i < (core + 1) * MAX_row / 4; i++)  
        for (int j = 0; j < MAX_row; j++)  
            for (int k = 0; k < MAX_col; k++)  
                matC[i][j] += matA[i][k] * matB[k][j]; 
} 
  
// Driver Code 
int main() 
{ 
    // Generating random values in matA and matB 
    for (int i = 0; i < MAX_row; i++) { 
        for (int j = 0; j < MAX_col; j++) { 
            matA[i][j] = rand() % 10; 
         //   matB[i][j] = rand() % 10; 
        } 
    } 
    for (int i = 0; i < MAX_col; i++) { 
        for (int j = 0; j < MAX_row; j++) { 
         //   matA[i][j] = rand() % 10; 
            matB[i][j] = rand() % 10; 
        } 
    } 
  
    // Displaying matA 
    cout << endl 
         << "Matrix A" << endl; 
    for (int i = 0; i < MAX_row; i++) { 
        for (int j = 0; j < MAX_col; j++)  
            cout << matA[i][j] << " "; 
        cout << endl; 
    } 
  
    // Displaying matB 
    cout << endl 
         << "Matrix B" << endl; 
    for (int i = 0; i < MAX_col; i++) { 
        for (int j = 0; j < MAX_row; j++)  
            cout << matB[i][j] << " ";         
        cout << endl; 
    } 
  
    // declaring four threads 
    pthread_t threads[MAX_THREAD]; 
  
    // Creating four threads, each evaluating its own part 
    for (int i = 0; i < MAX_THREAD; i++) { 
        int* p; 
        pthread_create(&threads[i], NULL, multi, (void*)(p)); 
    } 
  
    // joining and waiting for all threads to complete 
    for (int i = 0; i < MAX_THREAD; i++)  
        pthread_join(threads[i], NULL);     
  
    // Displaying the result matrix 
    cout << endl 
         << "Multiplication of A and B" << endl; 
    for (int i = 0; i < MAX_row; i++) { 
        for (int j = 0; j < MAX_row; j++)  
            cout << matC[i][j] << " ";         
        cout << endl; 
    } 
    return 0; 
} 