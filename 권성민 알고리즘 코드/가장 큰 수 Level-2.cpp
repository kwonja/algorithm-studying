#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) {
	string answer = "";
	string comp1; string comp2;
	int temp;
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		for (int j = 0; j < numbers.size() - i - 1; j++)
		{
			comp1 = to_string(numbers[j]) + to_string(numbers[j + 1]);
			comp2 = to_string(numbers[j + 1]) + to_string(numbers[j]);

			if (stoi(comp2) > stoi(comp1))
			{
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		answer += to_string(numbers[i]);
	}

	return answer;
}