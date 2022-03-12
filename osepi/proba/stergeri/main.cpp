#include <iostream>
#include <fstream>
#define cin fin
#define cout fout

using namespace std;

ifstream fin("stergeri.in");
ofstream fout("stergeri.out");

struct Data
{
    int sum;
    int index;
};

Data nums[100000];

int n;
int inserted;

struct
{
    int steps = 0;
    int max = 0;
    bool deleted[100000];
} solution;

void insert(int index, int sum, int dataindex) {
    inserted++;
    for(int i = inserted; i > index; i--) {
        nums[i] = nums[i-1];
    }
    nums[index] = {sum, dataindex};
}

void insert_binary(int sum, int index)
{
    int e = 0, j = inserted;
    while (e <= j)
    {
        int m = (e + j) / 2;
        if (sum <= nums[m].sum)
        {
            e = m + 1;
        }
        else
        {
            j = m - 1;
        }
    }
    insert(e, sum, index);
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++) {
        solution.deleted[i] = false;
    }

    int temp;
    cin >> temp;
    int sum = 0;
    while (temp)
    {
        sum += temp % 10;
        temp /= 10;
    }
    nums[0] = {sum, 0};
    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        int sum = 0;
        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }
        insert_binary(sum, i);
    }

    // for(int i = 0; i < n; i++) {
    //     cout << nums[i].sum << ' ';
    // }
    // cout << endl;
    
    int curr = 0;
    while(curr < n) {
        if(solution.deleted[nums[curr].index]){
            curr++;
            continue;
        }
        if(nums[curr].sum == nums[curr+1].sum) {
            int kisebb, nagyobb;
            if(nums[curr].index < nums[curr+1].index) {
                kisebb = nums[curr].index;
                nagyobb = nums[curr+1].index;
            }
            else {
                kisebb = nums[curr+1].index;
                nagyobb = nums[curr].index;
            }
            for(int i = kisebb; i <= nagyobb; i++) {
                solution.deleted[i] = true;
            }
            if(solution.max < nagyobb - kisebb + 1) {
                solution.max = nagyobb - kisebb + 1;
            }
            curr += 2;
        }
        else {
            solution.deleted[nums[curr].index] = true;
            if(solution.max < 1) {
                solution.max = 1;
            }
            curr++;
        }
        solution.steps++;
    }
    cout << solution.steps << ' ' << solution.max << endl;
    return 0;
}
