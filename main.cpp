#include "includeSTL.hpp"
#include "Polynomial/includeME.hpp"
#include "Geometry/includeME.hpp"

int main()
{
	Term t(2.9, Monomial(vector<int>{1, 2, 3}));
	cout << t << endl;

	return 0;
}