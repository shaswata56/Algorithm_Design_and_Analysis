#include <bits/stdc++.h>
using namespace std;

struct Thing
{
	int value, weight;
};

bool cmp(Thing a, Thing b)
{
	double unit_val_a = (double) a.value / a.weight;
	double unit_val_b = (double) b.value / b.weight;
	return unit_val_a > unit_val_b;
}

double fractionalKnapSack(int W, Thing things[], int n)
{
	sort(things, things + n, cmp);
	int current_weight = 0;
	double final_value = 0.0;
	for(int i = 0; i < n; i++)
	{
		if(current_weight + things[i].weight <= W)
		{
			current_weight += things[i].weight;
			final_value += things[i].value;
		}
		else
		{
			int remain = W - current_weight;
			final_value += things[i].value * 
				((double) remain / things[i].weight);
			break;
		}
	}
	return final_value;
}

int main()
{	
	int W, n;
	cout << "Enter the capacity of the Sack: ";
	cin >> W;
	cout << "Enter number of things: ";
	cin >> n;
	Thing arr[n];
	cout << "Enter value and weight pair-wise:" << endl;
	for(int i = 0; i < n; i++)
	{
		int w, v;
		cin >> v >> w;
		arr[i].value = v;
		arr[i].weight = w;
	}
	cout << "Maximum obtainable value: " << fractionalKnapSack(W, arr, n) << endl;
	return 0;
}
