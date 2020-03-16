#include<iostream.h>

#include<fstream.h>

#include<stdlib.h>

#include<string.h>

#include<conio.h>

#include<stdio.h>

#include<process.h>

void login_user();
void register_newuser();
void forgot_usernamepassword();
class car_details {
   int carcode;
   int regno;
   char name[30];
   int model;
   char category[10];
   public:
      void heading() {
         cout << "\nCarcode " << " REGNo\t" << "  Name\t\t" << "Model\t" << "Category";
      }
   void display() {
      cout << endl << carcode << "\t" << regno << "\t" << name << "\t" << model << "\t" << category << endl;
   }
   int getcarcode() {
      return carcode;
   }
   char * getcategory() {
      return category;
   }
}
cars[3];
class route_details {
   int routecode;
   char from[20];
   char to[20];
   int distance;
   public:
      void heading() {
         cout << "\nRoutecode   " << "From\t" << " To\t " << "     Distance";
      }
   void display() {
      cout << endl << routecode << "\t" << from << "\t" << to << "\t" << distance << endl;
   }
   int getroutecode() {
      return routecode;
   }
   int getdistance() {
      return distance;
   }
}
routes[5];
class charge_details {
   int chargecode;
   int timefrom;
   int timeto;
   public:
      void heading() {
         cout << "\nCode" << " Timefrom " << " Timeto" << endl;
      }
   void display() {
      cout << endl << chargecode << "\t" << timefrom << "\t" << timeto << endl;
   }
   int gettimefrom() {
      return timefrom;
   }
   int gettimeto() {
      return timeto;
   }
}
charges[3];
class ride_information {
   int custcode;
   int carcode;
   int timing;
   int routecode;
   public:
      ride_information() {
         timing,
         custcode,
         routecode,
         carcode = 0;
      }
   public:
      void confirm_booking() {
         cout << "Select your Car" << endl;
         cin >> carcode;
         cout << "Ride timing" << endl;
         cin >> timing;
         cout << "Enter route";
         cin >> routecode;
      }
   int getcarcode() {
      return carcode;
   }
   int gettiming() {
      return timing;
   }
   int getroutecode() {
      return routecode;
   }
}
booking;
void cars_display(car_details[]);
void routes_display(route_details[]);
void charges_display(charge_details[]);
void book_ride(car_details[], route_details[], charge_details[], ride_information);
void calc_fare(car_details[], route_details[], charge_details[], ride_information);
void main() {
   int choice;
   cout << "\n\n^^^^^^^^^^^^^^^^^^^^^^^^CAB BOOKING SYSTEM^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
   cout << "\n\n**********************SRDF Vivekananda Vidyalaya************************\n\n";
   cout << "DONE BY :" << endl << "N.Vittal" << endl << "S.Prajoth" << endl;
   cout << "***********************************************************************\n\n\n";
   cout << "                      Welcome to login page                               \n\n";
   cout << "**********************          MENU       ****************************\n\n";
   cout << "1.LOGIN" << endl;
   cout << "2.REGISTER" << endl;
   cout << "3.FORGOT PASSWORD (or) USERNAME" << endl;
   cout << "\nEnter your choice :";
   cin >> choice;
   cout << endl;
   switch (choice) {
   case 1:
      login_user();
      break;
   case 2:
      register_newuser();
      break;
   case 3:
      forgot_usernamepassword();
      break;
   default:
      system("cls");
      cout << "You've made a mistake , give it a try again\n" << endl;
      main();
   }
   car_details cars[3] = {
      {
         9306,
         12172,
         "Tata Indica",
         2017,
         "Micro"
      },
      {
         9307,
         12173,
         "Toyota Etios",
         2018,
         "Prime"
      },
      {
         9308,
         12174,
         "Maruti Ertiga",
         2019,
         "SUV"
      }
   };

   route_details routes[5] = {
      {
         1001,
         "  Chennai",
         "Salem\t",
         364
      },
      {
         1002,
         "  Chennai",
         "Tiruchirapalli ",
         330
      },
      {
         1003,
         "  Chennai",
         "Tiruvannamalai ",
         195
      },
      {
         1004,
         "  Chennai",
         "Coimbatore ",
         507
      },
      {
         1005,
         "  Chennai",
         "Tiruchendur ",
         638
      }
   };

   charge_details charges[3] = {
      {
         8305,
         3,
         10
      },
      {
         8304,
         11,
         17
      },
      {
         8303,
         18,
         24
      }
   };

   char option;
   while (option == 'N' || 'n') {
      int choice = 0;
      cout << "1.Display available cars:\n";
      cout << "2.Display available Routes:\n";
      cout << "3.Display cab availability time:\n";
      cout << "4.Book your Ride\n";
      cout << "5.EXIT\n";
      cin >> choice;
      switch (choice) {
      case 1:
         cars_display(cars);
         break;
      case 2:
         routes_display(routes);
         break;
      case 3:
         charges_display(charges);
         break;
      case 4:
         book_ride(cars, routes, charges, booking);
         break;
      case 5:
         cout << "Thanks for using this program: ^_^ ^_^\n\n";
         clrscr();
         exit(0);
         break;
      }
      cout << "\nDo you want to exit?(Y/N)\n";
      cin >> option;
   }
   getch();
}
void showheaders(char title[50]) {
   cout << "************" << title << "************";
}
void cars_display(car_details cars[3]) {
   showheaders("Select Cars");
   cars[0].heading();
   for (int i = 0; i < 3; i++) {
      cars[i].display();
   }
}
void routes_display(route_details routes[5]) {
   showheaders("Select Routes");
   routes[0].heading();
   for (int i = 0; i < 5; i++) {
      routes[i].display();
      cout << "-------------------------------------------------";
   }
}
void charges_display(charge_details charges[3]) {
   showheaders("Select Charges");
   charges[0].heading();
   for (int i = 0; i < 3; i++) {
      charges[i].display();
      cout << "-------------------------------------------------";
   }
}
void book_ride(car_details cars[], route_details routes[], charge_details charges[], ride_information booking) {
   showheaders("Book your Riding");
   cout << endl;
   cout << "Select Car --->\n";
   cout << "Cars Available:" << endl << "Carcodes:" << endl << "Hope you have seen the details of carcodes listed below!" << endl;
   for (int i = 0; i < 3; i++) {
      cout << i + 1 << ")" << cars[i].getcarcode() << " " << endl;
   }
   cout << " Timing --->\n";
   cout << "   Timefrom " << "Timeto " << endl;
   for (int j = 0; j < 3; j++) {
      cout << cars[j].getcarcode() << "-->" << charges[j].gettimefrom() << "\t" << charges[j].gettimeto() << endl;
   }
   cout << " Select Route --->\n";
   cout << "Available Routes:" << endl << "Route Codes:" << endl << "Hope you have seen the details of routecodes listed below!" << endl;
   for (int k = 0; k < 5; k++) {
      cout << k + 1 << ")" << routes[k].getroutecode() << " " << endl;
   }
   booking.confirm_booking();
   calc_fare(cars, routes, charges, booking);
}
void calc_fare(car_details cars[], route_details routes[], charge_details charges[], ride_information booking) {
   cars[0].heading();
   for (int i = 0; i < 3; i++) {
      if (cars[i].getcarcode() == booking.getcarcode()) {
         cars[i].display();
      }
   }
   int distance = 0;
   routes[0].heading();
   for (int j = 0; j < 5; j++) {
      if (routes[j].getroutecode() == booking.getroutecode()) {
         distance = routes[j].getdistance();
         routes[j].display();
      }
   }
   int rate, DriverBeta = 0;
   for (int k = 0; k < 3; k++) {
      if (booking.gettiming() >= charges[k].gettimefrom() && booking.gettiming() <= charges[k].gettimeto()) {
         if (strcmpi(cars[k].getcategory(), "Micro") == 0) {
            rate = 9;
            DriverBeta = 250;
         }
         if (strcmpi(cars[k].getcategory(), "Prime") == 0) {
            rate = 11;
            DriverBeta = 350;
         }
         if (strcmpi(cars[k].getcategory(), "SUV") == 0) {
            rate = 15;
            DriverBeta = 450;
         }

      }
   }
   cout << "Rate per KM" << rate << endl;
   cout << "--------------------------------------------";
   cout << "\n Your ride fare for selected ride is=" << distance * rate << endl;
   cout << "--------------------------------------------" << endl;
   cout << " Extra Driver Beta alloted is=" << DriverBeta << endl;
   cout << "--------------------------------------------" << endl;
   cout << " Your total fare is=" << (distance * rate) + DriverBeta << endl;
   cout << "--------------------------------------------" << endl;
   cout << "A driver will be assigned to you shortly. Also, driver details will be" << endl << "sent through SMS and email." << endl;
}

