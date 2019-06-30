#include"header.h" 
#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<fstream>
#include<windows.h>
#include<conio.h>

void make_console() {
    system("cls");
    pak_motors p;
    p.main_menu();
}
 
//VEHILE HEIRARCHY
vehicle::vehicle(){}

vehicle::vehicle(std::string br,std::string mo,std::string co,std::string ty,float wei)
:brand(br),model(mo),color(co),type(ty),weight(wei){}

void vehicle::donothing(){}
    
    //GAS_VEHICLE
gas_vehicle::gas_vehicle():vehicle(){}

gas_vehicle::gas_vehicle(std::string br,std::string mo,std::string co,std::string ty,float wei,float fts,int qua,long long int cos)
:vehicle(br,mo,co,ty,wei),fuel_tank_size(fts),quantity(qua),cost(cos){}

std::tuple<gas_vehicle,bool,int>gas_vehicle::add_gas_vehicle(const std::vector<gas_vehicle>&gv) {
    bool token;
    gas_vehicle temp;

    std::cout << "Enter brand: " ;
    std::cin >> temp.brand ;
    std::cout << "Enter model: " ;
    std::cin >> temp.model ;
    std::cout << "Enter color: " ;
    std::cin >> temp.color ;
    std::cout << "Enter type: " ;
    std::cin >> temp.type ;
    std::cout << "Enter weight: " ;
    std::cin >> temp.weight ;
    std::cout << "Enter fuel tank capacity: " ;
    std::cin >> temp.fuel_tank_size ;
    std::cout << "Enter quantity: " ;
    std::cin >> temp.quantity ;
    std::cout << "Enter cost: " ;
    std::cin >> temp.cost ;

    if(gv.size()==0) {
        token=false;
        return std::make_tuple(temp,token,0);
    }

    for(int i=0; i<gv.size(); i++) {
        if(temp.brand==gv[i].brand && temp.model==gv[i].model && temp.color == gv[i].color) {
            token=true;
            return std::make_tuple(temp,token,i);
        } else {
            continue ;
        }
    } 

    token=false;
    return std::make_tuple(temp,token,0);
}

void gas_vehicle::display() {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Weight: " << weight << std::endl;
        std::cout << "Fuel tank size: " << fuel_tank_size << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Cost: " << cost << std::endl ;
        std::cout << std::endl;
}

void operator >>(std::ifstream &read, gas_vehicle &g) {
    read >> g.brand >> g.model >> g.color >> g.type >> g.weight >> g.fuel_tank_size >> g.quantity >> g.cost ;
} 

void operator <<(std::ofstream &write, gas_vehicle &g) {
    write << g.brand << " " << g.model << " " << g.color << " " << g.type << " " << g.weight << " " << g.fuel_tank_size << " " << g.quantity << " " << g.cost << std::endl ;
}

    //ELECTRIC_VEHICLE
electric_vehicle::electric_vehicle():vehicle(){}

electric_vehicle::electric_vehicle(std::string br,std::string mo,std::string co,std::string ty,float wei, float es, int qua , long long int cos)
:vehicle(br,mo,co,ty,wei),energy_storage(es),quantity(qua),cost(cos){}   

std::tuple<electric_vehicle,bool,int>electric_vehicle::add_electric_vehicle(const std::vector<electric_vehicle>&ev) {
    bool token;
    electric_vehicle temp;

    std::cout << "Enter brand: " ;
    std::cin >> temp.brand ;
    std::cout << "Enter model: " ;
    std::cin >> temp.model ;
    std::cout << "Enter color: " ;
    std::cin >> temp.color ;
    std::cout << "Enter type: " ;
    std::cin >> temp.type ;
    std::cout << "Enter weight: " ;
    std::cin >> temp.weight ;
    std::cout << "Enter energy storage: " ;
    std::cin >> temp.energy_storage ;
    std::cout << "Enter quantity: " ;
    std::cin >> temp.quantity ;
    std::cout << "Enter cost: " ;
    std::cin >> temp.cost ;

    for(int i=0; i<ev.size(); i++) {
        if(temp.brand==ev[i].brand && temp.model==ev[i].model && temp.color == ev[i].color) {
            token=true;
            return std::make_tuple(temp,token,i);
        } else {
            continue ;
        }
    } 

    token=false;
    return std::make_tuple(temp,token,0);
}


void electric_vehicle::display() {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Weight: " << weight << std::endl;
        std::cout << "Energy storage: " << energy_storage << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Cost: " << cost << std::endl ;
        std::cout << std::endl;
}

void operator >>(std::ifstream &read, electric_vehicle &e) {
    read >> e.brand >> e.model >> e.color >> e.type >> e.weight >> e.energy_storage >> e.quantity >> e.cost;
} 

void operator <<(std::ofstream &write, electric_vehicle &e) {
    write << e.brand << " " << e.model << " " << e.color << " " << e.type << " " << e.weight << " " << e.energy_storage << " " << e.quantity << " " << e.cost << std::endl ;
}

    //HYBRID VEHICLE 
