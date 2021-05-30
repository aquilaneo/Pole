#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <array>

using namespace std;

class Memory {
	vector<char> memory;
	int pointer = 0;

public:
	Memory () {
		this->memory.push_back (0);
	}

	void AddPointer () {
		this->pointer++;
		if (this->pointer >= this->memory.size ()) {
			this->memory.push_back (0);
		}
	}

	void SubtractPointer () {
		this->pointer--;
		if (this->pointer < 0) {
			cerr << "Error: ポインタの値がマイナスになりました！" << endl;
			exit (1);
		}
	}

	void AddMemory () {
		this->memory[this->pointer]++;
	}

	void SubtractMemory () {
		this->memory[this->pointer]--;
	}

	void OutputMemory () {
		cout << this->memory[this->pointer] << flush;
	}

	void InputMemory () {
		cin >> this->memory[this->pointer];
	}
};

class Command {
	int commandType = -1;
	Memory* memory;

public:
	Command (const string& str, Memory& memory) {
		this->memory = &memory;

		// コマンド候補文字列
		array<string, 6> commandStrings = {
				"II", "Il", "I1", "lI", "ll", "l1"
		};

		// コマンドタイプを判定
		for (int i = 0; i < commandStrings.size (); i++) {
			if (str == commandStrings[i]) {
				this->commandType = i;
				break;
			}
		}
	}

	void Execute () {
		switch (commandType) {
			case 0:
				// ポインタ1加算
				this->memory->AddPointer ();
				break;
			case 1:
				this->memory->SubtractPointer ();
				break;
			case 2:
				this->memory->AddMemory ();
				break;
			case 3:
				this->memory->SubtractMemory ();
				break;
			case 4:
				this->memory->OutputMemory ();
				break;
			case 5:
				this->memory->InputMemory ();
				break;
		}
	}
};

int main (int argc, char* argv[]) {
	// 引数チェック
	if (argc != 2) {
		cerr << "Error: 引数に実行するpoleファイルのパスを指定してください。" << endl;
		cerr << "(例: ./Pole hello.pole)" << endl;
		return 1;
	}

	// ファイル存在チェック
	filesystem::path path = argv[1];
	if (!filesystem::exists (path)) {
		cerr << "Error: 指定されたファイル " << path << " は存在しません。" << endl;
		return 1;
	}

	// ファイル読み込みとエラー処理
	ifstream input (path);
	if (input.fail ()) {
		cerr << "Error: 指定されたファイル " << path << " の読み込みに失敗しました。" << endl;
	}

	// 内容を解釈
	vector<Command> commands;
	Memory memory;
	char buf;
	string commandString = "  ";
	int index = 0;
	char validateCharacters[] = {'I', 'l', '1'};
	while (input.get (buf)) {
		// bufが命令の文字が判断
		bool correct = false;
		for (char validateCharacter : validateCharacters) {
			if (buf == validateCharacter) {
				correct = true;
				break;
			}
		}

		// コマンドとして認識
		if (correct) {
			commandString[index] = buf;
			if (index == 1) {
				commands.emplace_back (commandString, memory);
				commandString = "  ";
				index = 0;
			} else {
				index++;
			}
		}
	}

	// 実行
	for (auto& command : commands) {
		command.Execute ();
	}
    cout << endl;

	return 0;
}
