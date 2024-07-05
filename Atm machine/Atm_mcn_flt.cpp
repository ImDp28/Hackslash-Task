#include<iostream>
#include<vector>
using namespace std;
class Atm{
    private:
    vector<int> denomination;
    vector<int> notecount;
    public:
    Atm(){
        denomination={10,20,50,100,200,500};
        notecount={0,0,0,0,0,0};
    }
    void deposit(vector<int> dep){
        for(int i=0;i<6;i++){
            notecount[i]+=dep[i];
        }
        
    }
   vector<int> withdraw(int amount){
        vector<int> result(6,0);
        for(int i=0;i<6;i++){
            result[5-i]=min((amount/denomination[5-i]),notecount[5-i]);
            amount-=result[5-i]*denomination[5-i];
            notecount[5-i]-=result[5-i];
        }
        if(amount>0) return {-1};
        else{
            return result;
        }

        
    }
    
};
int main(){
    Atm atm;
    vector<int> dep;  
    cout<<"Welcome to Deposit Service...Enter notes in order 10,20,50,100,200,500:- "<<endl;
    for(int i=0;i<6;i++){
        int x;
        cin>>x;
        dep.push_back(x);
    }
    atm.deposit(dep);
    dep.clear();
    int y;
    cout<<"Enter Amnt For Withdrawal:- ";
    cin>>y;
    vector<int> result = atm.withdraw(y); 
    if (result.size() == 1 && result[0] == -1) {
        cout << "Withdraw not possible" << endl;
    } else {
        cout<<"Notes in order 10 20 50 100 200 500"<<endl;
        for(int i=0;i<6;i++){
            cout<<result[i]<<" ";
        }
    }
    return 0;
}