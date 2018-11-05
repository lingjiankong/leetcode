// Well... this not such a good interview question. Just memorize it.
string intToRoman(int num)
{
	static const string s[4][10] =
	{ 
		// All possible representation of ones digit.
		{"","I","II","III","IV","V","VI","VII","VIII","IX"},
		// {0, 1, 2, 3, 4, 5, 6. 7, 8, 9}

		// All possible representation of tens digit.
		{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
		// {0, 10, 20, 30, 40, 50, 60. 70, 80, 90}

		// All possible representation of hundreds digit.
		{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
		// {0, 100, 200, 300, 400, 500, 600. 700, 800, 900}

		// All possible representation of thousands digit.
		{"","M","MM","MMM"}
		// {0, 1000, 2000, 3000}
	};
	
	return s[3][num/1000%10] + s[2][num/100%10] + s[1][num/10%10] + s[0][num%10];
}
