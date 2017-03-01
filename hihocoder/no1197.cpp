#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <map>
#include <string>
#include <bitset>
#include <set>

using namespace std;

typedef long long ll;


int main() {
	vector<string> text;
	string line, str;
	while (getline(cin, line)) {
		text.push_back(line);
	}

	for (int index = 0; index < text.size(); index++) {
		str = "";
		string current = text[index];
		int size = current.size();

		bool flag = true;
		bool flag_space = false;
		for (int i = 0; i < size; i++) {
			if (current[i] == ' ') {
				flag_space = true;
			}
			else if (current[i] == ',' || current[i] == '.') {
				str += current[i];
				flag_space = true;
				if (current[i] == '.') {
					str += " ";
					flag = true;
				}

			}
			else if (isalpha(current[i])){
				if (flag_space && !flag) {
					str += " ";
				}

				if (flag) {
					str += toupper(current[i]);
					flag = false;
				}
				else
					str += tolower(current[i]);
				flag_space = false;
			}
		}
		if (str[str.size() - 1] == ' ') cout << str.substr(0, str.size() - 1);
		else cout << str;
		if (index != (text.size() - 1))
			cout << endl;
	}
	return 0;
}