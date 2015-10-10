#include <iostream>
#include <vector>
using namespace std;

//------ NOT MINE----
typedef std::vector<int>::iterator vec_it;
void not_my_merge(vec_it left, vec_it left_end, vec_it right, vec_it right_end, vec_it numbers);
void not_my_merge_sort(std::vector<int>& numbers);
//---- ENDOF NOT MINE

void printVec(vector<int> v){
    for (int i : v){
        cout << i << ",";
    }
    cout << endl;
}

void mergeSort(vector<int> &v){
    int iCurSize = v.size();
    
    if (iCurSize <= 1){
        return;
    }

    vector<int> v1(v.begin(), v.begin() + iCurSize/2);
    vector<int> v2(v.begin()+iCurSize/2, v.end());

    mergeSort(v1); 
    mergeSort(v2);

    v.clear();
    int i = 0, j = 0;
    while (i+j < iCurSize){

        if (i < v1.size() && v1[i] <= v2[j]){
            v.push_back(v1[i]);
            ++i;
        } else if (j < v2.size()){
            v.push_back(v2[j]);
            ++j;
        } else if (i < v1.size()){
            v.push_back(v1[i]);
            ++i;
        }
    }
    //printVec(v);
}

int main(){
    vector<int> v_in{6,5,4,3,2,8,7,8,5,4,5,6,7,5,5,5,5,3};
    cout << "unsorted: ";
    printVec(v_in);

    mergeSort(v_in);
    //not_my_merge_sort(v_in);
     
    cout << "sorted: "; 
    printVec(v_in);
    return 0;
}

//------------------------------------ NOT MY CODE -----------------------
// void not_my_merge(vec_it left, vec_it left_end, vec_it right, vec_it right_end, vec_it numbers){
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
// void not_my_merge_sort(std::vector<int>& numbers){
//     if (numbers.size() <= 1) {
//         return;
//     }
//     std::vector<int>::size_type middle = numbers.size() / 2;
//     std::vector<int> left(numbers.begin(), numbers.begin() + middle);
//     std::vector<int> right(numbers.begin() + middle, numbers.end());
//     not_my_merge_sort(left);
//     not_my_merge_sort(right);
//     not_my_merge(left.begin(), left.end(), right.begin(), right.end(), numbers.begin());
// }