int kadane(int* arr, int* start, int* finish, int n) 
{ 
	// initialize sum, maxSum and 
	int sum = 0, maxSum = INT_MIN, i; 

	// Just some initial value to check for all negative values case 
	*finish = -1; 

	// local variable 
	int local_start = 0; 

	for (i = 0; i < n; ++i) 
	{ 
		sum += arr[i]; 
		if (sum < 0) 
		{ 
			sum = 0; 
			local_start = i+1; 
		} 
		else if (sum > maxSum) 
		{ 
			maxSum = sum; 
			*start = local_start; 
			*finish = i; 
		} 
	} 

	// There is at-least one non-negative number 
	if (*finish != -1) 
		return maxSum; 

	// Special Case: When all numbers in arr[] are negative 
	maxSum = arr[0]; 
	*start = *finish = 0; 

	// Find the maximum element in array 
	for (i = 1; i < n; i++) 
	{ 
		if (arr[i] > maxSum) 
		{ 
			maxSum = arr[i]; 
			*start = *finish = i; 
		} 
	} 
	return maxSum; 
} 
