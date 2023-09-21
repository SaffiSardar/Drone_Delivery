#include<iostream>
#include <unistd.h>
#include<windows.h>
#include <iostream>
#include <fstream>

using namespace std;

class detail{
    public:
    virtual void details()=0;
};

class drone:public detail{
protected:
    float*weight;
    int distance;
    string*state_of_matter,*location,*weather;
    bool*traffic;
public:

    void details()
    {
        static int i = 0;
        if(i!=1)
     {
        system("Color 9");
        cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\n\n\t\t\t\t\t\t\t\t       Welcome To your Very OWn Drone Delivery System\n\n";
        cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t    DRONES AVAILABLE \n\n";
        cout<<"\t\t\t\t\t\t\t\t\t   -----------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t   | Light Model   |\tHeavy Model  "<<"|\n";
        cout<<"\t\t\t\t\t\t\t\t\t   -----------------------------------\n\n";
        sleep(5);
        system("cls");
        system("Color 4");
        cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout<<"\tLight Model :" << "\t\t\t\t\t\t\t\t\t\t\t\t\tHeavy Model :\n";
        cout<<"\t\t\tOperates at Both High and Low Altitude" << "\t\t\t\t\t\t\t\t\t\tOperates ONLY at Low Altitude\n";
        cout<<"\t\t\tHigh range and Low range variant's"<< "\t\t\t\t\t\t\t\t\t\tLow Range Variant\n";
        cout<<"\t\t\tOperate at both high and low speeds"<< "\t\t\t\t\t\t\t\t\t\tOperates at Low Speed Only\n";
        cout<<"\t\t\tStatus : Avalible"<< "\t\t\t\t\t\t\t\t\t\t\t\tStatus : Not Avalible\n";
        cout<<"\t\t\t\t{Ready For Launch}"<< "\t\t\t\t\t\t\t\t\t\t\t\t{Launched under certain conditions} \n";
        cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        i++;
     }
     else
     {
       cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
       cout<<"\n\n\t\t\t\t\t\t\t\t\t\t       INPUT DETAILS\n\n";
       cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
     }
    }

//Default Parameterized Constructor
    drone(float Weight=0.0,string State_of_matter="",bool Traffic=0,string Location="",string Weather=""){
        weight = new float;
        *weight=Weight;
        state_of_matter = new string;
        *state_of_matter=State_of_matter;
        traffic = new bool;
        *traffic=Traffic;
        location = new string;
        *location=Location;
        weather = new string;
        *weather = Weather;

    }
//COPY CONSTRUCTOR(DEEP COPY)
    drone(const drone &obj){
        weight = new float;
        *weight = *(obj.weight);
        state_of_matter = new string;
        state_of_matter=(obj.state_of_matter);
        traffic = new bool;
        traffic =(obj.traffic);
        location = new string;
        *location = *(obj.location);
        weather = new string;
        *weather = *(obj.weather);
        distance = obj.distance;// Shallow Copy
    }

