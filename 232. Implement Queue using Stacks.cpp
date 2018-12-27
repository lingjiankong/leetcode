// ***
//
// Implement the following operations of a queue using stacks.
// 
// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.
//
// ***

class MyQueue
{

	public:

		/** Initialize your data structure here. */
		MyQueue()
		{}
		
		/** Push element x to the back of queue. */
		void push(int x)
		{
			inStack.push(x);
		}
		
		/** Removes the element from in front of queue and returns that element. */
		int pop()
		{
			shiftStack();
			int toReturn = outStack.top(); outStack.pop();
			return toReturn;
		}
		
		/** Get the front element. */
		int peek()
		{
			shiftStack();
			return outStack.top();
		}
		
		/** Returns whether the queue is empty. */
		bool empty()
		{
			return inStack.empty() && outStack.empty();
		}
	
	private:

		stack<int> inStack;
		stack<int> outStack;

		void shiftStack()
		{
			if (outStack.empty())
			{
				while (!inStack.empty())
				{
					outStack.push(inStack.top()); inStack.pop();
				}
			}
		}

};
