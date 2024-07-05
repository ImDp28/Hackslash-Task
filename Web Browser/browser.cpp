#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Browser{
    private:
    vector<string> his1;
    vector<string> his2;
    int crtidx1;
    int crtidx2;
    int currenttab;
    public:
    Browser(){
        his1.push_back("Homepage");
        his2.push_back("Homepage");
        crtidx1=0;
        crtidx2=0;
        currenttab=0;
    }
    void visit(string url){
        if(currenttab==0){
            his1.resize(crtidx1 + 1);
            his1.push_back(url);
            crtidx1++;
        }
        else{
            his2.resize(crtidx2 + 1);
            his2.push_back(url);
            crtidx2++;
        }
    }
    string go_back(int n){
        if(currenttab==0){
            crtidx1=max(0,crtidx1-n);
            return his1[crtidx1];
        }
        else{
            crtidx2=max(0,crtidx2-n);
            return his2[crtidx2];
        }
    }
    string forward(int n){
        if(currenttab==0){
            crtidx1=min((int)his1.size()-1,crtidx1+n);
            return his1[crtidx1];
        }
        else{
            crtidx2=min((int)his2.size()-1,crtidx2+n);
            return his2[crtidx2];
        }
    }
    void changetab(){
        currenttab=1-currenttab;
    }

};
int main(){
    Browser Chrome; //chrome object
    Chrome.visit("Google");//1st webpage google
    Chrome.visit("Facebook");
    Chrome.visit("Whatsapp3");
    Chrome.visit("Instagram4");
    cout<<Chrome.go_back(3)<<endl;//going back 3 pages
    Chrome.visit("Miami");//visiting miami webpage
    cout<<Chrome.forward(3);//again trying to come forward 3 pages but forward history is cleared after visit.

    return 0;
}