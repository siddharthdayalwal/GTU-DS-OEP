void findMaxSum(int M[][COL]) 
{ 
	// Variables to store the final output 
	int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom; 

	int left, right, i; 
	int temp[ROW], sum, start, finish; 

	// Set the left column 
	for (left = 0; left < COL; ++left) 
	{ 
		// Initialize all elements of temp as 0 
		memset(temp, 0, sizeof(temp)); 

		// Set the right column for the left column set by outer loop 
		for (right = left; right < COL; ++right) 
		{ 
		// Calculate sum between current left and right for every row 'i' 
			for (i = 0; i < ROW; ++i) 
				temp[i] += M[i][right]; 

			// Find the maximum sum subarray in temp[]. The kadane() 
			// function also sets values of start and finish. So 'sum' is 
			// sum of rectangle between (start, left) and (finish, right) 
			// which is the maximum sum with boundary columns strictly as 
			// left and right. 
			sum = kadane(temp, &start, &finish, ROW); 

			// Compare sum with maximum sum so far. If sum is more, then 
			// update maxSum and other output values 
			if (sum > maxSum) 
			{ 
				maxSum = sum; 
				finalLeft = left; 
				finalRight = right; 
				finalTop = start; 
				finalBottom = finish; 
			} 
		} 
	} 

	// Print final values 
	printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft); 
	printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight); 
	printf("Max sum is: %d\n", maxSum); 
} 

// this is the code for find max sum
