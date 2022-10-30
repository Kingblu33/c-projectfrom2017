#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
/*
Creator:Demmar Allen


DESCRIPTION OF THE PROGRAM: This is appraisal system created for TNt Company limpted which allows
							supervisors of the company to enter grades and choose a employee of
							the month.This program also allows employees to view grades, give
							 employee of the month  and also calculate their netpay with or
							 without the inclusion of netpay.


*/

struct grades
{ // A structure called grades is created to store the values that will be given to each employee
	float Hay;
};
struct netpay
{ // A structure called net pay is created to store values that lead up to the value of netpay
	int Netpay;
	int week;
	int hours;
	int overtime;
	int deductions;
};

// declaration of functions
void login();
void login1();
int person();
int mainmenu();
//----------------------

COORD coord = {0, 0};
void gotoxy(int x, int y) // this funtion is used to move text to a different area of the screen
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	//-----------------------

	char F_name[][10] = {
		"Dwayne",
		"Cathy",
		"Haliando",
		"Marsha"

	};

	char M_name[][15] = {
		"Alhan", // The declaration of employees names in arrays
		"White",
		"Orlando",
		"Cool"

	};

	char L_name[][15] = {
		"Brayn",
		"Smith",
		"Brown",
		"Thompson"};

	//---------------------------
	gotoxy(30, 01);
	printf("\xdb\xdb\xdb\xdb\xdb\xdbWELCOME TO TNT COMPANY SYSTEM\xdb\xdb\xdb\xdb\xdb\xdb\n");

	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	system("CLS");

	FILE *fp, *Empname; // Declaration file pointers

	/// structure variable creation
	struct grades score1[5]; // Grade for punctuality
	struct grades score2[5]; // Grade for work ethics
	struct grades score3[5]; // Grade for teamwork
	struct grades score4[5]; // Grade for dependability
	struct grades score5[5]; // Grade for flexability
	struct grades average[5];
	struct grades empmonth;
	// store the value returned by the funtion mainmenu in the variable help
	int help = mainmenu();

	if (help == 1)
	{
		system("Cls");
		login(); // Call on the function login which prompts the user to enter a a and password.

		system("COLOR F2");

		int choice;

		printf(" \n  ::::::::::::::::::::::::::  |SUPERVISOR|  :::::::::::::::::::::::::: \n");
		gotoxy(30, 5);
		printf("1> Add Employee Grades");
		gotoxy(30, 07);
		printf("2>To choose employee of the month ");
		gotoxy(30, 9);
		printf("3> Exit System\n");
		gotoxy(30, 13);
		printf("Your Choice: ");

		choice = getche(); /*getche is a nonstandard function that which reads
							a single character from the keyboard and displays
						   immediately on output screen without waiting for enter key.
						   */

		switch (choice)

		{
		case '1':
			system("cls");

			int totalgrade; // stores value of all grades
			int answer;
			printf("Press 1 for %s %s %s\n", F_name[0], M_name[0], L_name[0]);
			printf("Press 2 for %s %s %s\n", F_name[1], M_name[1], L_name[1]);
			printf("Press 3 for %s %s %s \n", F_name[2], M_name[2], L_name[2]);
			printf("Press 4 for %s %s %s \n", F_name[3], M_name[3], L_name[3]);
			printf("Press 5 to exit\n");
			printf("Choice:   ");
			scanf("%d", &answer);

			while (answer >= 6)
			{
				system("cls");
				printf("Invalid Input\n");
				Sleep(1500);

				printf("Press 1 for %s %s %s\n", F_name[0], M_name[0], L_name[0]);
				printf("Press 2 for %s %s %s\n", F_name[1], M_name[1], L_name[1]);
				printf("Press 3 for %s %s %s \n", F_name[2], M_name[2], L_name[2]);
				printf("Press 4 for %s %s %s \n", F_name[3], M_name[3], L_name[3]);
				printf("Press 5 to exit\n");
				printf("Choice:   ");
				scanf("%d", &answer);
			}
			system("cls");

			for (int supcnt = 0; supcnt <= 5; supcnt++)
			{ // This for loop represents how many employees grades have been entered
				if (answer == 1)
				{
					system("cls");
					fp = fopen("Scores.txt", "w"); // opens the file scores.txt in write only mode

					printf("Grades entered so far:%d\n", supcnt);
					printf("Employee chosen: %s %s %s\n", F_name[0], M_name[0], L_name[0]);

					printf("Give employee grade out of 10 for each of the following characteristics \n");

					printf("Enter grade for punctuality:\n");
					scanf("%f", &score1[0].Hay); // the first value is read and stored in the array
					if (score1[0].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for punctuality:\n");
						scanf("%f", &score1[0].Hay);
					}
					if (score1[0].Hay <= 10)
					{ // this statment is excecuted if the  value that was entered is less than or equal to 10
						score1[0].Hay = score1[0].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score1[0].Hay);
						fprintf(fp, "%f\n", score1[0].Hay); // stores the value in the file scores.txt

						printf("Enter grade for Work ethics:\n\n");
						scanf("%f", &score2[0].Hay);
					}

					if (score2[0].Hay > 10)
					{ // this statement is execute if the value that was entered is greater than 10
						printf("INVALID INPUT\n");

						printf("Enter grade for Work Ethics:\n");
						scanf("%f", &score2[0].Hay);
					}
					if (score2[0].Hay <= 10)
					{
						score2[0].Hay = score2[0].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score2[0].Hay);
						fprintf(fp, "%f\n", score2[0].Hay);

						printf("Enter grade for Teamwork:\n\n");
						scanf("%f", &score3[0].Hay);
					}
					if (score3[0].Hay > 10)
					{
						printf("INVALID INPUT\n");
						printf("Enter grade for Teamwork:\n\n");
						scanf("%f", &score3[0].Hay);
					}
					if (score3[0].Hay <= 10)
					{
						score3[0].Hay = score3[0].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score3[0].Hay);
						fprintf(fp, "%f\n", score3[0].Hay);

						printf("Enter grade for dependability\n");
						scanf("%f", &score4[0].Hay);
					}
					if (score4[0].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for dependability\n");
						scanf("%f", &score4[0].Hay);
					}
					if (score4[0].Hay <= 10)
					{
						score4[0].Hay = score4[0].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score4[0].Hay);
						fprintf(fp, "%f\n", score4[0].Hay);

						printf("Enter grade for Flexability\n");
						scanf("%f", &score5[0].Hay);
					}
					if (score5[0].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for Flexability\n");
						scanf("%f", &score5[0].Hay);
					}
					if (score5[0].Hay <= 10)
					{
						score5[0].Hay = score5[0].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score5[0].Hay);
						fprintf(fp, "%f\n", score5[0].Hay);
					}

					Sleep(500);
					system("cls");

					printf("VALUES HAVE SUCESSFULLY BEEN STORED TO THE FILE\n");

					totalgrade = score1[0].Hay + score2[0].Hay + score3[0].Hay + score4[0].Hay + score5[0].Hay; // calculates all the values that were stored in the arrays and store it in a single variable

					average[0].Hay = totalgrade / 5;		  // calculates average by dividing the value by 5 then storing the value in the variable average
					printf("Average:%.2f\n", average[0].Hay); // prints the value of average on screen
					fprintf(fp, "%.2f\n", average[0].Hay);	  // stores value of average in the file score.txt
					supcnt++;								  // adds a value to supcnt
					fclose(fp);								  // closing the file
					printf("Press any key to continue\n");
					getch();
					system("cls");
					printf("RETURNING TO EMPLOYEE DECISION\n");
					Sleep(1000); // Sleep delays the time it takes to display another output on screen

					printf("Press 2 for %s %s %s\n", F_name[1], M_name[1], L_name[1]);
					printf("Press 3 for %s %s %s \n", F_name[2], M_name[2], L_name[2]);
					printf("Press 4 for %s %s %s \n", F_name[3], M_name[3], L_name[3]);
					printf("Press 5 to exit program\n");
					printf("Choice:   ");
					scanf("%d", &answer);
				}
				if (answer == 2)
				{
					system("cls");
					fp = fopen("Scores.txt", "a"); // opeining of the file scores.txt in append mode to ensure previous values that were entered for other employees isnt erased

					printf("Grades entered so far:%d\n", supcnt);
					printf("Employee chosen: %s %s %s\n", F_name[1], M_name[1], L_name[1]);

					printf("Give employee grade out of 10 for each of the following characteristics \n");

					printf("Enter grade for punctuality:\n");
					scanf("%f", &score1[1].Hay);
					if (score1[1].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for punctuality:\n");
						scanf("%f", &score1[1].Hay);
					}
					if (score1[1].Hay <= 10)
					{
						score1[1].Hay = score1[1].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score1[1].Hay);
						fprintf(fp, "%f\n", score1[1].Hay);

						printf("Enter grade for Work ethics:\n\n");
						scanf("%f", &score2[1].Hay);
					}

					if (score2[1].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for Work Ethics:\n");
						scanf("%f", &score2[1].Hay);
					}
					if (score2[1].Hay <= 10)
					{
						score2[1].Hay = score2[1].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score2[1].Hay);
						fprintf(fp, "%f\n", score2[1].Hay);

						printf("Enter grade for Teamwork:\n\n");
						scanf("%f", &score3[1].Hay);
					}
					if (score3[1].Hay > 10)
					{
						printf("INVALID INPUT\n");
						printf("Enter grade for Teamwork:\n\n");
						scanf("%f", &score3[1].Hay);
					}
					if (score3[1].Hay <= 10)
					{
						score3[1].Hay = score3[1].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score3[1].Hay);
						fprintf(fp, "%f\n", score3[1].Hay);

						printf("Enter grade for dependability\n");
						scanf("%f", &score4[1].Hay);
					}
					if (score4[1].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for dependability\n");
						scanf("%f", &score4[1].Hay);
					}
					if (score4[1].Hay <= 10)
					{
						score4[1].Hay = score4[1].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score4[1].Hay);
						fprintf(fp, "%f\n", score4[1].Hay);

						printf("Enter grade for Flexability\n");
						scanf("%f", &score5[1].Hay);
					}
					if (score5[1].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for Flexability\n");
						scanf("%f", &score5[1].Hay);
					}
					if (score5[1].Hay <= 10)
					{
						score5[1].Hay = score5[1].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score5[1].Hay);
						fprintf(fp, "%f\n", score5[1].Hay);
					}

					Sleep(500);
					system("cls");

					printf("VALUES HAVE SUCESSFULLY BEEN STORED TO THE FILE\n");

					totalgrade = score1[1].Hay + score2[1].Hay + score3[1].Hay + score4[1].Hay + score5[1].Hay;
					average[1].Hay = totalgrade / 5;
					printf("Average:%.2f\n", average[1].Hay);
					fprintf(fp, "%.2f\n", average[1].Hay);

					supcnt++;
					fclose(fp);
					printf("Press any key to continue\n");
					getch();
					system("cls");

					printf("RETURNING TO EMPLOYEE DECISION\n");
					Sleep(1000);

					printf("Press 3 for %s %s %s \n", F_name[2], M_name[2], L_name[2]);
					printf("Press 4 for %s %s %s \n", F_name[3], M_name[3], L_name[3]);
					printf("Choice:   ");
					scanf("%d", &answer);
				}

				if (answer == 3)
				{
					system("cls");
					fp = fopen("Scores.txt", "a");

					printf("Grades entered so far:%d\n", supcnt);
					printf("Employee chosen: %s %s %s\n", F_name[2], M_name[2], L_name[2]);

					printf("Give employee grade out of 10 for each of the following characteristics \n");

					printf("Enter grade for punctuality:\n");
					scanf("%f", &score1[2].Hay);
					if (score1[2].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for punctuality:\n");
						scanf("%f", &score1[2].Hay);
					}
					if (score1[2].Hay <= 10)
					{
						score1[2].Hay = score1[2].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score1[2].Hay);
						fprintf(fp, "%f\n", score1[2].Hay);

						printf("Enter grade for Work ethics:\n\n");
						scanf("%f", &score2[2].Hay);
					}

					if (score2[2].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for Work Ethics:\n");
						scanf("%f", &score2[2].Hay);
					}
					if (score2[2].Hay <= 10)
					{
						score2[2].Hay = score2[2].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score2[2].Hay);
						fprintf(fp, "%f\n", score2[2].Hay);

						printf("Enter grade for Teamwork:\n\n");
						scanf("%f", &score3[2].Hay);
					}
					if (score3[2].Hay > 10)
					{
						printf("INVALID INPUT\n");
						printf("Enter grade for Teamwork:\n\n");
						scanf("%f", &score3[2].Hay);
					}
					if (score3[2].Hay <= 10)
					{
						score3[2].Hay = score3[2].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score3[2].Hay);
						fprintf(fp, "%f\n", score3[2].Hay);

						printf("Enter grade for dependability\n");
						scanf("%f", &score4[2].Hay);
					}
					if (score4[2].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for dependability\n");
						scanf("%f", &score4[2].Hay);
					}
					if (score4[2].Hay <= 10)
					{
						score4[2].Hay = score4[2].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score4[2].Hay);
						fprintf(fp, "%f\n", score4[2].Hay);

						printf("Enter grade for Flexability\n");
						scanf("%f", &score5[2].Hay);
					}
					if (score5[2].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for Flexability\n");
						scanf("%f", &score5[2].Hay);
					}
					if (score5[2].Hay <= 10)
					{
						score5[2].Hay = score5[2].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score5[2].Hay);
						fprintf(fp, "%f\n", score5[2].Hay);
					}

					Sleep(500);
					system("cls");

					printf("VALUES HAVE SUCESSFULLY BEEN STORED TO THE FILE\n");

					totalgrade = score1[2].Hay + score2[2].Hay + score3[2].Hay + score4[2].Hay + score5[2].Hay;
					average[2].Hay = totalgrade / 5;
					printf("Average:%.2f\n", average[2].Hay);
					fprintf(fp, "%.2f\n", average[2].Hay);

					supcnt++;
					fclose(fp);
					printf("Press any key to continue\n");
					getch();
					system("cls");

					printf("RETURNING TO EMPLOYEE DECISION\n");
					Sleep(1000);
					printf("Press 4 for %s %s %s \n", F_name[3], M_name[3], L_name[3]);
					printf("Choice:   ");
					scanf("%d", &answer);
				}

				if (answer == 4)
				{
					system("cls");
					fp = fopen("Scores.txt", "a");

					printf("Grades entered so far:%d\n", supcnt);
					printf("Employee chosen: %s %s %s\n", F_name[3], M_name[3], L_name[3]);

					printf("Give employee grade out of 10 for each of the following characteristics \n");

					printf("Enter grade for punctuality:\n");
					scanf("%f", &score1[3].Hay);
					if (score1[3].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for punctuality:\n");
						scanf("%f", &score1[3].Hay);
					}
					if (score1[1].Hay <= 10)
					{
						score1[1].Hay = score1[1].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score1[1].Hay);
						fprintf(fp, "%f\n", score1[3].Hay);

						printf("Enter grade for Work ethics:\n\n");
						scanf("%f", &score2[3].Hay);
					}

					if (score2[3].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for Work Ethics:\n");
						scanf("%f", &score2[3].Hay);
					}
					if (score2[3].Hay <= 10)
					{
						score2[3].Hay = score2[3].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score2[3].Hay);
						fprintf(fp, "%f\n", score2[3].Hay);

						printf("Enter grade for Teamwork:\n\n");
						scanf("%f", &score3[3].Hay);
					}
					if (score3[3].Hay > 10)
					{
						printf("INVALID INPUT\n");
						printf("Enter grade for Teamwork:\n\n");
						scanf("%f", &score3[3].Hay);
					}
					if (score3[3].Hay <= 10)
					{
						score3[3].Hay = score3[3].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score3[3].Hay);
						fprintf(fp, "%f\n", score3[3].Hay);

						printf("Enter grade for dependability\n");
						scanf("%f", &score4[3].Hay);
					}
					if (score4[3].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for dependability\n");
						scanf("%f", &score4[3].Hay);
					}
					if (score4[3].Hay <= 10)
					{
						score4[3].Hay = score4[3].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score4[3].Hay);
						fprintf(fp, "%f\n", score4[3].Hay);

						printf("Enter grade for Flexability\n");
						scanf("%f", &score5[3].Hay);
					}
					if (score5[3].Hay > 10)
					{
						printf("INVALID INPUT\n");

						printf("Enter grade for Flexability\n");
						scanf("%f", &score5[3].Hay);
					}
					if (score5[3].Hay <= 10)
					{
						score5[3].Hay = score5[3].Hay * 100 / 10;
						printf("Grade after Calculation:%.2f\n", score5[3].Hay);
						fprintf(fp, "%f\n", score5[3].Hay);
					}

					Sleep(500);
					system("cls");

					printf("VALUES HAVE SUCESSFULLY BEEN STORED TO THE FILE\n");

					totalgrade = score1[3].Hay + score2[3].Hay + score3[3].Hay + score4[3].Hay + score5[3].Hay;
					average[3].Hay = totalgrade / 5;
					printf("Average:%.2f\n", average[3].Hay);
					fprintf(fp, "%.2f\n", average[3].Hay);

					supcnt++;
					fclose(fp);
					printf("Press any key to continue\n");
					getch();
					system("cls");

					printf("End of employee grading system\n");
					Sleep(1500);
					exit(0);
				}
				if (answer == 5)
				{
					printf("Exiting program\n");
					Sleep(2000);
					system("cls");
					exit(0);
				}
			}

			break; // leaves the first case

		case '2':
			system("cls"); // clears all output on screen
			printf("Which employee would you like to give employee of the month\n");

			Empname = fopen("names.txt", "w"); // opening of the file names.txt in write mode
			if (Empname != NULL)			   // if a employee of the month was already chosen
			{
				printf("Employee already chosen\n");
				printf("press any key to choose another emp of the month\n");
				getch();
				Sleep(500);
			}
			int answer_1;

			printf("Press 1 for %s %s %s\n", F_name[0], M_name[0], L_name[0]);
			printf("Press 2 for %s %s %s\n", F_name[1], M_name[1], L_name[1]);
			printf("Press 3 for %s %s %s \n", F_name[2], M_name[2], L_name[2]);
			printf("Press 4 for %s %s %s \n", F_name[3], M_name[3], L_name[3]);
			printf("Press 5 for none\n");
			printf("Press 6 to exit\n");
			printf("Choice:   ");
			scanf("%d", &answer_1);

			while (answer_1 > 6)
			{ // this is excecuted if user enters a value greater than 5
				printf("Invalid input try again\n");
				system("cls");
				printf("Press 1 for %s %s %s\n", F_name[0], M_name[0], L_name[0]);
				printf("Press 2 for %s %s %s\n", F_name[1], M_name[1], L_name[1]);
				printf("Press 3 for %s %s %s \n", F_name[2], M_name[2], L_name[2]);
				printf("Press 4 for %s %s %s \n", F_name[3], M_name[3], L_name[3]);
				printf("Press 5 for none\n");
				printf("Press 6 to exit\n");
				printf("Choice:   ");
				scanf("%d", &answer_1);
			}

			if (answer_1 == 1)
			{

				system("cls");
				fprintf(Empname, "%s %s %s\n", F_name[0], M_name[0], L_name[0]);				  // stores name in file names.txt
				printf("Employee of the month is :%s %s %s\n ", F_name[0], M_name[0], L_name[0]); // display employee chosen
				printf("Leaving employee decision\n");
				Sleep(500);
			}
			if (answer_1 == 2)
			{
				system("cls");
				fprintf(Empname, "%s %s %s\n", F_name[1], M_name[1], L_name[1]);
				printf("Employee of the month is :%s %s %s\n ", F_name[1], M_name[1], L_name[1]);
				printf("Leaving employee decision\n");
				Sleep(500);
			}
			if (answer_1 == 3)
			{
				system("cls");

				fprintf(Empname, "%s %s %s\n", F_name[2], M_name[2], L_name[2]);
				printf("Employee of the month is :%s %s %s\n ", F_name[2], M_name[2], L_name[2]);
				printf("Leaving employee decision\n");
				Sleep(500);
			}

			if (answer_1 == 4)
			{
				system("cls");
				fprintf(Empname, "%s %s %s", F_name[3], M_name[3], L_name[3]);
				printf("Employee of the month is :%s %s %s ", F_name[3], M_name[3], L_name[3]);
				printf("Leaving employee decision\n");
				Sleep(500);
			}

			if (answer_1 == 5)
			{
				system("cls");
				remove("names.txt"); // this is executed if the user doesnt wish to make anyone employee of the month
				printf("No employyee chosen\n");
				printf("Leaving employee decision\n");
				Sleep(500);
			}
			if (answer_1 == 6)
			{
				printf("EXITING\n");
				exit(0);
			}
			fclose(Empname); // closing of the file names.txt
			exit(0);
			break; // leaving case 2

		case '3':
			printf("\n LEaving program \n");
			Sleep(1000);
			system("cls");
			exit(0); // Leaves the system
			break;
		}
	}

	if (help == 2)
	{

		printf("WELCOME TO REGULAR EMPLOYEES MENUS");
		printf("\n\n\n\t\t\t\tPress any key to continue...");
		getch();
		system("CLS");
		login1(); // login for employees
		int choice_2;
		printf("\n::::::::::::::::::::::::::  |Employee|  ::::::::::::::::::::::::::\n");
		gotoxy(30, 02);
		printf("1> To view report");
		gotoxy(30, 05);
		printf("2>To fill out timesheet ");
		gotoxy(30, 07);
		printf("Your Choice:");
		choice_2 = getch();
		switch (choice_2)
		{
		case '1':
			fp = fopen("Scores.txt", "r");
			system("Cls");
			if (fp == NULL) // this statement is excecuted if no values are currently in the file
			{
				printf("No Grades have been entered in file\n");
				exit(1);
			}

			//----------------------------
			fscanf(fp, "%f", &score1[0].Hay);
			fscanf(fp, "%f", &score2[0].Hay);
			fscanf(fp, "%f", &score3[0].Hay);
			fscanf(fp, "%f", &score4[0].Hay);
			fscanf(fp, "%f", &score5[0].Hay);
			fscanf(fp, "%f", &score5[0].Hay);

			fscanf(fp, "%f", &score1[1].Hay);
			fscanf(fp, "%f", &score2[1].Hay); // reads that value that is stored in the file scores.txt
			fscanf(fp, "%f", &score3[1].Hay);
			fscanf(fp, "%f", &score4[1].Hay);
			fscanf(fp, "%f", &score5[1].Hay);

			fscanf(fp, "%f", &score1[2].Hay);
			fscanf(fp, "%f", &score2[2].Hay);
			fscanf(fp, "%f", &score3[2].Hay);
			fscanf(fp, "%f", &score4[2].Hay);
			fscanf(fp, "%f", &score5[2].Hay);

			fscanf(fp, "%f", &score1[3].Hay);
			fscanf(fp, "%f", &score2[3].Hay);
			fscanf(fp, "%f", &score3[3].Hay);
			fscanf(fp, "%f", &score4[3].Hay);
			fscanf(fp, "%f", &score5[3].Hay);
			//---------------------------------------------
			printf("EMPLOYEE's RECORD LIST (First Name, Last Name ,Middle Name, Punctuality, Work Ethics, Teamwork, Dependability, Flexability,\n");
			Sleep(500);
			printf("Press any key to view report\n");
			getch();
			system("cls");
			system("COLOR F1"); // changes screen color

			printf("\n::::::::::::::::::::::::::   |REPORT|    ::::::::::::::::::::::::::\n");
			printf("_______________________________________________________\n");
			printf("|%s%s\t", F_name[0], L_name[0]);
			printf("|%.2f\t", score1[0].Hay);
			printf("|%.2f\t", score2[0].Hay);
			printf("|%.2f\t", score3[0].Hay);
			printf("|%.2f\t", score4[0].Hay);
			printf("|%.2f|\n", score5[0].Hay);
			printf("|%s%s\t", F_name[1], L_name[1]);
			printf("|%.2f\t", score1[1].Hay);
			printf("|%.2f\t", score2[1].Hay);
			printf("|%.2f\t", score3[1].Hay);
			printf("|%.2f\t", score4[1].Hay);
			printf("|%.2f|\n", score5[1].Hay);
			printf("|%s%s\t", F_name[2], L_name[2]);
			printf("|%.2f\t", score1[2].Hay);
			printf("|%.2f\t", score2[2].Hay);
			printf("|%.2f\t", score3[2].Hay);
			printf("|%.2f\t", score4[2].Hay);
			printf("|%.2f|\n", score5[2].Hay);
			printf("|%s%s\t", F_name[3], L_name[3]);
			printf("|%.2f\t", score1[3].Hay);
			printf("|%.2f\t", score2[3].Hay);
			printf("|%.2f\t", score3[3].Hay);
			printf("|%.2f\t", score4[3].Hay);
			printf("|%.2f|", score5[3].Hay);
			printf("\n-------------------------------------------------------\n");
			// displays the values that were stored in file

			Empname = fopen("names.txt", "r");
			char c;
			if (Empname == NULL)
			{
			}
			c = getc(Empname); // stores the value that is in the file to the variable c
			printf("\n employee of the month:%c ", c);
			while (c != EOF)
			{ // this statement is excecuted if the value is not equal to the end of the file
				c = getc(Empname);
				printf("%c", c);
			}
			fclose(Empname);

			break;
		case '2':
			printf("Welcome to Time Sheet\n");
			system("cls");
			system("COLOR F0"); // changes system color
			int week;
			int rate = 15;
			int grosspay;

			int ans = person(); // stores the value from the function person to the variable ans

			printf("\nWhat Week of the Month is it?\n");
			printf("1....First Week\n");
			printf("2....Second Week\n");
			printf("3....Third Week\n");
			printf("4....Fourth week\n");
			printf("Choice:");

			scanf("%d", &week);

			struct netpay Monday;
			struct netpay tuesday;
			struct netpay wednesday;
			struct netpay thursday;
			struct netpay friday;
			int totalhours;

			system("CLS");

			if (week == 1)
			{
				printf("Currently entering values for :FIRST WEEK\n");
			}
			if (week == 2)
			{
				printf("Currently entering values for :SECOND WEEK\n");
			}
			if (week == 3)
			{
				printf("Currently entering values for :THIRD WEEK\n");
			}
			if (week == 4)
			{
				printf("Currently entering values for :FOURTH WEEK\n");
			}
			printf("Hours worked for a particular day cannot exceed 8\n");
			Sleep(500);
			if (week > 5)
			{
				printf("Wrong input start over\n");
				exit(0);
			}

			printf("Enter Hours worked Monday\n");
			scanf("%d", &Monday.hours);

			if (Monday.hours > 8)
			{ // this is exccuted if the value entered is greater than 8
				printf("invalid amount of hours\n");
				Sleep(500);
				printf("Hours cannot exceed 8\n");
				printf("Enter Hours worked Monday\n");
				scanf("%d", &Monday.hours);
			}
			if (Monday.hours <= 8)
			{ // this statement is excecuted if the value entered is less than or equal to 8
				printf("Enter Hours worked for tuesday\n");
				scanf("%d", &tuesday.hours);
			}
			if (tuesday.hours > 8)
			{
				printf("invalid amount of hours\n");
				printf("Hours cannot exceed 8");
				Sleep(500);
				printf("Enter Hours worked tuesday\n");
				scanf("%d", &tuesday.hours);
			}
			if (tuesday.hours <= 8)
			{
				printf("Enter Hours worked wednesday\n");
				scanf("%d", &wednesday.hours);
			}
			if (wednesday.hours > 8)
			{

				printf("invalid amount of hours\n");
				printf("Hours cannot exceed 8\n");
				Sleep(500);
				printf("Enter Hours worked wednesday\n");
				scanf("%d", &wednesday.hours);
			}
			if (wednesday.hours <= 8)
			{
				printf("Enter Hours worked Thursday\n");
				scanf("%d", &thursday.hours);
			}

			if (thursday.hours > 8)
			{

				printf("invalid amount of hours\n");
				printf("Hours cannot exceed 8\n");
				Sleep(500);
				printf("Enter Hours worked thursday\n");
				scanf("%d", &thursday.hours);
			}
			if (thursday.hours <= 8)
			{
				printf("Enter Hours worked friday\n");
				scanf("%d", &friday.hours);
			}
			if (friday.hours > 8)
			{

				printf("invalid amount of hours\n");
				printf("Hours cannot exceed 8\n");
				Sleep(500);
				printf("Enter Hours worked friday\n");
				scanf("%d", &friday.hours);
			}

			if (friday.hours <= 8)
			{

				totalhours = Monday.hours + tuesday.hours + wednesday.hours + thursday.hours + friday.hours; // takes the values that were stored in each variable and store it in one variable

				grosspay = rate * totalhours; // this calculates grosspay by taking rate and multiplying it by total hours then storing the value in the variable gross pay

				printf("%d", grosspay);
				system("cls");
			}
			int totalovertime;
			int overtimepay;

			struct netpay Overtime_1;
			struct netpay Overtime_2;
			struct netpay Overtime_3;
			struct netpay Overtime_4;
			struct netpay Overtime_5;

			printf("Entering overtime for Week:%d\n", week);

			printf("If you didnt do any extra hours just enter 0 in slots\n");

			printf("Enter Overtime Hours worked Monday\n");
			scanf("%d", &Overtime_1.overtime);

			if (Overtime_1.overtime > 4)
			{ // this statement is done if the value for overtime is greater than 4
				printf("invalid amount of Overtime hours\n");
				Sleep(500);
				printf(".");
				printf("Enter Hours worked Monday\n");
				scanf("%d", &Monday.hours);
			}
			if (Overtime_1.overtime <= 4)
			{ // this statemenet is excecuted if the value for overtime is less that or equal to 4
				printf("Enter Overtime Hours worked for tuesday\n");
				scanf("%d", &Overtime_2.overtime);
			}
			if (Overtime_2.overtime > 4)
			{
				printf("invalid amount of overtime hours\n");
				printf(".");
				Sleep(500);
				printf("Enter Hours worked tuesday\n");
				scanf("%d", &Overtime_2.overtime);
			}
			if (Overtime_2.overtime <= 4)
			{
				printf("Enter Overtime Hours worked wednesday\n");
				scanf("%d", &Overtime_3.overtime);
			}
			if (Overtime_3.overtime > 4)
			{

				printf("invalid amount of hours\n");
				printf(".");
				Sleep(500);
				printf("Enter Hours worked wednesday\n");
				scanf("%d", &wednesday.hours);
			}
			if (Overtime_3.overtime <= 4)
			{
				printf("Enter overtime Hours worked Thursday\n");
				scanf("%d", &Overtime_4.overtime);
			}

			if (Overtime_4.overtime > 4)
			{

				printf("invalid amount of hours\n");
				printf(".");
				Sleep(500);
				printf("Enter Hours worked thursday\n");
				scanf("%d", &thursday.hours);
			}
			if (Overtime_4.overtime <= 4)
			{
				printf("Enter Hours worked friday\n");
				scanf("%d", &Overtime_5.overtime);
			}
			if (Overtime_5.overtime > 4)
			{

				printf("invalid amount of hours\n");
				printf(".");
				Sleep(500);
				printf("Enter Hours worked friday\n");
				scanf("%d", &friday.hours);
			}

			if (Overtime_5.overtime <= 8)
			{
				totalovertime = Overtime_1.overtime + Overtime_2.overtime + Overtime_3.overtime + Overtime_4.overtime + Overtime_5.overtime; // calculates total hours worked by taking all the values stored in variable and storing it in one
				overtimepay = totalovertime * rate * 1.5;
				system("Cls");
			}
			struct netpay deduct;

			printf("Voluntary and involuntary deductions\n");
			printf("Value of non voluntariy dedductions will automatically calculate\n");

			printf("Enter value of non voluntary deductions\n");
			scanf("%d", &deduct.deductions);

			system("cls");
			int bonus = 3;

			struct netpay income[5];
			if (ans = 1)
			{									   // value from the function person
				Empname = fopen("names.txt", "r"); // opening of file names.txt in read only mode
				printf("Total Hours worked this week is:%d\n", totalhours);
				printf("Total Overtime Hours Worked this week is:%d\n", totalovertime);
				printf("Total deductions:%d\n", deduct.deductions);
				if (Empname == NULL)
				{																   // if the file is empty then this statement is excecuted
					income[0].Netpay = grosspay + overtimepay - deduct.deductions; // netpay is calculated without the inclusion of bonus
					printf("Mr.%s netpay for the week is:%d\n", L_name[0], income[0].Netpay);
				}
				if (Empname != NULL)
				{																		   // if the file contains a name
					income[0].Netpay = grosspay + overtimepay - deduct.deductions * bonus; // netpay is caculate by with bonus
					printf("Mr.%s netpay for the week with bonus is:%d\n", L_name[0], income[0].Netpay);
				}
				fclose(Empname);
				printf("Press any key to Exit program\n");
				getch();
				Sleep(2000);
				exit(0);
			}

			if (ans == 2)
			{
				Empname = fopen("names.txt", "r");
				printf("Total Hours worked this week is:%d\n", totalhours);
				printf("Total Overtime Hours Worked this week is:%d\n", totalovertime);
				printf("Total deductions:%d", deduct.deductions);
				printf("Gross pay before deductions:%d\n", grosspay);
				if (Empname == NULL)
				{
					income[0].Netpay = grosspay + overtimepay - deduct.deductions;
					printf("Mr.%s netpay for the week is:%d\n", L_name[1], income[1].Netpay);
				}
				if (Empname != NULL)
				{

					income[0].Netpay = grosspay + overtimepay - deduct.deductions * bonus;
					printf("Mr.%s netpay for the week with bonus is:%d\n", L_name[1], income[1].Netpay);
				}
				fclose(Empname);
				Sleep(2000);
				printf("Exiting Program\n");
				exit(0);
			}

			if (ans == 3)
			{

				Empname = fopen("names.txt", "r");
				printf("Total Hours worked this week is:%d\n", totalhours);
				printf("Total Overtime Hours Worked this week is:%d\n", totalovertime);
				printf("Total deductions:%d", deduct.deductions);
				printf("Gross pay before deductions:%d\n", grosspay);
				if (Empname == NULL)
				{
					income[0].Netpay = grosspay + overtimepay - deduct.deductions;
					printf("Mr.%s netpay for the week is:%d\n", L_name[2], income[2].Netpay);
				}
				if (Empname != NULL)
				{

					income[0].Netpay = grosspay + overtimepay - deduct.deductions * bonus;
					printf("Mr.%s netpay for the week with bonus is:%d\n", L_name[2], income[2].Netpay);
				}
				fclose(Empname);
				Sleep(2000);
				printf("Exiting Program\n");
				exit(0);
			}
			if (ans == 4)
			{
				Empname = fopen("names.txt", "r");
				printf("Total Hours worked this week is:%d\n", totalhours);
				printf("Total Overtime Hours Worked this week is:%d\n", totalovertime);
				printf("Total deductions:%d", deduct.deductions);
				printf("Gross pay before deductions:%d\n", grosspay);
				if (Empname == NULL)
				{
					income[0].Netpay = grosspay + overtimepay - deduct.deductions;
					printf("Mr.%s netpay for the week is:%d\n", L_name[3], income[3].Netpay);
				}
				if (Empname != NULL)
				{

					income[0].Netpay = grosspay + overtimepay - deduct.deductions * bonus;
					printf("Mr.%s netpay for the week with bonus is:%d\n", L_name[3], income[3].Netpay);
				}
				fclose(Empname);
			}
			if (ans > 4)
			{
				printf("INVALID INPUT\n");
				printf("exiting program\n");
				exit(0);
			}
		}
	}
	if (help == 3)
	{
		system("cls");
		printf("Come again soon\n");
		Sleep(1000);
		exit(0);
	}

	return 0;
}

