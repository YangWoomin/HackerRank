#include "header.h"

class Available_Workshops {
private:
	Workshop *ws;
	Workshop *temp;
	int size;
public:
	Available_Workshops(int* start_time, int* duration, int size) {
		this->size = size;
		ws = new Workshop[size];
		for (int i = 0; i < size; i++) {
			ws[i].start_time = start_time[i];
			ws[i].duration = duration[i];
			ws[i].end_time = start_time[i] + duration[i];
		}
		// temp = new Workshop[size]; // for merge sorting
	}

	void merge(int left, int right) {
		if (left == right) return;
		int mid = (left + right) / 2;
		merge(left, mid);
		merge(mid + 1, right);
		int i = left, j = mid + 1, k = left;
		while (i <= mid && j <= right) {
			if (ws[i].end_time < ws[j].end_time) temp[k++] = ws[i++];
			else temp[k++] = ws[j++];
		}
		while (i <= mid) temp[k++] = ws[i++];
		while (j <= right) temp[k++] = ws[j++];
		memcpy(ws + left, temp + left, (right - left + 1) * sizeof(Workshop));
	}

	void quick(int left, int right) {
		if (left == right) return;
		Workshop pivot = ws[left];
		int low = left + 1, high = right;
		while (low <= high) {
			while (low <= high && ws[low].end_time < pivot.end_time) low++;
			while (high >= low && ws[high].end_time > pivot.end_time) high--;
			if (low <= high) {
				Workshop tempWS = ws[low];
				ws[low++] = ws[high];
				ws[high--] = tempWS;
			}
		}
		ws[left] = ws[high];
		ws[high] = pivot;
		if (low < right) quick(low, right);
		if (high > left) quick(left, high);
	}

	int calculateMaxWorkshops() {
		// merge(0, size - 1);
		quick(0, size - 1);
		int max = 1;
		int prev = ws[0].end_time;
		for (int i = 1; i < size; i++) {
			if (prev <= ws[i].start_time) {
				max++;
				prev = ws[i].end_time;
			}
		}
		return max;
	}

	~Available_Workshops() {
		delete ws, temp;
	}
};

Available_Workshops* initialize(int* start_time, int* duration, int size) {
	return new Available_Workshops(start_time, duration, size);
}

int CalculateMaxWorkshops(Available_Workshops* aw) {
	return aw->calculateMaxWorkshops();
}

void attending_workshop() {
	int n; // number of workshops
	cin >> n;
	// create arrays of unknown size n
	int* start_time = new int[n];
	int* duration = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> start_time[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;
}