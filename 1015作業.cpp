#include <iostream>

using namespace std;

class GameCharacter
{
public:
	string name;
	int hp;
	int level;
	GameCharacter(string n,int h,int l):name(n),hp(h),level(l) {}
	void damage(int value)
	{
		hp -= value;
		if (hp <= 0)hp = 0;
	}
	void heal(int value)
	{
		hp += value;
		if (hp >= 100)hp = 100;
	}
	void levelup(int value)
	{
		level++;
		hp = 100;
	}
	void show()
	{
		cout << "Name: " << name << endl;
		cout << "HP: " << hp << endl;
		cout << "Level: " << level << endl;
	}
};

int main()
{
	string name;
	int n,hp, level,op,s,a;
	cout << "輸入角色人數: ";
	cin >> n;
	cout << endl;
	string name1, name2;
	int hp1 = 0, hp2 = 0, level1 = 1, level2 = 1;
	for (int i = 1; i <= n; i++)
	{
		cout << "===== 角色 " << i << " =====" << endl;
		cout << "Name: ";
		cin >> name;
		cout << "Hp: ";
		cin >> hp;
		cout << "Level: ";
		cin >> level;
		if (i == 1) {
			name1 = name; hp1 = hp; level1 = level;
		}
		else if (i == 2) {
			name2 = name; hp2 = hp; level2 = level;
		}
	}
	GameCharacter p1(name1, hp1, level1);
	GameCharacter p2(name2, hp2, level2);
	cout << "============ 選單 ============" << endl;
	cout << "1. 扣血" << endl;
	cout << "2. 回血" << endl;
	cout << "3. 升級" << endl;
	cout << "4. Show角色資料" << endl;
	cout << "5. Show全部角色資料" << endl;
	cout << "0. 結束程式" << endl;
	cout << "選哪個人: ";
	cin >> a;
	cout << "選擇: ";
	cin >> op;
	while (op != 0)
	{
		switch (op)
		{
		case 1:
			cin >> s;
			if (a == 1)
				p1.damage(s);
			else if (a == 2)
			{
				p2.damage(s);
			}
			break;
		case 2:
			cin >> s;
			if (a == 1)
				p1.heal(s);
			else if (a == 2)
			{
				p2.heal(s);
			}
			break;
		case 3:
			cin >> s;
			if (a == 1)
				p1.levelup(s);
			else if (a == 2)
			{
				p2.levelup(s);
			}
			break;
		case 4:
			if (a == 1)
				p1.show();
			else if (a == 2)
			{
				p2.show();
			}
			break;
		case 5:
			p1.show();
			p2.show();
			break;
		default:
			break;
		}
		cout << "選擇: ";
		cin >> op;
	}
	return 0;
}