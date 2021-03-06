#include "pch.h"
#include "interpreter.h"
#include <iostream>

int main()
{
	interpreter I;
	map<string, vector<string>> res;
	cout << "MiniSQL 1.2.2 (v1.2.2 beta, June 27 2019, 23:36:28) on win64" << endl;
	cout << "Input '\\help' or command list." << endl;
	while (true)
	{
		string cmd;
		cout << ">>> ";
		getline(cin,cmd);
		transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		if (cmd == "\\exit" || cmd == "\\quit") break;
		else if (cmd == "\\status") I.printAll(res);
		else if (cmd == "\\clear") system("cls");
		else if (cmd == "\\flush") I.flush();
		else if (cmd == "\\help")
		{
			cout << "Supported commands:" << endl;
			cout << "  select * from tableName [where condition];" << endl;
			cout << "  select (attr1, attr2, ... , attrN) from tableName [where condition];" << endl;
			cout << "" << endl;
			cout << "  create table tableName (attr1 type1 [primary unique notnull], ... , attrN typeN);" << endl;
			cout << "  create table tableName (attr1 type1 [unique notnull], ... , attrN typeN, primary key(attr));" << endl;
			cout << "" << endl;
			cout << "  create index indexName on tableName (attrName);" << endl;
			cout << "" << endl;
			cout << "  insert into tableName values(val1, val2, ... , valN);" << endl;
			cout << "  insert into tableName values(attr1=val1, attr2=val2, ... , attrN=valN);" << endl;
			cout << "" << endl;
			cout << "  delete * from tableName [where condition];" << endl;
			cout << "  delete (attr1, attr2, ... , attrN) from tableName [where condition];" << endl;
			cout << "" << endl;
			cout << "  drop table tableName;" << endl;
			cout << "" << endl;
			cout << "  drop index indexName;" << endl;
			cout << "" << endl;
			cout << "  '\\clear' to clear the screen." << endl;
			cout << "  '\\exit' or '\\quit' to exit this program." << endl;
			cout << "  '\\status' to show all info that last command created." << endl;
			cout << "  '\\flush' to flush all info into disk." << endl;
			cout << "" << endl;
			cout << "supported where expression:" << endl;
			cout << "  eg. where attr>val          >,<,>=,<=,<>" << endl;
			cout << "  eg. where attr1<>attr2" << endl;
			cout << "  eg. where attr1<val1 and ( attr2>=val2 or attr3<>val3 )" << endl;
			cout << "  eg. where attr between val1, val2" << endl;
			cout << "     note: between clause turns into :   attr>=val1 and attr<=val2" << endl;
			cout << "" << endl;
			cout << " NOTE:" << endl;
			cout << "   UNDEFINED values is allowed in tables, but compasion with UNDEFINED is NOT supported." << endl;
			cout << "   So if you insert an all-undefined record, you will not be able to access it." << endl;
		}
		else res = I.execute(cmd);
	}
	I.flush();
}

