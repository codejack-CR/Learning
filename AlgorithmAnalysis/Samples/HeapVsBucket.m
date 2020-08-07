H = load('heapTimings.txt');
BU = load('bucketTimings.txt'); 
rangeHeap = H(:,1);
rangeBucket = BU(:,1);
h_timings = H(:,2);
bu_timings = BU(:,2);
plot(rangeHeap, h_timings);
hold on
plot(rangeBucket, bu_timings);
xlabel('Number of elements');
ylabel('Time (in secs)');
legend('Heap Sort', 'Bucket Sort');
title('Heap Sort VS Bucket Sort');
hold off
