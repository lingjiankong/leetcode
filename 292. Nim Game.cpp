// ***
//
// You are playing the following Nim Game with your friend: There is a heap of stones on the table,
// each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner.
// You will take the first turn to remove the stones.
// 
// Both of you are very clever and have optimal strategies for the game.
// Write a function to determine whether you can win the game given the number of stones in the heap.
// 
// Example:
// 
// Input: 4
// Output: false 
// Explanation: If there are 4 stones in the heap, then you will never win the game;
//              No matter 1, 2, or 3 stones you remove, the last stone will always be 
//              removed by your friend.
//
// ***
//
// 1    Win
// 2    Win
// 3    Win
// 4    Lost
// 5    Win
// 6    Win
// 7    Win
// 8    Lost
// 9    Win
// 10   Win
// 
// 由此我们可以发现规律，只要是4的倍数个，我们一定会输，所以对4取余即可
// To generalize: 当可以拿1～n个石子时，那么个数为 (n+1) 的整数倍时一定会输
//
bool canWinNim(int n)
{
	return n % 4;
}
