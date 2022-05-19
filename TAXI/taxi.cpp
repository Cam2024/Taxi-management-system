#include"header.h";

int main()
{
	int o = 1;
	string temp_id;
	admin a;
	a.read();
	while (1) //Manage all operations
	{
		switch (o)
		{
		case 1:o = menu(); break;
		case 2:o = admin_menu(); break;
		case 3:o = drivers_menu(); break;
		case 4:o = admin_login(); break;
		case 5:o = a.driver_login(temp_id); break;
		case 6:a.add_car(); o = 2; break;
		case 7:a.edit_car(); o = 2; break;
		case 8:a.show_car(); o = 2; break;
		case 9:a.search_car(); o = 2; break;
		case 10:a.del_car(); o = 2; break;
		case 11:a.add_records(temp_id); o = 3; break;
		case 12:a.show_info(temp_id); o = 3; break;
		case 13:a.show_records(temp_id); o = 3; break;
		case 14:exit_system();
		}
	}
	return 0;
}

int menu()
{
	/*Display the main menu for user selection*/
	char ch;
	/*Temporary characters are used for user input*/
	int o = 0;
	/*operation of user selected*/
	chart();
	gotoxy(5, 40);
	cout << "    Please select an option to continue    ";
	gotoxy(7, 34);
	cout << "1: Admin Login";
	gotoxy(9, 34);
	cout << "2: Drivers Login";
	gotoxy(11, 34);
	cout << "3: EXIT System";
	gotoxy(19, 34);
	cout << "YOUR OPTION:";
	while (1)
	{
		gotoxy(19, 50);
		ch = getch();
		/*Use getch() to avoid the impact on the program each time you press Enter*/
		if (ch < 49 || ch > 51)
		{
			/*Allow the user to enter only 1, 2 and 3*/
			cout << "\tInvalid selection!!!";
		}
		else
		{
			break;
		}
	}
	system("cls");
	o = (int)ch - 48;
	/*Select operationand return it to main()*/
	switch (o)
	{
	case 1:o = 4; break;
	case 2:o = 5; break;
	case 3:o = 14; break;
	}
	return o;
}

int admin_menu()
{
	/*Display the main menu for user selection*/
	char ch;
	/*Temporary characters are used for user input*/
	int o = 0;
	/*operation of user selected*/
	chart();
	gotoxy(5, 40);
	cout << "    Please select an option to continue    ";
	gotoxy(7, 34);
	cout << "1: Show All Information";
	gotoxy(9, 34);
	cout << "2: Add Taxi Information";
	gotoxy(11, 34);
	cout << "3: Edit Taxi Information";
	gotoxy(13, 34);
	cout << "4: Delete Taxi Information";
	gotoxy(15, 34);
	cout << "5: Search Taxi Information";
	gotoxy(17, 34);
	cout << "6: Exit";
	gotoxy(19, 34);
	cout << "YOUR OPTION:";
	while (1)
	{
		gotoxy(19, 50);
		ch = getch();
		/*Use getch() to avoid the impact on the program each time you press Enter*/
		if (ch < 49 || ch > 54)
		{
			/*Allow the user to enter only 1, 2 and 3*/
			cout << "\tInvalid selection!!!";
		}
		else
		{
			break;
		}
	}
	system("cls");
	o = (int)ch - 48;
	/*Select operationand return it to main()*/
	switch (o)
	{
	case 1:o = 8;break;
	case 2:o = 6;break;
	case 3:o = 7;break;
	case 4:o = 10; break;
	case 5:o = 9; break;
	case 6:o = 1; break;
	}
	return o;
}

