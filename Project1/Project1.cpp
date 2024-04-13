#include<iostream>
#include<vector>
#include<string>
#include<fstream>

struct Item
{
	unsigned int _id;
	std::string _name;
	unsigned int _qtty;
	unsigned int _price;
};

int index;
int main()
{
	std::vector<Item> Items;
	std::cout << "Welcome! What do you want to do? \n(0)-Exit\n(1)-New Item\n(2)-Get Info about Item\n(3)-View All Items\n(4)-Save Items to file\n(5)-Load Items from file\n(6)-Delete an Item\n";
	while (1) {
		std::cin >> index;
		if (index == 0)
			break;
		else if (index == 1)
		{
			unsigned int a, c, d;
			std::string b;
			std::cout << "Enter Item id: "; std::cin >> a;
			std::cout << "Enter Item name: "; std::getline(std::cin >> std::ws, b);
			std::cout << "Enter Item quantity: "; std::cin >> c;
			std::cout << "Enter Item price: "; std::cin >> d;
			Item i = { a,b,c,d };
			Items.push_back(i);
		}
		else if (index == 2)
		{
			int i;
			std::cout << "Enter Index of Item: "; std::cin >> i;
			if (i > Items.size() || i <= 0)
			{
				std::cout << "Invalid Index!\n";
			}
			else {
				Item it = Items[i-1];
				std::cout << it._id << ' ' << it._name << ' ' << it._price << ' ' << it._qtty << '\n';
			}
		}
		else if (index == 3)
		{
			for (const Item i: Items)
			{
				std::cout << i._id << ' ' << i._name << ' ' << i._price << ' ' << i._qtty << '\n';
			}
		}
		else if (index == 4)
		{
			std::ofstream ofile;
			ofile.open("user_items.txt");
			for (const Item i : Items)
			{
				ofile << i._id << ' ' << i._name << ' ' << i._price << ' ' << i._qtty << '\n';
			}
			ofile.close();
		}
		else if (index == 5)
		{
			std::string itext;
			std::ifstream ifile("user_items.txt", std::ios_base::in);
			if (!ifile.is_open())
				std::cout << "Failed to open file!!\n";
			else {
				while (std::getline(ifile,itext))
				{
					std::cout << itext << '\n';
				}
			}
			ifile.close();
		}
		else if (index == 6)
		{
			int i;
			std::cout << "Enter index of item to delete: "; std::cin >> i;
			if (i > Items.size() || i <= 0)
			{
				std::cout << "Invalid Index!\n";
			}
			else {
				Items.erase(Items.begin() + (i-1));
			}

		}
		else
			std::cout << "Invalid ID! Try Again!\n";
	}
	return 0;
}