void login()
{
	int a = 0, i = 0;
	char uname[10], c = ' ';
	char pword[10], code[10];
	char user[20] = "user";
	char pass[20] = "pass";
	do
	{

		printf("\n  ::::::::::::::::::::::::::Supervisor LOGIN  ::::::::::::::::::::::::::  ");
		printf(" \n                       ENTER USERNAME:-");
		scanf("%s", &uname);
		printf(" \n                       ENTER PASSWORD:-");

		while (i < 10)
		{
			pword[i] = getch();
			c = pword[i];
			if (c == 13)
				break;
			else
				printf("*");
			i++;
		}
		pword[i] = '\0';
		// char code=pword;

		i = 0;
		// scanf("%s",&pword);
		if (strcmp(uname, "employee") == 0 && strcmp(pword, "access") == 0) // this if statement checks if the password and username is correct
		{
			printf("  \n\n\n       WELCOME TO SUPERVISORS MENUS !!!! LOGIN IS SUCCESSFUL"); // if the username and password is correct then it gives user access to the system
			printf("\n LOADING PLEASE WAIT... \n");
			for (i = 0; i < 3; i++)
			{
				printf(".");
				Sleep(500);
			}
			printf("\n\n\n\t\t\t\tPress any key to continue...");
			getch();
			break;
		}
		else // this statement is performed if username and password is incorrect
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
			a++;

			getch();
		}
	} while (a <= 2);
	if (a > 2) // this statemenet is executed if username and password is incorrect more than 4 times
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();
		exit(0);
	}
	system("cls");
}