    drone operator + (const drone& obj){
        drone temp1;
        *(temp1.weight)= *weight + *(obj.weight);
        *(temp1.state_of_matter)= *state_of_matter;
        *(temp1.traffic)= *traffic;
        *(temp1.location)= *location;
        *(temp1.weather)= *weather;
        return temp1;
    }
    bool s_traffic(){return *traffic;}
    string s_location(){return *location;}
    string g_weather(){return *weather;}
    void s_weight(float x){*weight = x;}
    float g_weight(){return *weight;}
    void s_state_of_matter(string x){*state_of_matter = x;}
    string g_state_of_matter(){return *state_of_matter;}
        void s_distance(string location){
        if (location == "1"){distance =100;}
        else if (location == "2"){distance =200;}
        else if (location == "3"){distance =300;}
        else if (location == "4"){distance =400;}
        else if (location == "5"){distance =500;}
        else if (location == "6"){distance =600;}
        else if (location == "7"){distance =700;}
        else if (location == "8"){distance =800;}
    }
    int g_distance(){return distance;}
//Destructor
};
class high_altitude:virtual public drone{
    protected:
        double altitude = 10000;
    public:
    void details(){
            cout<<"Welcome to Your Very own Drone delivery system!"<<endl;
    }
        high_altitude(float weight=0.0,string state_of_matter="",bool traffic=0,string location="",string weather=""):drone(weight,state_of_matter,traffic,location,weather){}
        high_altitude(const high_altitude &obj):drone(obj){}
        ~high_altitude(){}
        float highalt(){
            return altitude;
    }
};
class low_altitude:virtual public drone{
    protected:
        double altitude=5000;
    public:
    void details(){
            cout<<"Welcome to Your Very own Drone delivery system!"<<endl;
    }
        low_altitude(float weight=0.0,string state_of_matter="",bool traffic=0,string location="",string weather=""):drone(weight,state_of_matter,traffic,location,weather){}
        low_altitude(const low_altitude &obj):drone(obj){}
        ~low_altitude(){}
        float lowalt(){
            return altitude;
        }
};
class high_range:public virtual high_altitude,virtual public low_altitude{
    public:
    void details(){
            cout<<"Welcome to Your Very own Drone delivery system!"<<endl;
    }
        high_range(float weight=0.0,string state_of_matter="",bool traffic=0,string location="",string weather=""):high_altitude(weight,state_of_matter,traffic,location,weather),low_altitude(weight,state_of_matter,traffic,location,weather),drone(weight,state_of_matter,traffic,location,weather){}
        high_range(const high_range &obj):high_altitude(obj),low_altitude(obj),drone(obj){}
        ~high_range(){}
        int range(){
            return 1100;
        }
};
class low_range:public virtual high_altitude,public virtual low_altitude{
    public:
    void details(){
            cout<<"Welcome to Your Very own Drone delivery system!"<<endl;
    }
        low_range(float weight=0.0,string state_of_matter="",bool traffic=0,string location="",string weather=""):high_altitude(weight,state_of_matter,traffic,location,weather),low_altitude(weight,state_of_matter,traffic,location,weather),drone(weight,state_of_matter,traffic,location,weather){}
        low_range(const low_range &obj):high_altitude(obj),low_altitude(obj),drone(obj){}
        ~low_range(){}
        int range(){
            return 600;
        }
};

class high_speed: virtual public high_range, virtual public low_range{
    protected:
        int speed = 100;
    public:
    void details(){
            cout<<"Welcome to Your Very own Drone delivery system!"<<endl;
    }
        high_speed(float weight=0.0,string state_of_matter="",bool traffic=0,string location="",string weather=""):high_range(weight,state_of_matter,traffic,location,weather),low_range(weight,state_of_matter,traffic,location,weather),high_altitude(weight,state_of_matter,traffic,location,weather),low_altitude(weight,state_of_matter,traffic,location,weather),drone(weight,state_of_matter,traffic,location,weather){}
        high_speed(const high_speed &obj):high_range(obj),low_range(obj),high_altitude(obj),low_altitude(obj),drone(obj){}
        friend int speed(high_speed h);
        ~high_speed(){}
};
class heavy_model;
class low_speed:  virtual public high_range, virtual  public low_range{
        friend class heavy_model;
    protected:

