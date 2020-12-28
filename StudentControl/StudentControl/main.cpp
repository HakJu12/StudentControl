#include "main.h"

void loading();
void start();
int lobby();
int filelist();
int write();
int main();

void loading() {
	cls();
	cout << "학생관리프로그램 v1.0 로딩중." << endl;
	Sleep(200);
	cls();
	cout << "학생관리프로그램 v1.0 로딩중.." << endl;
	Sleep(200);
	cls()
	cout << "학생관리프로그램 v1.0 로딩중..." << endl;
	Sleep(200);
	cls()
	cout << "학생관리프로그램 v1.0 로딩중....." << endl;
	Sleep(1000);
}

void start() {
	uint password = 0;
	cls();
	cout << "----------------------------학생관리프로그램/로그인-------------------------------" << endl;
	cout << "Admin Password: ";
	cin >> password;
	if (cin.fail()) {
		cls();
		cout << "올바르지 않은 비밀번호 형식입니다. 다시 입력해 주세요." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		pause();
		return start();
	}
	else {
		if (password == 32767) {
			cls();
			cout << "로그인 성공.. 잠시 후 메인화면으로 넘어갑니다." << endl;
			Sleep(2000);
		}
		else {
			cout << "로그인에 실패하였습니다." << endl;
			cout << "비밀번호가 일치하지 않습니다. " << endl;
			pause();
			return start();
		}
	}
}

int lobby() {
	cls();
	int a = 0;
	cout << "----------------------------학생관리프로그램--------------------------------------" << endl;
	cout << "학생 명단 : 1" << endl;
	cout << "학생 추가 : 2" << endl;
	cout << "학생 삭제 : 3" << endl;
	cout << "학생 편집(추가예정) : 4" << endl;
	cout << "프로그램 종료 : 5" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "메뉴 번호를 입력해주세요 : ";
	cin >> a;
	if (cin.fail()) {
		cls();
		cout << "올바르지 않은 메뉴 형식입니다. 다시 입력하여 주시기 바랍니다." << endl;
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
			cout << "올바르지 않은 메뉴 형식입니다. 다시 입력하여 주시기 바랍니다. " << endl;
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

	cout << "메인 화면: [1], 프로그램 종료: [0]" << endl;
	cin >> sel;
	if (cin.fail()) {
		cls();
		cout << "0과 1 이외의 문자나 숫자를 입력하지 마십시오." << endl;
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
			cout << "메인 화면으로 돌아갑니다. 잠시만 기다려주세요..." << endl;
			Sleep(500);
			return lobby();
			break;
		default:
			cls();
			cout << "0 또는 1 이외의 숫자를 입력하지 마십시오. 오류가 발생할 수 있습니다. " << endl;
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
	cout << "추가할 학생의 이름을 입력하십시오:";
	cin >> name;
	cls();
	cout << "추가할 학생의 번호를 입력하십시오:";
	cin >> number;
	cls();
	cout << "추가할 학생의 점수를 입력하십시오:";
	cin >> score;
	cls();
	write << "|" << name << "| " << "\t" << "|" << number << "| " << "\t" << "|" << score << "|" << endl;
	cls();
	cout << "등록이 완료되었습니다." << endl;
	cls();
	cout << "메인 메뉴: [1], 학생 명단: [2], 프로그램 재시작: [3], 프로그램 종료: [0] 을 입력하세요:";
	cin >> select;
	if (cin.fail()) {
		cout << "보기에 없는 숫자나 문자를 입력할 수 없습니다. 메인 메뉴로 돌아갑니다." << endl;
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
			cout << "보기에 없는 숫자나 문자를 입력할 수 없습니다. 메인 메뉴로 돌아갑니다." << endl;
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