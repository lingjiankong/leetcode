// ***
//
// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
// 
// Example:
// 
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3
//
// ***
class MovingAverage
{

	public:

		MovingAverage(int size) :
			mWindowSize(size),
			mSum(0)
		{}
		
		double next(int val)
		{
			if (mQueue.size() >= mWindowSize)
			{
				mSum -= mQueue.front(); mQueue.pop();
			}

			mQueue.push(val);
			mSum += val;

			return mSum / mQueue.size();
		}

	private:

		queue<int> mQueue;

		int mWindowSize;

		double mSum;
};