        int speed = 50;
    public:
    //Display 1
    void details(){}
        low_speed(float weight=0.0,string state_of_matter="",bool traffic=0,string location="",string weather=""):high_range(weight,state_of_matter,traffic,location,weather),low_range(weight,state_of_matter,traffic,location,weather),high_altitude(weight,state_of_matter,traffic,location,weather),low_altitude(weight,state_of_matter,traffic,location,weather),drone(weight,state_of_matter,traffic,location,weather){}
        low_speed(const low_speed &obj):high_range(obj),low_range(obj),high_altitude(obj),low_altitude(obj),drone(obj){}
        friend int speed(low_speed l);
        ~low_speed(){}
};
int speed(high_speed h){return h.speed;}
int speed(low_speed h ){return h.speed;}
class heavy_model
{
    low_speed obj;
    public:
    void set_obj(low_speed obj){this->obj = obj;}
    void details()
    {
        static int i = 0;
        string space="";
        if(i>2)
        {
            i=0;
        }
        if(i==0)
        {
            cout<<"\n\n\nHEAVY MODEL\n";
        }
        if(i==1)
        {
           space="\t\t\t\t\t\t\t";
           cout<<"\n";
        }
        if(i==2)
        {
            space="\t\t\t\t\t\t\t\t\t\t\t";
        }
        if(i!=2)
        {
          cout<<space+"\t\t\t------------------------\n";
        }
        string Location;
        if(*(obj.location)=="1"){Location = "Johar Town";}
        if(*(obj.location)=="2"||*(obj.location)=="6"){Location = "Bahria Town";}
        if(*(obj.location)=="3"||*(obj.location)=="7"){Location = "Defence";}
        if(*(obj.location)=="4"){Location = "Garden Town";}
        if(*(obj.location)=="5"){Location = "Zero";}
        if(*(obj.location)=="8"){Location = "Eden Villas";}
        if(i!=2)
        {
            cout<<space+"\t\t\tWeight of Parcel :" << *(obj.weight) << endl;
        }
        cout<<space+"\t\t\tLocation         :" << Location << endl;
        if(*(obj.traffic)==0){Location = "Crowded area ";}
        if(*(obj.traffic)==1){Location = "Less Crowded ";}
        cout<<space+"\t\t\tTraffiq          :"<< Location << endl;
        cout<<space+"\t\t\tWeather          :"<< *(obj.weather)<< endl;
        cout<<space+"\t\t\tState of Matter  :" << *(obj.state_of_matter) << endl;
        i++;
    }
    ~heavy_model(){}
};
class light_model:  public  high_speed ,   public  low_speed{
    light_model*l1;
    public:
    //Display 2
        void details();
        void set_obj(light_model*l1){*(this->l1) = *l1;}
        light_model get_obj(){return *l1;}
        light_model(float weight=0.0,string state_of_matter="",bool traffic=0,string location="",string weather=""):high_speed(weight,state_of_matter,traffic,location,weather),low_speed(weight,state_of_matter,traffic,location,weather),high_altitude(weight,state_of_matter,traffic,location,weather),low_altitude(weight,state_of_matter,traffic,location,weather),drone(weight,state_of_matter,traffic,location,weather){}
        light_model(const light_model &obj):high_speed(obj),low_speed(obj),high_altitude(obj),low_altitude(obj),drone(obj){}
        ~light_model(){}
};
    void light_model::details()
    {
        static int i = 0;
        string space="";
        if(i>2)
        {
          i=0;
        }
        if(i==0)
        {
            cout<<"\n\n\nLIGHT MODEL\n";
        }
        if(i==1)
        {
           space="\t\t\t\t\t\t\t";
           cout<<"\n";
        }
        if(i==2)
        {
            space="\t\t\t\t\t\t\t\t\t\t\t";
        }
        string Location;
        if(i!=2)
        {
          cout<<space+"\t\t\t------------------------\n";
        }
        if(*location=="1"){Location = "Johar Town";}
        if(*location=="2"||*location=="6"){Location = "Bahria Town";}
        if(*location=="3"||*location=="7"){Location = "Defence";}
        if(*location=="4"){Location = "Garden Town";}
        if(*location=="5"){Location = "Zero";}
        if(*location=="8"){Location = "Eden Villas";}
        if(i!=2)
        {
          cout<<space +"\t\t\tWeight of Parcel :" << *weight << endl;
        }
        cout<<space+"\t\t\tLocation         :" << Location << endl;
        if(*traffic==0){Location = "Crowded area ";}
        if(*traffic==1){Location = "Less Crowded ";}
        cout<<space+"\t\t\tTraffiq          :"<< Location << endl;
        cout<<space+"\t\t\tWeather          :"<< *weather<< endl;
        cout<<space+"\t\t\tState of Matter  :" << *state_of_matter << endl;
        i++;

    }