hybrid_vehicle::hybrid_vehicle(){}

hybrid_vehicle::hybrid_vehicle(std::string br,std::string mo,std::string co,std::string ty,float wei, float fts,float es,int quan,long long int cos)
:vehicle(br,mo,co,ty,wei),fuel_tank_size(fts),energy_storage(es),quantity(quan),cost(cos){} 

std::tuple<hybrid_vehicle,bool,int>hybrid_vehicle::add_hybrid_vehicle(const std::vector<hybrid_vehicle>&hv) {
    bool token;
    hybrid_vehicle temp;

    std::cout << "Enter brand: " ;
    std::cin >> temp.brand ;
    std::cout << "Enter model: " ;
    std::cin >> temp.model ;
    std::cout << "Enter color: " ;
    std::cin >> temp.color ;
    std::cout << "Enter type: " ;
    std::cin >> temp.type ;
    std::cout << "Enter weight: " ;
    std::cin >> temp.weight ;
    std::cout << "Enter fuel tank capacity: " ;
    std::cin >> temp.fuel_tank_size ;
    std::cout << "Enter energy capacity: " ;
    std::cin >> temp.energy_storage ;
    std::cout << "Enter quantity: " ;
    std::cin >> temp.quantity ;
    std::cout << "Enter cost: " ;
    std::cin >> temp.cost ;

    for(int i=0; i<hv.size(); i++) {
        if(temp.brand==hv[i].brand && temp.model==hv[i].model && temp.color == hv[i].color && temp.type == hv[i].type) {
            token=true;
            return std::make_tuple(temp,token,i);
        } else {
            continue ;
        }
    } 

    token=false;
    return std::make_tuple(temp,token,0);
}


void hybrid_vehicle::display() {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Weight: " << weight << std::endl;
        std::cout << "Energy storage: " << energy_storage << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Cost: " << cost << std::endl ;
        std::cout << std::endl;
}

void operator >>(std::ifstream &read, hybrid_vehicle &h) {
    read >> h.brand >> h.model >> h.color >> h.type >> h.weight >> h.fuel_tank_size >> h.energy_storage >> h.quantity >> h.cost ;
} 

void operator <<(std::ofstream &write, hybrid_vehicle &h) {
    write << h.brand << " " << h.model << " " << h.color << " " << h.type << " " << h.weight << " " << h.fuel_tank_size << " " << h.energy_storage << " " << h.quantity << " " << h.cost << std::endl ;
}

// PAKMOTOR CLASS 
pak_motors::pak_motors(){}
void pak_motors::null(){}

void pak_motors::main_menu() {
    std::string a; bool token ;
    e.push_back(employee("Hassan","Zahid","admin","admin","admin"));
    make("emp.txt"); make("gas.txt"); make("electric.txt"); make("hybrid.txt");
    while (1) {
    std::cout << "\t\t\t\t\t==========\n" ;
    std::cout << "\t\t\t\t\tPAK-MOTORS\n" ;
    std::cout << "\t\t\t\t\t==========\n" ;
    std::cout << "\n\n1. Login\n2. Sign up\n3. Exit\n" ;
    std::cout << "\nEnter choice: " ;
    std:: cin >> a;

    int choice=std::atoi(a.c_str());

    switch (choice) {
        case 1:
        system("cls");
        login();
        token=true;
        break;
    
        case 2:
        system("cls");
        sign_up();
        break;

        case 3:
        token=true;
        break;

        default:
        std::cout << "Invalid choice.\n" ;
        system("cls");
        break;
    }
    
        if(token==true) {
            break;
        }
    }
    update("emp.txt"); update("gas.txt"); update("electric.txt"); update("hybrid.txt");
}

void pak_motors::login() {
    std::string a; bool token; customer c;
    while(1) {
    std::cout << "\t\t\t\t\t=====\n" ;
    std::cout << "\t\t\t\t\tLOGIN\n" ;
    std::cout << "\t\t\t\t\t=====\n" ;
    std::cout << "1. Customer\n2. Employee\n3. Exit\n" ;
    std::cout << "\nEnter choice: " ;
    std::cin >> a ;

    int choice=std::atoi(a.c_str());

    switch(choice) {
        case 1:
        system("cls");
        c.login();
        token=true;
        break ;

        case 2:
        system("cls");
        token=emp_auth();
        break ;

        case 3:
        token=true; 
        break;

        default:
        std::cout << "Invalid choice.\n" ;
        token=false;
        system("cls");
        break;
    }

        if(token==true) {
            break ;
        }
    }
}

