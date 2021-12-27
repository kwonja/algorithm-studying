#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
	int answer = 0; int n = 2;
	vector<int>tree; tree.push_back(0); tree.push_back(0);
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = n; j < (n * 2); j++)
		{
			if (j % 2 == 0)tree.push_back(tree[j / 2] - numbers[i]);
			else tree.push_back(tree[j / 2] + numbers[i]);
		}
		n = n * 2;
	}
	n = n / 2;
	for (int i = n; i < (n * 2); i++)if (tree[i] == target)answer++;
	return answer;
}