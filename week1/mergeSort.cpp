#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeRecurs(vector<int> v){
    int iCurSize = v.size();
    
    if (iCurSize <= 1){
        return v;
    }

    vector<int> v1(v.begin(), v.begin() + iCurSize/2);
    vector<int> v2(v.begin()+iCurSize/2, v.end());

    v1 = mergeRecurs(v1); 
    v2 = mergeRecurs(v2);

    vector<int> sorted;
    for (int i=0; i < iCurSize/2; ++i){
        if (v1[i] <= v2[i]){
            sorted.push_back(v1[i]);
            sorted.push_back(v2[i]);
        } else {
            sorted.push_back(v2[i]);
            sorted.push_back(v1[i]);
        }
    }
    for (int i : sorted){
        cout << i;
    }
    cout << "\n";
    return sorted;
}




int main(){
    vector<int> v_in{6,5,4,3,2,8,7,1};
    cout << "unsorted: ";
    for (int i : v_in){
        cout << i << ",";
    }
    cout << "\n";


    auto v_out = mergeRecurs(v_in);

     
    
    cout << "sorted: "; 
    for (auto i : v_out){
        cout << i << ",";
    }
    cout << ")\n";
    return 0;
}