bool pak_motors::emp_auth() {
    std::string a; std::string b; bool token;
    std::cout << "\t\t\t\t\t==============\n" ;
    std::cout << "\t\t\t\t\tAUTHENTICATION\n" ;
    std::cout << "\t\t\t\t\t==============\n" ;
    std::cout << "\n\nEnter Username: " ;
    std::cin >> a ;
    std::cout << "Enter password: " ;
    std::cin >> b;
    
    for (int i = 0; i < e.size(); i++) {
        token=e[i].authentication(a,b);
        if(token==true) {
            e[i].main_menu(e);
            break;
        } else {
            continue;
        }
    } 

    if(token==false) {
        std::cout << "No entries found." ;
    }

    system("cls");
    return(token);
}

void pak_motors::sign_up() {
    employee m;
    m=employee::setter(e);
    e.push_back(m);
}

// DATA CLASS
std::vector<gas_vehicle>data::gv;
std::vector<electric_vehicle>data::ev;
std::vector<hybrid_vehicle>data::hv;
std::vector<employee>data::e;

int entry(const char *path) {
    if(path=="emp.txt") {
        employee emp; std::ifstream i;
        int count=0;

        i.open(path);
        while(!i.eof()) {
            i >> emp ;
            count=count+1;
        }
        i.close();
        return (count);
    } else if(path=="gas.txt") {
        gas_vehicle gas; std::ifstream i;
        int count=0;

        i.open(path);
        while(!i.eof()) {
            i >> gas ;
            count=count+1;
        }
        i.close();
        return(count);
    } else if(path=="electric.txt") {
        electric_vehicle elec; std::ifstream i;
        int count=0;

        i.open(path);
        while(!i.eof()) {
            i >> elec ;
            count=count+1;
        }
        i.close();
        return (count);
    } else if(path=="hybrid.txt") {
        hybrid_vehicle hyb; std::ifstream i;
        int count=0;

        i.open(path);
        while(!i.eof()) {
            i >> hyb ;
            count=count+1;
        }
        i.close();
        return (count);
    }
    return 0;
}

void data::make(const char *path) {
    if(path=="emp.txt") {
        employee emp; std::ifstream i;
        int cc=0;int c=::entry("emp.txt");

        i.open(path);
        while(!i.eof()) {
            if(cc==(c-1)) {
                break;
            }
            i >> emp ;
            e.push_back(emp);
            cc=cc+1;
        }
        i.close();       
    } else if(path=="gas.txt") {
        gas_vehicle gas; std::ifstream i;
        int cc=0;int c=::entry("gas.txt");
        
        i.open(path);
        while(!i.eof()) {
            if(cc==(c-1)) {
                break;
            }
            i >> gas ;
            gv.push_back(gas);
            cc=cc+1;
        }
        i.close();
    } else if(path=="electric.txt") {
        electric_vehicle elec; std::ifstream i;
        int cc=0;int c=::entry("electric.txt");

        i.open(path);
        while(!i.eof()) {
            if(cc==(c-1)) {
                break;
            }
            i >> elec ;
            ev.push_back(elec);
            cc=cc+1;
        }
        i.close();
    } else if(path=="hybrid.txt") {
        hybrid_vehicle hyb; std::ifstream i;
        int cc=0;int c=::entry("hybrid.txt");

        i.open(path);
        while(!i.eof()) {
            if(cc==(c-1)) {
                break;
            }
            i >> hyb ;
            hv.push_back(hyb);
            cc=cc+1;
        }
        i.close();
    }
}


void data::update(const char *path) {
    if(path=="emp.txt") {
        std::ofstream o;
        if(e.size()==0) {
            o.open("emp.txt",std::ios::trunc);
            o.close();
            return;
        }

        o.open(path);
        for(int i=1;i<e.size();i++) {
            o << e[i] ;
        }
        o.close();    

        return ;   
    } else if(path=="gas.txt") {
        std::ofstream o;
        if(gv.size()==0) {
            o.open(path,std::ofstream::out | std::ofstream::trunc);
            o.close();
            return;
        }

        o.open(path);
        for(int i=0;i<gv.size();i++) {
            o << gv[i] ;
        }
        o.close();
        return; 
    } else if(path=="electric.txt") {
        std::ofstream o;
        if(ev.size()==0) {
            o.open(path,std::ofstream::out | std::ofstream::trunc);
            o.close();
            return;
        }

        o.open(path);
        for(int i=0;i<ev.size();i++) {
            o << ev[i] ;
        }
        o.close();
        
        return; 
    } else if(path=="hybrid.txt") {
        std::ofstream o;
        if(hv.size()==0) {
            o.open(path,std::ofstream::out | std::ofstream::trunc);
            o.close();
            return;
        }

        o.open(path);
        for(int i=0;i<hv.size();i++) {
            o << hv[i] ;
        }
        o.close(); 
        
        return;
    }
}