int drivers_menu()
{
	/*Display the main menu for user selection*/
	char ch;
	/*Temporary characters are used for user input*/
	int o = 0;
	/*operation of user selected*/

	chart();
	gotoxy(5, 40);
	cout << "    Please select an option to continue    ";
	gotoxy(7, 34);
	cout << "1: Start Service";
	gotoxy(9, 34);
	cout << "2: Personal Information";
	gotoxy(11, 34);
	cout << "3: Rewards and Punishment Records";
	gotoxy(13, 34);
	cout << "4: Exit";
	gotoxy(19, 34);
	cout << "YOUR OPTION:";
	while (1)
	{
		gotoxy(19, 50);
		ch = getch();
		/*Use getch() to avoid the impact on the program each time you press Enter*/
		if (ch < 49 || ch > 52)
		{
			/*Allow the user to enter only 1, 2 and 3*/
			cout << "\tInvalid selection!!!";
		}
		else
		{
			break;
		}
	}
	system("cls");
	o = (int)ch - 48;
	switch (o)
	{
	case 1:o = 11; break;
	case 2:o = 12; break;
	case 3:o = 13; break;
	case 4:o = 1; break;
	}
	return o;
}

int admin_login()
{
	/*Administrator login*/
	char id[20] = { 'a','d','m','i','n','\0' };
	char temp_id[20] = "\0";
	char password[20] = { 'a','d','m','i','n','\0' };
	char temp_password[20] = "\0";
	char ch;
	int a = 1;
	chart();
	gotoxy(5, 38);
	cout << "Welcome to login NB TAXI management system!!!";
	gotoxy(7, 34);
	cout << "Please enter your account:";
	gotoxy(9, 34);
	cout << "Please enter your password:";
	gotoxy(14, 34);
	cout << "Press Enter to continue...";
	gotoxy(7, 61);
	enter(temp_id, 20, 1);
	gotoxy(9, 62);
	enter(temp_password, 20, 0);
	if (strcmp(id,temp_id))
	{
		gotoxy(11, 34);
		cout << "The administrator does not exist.";
		ch = getch();
		system("cls");
	}
	else
	{
		/*Judge whether the password is entered correctly*/
		if (!(strcmp(password, temp_password)))
		{
			gotoxy(11, 34);
			cout << "Login succesful, Loading~~~ ";
			per(11, 62);
			system("cls");
			a = 2;
		}
		else
		{
			gotoxy(11, 34);
			cout << "Password is wrong.";
			ch = getch();
			system("cls");
		}
	}
	return a;
}

int admin::driver_login(string& temp_id)
{
	//driver login
	char temp[12];
	char temp_pw[12];
	memset(temp, '\0', sizeof(temp));
	memset(temp_pw, '\0', sizeof(temp_pw));
	char ch;
	int a = 1;
	chart();
	if (tax.empty())
	{
		gotoxy(7, 32);
		cout << "No driver information!!!";
		gotoxy(9, 32);
		cout << "Please wait for the administrator to enter the information.";
		gotoxy(18, 32);
		cout << "Press Enter to continue...";
		getch();
		return 1;
	}
	gotoxy(5, 38);
	cout << "Welcome to login NB TAXI management system!!!";
	gotoxy(7, 34);
	cout << "Please enter your car ID:";
	gotoxy(9, 34);
	cout << "Please enter your password:";
	gotoxy(14, 34);
	cout << "Press Enter to continue...";
	gotoxy(7, 60);
	enter(temp, 10, 1);
	int count = 0;
	for (int i = 0; temp[i] != '\0'; i++)
	{
		count = count + 1;
	}
	string temp_1(temp, count);
	temp_id = temp_1;
	gotoxy(9, 62);
	enter(temp_pw, 10, 0);
	count = 0;
	for (int i = 0; temp_pw[i] != '\0'; i++)
	{
		count = count + 1;
	}
	string temp_password(temp_pw, count);
	vector<taxi>::iterator iter; //Create a vector iterator for the taxi class
	for (iter = this->tax.begin(); iter != this->tax.end(); iter++)
	{
		if (iter->car_id == temp_id)
		{
			if (iter->password == temp_password)
			{
				gotoxy(11, 34);
				cout << "Login succesful, Loading~~~ ";
				per(11, 62);
				system("cls");
				a = 3;
			}
			else
			{
				gotoxy(11, 34);
				cout << "Password is wrong.";
				ch = getch();
				system("cls");
				a = 2;
			}
			break;
		}
	}

	if (a == 1)
	{
		gotoxy(11, 34);
		cout << "The driver does not exist.";
		ch = getch();
		system("cls");
	}
	if (a == 2)
	{
		a = 1;
	}
	return a;
}

