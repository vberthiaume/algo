#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> &v){
    int iCurSize = v.size();
    if (iCurSize > 2){
        vector<int> v1 (&v[0], &v[iCurSize/2]);
        vector<int> v2 (&v[iCurSize/2 +1], &v[iCurSize]);
        mergeSort(v1); 
        mergeSort(v2); 
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    } else {
        if (v[0] > v[1]){
            int iTemp = v[1];
            v[1] = v[0];
            v[0] = iTemp;
        }
        return v;
    }
}

int main(){
    vector<int> v_in{4,5,7,3,2,8,7,1};
    auto v_out = (v_in);
    
    cout << "("; 
    for (auto i : v_out){
        cout << i << ",";
    }
    cout << ")\n";
    return 0;
}
