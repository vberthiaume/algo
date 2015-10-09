#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> v){
    for (int i : v){
        cout << i << ",";
    }
    cout << endl;
}

void mergeRecurs(vector<int> &v){
    int iCurSize = v.size();
    
    if (iCurSize <= 1){
        return;
    }

    vector<int> v1(v.begin(), v.begin() + iCurSize/2);
    vector<int> v2(v.begin()+iCurSize/2, v.end());

    mergeRecurs(v1); 
    mergeRecurs(v2);

    v.clear();
    int i = 0, j = 0;
    while (i+j < iCurSize){

        if (i < iCurSize/2 && v1[i] <= v2[j]){
            v.push_back(v1[i]);
            ++i;
        } else if (j < iCurSize/2){
            v.push_back(v2[j]);
            ++j;
        } else if (i < iCurSize/2){
            v.push_back(v1[i]);
            ++i;
        }
    }
    printVec(v);
}



// typedef std::vector<int>::iterator vec_it;
// void merge(vec_it left, vec_it left_end, vec_it right, vec_it right_end, vec_it numbers)
// {
//     while (left != left_end) {
//         if (*left < *right || right == right_end) {
//             *numbers = *left;
//             ++left;
//         } else {
//             *numbers = *right;
//             ++right;
//         }

//         ++numbers;
//     }

//     while (right != right_end) {
//         *numbers = *right;
//         ++right;
//         ++numbers;
//     }
// }

// void merge_sort(std::vector<int>& numbers)
// {
//     if (numbers.size() <= 1) {
//         return;
//     }

//     std::vector<int>::size_type middle = numbers.size() / 2;
//     std::vector<int> left(numbers.begin(), numbers.begin() + middle);
//     std::vector<int> right(numbers.begin() + middle, numbers.end());

//     merge_sort(left);
//     merge_sort(right);

//     merge(left.begin(), left.end(), right.begin(), right.end(), numbers.begin());
// }



int main(){
    //vector<int> v_in{6,5,4,3,2,8,7,1};
    
    vector<int> v_in{6,5,4,3,2,8,7,8,5,4,5,6,7,5,5,5,5};
    cout << "unsorted: ";
    printVec(v_in);


    mergeRecurs(v_in);
    //merge_sort(v_in);
     
    
    cout << "sorted: "; 
    printVec(v_in);
    
    return 0;
}
