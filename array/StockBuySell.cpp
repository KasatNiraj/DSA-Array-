struct Interval
 {
     int buy;
     int sell;
 };

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    if(n==1)
        return;
    Interval sol[n/2+1];
    int i=0;
    int count=0;
    while(i<n-1){
        //for local minima
        while(i<n-1 && (price[i+1]<=price[i]))  
            i++;
        if(i==n-1)
            break;
        sol[count].buy=i++;
        
        //for local maxima
        while(i<n && (price[i])>=price[i-1])
            i++;
        sol[count].sell=i-1;
        count++;
        
    }
    if(count==0)
        cout<<"No Profit";
    for(int i=0;i<count;i++){
        cout<<"("<<sol[i].buy<<" "<<sol[i].sell<<") ";
    }
    
}
