# Algorithm Analysis in C
_For Bubble, Selection, Heap and Bucket Sort_
## What is this?
This is a console application written in C to analyze the time complexities of Bubble, Selection, Heap and Bucket sorting algorithms.
It makes use of the `time.h` header file in C to calculate the time taken (in seconds) by each iteration of the algorithm using `clock()`.

### Dependencies
For running this C console application, you need a C compiler. Headers used are `stdio.h`, `stdlib.h` and `time.h`.

For Windows : [MinGW](https://osdn.net/projects/mingw/releases/)

For Linux : _No need, every distro of Linux has GCC, make sure to update your system_

#### Optional Dependency - 
[Octave](https://www.gnu.org/software/octave/)  _OR_  [MATLAB](https://www.mathworks.com/products/matlab.html)

### Inputs
Prompts the user to enter the number of iterations for each algorithm and starting element count before testing any algorithm. The number of elements on which
sorting is done can be calculated as `<Initial_Element_Count> * <Iteration_Number>`. The array elements are in range `1 - <Size_Of_Array>`and are randomly shuffled before sorting.

_*I advise against the use of higher iterations for slow algorithms like Bubble and Selection Sort_

### Outputs
Ouputs the time taken for each iteration in the console. For further analysis, the output is saved in a text file in the same directory as the C file.
Number of lines in the generated text file is equal to the iterations for which the algorithm is run.
Each line of the file contains the number of elements and time took to sort those number of elements using that algorithm separated by tab space.

*1000&nbsp;&nbsp;&nbsp;&nbsp;0.007615*

![Output showing the files generated](https://github.com/codejack-CR/Learning/blob/master/AlgorithmAnalysis/Samples/Screenshot_20200807_145624.jpeg)

_This format allows for easy plotting of the number of elements to the time taken to sort using **Octave/MATLAB** or **GNUPlot**._

_**Sample text files containing times and Octave scripts for plotting them are also included**_.

### Samples
#### Time Data (Sample Text Files)- 
1. [Bubble Sort Time Data](https://raw.githubusercontent.com/codejack-CR/Learning/master/AlgorithmAnalysis/Samples/bubbleTimings.txt)
2. [Selection Sort Time Data](https://raw.githubusercontent.com/codejack-CR/Learning/master/AlgorithmAnalysis/Samples/selectionTimings.txt)
3. [Heap Sort Time Data](https://raw.githubusercontent.com/codejack-CR/Learning/master/AlgorithmAnalysis/Samples/heapTimings.txt)
4. [Bucket Sort Time Data](https://raw.githubusercontent.com/codejack-CR/Learning/master/AlgorithmAnalysis/Samples/bucketTimings.txt)

#### Octave/MATLAB Scripts -
**Important :** You need to have the text files containing the sorting times in the same folder as the script. Either download the samples above or run the application to generate these files.
1. [Comparing all sorting algos](https://raw.githubusercontent.com/codejack-CR/Learning/master/AlgorithmAnalysis/Samples/TimingsPlot.m)
2. [Comparing Bubble sort and Selection sort](https://raw.githubusercontent.com/codejack-CR/Learning/master/AlgorithmAnalysis/Samples/BubbleVsSelection.m)
3. [Comparing Heap sort and Bucket+Quick sort](https://raw.githubusercontent.com/codejack-CR/Learning/master/AlgorithmAnalysis/Samples/HeapVsBucket.m)

#### Sample Plots - 
![Plot of all sorting algos](https://github.com/codejack-CR/Learning/blob/master/AlgorithmAnalysis/Samples/Screenshot_20200807_143555.jpeg)
![Plot of Bubble sort vs Selection sort](https://github.com/codejack-CR/Learning/blob/master/AlgorithmAnalysis/Samples/Screenshot_20200807_144042.jpeg)
![Plot of Heap sort vs Bucket+Quick sort](https://github.com/codejack-CR/Learning/blob/master/AlgorithmAnalysis/Samples/Screenshot_20200807_184047.jpeg)

### Additional Information
The sorting algorithm used to sort the buckets in Bucket sorting is the built-in `quicksort()` in `stdlib.h` header in C. This makes our bucket sorting algorithm faster than all other algorithms. You are requested to implement some other sorting algorithm or use existing sorting algorithms as per need.

_Have suggessions? I would love to hear them!_ :)
