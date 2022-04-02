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

class MaxHeap
{
    int *harr;
    int heap_size;
    int capacity;

public:
    MaxHeap(int cap);
    int left(int);
    int right(int);
    int parent(int);
    int getMax();
    int extractMax();
    void insertKey(int value);
    void increaseBy(int k, int value);
    void deleteKey(int i);
    void MaxHeapify(int k);
    void linearSearch(int value);
    void printArray();
    int height();
};

// MaxHeap(int cap);
MaxHeap::MaxHeap(int size)
{
    heap_size = 0;
    capacity = size;
    harr = new int[capacity];
}

// int left(int);
int MaxHeap::left(int key)
{
    return 2 * key + 1;
}

// int right(int);
int MaxHeap::right(int key)
{
    return 2 * key + 2;
}

// int parent(int);
int MaxHeap::parent(int key)
{
    return (key - 1) / 2;
}

// int getMax();
int MaxHeap::getMax()
{
    return harr[0];
}

// int extractMax();
int MaxHeap::extractMax()
{
    if (heap_size == 0)
    {
        return INT_MAX;
    }
    if (heap_size == 1)
        return harr[--heap_size];
    int max = harr[0];
    harr[0] = harr[heap_size - 1];
    --heap_size;
    MaxHeapify(0);
    return max;
}

// void insertKey(int value);
void MaxHeap::insertKey(int value)
{
    if (heap_size == capacity)
    {
        cout << "Heap OverFlow" << endl;
        return;
    }
    ++heap_size;
    int i = heap_size - 1;
    harr[i] = value;
    while (i != 0 and harr[i] > harr[parent(i)])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// void increaseBy(int k, int value);
void MaxHeap::increaseBy(int key, int value)
{
    harr[key] = value;
    while (key != 0 and harr[key] > harr[parent(key)])
    {
        swap(harr[key], harr[parent(key)]);
        key = parent(key);
    }
}

// void deleteKey(int i);
void MaxHeap::deleteKey(int key)
{
    if (key >= heap_size || key < 1)
    {
        cout << "Wrong key to be deleted." << endl;
        return;
    }
    increaseBy(key, INT_MAX);
    int a = extractMax();
}

// void MaxHeapify(int k);
void MaxHeap::MaxHeapify(int key)
{
    int l = left(key);
    int r = right(key);
    int maximum = key;
    if (l >= 0 and harr[l] > harr[maximum])
        maximum = l;
    if (r >= 0 and harr[r] > harr[maximum])
        maximum = r;
    if (maximum != key)
    {
        swap(harr[maximum], harr[key]);
        MaxHeapify(maximum);
    }
}

// void linearSearch(int value);
void MaxHeap::linearSearch(int value)
{
    rep(i, 0, heap_size - 1)
    {
        if (harr[i] == value)
        {
            cout << "Value : " << value << " is found at index " << i + 1 << endl;
            return;
        }
    }
    cout << "Value : " << value << " is not found in Heap" << endl;
}

// void printArray();
void MaxHeap::printArray()
{
    cout << "MaxHeap Array[] : ";
    rep(i, 0, heap_size - 1)
    {
        cout << harr[i] << " ";
    }
    cout << endl;
}

// int height();
int MaxHeap::height()
{
    return ceil(log2(heap_size + 1));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s;
    cout << "Enter Size of Max Heap : " << endl;
    cin >> s;
    MaxHeap obj(s);
    cout << "Max Heap Created" << endl;

    int option, value;
    do
    {
        cout << "Select Option to perform task. Press 0 to exit" << endl;
        cout << "1. Insert Key/Node" << endl;
        cout << "2. Search Key/Node" << endl;
        cout << "3. Delete Key/Node" << endl;
        cout << "4. Get Max" << endl;
        cout << "5. Extract Max" << endl;
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
            cout << "GET Max value : " << obj.getMax();
            cout << endl;
            system("pause");
            break;
        case 5:
            cout << "EXTRACT Max value : " << obj.extractMax();
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