void admin::show_car() //show all information
{
	if (tax.empty())
	{
		chart();
		gotoxy(7, 32);
		cout << "No information!!!";
		gotoxy(9, 32);
		cout << "Please wait for the administrator to enter the information.";
		gotoxy(18, 32);
		cout << "Press Enter to continue...";
		getch();
		return;
	}
	int count = 2;
	vector<taxi>::iterator iter; 
	for (iter = this->tax.begin(); iter != this->tax.end(); iter++) 
	{
		gotoxy(count, 10);
		cout << "  Driver_1 Name: " << iter->name_1;
		gotoxy(count + 1, 10);
		cout << "  Driver_2 Name: " << iter->name_2;
		gotoxy(count + 2, 10);
		cout << "  Password: " << iter->password;
		gotoxy(count + 3, 10);
		cout << "  Car ID: " << iter->car_id;
		gotoxy(count + 4, 10);
		cout << "  Car Type: " << iter->car_type;
		gotoxy(count + 5, 10);
		cout << "  Total income: " << iter->total_income << " ($)";
		cout << "  Rewards: " << iter->rewards << " (index)";
		cout << "  Punishments: " << iter->punishments << " (index)";
		count += 8;
	}
	gotoxy(count, 12);
	cout << "Press Enter to continue...";
	getch();
	system("cls");
}

void admin::add_car() //add a taxi information
{
	taxi t; 
	chart();
	gotoxy(7, 34);
	cout << "Please assign a car ID: ";
	gotoxy(9, 34);
	cout << "Please input a full name of driver 1: ";
	gotoxy(11, 34);
	cout << "Please input a full name of driver 2(Optional): ";
	gotoxy(13, 34);
	cout << "Please enter the car type: ";
	gotoxy(15, 34);
	cout << "Please set a password: ";
	gotoxy(7, 58);
	int count = 0;
	char temp[12];
	memset(temp, '\0', sizeof(temp));
	enter(temp, 10, 1);
	for (int i = 0; temp[i] != '\0'; i++)
	{
		count = count + 1;
	}
	if (count == 0)
	{
		cout << "A car ID is necessary!!!";
		gotoxy(18, 34);
		cout << "Press any key to return...";
		getch();
		system("cls");
		return;

	}
	string temp_1(temp, count);
	t.car_id = temp_1;
	vector<taxi>::iterator iter;
	for (iter = this->tax.begin(); iter != this->tax.end(); iter++)
	{
		if (iter->car_id == t.car_id)
		{
			gotoxy(17, 34);
			cout << "The taxi already exists!!!";
			gotoxy(18, 34);
			cout << "Press any key to return...";
			getch();
			system("cls");
			return;
		}
	}
	gotoxy(9, 72);
	count = 0;
	memset(temp, '\0', sizeof(temp));
	enter(temp, 10, 1);
	for (int i = 0; temp[i] != '\0'; i++)
	{
		count = count + 1;
	}
	if (count == 0)
	{
		gotoxy(10, 64);
		cout << "A driver is necessary!!!";
		gotoxy(18, 34);
		cout << "Press any key to return...";
		getch();
		system("cls");
		return;
	}
	string temp_2(temp, count);
	t.name_1 = temp_2;
	gotoxy(11, 82);
	char temp_name[12];
	memset(temp_name, '\0', sizeof(temp_name));
	enter(temp_name, 10, 1);
	string name = "                ";
	if (temp_name[0] == '\0')
	{
		name = "NULL           ";
	}
	else
	{
		for (int i = 0; temp_name[i] != '\0'; i++)
		{
			name[i] = temp_name[i];
		}
	}
	t.name_2 = name;
	gotoxy(13, 61);
	count = 0;
	memset(temp, '\0', sizeof(temp));
	enter(temp, 10, 1);
	for (int i = 0; temp[i] != '\0'; i++)
	{
		count = count + 1;
	}
	if (count == 0)
	{
		string temp_3 = "Classic";
		t.car_type = temp_3;
	}
	else
	{
		string temp_3(temp, count);
		t.car_type = temp_3;
	}
	gotoxy(15, 58);
	count = 0;
	memset(temp, '\0', sizeof(temp));
	enter(temp, 10, 1);
	for (int i = 0; temp[i] != '\0'; i++)
	{
		count = count + 1;
	}
	if (count == 0)
	{
		cout << "A password is necessary!!!";
		gotoxy(18, 34);
		cout << "Press any key to return...";
		getch();
		system("cls");
		return;
	}
	string temp_4(temp, count);
	t.password = temp_4;
	gotoxy(18, 34);
	cout << "Press Enter to continue...";
	getch();
	t.total_income = 0;
	t.rewards = 0;
	t.punishments = 0;
	tax.push_back(t);
	this->save();
}