void data::quan_change(std::string typ,int i) {
    int q,s_no;
    
    if(typ=="gas") {
        gas_display();
        std::cout << "\n" ;
        std::cout << "Enter serial no: " ;
        std::cin >> s_no ;
        std::cout << "Enter quantity: " ;
        std::cin >> q ;
        if(i==1) {
            
            if(gv[s_no].quantity>=q) {
            gv[s_no].quantity=gv[s_no].quantity-q;
            system("cls");
            std::cout << "\t\t\t\t\t============\n" ;
            std::cout << "\t\t\t\t\tSALE RECIEPT\n" ;
            std::cout << "\t\t\t\t\t============\n" ;
            std::cout << "\nBrand: " << gv[s_no].brand << std::endl ;
            std::cout << "Model: " << gv[s_no].model << std::endl ;
            std::cout << "Color: " << gv[s_no].color << std::endl ;
            std::cout << "Type: " << gv[s_no].type << std::endl ;
            std::cout << "Total bill: " << gv[s_no].cost * q << std::endl ;
            std::cout << std::endl ;
        } else {
            std::cout << "Cannot process sale. Sorry for inconvenience\n";
        }

        } else if(i==0) {
            gv[s_no].quantity=gv[s_no].quantity+q;
        }
    } else if(typ=="electric") {
        electric_display();
        std::cout << "\n" ;
        std::cout << "Enter serial no: " ;
        std::cin >> s_no ;
        std::cout << "Enter quantity: " ;
        std::cin >> q ;
        if(i==1) {

            if(ev[s_no].quantity>=q) {
            ev[s_no].quantity=ev[s_no].quantity-q;
            std::cout << "Brand: " << ev[s_no].brand << std::endl ;
            std::cout << "Model: " << ev[s_no].model << std::endl ;
            std::cout << "Color: " << ev[s_no].color << std::endl ;
            std::cout << "Type: " << ev[s_no].type << std::endl ;
            std::cout << "Total bill: " << ev[s_no].cost * q << std::endl ;
        } else {
            std::cout << "Cannot process sale. Sorry for inconvenience\n";
        }

        } else if(i==0) {
            ev[s_no].quantity=ev[s_no].quantity+q;
        }
        
    } else if(typ=="hybrid") {
        hybrid_display();
        std::cout << "\n" ;
        std::cout << "Enter serial no: " ;
        std::cin >> s_no ;
        std::cout << "Enter quantity: " ;
        std::cin >> q ;
        if(i==1) {

            if(hv[s_no].quantity>=q) {
            hv[s_no].quantity=hv[s_no].quantity-q;
            std::cout << "Brand: " << hv[s_no].brand << std::endl ;
            std::cout << "Model: " << hv[s_no].model << std::endl ;
            std::cout << "Color: " << hv[s_no].color << std::endl ;
            std::cout << "Type: " << hv[s_no].type << std::endl ;
            std::cout << "Total bill: " << hv[s_no].cost * q << std::endl ;
        } else {
            std::cout << "Cannot process sale. Sorry for inconvenience\n";
        }

        } else if(i==0) {
            hv[s_no].quantity=hv[s_no].quantity+q;
        }
    }
}

void data::buy() {
    std::string a; bool token;

    while(1) {
        std::cout << "\t\t\t\t\t===========\n" ;
        std::cout << "\t\t\t\t\tBUY VEHICLE\n" ;
        std::cout << "\t\t\t\t\t===========\n" ;
        std::cout << "\n1. Gas Vehicle\n2. Electric Vehicle\n3. Hybrid Vehicle\n" ;
        std::cout << "\n\nEnter the type of vehicle you want to buy: ";
        std::cin >> a ;

        int choice=atoi(a.c_str());
        switch(1) {
            case 1: {
                system("cls");
                std::cout << "\t\t\t\t\t===========\n" ;
                std::cout << "\t\t\t\t\tBUY VEHICLE\n" ;
                std::cout << "\t\t\t\t\t===========\n" ;
                quan_change("gas",1);
                token=true;
                break;
            }

            case 2: {
                system("cls");
                std::cout << "\t\t\t\t\t===========\n" ;
                std::cout << "\t\t\t\t\tBUY VEHICLE\n" ;
                std::cout << "\t\t\t\t\t===========\n" ;
                quan_change("electic",1);
                token=true;
                break;
            }

            case 3: {
                system("cls");
                std::cout << "\t\t\t\t\t===========\n" ;
                std::cout << "\t\t\t\t\tBUY VEHICLE\n" ;
                std::cout << "\t\t\t\t\t===========\n" ;
                quan_change("hybrid",1);
                token=true;
                break;
            }

            default:
            std::cout << "Invalid choice\n";
            break;

        }
        if(token==true) {
            std::cout << "Press any key to continue." ;
            getch();
            system("cls");
            break;
        }
    }
}

