#include <iostream>
#include <vector>

using namespace std;

//**************************************************************************************
// DECLARATIONS OF FUNCTIONS

//function resolving the issue of aggressive cows
unsigned int AggrCows(unsigned int N, unsigned int C, vector<unsigned int> xs);

//function adding new number to vector of xs setting it to the right position so that it is already sorted
bool AddToVector(vector<unsigned int> &xs, unsigned int number);

//function that puts on screen the data user provided for one test case
void print(const vector<unsigned int> & xs, unsigned int N, unsigned int C);



//**************************************************************************************
// MAIN

int main(void)
{
    cout << "Welcome to Aggressive Cows project." << endl;
    unsigned int t {}, tmp {1000000001};
    cout << "Please put in the number of test cases you want me to test." << endl;
    while (t == 0)
    {
        cout << "t: ";
        cin >> t;
    }
    
    vector<unsigned int> N, C;
    vector<vector<unsigned int>> x;

    N.resize(t);
    C.resize(t);
    x.resize(t);

    //getting the data from user

    for (unsigned int i = 0; i < t; i++)
    {
        cout << "Test case no: " << i + 1 << endl;
        while (N[i] < 2 || N[i] > 100000)
        {
            cout << "N: ";
            cin >> N[i];
        }
        while (C[i] < 2 || C[i] > N[i])
        {
            cout << "C: ";
            cin >> C[i];
        }

        for (unsigned int j = 0; j < N[i]; j++)
        {
            do            
            {
                cout << "x" << j + 1 << ": ";
                cin >> tmp;
                
            } while (tmp > 1000000000 || !AddToVector(x[i], tmp));
            tmp = 1000000001;
        }
    }

    // printing and giving out the information needed - the smallest distance between cows - 
    // for each test case
    for (unsigned int i = 0; i < t; i++)
    {
        cout << endl;
        cout << "TEST CASE no " << i + 1 << endl;
        cout << endl;
        print(x[i], N[i], C[i]);
        tmp = AggrCows(N[i], C[i], x[i]);
        cout << "The smallest distance between cows equals: " << tmp << "." << endl << endl;
    }


    return 0;
}

//**************************************************************************************
//**************************************************************************************
//**************************************************************************************
// DEFINITIONS OF FUNCTIONS


//**************************************************************************************
//function resolving the issue of aggressive cows
unsigned int AggrCows(unsigned int N, unsigned int C, vector<unsigned int> xs)
{
    // storing the position of stall where a cow is located
    // not sure it will be needed, but it will be there for now
    vector<unsigned int> where_are_cows;
    where_are_cows.resize(C);
    where_are_cows[0] = xs[0];
    where_are_cows[C - 1] = xs[xs.size() - 1];

    // ret - variable to be returned
    // avg - average 
    unsigned int avg {(where_are_cows[C - 1] - where_are_cows[0]) / (C - 1)}, ret {avg};


    /* TO DO */
    
    return ret;
}


//**************************************************************************************
//function adding new number to vector of xs setting it to the right position so that it is already sorted
bool AddToVector(vector<unsigned int> &xs, unsigned int number)
{
    
    if (xs.size() == 0)
    {
        xs.push_back(number);
        return true;
    }
    else
    {
        if (number < xs[0])
        {
            xs.insert(xs.begin(), number);
            return true;
        }
        if (number > xs[xs.size() - 1])
        {
            xs.push_back(number);
            return true;
        }
        if (number == xs[0] || number == xs[xs.size() - 1])
        {
            return false;
        }
        
        unsigned int mini, maxi, avg;
        mini = 0;
        maxi = xs.size() - 1;
        avg = (mini + maxi) / 2;

        /* TO DO */

        while (true)
        {
            if (number == xs[mini] || number == xs[maxi] || number == xs[avg])
            {
                return false;
            }
            if (number < xs[avg])
            {
                if (avg > 0)
                {
                    if (number > xs[avg - 1])
                    {
                        xs.insert(xs.begin() + avg, number);
                        return true;
                    }
                    else
                    {
                        maxi = avg;    
                    }                   
                }
                else // avg == 0
                {
                    xs.insert(xs.begin(), number);
                    return true;
                }
                
            }
            else // (number > xs[avg])
            {
                if (avg < xs.size() - 1)
                {
                    if (number < xs[avg + 1])
                    {
                        xs.insert(xs.begin() + avg + 1, number);
                        return true;
                    }
                    else
                    {
                        mini = avg;    
                    }                   
                }
                else // avg == 0
                {
                    xs.push_back(number);
                    return true;
                }
            }

            avg = (mini + maxi) / 2;

        }

    }
    return false;
}


//**************************************************************************************
//function that puts on screen the data user provided for one test case
void print(const vector<unsigned int> & xs, unsigned int N, unsigned int C)
{
    cout << "We are about to put " << C << " cows in " << N << " stalls "
         << "which are located on one line in such a way: " << endl;
    for (auto &i : xs)
    {
        cout << i << "\t";
    }
    cout << endl;
}