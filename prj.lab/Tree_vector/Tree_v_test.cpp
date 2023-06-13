#include<Tree_vector/Tree_v.h>
#include<string>
Tree_v f_;
bool isNum(std::string const &str)
{
    auto it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}
void help() {
	std::cout << "=================================================================\n";
	std::cout << "  find <�����> - ����� ������� � ������\n";
	std::cout << "  append <�����> - �������� ������� � ������\n";
	std::cout << "  delete <�����> - ������� ������� �� ������\n";
	std::cout << "  end - ��������� ���������\n";
	std::cout << "=================================================================\n>";
}
void mainMenu() {
	std::string current_command;
	std::cout << "=================================================================\n";
	std::cout << "������� help ��� ����������� ������ ���� ��������� ������.\n";
	std::cout << "=================================================================\n>";
	while(std::cin >> current_command) {;
		if (current_command == "delete") {
			std::string str;
			std::string sign = "";
			std::cin >> str;
			if (str[0] == '-') {
				str.erase(0, 1);
				sign = "-";
			} else sign = "";
			if (isNum(str)) {
				str = sign + str;
				int num = std::stoi(str);
				if (f_.find_key(num) == yes) {
					f_.delete_node(num);
					std::cout << "����� " << num << " ������� �� ������.\n>";
				} else std::cout << "����� " << num << " ��� � ������.\n>";
			}
			else {
				std::cout << "������ �����, ������ �� �������� ������.\n>";
			}
		} else if (current_command == "append") {
			std::string str;
			std::string sign = "";
			std::cin >> str;
			if (str[0] == '-') {
				str.erase(0, 1);
				sign = "-";
			} else sign = "";
			if (isNum(str)) {
				str = sign + str;
				int num = std::stoi(str);
				if (f_.find_key(num) == no) {
					f_.append_node(num);
					std::cout << "����� " << num << " ��������� � ����� ������.\n>";
				} else std::cout << "����� " << num << " ��� ���� � ������.\n>";
			}
			else {
				std::cout << "������ �����, ������ �� �������� ������.\n>";
			}
		} else if (current_command == "find") {
			std::string str;
			std::string sign = "";
			std::cin >> str;
			if (str[0] == '-') {
				str.erase(0, 1);
				sign = "-";
			} else sign = "";
			if (isNum(str)) {
				str = sign + str;
				int num = std::stoi(str);
				if (f_.find_key(num) == yes) {
					f_.append_node(num);
					std::cout << "����� " << num << " ���� � ������.\n>";
				} else std::cout << "����� " << num << " ��� � ������.\n>";
			}
			else {
				std::cout << "������ �����, ������ �� �������� ������.\n>";
			}
		} else if (current_command == "end") {
			std::cout << "��������� ���������. \n";
			return;
		} else if (current_command == "help") {
			help();
		} else {
			std::cout << "������� �� ����������. \n>";
		}
	}
}
int main() {
	
	/*f_.append_node(5);
	f_.append_node(3);
	f_.append_node(7);
	f_.append_node(1);
	f_.append_node(9);
	f_.print();
	f_.delete_node(5);
	f_.print();*/
	setlocale(LC_ALL, "Rus");
    mainMenu();
}