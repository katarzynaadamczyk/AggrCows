#include <iostream>
#include <vector>

using namespace std;

//function 
unsigned int AggrCows(unsigned int N, unsigned int C, vector<unsigned int> xs);

int main(void)
{
    cout << "Welcome to Aggressive Cows project." << endl;
    unsigned int t {};
    cout << "Please put in the number of test cases you want me to test." << endl;
    while (t == 0)
    {
        cout << "t: ";
        cin >> t;
    }
    
    vector<unsigned int> N, C;
    vector<vector<unsigned int> x;

    N.resize(t);
    C.resize(t);
    x.resize(t);

    for (unsigned int i = 0; i < t; i++)
    {
        cout << "Test case no: " << i + 1 << endl;
        while (N[i] == 0)
        {
            cout << "N: ";
            cin >> N[i];
        }
        while (C[i] == 0 || C[i] > N[i])
        {
            cout << "C: ";
            cin >> C[i];
        }
        x[i].resize(N[i]);
        for (unsigned int j = 0; j < N[i]; j++)
        {
            while (x[i][j] == 0)
            {
                cout << "x" << j + 1 << ": ";
                cin >> x[i][j];
            }
            /* tutaj wstawic funkje, ktora w odpowiednie miejsce bedzie ustawiac */
        }
    }

    return 0;
}