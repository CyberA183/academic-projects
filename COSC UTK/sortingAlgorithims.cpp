#include <iostream>
#include <vector>
using namespace std;

void swap(int i1, int i2, vector <int> &vec){
	
	int temp = vec[i1];
	vec [i1] = vec[i2];
	vec[i2] = temp;

}

void printVector( vector <int> &vec){

	for (int i = 0; i < vec.size(); i++){
		
		cout << " " << vec.at(i);
	}

	cout << "\n";
}

void bubbleSort(vector <int> &vec){
	
	int i, j, k;
	int N = vec.size();

	for (j = 1; j < N; j++){

		for (i = 0; i < N - 1; i++){

			if (vec[i] > vec[i+1]){

				swap(i, i+1, vec);
			}
		}
	}
}

void selectionSort(vector <int> &vec){
	
	int min;
	int n = vec.size();

	for (int i = 0; i < n-1; i++){
		
		min = i;

		for (int j = i+1; j < n; j++){
			
			if (vec[j] < vec[min]){
				
				min = j;
			}
		}

		if (min != i){
			
			swap(min, i, vec);
	}
	}
}

void insertionSort(vector <int> &vec){
	
	int insertionPosition, valueToInsert;

	for (int i = 1; i < vec.size(); i++){
		
		valueToInsert = vec[i];
		insertionPosition = i;

		while (insertionPosition > 0 && vec[insertionPosition-1] > valueToInsert){
			
			vec[insertionPosition] = vec[insertionPosition-1];
			insertionPosition = insertionPosition-1;
		}

		vec[insertionPosition] = valueToInsert;
	}
}

int main(){

	vector <int> data = {4, 1, 5, 6, 3, 2};
	selectionSort(data);
	printVector(data);
	return 0;
}
