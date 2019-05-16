
int passedLength(int x){
    int i = 1;
    while((x / 10) != 0){
        i++;
        x = x/10;
    }
    return i;
}


std::map<int, int> createMap(std::string s){
        
    int coff, exp;
    std::map<int, int> m; 

    while(!s.empty()){


        std::stringstream(s) >> coff;
        s.erase(0, passedLength(coff) + 1); // +1 to remove the " "

        std::stringstream(s) >> exp; 
        s.erase(0, passedLength(exp) + 1);

        // Insert into map
        int newcoff = coff + m[exp];
        m.erase(exp);
        m.insert({exp, coff});

        // debug
            std::cout << "coff: " << coff << std::endl;
            std::cout << "exp: " << exp << std::endl;
    
    }// end of while loop

    // debug
        std::cout<< "Raw (inputted in map)" << std::endl;
        std::cout<< "key(exp) \t" << "val(coff)" << std::endl;
        for(auto itr = m.begin(); itr != m.end(); ++itr){
            std::cout << itr->first << "\t\t" << itr -> second << "\n";
        }

        std::cout << "debug1" << std::endl;


        std::cout<< "Clean" << std::endl;
        for(auto itr = m.begin(); itr != m.end(); ++itr){
            std::cout << itr -> second << "x^" << itr->first << "  ";
        }
        std::cout << "\n";
        std::cout << "debug2" << std::endl;

    return m;
}
