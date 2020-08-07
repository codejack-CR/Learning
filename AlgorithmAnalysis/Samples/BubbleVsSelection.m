B = load('bubbleTimings.txt');
S = load('selectionTimings.txt');
rangeBubble = B(:,1);
rangeSelection = S(:,1);
b_timings = B(:,2);
s_timings = S(:,2);
plot(rangeBubble, b_timings);
hold on
plot(rangeSelection , s_timings);
xlabel('Number of elements');
ylabel('Time (in secs)');
legend('Bubble Sort', 'Selection Sort');
title('Bubble Sort VS Selection Sort');
hold off
