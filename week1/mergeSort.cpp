#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeRecurs(vector<int> &v){
    int iCurSize = v.size();
    if (iCurSize > 2){
        vector<int> v1(v.begin(), v.begin() + iCurSize/2);
        vector<int> v2(v.begin()+iCurSize/2, v.end());
        mergeRecurs(v1); 
        mergeRecurs(v2); 
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    } else {
        if (v[0] > v[1]){
            int iTemp = v[1];
            v[1] = v[0];
            v[0] = iTemp;
        }
        cout << v[0] << v[1] << "\n";
        return v;
    }
}
vector<int> mergeSort(vector<int> &v){
    int iCurSize = v.size();
    vector<int> v1(v.begin(), v.begin() + iCurSize/2);
    vector<int> v2(v.begin()+iCurSize/2, v.end());
    mergeRecurs(v1); 
    mergeRecurs(v2);
    cout << "v1: ";
    for (int i : v1){
        cout << i;
    }
    cout << "\nv2: ";
    for (int i : v2){
        cout << i;
    }
    cout << "\n";
    vector<int> fullySorted;
    for (int i = 0; i < iCurSize; i+=2){
        if (v1[i] <= v2[i]){
            fullySorted.push_back(v1[i]);
            fullySorted.push_back(v2[i]);
        } else {
            fullySorted.push_back(v2[i]);
            fullySorted.push_back(v1[i]);
        }
    }
    return fullySorted;
}

int main(){
    vector<int> v_in{6,5,4,3,2,8,7,1};
    cout << "unsorted: ";
    for (int i : v_in){
        cout << i << ",";
    }
    cout << "\n";


    auto v_out = mergeSort(v_in);
     
    
    cout << "sorted: "; 
    for (auto i : v_out){
        cout << i << ",";
    }
    cout << ")\n";
    return 0;
}