void data::search() const {
    std::string b,m,c,t; float fts,es ; long long int cos;
    int a;
    std::cout << "\t\t\t\t\t==============\n" ;
    std::cout << "\t\t\t\t\tSEARCH RECORDS\n" ;
    std::cout << "\t\t\t\t\t==============\n" ;
    std::cout << "\n\n1. Brand\t2. Model\t3. Color\t4. Type\t5. Fuel Tank Size\t6. Energy Storage\t7. Cost\n";
    std::cout << "\n\nEnter choice to search: " ;
    std::cin >> a ;

    switch(a) {
        case 1: {
            system("cls");
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\t\t\t\t\tSEARCH RECORDS\n" ;
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\n\nEnter Brand Name: " ;
            std::cin >> b ;
            std::cout << "\n" ;
            for(int i=0;i<gv.size();i++) {
                if(b==gv[i].brand) {
                    gv[i].display();
                }
            
            }

            for(int i=0;i<ev.size();i++) {
                if(b==ev[i].brand) {
                    ev[i].display();
                }
            
            }

            for(int i=0;i<hv.size();i++) {
                if(b==hv[i].brand) {
                    hv[i].display();
                }
            
            }
            break ;
        }

        
        case 2: {
            system("cls");
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\t\t\t\t\tSEARCH RECORDS\n" ;
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\n\nEnter Model(YEAR): " ;
            std::cin >> m ;
            std::cout << "\n" ;
            for(int i=0;i<gv.size();i++) {
                if(m==gv[i].model) {
                    gv[i].display();
                }
            
            }

            for(int i=0;i<ev.size();i++) {
                if(m==ev[i].model) {
                    ev[i].display();
                }
            
            }

            for(int i=0;i<hv.size();i++) {
                if(m==hv[i].model) {
                    hv[i].display();
                }
            
            }
            break ;
        }

        
        case 3: {
            system("cls");
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\t\t\t\t\tSEARCH RECORDS\n" ;
            std::cout << "\t\t\t\t\t==============\n" ;         
            std::cout << "\n\nEnter Color: " ;
            std::cin >> c ;
            std::cout << "\n" ;
            
            for(int i=0;i<gv.size();i++) {
                if(c==gv[i].color) {
                    gv[i].display();
                }
            
            }

            for(int i=0;i<ev.size();i++) {
                if(c==ev[i].color) {
                    ev[i].display();
                }
            
            }

            for(int i=0;i<hv.size();i++) {
                if(c==hv[i].color) {
                    hv[i].display();
                }
            
            }
            break ;
        }

        
        case 4: {
            system("cls");
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\t\t\t\t\tSEARCH RECORDS\n" ;
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\n\nEnter Type: " ;
            std::cin >> t ;
            std::cout << "\n" ;
            for(int i=0;i<gv.size();i++) {
                if(t==gv[i].type) {
                    gv[i].display();
                }
            
            }

            for(int i=0;i<ev.size();i++) {
                if(t==ev[i].type) {
                    ev[i].display();
                }
            
            }

            for(int i=0;i<hv.size();i++) {
                if(t==hv[i].type) {
                    hv[i].display();
                }
            
            }
            break ;
        }

        
        case 5: {
            system("cls");
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\t\t\t\t\tSEARCH RECORDS\n" ;
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\n\nEnter Fuel Tank Size: " ;
            std::cin >> fts ;
            std::cout << "\n" ;
            for(int i=0;i<gv.size();i++) {
                if(b==gv[i].brand) {
                    gv[i].display();
                }
            
            }
            break ;
        }

        
        case 6: {
            system("cls");
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\t\t\t\t\tSEARCH RECORDS\n" ;
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\n\nEnter Energy Storage: " ;
            std::cin >> b ;
            std::cout << "\n" ;
            for(int i=0;i<ev.size();i++) {
                if(es==ev[i].energy_storage) {
                    ev[i].display();
                }
            
            }
            break ;
        }

        
        case 7: {
            system("cls");
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "\t\t\t\t\tSEARCH RECORDS\n" ;
            std::cout << "\t\t\t\t\t==============\n" ;
            std::cout << "Enter Cost: " ;
            std::cin >> cos ;
            std::cout << "\n" ;
            for(int i=0;i<gv.size();i++) {
                if(cos==gv[i].cost) {
                    gv[i].display();
                }
            
            }

            for(int i=0;i<ev.size();i++) {
                if(cos==ev[i].cost) {
                    ev[i].display();
                }
            
            }

            for(int i=0;i<hv.size();i++) {
                if(cos==hv[i].cost) {
                    hv[i].display();
                }
            
            }
            break ;
        }

        default:
        std::cout << "Invalid choice\n";
        system("cls");
        break;
    }
    std::cout << "\nEnter any key to continue." ;
    getch();
    system("cls");
}

