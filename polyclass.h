

class poly{

    std::map<int, int> pm;

public:
    poly(){

    }

    poly(std::string a){
        pm = createMap(a);
    }

    // Overloaded operators:
    // Note: I believe this could be passed by refference to speed up the operation.
    poly operator+(const poly b) const{
        poly temp;
        temp.pm = this->pm;
        auto itr = b.pm.begin();
        while(itr != b.pm.end()){
            int newval = temp.pm[itr->first] + itr -> second;
            temp.pm.erase(itr->first);
            temp.pm.insert({itr->first, newval});
            itr++;
        }
        return temp;
    }

    poly operator-(const poly b) const{
        poly temp;
        temp.pm = this->pm;
        auto itr = b.pm.begin();
        while(itr != b.pm.end()){
            int newval = temp.pm[itr->first] - itr -> second;
            temp.pm.erase(itr->first);
            temp.pm.insert({itr->first, newval});
            itr++;
        }
        return temp;
    }

    poly operator*(const poly b) const{
        poly temp;
        auto itr1 = b.pm.begin();
        auto itr2 = this->pm.begin();
        int newVal = 0;
        while(itr1 != b.pm.end()){
            while(itr2 != this->pm.end()){  
                newVal = temp.pm[itr1->second] + itr1->second * itr2->second;
                temp.pm.erase(itr2->first + itr1->first);
                temp.pm.insert({itr2->first + itr1->first, newVal});
                itr2++;
            }
            itr2 = this->pm.begin();
            itr1++;
        }

        // // Remove elements that have value 0;
        // auto itr3 = temp.pm.begin();
        // std::cout<< "this is the contents of itr3\n";
        // while(itr3 != temp.pm.end()){
        //     std::cout<< itr3 -> first << '\t' <<  itr3 -> second << std::endl;
        //     itr3++;
        // }

        // itr3 = temp.pm.begin();
        // while(itr3 != temp.pm.end()){
        //     temp.pm.erase(itr3);
        //     itr3++;
        // }

        auto itr3 = temp.pm.begin();
        // itr3 = temp.pm.find(5);
        // std::cout<< itr3->first << " " << itr3->second << '\n';
        // temp.pm.erase(5);
        std::list<int> stk;
        while(itr3 != temp.pm.end()){
            if(itr3 ->second == 0)
                stk.push_front(itr3->first);
            itr3++;
        }
        while(!stk.empty()){
            temp.pm.erase(stk.front());
            stk.pop_front();
        }

        return temp;
    }


    void displayMap(){
        for(auto itr = pm.begin(); itr != pm.end(); ++itr){
                std::cout << itr -> second << "x^" << itr->first << "  ";
            }
            std::cout << "\n";
    }



private:
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
            std::cout<< "Raw (inputted in map): " << std::endl;
            std::cout<< "key(exp) \t" << "val(coff)" << std::endl;
            for(auto itr = m.begin(); itr != m.end(); ++itr){
                std::cout << itr->first << "\t\t" << itr -> second << "\n";
            }

            std::cout<< "Clean: " << std::endl;
            for(auto itr = m.begin(); itr != m.end(); ++itr){
                std::cout << itr -> second << "x^" << itr->first << "  ";
            }
            std::cout << "\n";
            std::cout << "\n";

        return m;
    }

    friend std::ostream& operator<< (std::ostream& os, poly p); 
};

    std::ostream& operator<< (std::ostream& os, poly p){
        
        auto itr = p.pm.begin();
        char sign;
        while(itr != p.pm.end()){
            if(itr->second > 0)
                sign = '+';
            else
                sign = '-';
            os << sign <<itr -> second << "x^" << itr->first << "  ";
            itr++;
        }
        return os;
    }
    