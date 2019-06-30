#ifndef HEADER_H
#define HEADER_H
#include<string>
#include<vector>
#include<tuple>
#include<fstream> 

class employee;
class visitor;
class vehicle;
class gas_vehicle;
class electric_vehicle;
class hybrid_vehicle;

int entry(const char *);

class data {
    protected:
    static std::vector<employee>e;
    static std::vector<gas_vehicle> gv;
    static std::vector<electric_vehicle> ev;
    static std::vector<hybrid_vehicle> hv;
    void virtual null()=0;
    int entry(const char *); 
    void record_add();
    void record_delete();
    void make(const char *);
    void update(const char *);
    
    public:
    void gas_display() const ;
    void electric_display() const ;
    void hybrid_display() const;
    void record_display() const;
    void search_emp() const;
    void quan_add(std::string,vehicle *,int);
    void quan_change(std::string,int);
    void search() const;
    void buy();
    
};

class vehicle {
    protected:
    std::string brand;
    std::string model;
    std::string color;
    std::string type;
    float weight;

    public:
        vehicle();
        vehicle(std::string,std::string,std::string,std::string,float);
        virtual void donothing();
};

class gas_vehicle: public vehicle {
    float fuel_tank_size;
    int quantity;
    long long int cost;

    public:
        gas_vehicle();
        gas_vehicle(std::string,std::string,std::string,std::string,float,float,int,long long int);
        static std::tuple<gas_vehicle,bool,int>add_gas_vehicle(const std::vector<gas_vehicle>&); 
        void display();
        friend void data::gas_display() const ;
        friend void operator >> (std::ifstream &,gas_vehicle &);
        friend void operator << (std::ofstream &,gas_vehicle &);
        friend void data::quan_add(std::string,vehicle *,int);
        friend void data::quan_change(std::string,int);
        friend void data::search() const;  
};

class electric_vehicle: public vehicle {
    float energy_storage;
    int quantity;
    long long int cost;

    public:
        electric_vehicle();
        electric_vehicle(std::string,std::string,std::string,std::string,float,float,int,long long int);
        static std::tuple<electric_vehicle,bool,int>add_electric_vehicle(const std::vector<electric_vehicle>&);
        void display();
        friend void data::electric_display() const ;
        friend void operator >> (std::ifstream &,electric_vehicle &);
        friend void operator << (std::ofstream &,electric_vehicle &);
        friend void data::quan_add(std::string,vehicle *,int);
        friend void data::quan_change(std::string,int);
        friend void data::search() const;
};

class hybrid_vehicle: public vehicle {
    float fuel_tank_size;
    float energy_storage;
    int quantity;
    long long int cost;

    public:
        hybrid_vehicle();
        hybrid_vehicle(std::string,std::string,std::string,std::string,float,float,float,int,long long int);
        static std::tuple<hybrid_vehicle,bool,int>add_hybrid_vehicle(const std::vector<hybrid_vehicle>&);
        void display();
        friend void data::hybrid_display() const;
        friend void operator >> (std::ifstream &,hybrid_vehicle &);
        friend void operator << (std::ofstream &,hybrid_vehicle &);
        friend void data::quan_add(std::string,vehicle *,int);
        friend void data::quan_change(std::string,int);
        friend void data::search() const;
};

class pak_motors: public data{   
    public:
        pak_motors();
        void main_menu();
        void login();
        bool emp_auth();
        void sign_up();
        void null();

        
};

// EMPLOYEE CLASS 
class employee: public data {
    std::string fname;
    std::string lname;
    std::string designation;
    std::string username;
    std::string password;
        
        protected: 
        void change_details(const std::vector<employee>&) ;
        
        public:
        employee();
        employee(std::string, std::string , std::string , std::string , std::string);
        void null();
        static employee setter(const std::vector<employee>&);
        friend void operator >> (std::ifstream &,employee &);
        friend void operator << (std::ofstream &,employee &);
        bool authentication(std::string,std::string);
        void main_menu(const std::vector<employee>&);
        friend void data::search_emp() const;
        friend void data::quan_add(std::string,vehicle *,int);
};

// CUSTOMER CLASS 
class customer: public data {
    public:
        customer();
        void null();
        void login();
        void record_add();   
        void record_delete();
        void quan_add();
        void quan_change();
        void search_emp();
};

void make_console();

#endif