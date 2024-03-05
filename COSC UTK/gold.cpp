// Ariel Thompson
// Lab 0:  finding gold!!
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

  int goldTotal = 0;
  string map;
  
  while (cin >> map){
    
    for (size_t i = 0; i <= map.size(); i++){
      
      char mapExtract = map[i] - '@';

      if (mapExtract > 0){
        
        goldTotal += mapExtract;

      }
    }
  }

  cout << goldTotal << endl;
    
  return 0;

}

