#include <stdio.h>
#include <limits.h>
void printMinMaxSequence(int arr[], int n) {
if (n <= 0) {
printf("List is empty.\n");
return;
}
int minVal = INT_MAX;
int maxVal = INT_MIN;
printf("Minimum and maximum value sequences for the list:\n");
for (int i = 0; i < n; i++) {
minVal = (arr[i] < minVal) ? arr[i] : minVal;
maxVal = (arr[i] > maxVal) ? arr[i] : maxVal;
printf("Min Sequence: %d, Max Sequence: %d\n", minVal, maxVal);
}
}
int main() {
int n;
printf("Enter the number of elements in the list: ");
scanf("%d", &n);
if (n <= 0) {
printf("Invalid input! Please enter a valid number of elements.\n");
return 1;
}
int arr[n];
printf("Enter the elements of the list:\n");
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
printMinMaxSequence(arr, n);
return 0;
}

