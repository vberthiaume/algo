#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> v){
    return v;
}

int main(){
    vector<int> v_in{4,5,7,3,2,8,7,1};
    vector<int> v_out = mergeSort(v_in);
    
    cout << "("; 
    for (auto i : v_out){
        cout << i << ",";
    }
    cout << ")\n";
    return 0;
}
