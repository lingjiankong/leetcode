// To encode, add size-slash in front of every word in the vector.
// For example, [i love you] -> 1/i4/love3/you
// You may repalce '/' with whatever character you want.
// You are guaranteed when decode you will get the original string back.
// Just read the code and you'll understand.
class Codec
{

	public:

		string encode(vector<string>& strs)
		{
			string toReturn = "";
			
			for (string word : strs)
			{
				toReturn += to_string(word.size()) + '/' + word;
			}

			return toReturn;
			
		}

		vector<string> decode(string s)
		{
			vector<string> toReturn;
			
			// The beginning of numbers representing string length.
			int head = 0;

			while (head < s.size())
			{
				int slashPosition = s.find_first_of('/', head);
				int stringLength = stoi(s.substr(head, slashPosition));
				toReturn.push_back(s.substr(slashPosition + 1, stringLength));
				
				// slashPoisition + 1 is where the string starts
				// slashPosition + 1 + stringLength is where the number representing
				// the size of next string starts.
				head = slashPosition + 1 + stringLength;
			}

			return toReturn;
		}

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
