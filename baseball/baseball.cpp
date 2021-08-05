#include <iostream>
#include <random>
int main()
{
	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(1, 9);

	bool check[9] = { false, };

	int number3[3] = { 0, };

	int answer3[3] = { 0, };

	int strike = 0;
	int ball = 0;
	for (int i = 0; i < 3; i++)
	{
		int number = dis(gen);
		while (check[number] == true)
		{
			number = dis(gen);
		}

		check[number] = true;
		number3[i] = number;
		std::cin >> answer3[i];

		if (number3[i] == answer3[i])
		{
			strike++;
		}

		if (answer3[i] > 9 || answer3[i] < 1)
		{
			std::cout << "0이하이거나 10이상입니다. 프로그램을 종료합니다." << std::endl;
			return 0;
		}
	}
	if (strike < 3)
	{
		if (number3[0] == answer3[1])
		{
			ball++;
		}
		if (number3[0] == answer3[2])
		{
			ball++;
		}
		if(number3[1] == answer3[2])
		{
			ball ++;
		}
		
	}

	std::cout << "스트라이크: "; std::cout << strike << std::endl;

	std::cout << "볼: "; std::cout << ball << std::endl;

	return 0;
}