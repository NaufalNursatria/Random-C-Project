#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

    int n,m;

    cout << "Masukkan jumlah baris :" << endl;
    cin >> n;

    cout << "Masukkan jumlah kolom :" << endl;
    cin >> m;

    int matrix[n][m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << "Masukkan data ke[" << i + 1 << "][" << j+1 << "]: " << endl;
            cin >> matrix[i][j];
        }
    }
    cout << "Matrix sebelum transpose" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << " " <<matrix[i][j];
        }
        cout << endl;
    }
    cout << "Matrix setelah transpose" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << " " << matrix[j][i];
        }
        cout << endl;
    }
    return 0;
}