void admin::edit_car() //edit a taxi information
{
	char temp_income[20];
	char temp_rewards[20];
	char temp_pun[20];
	char temp_name[12];
	memset(temp_income, '\0', sizeof(temp_income));
	memset(temp_rewards, '\0', sizeof(temp_rewards));
	memset(temp_pun, '\0', sizeof(temp_pun));
	memset(temp_name, '\0', sizeof(temp_name));
	chart();
	if (tax.empty()) 
	{
		gotoxy(7, 32);
		cout << "No information!!!";
		gotoxy(9, 32);
		cout << "Please wait for the administrator to enter the information.";
		gotoxy(18, 32);
		cout << "Press Enter to continue...";
		getch();
		return;
	}
	string temp_id;
	gotoxy(4, 31);
	cout << "Input Car ID: ";
	int count = 0;
	char temp[12];
	memset(temp, '\0', sizeof(temp));
	enter(temp, 10, 1);
	for (int i = 0; temp[i] != '\0'; i++)
	{
		count = count + 1;
	}
	string temp_1(temp, count);
	temp_id = temp_1;
	vector<taxi>::iterator iter;
	for (iter = this->tax.begin(); iter != this->tax.end(); iter++) 
	{
		if (iter->car_id == temp_id)
		{
			gotoxy(7, 34);
			cout << "Please input a full name of driver 1: ";
			gotoxy(8, 34);
			cout << "Please input a full name of driver 2(Optional): ";
			gotoxy(10, 34);
			cout << "Please assign a car ID: ";
			gotoxy(11, 34);
			cout << "Please enter the car type: ";
			gotoxy(12, 34);
			cout << "Please set a password: ";
			gotoxy(14, 34);
			cout << "Please enter total income($): ";
			gotoxy(15, 34);
			cout << "Please enter the rewards index: ";
			gotoxy(16, 34);
			cout << "Please enter the Punishments index: ";
			gotoxy(7, 72);
			count = 0;
			memset(temp, '\0', sizeof(temp));
			enter(temp, 10, 1);
			for (int i = 0; temp[i] != '\0'; i++)
			{
				count = count + 1;
			}
			if (count == 0)
			{
				gotoxy(9, 64);
				cout << "A driver is necessary!!!";
				gotoxy(18, 34);
				cout << "Press any key to return...";
				getch();
				system("cls");
				return;
			}
			string temp_2(temp, count);
			iter->name_1 = temp_2;
			gotoxy(8, 82);
			enter(temp_name, 9, 1);
			string name = "NULL           ";
			for (int i = 0; temp_name[i] != '\0'; i++) 
			{
				name[i] = temp_name[i];
			}
			iter->name_2 = name;
			gotoxy(10, 58);
			count = 0;
			memset(temp, '\0', sizeof(temp));
			enter(temp, 10, 1);
			for (int i = 0; temp[i] != '\0'; i++)
			{
				count = count + 1;
			}
			if (count == 0)
			{
				cout << "A driver is necessary!!!";
				gotoxy(18, 34);
				cout << "Press any key to return...";
				getch();
				system("cls");
				return;
			}
			string temp_3(temp, count);
			vector<taxi>::iterator iter_1;
			for (iter_1 = this->tax.begin(); iter_1 != this->tax.end(); iter_1++)
			{
				if (temp_id == temp_3)
				{
					break;
				}
				if (iter_1->car_id == temp_3)
				{
					gotoxy(17, 34);
					cout << "The taxi already exists!!!";
					gotoxy(18, 34);
					cout << "Press any key to return...";
					getch();
					system("cls");
					return;
				}
			}
			iter->car_id = temp_3;
			gotoxy(11, 61);
			count = 0;
			memset(temp, '\0', sizeof(temp));
			enter(temp, 10, 1);
			for (int i = 0; temp[i] != '\0'; i++)
			{
				count = count + 1;
			}
			if (count == 0)
			{
				string temp_4 = "Classic";
				iter->car_type = temp_4;
			}
			else
			{
				string temp_4(temp, count);
				iter->car_type = temp_4;
			}
			gotoxy(12, 58);
			count = 0;
			memset(temp, '\0', sizeof(temp));
			enter(temp, 10, 1);
			for (int i = 0; temp[i] != '\0'; i++)
			{
				count = count + 1;
			}
			if (count == 0)
			{
				cout << "A driver is necessary!!!";
				gotoxy(18, 34);
				cout << "Press any key to return...";
				getch();
				system("cls");
				return;
			}
			string temp_5(temp, count);
			iter->password = temp_5;
			gotoxy(14, 64);
			enter(temp_income, 7, 6);
			iter->total_income = transf(temp_income);
			gotoxy(15, 66);
			enter(temp_rewards, 5, 6);
			iter->rewards = transf(temp_rewards);
			gotoxy(16, 70);
			enter(temp_pun, 5, 6);
			iter->punishments = transf(temp_pun);
			gotoxy(18, 34);
			cout << "Press Enter to continue...";
			getch();
			this->save();
			return;
		}
	}
	gotoxy(16, 34);
	cout << "Taxi information does not exist!!!";
	gotoxy(18, 34);
	cout << "Press Enter to continue...";
	getch();
	system("cls");
}

