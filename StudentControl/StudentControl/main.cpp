#include "main.h"

void loading();
void start();
int lobby();
int filelist();
int write();
int main();

void loading() {
	cls();
	cout << "�л��������α׷� v1.0 �ε���." << endl;
	Sleep(200);
	cls();
	cout << "�л��������α׷� v1.0 �ε���.." << endl;
	Sleep(200);
	cls()
	cout << "�л��������α׷� v1.0 �ε���..." << endl;
	Sleep(200);
	cls()
	cout << "�л��������α׷� v1.0 �ε���....." << endl;
	Sleep(1000);
}

void start() {
	uint password = 0;
	cls();
	cout << "----------------------------�л��������α׷�/�α���-------------------------------" << endl;
	cout << "Admin Password: ";
	cin >> password;
	if (cin.fail()) {
		cls();
		cout << "�ùٸ��� ���� ��й�ȣ �����Դϴ�. �ٽ� �Է��� �ּ���." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		pause();
		return start();
	}
	else {
		if (password == 32767) {
			cls();
			cout << "�α��� ����.. ��� �� ����ȭ������ �Ѿ�ϴ�." << endl;
			Sleep(2000);
		}
		else {
			cout << "�α��ο� �����Ͽ����ϴ�." << endl;
			cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�. " << endl;
			pause();
			return start();
		}
	}
}

int lobby() {
	cls();
	int a = 0;
	cout << "----------------------------�л��������α׷�--------------------------------------" << endl;
	cout << "�л� ��� : 1" << endl;
	cout << "�л� �߰� : 2" << endl;
	cout << "�л� ���� : 3" << endl;
	cout << "�л� ����(�߰�����) : 4" << endl;
	cout << "���α׷� ���� : 5" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "�޴� ��ȣ�� �Է����ּ��� : ";
	cin >> a;
	if (cin.fail()) {
		cls();
		cout << "�ùٸ��� ���� �޴� �����Դϴ�. �ٽ� �Է��Ͽ� �ֽñ� �ٶ��ϴ�." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		pause();
		return lobby();
	}
	else {
		switch (a) {
		case 1:
			return filelist();
			break;
		case 2:
			return write();
			break;
		case 5:
			return 0;
			break;
		default:
			cls();
			cout << "�ùٸ��� ���� �޴� �����Դϴ�. �ٽ� �Է��Ͽ� �ֽñ� �ٶ��ϴ�. " << endl;
			pause();
			return lobby();
			break;
		}
	}
}

int filelist() {
	int sel = 0;
	ifstream read;
	read.open("Student.txt", ifstream::in);

	string line;

	while (getline(read, line))
		cout << line << endl;

	read.close();

	cout << "���� ȭ��: [1], ���α׷� ����: [0]" << endl;
	cin >> sel;
	if (cin.fail()) {
		cls();
		cout << "0�� 1 �̿��� ���ڳ� ���ڸ� �Է����� ���ʽÿ�." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		pause();
		return filelist();
	} else {
		switch (sel) {
		case 0:
			return 0;
			break;
		case 1:
			cls();
			cout << "���� ȭ������ ���ư��ϴ�. ��ø� ��ٷ��ּ���..." << endl;
			Sleep(500);
			return lobby();
			break;
		default:
			cls();
			cout << "0 �Ǵ� 1 �̿��� ���ڸ� �Է����� ���ʽÿ�. ������ �߻��� �� �ֽ��ϴ�. " << endl;
			return filelist();
			break;
		}
	}
}

int write() {
	int select = 0;
	string name;
	string number;
	string score;
	ofstream write;
	write.open("Student.txt", ofstream::app);
	cls();
	cout << "�߰��� �л��� �̸��� �Է��Ͻʽÿ�:";
	cin >> name;
	cls();
	cout << "�߰��� �л��� ��ȣ�� �Է��Ͻʽÿ�:";
	cin >> number;
	cls();
	cout << "�߰��� �л��� ������ �Է��Ͻʽÿ�:";
	cin >> score;
	cls();
	write << "|" << name << "| " << "\t" << "|" << number << "| " << "\t" << "|" << score << "|" << endl;
	cls();
	cout << "����� �Ϸ�Ǿ����ϴ�." << endl;
	cls();
	cout << "���� �޴�: [1], �л� ���: [2], ���α׷� �����: [3], ���α׷� ����: [0] �� �Է��ϼ���:";
	cin >> select;
	if (cin.fail()) {
		cout << "���⿡ ���� ���ڳ� ���ڸ� �Է��� �� �����ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
		cin.clear();
		cin.ignore();
		pause();
		return lobby();
	}
	else {
		switch (select) {
		case 1:
			return lobby();
			break;
		case 2: 
			return filelist();
			break;
		case 3: 
			return main();
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "���⿡ ���� ���ڳ� ���ڸ� �Է��� �� �����ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
			return lobby();
			break;
		}
	}
}

int main() {
	loading();
	start();
	lobby();
	return 0;
}