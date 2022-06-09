// C++ Program to find best buying and selling days 
#include <bits/stdc++.h> 
using namespace std; 

// solution structure 
class Interval { 
public: 
	int buy; 
	int sell; 
}; 

// This function finds the buy sell 
// schedule for maximum profit 
void stockBuySell(int price[], int n) 
{ 
	// Prices must be given for at least two days 
	if (n == 1) 
		return; 

	int count = 0; // count of solution pairs 

	// solution vector 
	Interval sol[n / 2 + 1]; 

	// Traverse through given price array 
	int i = 0; 
	while (i < n - 1) { 
		// Find Local Minima. Note that the limit is (n-2) as we are 
		// comparing present element to the next element. 
		while ((i < n - 1) && (price[i + 1] <= price[i])) 
			i++; 

		// If we reached the end, break 
		// as no further solution possible 
		if (i == n - 1) 
			break; 

		// Store the index of minima 
		sol[count].buy = i++; 

		// Find Local Maxima. Note that the limit is (n-1) as we are 
		// comparing to previous element 
		while ((i < n) && (price[i] >= price[i - 1])) 
			i++; 

		// Store the index of maxima 
		sol[count].sell = i - 1; 

		// Increment count of buy/sell pairs 
		count++; 
	} 

	// print solution 
	if (count == 0) 
		cout << "There is no day when buying"
			<< " the stock will make profitn"; 
	else { 
		for (int i = 0; i < count; i++) 
			cout << "Buy on day: " << sol[i].buy 
				<< "\t Sell on day: " << sol[i].sell << endl; 
	} 

	return; 
} 

// Driver code 
int main() 
{ 
	// stock prices on consecutive days 
	int price[] = { 100, 180, 260, 310, 40, 535, 695 }; 
	int n = sizeof(price) / sizeof(price[0]); 

	// fucntion call 
	stockBuySell(price, n); 

	return 0; 
} 


