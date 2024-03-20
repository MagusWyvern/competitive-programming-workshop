#include <iostream>   

using namespace std;   
const long maxn = 20000 + 10; //size of the heap long n, len;                  
//n: the number of planks, len: the length of the heap long long p[maxn];           
//heap void heap_insert(long long k)
{                                                                          
    // insert k into the min heap, maintain the heap property
    long t = ++len;
    p[t] = k;
    while (t > 1)
        if (p[t / 2] > p[t])
        {
            swap(p[t], p[t / 2]);
            t /= 2;
        }
        else
            break;
}
void heap_pop(void) // Delete the root of the min heap, maintain the heap property
{
    long t = 1;
    p[t] = p[len--];
    while (t * 2 <= len)
    {
        long k = t * 2;
        if (k < len && p[k] > p[k + 1])
            ++k;
        if (p[t] > p[k])
        {
            swap(p[t], p[k]);
            t = k;
        }
        else
            break;
    }
}
int main(void)
{
    cin >> n;
    for (long i = 1; i <= n; i++) // lengths of n planks
        cin >> p[i];
    len = 0;
    for (long i = 1; i <= n; i++) // a min heap is constructed with n planks
        heap_insert(p[i]);
    long long ans = 0;
    while (len > 1)
    { // construct a Huffman tree
        long long a, b;
        a = p[1]; // delete the root of heap (weight a), maintain the heap property
        heap_pop();
        b = p[1]; // delete the root of heap (weight b), maintain the heap property
        heap_pop();
        ans += a + b; // the cost ans increases (a+b)   	 	heap_insert(a + b);      // A new node (a+b) is inserted into the min heap
    }
    cout << ans << endl; // Output the minimal cost
}
