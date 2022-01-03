#include <bits/stdc++.h>

using namespace std;

class Item
{
public:
    string itemName;
    int weight, cost;
    string type;
    void calc()
    {
        if (weight > 15)
            cost += (min(weight, 25) - 15) * 12;
        if (weight > 25)
            cost += (min(weight, 45) - 25) * 15;
        if (weight > 45)
            cost += (min(weight, 80) - 45) * 20;
        if (weight > 80)
            cost += (weight - 80) * 30;
    }
    Item(string name, int weight)
    {
        this->itemName = name;
        this->weight = weight;
        this->cost = 0;
        calc();
    }
    void printCost()
    {
        cout << itemName + " cost:" << cost << endl;
    }
};

class ItemA : public Item
{
public:
    ItemA(string name, int weight) : Item(name, weight)
    {
        type = "A";
    };
    void printCost()
    {
        cout << "Item Type:" + type << endl;
        cout << itemName + " cost:" << cost << endl;
    }
};

class ItemB : public Item
{
public:
    ItemB(string name, int weight) : Item(name, weight)
    {
        type = "B";
    };
    void printCost()
    {
        cout << "Item Type:" + type << endl;
        cout << itemName + " cost:" << cost << endl;
    }
};

class util
{
public:
    static void saveItem(Item nowItem)
    {
        ofstream fout("./item/" + nowItem.itemName);
        fout << nowItem.type << endl;
        fout << nowItem.itemName << endl;
        fout << nowItem.weight << endl;
        fout << nowItem.cost << endl;
    }
    // static void createItem()
    // {
    //     cout << "输入货物的名字和重量" << endl;
    //     string nowName;
    //     int nowWeight;
    //     cin >> nowName >> nowWeight;
    //     Item nowItem(nowName, nowWeight);
    //     saveItem(nowItem);
    //     nowItem.printCost();
    // }
    static void createItemA()
    {
        cout << "输入货物的名字和重量" << endl;
        string nowName;
        int nowWeight;
        cin >> nowName >> nowWeight;
        ItemA nowItem(nowName, nowWeight);
        saveItem(nowItem);
        nowItem.printCost();
    }
    static void createItemB()
    {
        cout << "输入货物的名字和重量" << endl;
        string nowName;
        int nowWeight;
        cin >> nowName >> nowWeight;
        ItemB nowItem(nowName, nowWeight);
        saveItem(nowItem);
        nowItem.printCost();
    }
    static void queryItem(string itemName)
    {
        ifstream fin("./item/" + itemName);
        if (!fin.is_open())
        {
            cout << "Error:" + itemName + " 不存在" << endl;
            return;
        }
        string nowName, nowType;
        int nowWeight, nowCost;
        fin >> nowType >> nowName >> nowWeight >> nowCost;
        cout << "查询结果:" << endl
             << "货物类型:" << nowType << " 货物名称:" << nowName << " 货物重量:" << nowWeight << " 货物花费:" << nowCost << endl;
    }
};

class menu
{
public:
    static void mainMenu()
    {
        util nowUtil;
        while (true)
        {
            cout << "输入 1 录入货物(类型A)" << endl;
            cout << "输入 2 录入货物(类型B)" << endl;
            cout << "输入 3 查询货物" << endl;
            cout << "输入 exit 退出程序" << endl;
            string opt;
            cin >> opt;
            if (opt == "1")
                nowUtil.createItemA();
            else if (opt == "2")
                nowUtil.createItemB();
            else if (opt == "3")
            {
                cout << "输入货物的名字" << endl;
                string nowName;
                cin >> nowName;
                nowUtil.queryItem(nowName);
            }
            else if (opt == "exit")
            {
                return;
            }
            else
            {
                cout << "Error input" << endl;
            }
        }
    }
};

int main()
{
    menu nowMenu;
    nowMenu.mainMenu();
    return 0;
}