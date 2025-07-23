#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(){
    string input;
    while(true){
        cout<<"$ >> ";
        getline(cin,input);
        if(input=="exit"){
            break;
        }

        istringstream iss(input);
        vector<string> tokens;
        string token;
        while(iss >> token){
            tokens.push_back(token);
        }

        if(tokens.empty()) continue;

        if(tokens[0]== "cd"){
            if(tokens.size()>1){
                if(chdir(tokens[1].c_str())!=0){
                    perror("chdir failed");
                }
            }
            else{
                cerr<<"cd: expected arguments\n";
            }
            continue;
        }

        vector<char*>args;
        for( string &t : tokens){
            args.push_back(&t[0]);
        }
        args.push_back(nullptr);

        pid_t pid= fork();
        if(pid==0){
            execvp(args[0],args.data());
            perror("execvp failed");
            exit(1);
        }
        else{
            wait(NULL);
        }
    }

    return 0;
}