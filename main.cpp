#include<bits/stdc++.h>
//ACPC2022
//TposersFTW
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define pb push_back
#define lcm(x,y) x*y/__gcd(x,y)
#define summ(n) (n*(n+1))/2
using namespace std;

struct process{
    int pid;
    int arrivalTime;
    int burstTime;
    int serviceTime=0;
    int waitingTime;
};
bool cmp(process p1,process p2){
    if(p1.burstTime==p2.burstTime)return(p1.arrivalTime<p2.arrivalTime);
    return(p1.burstTime<p2.burstTime);
}
bool cmpa(process p1,process p2){
    return(p1.arrivalTime<p2.arrivalTime);
}
int main(){
    struct process p[100];
    queue<process> q;
    vector<process>v;
    cout<<"Enter Number of Processes: ";
    int n,ct=0,av=0;cin>>n;
    for(int i=0;i<n;i++){
        cout<<endl<<"Enter the arrival time of process #"<<i+1<<": ";
        cin>>p[i].arrivalTime;
        cout<<endl<<"Enter the burst time of process #"<<i+1<<": ";
        cin>>p[i].burstTime;
        p[i].pid=i+1;
        v.pb(p[i]);
    }
    sort(v.begin(),v.end(),cmpa);
    v[0].serviceTime=v[0].arrivalTime;
    v[0].waitingTime=v[0].serviceTime-v[0].arrivalTime;
    int timer=v[0].burstTime;
    q.push(v[0]);
    v.erase(v.begin());
    sort(v.begin(),v.end(), cmp);
    bool f=false;
    int i=0;
    while(!v.empty()){
        if(v[i].arrivalTime<=timer){
            v[i].waitingTime=timer-v[i].arrivalTime;
            timer+=v[i].burstTime;
            q.push(v[i]);
            v.erase(v.begin()+i);
            i=0;
        }
        else i++;
    }
    for(int i=0;i<n;i++){
        cout<<endl<<"Process #"<<q.front().pid<<" "<<"Arrival Time: "<<q.front().arrivalTime<<" "<<"Burst Time: "<<q.front().burstTime<<" "<<"Waiting Time: "<<q.front().waitingTime;
        q.pop();
    }
    cout<<endl<<"Average Time: "<<av/n;

    return 0;
}
//Test Case
//4
//2
//3
//0
//4
//4
//2
//5
//4
