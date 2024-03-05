#include <iostream>
#include <vector>
using namespace std;

typedef int Bob;
typedef vector <int> iVec;

int main (){
	vector <iVec> pascal;
	int r; // r is for total rows
	
	cout << "Enter the total number of rows to generate Pascal's triangle: ";

	if (!(cin >> r)){
		cerr << "Bad rows - need an integer."<< endl;
		return 1;
	}

	pascal.resize(r); // this changes outer vector to have size = # of total rows
	
	/* Fill in the Pascal Triangle */
	for (int i = 0; i < pascal.size(); i++){	// i will be the row number
		for (int j = 0; j <= i; j++){ // j will be the cell number, p[i][j]
			if (j == 0 || j == i) {
				pascal[i].push_back(1);
			} else {
				int pNum = pascal[i-1][j-1] + pascal[i-1][j]; // up left + up right
				pascal[i].push_back(pNum);
			}
		}
	}

	for (int i = 0; i < pascal.size(); i++){
		for (int j = 0; j < pascal[i].size(); j++){
			cout << pascal[i][j] << " ";
		}
		cout << endl;
	}
}
