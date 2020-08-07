#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ITERS 1000

struct bucket{
    long count;
    long * value;
};

int comparator(const void* first, const void* second){
    long x = *((long*)first), y =  *((long*)second);
    if (x == y)
        return 0;
    else if (x < y)
        return -1;
    else
        return 1;
}

void swap(long* a, long* b){
    long temp = *a;
    *a = *b;
    *b = temp;
}

//Sorting functions here

//Bubble Sort
void bubbleSort(long * arr, long n) {
    long i, j; 
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]); 
} 

//Selection Sort
void selectionSort(long * arr, long n) {
    long i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

//Heap Sort
void heapify(long * arr, long n, long i){ 
    long largest = i; // Initialize largest as root 
    long l = 2*i + 1; // left = 2*i + 1 
    long r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
}
void heapSort(long * arr, long n) {
    // Build heap 
    for (long i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (long i=n-1; i>0; i--){
        // Move current root to end 
        swap(&arr[0], &arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
}

//Bucket Sort
void bucketSort(long * array , long n){
    struct bucket buckets[3];
    long i, j, k;
    long thirdDivider = n/3, twoThirdDivider = (2*n)/3;
    for (i = 0; i < 3; i++){
        buckets[i].count = 0;
        buckets[i].value = (long*)malloc(sizeof(long) * n);
    }
    
    for (i = 0; i < n; i++){
        if (array[i] < thirdDivider){
            buckets[0].value[buckets[0].count++] = array[i];
        }
        else if (array[i] > twoThirdDivider){
            buckets[2].value[buckets[2].count++] = array[i];
        }
        else{
            buckets[1].value[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++){
        // now using quicksort to sort the elements of buckets
        qsort(buckets[i].value, buckets[i].count, sizeof(long), &comparator);
        for (j = 0; j < buckets[i].count; j++){
            array[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
    }
}

void displayArray(long * arr, long size){
    for(long i = 0; i < size ; i++)
        printf(" %d", arr[i]);
}


void getRandArray(long * randArr, long size){
    for(long i = 0; i < size ; i++){
        randArr[i] = i+1;
    }
    //Shuffle Array
    for (long i = 0; i < size; i++) {
        long temp = randArr[i];
        long randomIndex = rand() % size;
        randArr[i] = randArr[randomIndex];
        randArr[randomIndex] = temp;
    }
}

void tester(double * timeArray, long * elemCount,  void (* sortFunc) (long *, long), long times, long elemMul){
    //Here, times is the number of times the tester will run and elemMul is the multiplier for
    //increasing the number of elements after every iteration
    //Times are stored in timesArray
    //Number of elements in the iteration are stored in elemCount array

    clock_t t;
    double time_taken;
    
    for(long i = 0; i < times ; i++){
        printf("\n--Iteration %ld--\n", i+1);
        
        //Create a random array to sort
        long currArrSize = elemMul * (i+1);
        long tempArr[currArrSize];
        getRandArray(tempArr, currArrSize);
        
        //Only for console output
//         printf("\nThe random array is : \n");
//         displayArray(tempArr, currArrSize);
//         printf("\n\n");
        
        //Sort and measure time
        t = clock();
        (*sortFunc)(tempArr, currArrSize);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        
        //Store the time taken and current elemCount in given arrays
        timeArray[i] = time_taken;
        elemCount[i] = currArrSize;
        
        //Print out the time and array size in this iteration
        printf("Took %f sec(s) on %ld elements\n", time_taken, currArrSize);
        
        //For just console output
//         printf("\nThe sorted array is : \n");
//         displayArray(tempArr, currArrSize);
//         printf("\n\n");
    }
}

void main(){
    
    //Use only for console output
//     long elementCounts[MAX_ITERS];
//     double timeTaken[MAX_ITERS];
//     
//     long iter_count_consol_o, initECount_consol_o;
//     printf("\nEnter the number of iterations for each algorithm : ");
//     scanf("%ld", &iter_count_consol_o);
//     printf("\nEnter the initial element count : ");
//     scanf("%ld", &initECount_consol_o);
//     
//     printf("\n\n=====Bubble Sorting=====\n");
//     tester(timeTaken, elementCounts , bubbleSort, iter_count_consol_o , initECount_consol_o);
//     
//     printf("\n\n=====Selection Sorting=====\n");
//     tester(timeTaken, elementCounts, selectionSort, iter_count_consol_o, initECount_consol_o);
//     
//     printf("\n\n=====Heap Sorting=====\n");
//     tester(timeTaken, elementCounts, heapSort, iter_count_consol_o , initECount_consol_o);
//     
//     printf("\n\n=====Bucket Sorting=====\n");
//     tester(timeTaken, elementCounts, bucketSort, iter_count_consol_o , initECount_consol_o);
    //End of console output code
    
    
    FILE  *f = NULL;
    
    long iterations , initECount;
    long elementCounts[MAX_ITERS];
    double timeTaken[MAX_ITERS];
    
    
    printf("\nEnter the number of iterations for bubble sorting : ");
    scanf("%ld", &iterations);
    printf("\nEnter the initial element count : ");
    scanf("%ld", &initECount);

    printf("\n\n=====Bubble Sorting=====\n");
    tester(timeTaken, elementCounts , bubbleSort, iterations , initECount);
    f = fopen("bubbleTimings.txt","w");
    for(long i = 0; i < iterations; i++){
        fprintf(f, "%ld\t %f\n", elementCounts[i], timeTaken[i]);
    }
    fclose(f);
    
    
    printf("\nEnter the number of iterations for selection sorting : ");
    scanf("%ld", &iterations);
    printf("\nEnter the initial element count : ");
    scanf("%ld", &initECount);
    
    printf("\n\n=====Selection Sorting=====\n");
    tester(timeTaken, elementCounts, selectionSort, iterations, initECount);
    f = fopen("selectionTimings.txt","w");
    for(long i = 0; i < iterations; i++){
        fprintf(f, "%ld\t %f\n", elementCounts[i], timeTaken[i]);
    }
    fclose(f);
    
    
    printf("\nEnter the number of iterations for heap sorting : ");
    scanf("%ld", &iterations);
    printf("\nEnter the initial element count : ");
    scanf("%ld", &initECount);
    
    printf("\n\n=====Heap Sorting=====\n");
    tester(timeTaken, elementCounts, heapSort, iterations , initECount);
    f = fopen("heapTimings.txt","w");
    for(long i = 0; i < iterations; i++){
        fprintf(f, "%ld\t %f\n", elementCounts[i], timeTaken[i]);
    }
    fclose(f);
    
    
    printf("\nEnter the number of iterations for bucket sorting : ");
    scanf("%ld", &iterations);
    printf("\nEnter the initial element count : ");
    scanf("%ld", &initECount);
    
    printf("\n\n=====Bucket Sorting=====\n");
    tester(timeTaken, elementCounts, bucketSort, iterations , initECount);
    f = fopen("bucketTimings.txt","w");
    for(long i = 0; i < iterations; i++){
        fprintf(f, "%ld\t %f\n", elementCounts[i], timeTaken[i]);
    }
    fclose(f);
}
