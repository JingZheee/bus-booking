#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <array>
using namespace std;

class Bus{
    protected:
        string date;
        string busID;
        string departureLocation;
        string arrivalLocation;
        string plateNum;
        int maxSeats;
        int filledSeats;
        string departTime;
        double price;
        string busType;

    public:
        Bus(string d="0/0/0",string id = "123", string _departLocation = "unknown", string arrival="unknown", string _departTime="00:00", string plate="", int max=0, int filled=0, double p=0, string bt = "unknown"){
            date = d;
            busID = id;
            departureLocation = _departLocation;
            arrivalLocation = arrival;
            departTime = _departTime;
            plateNum = plate;
            maxSeats = max;
            filledSeats = filled;
            price = p;
            busType = bt;
        }
        void setBusID(string id){
            busID = id;
        }
        void setDeparture(string d){
            departureLocation = d;
        }
        void setArrival(string a){
            arrivalLocation = a;
        }
        void setPlateNum(string p){
            plateNum = p;
        }
        void setMax(int m){
            maxSeats = m;
        }
        void setFilled(int f){
            filledSeats = f;
        }
        void setDepart(string depart){
            departTime = depart;
        }
        void setPrice(double p){
            price = p;
        }

        string getBusID(){
            return busID;
        }

        string getDepartLocation(){
            return departureLocation;
        }
        string getArrival(){
            return arrivalLocation;
        }
        string getPlateNum(){
            return plateNum;
        }
        int getMax(){
            return maxSeats;
        }
        int getFilled(){
            return filledSeats;
        }
        string getDepartTime(){
            return departTime ;
        }
        double getPrice(){
            return price;
        }

        string getDate(){
            return date;
        }

        string getBusType(){
            return busType;
        }

        friend class Admin;

};

class PremiumBus : public Bus{
    private : 
        string seatType = "Comfy Cushion Seats";

    public :
        string getSeatType(){
            return seatType;
        }
        void setSeatType(string s){
            seatType = s;
        }
        virtual void printAbout() = 0;
        PremiumBus(string d="0/0/0",string id = "123", string _departLocation = "unknown", string arrival="unknown", string _departTime="00:00", string plate="", int max=0, int filled=0, double p=0, string s = "noSeatType", string bt = "unknown"){
            date = d;
            busID = id;
            departureLocation = _departLocation;
            arrivalLocation = arrival;
            departTime = _departTime;
            plateNum = plate;
            maxSeats = max;
            filledSeats = filled;
            price = p;
            busType = bt;
            seatType = s;
        }
    

};

class StandardBus : public Bus{
    private : 
        double discount;

    public :
        double getDiscount(){
            return discount;
        }
        void setDiscount(double d){
            discount = d;
        }
        StandardBus(string d="0/0/0",string id = "123", string _departLocation = "unknown", string arrival="unknown", string _departTime="00:00", string plate="", int max=0, int filled=0, double p=0, double dis = 0, string bt = "unknown"){
            date = d;
            busID = id;
            departureLocation = _departLocation;
            arrivalLocation = arrival;
            departTime = _departTime;
            plateNum = plate;
            maxSeats = max;
            filledSeats = filled;
            price = p;
            busType = bt;
            discount = dis;
        }
    

};

class ExpressBus : public PremiumBus{
    private : 
        string movies[2] = {"Top Gun Maverick", "Cars 2"};

    public :
        string * getMovies(){
            return movies;
        }
        void setMovies(std::array<string,2> m){
            for(int i = 0; i < 2; i++){
                movies[i] = m[i];
            }
        }
        void printAbout(){
            cout << "Express Bus is a premium class bus equipped with movies you can enjoy on the way to your destination!" << endl;
        }
        ExpressBus(string d="0/0/0",string id = "123", string _departLocation = "unknown", string arrival="unknown", string _departTime="00:00", string plate="", int max=0, int filled=0, double p=0, std::array<string,2> m = {"movie1", "movie 2"}, string bt = "unknown"){
            date = d;
            busID = id;
            departureLocation = _departLocation;
            arrivalLocation = arrival;
            departTime = _departTime;
            plateNum = plate;
            maxSeats = max;
            filledSeats = filled;
            price = p;
            busType = bt;
            setMovies(m);
        }
};

class SonarBus : public PremiumBus{
    private : 
        bool toilet;

    public :
        bool getToiletStatus(){
            return toilet;
        }
        void setToilet(bool t){
            toilet = t;
        }
        void printAbout(){
            cout << "Sonar Bus is a premium class bus equipped with a toilet to take away all of your inconveniences!" << endl;
        }
        SonarBus(string d="0/0/0",string id = "123", string _departLocation = "unknown", string arrival="unknown", string _departTime="00:00", string plate="", int max=0, int filled=0, double p=0, bool t = false, string bt = "unknown"){
            date = d;
            busID = id;
            departureLocation = _departLocation;
            arrivalLocation = arrival;
            departTime = _departTime;
            plateNum = plate;
            maxSeats = max;
            filledSeats = filled;
            price = p;
            toilet = t;
            busType = bt;
        }
};