void login_user() {
   int login_r = 0;
   char username_r[50], password_r[50], user_r[50], pass_r[50];
   system("cls");
   cout << "Enter the following details" << endl;
   cout << "USERNAME :";
   cin >> username_r;
   cout << "PASSWORD :";
   cin >> password_r;

   ifstream login_file("database_Cab_Booking.txt");
   while (login_file >> user_r >> pass_r) {
      if (strcmp(user_r, username_r) == 0) {
         if (strcmp(pass_r, password_r) == 0)

         {
            login_r = 1;
            system("cls");
         }
      }
   }
   login_file.close();
   if (login_r == 1) {
      cout << "\nHello " << user_r << "\nLOGIN SUCCESSFUL\nWe're glad that you're here.\nThanks for logging in\n";
      cin.get();
   } else {
      cout << "\nLOGIN ERROR\nPlease check your username and password ^_^\n";
      main();
   }
}

void register_newuser() {
   struct database {
      char Fname[40], Lname[40], mbno[12], email[30];

   }
   db;
   cout << "Welcome for the registration process:\n";
   system("cls");
   cout << "Enter your First Name: \n";
   cin >> db.Fname;
   cout << "Enter your Last Name: \n";
   cin >> db.Lname;
   cout << "Enter your Mobile Number: \n";
   cin >> db.mbno;
   cout << "Enter your Email: \n";
   cin >> db.email;
   cout << "Don't worry! We dont't share your email and mobile number" << endl << " to third party resources!!";
   char reg_username[50], reg_password[50];

   cout << "\n Enter the username: ";
   cin >> reg_username;
   cout << "\nEnter the password :";
   cin >> reg_password;

   ofstream register_file("database_Cab_Booking.txt", ios::app);
   register_file << reg_username << ' ' << reg_password << endl;
   system("cls");
   cout << "\nRegistration Sucessful\n";
   main();

}