void data::record_add() {
        std::string a,b; bool token1;
        std::cout << "\t\t\t\t\t===========\n" ;
        std::cout << "\t\t\t\t\tADD RECORDS\n" ;
        std::cout << "\t\t\t\t\t===========\n" ;
        std::cout << "\n\n1. Add to existing record\n2. Add new record\n" ;
        std::cout << "\nEnter choice: " ;
        std::cin >> b ;
        int choice1=atoi(b.c_str());
        if(choice1==1) {
        
        while(1) {
        std::cout << "1. Gas Vehicle\n2. Electric Vehicle\n3. Hybrid Vehicle.\n4. Exit\n" ;
        std::cout << "Enter choice to add vehicle: " ;
        std::cin >> a ;

        int choice=atoi(a.c_str());

        switch(choice) {
            case 1: {
                quan_change("gas",0);
                break;
            }

            case 2: {
                quan_change("electric",0);
                break;
            }

            case 3: {
                quan_change("hybrid",0);
                break;
            }

            case 4:
            token1=true;
            break;

            default:
            std::cout << "Invalid choice.\n";
            system("cls");
            break;
        }    
        if(token1==true) {
            break;
            }
        }
    } else if(choice1==2) {
        
        while(1) {
        std::cout << "1. Gas Vehicle\n2. Electric Vehicle\n3. Hybrid Vehicle.\n4. Exit\n" ;
        std::cout << "Enter choice to add vehicle: " ;
        std::cin >> a ;

        int choice=atoi(a.c_str());

        switch(choice) {
            case 1: {
                gas_vehicle h; int a; bool token;
                std::tie(h,token,a)=gas_vehicle::add_gas_vehicle(gv);
                if(token==true) {
                    quan_add("gas",&h,a);
                } else if(token==false) {
                    gv.push_back(h);
                }
                break;
            }

            case 2: {
                electric_vehicle h; int a; bool token;
                std::tie(h,token,a)=electric_vehicle::add_electric_vehicle(ev);
                if(token==true) {
                    quan_add("electric",&h,a);
                } else if(token==false) {
                    ev.push_back(h);
                }
                break;
            }

            case 3: {
                hybrid_vehicle h; int a; bool token;
                std::tie(h,token,a)=hybrid_vehicle::add_hybrid_vehicle(hv);
                if(token==true) {
                    quan_add("hybrid",&h,a);
                    std::cout << "A" ;
                } else if(token==false) {
                    hv.push_back(h);
                }
                break;
            }

            case 4:
            token1=true;
            break;

            default:
            std::cout << "Invalid choice.\n";
            system("cls");
            break;
        }    
        if(token1==true) {
            break;
            }
        }   
    }
}

void data::record_delete() {
    int choice; std::string a; bool token;

    while(1) {
        std::cout << "\t\t\t\t\t=============\n" ;
        std::cout << "\t\t\t\t\tDELETE RECORDS\n" ;
        std::cout << "\t\t\t\t\t=============\n" ;
        std::cout << "\n1. Gas Vehicle\n2. Electric Vehicle\n3. Hybrid Vehicle\n4. Exit\n";
        std::cout << "Enter choice to delete vehicle: " ;
        std:: cin >> a ;
    
        int choice=atoi(a.c_str());
        switch(choice) {
            case 1: {
                gas_display();
                std::cout << "\n";
                std::cout << "Enter S.NO: " ;
                std::cin >> choice ;
                if(gv.size()==0) {
                    return;
                } else if(choice==0) {
                    gv.erase(gv.begin());
                } else {
                    gv.erase(gv.begin()+choice);
                }
                token=true;
                break;
            }

            case 2: {
                electric_display();
                std::cout << "\n";
                std::cout << "Enter S.NO: " ;
                std::cin >> choice ;
                if(ev.size()==0) {
                    return;
                } else if(choice==0) {
                    ev.erase(ev.begin());
                } else {
                    ev.erase(ev.begin()+choice);
                }
                token=true;
                break;
            }

            case 3: {
                hybrid_display();
                std::cout << "\n";
                std::cout << "Enter S.NO: " ;
                std::cin >> choice ;
                if(hv.size()==0) {
                    return;
                } else if(choice==0) {
                    hv.erase(hv.begin());
                } else {
                    hv.erase(hv.begin()+choice);
                }
                token=true;
                break;
            }

            case 4:
            token=true;
            break;

            default:
            std::cout << "Invalid choice.\n";
            system("cls");
            break;
        }
        if(token==true) {
            break;
        }
    }
}

void data::quan_add(std::string type,vehicle *ptr,int i){
        if(type=="gas") {
            gas_vehicle *ptr1=dynamic_cast<gas_vehicle *>(ptr);
            gv[i].quantity=gv[i].quantity+ptr1->quantity;
        } else if(type=="electric") {
            electric_vehicle *ptr1=dynamic_cast<electric_vehicle *>(ptr);
            ev[i].quantity=ev[i].quantity+ptr1->quantity;
        } else if(type=="hybrid") {
            hybrid_vehicle *ptr1=dynamic_cast<hybrid_vehicle *>(ptr);
            hv[i].quantity=hv[i].quantity+ptr1->quantity;
        }
}

