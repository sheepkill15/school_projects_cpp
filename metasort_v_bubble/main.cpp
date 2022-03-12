#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>

using namespace std;

ifstream test_file("adat.be");
const unsigned long long size = 1e8;
int original[size];
int arr_copy[size];
int test_arr[size];
unsigned long long n;

#define BENCHMARK(x)                                                                                         \
    {                                                                                                        \
        auto t1 = std::chrono::steady_clock::now();                                                              \
        x();                                                                                                 \
        auto t2 = std::chrono::steady_clock::now();                                                              \
                                                                                                             \
        /* Getting number of milliseconds as a double. */                                                                                 \
        std::cout << setw(30) << #x << ": " << duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.f << "s" << endl; \
    }

void Metasort_original()
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr_copy[i] > arr_copy[i + 1])
        {
            swap(arr_copy[i], arr_copy[i + 1]);
            if(i == 0) 
                i--;
            else i-= 2;
        }
    }
}

void Metasort_optimized()
{
    const size_t bound = n - 1;
    for (size_t i = 0; i < bound; i++)
    {
        const int kulonbseg = arr_copy[i] - arr_copy[i+1];
        if(kulonbseg > 0) {
            arr_copy[i] -= kulonbseg;
            arr_copy[i+1] += kulonbseg;
            i-= (2 - (i == 0));
        }
    }
}

void Bubblesort()
{
    bool ok = false;
    do
    {
        ok = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr_copy[i] > arr_copy[i + 1])
            {
                swap(arr_copy[i], arr_copy[i + 1]);
                ok = true;
            }
        }
    } while (ok);
}

void Bubblesort_optimized()
{
    bool ok = false;
    int k = 0;
    do
    {
        ok = false;
        for (int i = 0; i < n - 1 - k; i++)
        {
            if (arr_copy[i] > arr_copy[i + 1])
            {
                swap(arr_copy[i], arr_copy[i + 1]);
                ok = true;
            }
        }
        k++;
    } while (ok);
}

int partition (int low, int high)
{
    int pivot = arr_copy[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr_copy[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(arr_copy[i], arr_copy[j]);
        }
    }
    swap(arr_copy[i + 1], arr_copy[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void Simmsort() {
    unsigned long long maxi = 0;
    for(unsigned long long i = 0; i < n; i++) {
        if(arr_copy[i] > maxi) {
            maxi = arr_copy[i];
        }
    }
    maxi = maxi < n ? n : maxi;
    int *helper = new int[maxi + 1];
    cout << (sizeof(int) * (maxi + 1)) / (float)(1024 * 1024) << endl;
    for(unsigned long long i = 0; i < n; i++) {
        helper[i] = 0;
    }
    for(unsigned long long i = 0; i < n; i++) {
        helper[arr_copy[i]]++;
    }
    unsigned long long k = 0;
    for(unsigned long long i = 0; i <= maxi; i++) {
        for(unsigned long long j = 0; j < helper[i]; j++) {
            arr_copy[k++] = i;
        }
    }
    delete[] helper;
}

void copy_over()
{
    for (int i = 0; i < n; i++)
    {
        arr_copy[i] = original[i];
    }
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr_copy[i] << ' ';
    }
    cout << endl;
}

void sort_test(int tomb[], int bal, int jobb)
{
    int i = bal;
    int j = jobb;
    int kozep = tomb[(bal + jobb)/2];
    while(i <= j)
    {
        while(tomb[i]<kozep)
            i++;
        while(tomb[j]>kozep)
            j--;
        if(i<=j)
            swap(tomb[i],tomb[j]), i++, j--;
    }
    if(bal < j)
        sort_test(tomb,bal,j);
    if(i < jobb)
        sort_test(tomb,i,jobb);
}

bool check() {
    for(int i = 0; i < n; i++) {
        if(test_arr[i] != arr_copy[i]) return false;
    }
    return true;
}

int main()
{
    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;

    test_file >> n;
    for (int i = 0; i < n; i++)
    {
        test_file >> original[i];
        arr_copy[i] = original[i];
        test_arr[i] = original[i];
    }
    sort_test(test_arr, 0, n-1);
    cout << "Generated test array!" << endl;

    // cout << "Original: ";
    // print();

    BENCHMARK(Metasort_original);
    if(check()) {
        cout << "Helyes" << endl;
    }
    else {
        std::cerr << "Nem helyes" << endl;
    }
    copy_over();
    BENCHMARK(Metasort_optimized);
    if(check()) {
        cout << "Helyes" << endl;
    }
    else {
        std::cerr << "Nem helyes" << endl;
    }
    // // print();
    // copy_over();
    // BENCHMARK(Bubblesort);
    // if(check()) {
    //     cout << "Helyes" << endl;
    // }
    // else {
    //     std::cerr << "Nem helyes" << endl;
    // }
    // // print();
    // copy_over();
    // BENCHMARK(Bubblesort_optimized);
    // if(check()) {
    //     cout << "Helyes" << endl;
    // }
    // else {
    //     std::cerr << "Nem helyes" << endl;
    // }
    // print();
    // copy_over();
    // {                                                                                                        
    //     auto t1 = std::chrono::steady_clock::now();                                                              
    //     sort_test(arr_copy, 0, n - 1);                                                                                                 
    //     auto t2 = std::chrono::steady_clock::now();                                                              
                                                                                                             
    //     /* Getting number of milliseconds as a double. */                                                                             
    //     std::cout << setw(30) << "Quicksort" << ": " << duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.f << "s" << endl; 
    // }
    // if(check()) {
    //     cout << "Helyes" << endl;
    // }
    // else {
    //     std::cerr << "Nem helyes" << endl;
    // }
    // BENCHMARK(Simmsort);
    // if(check()) {
    //     cout << "Helyes" << endl;
    // }
    // else {
    //     std::cerr << "Nem helyes" << endl;
    // }
    // print();

    return 0;
}
