// ***
//
// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
// 
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
// 
// Follow up:
// Could you do both operations in O(1) time complexity?
// 
// Example:
// 
// LRUCache cache = new LRUCache( 2 /* capacity */ );
// 
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4
//
// ***
//
class LRUCache
{

	public:

		LRUCache(int capacity) :
			mCapacity(capacity)
		{}
		
		int get(int key)
		{
			const auto it = mHash.find(key);

			// If key does not exist, simply return -1.
			if (it == mHash.cend())
			{
				return -1;
			}
	 
			// Move this key to the front of the LinkedList.
			mList.splice(mList.begin(), mList, it->second);

			// Return the value of the key.
			return it->second->second;
		}
		
		void put(int key, int value)
		{        

			const auto it = mHash.find(key);
			
			// Key already exist
			if (it != mHash.cend())
			{
				// Update the value
				it->second->second = value;

				// Move this entry to the front of the LinkedList.
				mList.splice(mList.begin(), mList, it->second);

				return;
			}
			
			// Reached the capacity, remove the oldest entry
			if (mList.size() == mCapacity)
			{
				const auto& node = mList.back();

				mHash.erase(node.first);
				mList.pop_back();
			}
			
			// Insert the entry to the front of the LinkedList and update mapping.
			mList.emplace_front(key, value);
			mHash[key] = mList.begin();
		}

	private:

		int mCapacity;
		list<pair<int,int>> mList;
		unordered_map<int, list<pair<int,int>>::iterator> mHash;

};