void data::gas_display() const {
        std::cout << "\t\t\t\t\t==============\n" ;
        std::cout << "\t\t\t\t\tRECORD DISPLAY\n" ;
        std::cout << "\t\t\t\t\t==============\n" ; 
    
    for(int i=0;i<gv.size();i++) {
        std::cout << "Serial no: " << i << std::endl ;
        std::cout << "Brand: " << gv[i].brand << std::endl;
        std::cout << "Model: " << gv[i].model << std::endl;
        std::cout << "Color: " << gv[i].color << std::endl;
        std::cout << "Type: " << gv[i].type << std::endl;
        std::cout << "Weight: " << gv[i].weight << std::endl;
        std::cout << "Fuel tank size: " << gv[i].fuel_tank_size << std::endl;
        std::cout << "Quantity: " << gv[i].quantity << std::endl;
        std::cout << "Cost: " << gv[i].cost << std::endl ;
        std::cout << std::endl;
    }
}


void data::electric_display() const {
        std::cout << "\t\t\t\t\t==============\n" ;
        std::cout << "\t\t\t\t\tRECORD DISPLAY\n" ;
        std::cout << "\t\t\t\t\t==============\n" ;
    
    for(int i=0;i<ev.size();i++) {
        std::cout << i << "\n" ;
        std::cout << "Brand: " << ev[i].brand << std::endl;
        std::cout << "Model: " << ev[i].model << std::endl;
        std::cout << "Color: " << ev[i].color << std::endl;
        std::cout << "Type: " << ev[i].type << std::endl;
        std::cout << "Weight: " << ev[i].weight << std::endl;
        std::cout << "Energy storage: " << ev[i].energy_storage << std::endl;
        std::cout << "Quantity: " << ev[i].quantity << std::endl;
        std::cout << "Cost: " << ev[i].cost << std::endl ;
        std::cout << std::endl;
    }
}

void data::hybrid_display() const {
    std::cout << "\t\t\t\t\t==============\n" ;
    std::cout << "\t\t\t\t\tRECORD DISPLAY\n" ;
    std::cout << "\t\t\t\t\t==============\n" ;
    
    for(int i=0;i<hv.size();i++) {
        std::cout << i << "\n" ;
        std::cout << "Brand: " << hv[i].brand << std::endl;
        std::cout << "Model: " << hv[i].model << std::endl;
        std::cout << "Color: " << hv[i].color << std::endl;
        std::cout << "Type: " << hv[i].type << std::endl;
        std::cout << "Weight: " << hv[i].weight << std::endl;
        std::cout << "Fuel tank size: " << hv[i].fuel_tank_size << std::endl;
        std::cout << "Energy storage: " << hv[i].energy_storage << std::endl;
        std::cout << "Quantity: " << hv[i].quantity << std::endl;
        std::cout << "Cost: " << hv[i].cost << std::endl ;
        std::cout << std::endl;
    }
}

void data::record_display() const {
    std::string a; bool token;
    
    while(1) {
        std::cout << "\t\t\t\t\t==============\n" ;
        std::cout << "\t\t\t\t\tRECORD DISPLAY\n" ;
        std::cout << "\t\t\t\t\t==============\n" ;
        std::cout << "\n\n1. Gas vehicle\n2. Electric vehicle\n3. Hybrid vehicle\n4. Exit\n";
        std::cout << "\n\nEnter your choice to display: " ;
        std::cin >> a ;

        int choice=atoi(a.c_str());
        
        switch(choice) {
            case 1:
            system("cls"); 
            gas_display();
            token=true;
            break;

            case 2:
            system("cls");
            electric_display();
            token=true;
            break;

            case 3:
            system("cls");
            hybrid_display();
            token=true;
            break; 

            case 4:
            token=true;
            break;

            default:
            std::cout << "Invalid choice.\n" ;
            system("cls");
            break;
        }

        if(token==true) {
            break ;
        }
    }
 }

void data::search_emp() const{
        std::cout << "\t\t\t\t\t===============\n" ;
        std::cout << "\t\t\t\t\tSEARCH EMPLOYEE\n" ;
        std::cout << "\t\t\t\t\t===============\n" ;
        std::cout << std::endl << std::endl ;
    for (int i = 0; i < e.size(); i++) {
        std::cout << "First name: " << e[i].fname << std::endl ;
        std::cout << "Last name: " << e[i].lname << std::endl ;
        std::cout << "Designation: " << e[i].designation << std::endl ;
    }
}

// EMPLOYEE CLASS 
employee::employee(){}

employee::employee(std::string fn, std::string ln, std::string un, std::string desig, std::string pass)
:fname(fn),lname(ln),username(un),designation(desig),password(pass) {}

void employee::null() {}

employee employee::setter(const std::vector<employee>&e) {
    employee em;
    std::cout << "\t\t\t\t\t=======\n" ;
    std::cout << "\t\t\t\t\tSIGN UP\n" ;
    std::cout << "\t\t\t\t\t=======\n" ;
    std::cout << "\n\nEnter first name: " ;
    std::cin >> em.fname ;
    std::cout << "Enter last name: " ;
    std::cin >> em.lname ;
    std::cout << "Enter designation: " ;
    std::cin >> em.designation ;
    
    while(1) {
        bool token=true;
        std::cout << "Enter username: " ;
        std::cin  >> em.username ;
        
        for(int i=0; i<e.size();i++) {
            if(em.username==e[i].username) {
                std::cout << "Username is already taken." << std::endl ;
                token = false;
                break;
            } else {
                continue;
            }
        }
    
        if(token==true) {
            break ;
        }
    }
        std:: cout << "Enter password: " ;
        std::cin >> em.password ;
        system("cls");
        std::cout << "Press any key to continue." ;
        getch();
        return(em);
}

