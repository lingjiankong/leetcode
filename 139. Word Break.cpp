// THIS IS INCOMPLETE. THIS SOLUTION HAS BUG. TODO
class Solution
{

	public:

		bool wordBreak(const string& s, vector<string>& wordDict)
		{
			for (string word : wordDict)
			{
				mCache.insert({word, true});
			}

			return wordBreak(s);
		}

	private:
		
		unordered_map<string, bool> mCache;

		bool wordBreak(const string& s)
		{
			if (mCache[s])
			{
				return mCache[s];
			}

			for (int i = 0; i < s.size(); ++i)
			{
				string leftSubstr = s.substr(0, i);
				string rightSubstr = s.substr(i);
				
				if (wordBreak(leftSubstr) && mCache.count(rightSubstr))
				{
					return mCache[s] = true;
				}
			}

			return mCache[s] = false;
		}

};
