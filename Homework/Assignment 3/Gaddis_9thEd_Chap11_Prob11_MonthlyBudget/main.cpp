/* 
 * File: main.cpp   
 * Author: Khadiza Akter
 * Created on 9/26/2022
 * Purpose: Evaluating monthly budget of a student using structure
 */

//System Libraries
#include <iostream>
#include <iomanip> //setprecision()
#include <cmath> //abs()
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
//structure declaration
struct MonthlyBudget{
    float  housing,            //expense for housing             
            utilities,          //expense for utilities              
            householdExpenses,  //expense for householdExpenses 
            transportation,     //expense for transportation 
            food,               //expense for food         
            medical,            //expense for medical        
            insurance,          //expense for insurance      
            entertainment,      //expense for entertainment      
            clothing,           //expense for clothing     
            miscellaneious;     //expense for miscellaneious 
};

//Function Prototypes
void getInformation(MonthlyBudget&); //get monthly budget information by user
void reportMonthlyBudget(const MonthlyBudget&); //calculate total budget, cost, rest amount for a month and display report

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    MonthlyBudget data; //structure variable
    
    
    getInformation(data); //pass structure variable to function as argument
    reportMonthlyBudget(data); //pass structure variable to function as argument

    //Exit stage right!
    return 0;
}
//this function used to get monthly budget information by user
void getInformation(MonthlyBudget& data){
    cout <<"Enter housing cost for the month:$"<<endl;
    cin >> data.housing;
    cout <<"Enter utilities cost for the month:$"<<endl;
    cin >> data.utilities;
    cout <<"Enter household expenses cost for the month:$"<<endl;
    cin >> data.householdExpenses;
    cout <<"Enter transportation cost for the month:$"<<endl;
    cin >> data.transportation;
    cout <<"Enter food cost for the month:$"<<endl;
    cin >> data.food;
    cout <<"Enter medical cost for the month:$"<<endl;
    cin >> data.medical;
    cout <<"Enter insurance cost for the month:$"<<endl;
    cin >> data.insurance;
    cout <<"Enter entertainment cost for the month:$"<<endl;
    cin >> data.entertainment;
    cout <<"Enter clothing cost for the month:$"<<endl;
    cin >> data.clothing;
    cout <<"Enter miscellaneous cost for the month:$"<<endl;
    cin >> data.miscellaneious;
}
//This function calculate total budget, cost, restamount for a month and display report
void reportMonthlyBudget(const MonthlyBudget& data) {
    float totalbudget; //used to hold total budget of a month
    float totalCost;   //used to hold total cost of a month
    float restBudget;  //used to hold rest budget of a month
    
    //checking monthly budget and cost even, over or under
   if(data.housing == 500){          
       cout <<"Housing Even"<<endl;
   }else if (data.housing > 500){
       cout <<"Housing Over"<<endl;
   }else {
       cout <<"Housing Under" <<endl;
   }
   if(data.utilities == 150){
       cout <<"Utilities Even"<<endl;
   }else if (data.utilities > 150){
       cout <<"Utilities Over"<<endl;
   }else {
       cout <<"Utilities Under" <<endl;
   }
   if(data.householdExpenses == 65){
       cout <<"Household Expenses Even"<<endl;
   }else if (data.householdExpenses > 65){
       cout <<"Household Expenses Over"<<endl;
   }else {
       cout <<"Household Expenses Under" <<endl;
   }
   if(data.transportation == 50){
       cout <<"Transportation Even"<<endl;
   }else if (data.transportation > 50){
       cout <<"Transportation Over"<<endl;
   }else {
       cout <<"Transportation Under" <<endl;
   }
   if(data.food == 250){
       cout <<"Food Even"<<endl;
   }else if (data.food > 250){
       cout <<"Food Over"<<endl;
   }else {
       cout <<"Food Under" <<endl;
   }
   if(data.medical == 30){
       cout <<"Medical Even"<<endl;
   }else if (data.medical > 30){
       cout <<"Medical Over"<<endl;
   }else {
       cout <<"Medical Under" <<endl;
   }
   if(data.insurance == 100){
       cout <<"Insurance Even"<<endl;
   }else if (data.insurance > 100){
       cout <<"Insurance Over"<<endl;
   }else {
       cout <<"Insurance Under" <<endl;
   }
   if(data.entertainment == 150){
       cout <<"Entertainment Even"<<endl;
   }else if (data.entertainment > 150){
       cout <<"Entertainment Over"<<endl;
   }else {
       cout <<"Entertainment Under" <<endl;
   }
   if(data.clothing == 75){
       cout <<"Clothing Even"<<endl;
   }else if (data.clothing > 75){
       cout <<"Clothing Over"<<endl;
   }else {
       cout <<"Clothing Under" <<endl;
   }
   if(data.miscellaneious == 50){
       cout <<"Miscellaneous Even"<<endl;
   }else if (data.miscellaneious > 50){
       cout <<"Miscellaneous Over"<<endl;
   }else {
       cout <<"Miscellaneous Under" <<endl;
   }
   
   cout <<fixed<<setprecision(2); //output formatting with 2 decimal place
   totalbudget = 500.00+150.00+65.00+50.00+250.00+30.00+100.00+150.00+75.00+50.00; //calculate total budget for a month
   
   totalCost = data.housing+data.utilities+data.householdExpenses                 //calculate total cost for a month
              +data.food+data.medical+data.insurance+data.entertainment+
              data.clothing+data.miscellaneious+data.transportation;
                           
    restBudget = totalbudget - totalCost;                                          //rest budget for a month
   
   //check the rest amount is under, over or even
    if (restBudget == 0.00)  cout << "You were $0.00 even budget";
    else if(restBudget > 0 || restBudget > 0.00)
        cout <<"You were $"<<restBudget<<" under budget";
    else
        cout <<"You were $"<<abs(restBudget)<<" over budget";


}