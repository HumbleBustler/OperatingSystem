# include <stdio.h>
# include <pthread.h>

int MAT1[10][10];
int MAT2[10][10];
int MAT3[10][10];

int r1,c1,r2,c2;

void *thread_Multiply_Matrix(void *);

int step_i = 0;
int main()
{
    pthread_t tid[4];    
    int iCount,jCount,kcount;
    
    printf("Enter Number of Rows For Matrix 1 :");
    scanf("%d",&r1);
    
    printf("Enter Number of Columns For Matrix 1 :");
    scanf("%d",&c1);
    
    for(iCount=0;iCount<r1;iCount++)
    {
        for(jCount=0;jCount<c1;jCount++)
        {
            printf("Enter Mat1[%d][%d] :",iCount,jCount);
            scanf("%d",&MAT1[iCount][jCount]);
        }
    }
    
    printf("\n");
    
    printf("Enter Numer of Rows For Matrix 2 :");
    scanf("%d",&r2);
    
    printf("Enter Number of Columns For Matrix 2 :");
    scanf("%d",&c2);
    
    for(iCount=0;iCount<r2;iCount++)
    {
        for(jCount=0;jCount<c2;jCount++)
        {
            printf("Enter Mat2[%d][%d] :",iCount,jCount);
            scanf("%d",&MAT2[iCount][jCount]);
        }
    }
    
    if(c1!=r2)
    {
        printf("Multipication of Matrix not Possible !!!");
    }
    else
    {
        for(iCount=0;iCount<r1;iCount++)
        {
            for(jCount=0;jCount<c2;jCount++)
            {
                MAT3[iCount][jCount]=0;
            }
        }
/*        
        pthread_create(&tid,NULL,thread_Multiply_Matrix,NULL);
        
        for(iCount=0;iCount<r1;iCount=iCount+2)
        {
            for(jCount=0;jCount<c2;jCount++)
            {
                for(kcount=0;kcount<c1;kcount++)
                {
                    MAT3[iCount][jCount]+=MAT1[iCount][kcount] * MAT2[kcount][jCount];
                }
            }
        }
        
        pthread_join(tid,NULL);
*/
         for (int i = 0; i < 4; i++) { 
            int* p;
            printf("thread creation\n"); 
            pthread_create(&tid[i], NULL, thread_Multiply_Matrix, (void*)(p)); 
            printf("%d thread active\n",i);
        } 
      
        // joining and waiting for all threads to complete 
        for (int i = 0; i < 4; i++)  
        {    printf("waiting for join\n");
            pthread_join(tid[i], NULL);     
      
        }
        
    printf("\n Matrix 1 \n");
    
    for(iCount=0;iCount<r1;iCount++)
    {
        for(jCount=0;jCount<c1;jCount++)
        {
            printf("%d \t",MAT1[iCount][jCount]);
        }
        printf("\n");
    }    
    
    printf("\n Matrix 2 \n");
    
    for(iCount=0;iCount<r2;iCount++)
    {
        for(jCount=0;jCount<c2;jCount++)
        {
            printf("%d \t",MAT2[iCount][jCount]);
        }
        printf("\n");
    }    
    
    printf("\n Multipication of Matrix ...\n");
    
    for(iCount=0;iCount<r1;iCount++)
    {
        for(jCount=0;jCount<c2;jCount++)
        {
            printf("%d \t",MAT3[iCount][jCount]);
        }
        printf("\n");
    }    
    return 0;
}
}

void *thread_Multiply_Matrix(void *para)
{  

    int core = step_i++;
    printf("thread %d started\n",core);
    int iCount,jCount,kcount;
    for(iCount=core * r1 /4; iCount<(core + 1)*r1/4 ;iCount++)
        {
            for(jCount=0;jCount<c2;jCount++)
            {
                for(kcount=0;kcount<c1;kcount++)
                {                    
                    MAT3[iCount][jCount]+=MAT1[iCount][kcount] * MAT2[kcount][jCount];
                }
            }
        }
        
    printf("thread finished ...");
    pthread_exit(0);
}