#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int> &v){
    int iCurSize = v.size();
    if (iCurSize > 2){
        vector<int> v1 (&v[0], &v[iCurSize/2]);
        vector<int> v2 (&v[iCurSize/2 +1], &v[iCurSize]);
        mergeSort(v1); 
        mergeSort(v2); 
    } else {
        if (v[0] > v[1]){
            int iTemp = v[1];
            v[1] = v[0];
            v[0] = iTemp;
        }
    }
}

int main(){
    vector<int> v{4,5,7,3,2,8,7,1};
    mergeSort(v);
    
    cout << "("; 
    for (auto i : v){
        cout << i << ",";
    }
    cout << ")\n";
    return 0;
}