void admin::search_car() //search a taxi information
{
	chart();
	if (tax.empty())
	{
		gotoxy(7, 32);
		cout << "No information!!!";
		gotoxy(9, 32);
		cout << "Please wait for the administrator to enter the information.";
		gotoxy(18, 32);
		cout << "Press Enter to continue...";
		getch();
		return;
	}
	string id;
	gotoxy(4, 31);
	cout << "Input Car ID: "; 
	int count = 0;
	char temp[12];
	memset(temp, '\0', sizeof(temp));
	enter(temp, 10, 1);
	for (int i = 0; temp[i] != '\0'; i++)
	{
		count = count + 1;
	}
	string temp_1(temp, count);
	id = temp_1;
	vector<taxi>::iterator iter;
	for (iter = this->tax.begin(); iter != this->tax.end(); iter++)
	{
		if (iter->car_id == id)
		{
			gotoxy(7, 34);
			cout << "Driver_1 Name: " << iter->name_1;
			gotoxy(8, 34);
			cout << "Driver_2 Name: " << iter->name_2;
			gotoxy(10, 34);
			cout << "Password: " << iter->password;
			gotoxy(11, 34);
			cout << "Car ID: " << iter->car_id;
			gotoxy(12, 34);
			cout << "Car Type: " << iter->car_type;
			gotoxy(14, 34);
			cout << "Total income: " << iter->total_income << " ($)";
			gotoxy(15, 34);
			cout << "Rewards: " << iter->rewards << " (index)";
			gotoxy(16, 34);
			cout << "Punishments: " << iter->punishments << " (index)";
			gotoxy(18, 34);
			cout << "Press Enter to continue...";
			getch();
			system("cls");
			return;
		}
	}
	gotoxy(16, 34);
	cout << "Taxi information does not exist!!!";
	gotoxy(18, 34);
	cout << "Press Enter to continue...";
	getch();
	system("cls");
}