class Passenger{
    private:
        string name;
        int age;
        string phoneNum;
        string ic;
        vector <string> bookedId;
    public:
        void setBookedid(string id){
            bookedId.push_back(id);
        };
        Passenger(string _name, int _age, string _phoneNum, string _ic){
            name = _name;
            age = _age;
            phoneNum = _phoneNum;
            ic = _ic;
        }


};

class Admin {
    private:
        string adminID;
        string password;
    public:
        Admin(){
            adminID = "admin";
            password = "12345";
        }
        bool logIn(){
            string id;
            string pass;
            cout << "Enter ID : ";
            cin >> id;
            cout << "Enter Password : ";
            cin >> pass;

            return ((id == adminID) && (password == pass));    
        }
        Bus addBus(){
            string date;
            string busID;
            string departureLocation;
            string arrivalLocation;
            string plateNum;
            int maxSeats;
            int filledSeats = 0;
            string departTime;
            double price;
            int busTypeChoice;

            cout << "Enter the date for the bus: ";
            getline(cin, date);
            cout << "Enter the busID for the bus: ";
            getline(cin, busID);
            cout << "Enter the departure location for the bus: ";
            getline(cin, departureLocation);
            cout << "Enter the arrival location for the bus: ";
            getline(cin, arrivalLocation);
            cout << "Enter the plate number for the bus: ";
            getline(cin, plateNum);
            cout << "Enter the depart time for the bus: ";
            getline(cin, departTime);
            cout << "Enter the maximum capacity for the bus: ";
            cin >> maxSeats;
            cout << "Enter the ticket price for the bus: ";
            cin >> price;
            cout << "Choose the type of bus to add: " << endl;
            cout << "[0] Standard Bus" << endl;
            cout << "[1] Express Bus" << endl;
            cout << "[2] Sonar Bus" << endl;
            cout << "Choice : ";
            cin >> busTypeChoice;
            system("pause");
            if(busTypeChoice == 0){
                double discount;
                cout << "Enter member discount for the ticket: ";
                cin >> discount;
                StandardBus newBus(date, busID, departureLocation, arrivalLocation, departTime, plateNum, maxSeats, filledSeats, price, discount, "Standard Bus");
                return newBus;
            }
            else if(busTypeChoice == 1){
                string movies[2];
                for (int i = 0; i < 2; i++){
                    cout << "Enter movie " << i+1 << " name: ";
                    cin >> movies[i];
                }
                ExpressBus newBus(date, busID, departureLocation, arrivalLocation, departTime, plateNum, maxSeats, filledSeats, price, {"Top Gun : Maverick", "Cars 2"}, "Express Bus");
                return newBus;
            }
            else if(busTypeChoice == 2){
                bool toiletAvailability;
                cout << "Is toilet available ?";
                cout << "[0] No" << endl;
                cout << "[1] Yes" << endl;
                cin >> toiletAvailability;
                SonarBus newBus(date, busID, departureLocation, arrivalLocation, departTime, plateNum, maxSeats, filledSeats, price, toiletAvailability, "Sonar Bus");
                return newBus;
            }
            Bus newBus(date, busID, departureLocation, arrivalLocation, departTime, plateNum, maxSeats, filledSeats, price);
            return newBus;
            
        }
};

class Payment {
    private:
        double amount;
        bool status;
    public:
        Payment(double a){
            amount = a;
        }
        void makePayment(){
            char ans;
            cout << "Do you want to make payment?(Y/N): ";
            cin >> ans;
            if(ans == 'Y'){
                status = true;
            } else {
                status = false;
            }
        }
        bool getStatus(){
            return status;
        }

};

class Booking{
    private:
        Passenger *passenger;
        Bus *bus;
        string bookingId;
        double price;
        

    public:
        Payment payment;
        Booking(Passenger *p, Bus *b, double pri, string id):payment(pri){
            passenger = p;
            bus = b;
            bookingId = id;
        }
        
        bool bookSeat(){
            payment.makePayment();
            if(payment.getStatus() == 1){
                int newFilled = bus->getFilled() + 1;
                bus->setFilled(newFilled);
                passenger->setBookedid(bookingId);
                cout << "Your purchase was successful" << endl;
                system("pause");
                return true;
            } else {
                cout << "The payment was fail. Please make the purchase again." << endl;
                return false;
            }
            
        }
        void print(){
            cout << "Booking id: " << bookingId << endl;
            cout << "Bus information" << endl;
            cout << "----------------------------------" << endl;
            cout << "Date: " << bus->getDate() << endl;
            cout << "Depature location: " << bus->getDepartLocation() << endl;
            cout << "Arrival location: " << bus->getArrival() << endl;
            cout << "Depature time: " << bus->getDepartTime() << endl;
            cout << "Plate Number: " << bus->getPlateNum() << endl;

        }

};

