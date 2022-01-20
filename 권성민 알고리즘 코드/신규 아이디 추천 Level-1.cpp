#include <string>
#include <vector>

using namespace std;

//A-> 65 ~ 90
//a -> 97 ~ 122
//48~57
string solution(string new_id) {
	string answer = "";
	//규칙 1
	for (int i = 0; i < new_id.length(); i++)
	{
		if ((new_id[i] >= 'A') && (new_id[i] <= 'Z'))
		{
			new_id[i] += 32;
		}
	}
	//규칙2
	for (int i = 0; i < new_id.length(); ) {
		if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
			|| new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
		{
			i++;
			continue;
		}

		new_id.erase(new_id.begin() + i, new_id.begin() + (i + 1));
	}
	for (int i = 0; i < new_id.length(); i++)
	{
		//규칙 3
		if (new_id[i] == '.' && new_id[i + 1] == '.')
		{
			new_id.erase(new_id.begin() + i, new_id.begin() + (i + 1));
			i--;
			continue;
		}
	}
	//규칙 4
	if (new_id[0] == '.')
	{
		new_id.erase(new_id.begin(), new_id.begin() + 1);
	}
	if (new_id[new_id.length() - 1] == '.')
	{
		new_id.erase(new_id.begin() + new_id.length() - 1, new_id.begin() + new_id.length());
	}
	//규칙 5
	if (new_id.length() == 0)
	{
		new_id += 'a';
	}
	//규칙 6
	if (new_id.length() >= 16)
	{
		new_id.erase(new_id.begin() + 15, new_id.begin() + new_id.length());
	}
	//규칙 4
	if (new_id[new_id.length() - 1] == '.')
	{
		new_id.erase(new_id.begin() + (new_id.length() - 1), new_id.begin() + new_id.length());
	}
	//규칙 7
	while (new_id.length() < 3)
	{
		new_id += (new_id[new_id.length() - 1]);
	}
	answer = new_id;
	return answer;
}