void admin::del_car() //delete a taxi information
{
	chart();
	if (tax.empty()) 
	{
		gotoxy(7, 32);
		cout << "No information!!!";
		gotoxy(9, 32);
		cout << "Please wait for the administrator to enter the information.";
		gotoxy(18, 32);
		cout << "Press Enter to continue...";
		getch();
		return;
	}
	string temp_id;
	gotoxy(7, 35);
	cout << "Input Car ID:  "; 
	int count = 0;
	char temp[12];
	memset(temp, '\0', sizeof(temp));
	enter(temp, 10, 1);
	for (int i = 0; temp[i] != '\0'; i++)
	{
		count = count + 1;
	}
	string temp_1(temp, count);
	temp_id = temp_1;
	vector<taxi>::iterator iter;
	for (iter = this->tax.begin(); iter != this->tax.end();iter++)
	{
		if (iter->car_id == temp_id) {
			gotoxy(9, 35);
			cout << "Are you sure to delete?";
			gotoxy(10, 35);
			cout << "(Enter Y or y to confirm deletion or other keys to exit)";
			int ch;
			ch = getch();
			if (ch == 'y' || ch == 'Y')
			{
				iter = tax.erase(iter);
				this->save();
			}
			system("cls");
			return;
		}
	}
	gotoxy(16, 34);
	cout << "Taxi information does not exist!!!";
	gotoxy(18, 34);
	cout << "Press Enter to continue...";
	getch();
	system("cls");
}

void admin::add_records(string& temp_id) //add a income and r&p record
{
	int income = 0;
	int record = 0;
	char temp_income[20];
	char temp_record[20];
	memset(temp_income, '\0', sizeof(temp_income));
	memset(temp_record, '\0', sizeof(temp_record));
	vector<taxi>::iterator iter;
	for (iter = this->tax.begin(); iter != this->tax.end(); iter++)
	{
		if (iter->car_id == temp_id) 
		{
			chart();
			gotoxy(7, 34);
			cout << "Please tell the driver your destination...";
			gotoxy(9, 34);
			cout << "Press enter when you are ready!!!";
			getch();
			system("cls");
			chart();
			gotoxy(7, 34);
			cout << "Driving...";
			per(7, 45);
			gotoxy(7, 34);
			cout << "We have reached our destination  >.< ";
			gotoxy(9, 34);
			cout << "Ask the driver how much you need to pay($): "; 
			gotoxy(11, 34);
			cout << "Are you satisfied with this service : ";
			gotoxy(13, 34);
			cout << "(Please enter 0-9 to indicate your satisfaction)";
			gotoxy(9, 79);
			enter(temp_income, 3, 6);
			income = transf(temp_income);
			gotoxy(11, 71);
			enter(temp_record, 1, 6);
			record = transf(temp_record);
			gotoxy(16, 34);
			cout << "Thank you for your comments on this service!!!";
			gotoxy(18, 34);
			cout << "Press Enter to continue...";
			iter->total_income += income;
			record -= 4;
			if (record >= 0)
			{
				iter->rewards += record;
			}
			else
			{
				iter->punishments += ((~record)+1);
			}
			this->save();
			getch();
			system("cls");
			break;
		}
	}
}

void admin::show_info(string& temp_id) //show personal information
{
	vector<taxi>::iterator iter; 
	for (iter = this->tax.begin(); iter != this->tax.end(); iter++) 
	{
		if (temp_id == iter->car_id)
		{
			chart();
			gotoxy(6, 34);
			cout << "Driver_1 Name: " << iter->name_1;
			gotoxy(8, 34);
			cout << "Driver_2 Name: " << iter->name_2;
			gotoxy(10, 34);
			cout << "Password: " << iter->password;
			gotoxy(12, 34);
			cout << "Car ID: " << iter->car_id;
			gotoxy(14, 34);
			cout << "Car Type: " << iter->car_type;
			gotoxy(16, 34);
			cout << "Total income: " << iter->total_income << " ($)";
			gotoxy(18, 34);
			cout << "Press Enter to continue...";
			getch();
			system("cls");
			return;
		}
	}
}