template<class T>
class Time
{
    T time;
    public:
    T calc_Time(T alt,T dist,T speed)
    {
        time = dist / speed + (2 * alt / speed);
        return time;
    }
};
int main(){
    int b = 0;
    do{
    int country=-1,city=-1,distance=-1,distance1=-1,ranges=-1,ranges1=-1,traffic=-1,speeds=-1,speeds1=-1;
    float weight = 0,weight1 = 0,altitudes=0,altitudes1=0;
    string deliveryspeed="",state_of_matter = "",location= "",weather="";
    bool flag = false;
    int reorder=0;
    heavy_model heavy;
    light_model*l1,*h1;
    char enter;
    detail*ptr;
    drone d1;
    // sleep(3); //FOR CODEBLOCK
    ptr=&d1;
   if(b!=1)
{
    ptr->details();
    sleep(5);
    system("Color 2");
//Exception Handling:

    try
    {
      cout<<"\t\tPress y  to Continue.........\n";
      cin>>enter;
      if(enter=='y')
     {
        system("cls");
     }
      else
     {
        throw enter;
     }
    }
    catch(char a)
    {
        while(enter!='y')
        {   system("Color 4");
            static int i = 0;
               if(i!=0)
            {
                cout<<"\n\tPress y to continue you entered " << enter << endl;
                cin>>enter;
            }
               else
            {  cout<<"\n\tPress y to continue you entered " << a << endl;
               cin>>enter;
            }
            i++;
        }
        sleep(2);
    }
    system("cls");
}
    ptr->details();
    while (deliveryspeed!="1" && deliveryspeed!="0")
    {    system("Color 2");
        cout<<"\n\nIf you want Fast Delivery, press 1, else for Normal Delivery, press 0."<<endl;
        cin>>deliveryspeed;
    }
    while (state_of_matter!="Liquid" && state_of_matter!="Gas" && state_of_matter!="Solid" )
    {
        cout<<"Please input whther your parcel is Liquid/Gas/Solid."<<endl;
        cin>>state_of_matter;
    }
    while (country!=1 && country!=2)
    {
        cout<<"PLease select the city you want to send your Parcel in, press 1 for Lahore, 2 for Islamabad."<<endl;
        cin>>country;
    }
    while(location!="1" && location!="2" && location!="3" && location!="4" && location!="5" && location!="6" && location!="7" && location!="8"  )
    if (country==1){
        cout<<"Press 1 for Johar Town, 2 for Bahria Town, 3 for Defence, and 4 for Garden Town."<<endl;
        cin>>location;
    }
    else if (country==2){
        cout<<"Press 5 for Zero, 6 for Bahria Town, 7 for Defence, and 8 for Eden Villas."<<endl;
        cin>>location;
    }
    cout<<"Enter Weight of your parcel:"<<endl;
    cin>>weight;
    while(weather!="Sunny" && weather!="Rainy"){
        cout<<"What is the usual Weather at this location, enter Sunny or Rainy: "<<endl;
        cin>>weather;
    }
    while(traffic!=1 && traffic!=0){
        cout<<"Is this area usually crowded, Press 1 if yes, else 0! "<<endl;
        cin>>traffic;
    }
    sleep(2);
    system("cls");
    if (deliveryspeed=="0"){
        l1 = new light_model(weight,state_of_matter,traffic,location,weather);
        light_model l2(*l1);
        drone l3=*l1+l2;
        ptr=l1;
        if(weather!="Rainy")
        {
            ptr->details();
            system("Color F");
        }
        weight1=l3.g_weight();
        l1->s_distance(location);
        l2.s_distance(location);
        low_speed ls(weight,state_of_matter,traffic,location,weather);
        speeds = speed(ls);
        speeds1= speed(ls);
         if(weather=="Rainy")
        {
            heavy.set_obj(ls);
            heavy.details();
            flag = true;
            system("Color F");
        }
        distance = l1->g_distance();
        distance1= l2.g_distance();
        if (distance<=600){
            ranges=l1->low_range::range();
            ranges=l2.low_range::range();
            if(weather=="Sunny"){
                altitudes =l1->highalt();
                altitudes1=l2.highalt();
            }
            else{
                altitudes =l1->lowalt();
                altitudes1=l2.lowalt();
            }
        }
        else{
            ranges =l1->high_range::range();
            ranges1=l2.high_range::range();
            if(weather=="Sunny"){
                altitudes =l1->highalt();
                altitudes1=l2.highalt();
            }
            else{
                altitudes =l1->lowalt();
                altitudes1=l2.lowalt();
            }
        }
    }

    else if (deliveryspeed=="1"){
        h1 = new light_model(weight,state_of_matter,traffic,location,weather);
        light_model h2(*h1);
        drone h3=*h1+h2;
        ptr=h1;
          if(weather!="Rainy")
        {
            system("Color F");
            ptr->details();
        }
        weight1=h3.g_weight();
        h1->s_distance(location);
        h2.s_distance(location);
        low_speed ls(weight,state_of_matter,traffic,location,weather);
        high_speed hs(weight,state_of_matter,traffic,location,weather);
        speeds = speed(hs);
        speeds1= speed(hs);
            if(weather=="Rainy")
        {
            system("Color F");
            heavy.set_obj(ls);
            speeds = speed(ls);
            speeds1 = speed(ls);
            heavy.details();
            flag = true;
        }
        distance = h1->g_distance();
        distance1= h2.g_distance();
        if (distance<=600){
            ranges =h1->low_range::range();
            ranges1=h2.low_range::range();
            if(deliveryspeed=="1" && weather=="Sunny"){
                altitudes =h1->highalt();
                altitudes1=h2.highalt();
            }
            else{
                altitudes =h1->lowalt();
                altitudes1=h2.lowalt();
            }
        }
        else{
            ranges =h1->high_range::range();
            ranges1=h2.high_range::range();
            if(deliveryspeed=="1" && weather=="Sunny"){
                altitudes =h1->highalt();
                altitudes1=h2.highalt();
            }
            else{
                altitudes =h1->lowalt();
                altitudes1=h2.lowalt();
            }
        }
    }

    Time<float>time;
    float timee = time.calc_Time(altitudes,distance,speeds);
    cout<<"\t\t\tAltitude         :" <<altitudes<<endl;
    cout<< "\t\t\tDistance         :"<<distance<<endl;
    cout<< "\t\t\tSpeed            :"<<speeds<<endl;
    cout<< "\t\t\tArrival Time     :" << timee <<"s"<<endl;
    cout<<"\t\t\t------------------------\n\n\n";
    cout<<"Do you wish to re-order the delivery of this parcel? if yes, press 1, else 0."<<endl;
    cin>>reorder;
    if(reorder==1){
    cout<<"Your order for re-delivery has been placed, it will take the same time as before for second parcel\n";
    if(flag==false)
    {
      ptr->details();
    }
    if(flag==true)
    {
        heavy.details();
    }
    string space="\t\t\t\t\t\t\t";
    cout<<space+"\t\t\tAltitude         :" <<altitudes<<endl;
    cout<<space+"\t\t\tDistance         :"<<distance<<endl;
    cout<<space+"\t\t\tSpeed            :"<<speeds<<endl;
    cout<<space+"\t\t\tArrival Time     :" << timee*2 <<"s"<<endl;
    cout<<space+"\t\t\t------------------------\n\n\n";

    cout<<"Do you wish to enter both your parcels in the same drone to save time? Press 2 if yes, else 0."<<endl;
    cin>>reorder;
    if (reorder==2){
        string space ="\t\t\t\t\t\t\t\t\t\t\t";
        cout<<space+"\t\t\t------------------------\n";
        cout<<space +"\t\t\tWeight of Parcel :" <<weight1<<endl;
        if(flag==false)
        {
          ptr->details();
        }
        if(flag==true)
        {
            heavy.details();
        }
        cout<<space+"\t\t\tAltitude         :" <<altitudes<<endl;
        cout<<space+"\t\t\tDistance         :"<<distance<<endl;
        cout<<space+"\t\t\tSpeed            :"<<speeds<<endl;
        cout<<space+"\t\t\tArrival Time     :" << timee <<"s"<<endl;
        cout<<space+"\t\t\t------------------------\n\n\n";
    }
    }


    fstream Out("Drone.txt",ios::app);
        if (Out.is_open()) {
            Out << "Altitude: "<<altitudes<<"ft"<<", Distance: "<<distance<<"km"<<" Speed: "<<speeds<<"km/h"<<", Time: "<<timee<<"s"<<endl;
            Out.close();
            cout << endl << "Reciept added" << endl;
        }

    cout<<"Do you wish to order another Parcel? If yes press 1, else 0: "<<endl;
    cin>>b;
    sleep(2);
    system("cls");
}while(b==1);
}
