#include <iostream>
#include <cstring>
using namespace std;
void kmp(string str, int arr[])
{
    int m = str.length(), k;
    arr[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = arr[i - 1];
        while (k >= 0)
        {
            if (str[k] == str[i - 1])
                break;
            else
                k = arr[k];
        }
        arr[i] = k + 1;
    }
}
bool strcheck(string str, string dest)
{
    int m = str.length();
    int n = dest.length();
    int f[m];     
    kmp(str, f);     
    int i = 0;
    int k = 0;        
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (dest[i] == str[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = f[k];
    }
    return 0;
}
 
int main()
{
    string tar = "tommy and rocky are playing in the ground";
    string pat = "play";
    if (strcheck(pat, tar))
        cout<<"'"<<pat<<"' found in the str '"<<tar<<"'\n";
    else
        cout<<"'"<<pat<<"' not found in the str '"<<tar<<"'\n";
    pat = "rocking";
    if (strcheck(pat, tar))
        cout<<"'"<<pat<<"' found in the str '"<<tar<<"'\n";
    else
        cout<<"'"<<pat<<"' not found in the str '"<<tar<<"'\n";
    return 0;
}