void admin::show_records(string& temp_id) //show rewards and punishments records
{
	vector<taxi>::iterator iter;
	for (iter = this->tax.begin(); iter != this->tax.end(); iter++) 
	{
		if (temp_id == iter->car_id)
		{
			chart();
			gotoxy(7, 34);
			cout << "Rewards: " << iter->rewards << " (index)";
			gotoxy(9, 34);
			cout << "Punishments: " << iter->punishments << " (index)";
			gotoxy(18, 34);
			cout << "Press Enter to continue...";
			getch();
			system("cls");
			return;
		}
	}
}

int admin::read() //read all information
{
	fstream readfile("taxi.txt");
	int rows = 0;
	if (readfile)//Judge whether the file is empty
	{
		taxi t;
		if (!(readfile >> t))
		{
			return 1;
		}
		tax.push_back(t); 
		rows++;
		while (readfile >> t)//read all data push_back in Vector
		{
			rows++;
			tax.push_back(t); 
		}
		readfile.close();//close file
		return rows;
	}
	else
	{
		ofstream outfile;//create a file
		outfile.open("taxi.txt"); 
		if (!outfile.is_open())
		{
			cout << "ERROR!!!" << endl;
			return -1;
		}
		outfile.close();
	}
	return 2;
}
void admin::save()//save data 
{
	ofstream outfile("taxi.txt"); 
	vector<taxi>::iterator iter;
	for (iter = this->tax.begin(); iter != this->tax.end(); iter++)
	{
		outfile << iter->name_1 << "\t"<< iter->name_2 << "\t"
			<< iter->password << "\t" << iter->total_income
			<< "\t" << iter->rewards << "\t" << iter->punishments
			<< "\t" << iter->car_id << "\t" << iter->car_type << endl;
	}
	outfile.close();
}

int transf(char* temp) //transform string to integer
{
	int sum = 0;
	for (int i = 0; temp[i] != '\0'; i++)
	{
		sum = temp[i] - 48 + sum * 10;
	}
	return sum;
}

void enter(char* temp, int i, int s) //Input function(It can avoid all wrong input)
{
	char ch;
	int count = 0;
	while (1)
	{
		ch = getch();
		/*Legal input will be read*/
		if (s == 6)
		{
			if (ch > 47 && ch < 59 && count < i)
			{
				temp[count] = ch;
				cout << ch;
				count = count + 1;
			}
		}
		else
		{
			if (ch > 32 && ch < 125 && count < i)
			{
				temp[count] = ch;
				if (s == 0)
				{
					cout << "*";
				}
				else
				{
					cout << ch;
				}
				count = count + 1;
			}
		}
		/*Implement backspace operation*/
		if (ch == 8 && count > 0)
		{
			cout << "\b";
			cout << " ";
			cout << "\b";
			count = count - 1;
			temp[count] = '\0';
		}
		if (ch == 13)
		{
			break;
		}
	}
}

void gotoxy(int x, int y) //Move Cursor
{
	/*A very useful function to move the cursor position on the screen*/
	COORD coord;
	coord.X = y;
	coord.Y = x;
	/*Define a structure for storing location information*/
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	/*move the cursor position on the screen*/
}

void chart() // a chart is very useful
{
	/*Charts used in many places*/
	gotoxy(5, 30);
	cout << "**************************************************************" << endl;
	for (int x = 6; x < 20; x++)
	{
		gotoxy(x, 30);
		cout << "*                                                            *" << endl;
	}
	gotoxy(20, 30);
	cout << "**************************************************************" << endl;

}

void per(int x, int y) //A percentage visual loading display
{
	for (int i = 0; i <= 100; i++)
	{
		gotoxy(x, y);
		cout << setw(3) << i << "%";
		Sleep(10);
	}
}

void exit_system() //exit system
{
	/*Exit of the whole program*/
	system("color 2f");
	chart();
	gotoxy(12, 52);
	cout << "Saving data...";
	per(12, 66);
	gotoxy(12, 52);
	cout << "Good bye~~~           ";
	Sleep(1000);
	system("color 0f");
	gotoxy(20, 52);
	exit(0);
}