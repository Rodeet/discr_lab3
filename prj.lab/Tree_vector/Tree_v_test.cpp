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
	std::cout << "  find <число> - Найти элемент в дереве\n";
	std::cout << "  append <число> - Добавить элемент в дерево\n";
	std::cout << "  delete <число> - Удалить элемент из дерева\n";
	std::cout << "  end - завершить программу\n";
	std::cout << "=================================================================\n>";
}
void mainMenu() {
	std::string current_command;
	std::cout << "=================================================================\n";
	std::cout << "Введите help для отображения списка всех доступных команд.\n";
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
					std::cout << "Число " << num << " удалено из дерева.\n>";
				} else std::cout << "Числа " << num << " нет в дереве.\n>";
			}
			else {
				std::cout << "Ошибка ввода, данные не являются числом.\n>";
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
					std::cout << "Число " << num << " добавлено в конец дерево.\n>";
				} else std::cout << "Число " << num << " уже есть в дереве.\n>";
			}
			else {
				std::cout << "Ошибка ввода, данные не являются числом.\n>";
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
					std::cout << "Число " << num << " есть в дереве.\n>";
				} else std::cout << "Числа " << num << " нет в дереве.\n>";
			}
			else {
				std::cout << "Ошибка ввода, данные не являются числом.\n>";
			}
		} else if (current_command == "end") {
			std::cout << "Программа завершена. \n";
			return;
		} else if (current_command == "help") {
			help();
		} else {
			std::cout << "Команда не распознана. \n>";
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