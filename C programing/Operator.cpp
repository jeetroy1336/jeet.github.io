#include<iostream>
using namespace std;

class Code
    {
        int day,month,year;

        public :

        // Constructors
        Code()
            {
                day = 0;
                month = 0;
                year = 0;
            }
        Code(int day,int month, int year)
            {
                this->day = day;
                this->month = month;
                this->year = year;
            }


        void setDay(int day)
            {
                this->day = day;
            }
        void setMonth(int month)
            {
                this->month = month;
            }
        void setYear(int year)
            {
                this->year = year;
            }
    
        int getDay()
            {
                return day;
            }
        int getMonth()
            {
                return month;
            }
        int getYear()
            {
                return year;
            }
        Code operator+(Code plus)
            {
                Code temp;

                temp.day = this->day + plus.day;
                temp.month = this->month + plus.month;
                temp.year = this->year + plus.year;
        
                return temp;
            }
        Code operator-(Code minus)
            {
                Code temp;

                temp.day = this->day - minus.day;
                temp.month = this->month - minus.month;
                temp.year = this->year - minus.year;
        
                return temp;
            }
        Code operator++()
            {
                // Pending
            }
    
};
int main()
    {
        system("CLS");

        Code s1(15, 11, 2002),s2(2, 1, 2);

        Code s3 = s1 + s2;
        //Displaying date
        cout<<"Date = "<<s1.getDay()<<":"<<s1.getMonth()<<":"<<s1.getYear()<<endl;

        //Displaying date after addition
        cout<<"New date = "<<s3.getDay()<<":"<<s3.getMonth()<<":"<<s3.getYear();
        return 0;
    }
