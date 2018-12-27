// ***
//
// Implement the following operations of a stack using queues.
// 
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.
//
// ***
//
class MyStack
{

	public:

		/** Initialize your data structure here. */
		MyStack()
		{}
		
		/** Push element x onto stack. */
		void push(int x)
		{
			mQueue.push(x);
			moveLastElementToQueueFront();
		}
		
		/** Removes the element on top of the stack and returns that element. */
		int pop()
		{
			int toReturn = mQueue.front(); mQueue.pop();
			return toReturn;
		}
		
		/** Get the top element. */
		int top()
		{
			return mQueue.front();
		}
		
		/** Returns whether the stack is empty. */
		bool empty()
		{
			return mQueue.empty();
		}

	private:

		queue<int> mQueue;

		void moveLastElementToQueueFront()
		{
			// If you only have one element in the queue, no need to move it to the front.
			// That is why i < mQueue.size()-1 : In order to move the newest element you just pushed to the front of the queue,
			// we need to move all nums.size()-1 element originally in front of that new element to the back of the new element.
			for (int i = 0; i < mQueue.size() - 1; ++i)
			{
				mQueue.push(mQueue.front()); mQueue.pop();
			}
		}

};