void forgot_usernamepassword() {
   int forgot_user;
   system("cls");
   cout << "Forgotten your Username or Password? We're here for help\n";
   cout << "1.Search your id by username" << endl;
   cout << "2.Search your id by password" << endl;
   cout << "3.Main menu" << endl;
   cout << "Enter your choice :";
   cin >> forgot_user;
   switch (forgot_user) {
   case 1:
      {
         int fuser = 0;
         char search_user[50],
         user_f[50],
         pass_f[50];
         cout << "\nEnter your remembered username :";
         cin >> search_user;

         ifstream f_user("database_Cab_Booking.txt");
         while (f_user >> user_f >> pass_f) {
            if (strcmp(user_f, search_user) == 0) {
               char s_password[50];
               fuser = 1;
               strcpy(s_password, pass_f);
            }
         }
         f_user.close();
         if (fuser == 1) {
            char s_password[50];
            cout << "\n\nHurray, account found\n";
            cout << "\nYour password is " << s_password;

            main();
         } else {
            cout << "\nSorry, Your user ID is not found in our database\n";
            cout << "\n Kindly contact our Customer Care and visit our website for more help. \n";
            cin.get();
            main();
         }
         break;
      }
   case 2:
      {
         int fpass = 0;
         char search_pass[50],
         user1[50],
         pass1[50];
         cout << "\nEnter the remembered password :";
         cin >> search_pass;

         ifstream f_pass("database_Cab_Booking.txt");
         while (f_pass >> user1 >> pass1) {
            if (strcmp(search_pass, pass1) == 0) {
               char s_username[50];
               fpass = 1;
               strcpy(s_username, user1);
            }
         }
         f_pass.close();
         if (fpass == 1) {
            char s_username[50];
            cout << "\nYour password is found in the database \n";
            cout << "\nYour Id is : " << s_username;
            main();
         } else {
            cout << "Sorry, We cannot found your password in our database \n";
            cout << "\n Kindly contact our Customer Care\n";
            cin.get();
            main();
         }

         break;
      }

   case 3:
      {
         cin.get();
         main();
      }
   default:
      cout << "Sorry, You entered wrong choice. Kindly try again" << endl;
      forgot_usernamepassword();
   }
}

