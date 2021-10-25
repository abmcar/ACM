#include<iostream>
#include<string>
#include<stack>

using namespace std;

string bds;
int kuohao;
stack<char> t;
char fixd[1001000];
int nowpos = 0;
int unable;

bool check()
{
	for(int i = 0; i < bds.size(); i++)
	{
		if(bds[i] == '(')
			kuohao++;
		if(bds[i] == ')')
			kuohao--;
	}
	if(kuohao != 0)
	{
		cout << "NO";
		return false;
	}
	return true;
}

int getlevel(char now)
{
	if(now == '(' || now == ')')
		return 3;
	if(now == '*' || now == '/')
		return 2;
	if(now == '+' || now == '-')	
		return 1;
	return 0;
}

void turnmid()
{
	if(check() == false)
	{
		unable = 1;
		return;
	}
	for(int i = 0; i < bds.size()-1; i++)
	{
		//cout << bds[i] << endl;
		if(bds[i] == ')' || bds[i] == '+' || bds[i] == '-' || bds[i] == '*' || bds[i] == '/')
		{
			nowpos++;
			fixd[nowpos] = '.';
		}
		if(getlevel(bds[i-1]) != 0 && bds[i] == '-')
		{
			nowpos++;
			fixd[nowpos] = '^';
			nowpos++;
			fixd[nowpos] = bds[i+1];
			i++;
			continue;
		}
		if(bds[i] >= '0' && bds[i] <= '9')
		{
			nowpos++;
			fixd[nowpos] = bds[i];
			continue;
		}
		if(bds[i] == '(')
		{
			t.push(bds[i]);
			continue;
		}
		if(bds[i] == ')')
		{
			char nowchar = t.top();
			t.pop();
			while(nowchar != '(')
			{
				nowpos++;
				fixd[nowpos] = nowchar;
				nowchar = t.top();
				t.pop();
			}
			continue;
		}
		//cout << bds[i] << endl;
		if(t.size() == 0)
		{
			t.push(bds[i]);
			continue;
		}
		int nowlevel = getlevel(bds[i]);
		int toplevel = getlevel(t.top());
		//cout << bds[i] << endl;
		//cout << nowlevel << " " << toplevel << endl;
		if(toplevel == 3 || toplevel < nowlevel)
		{
			t.push(bds[i]);
			continue;
		}
		//cout << bds[i] << endl;
		while(nowlevel <= toplevel)
		{
			//cout << t.top() << endl;
			nowpos++;
			fixd[nowpos] = t.top();
			t.pop();
			if(t.size() == 0)
				break;
			toplevel = getlevel(t.top());
		}
		t.push(bds[i]);
	}
	nowpos++;
	fixd[nowpos] = '.';
	while(t.size() != 0)
	{
		//cout << t.top() << endl;
		nowpos++;
		fixd[nowpos] = t.top();
		t.pop();
	}
	return;
}

void work()
{
	stack<int> num;
	for(int i = 1; i <= nowpos; i++)
	{
		if(fixd[i] == '^')
		{
			i++;
			int temp = fixd[i] - '0';
			temp *= -1;
			num.push(temp);
			i++;
			while(fixd[i] != '.')
			{
				int numa = num.top();
				int numb = fixd[i]-'0';
				num.pop();
				num.push(numa*10+numb);
				i++;
			}
			continue;
		}
		if(fixd[i] >= '0' && fixd[i] <= '9')
		{
			num.push(fixd[i]-'0');
			i++;
			while(fixd[i] != '.')
			{
				int numa = num.top();
				int numb = fixd[i]-'0';
				num.pop();
				num.push(numa*10+numb);
				i++;
			}
			continue;
		}
		if(fixd[i] == '+')
		{
			int ta,tb;
			ta = num.top();
			num.pop();
			tb = num.top();
			num.pop();
			num.push(ta+tb);
			//cout << num.top() << endl;
		}
		if(fixd[i] == '-')
		{
			int ta,tb;
			ta = num.top();
			num.pop();
			tb = num.top();
			num.pop();
			num.push(tb-ta);
			//cout << ta << " " << tb << " " << ta-tb << endl;
		}
		if(fixd[i] == '*')
		{
			int ta,tb;
			ta = num.top();
			num.pop();
			tb = num.top();
			num.pop();
			num.push(ta*tb);
			//cout << num.top() << endl;
		}
		if(fixd[i] == '/')
		{
			int ta,tb;
			ta = num.top();
			num.pop();
			tb = num.top();
			num.pop();
			num.push(tb/ta);
			//cout << num.top() << endl;
		}
	}
	cout << num.top() << endl;
}

int main()
{
	cin >> bds;
	turnmid();
	if(unable == 1)
		return 0;
	work();
	return 0;
}
