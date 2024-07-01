#include <iostream>
using namespace std;

void row_wise_sum(int** arr, int n, int m) {//n for row and m for column
	
	int max=0;
	int maxRowIndex = 0;
    for (int i = 0; i < n; i++) {
    	int sum=0;
        for (int j = 0; j < m; j++) {
           		sum+=arr[i][j];
            }
            if(max<=sum){
           			max=sum;
           			maxRowIndex = i+1;
				   }
           cout<<"the sum for "<<i+1<<"th "<< "row is "<<sum<<endl; 
        }
        cout<<"The largest row element sum is "<<max<<" at row number"<<maxRowIndex;
    }


/*void col_wise_sum(int** arr, int n, int m) {
    for (int j = 0; j < m; j++) { // Iterate over columns
        int sum = 0;
        for (int i = 0; i < n; i++) { // Iterate over rows
            sum += arr[i][j];
        }
        cout << "The sum for " << j+1 << "th column is " << sum << endl;
    }
}
*/


int main() {
    int n, m;
    cout << "Enter length of row and column:" << endl;
    cin >> n >> m;

    // Allocate dynamic 2D array
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "The array is:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    row_wise_sum(arr, n, m);
    //col_wise_sum(arr, n, m);
    return 0;
}

