class Logger {
public:
    map<string,int>mp;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.count(message)){
            if(timestamp-mp[message]>=10){
                mp[message] = timestamp;
                return true;
            }
            else return false;
        }
        else{
            mp[message] = timestamp;
            return true;
        }
    }
};