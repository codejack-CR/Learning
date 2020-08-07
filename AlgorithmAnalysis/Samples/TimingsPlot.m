clc;close all;clear all;

% Load the timings
B = load('bubbleTimings.txt');
S = load('selectionTimings.txt');
H = load('heapTimings.txt');
BU = load('bucketTimings.txt');

rangeBubble = B(:,1);
rangeSelection = S(:,1);
rangeHeap = H(:,1);
rangeBucket = BU(:,1);

b_timings = B(:,2);
s_timings = S(:,2);
h_timings = H(:,2);
bu_timings = BU(:,2);

plot(rangeBubble, b_timings);
hold on
plot(rangeSelection , s_timings);
plot(rangeHeap, h_timings);
plot(rangeBucket, bu_timings);
hold off

xlabel('Number of elements');
ylabel('Time (in secs)');
legend('Bubble Sort', 'Selection Sort', 'Heap Sort', 'Bucket Sort');
title('Comparision of Sorting Algorithms');
