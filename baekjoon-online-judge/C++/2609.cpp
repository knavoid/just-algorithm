#include <iostream>
using namespace std;

int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main()
{
	int x, y;
	cin >> x >> y;

	if (y > x) swap(x, y);

	int g = gcd(x, y);

	cout << g << endl;
	cout << g * (x / g) * (y / g);

	return 0;
}