int mainmenu()
{
	int choice;

	gotoxy(30, 00);
	printf("\xdb\xdb\xdb\xdb\xdb\xdbGENERAL MENUS\xdb\xdb\xdb\xdb\xdb\xdb\n");
	gotoxy(30, 02);
	printf("|::::::Press 1 for supervisors menus:::::|");
	gotoxy(30, 05);
	printf("|::::::Press 2 for Regular Employees Menus:::::|");
	gotoxy(30, 9);
	printf("|:::::press 3 to exit program at any time::::::|");
	gotoxy(30, 11);
	scanf("%d", &choice);

	return choice; // the function main menu displays 3 options and returns the value of choice
}

void login1()
{
	int a = 0, i = 0;
	char uname[20], c = ' ';
	char pword[20], code[10];
	char user[20] = "user";
	char pass[20] = "pass";
	do
	{

		printf("\n  ::::::::::::::::::::::::::  LOGIN  ::::::::::::::::::::::::::  ");
		printf(" \n                       ENTER USERNAME:-");
		scanf("%s", &uname);
		printf(" \n                       ENTER PASSWORD:-");
		while (i < 10)
		{
			pword[i] = getch();
			c = pword[i];
			if (c == 13)
				break;
			else
				printf("*");
			i++;
		}
		pword[i] = '\0';

		i = 0;
		if (strcmp(uname, "employee") == 0 && strcmp(pword, "access") == 0)
		{
			printf("  \n\n\n       WELCOME TO EMPLOYEE MENUS !!!! LOGIN Was SUCCESSFUL");
			printf("\n LOADING PLEASE WAIT... \n");
			for (i = 0; i < 3; i++)
			{
				printf(".");
				Sleep(500);
			}
			printf("\n\n\n\t\t\t\tPress any key to continue...");
			getch();
			break;
		}
		else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
			a++;

			getch();
		}
	} while (a <= 2);
	if (a > 2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();
		exit(0);
	}
	system("cls");
}

int person()
{
	//-----------------------
	char F_name[][10] = {
		"Dwayne",
		"Cathy",
		"Haliando",
		"Marsha"

	};

	char M_name[][15] = {
		"Alhan", // redeclaration of employees names in arrays
		"White",
		"Orlando",
		"Cool"

	};

	char L_name[][15] = {
		"Brayn",
		"Smith",
		"Brown",
		"Thompson"};
	//-------------------------

	int answer_2;
	printf("Press 1 for %s %s %s\n", F_name[0], M_name[0], L_name[0]);
	printf("Press 2 for %s %s %s\n", F_name[1], M_name[1], L_name[1]);
	printf("Press 3 for %s %s %s \n", F_name[2], M_name[2], L_name[2]);
	printf("Press 4 for %s %s %s \n", F_name[3], M_name[3], L_name[3]);
	printf("Choice:   ");
	scanf("%d", &answer_2);

	system("cls");
	return answer_2; // the function person gives user 4 options and  returns the value of answer
}
