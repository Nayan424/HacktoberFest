#include <bits/stdc++.h>
using namespace std;
int* stockSpan(int *price, int size)  {
	stack <int> s;
    int *arr=new int[size];
    arr[0]=1;
    if(size==1)
    {
        return arr;
    }
    s.push(0);
    for(int i=1;i<size;i++)
    {
        while(!s.empty() and price[i]>price[s.top()])
        {
            s.pop();
        }
		if(s.empty())
        {
            arr[i]=i+1;
        }
        else
        {
            arr[i]=i-s.top();
        }
        s.push(i);
    }
    return arr;
}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
