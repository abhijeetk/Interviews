///*
//Binomial coefficients can be recursively calculated as follows:
//(n, k)! = (n−1, k −1)! + (n−1, k)!
//The idea is to fix an element x in the set. If x is included in the subset, we
//have to choose k −1 elements from n−1 elements, and if x is not included in the
//subset, we have to choose k elements from n−1 elements.
//The base cases for the recursion are
//(n, 0)! = 1
//(n, n)! = 1
//because there is always exactly one way
//*/
//#include <iostream>
//using namespace std;
//
//int BioCoefficient(int n, int k) {
//    cout << "(" << n << ", " << k << ")" << endl;
//    if (k == 0 || k == n)
//        return 1;
//
//    int res = BioCoefficient(n - 1, k - 1) + BioCoefficient(n - 1, k);
//    return res;
//}
//
//#include <vector>
//int BioCoefficientBottomUp(int NN, int KK) {
//
//    vector<vector<int>> res(NN, vector<int>(KK, 0));
//    for (int n = 0; n <= NN; n++) {
//        for (int k = 0; k <= KK; k++) {
//            if (k == 0 || k == NN)
//                res[n][k] = 1;
//        }
//    }
//
//    for (int n = 1; n <= NN; n++) {
//        for (int k = 1; k <= KK; k++) {
//            res[n][k] = res[n-1][k-1] + res[n-1][k];
//        }
//    }
//    return res[NN-1][KK-1];
//}
//
//int main() {
//    int n = 5;
//    int k = 2;
//    cout << BioCoefficient(n, k) << endl;
//    cout << BioCoefficientBottomUp(n, k) << endl;
//    return 0;
//}