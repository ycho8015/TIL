#include <stdio.h>

const int MAX = 1000;
int main() {
	int n;
	scanf("%d", &n);

	int data[MAX];
	int sum[MAX];
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
		if (i == 0)
			sum[i] = data[i];
		else
			sum[i] = sum[i - 1] + data[i];
	}

	int maxSum = -9999999;
	for (int start = 0; start < n; start++) {
		for (int end = start; end < n; end++) {
			int currentSum = 0;
			if (start == 0)
				currentSum = sum[end];
			else
				currentSum += sum[end] - sum[start - 1];

			if (currentSum > maxSum)
				maxSum = currentSum;
		}
	}

	printf("%d", maxSum);
	return 0;
}
