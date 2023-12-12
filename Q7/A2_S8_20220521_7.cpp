// File: A2_S8_20220521_7.cpp
// Purpose: Solving Problem no. 7
// Author: بيجاد عبد الغفار عبد الهادي محمود
// Section: S8
// ID: 20220521
// TA: Khaled Ahmed
// Date: 26 Oct 2023

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using namespace std;
struct dominoT;//Because in the line after it I will use the name of the class, it is a way to avoid the error
void permute(vector<dominoT>& a, int l, int r);//Prototype of function
struct dominoT { //my struct
    int leftDots;
    int rightDots;
};
vector<vector<int>>res;// It will be a store in which the Permutations values are stored
vector<int>ress;// It will be a store in which resut of chain domina
bool FormsDominoChain(vector<dominoT>& dominos) {
    permute(dominos, 0, dominos.size() - 1);//call function permute
    for (auto x : res) {//check if the permutations is chain domina or no
        bool sucess = true; //check if the vector is chain domina or no
        ress = x;
        for (int i = 2;i < x.size() - 1;i += 2) {
            if (x[i] != x[i - 1]) {
                sucess = false;
                break;
            }
        }
        if (sucess == true) {
            return 1;
        }
    }
    return 0;
}
void permute(vector<dominoT>& a, int l, int r) {
    if (l == r) {
        vector<int>n;
        for (auto x : a) {    // Base case
            n.push_back(x.leftDots);
            n.push_back(x.rightDots);
        }
        res.push_back(n); //store Permutations case
    }
    else
    {
        for (int i = l; i <= r; i++)// Permutations made

        {
            swap(a[l], a[i]);// Swapping done
            permute(a, l + 1, r);// Recursion called
            swap(a[l], a[i]);//backtrack
        }
    }
}
int main()
{
    int size;
    cout << "Enter the number of Domino ==>";
    cin >> size;
    vector<dominoT>vector(size);
    cout << "Enter two number of donmino left first, then right" << endl;
    /*
     example if size =3
     2 1
     3 1
     4 1
    */
    for (auto& x : vector) {
        cin >> x.leftDots;
        cin >> x.rightDots;
    }
    if (FormsDominoChain(vector)) {//check domnia has chain or no
        cout << "True ,,it possible to build a chain consisting of every domino in the vector" << endl;
        for (int i = 0;i < ress.size();i++) { //to print answer
            if (i == ress.size() - 1) {
                cout << ress[i];//not to print _
                continue;
            }
            if (i % 2 == 1) {
                cout << ress[i] << " _ ";
            }
            else {
                cout << ress[i] << "|";
            }
        }
    }
    else {
        cout << "False,,it impossible to build a chain consisting of every domino in the vector";
    }
    return 0;
}
//Test case :
/*Test case :1
 5 ==>size
 2 6
 6 1
 1 4
 4 4
 4 3
 sucess
 */
/*
 Test case 2:
 4==>size
 2 6
 6 1
 4 4
 4 3
 */