void showSchedule(vector<Bus> &bus){
            cout << "---------------" << endl;
            cout << "BUS SCHEDULE" << endl;
            cout << "---------------" << endl;
            cout << left << setw(5) << " ";
            cout << left << setw(15) << "Name";
            cout << left << setw(15) << "Date";
            cout << left << setw(15) << "Departure";
            cout << left << setw(5) << " ";
            cout << left << setw(15) << "Arrival";
            cout << left << setw(9) << "Price";
            cout << left << setw(5) << "Seats";
            cout << endl;
            for (int i = 0; i < bus.size() ; i++){
                cout << left << setw(1) << "[" << right << setw(2) << i << left << setw(2) << "]";
                cout << left << setw(15) << bus[i].getBusType();
                cout << left << setw(15) << bus[i].getDate();
                cout << left << setw(15) << bus[i].getDepartLocation();
                cout << left << setw(5) << "->" ;
                cout << left << setw(15) << bus[i].getArrival();
                cout << left << setw(2) << "RM" << setw(7) << bus[i].getPrice();
                cout << left << setw(2) << bus[i].getFilled() << setw(1) << "/" << setw(2) << bus[i].getMax();
                cout << endl;

    }
}

int mainPage(){
    
    int selection;
    cout << "Please choose user : " << endl;
    cout << "Press 1 to enter as guest" << endl;
    cout << "Press 2 to enter as admin" << endl;
    cout << "Press 3 to exit" << endl;

    cout << "\nPress 1 or 2 or 3 to continue...." << endl;
    cin >> selection;
    return selection;
}

int adminPage(){
    int selection;
    cout << "\nPlease choose action : " << endl;
    cout << "Press 1 to see the schedule" << endl;
    cout << "Press 2 to add the bus schedule" << endl;

    cout << "\nPress 1 or 2 or 3 to continue...." << endl;
    cin >> selection;
    cin.ignore();
    return selection;
}

int userPage(){
    int selection;
    cout << "\nPlease choose action : " << endl;
    cout << "Press 1 to see the schedule" << endl;
    cout << "Press 2 to check your booking info" << endl;

    cout << "\nPress 1 or 2 to continue...." << endl;
    cin >> selection;
    return selection;
}

int main()
{
    Passenger passenger("Adam", 20, "0123488816", "031111140000");
    Admin admin;
    int selection, busNum;
    int bookingId = 1;
    vector<Booking>bookings;
    vector<Bus>bus;
    bus.push_back(StandardBus("31/5/2023","P100","Johor","Kuala Lumpur", "3:30pm","SYM187",40, 24, 35.50, 3, "Standard Bus"));
    bus.push_back(ExpressBus("2/6/2023","P101","Johor","Kelantan", "3:30pm","SYM187",45, 12, 70.50, {"Top Gun : Maverick", "Cars 2"}, "Express Bus"));
    bus.push_back(SonarBus("1/6/2023","P102","Johor","Penang", "10:00am","SYM187",40, 24, 80.50, true, "Sonar Bus"));

    main:
        system("cls");
        selection = mainPage();

    if (selection == 1){
        system("cls");
        selection = userPage();
        if(selection == 1){
            system("cls");
            bool status;
            showSchedule(bus);
            cout << "\nPlease select the bus you want to buy:" << endl;
            cin >> busNum;
            Booking booking(&passenger, &bus[busNum], bus[busNum].getPrice(), to_string(bookingId));
            status = booking.bookSeat();
            if(status){
                bookings.push_back(booking);
                bookingId++;
                goto main;
            } else {
                goto main;
            }
        } else if(selection == 2){
            system("cls");
            for(int i = 0; i < bookings.size(); i++){
                bookings[i].print();
            }
            system("pause");
            goto main;
        }
        
    }else if (selection == 2) {
        system("cls");
        while(!admin.logIn()){
            cout << "Wrong ID or password\n" << endl;
            cout << "Please enter again\n" << endl;
        } 
        system("cls");
        selection = adminPage();
        if(selection == 1){
            system("cls");
            showSchedule(bus);
            cout << "\n Press any key to return to main page or press 1 to exit";
            cin >> selection;
            if(selection == 1){
                goto exit;
            } else {
                goto main;
                
            }
        } else if(selection ==2){
            system("cls");
            bus.push_back(admin.addBus());
            cout << "\nThe bus information is successfully added." << endl;
            goto main;
        } else if(selection ==3){
            goto main;
        }


    } else if(selection == 3){
        goto exit;
    }
    exit:
        cout << "Thanks for using the bus sytem. Have a safe trip!";
}

