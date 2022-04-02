#include <bits/stdc++.h>
#define int long long
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long>
#define vvl vector<vl>
#define vll vector<ll>
#define vvll vector<vll>
#define vb vector<bool>
#define pb push_back
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp make_pair
#define rep(a, b, c) for (long long a = b; a <= c; ++a)
#define repr(a, b, c) for (long long a = b; a >= c; --a)
#define input(a, b, n)                 \
    for (long long i = b; i <= n; ++i) \
        cin >> a[i];
#define output(a, b, n)                \
    for (long long i = b; i <= n; ++i) \
        cout << a[i] << " ";
#define Mod 1000000007
using namespace std;
class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

public:
    MinHeap(int cap);
    int parent(int i);
    int left(int i);
    int right(int i);
    int getMin();
    int extractMin();
    void insertKey(int k);
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void MinHeapify(int i);
    void linearSearch(int val);
    void printArray();
    int height();
};

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

int MinHeap::parent(int i)
{
    return (i - 1) / 2;
}

int MinHeap::left(int i)
{
    return (2 * i + 1);
}

int MinHeap::right(int i)
{
    return (2 * i + 2);
}

int MinHeap::getMin()
{
    return harr[0];
}

int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        --heap_size;
        return harr[heap_size];
    }
    int min = harr[0];
    harr[0] = harr[heap_size - 1];
    --heap_size;
    MinHeapify(0); // O(Log n)
    return min;
}

void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "Overflow : Heap Full" << endl;
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    while (i != 0 and harr[parent(i)] > harr[i])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int val)
{
    harr[i] = val;
    while (i != 0 and harr[i] < harr[parent(i)])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    int a = extractMin();
}
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i; // Parent
    if (l < heap_size and harr[l] < harr[smallest])
        smallest = l;
    if (r < heap_size and harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest); // New Parent
    }
}

void MinHeap::linearSearch(int val)
{
    rep(i, 0, heap_size - 1)
    {
        if (harr[i] == val)
        {
            cout << "Value " << val << " found at index  : " << i << endl;
            return;
        }
    }
    cout << "Value " << val << " not found" << endl;
}

void MinHeap::printArray()
{
    rep(i, 0, heap_size - 1)
    {
        cout << harr[i] << " ";
    }
    cout << endl;
}

int MinHeap::height()
{
    return ceil(log2(heap_size + 1)) - 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s;
    cout << "Enter Size of Min Heap : " << endl;
    cin >> s;
    MinHeap obj(s);
    cout << "Min Heap Created" << endl;

    int option, value;
    do
    {
        cout << "Select Option to perform task. Press 0 to exit" << endl;
        cout << "1. Insert Key/Node" << endl;
        cout << "2. Search Key/Node" << endl;
        cout << "3. Delete Key/Node" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. Extract Min" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print/Traversal Heap values" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cout << "Enter Choice : " << endl;
        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Insert Operation" << endl;
            {
                cout << "Enter number of input to insert in HEAP :" << endl;
                int size = 0;
                cin >> size;
                cout << "Enter VALUE  to INSER in HEAP : " << endl;
                rep(i, 1, size)
                {
                    cin >> value;
                    obj.insertKey(value);
                }
                system("pause");
            }

            cout << endl;
            break;
        case 2:
            cout << "SEARCH Operation -" << endl;
            cout << "Enter VALUE to SEARCH in HEAP: ";
            cin >> value;
            obj.linearSearch(value);
            system("pause");
            break;
        case 3:
            cout << "DELETE Operation -" << endl;
            cout << "Enter INDEX of Heap Array to DELETE: ";
            cin >> value;
            obj.deleteKey(value);
            system("pause");
            break;
        case 4:
            cout << "GET Min value : " << obj.getMin();
            cout << endl;
            system("pause");
            break;
        case 5:
            cout << "EXTRACT Min value : " << obj.extractMin();
            cout << endl;
            system("pause");
            break;
        case 6:
            cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
            system("pause");
            break;

        case 7:
            cout << "PRINT Heap Array : " << endl;
            obj.printArray();
            cout << endl;
            system("pause");
            break;

        case 8:
            system("cls");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);
    return 0;
}