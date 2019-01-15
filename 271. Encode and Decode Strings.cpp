// ***
//
// Design an algorithm to encode a list of strings to a string.
// The encoded string is then sent over the network and is decoded back to the original list of strings.
// 
// Machine 1 (sender) has the function:
// 
// string encode(vector<string> strs) {
//   // ... your code
//   return encoded_string;
// }
// Machine 2 (receiver) has the function:
// vector<string> decode(string s) {
//   //... your code
//   return strs;
// }
// So Machine 1 does:
// 
// string encoded_string = encode(strs);
// and Machine 2 does:
// 
// vector<string> strs2 = decode(encoded_string);
// strs2 in Machine 2 should be the same as strs in Machine 1.
// 
// Implement the encode and decode methods.
// 
// Note:
// The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
// Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
// Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
//
// ***
//
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
				int stringLength = stoi(s.substr(head, slashPosition - head));
				toReturn.push_back(s.substr(slashPosition + 1, stringLength));
				
				// slashPoisition + 1 is where the string starts
				// slashPosition + 1 + stringLength is where the number which
				// representing the size of next string starts.
				head = slashPosition + 1 + stringLength;
			}

			return toReturn;
		}

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
