#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> data;
int p[5005];
int count[5005];

int Find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = Find(p[x]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y) {
        p[x] = y;
        count[y] += count[x];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int C, R;
    while (cin >> C >> R) {
        if (!C && !R) break;
        
        data.clear();
    	for (int i = 0; i < C; ++i) {
        	p[i] = i;
        	count[i] = 1;
    	}
        
        string A, B;
        for (int i = 0; i < C; ++i) {
            cin >> A;
            data[A] = i;
        }
        while (R--){
            cin >> A >> B;
            Union(data[A], data[B]);
        }
        int ans = 0;
    	for (int i = 0; i < C; ++i)
        	if (count[i] > ans) ans = count[i];
        cout << ans << endl;
    }
}
