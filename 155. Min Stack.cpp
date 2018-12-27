// ***
//
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// 
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
//
// Example:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.
//
// ***
class MinStack
{

	public:

		void push(int x)
		{
			s1.push(x);

			if (s2.empty() || x < getMin())
			{
				s2.push(x);
			}
			else
			{
				s2.push(getMin());
			}
		}
		
		void pop()
		{
			s1.pop();
			s2.pop();
		}
		
		int top()
		{
			return s1.top();
		}
		
		int getMin()
		{
			return s2.top();
		}

	private:

		stack<int> s1;
		stack<int> s2;

};
