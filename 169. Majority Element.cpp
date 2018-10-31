// 1. Find the sorted nth element
int majorityElement(vector<int>& nums)
{
	// std::nth_element(RandomIt first, RandomIt nth, RandomIt last)
	// std::nth_element(): rearranges the elements in the range [first,last),
	// in such way that the element at the nth position is the element that would be
	// in that position in a sorted sequence. The other elements are left without any specific order,
	// except that none of the elements preceding nth are greater than it, and none of the elements following it are less.
	nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
	return nums[nums.size()/2];
}

// 2. Moore voting algorithm: The idea is to repeatedly get rid of pairs of different element,
// after which the element left must be the majority element.
// Note that, in the problem statement, a majority element is guaranteed to exist.
// If the majority element is not guaranteed to exist,
// we need another iteration over the nums to check whether res is actually a majority element
int majorityElement2(vector<int>& nums)
{
	// What res equal to in the beginning doesn't matter, it is arbitrary.
	// res will be initialized when the loop starts.
	int res = 0;
	int count = 0;

	// You may swap the position of if and else if in this problem if you want,
	// however you cannot do that in 229. Majority Element II, see that question for reasons.
	for (int num : nums)
	{
		if (num == res)
		{
			++count;
		}
		else if (count == 0)
		{
			// Reset res to num, all subsequent iterations compare num with current res.
			// If they are different, we get rid of a pair of (res, num) and --count,
			// else we get another res and ++count
			res = num;
			count = 1;
		}
		else
		{
			// nums != res, thus we get rid of one pair of different number (res, num)
			--count;
		}
	}

	return res;
}

// This is exactly the same as above, just make the algorithm clear so you know what's going on.
//
// 2. This can be solved by Moore's voting algorithm.
// Basic idea of the algorithm is if we cancel out each occurrence of an element e with
// all the other elements that are different from e, then e will exist till end if it is a majority element.
// Below code loops through each element and maintains a count of the element that has the potential of
// being the majority element. If next element is same then increments the count, otherwise decrements the count.
// If the count reaches 0 then update the potential index to the current element and sets count to 1.
int majorityElement3(vector<int>& nums)
{
	int majorityIndex = 0;
	int count = 1;

	for (int i = 1; i < nums.size(); ++i)
	{
		nums[majorityIndex] == nums[i] ? ++count : --count;

		if (count == 0)
		{
			majorityIndex = i;
			count = 1;
		}
	}

	return nums[majorityIndex];
}
