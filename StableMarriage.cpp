/*
***********************************************************************************
Yonghao Lin
CSCI 211
Stable Marriage
January 17, 2023
***********************************************************************************
*/


#include <iostream>
using namespace std;

bool ok(int q[], int c){
    //c refers to the new man
    //q[c] refers to the new woman
    //i refers to the current man
    //q[i] refers to the current woman
    //The lower the value, the more interested the man/woman is in the other
    int menPreference[3][3] = {               //Men's Preference
        {0, 2, 1}, {0, 2, 1}, {1, 2, 0}
    };
    int womenPreference[3][3] = {             //Women's Preference
        {2, 1, 0}, {0, 1, 2}, {2, 0 ,1}
    };
    /*Test Conditions
    1. If the new woman has already been assigned to a man
    2. Does the current man prefer the new woman to his partner ([i][q[c]] < [i][q[i]]) and does the new woman prefer the current man to her partner ([q[c]][i] < q[c][c])
    3. Does the new man prefer the current woman to his partner ([c][q[i]] < [c][q[c]]) and does the current woman prefer the new man to her partner (q[i][c] < q[i][i])
    If any of the conditions are met then the tests return false. Otherwise, true is returned
    */
    for(int i = 0; i < c; i++)  
    {
        if(q[i] == q[c] || (menPreference[i][q[c]] < menPreference[i][q[i]] && womenPreference[q[c]][i] < womenPreference[q[c]][c]) || (menPreference[c][q[i]] < menPreference[c][q[c]] && womenPreference[q[i]][c] < womenPreference[q[i]][i]))
        {
            return false;
        }
    }
    return true;
}

void print(int q[], int solNum){
    cout << "Solution " << solNum << endl;
    for(int i = 0; i < 3; i++)
    { 
        cout << "Man " << i << " with woman: " << q[i] << endl;
    }
    cout << endl;
}

int main() {
    int q[3], c = 0, counter = 0;
    while(c != -1) //When c is equal to -1, it means that the program has gone through all computations
    {
        c++;
        if(c == 3) //When c is equal to 3, a solution has been found and will be printed
        {
            counter++;
            print(q, counter);
            c--; //Backtracks 
        }
        else 
        {
            q[c] = -1; 
        }
        while(q[c] < 3) //Searches through each woman
        {
            q[c]++;
            if(q[c] == 3) //Has searched through each woman and will proceed to backtrack
            {
                c--;
                if(c == -1) //No more solutions
                {
                    return 0;
                }
            }
            else if(ok(q, c)) 
            {
                break;
            }
        }
    }
    return 0;
}