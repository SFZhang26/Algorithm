#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>

using namespace std;

typedef long long ll;

ll T;

struct Node {
	int val;
	vector<Node *> next;
	Node(int s) :val(s) {};
};

//¡¨Ω”Õº
bool deal(map<string, Node *> &node, string str) {
	int start = 0;
	int i = start;
	for (; i < str.size(); i++) {
		if (str[i] == '=') break;
	}

	string left = str.substr(start, i - start);
	if (node.find(left) == node.end()) {
		node[left] = new Node(0);
	}
	if (node[left]->val == -1) node[left]->val = 0;

	i++;
	for (; i < str.size(); i++) {
		if (str[i] == '(') break;
	}
	i++;
	start = i;
	map<string, bool> m;
	for (; i < str.size(); i++) {
		if (str[i] == ',' || str[i] == ')') {
			if (str[i] == ')'&&i == start) return true;
			string cur = str.substr(start, i - start);
			if (cur == left) return false;
			else {
				if (node.find(cur) == node.end()) {
					node[cur] = new Node(-1);
				}
				if (m.find(cur)==m.end()) {
					node[left]->next.push_back(node[cur]);
					node[left]->val++;
					//cout << cur << "<-" << left << endl;
				}
				m[cur] = true;
			}
			if (str[i] == ')') break;
			start = i+1;
		}
	}
	return true;
}

bool BFS(map<string, Node *> &node, Node *cur, map<Node *, bool> visited) {
	for (int i = 0; i < cur->next.size(); i++) {
		if ((visited.find(cur->next[i]) != visited.end() && visited[cur->next[i]]) || cur->next[i]->val == -1)
			return false;
		else {
			if (cur->next[i]->val != 0){
				cur->next[i]->val = 0;
				visited[cur->next[i]] = true;
				if (!BFS(node, cur->next[i], visited)) return false;
				visited[cur->next[i]] = false;
			}
		}
	}
	return true;
}

bool solve(map<string, Node *> node) {
	for (map<string, Node *>::iterator it = node.begin(); it != node.end(); it++) {
		if (it->second->val == -1)
			return false;
		else if (it->second->val != 0) {
			map<Node *, bool> visited;
			visited[it->second] = true;
			bool re = BFS(node, it->second, visited);
			if (!re) return false;
			it->second->val=0;
		}
	}
	return true;
}

int main() {
	//open files
	ifstream f_input;
	ofstream f_output;

	f_input.open("C-large-practice.in");
	f_output.open("out_put");

	f_input >> T;

	for (int tt = 1; tt <= T; tt++) {
		int N;
		f_input >> N;
		bool result = true;
		map<string, Node *> node;
		for (int i = 0; i < N; i++) {
			string str;
			f_input >> str;
			bool noSelfToSelfNode = deal(node,str);
			if (!noSelfToSelfNode) {
				result = false;
				//break;
			}
		}
		if (result) result = solve(node);
		if (result) f_output << "Case #" << tt << ": GOOD" << endl;
		else f_output << "Case #" << tt << ": BAD" << endl;
		cout << tt << " finished" << endl;
	}

	f_input.close();
	f_output.close();
}