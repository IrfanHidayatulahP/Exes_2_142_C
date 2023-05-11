#include <iostream>
using namespace std;

int Pan[38];
int n;
int i;

void Input() {
    while (true) {
        cout << "Enter the number of Element in the Array : ";
        cin >> n;
        if ((n > 0) && (n <= 38))
            break;
        else
            cout << "\nArray Should Have minimum 1 and maximum 38 elements.\n\n";
    }
    cout << "\n_______________________\n";
    cout << " Enter Array Elements \n";
    cout << "_________________________\n";
    for (i = 0; i < n; i++) {
        cout << "<" << (i + 1) << ">";
        cin >> Pan[i];
    }
}


void ExeSearch(int mid, int lowerbound, int upperbound) {
    int pivot, i, j;
    if (lowerbound > upperbound)
        return;

    pivot = Pan[mid];

    i = lowerbound;
    j = upperbound;
    mid = lowerbound + upperbound / 2;
    while (i <= j) {
        while ((Pan[i] <= pivot) && (i <= upperbound)) {
            i++;
        }
        while ((Pan[j] > pivot) && (j >= lowerbound)) {
            j--;
        }
        if (i <= j) {
            cout << "\nFound" << Pan[mid];
        }
        else
            cout << "\nNot Found";
    }
}
   

void display() {
    char ch;
    int ctr;
    int item;

    do {
        cout << "\nEnter Element you want to search: ";
        cin >> item;

        ctr = 0;
        for (i = 0; i < n; i++) {
            ctr++;
            if (Pan[i] == item) {
                cout << "\n" << item << "Found at Position" << (i + 1) << endl;
                break;
            }
        }

        if (i == n)
            cout << "\n" << item << "Not Found in the Array\n";
        cout << "Number of Comparison: " << ctr << endl;

        cout << "\nContinue Search (y/n): ";
        cin >> ch;
    } while ((ch == 'y') || (ch == 'n'));
}


int main()
{
    Input();
    ExeSearch(0, n-1);
    display();
}

