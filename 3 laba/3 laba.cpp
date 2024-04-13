#include<iostream>

using namespace std;

void merge(int* array, int low, int high, int mid) {
	int i, j, n, c[1000];
	i = low;
	n = low;
	j = mid + 1;
	while (i <= mid && j <= high) {
		if (array[i] > array[j]) {
			c[n] = array[i];
			n++; i++;
		}
		else {
			c[n] = array[j];
			n++; j++;
		}
	}
	while (i <= mid) {
		c[n] = array[i];
		n++; i++;
	}
	while (j <= high) {
		c[n] = array[j];
		n++; j++;
	}
	for (i = low; i < n; i++) {
		array[i] = c[i];
	}
}

void mergesort(int* array, int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergesort(array, low, mid);
		mergesort(array, mid + 1, high);
		merge(array, low, high, mid);
	}
}



int main() {
	setlocale(LC_ALL, "Ukrainian");
	int n, d, S = 0;
	cout << "Enter the number of progression elements: ";
	cin >> n;
	int* A = new int[n];
	cout << "The first term of an arithmetic progression: ";
	cin >> A[1];
	cout << "Enter the progression difference";
	cin >> d;
	cout << "Elements of progression" << endl;
	for (int i = 1; i < n + 1; i++) {
		A[i] = (2 * A[1] + d * (i - 1)) / 2;
		S += A[i];
		cout << A[i] << endl;
	}
	cout << "Progression sum:" << S << endl;
	mergesort(A, 0, n + 2);
	cout << "Sorted array: " << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << endl;
	}

	system("pause");
	return 0;
}