void operator >> (std::ifstream &reader, employee &e) {
    reader >> e.fname >> e.lname >> e.designation >> e.username >> e.password ;
}

void operator <<(std::ofstream &reader, employee &e) {
    reader << e.fname << " " << e.lname << " " << e.designation << " " << e.username  << " " << e.password << std::endl ;
}


bool employee::authentication(std::string un, std::string a) {
    if(un==username && a==password) {
        return true ;
    } else {
        return false ;
    }
}

void employee::change_details(const std::vector<employee>&e){
    std::string a,b;
    std::cout << "\t\t\t\t\t=================\n" ;
    std::cout << "\t\t\t\t\tCHANGE OF DETAILS\n" ;
    std::cout << "\t\t\t\t\t=================\n" ;
    std::cout << "Enter designation: " ;
    std::cin >> designation ;

    while(1) {
        bool token=true; 
        std::cout << "Enter username: " ;
        std::cin >> a ;

        for(int i=0; i<e.size();i++) {
            if(a==this->username) {
                token=true;
                break;
            } else if(a==e[i].username) {
                std::cout << "Username is already taken." << std::endl ;
                token = false;
                break;
            } else {
                continue;
            }
        }

        if(token==true) {
            std::cout << "okay" << std::endl;
            break ; 
        }
    }
        std:: cout << "Enter password: " ;
        std::cin >> b ;
        
        username=a;
        password=b;
    
}

void employee::main_menu(const std::vector<employee>&e) {
    system("cls");
    std::string a; bool token ;
    
    while(1) {
        std::cout << std::endl ;
        std::cout << "\t\t\t\t\t==========\n" ;
        std::cout << "\t\t\t\t\tMAIN MENU\n" ;
        std::cout << "\t\t\t\t\t==========\n" ;
        std::cout << "\n\n\t\t\t\tWelcome " << fname << " " << lname << std::endl << std::endl;
        std::cout << "1. Display employee details\n2. Add records\n3. Delete records\n4. Display records\n5. Search records\n6. Change account details\n7.Logout\n" ;
        std::cout << std::endl ;
        std::cout << "Enter choice: " ;
        std::cin >> a ;

        int choice=atoi(a.c_str());
        switch(choice) {
            case 1:
            system("cls");
            search_emp();
            std::cout << "Press any key to continue: ";
            getch();
            break;

            case 2:
            system("cls");
            record_add();
            std::cout << "Press any key to continue: ";
            getch();
            break;

            case 3:
            system("cls");
            record_delete();
            std::cout << "Press any key to continue: ";
            getch();
            break;

            case 4:
            system("cls");
            record_display();
            std::cout << "Press any key to continue: ";
            getch();
            break ;

            case 5:
            system("cls");
            search();
            std::cout << "Press any key to continue: ";
            getch();
            break;

            case 6:
            system("cls");
            change_details(e);
            std::cout << "Press any key to continue: ";
            getch();
            break;

            case 7:
            system("cls");
            std::cout << "Have a good day!!!\n";
            token=true;
            break;

            default:
            std::cout << "Invalid choice.\n" ;
            system("cls");
            break;
        }

        if(token==true) {
            break;
        }
        system("cls");
    }
}

// CUSTOMER CLASS 
customer::customer(){}
void customer::null(){}
void customer::record_delete(){}
void customer::record_add(){}
void customer::search_emp(){}
void customer::quan_add(){}
void customer::quan_change(){}

void customer::login() {
    std::string a; bool token;
    
    while(1) {
        std::cout << "\t\t\t\t\t==============\n" ;
        std::cout << "\t\t\t\t\tCUSTOMER LOGIN\n" ;
        std::cout << "\t\t\t\t\t==============\n" ;
        std::cout << "\n\n\t\t\t\t\tWelcome guest." << std::endl;
        std::cout << "1. Search records\n2. Buy vehicles\n3. Exit\n" ;
        std::cout << "\n\nEnter your choice: " ;
        std::cin >> a ;

        int choice=atoi(a.c_str());

        switch(choice) {
            case 1:
            system("cls");
            search();
            break;

            case 2:
            system("cls");
            buy();
            break;

            case 3:
            system("cls");
            std::cout << "Thank You for Visiting PAK MOTORS\n";
            token=true;
            break;

            default:
            std::cout << "Invalid choice\n" ;
            system("cls");
            break;
        }
        if(token==true) {
            break;
        }
    }
}
