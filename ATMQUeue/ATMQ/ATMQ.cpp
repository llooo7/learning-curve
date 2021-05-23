#include <iostream>
#include <vector>

std::vector<int>sortline(std::vector<int>line,int maxWithdraw)
{
	int done{};
	int count{};
	while (true)
	{
		line[count] -= maxWithdraw;
		std::vector<int>orderedLine{};
		orderedLine.resize(std::size(line));
		if (line[count] <= 0)
		{
			orderedLine[done] = count;
			done++;
		}
		else
		{
			line [count]
		}
	}
}

int main()
{
	int cases;
	std::cin >> cases;
	for (int count{};count < cases;count++)
	{
		int linesize{};
		int maxWithdraw{};
		std::vector<int>line{};
		std::cin >> linesize >> maxWithdraw;
		line.resize(linesize, maxWithdraw);
		for (int count{};count < linesize;count++)
		{
			std::cin >> line[count];
		}
	}
}